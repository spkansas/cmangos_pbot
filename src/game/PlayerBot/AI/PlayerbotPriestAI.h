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

#ifndef _PLAYERBOTPRIESTAI_H
#define _PLAYERBOTPRIESTAI_H

#include "../Base/PlayerbotClassAI.h"

enum
{
    SPELL_HOLY,
    SPELL_SHADOWMAGIC,
    SPELL_DISCIPLINE
};

enum TalentsPriest  // 0x010
{
	PRIEST_UNBREAKABLE_WILL = 342,   // TabId = 201, Tab = 0, Row = 0, Column = 1
	PRIEST_TWIN_DISCIPLINES = 1898,  // TabId = 201, Tab = 0, Row = 0, Column = 2
	PRIEST_SILENT_RESOLVE = 352,   // TabId = 201, Tab = 0, Row = 1, Column = 0
	PRIEST_IMPROVED_INNER_FIRE = 346,   // TabId = 201, Tab = 0, Row = 1, Column = 1
	PRIEST_IMPROVED_POWER_WORD_FORTITUDE = 344,   // TabId = 201, Tab = 0, Row = 1, Column = 2
	PRIEST_MARTYRDOM = 321,   // TabId = 201, Tab = 0, Row = 1, Column = 3
	PRIEST_MEDITATION = 347,   // TabId = 201, Tab = 0, Row = 2, Column = 0
	PRIEST_INNER_FOCUS = 348,   // TabId = 201, Tab = 0, Row = 2, Column = 1
	PRIEST_IMPROVED_POWER_WORD_SHIELD = 343,   // TabId = 201, Tab = 0, Row = 2, Column = 2
	PRIEST_ABSOLUTION = 1769,  // TabId = 201, Tab = 0, Row = 3, Column = 0
	PRIEST_MENTAL_AGILITY = 341,   // TabId = 201, Tab = 0, Row = 3, Column = 1
	PRIEST_IMPROVED_MANA_BURN = 350,   // TabId = 201, Tab = 0, Row = 3, Column = 3
	PRIEST_REFLECTIVE_SHIELD = 2268,  // TabId = 201, Tab = 0, Row = 4, Column = 0
	PRIEST_MENTAL_STRENGTH = 1201,  // TabId = 201, Tab = 0, Row = 4, Column = 1
	PRIEST_SOUL_WARDING = 351,   // TabId = 201, Tab = 0, Row = 4, Column = 2
	PRIEST_FOCUSED_POWER = 1771,  // TabId = 201, Tab = 0, Row = 5, Column = 0
	PRIEST_ENLIGHTENMENT = 1772,  // TabId = 201, Tab = 0, Row = 5, Column = 2
	PRIEST_FOCUSED_WILL = 1858,  // TabId = 201, Tab = 0, Row = 6, Column = 0
	PRIEST_POWER_INFUSION = 322,   // TabId = 201, Tab = 0, Row = 6, Column = 1
	PRIEST_IMPROVED_FLASH_HEAL = 1773,  // TabId = 201, Tab = 0, Row = 6, Column = 2
	PRIEST_RENEWED_HOPE = 2235,  // TabId = 201, Tab = 0, Row = 7, Column = 0
	PRIEST_RAPTURE = 1896,  // TabId = 201, Tab = 0, Row = 7, Column = 1
	PRIEST_ASPIRATION = 1894,  // TabId = 201, Tab = 0, Row = 7, Column = 2
	PRIEST_DIVINE_AEGIS = 1895,  // TabId = 201, Tab = 0, Row = 8, Column = 0
	PRIEST_PAIN_SUPPRESSION = 1774,  // TabId = 201, Tab = 0, Row = 8, Column = 1
	PRIEST_GRACE = 1901,  // TabId = 201, Tab = 0, Row = 8, Column = 2
	PRIEST_BORROWED_TIME = 1202,  // TabId = 201, Tab = 0, Row = 9, Column = 1
	PRIEST_PENANCE = 1897,  // TabId = 201, Tab = 0, Row = 10, Column = 1
	PRIEST_HEALING_FOCUS = 410,   // TabId = 202, Tab = 1, Row = 0, Column = 0
	PRIEST_IMPROVED_RENEW = 406,   // TabId = 202, Tab = 1, Row = 0, Column = 1
	PRIEST_HOLY_SPECIALIZATION = 401,   // TabId = 202, Tab = 1, Row = 0, Column = 2
	PRIEST_SPELL_WARDING = 411,   // TabId = 202, Tab = 1, Row = 1, Column = 1
	PRIEST_DIVINE_FURY = 1181,  // TabId = 202, Tab = 1, Row = 1, Column = 2
	PRIEST_DESPERATE_PRAYER = 442,   // TabId = 202, Tab = 1, Row = 2, Column = 0
	PRIEST_BLESSED_RECOVERY = 1636,  // TabId = 202, Tab = 1, Row = 2, Column = 1
	PRIEST_INSPIRATION = 361,   // TabId = 202, Tab = 1, Row = 2, Column = 3
	PRIEST_HOLY_REACH = 1635,  // TabId = 202, Tab = 1, Row = 3, Column = 0
	PRIEST_IMPROVED_HEALIN = 408,   // TabId = 202, Tab = 1, Row = 3, Column = 1
	PRIEST_SEARING_LIGHT = 403,   // TabId = 202, Tab = 1, Row = 3, Column = 2
	PRIEST_HEALING_PRAYERS = 413,   // TabId = 202, Tab = 1, Row = 4, Column = 0
	PRIEST_SPIRIT_OF_REDEMPTION = 1561,  // TabId = 202, Tab = 1, Row = 4, Column = 1
	PRIEST_SPIRITUAL_GUIDANCE = 402,   // TabId = 202, Tab = 1, Row = 4, Column = 2
	PRIEST_SURGE_OF_LIGHT = 1766,  // TabId = 202, Tab = 1, Row = 5, Column = 0
	PRIEST_SPIRITUAL_HEALING = 404,   // TabId = 202, Tab = 1, Row = 5, Column = 2
	PRIEST_HOLY_CONCENTRATION = 1768,  // TabId = 202, Tab = 1, Row = 6, Column = 0
	PRIEST_LIGHTWELL = 1637,  // TabId = 202, Tab = 1, Row = 6, Column = 1
	PRIEST_BLESSED_RESILIENCE = 1765,  // TabId = 202, Tab = 1, Row = 6, Column = 2
	PRIEST_BODY_AND_SOUL = 2279,  // TabId = 202, Tab = 1, Row = 7, Column = 0
	PRIEST_EMPOWERED_HEALING = 1767,  // TabId = 202, Tab = 1, Row = 7, Column = 1
	PRIEST_SERENDIPITY = 1904,  // TabId = 202, Tab = 1, Row = 7, Column = 2
	PRIEST_EMPOWERED_RENEW = 1902,  // TabId = 202, Tab = 1, Row = 8, Column = 0
	PRIEST_CIRCLE_OF_HEALING = 1815,  // TabId = 202, Tab = 1, Row = 8, Column = 1
	PRIEST_TEST_OF_FAITH = 1903,  // TabId = 202, Tab = 1, Row = 8, Column = 2
	PRIEST_DIVINE_PROVIDENCE = 1905,  // TabId = 202, Tab = 1, Row = 9, Column = 1
	PRIEST_GUARDIAN_SPIRIT = 1911,  // TabId = 202, Tab = 1, Row = 10, Column = 1
	PRIEST_SPIRIT_TAP = 465,   // TabId = 203, Tab = 2, Row = 0, Column = 0
	PRIEST_IMPROVED_SPIRIT_TAP = 2027,  // TabId = 203, Tab = 2, Row = 0, Column = 1
	PRIEST_DARKNESS = 462,   // TabId = 203, Tab = 2, Row = 0, Column = 2
	PRIEST_SHADOW_AFFINITY = 466,   // TabId = 203, Tab = 2, Row = 1, Column = 0
	PRIEST_IMPROVED_SHADOW_WORD_PAIN = 482,   // TabId = 203, Tab = 2, Row = 1, Column = 1
	PRIEST_SHADOW_FOCUS = 463,   // TabId = 203, Tab = 2, Row = 1, Column = 2
	PRIEST_IMPROVED_PSYCHIC_SCREAM = 542,   // TabId = 203, Tab = 2, Row = 2, Column = 0
	PRIEST_IMPROVED_MIND_BLAST = 481,   // TabId = 203, Tab = 2, Row = 2, Column = 1
	PRIEST_MIND_FLAY = 501,   // TabId = 203, Tab = 2, Row = 2, Column = 2
	PRIEST_VEILED_SHADOWS = 483,   // TabId = 203, Tab = 2, Row = 3, Column = 1
	PRIEST_SHADOW_REACH = 881,   // TabId = 203, Tab = 2, Row = 3, Column = 2
	PRIEST_SHADOW_WEAVING = 461,   // TabId = 203, Tab = 2, Row = 3, Column = 3
	PRIEST_SILENCE = 541,   // TabId = 203, Tab = 2, Row = 4, Column = 0
	PRIEST_VAMPIRIC_EMBRACE = 484,   // TabId = 203, Tab = 2, Row = 4, Column = 1
	PRIEST_IMPROVED_VAMPIRIC_EMBRACE = 1638,  // TabId = 203, Tab = 2, Row = 4, Column = 2
	PRIEST_FOCUSED_MIND = 1777,  // TabId = 203, Tab = 2, Row = 4, Column = 3
	PRIEST_MIND_MELT = 1781,  // TabId = 203, Tab = 2, Row = 5, Column = 0
	PRIEST_IMPROVED_DEVOURING_PLAGUE = 2267,  // TabId = 203, Tab = 2, Row = 5, Column = 2
	PRIEST_SHADOWFORM = 521,   // TabId = 203, Tab = 2, Row = 6, Column = 1
	PRIEST_SHADOW_POWER = 1778,  // TabId = 203, Tab = 2, Row = 6, Column = 2
	PRIEST_IMPROVED_SHADOWFORM = 1906,  // TabId = 203, Tab = 2, Row = 7, Column = 0
	PRIEST_MISERY = 1816,  // TabId = 203, Tab = 2, Row = 7, Column = 2
	PRIEST_PSYCHIC_HORROR = 1908,  // TabId = 203, Tab = 2, Row = 8, Column = 0
	PRIEST_VAMPIRIC_TOUCH = 1779,  // TabId = 203, Tab = 2, Row = 8, Column = 1
	PRIEST_PAIN_AND_SUFFERING = 1909,  // TabId = 203, Tab = 2, Row = 8, Column = 2
	PRIEST_TWISTED_FAITH = 1907,  // TabId = 203, Tab = 2, Row = 9, Column = 2
	PRIEST_DISPERSION = 1910   // TabId = 203, Tab = 2, Row = 10, Column = 1
};

