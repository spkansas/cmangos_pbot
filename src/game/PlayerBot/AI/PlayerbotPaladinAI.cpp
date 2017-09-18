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
#include "PlayerbotPaladinAI.h"
#include "../Base/PlayerbotMgr.h"

class PlayerbotAI;

PlayerbotPaladinAI::PlayerbotPaladinAI(Player* const master, Player* const bot, PlayerbotAI* const ai) : PlayerbotClassAI(master, bot, ai)
{
    // TODO: fail on non-postivie return
    PlayerbotClassAI_ClassAIInit();
}


PlayerbotPaladinAI::~PlayerbotPaladinAI() 
{
}


bool PlayerbotPaladinAI::PlayerbotClassAI_ClassAIInit(void)
{
    RETRIBUTION_AURA              = m_botdata->GetAI()->initSpell(RETRIBUTION_AURA_1);
    CRUSADER_AURA                 = m_botdata->GetAI()->initSpell(CRUSADER_AURA_1);
    CRUSADER_STRIKE               = m_botdata->GetAI()->initSpell(CRUSADER_STRIKE_1);
    SEAL_OF_COMMAND               = m_botdata->GetAI()->initSpell(SEAL_OF_COMMAND_1);
    SEAL_OF_RIGHTEOUSNESS         = m_botdata->GetAI()->initSpell(SEAL_OF_RIGHTEOUSNESS_1);
    SEAL_OF_CORRUPTION            = m_botdata->GetAI()->initSpell(SEAL_OF_CORRUPTION_1);
    SEAL_OF_JUSTICE               = m_botdata->GetAI()->initSpell(SEAL_OF_JUSTICE_1);
    SEAL_OF_LIGHT                 = m_botdata->GetAI()->initSpell(SEAL_OF_LIGHT_1);
    SEAL_OF_VENGEANCE             = m_botdata->GetAI()->initSpell(SEAL_OF_VENGEANCE_1);
    SEAL_OF_WISDOM                = m_botdata->GetAI()->initSpell(SEAL_OF_WISDOM_1);
    JUDGEMENT_OF_LIGHT            = m_botdata->GetAI()->initSpell(JUDGEMENT_OF_LIGHT_1);
    JUDGEMENT_OF_WISDOM           = m_botdata->GetAI()->initSpell(JUDGEMENT_OF_WISDOM_1);
    JUDGEMENT_OF_JUSTICE          = m_botdata->GetAI()->initSpell(JUDGEMENT_OF_JUSTICE_1);
    DIVINE_STORM                  = m_botdata->GetAI()->initSpell(DIVINE_STORM_1);
    BLESSING_OF_MIGHT             = m_botdata->GetAI()->initSpell(BLESSING_OF_MIGHT_1);
    GREATER_BLESSING_OF_MIGHT     = m_botdata->GetAI()->initSpell(GREATER_BLESSING_OF_MIGHT_1);
    HAMMER_OF_WRATH               = m_botdata->GetAI()->initSpell(HAMMER_OF_WRATH_1);
    FLASH_OF_LIGHT                = m_botdata->GetAI()->initSpell(FLASH_OF_LIGHT_1); // Holy
    HOLY_LIGHT                    = m_botdata->GetAI()->initSpell(HOLY_LIGHT_1);
    HOLY_SHOCK                    = m_botdata->GetAI()->initSpell(HOLY_SHOCK_1);
    HOLY_WRATH                    = m_botdata->GetAI()->initSpell(HOLY_WRATH_1);
    DIVINE_FAVOR                  = m_botdata->GetAI()->initSpell(DIVINE_FAVOR_1);
    CONCENTRATION_AURA            = m_botdata->GetAI()->initSpell(CONCENTRATION_AURA_1);
    BLESSING_OF_WISDOM            = m_botdata->GetAI()->initSpell(BLESSING_OF_WISDOM_1);
    GREATER_BLESSING_OF_WISDOM    = m_botdata->GetAI()->initSpell(GREATER_BLESSING_OF_WISDOM_1);
    CONSECRATION                  = m_botdata->GetAI()->initSpell(CONSECRATION_1);
    AVENGING_WRATH                = m_botdata->GetAI()->initSpell(AVENGING_WRATH_1);
    LAY_ON_HANDS                  = m_botdata->GetAI()->initSpell(LAY_ON_HANDS_1);
    EXORCISM                      = m_botdata->GetAI()->initSpell(EXORCISM_1);
    SACRED_SHIELD                 = m_botdata->GetAI()->initSpell(SACRED_SHIELD_1);
    DIVINE_PLEA                   = m_botdata->GetAI()->initSpell(DIVINE_PLEA_1);
    BLESSING_OF_KINGS             = m_botdata->GetAI()->initSpell(BLESSING_OF_KINGS_1);
    GREATER_BLESSING_OF_KINGS     = m_botdata->GetAI()->initSpell(GREATER_BLESSING_OF_KINGS_1);
    BLESSING_OF_SANCTUARY         = m_botdata->GetAI()->initSpell(BLESSING_OF_SANCTUARY_1);
    GREATER_BLESSING_OF_SANCTUARY = m_botdata->GetAI()->initSpell(GREATER_BLESSING_OF_SANCTUARY_1);
    HAMMER_OF_JUSTICE             = m_botdata->GetAI()->initSpell(HAMMER_OF_JUSTICE_1);
    RIGHTEOUS_FURY                = m_botdata->GetAI()->initSpell(RIGHTEOUS_FURY_1);
    RIGHTEOUS_DEFENSE             = m_botdata->GetAI()->initSpell(RIGHTEOUS_DEFENSE_1);
    SHADOW_RESISTANCE_AURA        = m_botdata->GetAI()->initSpell(SHADOW_RESISTANCE_AURA_1);
    DEVOTION_AURA                 = m_botdata->GetAI()->initSpell(DEVOTION_AURA_1);
    FIRE_RESISTANCE_AURA          = m_botdata->GetAI()->initSpell(FIRE_RESISTANCE_AURA_1);
    FROST_RESISTANCE_AURA         = m_botdata->GetAI()->initSpell(FROST_RESISTANCE_AURA_1);
    HAND_OF_PROTECTION            = m_botdata->GetAI()->initSpell(HAND_OF_PROTECTION_1);
    DIVINE_PROTECTION             = m_botdata->GetAI()->initSpell(DIVINE_PROTECTION_1);
    DIVINE_INTERVENTION           = m_botdata->GetAI()->initSpell(DIVINE_INTERVENTION_1);
    DIVINE_SACRIFICE              = m_botdata->GetAI()->initSpell(DIVINE_SACRIFICE_1);
    DIVINE_SHIELD                 = m_botdata->GetAI()->initSpell(DIVINE_SHIELD_1);
    HOLY_SHIELD                   = m_botdata->GetAI()->initSpell(HOLY_SHIELD_1);
    AVENGERS_SHIELD               = m_botdata->GetAI()->initSpell(AVENGERS_SHIELD_1);
    HAND_OF_SACRIFICE             = m_botdata->GetAI()->initSpell(HAND_OF_SACRIFICE_1);
    SHIELD_OF_RIGHTEOUSNESS       = m_botdata->GetAI()->initSpell(SHIELD_OF_RIGHTEOUSNESS_1);
    REDEMPTION                    = m_botdata->GetAI()->initSpell(REDEMPTION_1);
    PURIFY                        = m_botdata->GetAI()->initSpell(PURIFY_1);
    CLEANSE                       = m_botdata->GetAI()->initSpell(CLEANSE_1);
    HAND_OF_RECKONING             = m_botdata->GetAI()->initSpell(HAND_OF_RECKONING_1);
    ART_OF_WAR                    = m_botdata->GetAI()->initSpell(ART_OF_WAR_1);
    HAMMER_OF_THE_RIGHTEOUS       = m_botdata->GetAI()->initSpell(HAMMER_OF_THE_RIGHTEOUS_1);

    // Warrior auras
    DEFENSIVE_STANCE              = 71;   //Def Stance
    BERSERKER_STANCE              = 2458; //Ber Stance
    BATTLE_STANCE                 = 2457; //Bat Stance

    FORBEARANCE                   = 25771; // cannot be protected

    // racial
    ARCANE_TORRENT                = m_botdata->GetAI()->initSpell(ARCANE_TORRENT_MANA_CLASSES);
    GIFT_OF_THE_NAARU             = m_botdata->GetAI()->initSpell(GIFT_OF_THE_NAARU_PALADIN); // draenei
    STONEFORM                     = m_botdata->GetAI()->initSpell(STONEFORM_ALL); // dwarf
    EVERY_MAN_FOR_HIMSELF         = m_botdata->GetAI()->initSpell(EVERY_MAN_FOR_HIMSELF_ALL); // human

    //The check doesn't work for now
    //PRAYER_OF_SHADOW_PROTECTION   = m_botdata->GetAI()->initSpell(PriestSpells::PRAYER_OF_SHADOW_PROTECTION_1);

	buff_list[0] = new PlayerbotBufflist;

	buff_list[0]->spellid.group				= { NULL };							// Group Version
	buff_list[0]->spellid.single			= { BLESSING_OF_MIGHT };			// Standard Version
	buff_list[0]->spellid.single_enhanced	= { GREATER_BLESSING_OF_MIGHT };	// Greater Version
	buff_list[0]->spec_required				= { NULL };							// Spec Required to cast
	buff_list[0]->caston_non_bot_all		= { PBOT_CLASS_TANK };				// Non-bot buff control
	buff_list[0]->caston_bot_role			= { BOT_ROLE::ROLE_TANK };			// Non-bot buff control
	buff_list[0]->caston_pet_all			= { PBOT_PET_ALL_TANK };			// Pet buff control

	buff_list[1] = new PlayerbotBufflist;

	buff_list[1]->spellid.group				= { NULL };							// Group Version
	buff_list[1]->spellid.single			= { BLESSING_OF_KINGS };			// Standard Version
	buff_list[1]->spellid.single_enhanced	= { GREATER_BLESSING_OF_KINGS };	// Greater Version
	buff_list[1]->spec_required				= { NULL };							// Spec Required to cast
	buff_list[1]->caston_non_bot_all		= { PBOT_CLASS_MELEEDPS | PBOT_CLASS_DRUID | PBOT_CLASS_SHAMAN };	// Non-bot buff control
	buff_list[1]->caston_bot_role			= { BOT_ROLE::ROLE_DPS_MELEE };		// Non-bot buff control
	buff_list[1]->caston_pet_all			= { PBOT_PET_ALL_HYBRID };			// Pet buff control

	buff_list[2] = new PlayerbotBufflist;

	buff_list[2]->spellid.group				= { NULL };							// Group Version
	buff_list[2]->spellid.single			= { BLESSING_OF_WISDOM };			// Standard Version
	buff_list[2]->spellid.single_enhanced	= { GREATER_BLESSING_OF_WISDOM };	// Greater Version
	buff_list[2]->spec_required				= { NULL };							// Spec Required to cast
	buff_list[2]->caston_non_bot_all		= { PBOT_CLASS_CASTER | PBOT_CLASS_PRIEST }; // Non-bot buff control
	buff_list[2]->caston_bot_role			= { (BOT_ROLE)(BOT_ROLE::ROLE_HEAL | BOT_ROLE::ROLE_DPS_CASTER) };	// Non-bot buff control
	buff_list[2]->caston_pet_all			= { PBOT_PET_ALL_MANA };			// Pet buff control

//	buff_list[3] = new PlayerbotBufflist;

//	buff_list[3]->spellid.group				= { NULL };							// Group Version
//	buff_list[3]->spellid.single			= { BLESSING_OF_SANCTUARY };		// Standard Version
//	buff_list[3]->spellid.single_enhanced	= { GREATER_BLESSING_OF_SANCTUARY };// Greater Version
//	buff_list[3]->spec_required				= { NULL };							// Spec Required to cast
//	buff_list[3]->caston_non_bot_all		= { PBOT_CLASS_ALL };				// Non-bot buff control

	m_botdata->SetRolePrimary(BOT_ROLE::ROLE_TANK);

    return PlayerbotClassAI::PlayerbotClassAI_ClassAIInit();
}


