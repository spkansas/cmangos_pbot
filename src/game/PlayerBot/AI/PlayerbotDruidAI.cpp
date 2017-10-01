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

#include "PlayerbotDruidAI.h"

class PlayerbotAI;

PlayerbotDruidAI::PlayerbotDruidAI(Player* const master, Player* const bot, PlayerbotAI* const ai) : PlayerbotClassAI(master, bot, ai)
{
	m_ActionBeforeCast = &(PlayerbotDruidAI::GoBuffForm);

    // TODO: fail on non-postivie return
    PlayerbotClassAI_ClassAIInit();
}


PlayerbotDruidAI::~PlayerbotDruidAI() 
{
}


bool PlayerbotDruidAI::PlayerbotClassAI_ClassAIInit(void)
{
    MOONFIRE                      = m_botdata->GetAI()->initSpell(MOONFIRE_1); // attacks
    STARFIRE                      = m_botdata->GetAI()->initSpell(STARFIRE_1);
    STARFALL                      = m_botdata->GetAI()->initSpell(STARFALL_1);
    WRATH                         = m_botdata->GetAI()->initSpell(WRATH_1);
    ROOTS                         = m_botdata->GetAI()->initSpell(ENTANGLING_ROOTS_1);
    INSECT_SWARM                  = m_botdata->GetAI()->initSpell(INSECT_SWARM_1);
    FORCE_OF_NATURE               = m_botdata->GetAI()->initSpell(FORCE_OF_NATURE_1);
    HURRICANE                     = m_botdata->GetAI()->initSpell(HURRICANE_1);
    MARK_OF_THE_WILD              = m_botdata->GetAI()->initSpell(MARK_OF_THE_WILD_1); // buffs
    GIFT_OF_THE_WILD              = m_botdata->GetAI()->initSpell(GIFT_OF_THE_WILD_1);
    THORNS                        = m_botdata->GetAI()->initSpell(THORNS_1);
    BARKSKIN                      = m_botdata->GetAI()->initSpell(BARKSKIN_1);
    INNERVATE                     = m_botdata->GetAI()->initSpell(INNERVATE_1);
    FAERIE_FIRE                   = m_botdata->GetAI()->initSpell(FAERIE_FIRE_1); // debuffs
    FAERIE_FIRE_FERAL             = m_botdata->GetAI()->initSpell(FAERIE_FIRE_FERAL_1);
    REJUVENATION                  = m_botdata->GetAI()->initSpell(REJUVENATION_1); // heals
    REGROWTH                      = m_botdata->GetAI()->initSpell(REGROWTH_1);
    WILD_GROWTH                   = m_botdata->GetAI()->initSpell(WILD_GROWTH_1);
    LIFEBLOOM                     = m_botdata->GetAI()->initSpell(LIFEBLOOM_1);
    NOURISH                       = m_botdata->GetAI()->initSpell(NOURISH_1);
    HEALING_TOUCH                 = m_botdata->GetAI()->initSpell(HEALING_TOUCH_1);
    SWIFTMEND                     = m_botdata->GetAI()->initSpell(SWIFTMEND_1);
    TRANQUILITY                   = m_botdata->GetAI()->initSpell(TRANQUILITY_1);
    REVIVE                        = m_botdata->GetAI()->initSpell(REVIVE_1);
    REBIRTH                       = m_botdata->GetAI()->initSpell(REBIRTH_1);
    REMOVE_CURSE                  = m_botdata->GetAI()->initSpell(REMOVE_CURSE_DRUID_1);
    ABOLISH_POISON                = m_botdata->GetAI()->initSpell(ABOLISH_POISON_1);
    // Druid Forms
    MOONKIN_FORM                  = m_botdata->GetAI()->initSpell(MOONKIN_FORM_1);
    DIRE_BEAR_FORM                = m_botdata->GetAI()->initSpell(DIRE_BEAR_FORM_1);
    BEAR_FORM                     = m_botdata->GetAI()->initSpell(BEAR_FORM_1);
    CAT_FORM                      = m_botdata->GetAI()->initSpell(CAT_FORM_1);
    TREE_OF_LIFE                  = m_botdata->GetAI()->initSpell(TREE_OF_LIFE_1);
    TRAVEL_FORM                   = m_botdata->GetAI()->initSpell(TRAVEL_FORM_1);
    // Cat Attack type's
    RAKE                          = m_botdata->GetAI()->initSpell(RAKE_1);
    CLAW                          = m_botdata->GetAI()->initSpell(CLAW_1); // 45
    COWER                         = m_botdata->GetAI()->initSpell(COWER_1); // 20
    MANGLE                        = m_botdata->GetAI()->initSpell(MANGLE_1); // 45
    TIGERS_FURY                   = m_botdata->GetAI()->initSpell(TIGERS_FURY_1);
    MANGLE_CAT                    = m_botdata->GetAI()->initSpell(MANGLE_CAT_1); //40
    // Cat Finishing Move's
    RIP                           = m_botdata->GetAI()->initSpell(RIP_1); // 30
    FEROCIOUS_BITE                = m_botdata->GetAI()->initSpell(FEROCIOUS_BITE_1); // 35
    MAIM                          = m_botdata->GetAI()->initSpell(MAIM_1); // 35
    SAVAGE_ROAR                   = m_botdata->GetAI()->initSpell(SAVAGE_ROAR_1); //25
    // Bear/Dire Bear Attacks & Buffs
    BASH                          = m_botdata->GetAI()->initSpell(BASH_1);
    MAUL                          = m_botdata->GetAI()->initSpell(MAUL_1); // 15
    SWIPE                         = m_botdata->GetAI()->initSpell(SWIPE_BEAR_1); // 20
    DEMORALIZING_ROAR             = m_botdata->GetAI()->initSpell(DEMORALIZING_ROAR_1); // 10
    CHALLENGING_ROAR              = m_botdata->GetAI()->initSpell(CHALLENGING_ROAR_1);
    ENRAGE                        = m_botdata->GetAI()->initSpell(ENRAGE_1);
    GROWL                         = m_botdata->GetAI()->initSpell(GROWL_1);
    MANGLE_BEAR                   = m_botdata->GetAI()->initSpell(MANGLE_BEAR_1);
    LACERATE                      = m_botdata->GetAI()->initSpell(LACERATE_1);

    // racial
    SHADOWMELD                    = m_botdata->GetAI()->initSpell(SHADOWMELD_ALL);
    WAR_STOMP                     = m_botdata->GetAI()->initSpell(WAR_STOMP_ALL); // tauren

    //Procs
    ECLIPSE                       = m_botdata->GetAI()->initSpell(ECLIPSE_1);
    ECLIPSE_SOLAR                 = m_botdata->GetAI()->initSpell(ECLIPSE_SOLAR_1);
    ECLIPSE_LUNAR                 = m_botdata->GetAI()->initSpell(ECLIPSE_LUNAR_1);

	m_botdata->SetRezSpell(REVIVE);

	buff_list[0] = new PlayerbotBufflist;

	buff_list[0]->spellid.group				= { GIFT_OF_THE_WILD };						// Group Version
	buff_list[0]->spellid.single			= { MARK_OF_THE_WILD };						// Standard Version
	buff_list[0]->spellid.single_enhanced	= { NULL };									// Greater Version
	buff_list[0]->spec_required				= { NULL };									// Spec Required to cast
	buff_list[0]->caston_non_bot_all		= { PBOT_CLASS_ALL };						// Non-bot buff control
	buff_list[0]->caston_bot_role			= { BOT_ROLE::ROLE_ALL };					// Non-bot buff control
	buff_list[0]->caston_pet_all			= { PBOT_PET_ALL };							// Pet buff control

	buff_list[1] = new PlayerbotBufflist;

	buff_list[1]->spellid.group				= { NULL };									// Group Version
	buff_list[1]->spellid.single			= { THORNS };								// Standard Version
	buff_list[1]->spellid.single_enhanced	= { NULL };									// Greater Version
	buff_list[1]->spec_required				= { NULL };									// Spec Required to cast
	buff_list[1]->caston_non_bot_all		= { PBOT_CLASS_TANK | PBOT_CLASS_DRUID };	// Non-bot buff control
	buff_list[1]->caston_bot_role			= { BOT_ROLE::ROLE_TANK };					// Non-bot buff control
	buff_list[1]->caston_pet_all			= { PBOT_PET_ALL };							// Pet buff control

	m_botdata->SetRolePrimary(BOT_ROLE::ROLE_HEAL);
	
	return PlayerbotClassAI::PlayerbotClassAI_ClassAIInit();
}