enum PriestSpells
{
    ABOLISH_DISEASE_1               = 552,
    BINDING_HEAL_1                  = 32546,
    BLESSED_HEALING_1               = 70772,
    CIRCLE_OF_HEALING_1             = 34861,
    CURE_DISEASE_1                  = 528,
    DESPERATE_PRAYER_1              = 19236,
    DEVOURING_PLAGUE_1              = 2944,
    DISPEL_MAGIC_1                  = 527,
    DISPERSION_1                    = 47585,
    DIVINE_HYMN_1                   = 64843,
    DIVINE_SPIRIT_1                 = 14752,
    FADE_1                          = 586,
    FEAR_WARD_1                     = 6346,
    FLASH_HEAL_1                    = 2061,
    GREATER_HEAL_1                  = 2060,
    GUARDIAN_SPIRIT_1               = 47788,
    HEAL_1                          = 2054,
    HOLY_FIRE_1                     = 14914,
    HOLY_NOVA_1                     = 15237,
    HYMN_OF_HOPE_1                  = 64901,
    INNER_FIRE_1                    = 588,
    INNER_FOCUS_1                   = 14751,
    LESSER_HEAL_1                   = 2050,
    LEVITATE_1                      = 1706,
    LIGHTWELL_1                     = 724,
    MANA_BURN_1                     = 8129,
    MASS_DISPEL_1                   = 32375,
    MIND_BLAST_1                    = 8092,
    MIND_CONTROL_1                  = 605,
    MIND_FLAY_1                     = 15407,
    MIND_SEAR_1                     = 48045,
    MIND_SOOTHE_1                   = 453,
    MIND_VISION_1                   = 2096,
    PAIN_SUPPRESSION_1              = 33206,
    PENANCE_1                       = 47540,
    POWER_INFUSION_1                = 10060,
    POWER_WORD_FORTITUDE_1          = 1243,
    POWER_WORD_SHIELD_1             = 17,
    PRAYER_OF_FORTITUDE_1           = 21562,
    PRAYER_OF_HEALING_1             = 596,
    PRAYER_OF_MENDING_1             = 33076,
    PRAYER_OF_SHADOW_PROTECTION_1   = 27683,
    PRAYER_OF_SPIRIT_1              = 27681,
    PSYCHIC_HORROR_1                = 64044,
    PSYCHIC_SCREAM_1                = 8122,
    RENEW_1                         = 139,
    RESURRECTION_1                  = 2006,
    SHACKLE_UNDEAD_1                = 9484,
    SHADOW_PROTECTION_1             = 976,
    SHADOW_WORD_DEATH_1             = 32379,
    SHADOW_WORD_PAIN_1              = 589,
    SHADOWFIEND_1                   = 34433,
    SHADOWFORM_1                    = 15473,
    SHOOT_1                         = 5019,
    SILENCE_1                       = 15487,
    SMITE_1                         = 585,
    VAMPIRIC_EMBRACE_1              = 15286,
    VAMPIRIC_TOUCH_1                = 34914
};
//class Player;

