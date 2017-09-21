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

#ifndef _PlayerbotRogueAI_H
#define _PlayerbotRogueAI_H

#include "../Base/PlayerbotClassAI.h"

enum
{
    RogueCombat,
    RogueSpellPreventing,
    RogueThreat,
    RogueStealth
};

enum RoguePoisonDisplayId
{
    DEADLY_POISON_DISPLAYID  = 13707,
    INSTANT_POISON_DISPLAYID = 13710,
    WOUND_POISON_DISPLAYID   = 37278
};

enum RogueSpells
{
    ADRENALINE_RUSH_1               = 13750,
    AMBUSH_1                        = 8676,
    BACKSTAB_1                      = 53,
    BLADE_FLURRY_1                  = 13877,
    BLIND_1                         = 2094,
    CHEAP_SHOT_1                    = 1833,
    CLOAK_OF_SHADOWS_1              = 31224,
    COLD_BLOOD_1                    = 14177,
    DEADLY_THROW_1                  = 26679,
    DISARM_TRAP_1                   = 1842,
    DISMANTLE_1                     = 51722,
    DISTRACT_1                      = 1725,
    ENVENOM_1                       = 32645,
    EVASION_1                       = 5277,
    EVISCERATE_1                    = 2098,
    EXPOSE_ARMOR_1                  = 8647,
    FAN_OF_KNIVES_1                 = 51723,
    FEINT_1                         = 1966,
    GARROTE_1                       = 703,
    GHOSTLY_STRIKE_1                = 14278,
    GOUGE_1                         = 1776,
    HEMORRHAGE_1                    = 16511,
    HUNGER_FOR_BLOOD_1              = 51662,
    KICK_1                          = 1766,
    KIDNEY_SHOT_1                   = 408,
    KILLING_SPREE_1                 = 51690,
    MUTILATE_1                      = 1329,
    PICK_LOCK_1                     = 1804,
    PICK_POCKET_1                   = 921,
    PREMEDITATION_1                 = 14183,
    PREPARATION_1                   = 14185,
    RIPOSTE_1                       = 14251,
    RUPTURE_1                       = 1943,
    SAP_1                           = 6770,
    SHADOW_DANCE_1                  = 51713,
    SHADOWSTEP_1                    = 36554,
    SHIV_1                          = 5938,
    SINISTER_STRIKE_1               = 1752,
    SLICE_AND_DICE_1                = 5171,
    SPRINT_1                        = 2983,
    STEALTH_1                       = 1784,
    TRICKS_OF_THE_TRADE_1           = 57934,
    VANISH_1                        = 1856
};