CombatManeuverReturns PlayerbotDruidAI::DoNextManeuver_Heal_ClassSetup(Unit* pTarget)
{
	if (!m_botdata->GetAI())  return RETURN_NO_ACTION_ERROR;
	if (!m_botdata->GetBot()) return RETURN_NO_ACTION_ERROR;

	// (un)Shapeshifting is considered one step closer so will return true (and have the bot wait a bit for the GCD)
	if (TREE_OF_LIFE > 0 && !m_botdata->GetBot()->HasAura(TREE_OF_LIFE, EFFECT_INDEX_0))
		if (CastSpell(TREE_OF_LIFE, m_botdata->GetBot()))
			return RETURN_CONTINUE;

	if (m_botdata->GetBot()->HasAura(CAT_FORM, EFFECT_INDEX_0))
	{
		m_botdata->GetBot()->RemoveAurasDueToSpell(CAT_FORM_1);
		//m_botdata->GetAI()->TellMaster("FormClearCat");
		return RETURN_CONTINUE;
	}
	if (m_botdata->GetBot()->HasAura(BEAR_FORM, EFFECT_INDEX_0))
	{
		m_botdata->GetBot()->RemoveAurasDueToSpell(BEAR_FORM_1);
		//m_botdata->GetAI()->TellMaster("FormClearBear");
		return RETURN_CONTINUE;
	}
	if (m_botdata->GetBot()->HasAura(DIRE_BEAR_FORM, EFFECT_INDEX_0))
	{
		m_botdata->GetBot()->RemoveAurasDueToSpell(DIRE_BEAR_FORM_1);
		//m_botdata->GetAI()->TellMaster("FormClearDireBear");
		return RETURN_CONTINUE;
	}
	// spellcasting form, but disables healing spells so it's got to go
	if (m_botdata->GetBot()->HasAura(MOONKIN_FORM, EFFECT_INDEX_0))
	{
		m_botdata->GetBot()->RemoveAurasDueToSpell(MOONKIN_FORM_1);
		//m_botdata->GetAI()->TellMaster("FormClearMoonkin");
		return RETURN_CONTINUE;
	}

	m_botdata->SetRezSpell(REVIVE);

	return RETURN_CONTINUE;
}