class PlayerbotPriestAI : PlayerbotClassAI
{
public:
    PlayerbotPriestAI(Player * const master, Player * const bot, PlayerbotAI * const ai);
    virtual ~PlayerbotPriestAI();

    // all non combat actions go here, ex buffs, heals, rezzes
 //   void DoNonCombatActions();

    // Utility Functions
    bool CastHoTOnTank();

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

	CombatManeuverReturns DoNextManeuver_Heal_ClassSetup(Unit *pTarget);

    CombatManeuverReturns DoFirstCombatManeuverPVE(Unit* pTarget);
    CombatManeuverReturns DoNextCombatManeuverPVE(Unit* pTarget);
    CombatManeuverReturns DoFirstCombatManeuverPVP(Unit* pTarget);
    CombatManeuverReturns DoNextCombatManeuverPVP(Unit* pTarget);

private:

    CombatManeuverReturns DoManeuver_Idle_SelfBuff(void);
//	CombatManeuverReturns DoManeuver_Idle_SummonPet(void);

//  CombatManeuverReturns DoManeuver_Idle_Rez_Prep(Player* target);
//  CombatManeuverReturns DoManeuver_Idle_Rez(Player* target);
//  CombatManeuverReturns DoManeuver_Idle_Rez_Post(Player* target);

