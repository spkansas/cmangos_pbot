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
    // TODO: fail on non-postivie return
    PlayerbotClassAI_ClassAIInit();
}


PlayerbotWarriorAI::~PlayerbotWarriorAI()
{
}


bool PlayerbotWarriorAI::PlayerbotClassAI_ClassAIInit(void)
{
    AUTO_SHOT               = m_botdata->GetAI()->initSpell(AUTO_SHOT_2); // GENERAL

    BATTLE_STANCE           = m_botdata->GetAI()->initSpell(BATTLE_STANCE_1); //ARMS
    CHARGE                  = m_botdata->GetAI()->initSpell(CHARGE_1); //ARMS
    OVERPOWER               = m_botdata->GetAI()->initSpell(OVERPOWER_1); // ARMS
    HEROIC_STRIKE           = m_botdata->GetAI()->initSpell(HEROIC_STRIKE_1); //ARMS
    REND                    = m_botdata->GetAI()->initSpell(REND_1); //ARMS
    THUNDER_CLAP            = m_botdata->GetAI()->initSpell(THUNDER_CLAP_1);  //ARMS
    HAMSTRING               = m_botdata->GetAI()->initSpell(HAMSTRING_1);  //ARMS
    MOCKING_BLOW            = m_botdata->GetAI()->initSpell(MOCKING_BLOW_1);  //ARMS
    RETALIATION             = m_botdata->GetAI()->initSpell(RETALIATION_1);  //ARMS
    SWEEPING_STRIKES        = m_botdata->GetAI()->initSpell(SWEEPING_STRIKES_1); //ARMS
    MORTAL_STRIKE           = m_botdata->GetAI()->initSpell(MORTAL_STRIKE_1);  //ARMS
    BLADESTORM              = m_botdata->GetAI()->initSpell(BLADESTORM_1);  //ARMS
    HEROIC_THROW            = m_botdata->GetAI()->initSpell(HEROIC_THROW_1);  //ARMS
    SHATTERING_THROW        = m_botdata->GetAI()->initSpell(SHATTERING_THROW_1);  //ARMS
    BLOODRAGE               = m_botdata->GetAI()->initSpell(BLOODRAGE_1); //PROTECTION
    DEFENSIVE_STANCE        = m_botdata->GetAI()->initSpell(DEFENSIVE_STANCE_1); //PROTECTION
    DEVASTATE               = m_botdata->GetAI()->initSpell(DEVASTATE_1); //PROTECTION
    SUNDER_ARMOR            = m_botdata->GetAI()->initSpell(SUNDER_ARMOR_1); //PROTECTION
    TAUNT                   = m_botdata->GetAI()->initSpell(TAUNT_1); //PROTECTION
    SHIELD_BASH             = m_botdata->GetAI()->initSpell(SHIELD_BASH_1); //PROTECTION
    REVENGE                 = m_botdata->GetAI()->initSpell(REVENGE_1); //PROTECTION
    SHIELD_BLOCK            = m_botdata->GetAI()->initSpell(SHIELD_BLOCK_1); //PROTECTION
    DISARM                  = m_botdata->GetAI()->initSpell(DISARM_1); //PROTECTION
    SHIELD_WALL             = m_botdata->GetAI()->initSpell(SHIELD_WALL_1); //PROTECTION
    SHIELD_SLAM             = m_botdata->GetAI()->initSpell(SHIELD_SLAM_1); //PROTECTION
    VIGILANCE               = m_botdata->GetAI()->initSpell(VIGILANCE_1); //PROTECTION
    DEVASTATE               = m_botdata->GetAI()->initSpell(DEVASTATE_1); //PROTECTION
    SHOCKWAVE               = m_botdata->GetAI()->initSpell(SHOCKWAVE_1); //PROTECTION
    CONCUSSION_BLOW         = m_botdata->GetAI()->initSpell(CONCUSSION_BLOW_1); //PROTECTION
    SPELL_REFLECTION        = m_botdata->GetAI()->initSpell(SPELL_REFLECTION_1); //PROTECTION
    LAST_STAND              = m_botdata->GetAI()->initSpell(LAST_STAND_1); //PROTECTION
    BATTLE_SHOUT            = m_botdata->GetAI()->initSpell(BATTLE_SHOUT_1); //FURY
    DEMORALIZING_SHOUT      = m_botdata->GetAI()->initSpell(DEMORALIZING_SHOUT_1); //FURY
    CLEAVE                  = m_botdata->GetAI()->initSpell(CLEAVE_1); //FURY
    INTIMIDATING_SHOUT      = m_botdata->GetAI()->initSpell(INTIMIDATING_SHOUT_1); //FURY
    EXECUTE                 = m_botdata->GetAI()->initSpell(EXECUTE_1); //FURY
    CHALLENGING_SHOUT       = m_botdata->GetAI()->initSpell(CHALLENGING_SHOUT_1); //FURY
    SLAM                    = m_botdata->GetAI()->initSpell(SLAM_1); //FURY
    BERSERKER_STANCE        = m_botdata->GetAI()->initSpell(BERSERKER_STANCE_1); //FURY
    INTERCEPT               = m_botdata->GetAI()->initSpell(INTERCEPT_1); //FURY
    DEATH_WISH              = m_botdata->GetAI()->initSpell(DEATH_WISH_1); //FURY
    BERSERKER_RAGE          = m_botdata->GetAI()->initSpell(BERSERKER_RAGE_1); //FURY
    WHIRLWIND               = m_botdata->GetAI()->initSpell(WHIRLWIND_1); //FURY
    PUMMEL                  = m_botdata->GetAI()->initSpell(PUMMEL_1); //FURY
    BLOODTHIRST             = m_botdata->GetAI()->initSpell(BLOODTHIRST_1); //FURY
    RECKLESSNESS            = m_botdata->GetAI()->initSpell(RECKLESSNESS_1); //FURY
    RAMPAGE                 = 0; // passive
    HEROIC_FURY             = m_botdata->GetAI()->initSpell(HEROIC_FURY_1); //FURY
    COMMANDING_SHOUT        = m_botdata->GetAI()->initSpell(COMMANDING_SHOUT_1); //FURY
    ENRAGED_REGENERATION    = m_botdata->GetAI()->initSpell(ENRAGED_REGENERATION_1); //FURY
    PIERCING_HOWL           = m_botdata->GetAI()->initSpell(PIERCING_HOWL_1); //FURY

    // racial
    GIFT_OF_THE_NAARU       = m_botdata->GetAI()->initSpell(GIFT_OF_THE_NAARU_WARRIOR); // draenei
    STONEFORM               = m_botdata->GetAI()->initSpell(STONEFORM_ALL); // dwarf
    ESCAPE_ARTIST           = m_botdata->GetAI()->initSpell(ESCAPE_ARTIST_ALL); // gnome
    EVERY_MAN_FOR_HIMSELF   = m_botdata->GetAI()->initSpell(EVERY_MAN_FOR_HIMSELF_ALL); // human
    SHADOWMELD              = m_botdata->GetAI()->initSpell(SHADOWMELD_ALL); // night elf
    BLOOD_FURY              = m_botdata->GetAI()->initSpell(BLOOD_FURY_MELEE_CLASSES); // orc
    WAR_STOMP               = m_botdata->GetAI()->initSpell(WAR_STOMP_ALL); // tauren
    BERSERKING              = m_botdata->GetAI()->initSpell(BERSERKING_ALL); // troll
    WILL_OF_THE_FORSAKEN    = m_botdata->GetAI()->initSpell(WILL_OF_THE_FORSAKEN_ALL); // undead

    //Procs
    SLAM_PROC               = m_botdata->GetAI()->initSpell(SLAM_PROC_1);
    BLOODSURGE              = m_botdata->GetAI()->initSpell(BLOODSURGE_1);
    TASTE_FOR_BLOOD         = m_botdata->GetAI()->initSpell(TASTE_FOR_BLOOD_1);
    SUDDEN_DEATH            = m_botdata->GetAI()->initSpell(SUDDEN_DEATH_1);
	
	m_botdata->SetRolePrimary(BOT_ROLE::ROLE_TANK);

    return PlayerbotClassAI::PlayerbotClassAI_ClassAIInit();
}