CombatManeuverReturns PlayerbotDruidAI::DoFirstCombatManeuverPVE(Unit* /*pTarget*/)
{
    return RETURN_NO_ACTION_OK;
}

CombatManeuverReturns PlayerbotDruidAI::DoFirstCombatManeuverPVP(Unit* /*pTarget*/)
{
    return RETURN_NO_ACTION_OK;
}


CombatManeuverReturns PlayerbotDruidAI::DoNextCombatManeuverPVE(Unit* pTarget)
{
    if (!m_botdata->GetAI())  return RETURN_NO_ACTION_ERROR;
    if (!m_botdata->GetBot()) return RETURN_NO_ACTION_ERROR;

    //uint32 masterHP = m_botdata->GetMaster()->GetHealth() * 100 / m_botdata->GetMaster()->GetMaxHealth();

    uint32 spec = m_botdata->GetBot()->GetSpec();
    if (spec == 0) // default to spellcasting or healing for healer
        spec = (PlayerbotAI::ORDERS_HEAL & m_botdata->GetAI()->GetCombatOrder() ? DRUID_SPEC_RESTORATION : DRUID_SPEC_BALANCE);

    // Make sure healer stays put, don't even melee (aggro) if in range.
    if (m_botdata->GetAI()->IsHealer() && m_botdata->GetAI()->GetCombatStyle() != PlayerbotAI::COMBAT_RANGED)
        m_botdata->GetAI()->SetCombatStyle(PlayerbotAI::COMBAT_RANGED);
    else if (!m_botdata->GetAI()->IsHealer() && m_botdata->GetAI()->GetCombatStyle() != PlayerbotAI::COMBAT_MELEE)
        m_botdata->GetAI()->SetCombatStyle(PlayerbotAI::COMBAT_MELEE);

    //Unit* pVictim = pTarget->getVictim();
    uint32 BEAR = (DIRE_BEAR_FORM > 0 ? DIRE_BEAR_FORM : BEAR_FORM);

    // TODO: do something to allow emergency heals for non-healers?
    switch (CheckForms())
    {
        case RETURN_OK_SHIFTING:
            return RETURN_CONTINUE;

        case RETURN_FAIL:
        case RETURN_OK_CANNOTSHIFT:
            if (spec == DRUID_SPEC_FERAL)
                spec = DRUID_SPEC_BALANCE; // Can't shift, force spellcasting
            break; // rest functions without form

        //case RETURN_OK_NOCHANGE: // great!
        //case RETURN_FAIL_WAITINGONSELFBUFF: // This is war dammit! No time for silly buffs during combat...
        default:
            break;
    }

    //Used to determine if this bot is highest on threat
    Unit *newTarget = m_botdata->GetAI()->FindAttacker((PlayerbotAI::ATTACKERINFOTYPE) (PlayerbotAI::AIT_VICTIMSELF | PlayerbotAI::AIT_HIGHESTTHREAT), m_botdata->GetBot());
    if (newTarget) // TODO: && party has a tank
    {
        if (HealPlayer(m_botdata->GetBot()) == RETURN_CONTINUE)
            return RETURN_CONTINUE;

        // TODO: Heal tank

        // We have aggro, don't need to heal self or tank, wait for aggro to subside
        //if (m_botdata->GetAI()->IsHealer()) // Commented out: not necessary because of below. Leave code here in case below ever changes.
        //    return RETURN_NO_ACTION_OK;

        // We have no shoot spell; Assume auto-attack is on
        return RETURN_NO_ACTION_OK;
    }

    if (m_botdata->GetAI()->IsHealer())
       return DoNextManeuver_Heal(pTarget);

    switch (spec)
    {
        case DRUID_SPEC_FERAL:
            if (BEAR > 0 && m_botdata->GetBot()->HasAura(BEAR))
                return _DoNextPVECombatManeuverBear(pTarget);
            if (CAT_FORM > 0 && m_botdata->GetBot()->HasAura(CAT_FORM))
                return _DoNextPVECombatManeuverCat(pTarget);
            // NO break - failover to DRUID_SPEC_BALANCE

        case DRUID_SPEC_RESTORATION: // There is no Resto DAMAGE rotation. If you insist, go Balance...
        case DRUID_SPEC_BALANCE:
            if (m_botdata->GetBot()->HasAura(BEAR) || m_botdata->GetBot()->HasAura(CAT_FORM) || m_botdata->GetBot()->HasAura(TREE_OF_LIFE))
                return RETURN_NO_ACTION_UNKNOWN; // Didn't shift out of inappropriate form

            return _DoNextPVECombatManeuverSpellDPS(pTarget);

        /*if (BASH > 0 && !pTarget->HasAura(BASH, EFFECT_INDEX_0) && DruidSpellCombat < 5 && CastSpell(BASH, pTarget))
            return RETURN_CONTINUE;
        if (CHALLENGING_ROAR > 0 && pVictim != m_botdata->GetBot() && !pTarget->HasAura(CHALLENGING_ROAR, EFFECT_INDEX_0) && !pTarget->HasAura(GROWL, EFFECT_INDEX_0) && CastSpell(CHALLENGING_ROAR, pTarget))
            return RETURN_CONTINUE;
        if (ROOTS > 0 && !pTarget->HasAura(ROOTS, EFFECT_INDEX_0) && CastSpell(ROOTS, pTarget))
            return RETURN_CONTINUE;
        if (HURRICANE > 0 && ai->In_Reach(target,HURRICANE) && m_botdata->GetAI()->GetAttackerCount() >= 5 && CastSpell(HURRICANE, pTarget))
        {
            m_botdata->GetAI()->SetIgnoreUpdateTime(10);
            return RETURN_CONTINUE;
        }
        if (STARFALL > 0 && ai->In_Reach(target,STARFALL) && !m_botdata->GetBot()->HasAura(STARFALL, EFFECT_INDEX_0) && m_botdata->GetAI()->GetAttackerCount() >= 3 && CastSpell(STARFALL, pTarget))
            return RETURN_CONTINUE;
        if (BARKSKIN > 0 && pVictim == m_botdata->GetBot() && m_botdata->GetAI()->GetHealthPercent() < 75 && !m_botdata->GetBot()->HasAura(BARKSKIN, EFFECT_INDEX_0) && CastSpell(BARKSKIN, m_botdata->GetBot()))
            return RETURN_CONTINUE;
        if (INNERVATE > 0 && ai->In_Reach(m_botdata->GetBot(),INNERVATE) && !m_botdata->GetBot()->HasAura(INNERVATE, EFFECT_INDEX_0) && CastSpell(INNERVATE, m_botdata->GetBot()))
            return RETURN_CONTINUE;
        */
    }

    return RETURN_NO_ACTION_UNKNOWN;
} // end DoNextCombatManeuver

