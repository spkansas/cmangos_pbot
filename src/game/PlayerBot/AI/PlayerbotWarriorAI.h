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

#ifndef _PlayerbotWarriorAI_H
#define _PlayerbotWarriorAI_H

#include "../Base/PlayerbotClassAI.h"

enum
{
    WarriorSpellPreventing,
    WarriorBattle,
    WarriorDefensive,
    WarriorBerserker
};

enum WarriorSpells
{
    AUTO_SHOT_2                     = 75,
    BATTLE_SHOUT_1                  = 6673,
    BATTLE_STANCE_1                 = 2457,
    BERSERKER_RAGE_1                = 18499,
    BERSERKER_STANCE_1              = 2458,
    BLADESTORM_1                    = 46924,
    BLOODRAGE_1                     = 2687,
    BLOODTHIRST_1                   = 23881,
    CHALLENGING_SHOUT_1             = 1161,
    CHARGE_1                        = 100,
    CLEAVE_1                        = 845,
    COMMANDING_SHOUT_1              = 469,
    CONCUSSION_BLOW_1               = 12809,
    DEATH_WISH_1                    = 12292,
    DEFENSIVE_STANCE_1              = 71,
    DEMORALIZING_SHOUT_1            = 1160,
    DEVASTATE_1                     = 20243,
    DISARM_1                        = 676,
    ENRAGED_REGENERATION_1          = 55694,
    EXECUTE_1                       = 5308,
    HAMSTRING_1                     = 1715,
    HEROIC_FURY_1                   = 60970,
    HEROIC_STRIKE_1                 = 78,
    HEROIC_THROW_1                  = 57755,
    INTERCEPT_1                     = 20252,
    INTERVENE_1                     = 3411,
    INTIMIDATING_SHOUT_1            = 5246,
    LAST_STAND_1                    = 12975,
    MOCKING_BLOW_1                  = 694,
    MORTAL_STRIKE_1                 = 12294,
    OVERPOWER_1                     = 7384,
    PIERCING_HOWL_1                 = 12323,
    PUMMEL_1                        = 6552,
    RECKLESSNESS_1                  = 1719,
    REND_1                          = 772,
    RETALIATION_1                   = 20230,
    REVENGE_1                       = 6572,
    SHATTERING_THROW_1              = 64382,
    SHIELD_BASH_1                   = 72,
    SHIELD_BLOCK_1                  = 2565,
    SHIELD_SLAM_1                   = 23922,
    SHIELD_WALL_1                   = 871,
    SHOCKWAVE_1                     = 46968,
    SLAM_1                          = 1464,
    SPELL_REFLECTION_1              = 23920,
    SUNDER_ARMOR_1                  = 7386,
    SWEEPING_STRIKES_1              = 12328,
    TAUNT_1                         = 355,
    THUNDER_CLAP_1                  = 6343,
    VICTORY_RUSH_1                  = 34428,
    VIGILANCE_1                     = 50720,
    WHIRLWIND_1                     = 1680,

    //Procs
    SLAM_PROC_1                     = 46916,
    BLOODSURGE_1                    = 46915,
    TASTE_FOR_BLOOD_1               = 56638,
    SUDDEN_DEATH_1                  = 52437
};