enum TalentsRogue  // 0x008
{
	ROGUE_IMPROVED_GOUGE = 203,   // TabId = 181, Tab = 1, Row = 0, Column = 0
	ROGUE_IMPROVED_SINISTER_STRIKE = 201,   // TabId = 181, Tab = 1, Row = 0, Column = 1
	ROGUE_DUAL_WIELD_SPECIALIZATION = 221,   // TabId = 181, Tab = 1, Row = 0, Column = 2
	ROGUE_IMPROVED_SLICE_AND_DICE = 1827,  // TabId = 181, Tab = 1, Row = 1, Column = 0
	ROGUE_DEFLECTION = 187,   // TabId = 181, Tab = 1, Row = 1, Column = 1
	ROGUE_PRECISION = 181,   // TabId = 181, Tab = 1, Row = 1, Column = 3
	ROGUE_ENDURANCE = 204,   // TabId = 181, Tab = 1, Row = 2, Column = 0
	ROGUE_RIPOSTE = 301,   // TabId = 181, Tab = 1, Row = 2, Column = 1
	ROGUE_CLOSE_QUARTERS_COMBAT = 182,   // TabId = 181, Tab = 1, Row = 2, Column = 2
	ROGUE_IMPROVED_KICK = 206,   // TabId = 181, Tab = 1, Row = 3, Column = 0
	ROGUE_IMPROVED_SPRINT = 222,   // TabId = 181, Tab = 1, Row = 3, Column = 1
	ROGUE_LIGHTNING_REFLEXES = 186,   // TabId = 181, Tab = 1, Row = 3, Column = 2
	ROGUE_AGGRESSION = 1122,  // TabId = 181, Tab = 1, Row = 3, Column = 3
	ROGUE_MACE_SPECIALIZATION = 184,   // TabId = 181, Tab = 1, Row = 4, Column = 0
	ROGUE_BLADE_FLURRY = 223,   // TabId = 181, Tab = 1, Row = 4, Column = 1
	ROGUE_HACK_AND_SLASH = 242,   // TabId = 181, Tab = 1, Row = 4, Column = 2
	ROGUE_WEAPON_EXPERTISE = 1703,  // TabId = 181, Tab = 1, Row = 5, Column = 1
	ROGUE_BLADE_TWISTING = 1706,  // TabId = 181, Tab = 1, Row = 5, Column = 2
	ROGUE_VITALITY = 1705,  // TabId = 181, Tab = 1, Row = 6, Column = 0
	ROGUE_ADRENALINE_RUSH = 205,   // TabId = 181, Tab = 1, Row = 6, Column = 1
	ROGUE_NERVES_OF_STEEL = 1707,  // TabId = 181, Tab = 1, Row = 6, Column = 2
	ROGUE_THROWING_SPECIALIZATION = 2072,  // TabId = 181, Tab = 1, Row = 7, Column = 0
	ROGUE_COMBAT_POTENCY = 1825,  // TabId = 181, Tab = 1, Row = 7, Column = 2
	ROGUE_UNFAIR_ADVANTAGE = 2073,  // TabId = 181, Tab = 1, Row = 8, Column = 0
	ROGUE_SURPRISE_ATTACKS = 1709,  // TabId = 181, Tab = 1, Row = 8, Column = 1
	ROGUE_SAVAGE_COMBAT = 2074,  // TabId = 181, Tab = 1, Row = 8, Column = 2
	ROGUE_PREY_ON_THE_WEAK = 2075,  // TabId = 181, Tab = 1, Row = 9, Column = 1
	ROGUE_KILLING_SPREE = 2076,  // TabId = 181, Tab = 1, Row = 10, Column = 1
	ROGUE_IMPROVED_EVISCERATE = 276,   // TabId = 182, Tab = 0, Row = 0, Column = 0
	ROGUE_REMORSELESS_ATTACKS = 272,   // TabId = 182, Tab = 0, Row = 0, Column = 1
	ROGUE_MALICE = 270,   // TabId = 182, Tab = 0, Row = 0, Column = 2
	ROGUE_RUTHLESSNESS = 273,   // TabId = 182, Tab = 0, Row = 1, Column = 0
	ROGUE_BLOOD_SPATTER = 2068,  // TabId = 182, Tab = 0, Row = 1, Column = 1
	ROGUE_PUNCTURING_WOUNDS = 277,   // TabId = 182, Tab = 0, Row = 1, Column = 3
	ROGUE_VIGOR = 382,   // TabId = 182, Tab = 0, Row = 2, Column = 0
	ROGUE_IMPROVED_EXPOSE_ARMOR = 278,   // TabId = 182, Tab = 0, Row = 2, Column = 1
	ROGUE_LETHALITY = 269,   // TabId = 182, Tab = 0, Row = 2, Column = 2
	ROGUE_VILE_POISONS = 682,   // TabId = 182, Tab = 0, Row = 3, Column = 1
	ROGUE_IMPROVED_POISONS = 268,   // TabId = 182, Tab = 0, Row = 3, Column = 2
	ROGUE_FLEET_FOOTED = 1721,  // TabId = 182, Tab = 0, Row = 4, Column = 0
	ROGUE_COLD_BLOOD = 280,   // TabId = 182, Tab = 0, Row = 4, Column = 1
	ROGUE_IMPROVED_KIDNEY_SHOT = 279,   // TabId = 182, Tab = 0, Row = 4, Column = 2
	ROGUE_QUICK_RECOVERY = 1762,  // TabId = 182, Tab = 0, Row = 4, Column = 3
	ROGUE_SEAL_FATE = 283,   // TabId = 182, Tab = 0, Row = 5, Column = 1
	ROGUE_MURDER = 274,   // TabId = 182, Tab = 0, Row = 5, Column = 2
	ROGUE_DEADLY_BREW = 2065,  // TabId = 182, Tab = 0, Row = 6, Column = 0
	ROGUE_OVERKILL = 281,   // TabId = 182, Tab = 0, Row = 6, Column = 1
	ROGUE_DEADENED_NERVES = 1723,  // TabId = 182, Tab = 0, Row = 6, Column = 2
	ROGUE_FOCUSED_ATTACKS = 2069,  // TabId = 182, Tab = 0, Row = 7, Column = 0
	ROGUE_FIND_WEAKNESS = 1718,  // TabId = 182, Tab = 0, Row = 7, Column = 2
	ROGUE_MASTER_POISONER = 1715,  // TabId = 182, Tab = 0, Row = 8, Column = 0
	ROGUE_MUTILATE = 1719,  // TabId = 182, Tab = 0, Row = 8, Column = 1
	ROGUE_TURN_THE_TABLES = 2066,  // TabId = 182, Tab = 0, Row = 8, Column = 2
	ROGUE_CUT_TO_THE_CHASE = 2070,  // TabId = 182, Tab = 0, Row = 9, Column = 1
	ROGUE_HUNGER_FOR_BLOOD = 2071,  // TabId = 182, Tab = 0, Row = 10, Column = 1
	ROGUE_RELENTLESS_STRIKES = 2244,  // TabId = 183, Tab = 2, Row = 0, Column = 0
	ROGUE_MASTER_OF_DECEPTION = 241,   // TabId = 183, Tab = 2, Row = 0, Column = 1
	ROGUE_OPPORTUNITY = 261,   // TabId = 183, Tab = 2, Row = 0, Column = 2
	ROGUE_SLEIGHT_OF_HAND = 1700,  // TabId = 183, Tab = 2, Row = 1, Column = 0
	ROGUE_DIRTY_TRICKS = 262,   // TabId = 183, Tab = 2, Row = 1, Column = 1
	ROGUE_CAMOUFLAGE = 244,   // TabId = 183, Tab = 2, Row = 1, Column = 2
	ROGUE_ELUSIVENESS = 247,   // TabId = 183, Tab = 2, Row = 2, Column = 0
	ROGUE_GHOSTLY_STRIKE = 303,   // TabId = 183, Tab = 2, Row = 2, Column = 1
	ROGUE_SERRATED_BLADES = 1123,  // TabId = 183, Tab = 2, Row = 2, Column = 2
	ROGUE_SETUP = 246,   // TabId = 183, Tab = 2, Row = 3, Column = 0
	ROGUE_INITIATIVE = 245,   // TabId = 183, Tab = 2, Row = 3, Column = 1
	ROGUE_IMPROVED_AMBUSH = 263,   // TabId = 183, Tab = 2, Row = 3, Column = 2
	ROGUE_HEIGHTENED_SENSES = 1701,  // TabId = 183, Tab = 2, Row = 4, Column = 0
	ROGUE_PREPARATION = 284,   // TabId = 183, Tab = 2, Row = 4, Column = 1
	ROGUE_DIRTY_DEEDS = 265,   // TabId = 183, Tab = 2, Row = 4, Column = 2
	ROGUE_HEMORRHAGE = 681,   // TabId = 183, Tab = 2, Row = 4, Column = 3
	ROGUE_MASTER_OF_SUBTLETY = 1713,  // TabId = 183, Tab = 2, Row = 5, Column = 0
	ROGUE_DEADLINESS = 1702,  // TabId = 183, Tab = 2, Row = 5, Column = 2
	ROGUE_ENVELOPING_SHADOWS = 1711,  // TabId = 183, Tab = 2, Row = 6, Column = 0
	ROGUE_PREMEDITATION = 381,   // TabId = 183, Tab = 2, Row = 6, Column = 1
	ROGUE_CHEAT_DEATH = 1722,  // TabId = 183, Tab = 2, Row = 6, Column = 2
	ROGUE_SINISTER_CALLING = 1712,  // TabId = 183, Tab = 2, Row = 7, Column = 1
	ROGUE_WAYLAY = 2077,  // TabId = 183, Tab = 2, Row = 7, Column = 2
	ROGUE_HONOR_AMONG_THIEVES = 2078,  // TabId = 183, Tab = 2, Row = 8, Column = 0
	ROGUE_SHADOWSTEP = 1714,  // TabId = 183, Tab = 2, Row = 8, Column = 1
	ROGUE_FILTHY_TRICKS = 2079,  // TabId = 183, Tab = 2, Row = 8, Column = 2
	ROGUE_SLAUGHTER_FROM_THE_SHADOWS = 2080,  // TabId = 183, Tab = 2, Row = 9, Column = 1
	ROGUE_SHADOW_DANCE = 2081   // TabId = 183, Tab = 2, Row = 10, Column = 1
};