CombatManeuverReturns PlayerbotDruidAI::DoNextCombatManeuverPVP(Unit* pTarget)
{
    if (m_botdata->GetAI()->CastSpell(MOONFIRE))
        return RETURN_CONTINUE;

    return DoNextCombatManeuverPVE(pTarget); // TODO: bad idea perhaps, but better than the alternative
}

CombatManeuverReturns PlayerbotDruidAI::_DoNextPVECombatManeuverBear(Unit* pTarget)
{
    if (!m_botdata->GetAI())  return RETURN_NO_ACTION_ERROR;
    if (!m_botdata->GetBot()) return RETURN_NO_ACTION_ERROR;

    if (!m_botdata->GetBot()->HasAura( (DIRE_BEAR_FORM > 0 ? DIRE_BEAR_FORM : BEAR_FORM) )) return RETURN_NO_ACTION_ERROR;

    // Used to determine if this bot is highest on threat
    Unit* newTarget = m_botdata->GetAI()->FindAttacker((PlayerbotAI::ATTACKERINFOTYPE) (PlayerbotAI::AIT_VICTIMSELF | PlayerbotAI::AIT_HIGHESTTHREAT), m_botdata->GetBot());
    Unit* pVictim = pTarget->getVictim();

    // Face enemy, make sure you're attacking
    if (!m_botdata->GetBot()->HasInArc(pTarget))
    {
        m_botdata->GetBot()->SetFacingTo(m_botdata->GetBot()->GetAngle(pTarget));
        if (pVictim)
            pVictim->Attack(pTarget, true);
    }

    if (PlayerbotAI::ORDERS_TANK & m_botdata->GetAI()->GetCombatOrder() && !newTarget && GROWL > 0 && m_botdata->GetBot()->IsSpellReady(GROWL))
        if (CastSpell(GROWL, pTarget))
            return RETURN_CONTINUE;

    if (FAERIE_FIRE_FERAL > 0 && m_botdata->GetAI()->In_Reach(pTarget,FAERIE_FIRE_FERAL) && !pTarget->HasAura(FAERIE_FIRE_FERAL, EFFECT_INDEX_0))
        if (CastSpell(FAERIE_FIRE_FERAL, pTarget))
            return RETURN_CONTINUE;

    if (SWIPE > 0 && m_botdata->GetAI()->In_Reach(pTarget,SWIPE) && m_botdata->GetAI()->GetAttackerCount() >= 2 && CastSpell(SWIPE, pTarget))
        return RETURN_CONTINUE;

    if (ENRAGE > 0 && m_botdata->GetBot()->IsSpellReady(ENRAGE) && CastSpell(ENRAGE, m_botdata->GetBot()))
        return RETURN_CONTINUE;

    if (DEMORALIZING_ROAR > 0 && !pTarget->HasAura(DEMORALIZING_ROAR, EFFECT_INDEX_0) && CastSpell(DEMORALIZING_ROAR, pTarget))
        return RETURN_CONTINUE;

    if (MANGLE_BEAR > 0 && !pTarget->HasAura(MANGLE_BEAR) && CastSpell(MANGLE_BEAR, pTarget))
        return RETURN_CONTINUE;

    if (LACERATE > 0 && !pTarget->HasAura(LACERATE, EFFECT_INDEX_0) && CastSpell(LACERATE, pTarget))
        return RETURN_CONTINUE;

    if (MAUL > 0 && CastSpell(MAUL, pTarget))
        return RETURN_CONTINUE;

    return RETURN_NO_ACTION_UNKNOWN;
}