CombatManeuverReturns PlayerbotWarriorAI::DoFirstCombatManeuverPVE(Unit* pTarget)
{
    if (!m_botdata->GetAI())  return RETURN_NO_ACTION_ERROR;
    if (!m_botdata->GetBot()) return RETURN_NO_ACTION_ERROR;

    float fTargetDist = m_botdata->GetBot()->GetCombatDistance(pTarget, true);

    if (DEFENSIVE_STANCE && (m_botdata->GetAI()->GetCombatOrder() & PlayerbotAI::ORDERS_TANK))
    {
        if (!m_botdata->GetBot()->HasAura(DEFENSIVE_STANCE, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(DEFENSIVE_STANCE))
            return RETURN_CONTINUE;
        else if (TAUNT > 0 && m_botdata->GetBot()->HasAura(DEFENSIVE_STANCE, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(TAUNT, *pTarget))
            return RETURN_FINISHED_FIRST_MOVES;
    }

    if (BERSERKER_STANCE)
    {
        if (!m_botdata->GetBot()->HasAura(BERSERKER_STANCE, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(BERSERKER_STANCE))
            return RETURN_CONTINUE;
        if (BLOODRAGE > 0 && m_botdata->GetBot()->HasAura(BERSERKER_STANCE, EFFECT_INDEX_0) && m_botdata->GetAI()->GetRageAmount() <= 10)
            return m_botdata->GetAI()->CastSpell(BLOODRAGE) ? RETURN_FINISHED_FIRST_MOVES : RETURN_NO_ACTION_ERROR;
        if (INTERCEPT > 0 && m_botdata->GetBot()->HasAura(BERSERKER_STANCE, EFFECT_INDEX_0))
        {
            if (fTargetDist < 8.0f)
                return RETURN_NO_ACTION_OK;
            else if (fTargetDist > 25.0f)
                return RETURN_CONTINUE; // wait to come into range
            else if (INTERCEPT > 0 && m_botdata->GetAI()->CastSpell(INTERCEPT, *pTarget))
            {
                float x, y, z;
                pTarget->GetContactPoint(m_botdata->GetBot(), x, y, z, 3.666666f);
                m_botdata->GetBot()->Relocate(x, y, z);
                return RETURN_FINISHED_FIRST_MOVES;
            }
        }
    }

    if (BATTLE_STANCE)
    {
        if (!m_botdata->GetBot()->HasAura(BATTLE_STANCE, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(BATTLE_STANCE))
            return RETURN_CONTINUE;
        if (CHARGE > 0 && m_botdata->GetBot()->HasAura(BATTLE_STANCE, EFFECT_INDEX_0))
        {
            if (fTargetDist < 8.0f)
                return RETURN_NO_ACTION_OK;
            if (fTargetDist > 25.0f)
                return RETURN_CONTINUE; // wait to come into range
            else if (CHARGE > 0 && m_botdata->GetAI()->CastSpell(CHARGE, *pTarget))
            {
                float x, y, z;
                pTarget->GetContactPoint(m_botdata->GetBot(), x, y, z, 3.666666f);
                m_botdata->GetBot()->Relocate(x, y, z);
                return RETURN_FINISHED_FIRST_MOVES;
            }
        }
    }

    return RETURN_NO_ACTION_OK;
}

// TODO: blatant copy of PVE for now, please PVP-port it
CombatManeuverReturns PlayerbotWarriorAI::DoFirstCombatManeuverPVP(Unit *pTarget)
{
    if (!m_botdata->GetAI())  return RETURN_NO_ACTION_ERROR;
    if (!m_botdata->GetBot()) return RETURN_NO_ACTION_ERROR;

    float fTargetDist = m_botdata->GetBot()->GetCombatDistance(pTarget, true);

    if (DEFENSIVE_STANCE && (m_botdata->GetAI()->GetCombatOrder() & PlayerbotAI::ORDERS_TANK))
    {
        if (!m_botdata->GetBot()->HasAura(DEFENSIVE_STANCE, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(DEFENSIVE_STANCE))
            return RETURN_CONTINUE;
        else if (TAUNT > 0 && m_botdata->GetBot()->HasAura(DEFENSIVE_STANCE, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(TAUNT, *pTarget))
            return RETURN_FINISHED_FIRST_MOVES;
    }

    if (BERSERKER_STANCE)
    {
        if (!m_botdata->GetBot()->HasAura(BERSERKER_STANCE, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(BERSERKER_STANCE))
            return RETURN_CONTINUE;
        if (BLOODRAGE > 0 && m_botdata->GetBot()->HasAura(BERSERKER_STANCE, EFFECT_INDEX_0) && m_botdata->GetAI()->GetRageAmount() <= 10)
            return m_botdata->GetAI()->CastSpell(BLOODRAGE) ? RETURN_FINISHED_FIRST_MOVES : RETURN_NO_ACTION_ERROR;
        if (INTERCEPT > 0 && m_botdata->GetBot()->HasAura(BERSERKER_STANCE, EFFECT_INDEX_0))
        {
            if (fTargetDist < 8.0f)
                return RETURN_NO_ACTION_OK;
            else if (fTargetDist > 25.0f)
                return RETURN_CONTINUE; // wait to come into range
            else if (INTERCEPT > 0 && m_botdata->GetAI()->CastSpell(INTERCEPT, *pTarget))
            {
                float x, y, z;
                pTarget->GetContactPoint(m_botdata->GetBot(), x, y, z, 3.666666f);
                m_botdata->GetBot()->Relocate(x, y, z);
                return RETURN_FINISHED_FIRST_MOVES;
            }
        }
    }

    if (BATTLE_STANCE)
    {
        if (!m_botdata->GetBot()->HasAura(BATTLE_STANCE, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(BATTLE_STANCE))
            return RETURN_CONTINUE;
        if (CHARGE > 0 && m_botdata->GetBot()->HasAura(BATTLE_STANCE, EFFECT_INDEX_0))
        {
            if (fTargetDist < 8.0f)
                return RETURN_NO_ACTION_OK;
            if (fTargetDist > 25.0f)
                return RETURN_CONTINUE; // wait to come into range
            else if (CHARGE > 0 && m_botdata->GetAI()->CastSpell(CHARGE, *pTarget))
            {
                float x, y, z;
                pTarget->GetContactPoint(m_botdata->GetBot(), x, y, z, 3.666666f);
                m_botdata->GetBot()->Relocate(x, y, z);
                return RETURN_FINISHED_FIRST_MOVES;
            }
        }
    }

    return RETURN_NO_ACTION_OK;
}


CombatManeuverReturns PlayerbotWarriorAI::DoNextCombatManeuverPVE(Unit *pTarget)
{
    if (!m_botdata->GetAI())  return RETURN_NO_ACTION_ERROR;
    if (!m_botdata->GetBot()) return RETURN_NO_ACTION_ERROR;

    //Unit* pVictim = pTarget->getVictim();
    //float fTargetDist = m_botdata->GetBot()->GetCombatDistance(pTarget, true);
    uint32 spec = m_botdata->GetBot()->GetSpec();

    //If we have devastate it will replace SA in our rotation
    //uint32 SUNDER = (DEVASTATE > 0 ? DEVASTATE : SUNDER_ARMOR);

    //Used to determine if this bot is highest on threat
    Unit* newTarget = m_botdata->GetAI()->FindAttacker((PlayerbotAI::ATTACKERINFOTYPE) (PlayerbotAI::AIT_VICTIMSELF | PlayerbotAI::AIT_HIGHESTTHREAT), m_botdata->GetBot());

    // do shouts, berserker rage, etc...
    if (BERSERKER_RAGE > 0 && !m_botdata->GetBot()->HasAura(BERSERKER_RAGE, EFFECT_INDEX_0))
        m_botdata->GetAI()->CastSpell(BERSERKER_RAGE);
    else if (BLOODRAGE > 0 && m_botdata->GetAI()->GetRageAmount() <= 10)
        m_botdata->GetAI()->CastSpell(BLOODRAGE);

    CheckShouts();
	// buff master with VIGILANCE
//	if (VIGILANCE > 0)
//		(!m_botdata->GetMaster()->HasAura(VIGILANCE, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(VIGILANCE, *m_botdata->GetMaster()));

    switch (spec)
    {
        case WARRIOR_SPEC_ARMS:
            // Execute doesn't scale too well with extra rage and uses up *all* rage preventing use of other skills
            //Haven't found a way to make sudden death work yet, either wrong spell or it needs an effect index(probably)
            if (EXECUTE > 0 && (pTarget->GetHealthPercent() < 20 || m_botdata->GetBot()->HasAura(SUDDEN_DEATH)) && m_botdata->GetAI()->GetRageAmount() < 30 && m_botdata->GetAI()->CastSpell (EXECUTE, *pTarget))
                return RETURN_CONTINUE;
            if (REND > 0 && !pTarget->HasAura(REND, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(REND, *pTarget))
                return RETURN_CONTINUE;
            if (MORTAL_STRIKE > 0 && m_botdata->GetBot()->IsSpellReady(MORTAL_STRIKE) && m_botdata->GetAI()->CastSpell(MORTAL_STRIKE, *pTarget))
                return RETURN_CONTINUE;
            if (SHATTERING_THROW > 0 && !pTarget->HasAura(SHATTERING_THROW, EFFECT_INDEX_0) && m_botdata->GetBot()->IsSpellReady(SHATTERING_THROW) && m_botdata->GetAI()->CastSpell(SHATTERING_THROW, *pTarget))
                return RETURN_CONTINUE;
            if (BLADESTORM > 0 && m_botdata->GetBot()->IsSpellReady(BLADESTORM) /*&& m_botdata->GetAI()->GetAttackerCount() >= 3*/ && m_botdata->GetAI()->CastSpell(BLADESTORM, *pTarget))
                return RETURN_CONTINUE;
            // No way to tell if overpower is active (yet), however taste for blood works
            if (OVERPOWER > 0 && m_botdata->GetBot()->HasAura(TASTE_FOR_BLOOD) && m_botdata->GetAI()->CastSpell(OVERPOWER, *pTarget))
                return RETURN_CONTINUE;
            if (HEROIC_STRIKE > 0 && m_botdata->GetAI()->CastSpell(HEROIC_STRIKE, *pTarget))
                return RETURN_CONTINUE;
            if (SLAM > 0 && m_botdata->GetAI()->CastSpell(SLAM, *pTarget))
            {
                m_botdata->GetAI()->SetIgnoreUpdateTime(1); // TODO: SetIgnoreUpdateTime takes a uint8 - how will 1.5 work as a value?
                return RETURN_CONTINUE;
            }

        case WARRIOR_SPEC_FURY:
            if (EXECUTE > 0 && pTarget->GetHealthPercent() < 20 && m_botdata->GetAI()->CastSpell (EXECUTE, *pTarget))
                return RETURN_CONTINUE;
            if (BLOODTHIRST > 0 && m_botdata->GetBot()->IsSpellReady(BLOODTHIRST) && m_botdata->GetAI()->CastSpell(BLOODTHIRST, *pTarget))
                return RETURN_CONTINUE;
            if (WHIRLWIND > 0 && m_botdata->GetBot()->IsSpellReady(WHIRLWIND) && m_botdata->GetAI()->CastSpell(WHIRLWIND, *pTarget))
                return RETURN_CONTINUE;
            if (SLAM > 0 && m_botdata->GetBot()->HasAura(BLOODSURGE, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(SLAM, *pTarget))
                return RETURN_CONTINUE;
            if (HEROIC_STRIKE > 0 && m_botdata->GetAI()->CastSpell(HEROIC_STRIKE, *pTarget))
                return RETURN_CONTINUE;

        case WARRIOR_SPEC_PROTECTION:
            if (m_botdata->GetAI()->GetCombatOrder() & PlayerbotAI::ORDERS_TANK && !newTarget && TAUNT > 0 && m_botdata->GetBot()->IsSpellReady(TAUNT) && m_botdata->GetAI()->CastSpell(TAUNT, *pTarget))
                return RETURN_CONTINUE;
            // No way to tell if revenge is active (yet)
            /*if (REVENGE > 0 && m_botdata->GetAI()->CastSpell(REVENGE, *pTarget))
                return RETURN_CONTINUE;*/
            if (REND > 0 && !pTarget->HasAura(REND, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(REND, *pTarget))
                return RETURN_CONTINUE;
            if (THUNDER_CLAP > 0 && !pTarget->HasAura(THUNDER_CLAP) && m_botdata->GetAI()->CastSpell(THUNDER_CLAP, *pTarget))
                return RETURN_CONTINUE;
            if (DEMORALIZING_SHOUT > 0 && !pTarget->HasAura(DEMORALIZING_SHOUT, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(DEMORALIZING_SHOUT, *pTarget))
                return RETURN_CONTINUE;
            if (CONCUSSION_BLOW > 0 && m_botdata->GetBot()->IsSpellReady(CONCUSSION_BLOW) && m_botdata->GetAI()->CastSpell(CONCUSSION_BLOW, *pTarget))
                return RETURN_CONTINUE;
            if (SHOCKWAVE > 0 && m_botdata->GetBot()->IsSpellReady(SHOCKWAVE) && m_botdata->GetAI()->CastSpell(SHOCKWAVE, *pTarget))
                return RETURN_CONTINUE;
            if (SHIELD_SLAM > 0 && m_botdata->GetBot()->IsSpellReady(SHIELD_SLAM) && m_botdata->GetAI()->CastSpell(SHIELD_SLAM, *pTarget))
                return RETURN_CONTINUE;
            /*if (SUNDER > 0 && !pTarget->HasAura(SUNDER_ARMOR) && m_botdata->GetAI()->CastSpell(SUNDER, *pTarget))
                return RETURN_CONTINUE;*/
            if (HEROIC_STRIKE > 0 && m_botdata->GetAI()->CastSpell(HEROIC_STRIKE, *pTarget))
                return RETURN_CONTINUE;

        /*case WarriorSpellPreventing:
            if (SHIELD_BASH > 0 && m_botdata->GetAI()->CastSpell(SHIELD_BASH, *pTarget))
                return RETURN_CONTINUE;
            if (PUMMEL > 0 && m_botdata->GetAI()->CastSpell(PUMMEL, *pTarget))
                return RETURN_CONTINUE;
            if (SPELL_REFLECTION > 0 && !m_botdata->GetBot()->HasAura(SPELL_REFLECTION, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(SPELL_REFLECTION, *m_botdata->GetBot()))
                return RETURN_CONTINUE;
            break;

        case WarriorBattle:
            if (LAST_STAND > 0 && !m_botdata->GetBot()->HasAura(LAST_STAND, EFFECT_INDEX_0) && m_botdata->GetBot()->GetHealthPercent() < 50 && m_botdata->GetAI()->CastSpell(LAST_STAND, *m_botdata->GetBot()))
                return RETURN_CONTINUE;
            if (DEATH_WISH > 0 && !m_botdata->GetBot()->HasAura(DEATH_WISH, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(DEATH_WISH, *m_botdata->GetBot()))
                return RETURN_CONTINUE;
            if (RETALIATION > 0 && pVictim == m_botdata->GetBot() && m_botdata->GetAI()->GetAttackerCount() >= 2 && !m_botdata->GetBot()->HasAura(RETALIATION, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(RETALIATION, *m_botdata->GetBot()))
                return RETURN_CONTINUE;
            if (SWEEPING_STRIKES > 0 && m_botdata->GetAI()->GetAttackerCount() >= 2 && !m_botdata->GetBot()->HasAura(SWEEPING_STRIKES, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(SWEEPING_STRIKES, *m_botdata->GetBot()))
                return RETURN_CONTINUE;
            if (INTIMIDATING_SHOUT > 0 && m_botdata->GetAI()->GetAttackerCount() > 5 && m_botdata->GetAI()->CastSpell(INTIMIDATING_SHOUT, *pTarget))
                return RETURN_CONTINUE;
            if (ENRAGED_REGENERATION > 0 && !m_botdata->GetBot()->HasAura(BERSERKER_RAGE, EFFECT_INDEX_0) && !m_botdata->GetBot()->HasAura(ENRAGED_REGENERATION, EFFECT_INDEX_0) && m_botdata->GetBot()->GetHealth() < m_botdata->GetBot()->GetMaxHealth() * 0.5 && m_botdata->GetAI()->CastSpell(ENRAGED_REGENERATION, *m_botdata->GetBot()))
                return RETURN_CONTINUE;
            if (HAMSTRING > 0 && !pTarget->HasAura(HAMSTRING, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(HAMSTRING, *pTarget))
                return RETURN_CONTINUE;
            if (CHALLENGING_SHOUT > 0 && pVictim != m_botdata->GetBot() && m_botdata->GetAI()->GetHealthPercent() > 25 && !pTarget->HasAura(MOCKING_BLOW, EFFECT_INDEX_0) && !pTarget->HasAura(CHALLENGING_SHOUT, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(CHALLENGING_SHOUT, *pTarget))
                return RETURN_CONTINUE;
            if (CLEAVE > 0 && m_botdata->GetAI()->CastSpell(CLEAVE, *pTarget))
                return RETURN_CONTINUE;
            if (PIERCING_HOWL > 0 && && m_botdata->GetAI()->GetAttackerCount() >= 3 && !pTarget->HasAura(WAR_STOMP, EFFECT_INDEX_0) && !pTarget->HasAura(PIERCING_HOWL, EFFECT_INDEX_0) && !pTarget->HasAura(SHOCKWAVE, EFFECT_INDEX_0) && !pTarget->HasAura(CONCUSSION_BLOW, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(PIERCING_HOWL, *pTarget))
                return RETURN_CONTINUE;
            if (MOCKING_BLOW > 0 && pVictim != m_botdata->GetBot() && m_botdata->GetAI()->GetHealthPercent() > 25 && !pTarget->HasAura(MOCKING_BLOW, EFFECT_INDEX_0) && !pTarget->HasAura(CHALLENGING_SHOUT, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(MOCKING_BLOW, *pTarget))
                return RETURN_CONTINUE;
            if (HEROIC_THROW > 0 && m_botdata->GetAI()->CastSpell(HEROIC_THROW, *pTarget))
                return RETURN_CONTINUE;
            if (m_botdata->GetBot()->getRace() == RACE_TAUREN && !pTarget->HasAura(WAR_STOMP, EFFECT_INDEX_0) && !pTarget->HasAura(PIERCING_HOWL, EFFECT_INDEX_0) && !pTarget->HasAura(SHOCKWAVE, EFFECT_INDEX_0) && !pTarget->HasAura(CONCUSSION_BLOW, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(WAR_STOMP, *pTarget))
                return RETURN_CONTINUE;
            if (m_botdata->GetBot()->getRace() == RACE_HUMAN && m_botdata->GetBot()->hasUnitState(UNIT_STAT_STUNNED) || m_botdata->GetBot()->HasAuraType(SPELL_AURA_MOD_FEAR) || m_botdata->GetBot()->HasAuraType(SPELL_AURA_MOD_DECREASE_SPEED) || m_botdata->GetBot()->HasAuraType(SPELL_AURA_MOD_CHARM) && m_botdata->GetAI()->CastSpell(EVERY_MAN_FOR_HIMSELF, *m_botdata->GetBot()))
                return RETURN_CONTINUE;
            if (m_botdata->GetBot()->getRace() == RACE_UNDEAD && m_botdata->GetBot()->HasAuraType(SPELL_AURA_MOD_FEAR) || m_botdata->GetBot()->HasAuraType(SPELL_AURA_MOD_CHARM) && m_botdata->GetAI()->CastSpell(WILL_OF_THE_FORSAKEN, *m_botdata->GetBot()))
                return RETURN_CONTINUE;
            if (m_botdata->GetBot()->getRace() == RACE_DWARF && m_botdata->GetBot()->HasAuraState(AURA_STATE_DEADLY_POISON) && m_botdata->GetAI()->CastSpell(STONEFORM, *m_botdata->GetBot()))
                return RETURN_CONTINUE;
            if (m_botdata->GetBot()->getRace() == RACE_GNOME && m_botdata->GetBot()->hasUnitState(UNIT_STAT_STUNNED) || m_botdata->GetBot()->HasAuraType(SPELL_AURA_MOD_DECREASE_SPEED) && m_botdata->GetAI()->CastSpell(ESCAPE_ARTIST, *m_botdata->GetBot()))
                return RETURN_CONTINUE;
            if (m_botdata->GetBot()->getRace() == RACE_NIGHTELF && pVictim == m_botdata->GetBot() && m_botdata->GetAI()->GetHealthPercent() < 25 && !m_botdata->GetBot()->HasAura(SHADOWMELD, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(SHADOWMELD, *m_botdata->GetBot()))
                return RETURN_CONTINUE;
            if (m_botdata->GetBot()->getRace() == RACE_ORC && !m_botdata->GetBot()->HasAura(BLOOD_FURY, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(BLOOD_FURY, *m_botdata->GetBot()))
                return RETURN_CONTINUE;
            if (m_botdata->GetBot()->getRace() == RACE_TROLL && !m_botdata->GetBot()->HasAura(BERSERKING, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(BERSERKING, *m_botdata->GetBot()))
                return RETURN_CONTINUE;
            if (m_botdata->GetBot()->getRace() == RACE_DRAENEI && m_botdata->GetAI()->GetHealthPercent() < 25 && !m_botdata->GetBot()->HasAura(GIFT_OF_THE_NAARU, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(GIFT_OF_THE_NAARU, *m_botdata->GetBot()))
                return RETURN_CONTINUE;
            break;

        case WarriorDefensive:
            if (DISARM > 0 && !pTarget->HasAura(DISARM, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(DISARM, *pTarget))
                return RETURN_CONTINUE;
            if (SHIELD_BLOCK > 0 && !m_botdata->GetBot()->HasAura(SHIELD_BLOCK, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(SHIELD_BLOCK, *m_botdata->GetBot()))
                return RETURN_CONTINUE;
            if (SHIELD_WALL > 0 && !m_botdata->GetBot()->HasAura(SHIELD_WALL, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(SHIELD_WALL, *m_botdata->GetBot()))
                return RETURN_CONTINUE;
            break;*/
    }

    return RETURN_NO_ACTION_OK;
}

CombatManeuverReturns PlayerbotWarriorAI::DoNextCombatManeuverPVP(Unit* pTarget)
{
    if (m_botdata->GetAI()->CastSpell(HEROIC_STRIKE))
        return RETURN_CONTINUE;

    return DoNextCombatManeuverPVE(pTarget); // TODO: bad idea perhaps, but better than the alternative
}

//Buff and rebuff shouts
void PlayerbotWarriorAI::CheckShouts()
{
    if (!m_botdata->GetAI())  return;
    if (!m_botdata->GetBot()) return;

    if (m_botdata->GetBot()->GetSpec() == WARRIOR_SPEC_PROTECTION && COMMANDING_SHOUT > 0)
    {
        if (!m_botdata->GetBot()->HasAura(COMMANDING_SHOUT, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(COMMANDING_SHOUT))
            return;
    }
    else // Not prot, or prot but no Commanding Shout yet
    {
        if (!m_botdata->GetBot()->HasAura(BATTLE_SHOUT, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(BATTLE_SHOUT))
            return;
    }
}


CombatManeuverReturns PlayerbotWarriorAI::DoManeuver_Idle_Forms_Start(void)
{
	CombatManeuverReturns ret_val;

	//Stance Check
	if (m_botdata->GetSpec() == WARRIOR_SPEC_ARMS && !m_botdata->GetBot()->HasAura(BATTLE_STANCE, EFFECT_INDEX_0))
	{
		ret_val = (m_botdata->GetAI()->CastSpell(BATTLE_STANCE) ? RETURN_NO_ACTION_OK : RETURN_CONTINUE);
	}
	else if (m_botdata->GetSpec() == WARRIOR_SPEC_FURY && !m_botdata->GetBot()->HasAura(BERSERKER_STANCE, EFFECT_INDEX_0))
	{
		ret_val = (m_botdata->GetAI()->CastSpell(BERSERKER_STANCE) ? RETURN_NO_ACTION_OK : RETURN_CONTINUE);
	}
	else if (m_botdata->GetSpec() == WARRIOR_SPEC_PROTECTION && !m_botdata->GetBot()->HasAura(DEFENSIVE_STANCE, EFFECT_INDEX_0))
	{
		ret_val = (m_botdata->GetAI()->CastSpell(DEFENSIVE_STANCE) ? RETURN_NO_ACTION_OK : RETURN_CONTINUE);
	}
	else
	{
		ret_val = RETURN_NO_ACTION_OK;
	}

	return ret_val;
}


CombatManeuverReturns PlayerbotWarriorAI::DoManeuver_Idle_Heal_Prep(Player* target)
{
	CombatManeuverReturns ret_val;

	if (m_botdata->GetBot()->getRace() == RACE_DRAENEI && !target->HasAura(GIFT_OF_THE_NAARU, EFFECT_INDEX_0) && target->GetHealthPercent() < 70)
	{
		ret_val = m_botdata->SetHealSpell(GIFT_OF_THE_NAARU) ? RETURN_NO_ACTION_OK : RETURN_CONTINUE);
	}
	else
	{
		m_botdata->SetHealSpell(0);

		ret_val = RETURN_NO_ACTION_OK;
	}

	return ret_val;
}


// Match up with "Pull()" below
bool PlayerbotWarriorAI::CanPull()
{
    if (!m_botdata->GetBot()) return false;
    if (!m_botdata->GetAI()) return false;

    if (m_botdata->GetBot()->GetUInt32Value(PLAYER_AMMO_ID)) // Having ammo equipped means a weapon is equipped as well. Probably. [TODO: does this work with throwing knives? Can a playerbot 'cheat' ammo into the slot without a proper weapon?]
    {
        // Can't do this, CanPull CANNOT check for anything that requires a target
        //if (!m_botdata->GetAI()->IsInRange(m_botdata->GetAI()->GetCurrentTarget(), AUTO_SHOT))
        //{
        //    m_botdata->GetAI()->TellMaster("I'm out of range.");
        //    return false;
        //}
        return true;
    }

    return false;
}

// Match up with "CanPull()" above
bool PlayerbotWarriorAI::Pull()
{
    if (!m_botdata->GetBot()) return false;
    if (!m_botdata->GetAI())  return false;

    if (m_botdata->GetBot()->GetCombatDistance(m_botdata->GetAI()->GetCurrentTarget(), true) > ATTACK_DISTANCE)
    {
        if (!m_botdata->GetAI()->In_Range(m_botdata->GetAI()->GetCurrentTarget(), AUTO_SHOT))
        {
            m_botdata->GetAI()->TellMaster("I'm out of range.");
            return false;
        }

        // activate auto shot: Reworked to account for AUTO_SHOT being a triggered spell
        if (AUTO_SHOT && m_botdata->GetAI()->GetCurrentSpellId() != AUTO_SHOT)
        {
            m_botdata->GetBot()->CastSpell(m_botdata->GetAI()->GetCurrentTarget(), AUTO_SHOT, TRIGGERED_OLD_TRIGGERED);
            return true;
        }
    }
    else // target is in melee range
    {
        m_botdata->GetAI()->Attack(m_botdata->GetAI()->GetCurrentTarget());
        return true;
    }

    return false;
}