//class Player;

class PlayerbotRogueAI : PlayerbotClassAI
{

private:

	// COMBAT
	uint32	SINISTER_STRIKE, 
			BACKSTAB, 
			GOUGE, 
			EVASION, 
			SPRINT, 
			KICK, 
			FEINT, 
			SHIV, 
			FAN_OF_KNIVES;

	// SUBTLETY
	uint32	SHADOWSTEP, 
			STEALTH, 
			VANISH, 
			HEMORRHAGE, 
			BLIND, 
			SHADOW_DANCE, 
			PICK_POCKET, 
			CLOAK_OF_SHADOWS, 
			TRICK_TRADE, 
			CRIPPLING_POISON, 
			DEADLY_POISON, 
			MIND_NUMBING_POISON, 
			GHOSTLY_STRIKE, 
			DISTRACT, 
			PREPARATION, 
			PREMEDITATION;

	// ASSASSINATION
	uint32	EVISCERATE, 
			SLICE_DICE, 
			GARROTE, 
			EXPOSE_ARMOR, 
			AMBUSH, 
			RUPTURE, 
			DISMANTLE, 
			CHEAP_SHOT, 
			KIDNEY_SHOT, 
			MUTILATE, 
			ENVENOM, 
			DEADLY_THROW;

	// racial
	uint32	ARCANE_TORRENT, 
			GIFT_OF_THE_NAARU, 
			STONEFORM, 
			ESCAPE_ARTIST, 
			EVERY_MAN_FOR_HIMSELF, 
			SHADOWMELD, 
			BLOOD_FURY, 
			WAR_STOMP, 
			BERSERKING, 
			WILL_OF_THE_FORSAKEN;