CombatManeuverReturns PlayerbotDruidAI::_DoNextPVECombatManeuverCat(Unit* pTarget)
{
    if (!m_botdata->GetAI())  return RETURN_NO_ACTION_ERROR;
    if (!m_botdata->GetBot()) return RETURN_NO_ACTION_ERROR;

    if (!m_botdata->GetBot()->HasAura(CAT_FORM)) return RETURN_NO_ACTION_UNKNOWN;

    //Used to determine if this bot is highest on threat
    Unit *newTarget = m_botdata->GetAI()->FindAttacker((PlayerbotAI::ATTACKERINFOTYPE) (PlayerbotAI::AIT_VICTIMSELF | PlayerbotAI::AIT_HIGHESTTHREAT), m_botdata->GetBot());
    Unit* pVictim = pTarget->getVictim();

    // Face enemy, make sure you're attacking
    if (!m_botdata->GetBot()->HasInArc(pTarget))
    {
        m_botdata->GetBot()->SetFacingTo(m_botdata->GetBot()->GetAngle(pTarget));
        if (pVictim)
            pVictim->Attack(pTarget, true);
    }

    // Attempt to do a finishing move
    if (m_botdata->GetBot()->GetComboPoints() >= 5)
    {
        // 25 Energy
        if (SAVAGE_ROAR > 0 && !m_botdata->GetBot()->HasAura(SAVAGE_ROAR))
        {
            if (CastSpell(SAVAGE_ROAR, pTarget))
                return RETURN_CONTINUE;
        }
        // 30 Energy
        else if (RIP > 0 && !pTarget->HasAura(RIP, EFFECT_INDEX_0))
        {
            if (CastSpell(RIP, pTarget))
                return RETURN_CONTINUE;
        }
        // 35 Energy
        else if (FEROCIOUS_BITE > 0)
        {
            if (CastSpell(FEROCIOUS_BITE, pTarget))
                return RETURN_CONTINUE;
        }
    } // End 5 ComboPoints

    if (newTarget && COWER > 0 && m_botdata->GetBot()->IsSpellReady(COWER) && CastSpell(COWER, pTarget))
        return RETURN_CONTINUE;

    if (FAERIE_FIRE_FERAL > 0 && m_botdata->GetAI()->In_Reach(pTarget,FAERIE_FIRE_FERAL) && !pTarget->HasAura(FAERIE_FIRE_FERAL, EFFECT_INDEX_0) && CastSpell(FAERIE_FIRE_FERAL, pTarget))
        return RETURN_CONTINUE;

    if (TIGERS_FURY > 0 && m_botdata->GetBot()->IsSpellReady(TIGERS_FURY) && CastSpell(TIGERS_FURY))
        return RETURN_CONTINUE;

    if (MANGLE_CAT > 0 && !pTarget->HasAura(MANGLE_CAT) && CastSpell(MANGLE_CAT))
        return RETURN_CONTINUE;

    if (RAKE > 0 && !pTarget->HasAura(RAKE) && CastSpell(RAKE, pTarget))
        return RETURN_CONTINUE;

    if (CLAW > 0 && CastSpell(CLAW, pTarget))
        return RETURN_CONTINUE;

    return RETURN_NO_ACTION_UNKNOWN;
}