enum TalentsWarrior  // 0x001
{
	WARRIOR_IMPROVED_HEROIC_STRIKE = 124,   // TabId = 161, Tab = 0, Row = 0, Column = 0
	WARRIOR_DEFLECTION = 130,   // TabId = 161, Tab = 0, Row = 0, Column = 1
	WARRIOR_IMPROVED_REND = 127,   // TabId = 161, Tab = 0, Row = 0, Column = 2
	WARRIOR_IMPROVED_CHARGE = 126,   // TabId = 161, Tab = 0, Row = 1, Column = 0
	WARRIOR_IRON_WILL = 641,   // TabId = 161, Tab = 0, Row = 1, Column = 1
	WARRIOR_TACTICAL_MASTERY = 128,   // TabId = 161, Tab = 0, Row = 1, Column = 2
	WARRIOR_IMPROVED_OVERPOWER = 131,   // TabId = 161, Tab = 0, Row = 2, Column = 0
	WARRIOR_ANGER_MANAGEMENT = 137,   // TabId = 161, Tab = 0, Row = 2, Column = 1
	WARRIOR_IMPALE = 662,   // TabId = 161, Tab = 0, Row = 2, Column = 2
	WARRIOR_DEEP_WOUNDS = 121,   // TabId = 161, Tab = 0, Row = 2, Column = 3
	WARRIOR_TWOHANDED_WEAPON_SPECIALIZATION = 136,   // TabId = 161, Tab = 0, Row = 3, Column = 1
	WARRIOR_TASTE_FOR_BLOOD = 2232,  // TabId = 161, Tab = 0, Row = 3, Column = 2
	WARRIOR_POLEAXE_SPECIALIZATION = 132,   // TabId = 161, Tab = 0, Row = 4, Column = 0
	WARRIOR_SWEEPING_STRIKES = 133,   // TabId = 161, Tab = 0, Row = 4, Column = 1
	WARRIOR_MACE_SPECIALIZATION = 125,   // TabId = 161, Tab = 0, Row = 4, Column = 2
	WARRIOR_SWORD_SPECIALIZATION = 123,   // TabId = 161, Tab = 0, Row = 4, Column = 3
	WARRIOR_WEAPON_MASTERY = 134,   // TabId = 161, Tab = 0, Row = 5, Column = 0
	WARRIOR_IMPROVED_HAMSTRING = 129,   // TabId = 161, Tab = 0, Row = 5, Column = 2
	WARRIOR_TRAUMA = 1859,  // TabId = 161, Tab = 0, Row = 5, Column = 3
	WARRIOR_SECOND_WIND = 1663,  // TabId = 161, Tab = 0, Row = 6, Column = 0
	WARRIOR_MORTAL_STRIKE = 135,   // TabId = 161, Tab = 0, Row = 6, Column = 1
	WARRIOR_STRENGTH_OF_ARMS = 1862,  // TabId = 161, Tab = 0, Row = 6, Column = 2
	WARRIOR_IMPROVED_SLAM = 2233,  // TabId = 161, Tab = 0, Row = 6, Column = 3
	WARRIOR_JUGGERNAUT = 2283,  // TabId = 161, Tab = 0, Row = 7, Column = 0
	WARRIOR_IMPROVED_MORTAL_STRIKE = 1824,  // TabId = 161, Tab = 0, Row = 7, Column = 1
	WARRIOR_UNRELENTING_ASSAULT = 1860,  // TabId = 161, Tab = 0, Row = 7, Column = 2
	WARRIOR_SUDDEN_DEATH = 1662,  // TabId = 161, Tab = 0, Row = 8, Column = 0
	WARRIOR_ENDLESS_RAGE = 1661,  // TabId = 161, Tab = 0, Row = 8, Column = 1
	WARRIOR_BLOOD_FRENZY = 1664,  // TabId = 161, Tab = 0, Row = 8, Column = 2
	WARRIOR_WRECKING_CREW = 2231,  // TabId = 161, Tab = 0, Row = 9, Column = 1
	WARRIOR_BLADESTORM = 1863,  // TabId = 161, Tab = 0, Row = 10, Column = 1
	WARRIOR_IMPROVED_BLOODRAGE = 142,   // TabId = 163, Tab = 2, Row = 0, Column = 0
	WARRIOR_SHIELD_SPECIALIZATION = 1601,  // TabId = 163, Tab = 2, Row = 0, Column = 1
	WARRIOR_IMPROVED_THUNDER_CLAP = 141,   // TabId = 163, Tab = 2, Row = 0, Column = 2
	WARRIOR_INCITE = 144,   // TabId = 163, Tab = 2, Row = 1, Column = 1
	WARRIOR_ANTICIPATION = 138,   // TabId = 163, Tab = 2, Row = 1, Column = 2
	WARRIOR_LAST_STAND = 153,   // TabId = 163, Tab = 2, Row = 2, Column = 0
	WARRIOR_IMPROVED_REVENGE = 147,   // TabId = 163, Tab = 2, Row = 2, Column = 1
	WARRIOR_SHIELD_MASTERY = 1654,  // TabId = 163, Tab = 2, Row = 2, Column = 2
	WARRIOR_TOUGHNESS = 140,   // TabId = 163, Tab = 2, Row = 2, Column = 3
	WARRIOR_IMPROVED_SPELL_REFLECTION = 2247,  // TabId = 163, Tab = 2, Row = 3, Column = 0
	WARRIOR_IMPROVED_DISARM = 151,   // TabId = 163, Tab = 2, Row = 3, Column = 1
	WARRIOR_PUNCTURE = 146,   // TabId = 163, Tab = 2, Row = 3, Column = 2
	WARRIOR_IMPROVED_DISCIPLINES = 150,   // TabId = 163, Tab = 2, Row = 4, Column = 0
	WARRIOR_CONCUSSION_BLOW = 152,   // TabId = 163, Tab = 2, Row = 4, Column = 1
	WARRIOR_GAG_ORDER = 149,   // TabId = 163, Tab = 2, Row = 4, Column = 2
	WARRIOR_ONEHANDED_WEAPON_SPECIALIZATION = 702,   // TabId = 163, Tab = 2, Row = 5, Column = 2
	WARRIOR_IMPROVED_DEFENSIVE_STANCE = 1652,  // TabId = 163, Tab = 2, Row = 6, Column = 0
	WARRIOR_VIGILANCE = 148,   // TabId = 163, Tab = 2, Row = 6, Column = 1
	WARRIOR_FOCUSED_RAGE = 1660,  // TabId = 163, Tab = 2, Row = 6, Column = 2
	WARRIOR_VITALITY = 1653,  // TabId = 163, Tab = 2, Row = 7, Column = 1
	WARRIOR_SAFEGUARD = 1870,  // TabId = 163, Tab = 2, Row = 7, Column = 2
	WARRIOR_WARBRINGER = 2236,  // TabId = 163, Tab = 2, Row = 8, Column = 0
	WARRIOR_DEVASTATE = 1666,  // TabId = 163, Tab = 2, Row = 8, Column = 1
	WARRIOR_CRITICAL_BLOCK = 1893,  // TabId = 163, Tab = 2, Row = 8, Column = 2
	WARRIOR_SWORD_AND_BOARD = 1871,  // TabId = 163, Tab = 2, Row = 9, Column = 1
	WARRIOR_DAMAGE_SHIELD = 2246,  // TabId = 163, Tab = 2, Row = 9, Column = 2
	WARRIOR_SHOCKWAVE = 1872,  // TabId = 163, Tab = 2, Row = 10, Column = 1
	WARRIOR_ARMORED_TO_THE_TEETH = 2250,  // TabId = 164, Tab = 1, Row = 0, Column = 0
	WARRIOR_BOOMING_VOICE = 158,   // TabId = 164, Tab = 1, Row = 0, Column = 1
	WARRIOR_CRUELTY = 157,   // TabId = 164, Tab = 1, Row = 0, Column = 2
	WARRIOR_IMPROVED_DEMORALIZING_SHOUT = 161,   // TabId = 164, Tab = 1, Row = 1, Column = 1
	WARRIOR_UNBRIDLED_WRATH = 159,   // TabId = 164, Tab = 1, Row = 1, Column = 2
	WARRIOR_IMPROVED_CLEAVE = 166,   // TabId = 164, Tab = 1, Row = 2, Column = 0
	WARRIOR_PIERCING_HOWL = 160,   // TabId = 164, Tab = 1, Row = 2, Column = 1
	WARRIOR_BLOOD_CRAZE = 661,   // TabId = 164, Tab = 1, Row = 2, Column = 2
	WARRIOR_COMMANDING_PRESENCE = 154,   // TabId = 164, Tab = 1, Row = 2, Column = 3
	WARRIOR_DUAL_WIELD_SPECIALIZATION = 1581,  // TabId = 164, Tab = 1, Row = 3, Column = 0
	WARRIOR_IMPROVED_EXECUTE = 1542,  // TabId = 164, Tab = 1, Row = 3, Column = 1
	WARRIOR_ENRAGE = 155,   // TabId = 164, Tab = 1, Row = 3, Column = 2
	WARRIOR_PRECISION = 1657,  // TabId = 164, Tab = 1, Row = 4, Column = 0
	WARRIOR_DEATH_WISH = 165,   // TabId = 164, Tab = 1, Row = 4, Column = 1
	WARRIOR_IMPROVED_INTERCEPT = 1543,  // TabId = 164, Tab = 1, Row = 4, Column = 2
	WARRIOR_IMPROVED_BERSERKER_RAGE = 1541,  // TabId = 164, Tab = 1, Row = 5, Column = 0
	WARRIOR_FLURRY = 156,   // TabId = 164, Tab = 1, Row = 5, Column = 2
	WARRIOR_INTENSIFY_RAGE = 1864,  // TabId = 164, Tab = 1, Row = 6, Column = 0
	WARRIOR_BLOODTHIRST = 167,   // TabId = 164, Tab = 1, Row = 6, Column = 1
	WARRIOR_IMPROVED_WHIRLWIND = 1655,  // TabId = 164, Tab = 1, Row = 6, Column = 3
	WARRIOR_FURIOUS_ATTACKS = 1865,  // TabId = 164, Tab = 1, Row = 7, Column = 0
	WARRIOR_IMPROVED_BERSERKER_STANCE = 1658,  // TabId = 164, Tab = 1, Row = 7, Column = 3
	WARRIOR_HEROIC_FURY = 1868,  // TabId = 164, Tab = 1, Row = 8, Column = 0
	WARRIOR_RAMPAGE = 1659,  // TabId = 164, Tab = 1, Row = 8, Column = 1
	WARRIOR_BLOODSURGE = 1866,  // TabId = 164, Tab = 1, Row = 8, Column = 2
	WARRIOR_UNENDING_FURY = 2234,  // TabId = 164, Tab = 1, Row = 9, Column = 1
	WARRIOR_TITANS_GRIP = 1867   // TabId = 164, Tab = 1, Row = 10, Column = 1
};