	uint32 SpellSequence, LastSpellCombat, LastSpellSubtlety, LastSpellAssassination, Aura;

public:
 
	PlayerbotRogueAI(Player * const master, Player * const bot, PlayerbotAI * const ai);
    virtual ~PlayerbotRogueAI();

 
protected:

	bool PBotNewAI(void) { return true; }

private:

	bool PlayerbotClassAI_ClassAIInit(void);

	//	CombatManeuverReturns DoManeuver_Combat_Start_Class_Prep(Unit *pTarget);
	//	CombatManeuverReturns DoManeuver_Combat_Start_Class_Post(Unit *pTarget);

	//	CombatManeuverReturns DoManeuver_Combat_Move_Class_Prep(Unit *pTarget);
	//	CombatManeuverReturns DoManeuver_Combat_Move_Class_Post(Unit *pTarget);

	//	CombatManeuverReturns DoManeuver_Combat_Exec_Class_Prep(Unit *pTarget);
	//	CombatManeuverReturns DoManeuver_Combat_Exec_Class_Post(Unit *pTarget);

	//	CombatManeuverReturns DoNextManeuver_Heal_ClassSetup(Unit *pTarget);

    CombatManeuverReturns DoFirstCombatManeuverPVE(Unit* pTarget);
    CombatManeuverReturns DoNextCombatManeuverPVE(Unit* pTarget);
    CombatManeuverReturns DoFirstCombatManeuverPVP(Unit* pTarget);
    CombatManeuverReturns DoNextCombatManeuverPVP(Unit* pTarget);

private:

	CombatManeuverReturns DoManeuver_Idle_Forms_Start(void);

//	CombatManeuverReturns DoManeuver_Idle_Cure_Detremental(void);

//	CombatManeuverReturns DoManeuver_Idle_SelfBuff(void);

//	CombatManeuverReturns DoManeuver_Idle_Rez_Prep(Player *target);
//	CombatManeuverReturns DoManeuver_Idle_Rez(Player *target);
//	CombatManeuverReturns DoManeuver_Idle_Rez_Post(Player *target);

//  CombatManeuverReturns DoManeuver_Idle_Heal_Prep(Player *target);
//	CombatManeuverReturns DoManeuver_Idle_Heal(Player *target);
//	CombatManeuverReturns DoManeuver_Idle_Heal_Post(Player *target);

//	CombatManeuverReturns DoManeuver_Idle_Buff_Prep(void);
//	CombatManeuverReturns DoManeuver_Idle_Buff(void);
//	CombatManeuverReturns DoManeuver_Idle_Buff_Post(void);

//	CombatManeuverReturns DoManeuver_Idle_Pet_Summon(void);

//	CombatManeuverReturns DoManeuver_Idle_Pet_BuffnHeal(void);

	CombatManeuverReturns DoManeuver_Idle_Forms_End(void);

private:
	
};

#endif