CombatManeuverReturns PlayerbotDruidAI::_DoNextPVECombatManeuverSpellDPS(Unit* pTarget)
{
    if (!m_botdata->GetAI())  return RETURN_NO_ACTION_ERROR;
    if (!m_botdata->GetBot()) return RETURN_NO_ACTION_ERROR;

    uint32 NATURE = (STARFIRE > 0 ? STARFIRE : WRATH);

    if (FAERIE_FIRE > 0 && m_botdata->GetAI()->In_Reach(pTarget,FAERIE_FIRE) && !pTarget->HasAura(FAERIE_FIRE, EFFECT_INDEX_0) && CastSpell(FAERIE_FIRE, pTarget))
        return RETURN_CONTINUE;

    if (MOONFIRE > 0 && m_botdata->GetAI()->In_Reach(pTarget,MOONFIRE) && !pTarget->HasAura(MOONFIRE, EFFECT_INDEX_0) && CastSpell(MOONFIRE, pTarget))
        return RETURN_CONTINUE;

    if (INSECT_SWARM > 0 && m_botdata->GetAI()->In_Reach(pTarget,INSECT_SWARM) && !pTarget->HasAura(INSECT_SWARM, EFFECT_INDEX_0) && CastSpell(INSECT_SWARM, pTarget))
        return RETURN_CONTINUE;

    // TODO: Doesn't work, I can't seem to nail the aura/effect index that would make this work properly
    if (ECLIPSE_SOLAR > 0 && WRATH > 0 && m_botdata->GetAI()->In_Reach(pTarget,WRATH) && m_botdata->GetBot()->HasAura(ECLIPSE_SOLAR) && CastSpell(WRATH, pTarget))
        return RETURN_CONTINUE;

    // TODO: Doesn't work, I can't seem to nail the aura/effect index that would make this work properly
    if (ECLIPSE_LUNAR > 0 && m_botdata->GetAI()->In_Reach(pTarget,STARFIRE) && STARFIRE > 0 && m_botdata->GetBot()->HasAura(ECLIPSE_LUNAR) && CastSpell(STARFIRE, pTarget))
        return RETURN_CONTINUE;

    if (FORCE_OF_NATURE > 0 && m_botdata->GetAI()->In_Reach(pTarget,FORCE_OF_NATURE) && CastSpell(FORCE_OF_NATURE))
        return RETURN_CONTINUE;

    if (NATURE > 0 && CastSpell(NATURE, pTarget))
        return RETURN_CONTINUE;

    // Face enemy, make sure you're attacking
    if (!m_botdata->GetBot()->HasInArc(pTarget))
    {
        m_botdata->GetBot()->SetFacingTo(m_botdata->GetBot()->GetAngle(pTarget));
        if (m_botdata->GetAI()->GetCombatStyle() == PlayerbotAI::COMBAT_MELEE)
            m_botdata->GetBot()->Attack(pTarget, true);
        else
            m_botdata->GetBot()->AttackStop();
    }

    return RETURN_NO_ACTION_UNKNOWN;
}


