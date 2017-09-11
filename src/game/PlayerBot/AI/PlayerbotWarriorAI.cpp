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

#include "PlayerbotWarriorAI.h"
#include "../Base/PlayerbotMgr.h"

class PlayerbotAI;
PlayerbotWarriorAI::PlayerbotWarriorAI(Player* const master, Player* const bot, PlayerbotAI* const ai) : PlayerbotClassAI(master, bot, ai)
{
    AUTO_SHOT               = GetAI()->initSpell(AUTO_SHOT_2); // GENERAL

    BATTLE_STANCE           = GetAI()->initSpell(BATTLE_STANCE_1); //ARMS
    CHARGE                  = GetAI()->initSpell(CHARGE_1); //ARMS
    OVERPOWER               = GetAI()->initSpell(OVERPOWER_1); // ARMS
    HEROIC_STRIKE           = GetAI()->initSpell(HEROIC_STRIKE_1); //ARMS
    REND                    = GetAI()->initSpell(REND_1); //ARMS
    THUNDER_CLAP            = GetAI()->initSpell(THUNDER_CLAP_1);  //ARMS
    HAMSTRING               = GetAI()->initSpell(HAMSTRING_1);  //ARMS
    MOCKING_BLOW            = GetAI()->initSpell(MOCKING_BLOW_1);  //ARMS
    RETALIATION             = GetAI()->initSpell(RETALIATION_1);  //ARMS
    SWEEPING_STRIKES        = GetAI()->initSpell(SWEEPING_STRIKES_1); //ARMS
    MORTAL_STRIKE           = GetAI()->initSpell(MORTAL_STRIKE_1);  //ARMS
    BLADESTORM              = GetAI()->initSpell(BLADESTORM_1);  //ARMS
    HEROIC_THROW            = GetAI()->initSpell(HEROIC_THROW_1);  //ARMS
    SHATTERING_THROW        = GetAI()->initSpell(SHATTERING_THROW_1);  //ARMS
    BLOODRAGE               = GetAI()->initSpell(BLOODRAGE_1); //PROTECTION
    DEFENSIVE_STANCE        = GetAI()->initSpell(DEFENSIVE_STANCE_1); //PROTECTION
    DEVASTATE               = GetAI()->initSpell(DEVASTATE_1); //PROTECTION
    SUNDER_ARMOR            = GetAI()->initSpell(SUNDER_ARMOR_1); //PROTECTION
    TAUNT                   = GetAI()->initSpell(TAUNT_1); //PROTECTION
    SHIELD_BASH             = GetAI()->initSpell(SHIELD_BASH_1); //PROTECTION
    REVENGE                 = GetAI()->initSpell(REVENGE_1); //PROTECTION
    SHIELD_BLOCK            = GetAI()->initSpell(SHIELD_BLOCK_1); //PROTECTION
    DISARM                  = GetAI()->initSpell(DISARM_1); //PROTECTION
    SHIELD_WALL             = GetAI()->initSpell(SHIELD_WALL_1); //PROTECTION
    SHIELD_SLAM             = GetAI()->initSpell(SHIELD_SLAM_1); //PROTECTION
    VIGILANCE               = GetAI()->initSpell(VIGILANCE_1); //PROTECTION
    DEVASTATE               = GetAI()->initSpell(DEVASTATE_1); //PROTECTION
    SHOCKWAVE               = GetAI()->initSpell(SHOCKWAVE_1); //PROTECTION
    CONCUSSION_BLOW         = GetAI()->initSpell(CONCUSSION_BLOW_1); //PROTECTION
    SPELL_REFLECTION        = GetAI()->initSpell(SPELL_REFLECTION_1); //PROTECTION
    LAST_STAND              = GetAI()->initSpell(LAST_STAND_1); //PROTECTION
    BATTLE_SHOUT            = GetAI()->initSpell(BATTLE_SHOUT_1); //FURY
    DEMORALIZING_SHOUT      = GetAI()->initSpell(DEMORALIZING_SHOUT_1); //FURY
    CLEAVE                  = GetAI()->initSpell(CLEAVE_1); //FURY
    INTIMIDATING_SHOUT      = GetAI()->initSpell(INTIMIDATING_SHOUT_1); //FURY
    EXECUTE                 = GetAI()->initSpell(EXECUTE_1); //FURY
    CHALLENGING_SHOUT       = GetAI()->initSpell(CHALLENGING_SHOUT_1); //FURY
    SLAM                    = GetAI()->initSpell(SLAM_1); //FURY
    BERSERKER_STANCE        = GetAI()->initSpell(BERSERKER_STANCE_1); //FURY
    INTERCEPT               = GetAI()->initSpell(INTERCEPT_1); //FURY
    DEATH_WISH              = GetAI()->initSpell(DEATH_WISH_1); //FURY
    BERSERKER_RAGE          = GetAI()->initSpell(BERSERKER_RAGE_1); //FURY
    WHIRLWIND               = GetAI()->initSpell(WHIRLWIND_1); //FURY
    PUMMEL                  = GetAI()->initSpell(PUMMEL_1); //FURY
    BLOODTHIRST             = GetAI()->initSpell(BLOODTHIRST_1); //FURY
    RECKLESSNESS            = GetAI()->initSpell(RECKLESSNESS_1); //FURY
    RAMPAGE                 = 0; // passive
    HEROIC_FURY             = GetAI()->initSpell(HEROIC_FURY_1); //FURY
    COMMANDING_SHOUT        = GetAI()->initSpell(COMMANDING_SHOUT_1); //FURY
    ENRAGED_REGENERATION    = GetAI()->initSpell(ENRAGED_REGENERATION_1); //FURY
    PIERCING_HOWL           = GetAI()->initSpell(PIERCING_HOWL_1); //FURY

    RECENTLY_BANDAGED       = 11196; // first aid check

    // racial
    GIFT_OF_THE_NAARU       = GetAI()->initSpell(GIFT_OF_THE_NAARU_WARRIOR); // draenei
    STONEFORM               = GetAI()->initSpell(STONEFORM_ALL); // dwarf
    ESCAPE_ARTIST           = GetAI()->initSpell(ESCAPE_ARTIST_ALL); // gnome
    EVERY_MAN_FOR_HIMSELF   = GetAI()->initSpell(EVERY_MAN_FOR_HIMSELF_ALL); // human
    SHADOWMELD              = GetAI()->initSpell(SHADOWMELD_ALL); // night elf
    BLOOD_FURY              = GetAI()->initSpell(BLOOD_FURY_MELEE_CLASSES); // orc
    WAR_STOMP               = GetAI()->initSpell(WAR_STOMP_ALL); // tauren
    BERSERKING              = GetAI()->initSpell(BERSERKING_ALL); // troll
    WILL_OF_THE_FORSAKEN    = GetAI()->initSpell(WILL_OF_THE_FORSAKEN_ALL); // undead

    //Procs
    SLAM_PROC               = GetAI()->initSpell(SLAM_PROC_1);
    BLOODSURGE              = GetAI()->initSpell(BLOODSURGE_1);
    TASTE_FOR_BLOOD         = GetAI()->initSpell(TASTE_FOR_BLOOD_1);
    SUDDEN_DEATH            = GetAI()->initSpell(SUDDEN_DEATH_1);
}
PlayerbotWarriorAI::~PlayerbotWarriorAI() {}