//class Player;

class PlayerbotWarriorAI : PlayerbotClassAI
{

private:

	// ARMS
	uint32	BATTLE_STANCE,
			CHARGE,
			HEROIC_STRIKE,
			REND,
			THUNDER_CLAP,
			HAMSTRING,
			MOCKING_BLOW,
			RETALIATION,
			SWEEPING_STRIKES,
			MORTAL_STRIKE,
			BLADESTORM,
			HEROIC_THROW,
			SHATTERING_THROW,
			TASTE_FOR_BLOOD,
			SUDDEN_DEATH;

	// PROTECTION
	uint32	DEFENSIVE_STANCE,
			BLOODRAGE,
			SUNDER_ARMOR,
			TAUNT,
			SHIELD_BASH,
			REVENGE,
			SHIELD_BLOCK,
			DISARM,
			SHIELD_WALL,
			SHIELD_SLAM,
			VIGILANCE,
			DEVASTATE,
			SHOCKWAVE,
			CONCUSSION_BLOW,
			SPELL_REFLECTION,
			LAST_STAND;

	// FURY
	uint32	BERSERKER_STANCE,
			BATTLE_SHOUT,
			DEMORALIZING_SHOUT,
			OVERPOWER,
			CLEAVE,
			INTIMIDATING_SHOUT,
			EXECUTE,
			CHALLENGING_SHOUT,
			SLAM,
			INTERCEPT,
			DEATH_WISH,
			BERSERKER_RAGE,
			WHIRLWIND,
			PUMMEL,
			BLOODTHIRST,
			RECKLESSNESS,
			RAMPAGE,
			HEROIC_FURY,
			COMMANDING_SHOUT,
			ENRAGED_REGENERATION,
			PIERCING_HOWL,
			SLAM_PROC,
			BLOODSURGE;

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