CombatManeuverReturns PlayerbotDruidAI::HealPlayer(Player* target)
{
    CombatManeuverReturns r = PlayerbotClassAI::HealPlayer(target);
    if (r != RETURN_NO_ACTION_OK)
        return r;

    //If spell exists and orders say we should be dispelling
    if ((REMOVE_CURSE > 0 || ABOLISH_POISON > 0) && (m_botdata->GetAI()->GetCombatOrder() & PlayerbotAI::ORDERS_NODISPEL) == 0)
    {
        //This does something important(lol)
        uint32 dispelMask  = GetDispellMask(DISPEL_CURSE);
        uint32 dispelMask2  = GetDispellMask(DISPEL_POISON);
        //Get a list of all the targets auras(spells affecting target)
        Unit::SpellAuraHolderMap const& auras = target->GetSpellAuraHolderMap();
        //Iterate through the auras
        for (Unit::SpellAuraHolderMap::const_iterator itr = auras.begin(); itr != auras.end(); itr++)
        {
            SpellAuraHolder *holder = itr->second;
            //I dont know what this does but it doesn't work without it
            if ((1 << holder->GetSpellProto()->Dispel) & dispelMask)
            {
                //If the spell is dispellable and we can dispel it, do so
                if ((holder->GetSpellProto()->Dispel == DISPEL_CURSE) & (REMOVE_CURSE > 0))
                {
                    if (CastSpell(REMOVE_CURSE, target))
                        return RETURN_CONTINUE;
                    return RETURN_NO_ACTION_ERROR;
                }
            }
            else if ((1 << holder->GetSpellProto()->Dispel) & dispelMask2)
            {
                if ((holder->GetSpellProto()->Dispel == DISPEL_POISON) & (ABOLISH_POISON > 0))
                {
                    if (CastSpell(ABOLISH_POISON, target))
                        return RETURN_CONTINUE;
                    return RETURN_NO_ACTION_ERROR;
                }
            }
        }
    }

    uint8 hp = target->GetHealthPercent();

    // Everyone is healthy enough, return OK. MUST correlate to highest value below (should be last HP check)
    if (hp >= 90)
        return RETURN_NO_ACTION_OK;

    // Reset form if needed
    if (!m_botdata->GetBot()->HasAura(TREE_OF_LIFE) || TREE_OF_LIFE == 0)
        GoBuffForm(GetPlayerBot());

    // Start heals. Do lowest HP checks at the top
    if (hp < 30)
    {
        // TODO: Use in conjunction with Nature's Swiftness
        if (HEALING_TOUCH > 0 && m_botdata->GetAI()->In_Reach(target,HEALING_TOUCH) && (NOURISH == 0 /*|| CastSpell(NATURES_SWIFTNESS)*/ ) && CastSpell(HEALING_TOUCH, target))
            return RETURN_CONTINUE;

        if (NOURISH > 0 && m_botdata->GetAI()->In_Reach(target,NOURISH) && CastSpell(NOURISH, target))
            return RETURN_CONTINUE;
    }

    if (hp < 45 && WILD_GROWTH > 0 && m_botdata->GetAI()->In_Reach(target,WILD_GROWTH) && !target->HasAura(WILD_GROWTH) && CastSpell(WILD_GROWTH, target))
        return RETURN_CONTINUE;

    if (hp < 50 && SWIFTMEND > 0 && m_botdata->GetAI()->In_Reach(target,SWIFTMEND) && (target->HasAura(REJUVENATION) || target->HasAura(REGROWTH)) && CastSpell(SWIFTMEND, target))
        return RETURN_CONTINUE;

    if (hp < 60 && REGROWTH > 0 && m_botdata->GetAI()->In_Reach(target,REGROWTH) && !target->HasAura(REGROWTH) && CastSpell(REGROWTH, target))
        return RETURN_CONTINUE;

    if (hp < 65 && LIFEBLOOM > 0 && m_botdata->GetAI()->In_Reach(target,LIFEBLOOM) && !target->HasAura(LIFEBLOOM) && CastSpell(LIFEBLOOM, target))
        return RETURN_CONTINUE;

    if (hp < 90 && REJUVENATION > 0 && m_botdata->GetAI()->In_Reach(target,REJUVENATION) && !target->HasAura(REJUVENATION) && CastSpell(REJUVENATION, target))
        return RETURN_CONTINUE;

    return RETURN_NO_ACTION_UNKNOWN;
} // end HealTarget

/**
* CheckForms()
*
* Returns bool - Value indicates success - shape was shifted, already shifted, no need to shift.
*/
uint8 PlayerbotDruidAI::CheckForms()
{
    uint32 spec = m_botdata->GetBot()->GetSpec();
    uint32 BEAR = (DIRE_BEAR_FORM > 0 ? DIRE_BEAR_FORM : BEAR_FORM);

    if (spec == DRUID_SPEC_BALANCE)
    {
        if (m_botdata->GetBot()->HasAura(MOONKIN_FORM))
            return RETURN_OK_NOCHANGE;

        if (!MOONKIN_FORM)
            return RETURN_OK_CANNOTSHIFT;

        if (CastSpell(MOONKIN_FORM))
            return RETURN_OK_SHIFTING;
        else
            return RETURN_FAIL;
    }

    if (spec == DRUID_SPEC_FERAL)
    {
        // Use Bear form only if we are told we're a tank and have thorns up
        if (m_botdata->GetAI()->GetCombatOrder() & PlayerbotAI::ORDERS_TANK)
        {
            if (m_botdata->GetBot()->HasAura(BEAR))
                return RETURN_OK_NOCHANGE;

            if (!BEAR)
                return RETURN_OK_CANNOTSHIFT;

            if (!m_botdata->GetBot()->HasAura(THORNS))
                return RETURN_FAIL_WAITINGONSELFBUFF;

            if (CastSpell(BEAR))
                return RETURN_OK_SHIFTING;
            else
                return RETURN_FAIL;
        }
        else // No tank orders - try to go kitty or at least bear
        {
            if (CAT_FORM > 0)
            {
                if (m_botdata->GetBot()->HasAura(CAT_FORM))
                    return RETURN_OK_NOCHANGE;

                if (CastSpell(CAT_FORM))
                    return RETURN_OK_SHIFTING;
                else
                    return RETURN_FAIL;
            }

            if (BEAR > 0)
            {
                if (m_botdata->GetBot()->HasAura(BEAR))
                    return RETURN_OK_NOCHANGE;

                if (CastSpell(BEAR))
                    return RETURN_OK_SHIFTING;
                else
                    return RETURN_FAIL;
            }

            return RETURN_OK_CANNOTSHIFT;
        }
    }

    if (spec == DRUID_SPEC_RESTORATION)
    {
        if (m_botdata->GetBot()->HasAura(TREE_OF_LIFE))
            return RETURN_OK_NOCHANGE;

        if (!TREE_OF_LIFE)
            return RETURN_OK_CANNOTSHIFT;

        if (CastSpell(TREE_OF_LIFE))
            return RETURN_OK_SHIFTING;
        else
            return RETURN_FAIL;
    }

    // Unknown Spec
    return RETURN_FAIL;
}