CombatManeuverReturns PlayerbotWarriorAI::DoFirstCombatManeuverPVE(Unit* pTarget)
{
    if (!GetAI())  return RETURN_NO_ACTION_ERROR;
    if (!m_bot) return RETURN_NO_ACTION_ERROR;

    float fTargetDist = m_bot->GetCombatDistance(pTarget, true);

    if (DEFENSIVE_STANCE && (GetAI()->GetCombatOrder() & PlayerbotAI::ORDERS_TANK))
    {
        if (!m_bot->HasAura(DEFENSIVE_STANCE, EFFECT_INDEX_0) && GetAI()->CastSpell(DEFENSIVE_STANCE))
            return RETURN_CONTINUE;
        else if (TAUNT > 0 && m_bot->HasAura(DEFENSIVE_STANCE, EFFECT_INDEX_0) && GetAI()->CastSpell(TAUNT, *pTarget))
            return RETURN_FINISHED_FIRST_MOVES;
    }

    if (BERSERKER_STANCE)
    {
        if (!m_bot->HasAura(BERSERKER_STANCE, EFFECT_INDEX_0) && GetAI()->CastSpell(BERSERKER_STANCE))
            return RETURN_CONTINUE;
        if (BLOODRAGE > 0 && m_bot->HasAura(BERSERKER_STANCE, EFFECT_INDEX_0) && GetAI()->GetRageAmount() <= 10)
            return GetAI()->CastSpell(BLOODRAGE) ? RETURN_FINISHED_FIRST_MOVES : RETURN_NO_ACTION_ERROR;
        if (INTERCEPT > 0 && m_bot->HasAura(BERSERKER_STANCE, EFFECT_INDEX_0))
        {
            if (fTargetDist < 8.0f)
                return RETURN_NO_ACTION_OK;
            else if (fTargetDist > 25.0f)
                return RETURN_CONTINUE; // wait to come into range
            else if (INTERCEPT > 0 && GetAI()->CastSpell(INTERCEPT, *pTarget))
            {
                float x, y, z;
                pTarget->GetContactPoint(m_bot, x, y, z, 3.666666f);
                m_bot->Relocate(x, y, z);
                return RETURN_FINISHED_FIRST_MOVES;
            }
        }
    }

    if (BATTLE_STANCE)
    {
        if (!m_bot->HasAura(BATTLE_STANCE, EFFECT_INDEX_0) && GetAI()->CastSpell(BATTLE_STANCE))
            return RETURN_CONTINUE;
        if (CHARGE > 0 && m_bot->HasAura(BATTLE_STANCE, EFFECT_INDEX_0))
        {
            if (fTargetDist < 8.0f)
                return RETURN_NO_ACTION_OK;
            if (fTargetDist > 25.0f)
                return RETURN_CONTINUE; // wait to come into range
            else if (CHARGE > 0 && GetAI()->CastSpell(CHARGE, *pTarget))
            {
                float x, y, z;
                pTarget->GetContactPoint(m_bot, x, y, z, 3.666666f);
                m_bot->Relocate(x, y, z);
                return RETURN_FINISHED_FIRST_MOVES;
            }
        }
    }

    return RETURN_NO_ACTION_OK;
}

