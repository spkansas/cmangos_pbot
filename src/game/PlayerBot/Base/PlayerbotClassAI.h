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

enum JOB_TYPE
{
    JOB_HEAL     = 0x01,
    JOB_TANK     = 0x02,
    JOB_MASTER   = 0x04, // Not a fan of this distinction but user (or rather, admin) choice
    JOB_DPS      = 0x08,
    JOB_ALL      = 0x0F, // all of the above
    JOB_MANAONLY = 0x10  // for buff checking (NOTE: this means any with powertype mana AND druids (who may be shifted but still have mana)
};

enum BOT_ROLE
{
	ROLE_HEAL		 = 0b00000001,
	ROLE_TANK		 = 0b00000010,
	ROLE_DPS		 = 0b00000100,
	ROLE_BUFF		 = 0b10000000,
	ROLE_ALL		 = 0b10000111
};


struct heal_priority
{
    Player* p;
    uint8 hp;
    JOB_TYPE type;
    heal_priority(Player* pin, uint8 hpin, JOB_TYPE t) : p(pin), hp(hpin), type(t) {}
    // overriding the operator like this is not recommended for general use - however we won't use this struct for anything else
    bool operator<(const heal_priority& a) const { return type < a.type; }
};

class PlayerbotClassAIData_LoadFailed : public std::runtime_error 
{
public:
	PlayerbotClassAIData_LoadFailed() : std::runtime_error("PlayerbotClassAI database load failure") { }
};


class PlayerbotClassAIData
{
private:
  
    BOT_ROLE	 m_eBotRole = BOT_ROLE::ROLE_ALL;

    Player		*m_master;
    Player		*m_bot;

    PlayerbotAI *m_ai;

    time_t		 m_tTimeStart;
    time_t		 m_tTimeWaitUntil;

    uint32		 m_uiBotSpec     = 0;
    uint32       m_uiRezSpellID  = 0;
    uint32       m_uiHealSpellID = 0;

public:

    PlayerbotClassAIData(Player * const master, Player * const bot, PlayerbotAI * const ai) : m_master(master), m_bot(bot), m_ai(ai)
    {
        if (!DB_LoadData()) throw PlayerbotClassAIData_LoadFailed();
    }
    virtual ~PlayerbotClassAIData() {};

    Player      * const GetMaster(void) { return m_master; }
    Player      * const GetBot(void) { return m_bot; }
    PlayerbotAI * const GetAI(void) { return m_ai; }

    uint32		  const GetSpec(void) { return m_uiBotSpec; }

    BOT_ROLE	  const GetRoles(void)                    { return m_eBotRole; }
    bool				SetRoles(BOT_ROLE eRole)          { m_eBotRole = eRole; return true; }

    uint32        const GetRezSpell(void)                 { return m_uiRezSpellID; }
    bool				SetRezSpell(uint32 uiRezSpellID)  { m_uiRezSpellID = uiRezSpellID; return true; }

    uint32        const GetHealSpell(void)                 { return m_uiHealSpellID; }
    bool				SetHealSpell(uint32 uiHealSpellID) { m_uiHealSpellID = uiHealSpellID; return true; }

protected:
	
		bool  DB_LoadData(void);
		bool  DB_SaveData(void);

};

class PlayerbotClassAI
{
protected:

	PlayerbotClassAIData *m_botdata;
    
    // first aid
    uint32               RECENTLY_BANDAGED;

    // These values are used in GetHealTarget and can be overridden per class (to accomodate healing spell health checks)
    uint8                m_MinHealthPercentTank;
    uint8                m_MinHealthPercentHealer;
    uint8                m_MinHealthPercentDPS;
    uint8                m_MinHealthPercentMaster;

    time_t               m_WaitUntil;

	uint32				 buff_array[10][3] = {{0}};

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

    virtual CombatManeuverReturns DoManeuver_Idle_SelfBuff(void);
	virtual CombatManeuverReturns DoManeuver_Idle_Pet_Summon(void);
	virtual CombatManeuverReturns DoManeuver_Idle_Pet_BuffnHeal(void);

    virtual CombatManeuverReturns DoManeuver_Idle_Rez_Prep(Player* target);
    virtual CombatManeuverReturns DoManeuver_Idle_Rez(Player* target);
    virtual CombatManeuverReturns DoManeuver_Idle_Rez_Post(Player* target);

    virtual CombatManeuverReturns DoManeuver_Idle_Heal_Prep(Player* target);
    virtual CombatManeuverReturns DoManeuver_Idle_Heal(Player* target);
    virtual CombatManeuverReturns DoManeuver_Idle_Heal_Post(Player* target);

    virtual CombatManeuverReturns DoManeuver_Idle_Buff_Prep(void);
    virtual CombatManeuverReturns DoManeuver_Idle_Buff(void);
    virtual CombatManeuverReturns DoManeuver_Idle_Buff_Post(void);

public:

	virtual CombatManeuverReturns DoManeuver_Idle_Buff_Helper(uint32 spellId, Unit *target);

protected:

//	virtual CombatManeuverReturns DoNextManeuver_Combat_ClassSetup(Unit *pTarget) = 0;

	virtual CombatManeuverReturns DoNextManeuver_Heal(Unit *pTarget);


    virtual CombatManeuverReturns DoFirstCombatManeuverPVE(Unit *pTarget);
    virtual CombatManeuverReturns DoNextCombatManeuverPVE(Unit *pTarget);

    virtual CombatManeuverReturns DoFirstCombatManeuverPVP(Unit *pTarget);
    virtual CombatManeuverReturns DoNextCombatManeuverPVP(Unit *pTarget);

    CombatManeuverReturns CastSpellNoRanged(uint32 nextAction, Unit *pTarget);
    CombatManeuverReturns CastSpellWand(uint32 nextAction, Unit *pTarget, uint32 SHOOT);
    virtual CombatManeuverReturns HealPlayer(Player* target);
    CombatManeuverReturns Buff(CombatManeuverReturns (PlayerbotClassAI::*Buff_Helper)(uint32, Unit*), uint32 spellId, uint32 type = JOB_ALL, bool bMustBeOOC = true);
    bool NeedGroupBuff(uint32 groupBuffSpellId, uint32 singleBuffSpellId);
    Player* GetHealTarget(JOB_TYPE type = JOB_ALL);
    Player* GetDispelTarget(DispelType dispelType, JOB_TYPE type = JOB_ALL, bool bMustBeOOC = false);
    Player* GetResurrectionTarget(JOB_TYPE type = JOB_ALL, bool bMustBeOOC = true);
    JOB_TYPE GetTargetJob(Player* target);

    bool FleeFromAoEIfCan(uint32 spellId, Unit* pTarget);
    bool FleeFromTrapGOIfCan(uint32 goEntry, Unit* pTarget);
    bool FleeFromNpcWithAuraIfCan(uint32 NpcEntry, uint32 spellId, Unit* pTarget);
    bool FleeFromPointIfCan(uint32 radius, Unit* pTarget, float x0, float y0, float z0, float forcedAngle = 0.0f);

    bool EatDrinkBandage(bool bMana = true, unsigned char foodPercent = 50, unsigned char drinkPercent = 50, unsigned char bandagePercent = 70);

    CombatManeuverReturns RessurectTarget(Player* target, uint32 RezSpell);
    CombatManeuverReturns HealTarget(Player* target, uint32 HealSpell);
};

#endif