	// general
	uint32	AUTO_SHOT;

	uint32	SpellSequence = 0; 

public:

    PlayerbotWarriorAI(Player * const master, Player * const bot, PlayerbotAI * const ai);
    virtual ~PlayerbotWarriorAI();

    bool Pull();

    // Utility Functions
    bool CanPull();

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

	CombatManeuverReturns DoFirstCombatManeuverPVE(Unit *pTarget);
    CombatManeuverReturns DoNextCombatManeuverPVE(Unit *pTarget);
    CombatManeuverReturns DoFirstCombatManeuverPVP(Unit *pTarget);
    CombatManeuverReturns DoNextCombatManeuverPVP(Unit *pTarget);

private:

	CombatManeuverReturns DoManeuver_Idle_Forms_Start(void);

//	CombatManeuverReturns DoManeuver_Idle_Cure_Detremental(void);

//	CombatManeuverReturns DoManeuver_Idle_SelfBuff(void);

//	CombatManeuverReturns DoManeuver_Idle_Rez_Prep(Player *target);
//	CombatManeuverReturns DoManeuver_Idle_Rez(Player *target);
//	CombatManeuverReturns DoManeuver_Idle_Rez_Post(Player *target);

	CombatManeuverReturns DoManeuver_Idle_Heal_Prep(Player *target);
//	CombatManeuverReturns DoManeuver_Idle_Heal(Player *target);
//	CombatManeuverReturns DoManeuver_Idle_Heal_Post(Player *target);

//	CombatManeuverReturns DoManeuver_Idle_Buff_Prep(void);
//	CombatManeuverReturns DoManeuver_Idle_Buff(void);
//	CombatManeuverReturns DoManeuver_Idle_Buff_Post(void);

//	CombatManeuverReturns DoManeuver_Idle_Pet_Summon(void);

//	CombatManeuverReturns DoManeuver_Idle_Pet_BuffnHeal(void);

//	CombatManeuverReturns DoManeuver_Idle_Forms_End(void);

private:
	
	//Buff/rebuff shouts
	void CheckShouts();
};

#endif