// TODO: blatant copy of PVE for now, please PVP-port it
CombatManeuverReturns PlayerbotWarriorAI::DoFirstCombatManeuverPVP(Unit *pTarget)
{
    if (!GetAI())  return RETURN_NO_ACTION_ERROR;
    if (!m_bot) return RETURN_NO_ACTION_ERROR;

    float fTargetDist = m_bot->GetCombatDistance(pTarget, true);

    if (DEFENSIVE_STANCE && (GetAI()->GetCombatOrder() & PlayerbotAI::ORDERS_TANK))
    {
        if (!m_bot->HasAura(DEFENSIVE_STANCE, EFFECT_INDEX_0) && GetAI()->CastSpell(DEFENSIVE_STANCE))
            return RETURN_CONTINUE;
        else if (TAUNT > 0 && m_bot->HasAura(DEFENSIVE_STANCE, EFFECT_INDEX_0) && GetAI()->CastSpell(TAUNT, *pTarget))
            return RETURN_FINISHED_FIRST_MOVES;
    }

    if (BERSERKER_STANCE)
    {
        if (!m_bot->HasAura(BERSERKER_STANCE, EFFECT_INDEX_0) && GetAI()->CastSpell(BERSERKER_STANCE))
            return RETURN_CONTINUE;
        if (BLOODRAGE > 0 && m_bot->HasAura(BERSERKER_STANCE, EFFECT_INDEX_0) && GetAI()->GetRageAmount() <= 10)
            return GetAI()->CastSpell(BLOODRAGE) ? RETURN_FINISHED_FIRST_MOVES : RETURN_NO_ACTION_ERROR;
        if (INTERCEPT > 0 && m_bot->HasAura(BERSERKER_STANCE, EFFECT_INDEX_0))
        {
            if (fTargetDist < 8.0f)
                return RETURN_NO_ACTION_OK;
            else if (fTargetDist > 25.0f)
                return RETURN_CONTINUE; // wait to come into range
            else if (INTERCEPT > 0 && GetAI()->CastSpell(INTERCEPT, *pTarget))
            {
                float x, y, z;
                pTarget->GetContactPoint(m_bot, x, y, z, 3.666666f);
                m_bot->Relocate(x, y, z);
                return RETURN_FINISHED_FIRST_MOVES;
            }
        }
    }

    if (BATTLE_STANCE)
    {
        if (!m_bot->HasAura(BATTLE_STANCE, EFFECT_INDEX_0) && GetAI()->CastSpell(BATTLE_STANCE))
            return RETURN_CONTINUE;
        if (CHARGE > 0 && m_bot->HasAura(BATTLE_STANCE, EFFECT_INDEX_0))
        {
            if (fTargetDist < 8.0f)
                return RETURN_NO_ACTION_OK;
            if (fTargetDist > 25.0f)
                return RETURN_CONTINUE; // wait to come into range
            else if (CHARGE > 0 && GetAI()->CastSpell(CHARGE, *pTarget))
            {
                float x, y, z;
                pTarget->GetContactPoint(m_bot, x, y, z, 3.666666f);
                m_bot->Relocate(x, y, z);
                return RETURN_FINISHED_FIRST_MOVES;
            }
        }
    }

    return RETURN_NO_ACTION_OK;
}