    CombatManeuverReturns DoManeuver_Idle_Heal_Prep(Player* target);
//  CombatManeuverReturns DoManeuver_Idle_Heal(Player* target);
//  CombatManeuverReturns DoManeuver_Idle_Heal_Post(Player* target);

private:

    CombatManeuverReturns CastSpell(uint32 nextAction, Unit *pTarget = nullptr) { return CastSpellWand(nextAction, pTarget, SHOOT); }

    // Heals the target based off its hps
    CombatManeuverReturns HealPlayer(Player* target);
	
	// holy
    uint32 BINDING_HEAL,
           CIRCLE_OF_HEALING,
           CLEARCASTING,
           DESPERATE_PRAYER,
           FLASH_HEAL,
           GREATER_HEAL,
           HEAL,
           HOLY_FIRE,
           HOLY_NOVA,
           LESSER_HEAL,
           MANA_BURN,
           PRAYER_OF_HEALING,
           PRAYER_OF_MENDING,
           RENEW,
           RESURRECTION,
           SMITE,
           CURE_DISEASE;
    // ranged
    uint32 SHOOT;

    // shadowmagic
    uint32 FADE,
           SHADOW_WORD_PAIN,
           MIND_BLAST,
           SCREAM,
           MIND_FLAY,
           DEVOURING_PLAGUE,
           SHADOW_PROTECTION,
           VAMPIRIC_TOUCH,
           PRAYER_OF_SHADOW_PROTECTION,
           SHADOWFIEND,
           MIND_SEAR,
           SHADOWFORM,
           VAMPIRIC_EMBRACE;

    // discipline
    uint32 POWER_WORD_SHIELD,
           INNER_FIRE,
           POWER_WORD_FORTITUDE,
           PRAYER_OF_FORTITUDE,
           FEAR_WARD,
           POWER_INFUSION,
           MASS_DISPEL,
           PENANCE,
           DIVINE_SPIRIT,
           PRAYER_OF_SPIRIT,
           INNER_FOCUS;

    // racial
    uint32 ARCANE_TORRENT,
           GIFT_OF_THE_NAARU,
           STONEFORM,
           ESCAPE_ARTIST,
           EVERY_MAN_FOR_HIMSELF,
           SHADOWMELD,
           WAR_STOMP,
           BERSERKING,
           WILL_OF_THE_FORSAKEN;
};

#endif