CombatManeuverReturns PlayerbotDruidAI::DoManeuver_Idle_SelfBuff(void)
{
	if (INNERVATE && m_botdata->GetAI()->In_Reach(m_botdata->GetBot(), INNERVATE) && !m_botdata->GetBot()->HasAura(INNERVATE) && m_botdata->GetAI()->GetManaPercent() <= 20 && CastSpell(INNERVATE, m_botdata->GetBot()))
	{
		return RETURN_CONTINUE;
	}

	return RETURN_NO_ACTION_OK;
}

CombatManeuverReturns PlayerbotDruidAI::DoManeuver_Idle_Forms_End(void)
{
	if (CheckForms() != RETURN_FAIL)
	{
		return RETURN_CONTINUE;
	}

	return RETURN_NO_ACTION_OK;
}

CombatManeuverReturns PlayerbotDruidAI::BuffHelper(uint32 spellId, Unit* target)
{
    //DEBUG_LOG("..Druid_BuffHelper to the rescue!");
    if (spellId == 0) return RETURN_NO_ACTION_ERROR;
    if (!target)      return RETURN_NO_ACTION_INVALIDTARGET;
    //DEBUG_LOG("..Sanity checks passed");
	

    if (m_botdata->GetAI()->Buff(spellId, target, (m_ActionBeforeCast)))
    {
        //DEBUG_LOG("..Buffed");
        return RETURN_CONTINUE;
    }

    //DEBUG_LOG("..Not buffing anyone!");
    return RETURN_CONTINUE;
}

void PlayerbotDruidAI::GoBuffForm(Player* self)
{
    // RANK_1 spell ids used because this is a static method which does not have access to instance.
    // There is only one rank for these spells anyway.
    if (self->HasAura(CAT_FORM_1))
        self->RemoveAurasDueToSpell(CAT_FORM_1);
    if (self->HasAura(BEAR_FORM_1))
        self->RemoveAurasDueToSpell(BEAR_FORM_1);
    if (self->HasAura(DIRE_BEAR_FORM_1))
        self->RemoveAurasDueToSpell(DIRE_BEAR_FORM_1);
    if (self->HasAura(MOONKIN_FORM_1))
        self->RemoveAurasDueToSpell(MOONKIN_FORM_1);
    if (self->HasAura(TRAVEL_FORM_1))
        self->RemoveAurasDueToSpell(TRAVEL_FORM_1);
}

// Match up with "Pull()" below
bool PlayerbotDruidAI::CanPull()
{
    if (BEAR_FORM && FAERIE_FIRE_FERAL)
        return true;

    return false;
}

// Match up with "CanPull()" above
bool PlayerbotDruidAI::Pull()
{
    if (BEAR_FORM > 0 && (CastSpell(FAERIE_FIRE_FERAL) & RETURN_CONTINUE))
        return true;

    return false;
}

bool PlayerbotDruidAI::CastHoTOnTank()
{
    if (!m_botdata->GetAI()) return false;

    if ((PlayerbotAI::ORDERS_HEAL & m_botdata->GetAI()->GetCombatOrder()) == 0) return false;

    // Druid HoTs: Rejuvenation, Regrowth, Tranquility (channeled, AoE), Lifebloom, and Wild Growth
    if (REJUVENATION > 0)
        return (RETURN_CONTINUE & CastSpell(REJUVENATION, m_botdata->GetAI()->GetGroupTank()));

    return false;
}


/*
if (!target->isAlive())
{
if (m_botdata->GetBot()->isInCombat())
{
// TODO: Add check for cooldown
if (REBIRTH && m_botdata->GetAI()->In_Reach(target,REBIRTH) && m_botdata->GetAI()->CastSpell(REBIRTH, *target))
{
std::string msg = "Resurrecting ";
msg += target->GetName();
m_botdata->GetBot()->Say(msg, LANG_UNIVERSAL);
return RETURN_CONTINUE;
}
}
else
{
if (REVIVE && m_botdata->GetAI()->In_Reach(target,REVIVE) && m_botdata->GetAI()->CastSpell(REVIVE, *target))
{
std::string msg = "Resurrecting ";
msg += target->GetName();
m_botdata->GetBot()->Say(msg, LANG_UNIVERSAL);
return RETURN_CONTINUE;
}
}
return RETURN_NO_ACTION_ERROR; // not error per se - possibly just OOM
}
*/