CombatManeuverReturns PlayerbotWarriorAI::DoNextCombatManeuverPVE(Unit *pTarget)
{
    if (!GetAI())  return RETURN_NO_ACTION_ERROR;
    if (!m_bot) return RETURN_NO_ACTION_ERROR;

    //Unit* pVictim = pTarget->getVictim();
    //float fTargetDist = m_bot->GetCombatDistance(pTarget, true);
    uint32 spec = m_bot->GetSpec();

    //If we have devastate it will replace SA in our rotation
    //uint32 SUNDER = (DEVASTATE > 0 ? DEVASTATE : SUNDER_ARMOR);

    //Used to determine if this bot is highest on threat
    Unit* newTarget = GetAI()->FindAttacker((PlayerbotAI::ATTACKERINFOTYPE) (PlayerbotAI::AIT_VICTIMSELF | PlayerbotAI::AIT_HIGHESTTHREAT), m_bot);

    // do shouts, berserker rage, etc...
    if (BERSERKER_RAGE > 0 && !m_bot->HasAura(BERSERKER_RAGE, EFFECT_INDEX_0))
        GetAI()->CastSpell(BERSERKER_RAGE);
    else if (BLOODRAGE > 0 && GetAI()->GetRageAmount() <= 10)
        GetAI()->CastSpell(BLOODRAGE);

    CheckShouts();

    switch (spec)
    {
        case WARRIOR_SPEC_ARMS:
            // Execute doesn't scale too well with extra rage and uses up *all* rage preventing use of other skills
            //Haven't found a way to make sudden death work yet, either wrong spell or it needs an effect index(probably)
            if (EXECUTE > 0 && (pTarget->GetHealthPercent() < 20 || m_bot->HasAura(SUDDEN_DEATH)) && GetAI()->GetRageAmount() < 30 && GetAI()->CastSpell (EXECUTE, *pTarget))
                return RETURN_CONTINUE;
            if (REND > 0 && !pTarget->HasAura(REND, EFFECT_INDEX_0) && GetAI()->CastSpell(REND, *pTarget))
                return RETURN_CONTINUE;
            if (MORTAL_STRIKE > 0 && m_bot->IsSpellReady(MORTAL_STRIKE) && GetAI()->CastSpell(MORTAL_STRIKE, *pTarget))
                return RETURN_CONTINUE;
            if (SHATTERING_THROW > 0 && !pTarget->HasAura(SHATTERING_THROW, EFFECT_INDEX_0) && m_bot->IsSpellReady(SHATTERING_THROW) && GetAI()->CastSpell(SHATTERING_THROW, *pTarget))
                return RETURN_CONTINUE;
            if (BLADESTORM > 0 && m_bot->IsSpellReady(BLADESTORM) /*&& GetAI()->GetAttackerCount() >= 3*/ && GetAI()->CastSpell(BLADESTORM, *pTarget))
                return RETURN_CONTINUE;
            // No way to tell if overpower is active (yet), however taste for blood works
            if (OVERPOWER > 0 && m_bot->HasAura(TASTE_FOR_BLOOD) && GetAI()->CastSpell(OVERPOWER, *pTarget))
                return RETURN_CONTINUE;
            if (HEROIC_STRIKE > 0 && GetAI()->CastSpell(HEROIC_STRIKE, *pTarget))
                return RETURN_CONTINUE;
            if (SLAM > 0 && GetAI()->CastSpell(SLAM, *pTarget))
            {
                GetAI()->SetIgnoreUpdateTime(1); // TODO: SetIgnoreUpdateTime takes a uint8 - how will 1.5 work as a value?
                return RETURN_CONTINUE;
            }

        case WARRIOR_SPEC_FURY:
            if (EXECUTE > 0 && pTarget->GetHealthPercent() < 20 && GetAI()->CastSpell (EXECUTE, *pTarget))
                return RETURN_CONTINUE;
            if (BLOODTHIRST > 0 && m_bot->IsSpellReady(BLOODTHIRST) && GetAI()->CastSpell(BLOODTHIRST, *pTarget))
                return RETURN_CONTINUE;
            if (WHIRLWIND > 0 && m_bot->IsSpellReady(WHIRLWIND) && GetAI()->CastSpell(WHIRLWIND, *pTarget))
                return RETURN_CONTINUE;
            if (SLAM > 0 && m_bot->HasAura(BLOODSURGE, EFFECT_INDEX_0) && GetAI()->CastSpell(SLAM, *pTarget))
                return RETURN_CONTINUE;
            if (HEROIC_STRIKE > 0 && GetAI()->CastSpell(HEROIC_STRIKE, *pTarget))
                return RETURN_CONTINUE;

        case WARRIOR_SPEC_PROTECTION:
            if (GetAI()->GetCombatOrder() & PlayerbotAI::ORDERS_TANK && !newTarget && TAUNT > 0 && m_bot->IsSpellReady(TAUNT) && GetAI()->CastSpell(TAUNT, *pTarget))
                return RETURN_CONTINUE;
            // No way to tell if revenge is active (yet)
            /*if (REVENGE > 0 && GetAI()->CastSpell(REVENGE, *pTarget))
                return RETURN_CONTINUE;*/
            if (REND > 0 && !pTarget->HasAura(REND, EFFECT_INDEX_0) && GetAI()->CastSpell(REND, *pTarget))
                return RETURN_CONTINUE;
            if (THUNDER_CLAP > 0 && !pTarget->HasAura(THUNDER_CLAP) && GetAI()->CastSpell(THUNDER_CLAP, *pTarget))
                return RETURN_CONTINUE;
            if (DEMORALIZING_SHOUT > 0 && !pTarget->HasAura(DEMORALIZING_SHOUT, EFFECT_INDEX_0) && GetAI()->CastSpell(DEMORALIZING_SHOUT, *pTarget))
                return RETURN_CONTINUE;
            if (CONCUSSION_BLOW > 0 && m_bot->IsSpellReady(CONCUSSION_BLOW) && GetAI()->CastSpell(CONCUSSION_BLOW, *pTarget))
                return RETURN_CONTINUE;
            if (SHOCKWAVE > 0 && m_bot->IsSpellReady(SHOCKWAVE) && GetAI()->CastSpell(SHOCKWAVE, *pTarget))
                return RETURN_CONTINUE;
            if (SHIELD_SLAM > 0 && m_bot->IsSpellReady(SHIELD_SLAM) && GetAI()->CastSpell(SHIELD_SLAM, *pTarget))
                return RETURN_CONTINUE;
            /*if (SUNDER > 0 && !pTarget->HasAura(SUNDER_ARMOR) && GetAI()->CastSpell(SUNDER, *pTarget))
                return RETURN_CONTINUE;*/
            if (HEROIC_STRIKE > 0 && GetAI()->CastSpell(HEROIC_STRIKE, *pTarget))
                return RETURN_CONTINUE;

        /*case WarriorSpellPreventing:
            if (SHIELD_BASH > 0 && GetAI()->CastSpell(SHIELD_BASH, *pTarget))
                return RETURN_CONTINUE;
            if (PUMMEL > 0 && GetAI()->CastSpell(PUMMEL, *pTarget))
                return RETURN_CONTINUE;
            if (SPELL_REFLECTION > 0 && !m_bot->HasAura(SPELL_REFLECTION, EFFECT_INDEX_0) && GetAI()->CastSpell(SPELL_REFLECTION, *m_bot))
                return RETURN_CONTINUE;
            break;

        case WarriorBattle:
            if (LAST_STAND > 0 && !m_bot->HasAura(LAST_STAND, EFFECT_INDEX_0) && m_bot->GetHealthPercent() < 50 && GetAI()->CastSpell(LAST_STAND, *m_bot))
                return RETURN_CONTINUE;
            if (DEATH_WISH > 0 && !m_bot->HasAura(DEATH_WISH, EFFECT_INDEX_0) && GetAI()->CastSpell(DEATH_WISH, *m_bot))
                return RETURN_CONTINUE;
            if (RETALIATION > 0 && pVictim == m_bot && GetAI()->GetAttackerCount() >= 2 && !m_bot->HasAura(RETALIATION, EFFECT_INDEX_0) && GetAI()->CastSpell(RETALIATION, *m_bot))
                return RETURN_CONTINUE;
            if (SWEEPING_STRIKES > 0 && GetAI()->GetAttackerCount() >= 2 && !m_bot->HasAura(SWEEPING_STRIKES, EFFECT_INDEX_0) && GetAI()->CastSpell(SWEEPING_STRIKES, *m_bot))
                return RETURN_CONTINUE;
            if (INTIMIDATING_SHOUT > 0 && GetAI()->GetAttackerCount() > 5 && GetAI()->CastSpell(INTIMIDATING_SHOUT, *pTarget))
                return RETURN_CONTINUE;
            if (ENRAGED_REGENERATION > 0 && !m_bot->HasAura(BERSERKER_RAGE, EFFECT_INDEX_0) && !m_bot->HasAura(ENRAGED_REGENERATION, EFFECT_INDEX_0) && m_bot->GetHealth() < m_bot->GetMaxHealth() * 0.5 && GetAI()->CastSpell(ENRAGED_REGENERATION, *m_bot))
                return RETURN_CONTINUE;
            if (HAMSTRING > 0 && !pTarget->HasAura(HAMSTRING, EFFECT_INDEX_0) && GetAI()->CastSpell(HAMSTRING, *pTarget))
                return RETURN_CONTINUE;
            if (CHALLENGING_SHOUT > 0 && pVictim != m_bot && GetAI()->GetHealthPercent() > 25 && !pTarget->HasAura(MOCKING_BLOW, EFFECT_INDEX_0) && !pTarget->HasAura(CHALLENGING_SHOUT, EFFECT_INDEX_0) && GetAI()->CastSpell(CHALLENGING_SHOUT, *pTarget))
                return RETURN_CONTINUE;
            if (CLEAVE > 0 && GetAI()->CastSpell(CLEAVE, *pTarget))
                return RETURN_CONTINUE;
            if (PIERCING_HOWL > 0 && && GetAI()->GetAttackerCount() >= 3 && !pTarget->HasAura(WAR_STOMP, EFFECT_INDEX_0) && !pTarget->HasAura(PIERCING_HOWL, EFFECT_INDEX_0) && !pTarget->HasAura(SHOCKWAVE, EFFECT_INDEX_0) && !pTarget->HasAura(CONCUSSION_BLOW, EFFECT_INDEX_0) && GetAI()->CastSpell(PIERCING_HOWL, *pTarget))
                return RETURN_CONTINUE;
            if (MOCKING_BLOW > 0 && pVictim != m_bot && GetAI()->GetHealthPercent() > 25 && !pTarget->HasAura(MOCKING_BLOW, EFFECT_INDEX_0) && !pTarget->HasAura(CHALLENGING_SHOUT, EFFECT_INDEX_0) && GetAI()->CastSpell(MOCKING_BLOW, *pTarget))
                return RETURN_CONTINUE;
            if (HEROIC_THROW > 0 && GetAI()->CastSpell(HEROIC_THROW, *pTarget))
                return RETURN_CONTINUE;
            if (m_bot->getRace() == RACE_TAUREN && !pTarget->HasAura(WAR_STOMP, EFFECT_INDEX_0) && !pTarget->HasAura(PIERCING_HOWL, EFFECT_INDEX_0) && !pTarget->HasAura(SHOCKWAVE, EFFECT_INDEX_0) && !pTarget->HasAura(CONCUSSION_BLOW, EFFECT_INDEX_0) && GetAI()->CastSpell(WAR_STOMP, *pTarget))
                return RETURN_CONTINUE;
            if (m_bot->getRace() == RACE_HUMAN && m_bot->hasUnitState(UNIT_STAT_STUNNED) || m_bot->HasAuraType(SPELL_AURA_MOD_FEAR) || m_bot->HasAuraType(SPELL_AURA_MOD_DECREASE_SPEED) || m_bot->HasAuraType(SPELL_AURA_MOD_CHARM) && GetAI()->CastSpell(EVERY_MAN_FOR_HIMSELF, *m_bot))
                return RETURN_CONTINUE;
            if (m_bot->getRace() == RACE_UNDEAD && m_bot->HasAuraType(SPELL_AURA_MOD_FEAR) || m_bot->HasAuraType(SPELL_AURA_MOD_CHARM) && GetAI()->CastSpell(WILL_OF_THE_FORSAKEN, *m_bot))
                return RETURN_CONTINUE;
            if (m_bot->getRace() == RACE_DWARF && m_bot->HasAuraState(AURA_STATE_DEADLY_POISON) && GetAI()->CastSpell(STONEFORM, *m_bot))
                return RETURN_CONTINUE;
            if (m_bot->getRace() == RACE_GNOME && m_bot->hasUnitState(UNIT_STAT_STUNNED) || m_bot->HasAuraType(SPELL_AURA_MOD_DECREASE_SPEED) && GetAI()->CastSpell(ESCAPE_ARTIST, *m_bot))
                return RETURN_CONTINUE;
            if (m_bot->getRace() == RACE_NIGHTELF && pVictim == m_bot && GetAI()->GetHealthPercent() < 25 && !m_bot->HasAura(SHADOWMELD, EFFECT_INDEX_0) && GetAI()->CastSpell(SHADOWMELD, *m_bot))
                return RETURN_CONTINUE;
            if (m_bot->getRace() == RACE_ORC && !m_bot->HasAura(BLOOD_FURY, EFFECT_INDEX_0) && GetAI()->CastSpell(BLOOD_FURY, *m_bot))
                return RETURN_CONTINUE;
            if (m_bot->getRace() == RACE_TROLL && !m_bot->HasAura(BERSERKING, EFFECT_INDEX_0) && GetAI()->CastSpell(BERSERKING, *m_bot))
                return RETURN_CONTINUE;
            if (m_bot->getRace() == RACE_DRAENEI && GetAI()->GetHealthPercent() < 25 && !m_bot->HasAura(GIFT_OF_THE_NAARU, EFFECT_INDEX_0) && GetAI()->CastSpell(GIFT_OF_THE_NAARU, *m_bot))
                return RETURN_CONTINUE;
            break;

        case WarriorDefensive:
            if (DISARM > 0 && !pTarget->HasAura(DISARM, EFFECT_INDEX_0) && GetAI()->CastSpell(DISARM, *pTarget))
                return RETURN_CONTINUE;
            if (SHIELD_BLOCK > 0 && !m_bot->HasAura(SHIELD_BLOCK, EFFECT_INDEX_0) && GetAI()->CastSpell(SHIELD_BLOCK, *m_bot))
                return RETURN_CONTINUE;
            if (SHIELD_WALL > 0 && !m_bot->HasAura(SHIELD_WALL, EFFECT_INDEX_0) && GetAI()->CastSpell(SHIELD_WALL, *m_bot))
                return RETURN_CONTINUE;
            break;*/
    }

    return RETURN_NO_ACTION_OK;
}