CombatManeuverReturns PlayerbotPaladinAI::DoNextManeuver_Heal_ClassSetup(Unit* pTarget)
{
	// No healing setup needed, so pass success
	return RETURN_CONTINUE;
}

CombatManeuverReturns PlayerbotPaladinAI::DoFirstCombatManeuverPVE(Unit* /*pTarget*/)
{
    return RETURN_NO_ACTION_OK;
}

CombatManeuverReturns PlayerbotPaladinAI::DoFirstCombatManeuverPVP(Unit* /*pTarget*/)
{
    return RETURN_NO_ACTION_OK;
}

CombatManeuverReturns PlayerbotPaladinAI::DoNextCombatManeuverPVE(Unit *pTarget)
{
    if (!m_botdata->GetAI())  return RETURN_NO_ACTION_ERROR;
    if (!m_botdata->GetBot()) return RETURN_NO_ACTION_ERROR;
    if (!pTarget) return RETURN_NO_ACTION_INVALIDTARGET;

    // damage spells
    uint32 spec = m_botdata->GetBot()->GetSpec();
    std::ostringstream out;

    // Make sure healer stays put, don't even melee (aggro) if in range.
    if (m_botdata->GetAI()->IsHealer() && m_botdata->GetAI()->GetCombatStyle() != PlayerbotAI::COMBAT_RANGED)
		m_botdata->GetAI()->SetCombatStyle(PlayerbotAI::COMBAT_RANGED);
    else if (!m_botdata->GetAI()->IsHealer() && m_botdata->GetAI()->GetCombatStyle() != PlayerbotAI::COMBAT_MELEE)
		m_botdata->GetAI()->SetCombatStyle(PlayerbotAI::COMBAT_MELEE);

    // Heal
    if (m_botdata->GetAI()->IsHealer())
    {
        if (HealPlayer(GetHealTarget()) & (RETURN_NO_ACTION_OK | RETURN_CONTINUE))
            return RETURN_CONTINUE;
    }
    else if (m_botdata->GetAI()->GetGroupHealer() && m_botdata->GetAI()->GetGroupHealer()->isAlive())
    {
        // Desirable? Debatable. We should have faith in the healer. On the other hand this low HP could be considered a crisis,
        // and DPS is not crucial so probably a good thing (which is why I put it in)
        // Of course, keep in mind we're not healing specced so it's unlikely to do much later on...
        if (!m_botdata->GetAI()->IsTank() && m_botdata->GetAI()->GetHealthPercent() < 35 && HealPlayer(m_botdata->GetBot()) & (RETURN_NO_ACTION_OK | RETURN_CONTINUE))
            return RETURN_CONTINUE;
    }
    else
    {
        // Is this desirable? Debatable.
        // TODO: In a group/raid with a healer you'd want this bot to focus on DPS (it's not specced/geared for healing either)
        if (m_botdata->GetAI()->GetHealthPercent() < 50 && HealPlayer(m_botdata->GetBot()) & (RETURN_NO_ACTION_OK | RETURN_CONTINUE))
            return RETURN_CONTINUE;
    }

    //Used to determine if this bot has highest threat
    Unit *newTarget = m_botdata->GetAI()->FindAttacker((PlayerbotAI::ATTACKERINFOTYPE) (PlayerbotAI::AIT_VICTIMSELF | PlayerbotAI::AIT_HIGHESTTHREAT), m_botdata->GetBot());
    switch (spec)
    {
        case PALADIN_SPEC_HOLY:
            if (m_botdata->GetAI()->IsHealer())
                return RETURN_NO_ACTION_OK;
            // else: DPS (retribution, NEVER protection)

        case PALADIN_SPEC_RETRIBUTION:
            if (HAMMER_OF_WRATH > 0 && pTarget->GetHealth() < pTarget->GetMaxHealth() * 0.20 && m_botdata->GetAI()->CastSpell (HAMMER_OF_WRATH, *pTarget))
                return RETURN_CONTINUE;
            if (ART_OF_WAR > 0 && EXORCISM > 0 && m_botdata->GetBot()->IsSpellReady(EXORCISM) && m_botdata->GetBot()->HasAura(ART_OF_WAR, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell (EXORCISM, *pTarget))
                return RETURN_CONTINUE;
            if (CRUSADER_STRIKE > 0 && m_botdata->GetBot()->IsSpellReady(CRUSADER_STRIKE) && m_botdata->GetAI()->CastSpell (CRUSADER_STRIKE, *pTarget))
                return RETURN_CONTINUE;
            if (DIVINE_STORM > 0 && /*m_botdata->GetAI()->GetAttackerCount() >= 3 && meleeReach*/ m_botdata->GetBot()->IsSpellReady(DIVINE_STORM) && m_botdata->GetAI()->CastSpell (DIVINE_STORM, *pTarget))
                return RETURN_CONTINUE;
            if (JUDGEMENT_OF_LIGHT > 0 && m_botdata->GetAI()->CastSpell (JUDGEMENT_OF_LIGHT, *pTarget))
                return RETURN_CONTINUE;
            if (AVENGING_WRATH > 0 && m_botdata->GetAI()->CastSpell (AVENGING_WRATH, *m_botdata->GetBot()))
                return RETURN_CONTINUE;
            /*if (HAMMER_OF_JUSTICE > 0 && !pTarget->HasAura(HAMMER_OF_JUSTICE, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell (HAMMER_OF_JUSTICE, *pTarget))
                return RETURN_CONTINUE;*/
            /*if (SACRED_SHIELD > 0 && pVictim == m_botdata->GetBot() && m_botdata->GetAI()->GetHealthPercent() < 70 && !m_botdata->GetBot()->HasAura(SACRED_SHIELD, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell (SACRED_SHIELD, *m_botdata->GetBot()))
                return RETURN_CONTINUE;*/
            /*if (HOLY_WRATH > 0 && m_botdata->GetAI()->GetAttackerCount() >= 3 && meleeReach && m_botdata->GetAI()->CastSpell (HOLY_WRATH, *pTarget))
                return RETURN_CONTINUE;*/
            /*if (HAND_OF_SACRIFICE > 0 && pVictim == m_botdata->GetMaster() && !m_botdata->GetMaster()->HasAura(HAND_OF_SACRIFICE, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell (HAND_OF_SACRIFICE, *m_botdata->GetMaster()))
                return RETURN_CONTINUE;*/
            /*if (DIVINE_PROTECTION > 0 && pVictim == m_botdata->GetBot() && !m_botdata->GetBot()->HasAura(FORBEARANCE, EFFECT_INDEX_0) && m_botdata->GetAI()->GetHealthPercent() < 30 && m_botdata->GetAI()->CastSpell (DIVINE_PROTECTION, *m_botdata->GetBot()))
                return RETURN_CONTINUE;*/
            /*if (RIGHTEOUS_DEFENSE > 0 && pVictim != m_botdata->GetBot() && m_botdata->GetAI()->GetHealthPercent() > 70 && m_botdata->GetAI()->CastSpell (RIGHTEOUS_DEFENSE, *pTarget))
                return RETURN_CONTINUE;*/
            /*if (DIVINE_PLEA > 0 && !m_botdata->GetBot()->HasAura(DIVINE_PLEA, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell (DIVINE_PLEA, *m_botdata->GetBot()))
                return RETURN_CONTINUE;*/
            /*if (DIVINE_FAVOR > 0 && !m_botdata->GetBot()->HasAura(DIVINE_FAVOR, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell (DIVINE_FAVOR, *m_botdata->GetBot()))
                return RETURN_CONTINUE;*/
            return RETURN_NO_ACTION_OK;

        case PALADIN_SPEC_PROTECTION:
            //Taunt if orders specify
            if (m_botdata->GetAI()->GetCombatOrder() & PlayerbotAI::ORDERS_TANK && !newTarget && HAND_OF_RECKONING > 0 && m_botdata->GetBot()->IsSpellReady(HAND_OF_RECKONING) && m_botdata->GetAI()->CastSpell(HAND_OF_RECKONING, *pTarget))
                return RETURN_CONTINUE;
            if (CONSECRATION > 0 && m_botdata->GetBot()->IsSpellReady(CONSECRATION) && m_botdata->GetAI()->CastSpell(CONSECRATION, *pTarget))
                return RETURN_CONTINUE;
            if (HOLY_SHIELD > 0 && !m_botdata->GetBot()->HasAura(HOLY_SHIELD) && m_botdata->GetAI()->CastSpell(HOLY_SHIELD, *m_botdata->GetBot()))
                return RETURN_CONTINUE;
            if (AVENGERS_SHIELD > 0 && m_botdata->GetBot()->IsSpellReady(AVENGERS_SHIELD) && m_botdata->GetAI()->CastSpell(AVENGERS_SHIELD, *pTarget))
                return RETURN_CONTINUE;
            if (HAMMER_OF_THE_RIGHTEOUS > 0 && m_botdata->GetBot()->IsSpellReady(HAMMER_OF_THE_RIGHTEOUS) && m_botdata->GetAI()->CastSpell(HAMMER_OF_THE_RIGHTEOUS, *pTarget))
                return RETURN_CONTINUE;
            if (SHIELD_OF_RIGHTEOUSNESS > 0 && m_botdata->GetBot()->IsSpellReady(SHIELD_OF_RIGHTEOUSNESS) && m_botdata->GetAI()->CastSpell(SHIELD_OF_RIGHTEOUSNESS, *pTarget))
                return RETURN_CONTINUE;
            if (JUDGEMENT_OF_LIGHT > 0 && m_botdata->GetAI()->CastSpell (JUDGEMENT_OF_LIGHT, *pTarget))
                return RETURN_CONTINUE;
            return RETURN_NO_ACTION_OK;
    }

    //if (DIVINE_SHIELD > 0 && m_botdata->GetAI()->GetHealthPercent() < 30 && pVictim == m_botdata->GetBot() && !m_botdata->GetBot()->HasAura(FORBEARANCE, EFFECT_INDEX_0) && !m_botdata->GetBot()->HasAura(DIVINE_SHIELD, EFFECT_INDEX_0))
    //    m_botdata->GetAI()->CastSpell(DIVINE_SHIELD, *m_botdata->GetBot());

    //if (DIVINE_SACRIFICE > 0 && m_botdata->GetAI()->GetHealthPercent() > 50 && pVictim != m_botdata->GetBot() && !m_botdata->GetBot()->HasAura(DIVINE_SACRIFICE, EFFECT_INDEX_0))
    //    m_botdata->GetAI()->CastSpell(DIVINE_SACRIFICE, *m_botdata->GetBot());

    return RETURN_NO_ACTION_OK;
}

CombatManeuverReturns PlayerbotPaladinAI::DoNextCombatManeuverPVP(Unit* pTarget)
{
    if (m_botdata->GetAI()->CastSpell(HAMMER_OF_JUSTICE))
        return RETURN_CONTINUE;

    return DoNextCombatManeuverPVE(pTarget); // TODO: bad idea perhaps, but better than the alternative
}

CombatManeuverReturns PlayerbotPaladinAI::HealPlayer(Player* target)
{
    CombatManeuverReturns r = PlayerbotClassAI::HealPlayer(target);
    if (r != RETURN_NO_ACTION_OK)
        return r;

    if (!target->isAlive())
    {
        if (REDEMPTION && m_botdata->GetAI()->CastSpell(REDEMPTION, *target))
        {
            std::string msg = "Resurrecting ";
            msg += target->GetName();
            m_botdata->GetBot()->Say(msg, LANG_UNIVERSAL);
            return RETURN_CONTINUE;
        }
        return RETURN_NO_ACTION_ERROR; // not error per se - possibly just OOM
    }

    if (PURIFY > 0 && (m_botdata->GetAI()->GetCombatOrder() & PlayerbotAI::ORDERS_NODISPEL) == 0)
    {
        uint32 DISPEL = CLEANSE > 0 ? CLEANSE : PURIFY;
        uint32 dispelMask  = GetDispellMask(DISPEL_DISEASE);
        uint32 dispelMask2 = GetDispellMask(DISPEL_POISON);
        uint32 dispelMask3 = GetDispellMask(DISPEL_MAGIC);
        Unit::SpellAuraHolderMap const& auras = target->GetSpellAuraHolderMap();
        for (Unit::SpellAuraHolderMap::const_iterator itr = auras.begin(); itr != auras.end(); ++itr)
        {
            SpellAuraHolder *holder = itr->second;
            if ((1 << holder->GetSpellProto()->Dispel) & dispelMask)
            {
                if (holder->GetSpellProto()->Dispel == DISPEL_DISEASE)
                {
                    if (m_botdata->GetAI()->CastSpell(DISPEL, *target))
                        return RETURN_CONTINUE;
                    return RETURN_NO_ACTION_ERROR;
                }
            }
            else if ((1 << holder->GetSpellProto()->Dispel) & dispelMask2)
            {
                if (holder->GetSpellProto()->Dispel == DISPEL_POISON)
                {
                    if (m_botdata->GetAI()->CastSpell(DISPEL, *target))
                        return RETURN_CONTINUE;
                    return RETURN_NO_ACTION_ERROR;
                }
            }
            else if ((1 << holder->GetSpellProto()->Dispel) & dispelMask3 & (DISPEL == CLEANSE))
            {
                if (holder->GetSpellProto()->Dispel == DISPEL_MAGIC)
                {
                    if (m_botdata->GetAI()->CastSpell(DISPEL, *target))
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

    if (hp < 25 && m_botdata->GetAI()->CastSpell(LAY_ON_HANDS, *target))
        return RETURN_CONTINUE;

    // You probably want to save this for tank/healer trouble
    if (hp < 30 && HAND_OF_PROTECTION > 0 && !target->HasAura(FORBEARANCE, EFFECT_INDEX_0)
        && !target->HasAura(HAND_OF_PROTECTION, EFFECT_INDEX_0) && !target->HasAura(DIVINE_PROTECTION, EFFECT_INDEX_0)
        && !target->HasAura(DIVINE_SHIELD, EFFECT_INDEX_0) && (GetTargetJob(target) & (JOB_HEAL | JOB_TANK))
        && m_botdata->GetAI()->CastSpell(HAND_OF_PROTECTION, *target))
        return RETURN_CONTINUE;

    // Isn't this more of a group heal spell?
    if (hp < 40 && m_botdata->GetAI()->CastSpell(FLASH_OF_LIGHT, *target))
        return RETURN_CONTINUE;

    if (hp < 60 && m_botdata->GetAI()->CastSpell(HOLY_SHOCK, *target))
        return RETURN_CONTINUE;

    if (hp < 90 && m_botdata->GetAI()->CastSpell(HOLY_LIGHT, *target))
        return RETURN_CONTINUE;

    return RETURN_NO_ACTION_UNKNOWN;
} // end HealTarget

void PlayerbotPaladinAI::CheckAuras()
{
    if (!m_botdata->GetAI())  return;
    if (!m_botdata->GetBot()) return;

    uint32 spec = m_botdata->GetBot()->GetSpec();

    // If we have resist orders, adjust accordingly
    if (m_botdata->GetAI()->GetCombatOrder() & PlayerbotAI::ORDERS_RESIST_FROST)
    {
        if (!m_botdata->GetBot()->HasAura(FROST_RESISTANCE_AURA) && FROST_RESISTANCE_AURA > 0 && !m_botdata->GetBot()->HasAura(FROST_RESISTANCE_AURA))
            m_botdata->GetAI()->CastSpell(FROST_RESISTANCE_AURA);
        return;
    }
    else if (m_botdata->GetAI()->GetCombatOrder() & PlayerbotAI::ORDERS_RESIST_FIRE)
    {
        if (!m_botdata->GetBot()->HasAura(FIRE_RESISTANCE_AURA) && FIRE_RESISTANCE_AURA > 0 && !m_botdata->GetBot()->HasAura(FIRE_RESISTANCE_AURA))
            m_botdata->GetAI()->CastSpell(FIRE_RESISTANCE_AURA);
        return;
    }
    else if (m_botdata->GetAI()->GetCombatOrder() & PlayerbotAI::ORDERS_RESIST_SHADOW)
    {
        // Shadow protection check is broken, they stack!
        if (!m_botdata->GetBot()->HasAura(SHADOW_RESISTANCE_AURA) && SHADOW_RESISTANCE_AURA > 0 && !m_botdata->GetBot()->HasAura(SHADOW_RESISTANCE_AURA)) // /*&& !m_botdata->GetBot()->HasAura(PRAYER_OF_SHADOW_PROTECTION)*/ /*&& !m_botdata->GetBot()->HasAura(PRAYER_OF_SHADOW_PROTECTION)*/
            m_botdata->GetAI()->CastSpell(SHADOW_RESISTANCE_AURA);
        return;
    }

    // If we have no resist orders, adjust aura based on spec
    if (spec == PALADIN_SPEC_HOLY)
    {
        if (CONCENTRATION_AURA > 0 && !m_botdata->GetBot()->HasAura(CONCENTRATION_AURA))
            m_botdata->GetAI()->CastSpell(CONCENTRATION_AURA);
        return;
    }
    else if (spec == PALADIN_SPEC_PROTECTION)
    {
        if (DEVOTION_AURA > 0 && !m_botdata->GetBot()->HasAura(DEVOTION_AURA))
            m_botdata->GetAI()->CastSpell(DEVOTION_AURA);
        return;
    }
    else if (spec == PALADIN_SPEC_RETRIBUTION)
    {
        if (RETRIBUTION_AURA > 0 && !m_botdata->GetBot()->HasAura(RETRIBUTION_AURA))
            m_botdata->GetAI()->CastSpell(RETRIBUTION_AURA);
        return;
    }

}

bool PlayerbotPaladinAI::CheckSeals()
{
    if (!m_botdata->GetAI())  return false;
    if (!m_botdata->GetBot()) return false;

    uint32 spec = m_botdata->GetBot()->GetSpec();

    switch (spec)
    {
        case PALADIN_SPEC_HOLY:
            if (SEAL_OF_WISDOM > 0 && !m_botdata->GetBot()->HasAura(SEAL_OF_WISDOM, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(SEAL_OF_WISDOM, *m_botdata->GetBot()))
                return true;
            break;

        case PALADIN_SPEC_PROTECTION:
            if (SEAL_OF_RIGHTEOUSNESS > 0 && !m_botdata->GetBot()->HasAura(SEAL_OF_RIGHTEOUSNESS, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(SEAL_OF_RIGHTEOUSNESS, *m_botdata->GetBot()))
                return true;
            break;

        case PALADIN_SPEC_RETRIBUTION:
            if (SEAL_OF_COMMAND > 0 && !m_botdata->GetBot()->HasAura(SEAL_OF_COMMAND, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(SEAL_OF_COMMAND, *m_botdata->GetBot()))
                return true;
            else if (SEAL_OF_RIGHTEOUSNESS > 0 && !m_botdata->GetBot()->HasAura(SEAL_OF_RIGHTEOUSNESS, EFFECT_INDEX_0) && !m_botdata->GetBot()->HasAura(SEAL_OF_COMMAND, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(SEAL_OF_RIGHTEOUSNESS, *m_botdata->GetBot()))
                return true;
            break;
    }
    return false;
}


CombatManeuverReturns PlayerbotPaladinAI::DoManeuver_Idle_SelfBuff(void)
{
	CheckAuras();

	//Put up RF if tank
	if (m_botdata->GetAI()->GetCombatOrder() & PlayerbotAI::ORDERS_TANK)
		m_botdata->GetAI()->SelfBuff(RIGHTEOUS_FURY);
	//Disable RF if not tank
	else if (m_botdata->GetBot()->HasAura(RIGHTEOUS_FURY))
		m_botdata->GetBot()->RemoveAurasDueToSpell(RIGHTEOUS_FURY);

	return RETURN_NO_ACTION_OK;
}


// Match up with "Pull()" below
bool PlayerbotPaladinAI::CanPull()
{
    if (HAND_OF_RECKONING && m_botdata->GetBot()->IsSpellReady(HAND_OF_RECKONING))
        return true;
    if (EXORCISM && m_botdata->GetBot()->IsSpellReady(EXORCISM))
        return true;

    return false;
}

// Match up with "CanPull()" above
bool PlayerbotPaladinAI::Pull()
{
    if (HAND_OF_RECKONING && m_botdata->GetAI()->CastSpell(HAND_OF_RECKONING))
        return true;
    if (EXORCISM && m_botdata->GetAI()->CastSpell(EXORCISM))
        return true;

    return false;
}

bool PlayerbotPaladinAI::CastHoTOnTank()
{
    if (!m_botdata->GetAI()) return false;

    if ((PlayerbotAI::ORDERS_HEAL & m_botdata->GetAI()->GetCombatOrder()) == 0) return false;

    // Paladin: Sheath of Light (with talents), Flash of Light (with Infusion of Light talent and only on a target with the Sacred Shield buff),
    //          Holy Shock (with Tier 8 set bonus)
    // None of these are HoTs to cast before pulling (I think)

    return false;
}
