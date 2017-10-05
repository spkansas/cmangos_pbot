/*
 * This file is part of the CMaNGOS Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef _PLAYERBOTCLASSAI_H
#define _PLAYERBOTCLASSAI_H

#include "Common.h"
#include "WorldPacket.h"
#include "PlayerbotAI.h"
#include "../../Entities/Player.h"
#include "../../Entities/Unit.h"
#include "../../Globals/ObjectMgr.h"
#include "../../Globals/ObjectAccessor.h"
#include "../../Globals/SharedDefines.h"
#include "../../Spells/SpellMgr.h"
#include "../../Spells/SpellAuras.h"
#include "../../World/World.h"

class Player;
class PlayerbotAI;

enum BOT_ROLE
{
	ROLE_NONE		 = 0b00000000,
	ROLE_HEAL		 = 0b00000001,
	ROLE_TANK		 = 0b00000010,
	ROLE_DPS_CASTER  = 0b00000100, 
	ROLE_DPS_MELEE   = 0b00001000,
	ROLE_BUFF		 = 0b10000000,
	ROLE_ALL_DPS	 = 0b00001100,
	ROLE_ALL_CHAR	 = 0b00001111,
	ROLE_ALL		 = 0b10001111
};

#define PBOT_CLASS_NONE		0b0000000000000000
#define PBOT_CLASS_DK		0b0000000000000001
#define PBOT_CLASS_DRUID	0b0000000000000010 
#define PBOT_CLASS_PALADIN	0b0000000000000100
#define PBOT_CLASS_WARLOCK  0b0000000000001000
#define PBOT_CLASS_SHAMAN	0b0000000000010000
#define PBOT_CLASS_PRIEST	0b0000000000100000
#define PBOT_CLASS_HUNTER	0b0000000001000000
#define PBOT_CLASS_MAGE		0b0000000010000000
#define PBOT_CLASS_WARRIOR	0b0000000100000000
#define PBOT_CLASS_ROGUE	0b0000001000000000
#define PBOT_CLASS_ALL		0b0000001111111111

#define PBOT_CLASS_MELEEDPS	PBOT_CLASS_HUNTER | PBOT_CLASS_ROGUE
#define PBOT_CLASS_TANK		PBOT_CLASS_DK | PBOT_CLASS_PALADIN | PBOT_CLASS_WARRIOR
#define PBOT_CLASS_CASTER	PBOT_CLASS_WARLOCK | PBOT_CLASS_MAGE

#define PBOT_PET_NONE		0b00000000
#define PBOT_PET_SUMMON		0b00000001
#define PBOT_PET_HUNTER		0b00000010
#define PBOT_PET_GUARDIAN	0b00000100
#define PBOT_PET_MINI		0b00001000
#define PBOT_PET_PROTECTOR	0b00010000
#define PBOT_PET_ALL_TANK	0b00000010
#define PBOT_PET_ALL_MANA	0b00000001
#define PBOT_PET_ALL_HYBRID	0b00011100
#define PBOT_PET_ALL		0b00011111

class PlayerbotBufflist
{
public:
	struct spellidlist
	{
		uint32 group = 0;
		uint32 single = 0;
		uint32 single_enhanced = 0;
	} spellid;

	uint32 spec_required = 0;

	union
	{
		struct class_bitstruct
		{
			uint16 death_knight : 1;
			uint16 druid : 1;
			uint16 paladin : 1;
			uint16 warlock : 1;
			uint16 shaman : 1;
			uint16 priest : 1;
			uint16 hunter : 1;
			uint16 mage : 1;
			uint16 warrior : 1;
			uint16 rogue : 1;
			uint16 padding : 6;
		} caston_non_bot;

		uint16 caston_non_bot_all = PBOT_CLASS_NONE;
	};

	union
	{
		struct pet_bitstruct
		{
			uint8 summon : 1;
			uint8 hunter : 1;
			uint8 guardian : 1;
			uint8 mini : 1;
			uint8 protector : 1;
			uint8 padding : 3;
		} caston_pet;

		uint8 caston_pet_all = PBOT_PET_NONE;
	};

	BOT_ROLE caston_bot_role = BOT_ROLE::ROLE_ALL_CHAR;

	bool CheckClass(uint8 ui8Class)
	{
		switch (ui8Class)
		{
			case CLASS_PRIEST:
				return (bool)(caston_non_bot.priest);
			case CLASS_PALADIN:
				return (bool)(caston_non_bot.paladin);
			case CLASS_WARLOCK:
				return (bool)(caston_non_bot.warlock);
			case CLASS_MAGE:
				return (bool)(caston_non_bot.mage);
			case CLASS_ROGUE:
				return (bool)(caston_non_bot.rogue);
			case CLASS_WARRIOR:
				return (bool)(caston_non_bot.warrior);
			case CLASS_DRUID:
				return (bool)(caston_non_bot.druid);
			case CLASS_SHAMAN:
				return (bool)(caston_non_bot.shaman);
			case CLASS_HUNTER:
				return (bool)(caston_non_bot.hunter);
			default:
				return false;
		}
	}

	bool CheckPet(PetType ePetType)
	{
		switch (ePetType)
		{
		case PetType::SUMMON_PET:
			return (bool)(caston_pet.summon);
		case PetType::HUNTER_PET:
			return (bool)(caston_pet.hunter);
		case PetType::GUARDIAN_PET:
			return (bool)(caston_pet.guardian);
		case PetType::MINI_PET:
			return (bool)(caston_pet.mini);
		case PetType::PROTECTOR_PET:
			return (bool)(caston_pet.protector);
		default:
			return false;
		}
	}
};


struct role_priority
{
public:
	Player*	 pPlayer	= nullptr;
	uint8	 uiHP		= 0;
	BOT_ROLE eRole		= ROLE_NONE;

	role_priority(Player* pin, uint8 hpin, BOT_ROLE t) : pPlayer(pin), uiHP(hpin), eRole(t) {}

	// overriding the operator like this is not recommended for general use - however we won't use this struct for anything else
	bool operator<(const role_priority& a) const 
	{ 
		return (eRole == a.eRole ? (bool)(uiHP < a.uiHP) : (bool)(eRole < a.eRole));
	}
};


class PlayerbotClassAIData_LoadFailed : public std::runtime_error 
{
public:
	PlayerbotClassAIData_LoadFailed() : std::runtime_error("PlayerbotClassAI database load failure") { }
};


class PlayerbotClassAIData
{
private:
  
    BOT_ROLE	 m_eBotRole		 = BOT_ROLE::ROLE_ALL;
	BOT_ROLE	 m_eBotPrimeRole = BOT_ROLE::ROLE_NONE;

    Player		*m_master;
    Player		*m_bot;

    PlayerbotAI *m_ai;

    time_t		 m_tTimeStart;
    time_t		 m_tTimeWaitUntil;

    uint32		 m_uiBotSpec     = 0;
    uint32       m_uiRezSpellID  = 0;
    uint32       m_uiHealSpellID = 0;

	uint32       m_uiDispellMagicSpellID = 0;
	uint32       m_uiDispellDiseaseSpellID = 0;
	uint32       m_uiDispellPosionSpellID = 0;
	uint32       m_uiDispellCurseSpellID = 0;

public:

    PlayerbotClassAIData(Player * const master, Player * const bot, PlayerbotAI * const ai) : m_master(master), m_bot(bot), m_ai(ai)
    {
        if (!DB_LoadData()) throw PlayerbotClassAIData_LoadFailed();
    }
    virtual ~PlayerbotClassAIData() {};

    Player      * const GetMaster(void)					  { return m_master; }
    Player      * const GetBot(void)					  { return m_bot; }
    PlayerbotAI * const GetAI(void)						  { return m_ai; }

    uint32		  const GetSpec(void)					  { return m_uiBotSpec; }

    BOT_ROLE	  const GetRoles(void)                    { return m_eBotRole; }
    bool				SetRoles(BOT_ROLE eRole)          { m_eBotRole = eRole; return true; }

	BOT_ROLE	  const GetRolePrimary(void)			  { return m_eBotPrimeRole; }
	bool				SetRolePrimary(BOT_ROLE eRole)	  { m_eBotPrimeRole = eRole; return true; }

	bool		  const GetCanCure(void)				  { return (m_uiDispellMagicSpellID || m_uiDispellDiseaseSpellID ||
																    m_uiDispellPosionSpellID || m_uiDispellCurseSpellID); }
    uint32        const GetRezSpell(void)                 { return m_uiRezSpellID; }
    bool				SetRezSpell(uint32 uiRezSpellID)  { m_uiRezSpellID = uiRezSpellID; return true; }

    uint32        const GetHealSpell(void)                 { return m_uiHealSpellID; }
    bool				SetHealSpell(uint32 uiHealSpellID) { m_uiHealSpellID = uiHealSpellID; return true; }

	uint32        const GetDispellMagicSpell(void)						   { return m_uiDispellMagicSpellID; }
	bool				SetDispellMagicSpell(uint32 uiDispellMagicSpellID) { m_uiDispellMagicSpellID = uiDispellMagicSpellID; return true; }

	uint32        const GetDispellDiseaseSpell(void)						{ return m_uiDispellDiseaseSpellID; }
	bool				SetDispellDiseaseSpell(uint32 uiDispellDisease)		{ m_uiDispellDiseaseSpellID = uiDispellDisease; return true; }

	uint32        const GetDispellPosionSpell(void)							{ return m_uiDispellPosionSpellID; }
	bool				SetDispellPosionSpell(uint32 uiDispellPosionSpellID) { m_uiDispellPosionSpellID = uiDispellPosionSpellID; return true; }

	uint32        const GetDispellCurseSpell(void)							{ return m_uiDispellCurseSpellID; }
	bool				SetDispellCurseSpell(uint32 uiDispellCurseSpellID)  { m_uiDispellCurseSpellID = uiDispellCurseSpellID; return true; }

protected:
	
		bool  DB_LoadData(void);
		bool  DB_SaveData(void);

};

class PlayerbotClassAI
{
protected:

	PlayerbotClassAIData *m_botdata;
    
    // first aid
    uint32               RECENTLY_BANDAGED = 11196;

    // These values are used in GetHealTarget and can be overridden per class (to accomodate healing spell health checks)
    uint8                m_MinHealthPercentTank;
    uint8                m_MinHealthPercentHealer;
    uint8                m_MinHealthPercentDPS;
    uint8                m_MinHealthPercentMaster;

    time_t               m_WaitUntil;

	PlayerbotBufflist   *buff_list[10] = { nullptr };
	uint32				 debuff_list[5] = { 0 };

	void (*m_ActionBeforeCast)(Player *) = NULL;

public:

    PlayerbotClassAI(Player * const master, Player * const bot, PlayerbotAI * const ai);
	~PlayerbotClassAI();

public:

    // all combat actions go here
    virtual CombatManeuverReturns DoManeuver_Combat_Start(Unit *pTarget);
	virtual CombatManeuverReturns DoManeuver_Combat_Move(Unit *pTarget);
	virtual CombatManeuverReturns DoManeuver_Combat_Exec(Unit *pTarget);

    bool Pull() { DEBUG_LOG("[PlayerbotAI]: Warning: Using PlayerbotClassAI::Pull() rather than class specific function"); return false; }
    bool Neutralize() { DEBUG_LOG("[PlayerbotAI]: Warning: Using PlayerbotClassAI::Neutralize() rather than class specific function"); return false; }

    // all non combat actions go here, ex buffs, heals, rezzes
    virtual void DoNonCombatActions();

    // Utilities
    Player*			GetMaster()		    { return m_botdata->GetMaster(); }
    Player*			GetPlayerBot()	    { return m_botdata->GetBot();}
    PlayerbotAI*	GetAI()			    { return m_botdata->GetAI(); }
    bool            CanPull();
    bool            CastHoTOnTank();
    time_t          GetWaitUntil()	    { return m_WaitUntil; }
    void            SetWait(uint8 t)    { m_WaitUntil = m_botdata->GetAI()->CurrentTime() + t; }
    void            ClearWait()		    { m_WaitUntil = 0; }
    //void SetWaitUntil(time_t t)	    { m_WaitUntil = t; }

protected:

    virtual bool PlayerbotClassAI_ClassAIInit(void);

protected:
	// Temp AI Flag
	virtual bool PBotNewAI(void) { return false; }

	// Class overriables
	virtual CombatManeuverReturns DoManeuver_Combat_Start_Class_Prep(Unit *pTarget);
	virtual CombatManeuverReturns DoManeuver_Combat_Start_Class_Post(Unit *pTarget);

	virtual CombatManeuverReturns DoManeuver_Combat_Move_Class_Prep(Unit *pTarget);
	virtual CombatManeuverReturns DoManeuver_Combat_Move_Class_Post(Unit *pTarget);

	virtual CombatManeuverReturns DoManeuver_Combat_Exec_Class_Prep(Unit *pTarget);
//	virtual CombatManeuverReturns DoManeuver_Combat_Exec_Class_Buff(Unit *pTarget);
//	virtual CombatManeuverReturns DoManeuver_Combat_Exec_Class_Cast(Unit *pTarget);
	virtual CombatManeuverReturns DoManeuver_Combat_Exec_Class_Post(Unit *pTarget);

	virtual CombatManeuverReturns DoNextManeuver_Heal_ClassSetup(Unit *pTarget);

protected:

	virtual CombatManeuverReturns DoManeuver_Idle_Forms_Start(void);

	virtual CombatManeuverReturns DoManeuver_Idle_Cure_Detremental(void);
	
	virtual CombatManeuverReturns DoManeuver_Idle_SelfBuff(void);
	
    virtual CombatManeuverReturns DoManeuver_Idle_Rez_Prep(Player* target);
    virtual CombatManeuverReturns DoManeuver_Idle_Rez(Player* target);
    virtual CombatManeuverReturns DoManeuver_Idle_Rez_Post(Player* target);

    virtual CombatManeuverReturns DoManeuver_Idle_Heal_Prep(Player* target);
    virtual CombatManeuverReturns DoManeuver_Idle_Heal(Player* target);
    virtual CombatManeuverReturns DoManeuver_Idle_Heal_Post(Player* target);

    virtual CombatManeuverReturns DoManeuver_Idle_Buff_Prep(void);
    virtual CombatManeuverReturns DoManeuver_Idle_Buff(void);
    virtual CombatManeuverReturns DoManeuver_Idle_Buff_Post(void);

	virtual CombatManeuverReturns DoManeuver_Idle_Pet_Summon(void);

	virtual CombatManeuverReturns DoManeuver_Idle_Pet_BuffnHeal(void);

	virtual CombatManeuverReturns DoManeuver_Idle_Forms_End(void);

public:

	virtual CombatManeuverReturns DoManeuver_Idle_Buff_Helper(uint32 spellId, Unit *target);

protected:

	virtual CombatManeuverReturns DoNextManeuver_Heal(Unit *pTarget);


    virtual CombatManeuverReturns DoFirstCombatManeuverPVE(Unit *pTarget);
    virtual CombatManeuverReturns DoNextCombatManeuverPVE(Unit *pTarget);

    virtual CombatManeuverReturns DoFirstCombatManeuverPVP(Unit *pTarget);
    virtual CombatManeuverReturns DoNextCombatManeuverPVP(Unit *pTarget);



    CombatManeuverReturns CastSpellNoRanged(uint32 nextAction, Unit *pTarget);
    CombatManeuverReturns CastSpellWand(uint32 nextAction, Unit *pTarget, uint32 SHOOT);
    virtual CombatManeuverReturns HealPlayer(Player* target);
	
    bool FleeFromAoEIfCan(uint32 spellId, Unit* pTarget);
    bool FleeFromTrapGOIfCan(uint32 goEntry, Unit* pTarget);
    bool FleeFromNpcWithAuraIfCan(uint32 NpcEntry, uint32 spellId, Unit* pTarget);
    bool FleeFromPointIfCan(uint32 radius, Unit* pTarget, float x0, float y0, float z0, float forcedAngle = 0.0f);

    bool EatDrinkBandage(bool bMana = true, unsigned char foodPercent = 50, unsigned char drinkPercent = 50, unsigned char bandagePercent = 70);

    CombatManeuverReturns RessurectTarget(Player* target, uint32 RezSpell);
    CombatManeuverReturns HealTarget(Player* target, uint32 HealSpell);

private:

	Player	*Get_Prioritized_Cure_Detremental_Target(BOT_ROLE tgtRole = ROLE_ALL);
	Player  *Get_Prioritized_Resurrection_Target(BOT_ROLE tgtRole = ROLE_ALL);

	BOT_ROLE GetTargetRole(Player* target);

protected:

	Player	*Get_Prioritized_Heal_Target(BOT_ROLE tgtRole = ROLE_ALL);

};

#endif