CombatManeuverReturns PlayerbotWarriorAI::DoNextCombatManeuverPVP(Unit* pTarget)
{
    if (GetAI()->CastSpell(HEROIC_STRIKE))
        return RETURN_CONTINUE;

    return DoNextCombatManeuverPVE(pTarget); // TODO: bad idea perhaps, but better than the alternative
}

//Buff and rebuff shouts
void PlayerbotWarriorAI::CheckShouts()
{
    if (!GetAI())  return;
    if (!m_bot) return;

    if (m_bot->GetSpec() == WARRIOR_SPEC_PROTECTION && COMMANDING_SHOUT > 0)
    {
        if (!m_bot->HasAura(COMMANDING_SHOUT, EFFECT_INDEX_0) && GetAI()->CastSpell(COMMANDING_SHOUT))
            return;
    }
    else // Not prot, or prot but no Commanding Shout yet
    {
        if (!m_bot->HasAura(BATTLE_SHOUT, EFFECT_INDEX_0) && GetAI()->CastSpell(BATTLE_SHOUT))
            return;
    }
}

void PlayerbotWarriorAI::DoNonCombatActions()
{
    if (!GetAI())  return;
    if (!m_bot) return;

    uint32 spec = m_bot->GetSpec();

    //Stance Check
    if (spec == WARRIOR_SPEC_ARMS && !m_bot->HasAura(BATTLE_STANCE, EFFECT_INDEX_0))
        GetAI()->CastSpell(BATTLE_STANCE);
    else if (spec == WARRIOR_SPEC_FURY && !m_bot->HasAura(BERSERKER_STANCE, EFFECT_INDEX_0))
        GetAI()->CastSpell(BERSERKER_STANCE);
    else if (spec == WARRIOR_SPEC_PROTECTION && !m_bot->HasAura(DEFENSIVE_STANCE, EFFECT_INDEX_0))
        GetAI()->CastSpell(DEFENSIVE_STANCE);

    // buff master with VIGILANCE
    if (VIGILANCE > 0)
        (!GetMaster()->HasAura(VIGILANCE, EFFECT_INDEX_0) && GetAI()->CastSpell(VIGILANCE, *GetMaster()));

    // hp check
    if (EatDrinkBandage(false))
        return;

    if (m_bot->getRace() == RACE_DRAENEI && !m_bot->HasAura(GIFT_OF_THE_NAARU, EFFECT_INDEX_0) && GetAI()->GetHealthPercent() < 70)
    {
        GetAI()->TellMaster("I'm casting gift of the naaru.");
        GetAI()->CastSpell(GIFT_OF_THE_NAARU, *m_bot);
        return;
    }
} // end DoNonCombatActions

// Match up with "Pull()" below
bool PlayerbotWarriorAI::CanPull()
{
    if (!m_bot) return false;
    if (!GetAI()) return false;

    if (m_bot->GetUInt32Value(PLAYER_AMMO_ID)) // Having ammo equipped means a weapon is equipped as well. Probably. [TODO: does this work with throwing knives? Can a playerbot 'cheat' ammo into the slot without a proper weapon?]
    {
        // Can't do this, CanPull CANNOT check for anything that requires a target
        //if (!GetAI()->IsInRange(GetAI()->GetCurrentTarget(), AUTO_SHOT))
        //{
        //    GetAI()->TellMaster("I'm out of range.");
        //    return false;
        //}
        return true;
    }

    return false;
}

// Match up with "CanPull()" above
bool PlayerbotWarriorAI::Pull()
{
    if (!m_bot) return false;
    if (!GetAI())  return false;

    if (m_bot->GetCombatDistance(GetAI()->GetCurrentTarget(), true) > ATTACK_DISTANCE)
    {
        if (!GetAI()->In_Range(GetAI()->GetCurrentTarget(), AUTO_SHOT))
        {
            GetAI()->TellMaster("I'm out of range.");
            return false;
        }

        // activate auto shot: Reworked to account for AUTO_SHOT being a triggered spell
        if (AUTO_SHOT && GetAI()->GetCurrentSpellId() != AUTO_SHOT)
        {
            m_bot->CastSpell(GetAI()->GetCurrentTarget(), AUTO_SHOT, TRIGGERED_OLD_TRIGGERED);
            return true;
        }
    }
    else // target is in melee range
    {
        GetAI()->Attack(GetAI()->GetCurrentTarget());
        return true;
    }

    return false;
}
