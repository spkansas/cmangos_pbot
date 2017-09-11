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
    RETRIBUTION_AURA              = GetAI()->initSpell(RETRIBUTION_AURA_1);
    CRUSADER_AURA                 = GetAI()->initSpell(CRUSADER_AURA_1);
    CRUSADER_STRIKE               = GetAI()->initSpell(CRUSADER_STRIKE_1);
    SEAL_OF_COMMAND               = GetAI()->initSpell(SEAL_OF_COMMAND_1);
    SEAL_OF_RIGHTEOUSNESS         = GetAI()->initSpell(SEAL_OF_RIGHTEOUSNESS_1);
    SEAL_OF_CORRUPTION            = GetAI()->initSpell(SEAL_OF_CORRUPTION_1);
    SEAL_OF_JUSTICE               = GetAI()->initSpell(SEAL_OF_JUSTICE_1);
    SEAL_OF_LIGHT                 = GetAI()->initSpell(SEAL_OF_LIGHT_1);
    SEAL_OF_VENGEANCE             = GetAI()->initSpell(SEAL_OF_VENGEANCE_1);
    SEAL_OF_WISDOM                = GetAI()->initSpell(SEAL_OF_WISDOM_1);
    JUDGEMENT_OF_LIGHT            = GetAI()->initSpell(JUDGEMENT_OF_LIGHT_1);
    JUDGEMENT_OF_WISDOM           = GetAI()->initSpell(JUDGEMENT_OF_WISDOM_1);
    JUDGEMENT_OF_JUSTICE          = GetAI()->initSpell(JUDGEMENT_OF_JUSTICE_1);
    DIVINE_STORM                  = GetAI()->initSpell(DIVINE_STORM_1);
    BLESSING_OF_MIGHT             = GetAI()->initSpell(BLESSING_OF_MIGHT_1);
    GREATER_BLESSING_OF_MIGHT     = GetAI()->initSpell(GREATER_BLESSING_OF_MIGHT_1);
    HAMMER_OF_WRATH               = GetAI()->initSpell(HAMMER_OF_WRATH_1);
    FLASH_OF_LIGHT                = GetAI()->initSpell(FLASH_OF_LIGHT_1); // Holy
    HOLY_LIGHT                    = GetAI()->initSpell(HOLY_LIGHT_1);
    HOLY_SHOCK                    = GetAI()->initSpell(HOLY_SHOCK_1);
    HOLY_WRATH                    = GetAI()->initSpell(HOLY_WRATH_1);
    DIVINE_FAVOR                  = GetAI()->initSpell(DIVINE_FAVOR_1);
    CONCENTRATION_AURA            = GetAI()->initSpell(CONCENTRATION_AURA_1);
    BLESSING_OF_WISDOM            = GetAI()->initSpell(BLESSING_OF_WISDOM_1);
    GREATER_BLESSING_OF_WISDOM    = GetAI()->initSpell(GREATER_BLESSING_OF_WISDOM_1);
    CONSECRATION                  = GetAI()->initSpell(CONSECRATION_1);
    AVENGING_WRATH                = GetAI()->initSpell(AVENGING_WRATH_1);
    LAY_ON_HANDS                  = GetAI()->initSpell(LAY_ON_HANDS_1);
    EXORCISM                      = GetAI()->initSpell(EXORCISM_1);
    SACRED_SHIELD                 = GetAI()->initSpell(SACRED_SHIELD_1);
    DIVINE_PLEA                   = GetAI()->initSpell(DIVINE_PLEA_1);
    BLESSING_OF_KINGS             = GetAI()->initSpell(BLESSING_OF_KINGS_1);
    GREATER_BLESSING_OF_KINGS     = GetAI()->initSpell(GREATER_BLESSING_OF_KINGS_1);
    BLESSING_OF_SANCTUARY         = GetAI()->initSpell(BLESSING_OF_SANCTUARY_1);
    GREATER_BLESSING_OF_SANCTUARY = GetAI()->initSpell(GREATER_BLESSING_OF_SANCTUARY_1);
    HAMMER_OF_JUSTICE             = GetAI()->initSpell(HAMMER_OF_JUSTICE_1);
    RIGHTEOUS_FURY                = GetAI()->initSpell(RIGHTEOUS_FURY_1);
    RIGHTEOUS_DEFENSE             = GetAI()->initSpell(RIGHTEOUS_DEFENSE_1);
    SHADOW_RESISTANCE_AURA        = GetAI()->initSpell(SHADOW_RESISTANCE_AURA_1);
    DEVOTION_AURA                 = GetAI()->initSpell(DEVOTION_AURA_1);
    FIRE_RESISTANCE_AURA          = GetAI()->initSpell(FIRE_RESISTANCE_AURA_1);
    FROST_RESISTANCE_AURA         = GetAI()->initSpell(FROST_RESISTANCE_AURA_1);
    HAND_OF_PROTECTION            = GetAI()->initSpell(HAND_OF_PROTECTION_1);
    DIVINE_PROTECTION             = GetAI()->initSpell(DIVINE_PROTECTION_1);
    DIVINE_INTERVENTION           = GetAI()->initSpell(DIVINE_INTERVENTION_1);
    DIVINE_SACRIFICE              = GetAI()->initSpell(DIVINE_SACRIFICE_1);
    DIVINE_SHIELD                 = GetAI()->initSpell(DIVINE_SHIELD_1);
    HOLY_SHIELD                   = GetAI()->initSpell(HOLY_SHIELD_1);
    AVENGERS_SHIELD               = GetAI()->initSpell(AVENGERS_SHIELD_1);
    HAND_OF_SACRIFICE             = GetAI()->initSpell(HAND_OF_SACRIFICE_1);
    SHIELD_OF_RIGHTEOUSNESS       = GetAI()->initSpell(SHIELD_OF_RIGHTEOUSNESS_1);
    REDEMPTION                    = GetAI()->initSpell(REDEMPTION_1);
    PURIFY                        = GetAI()->initSpell(PURIFY_1);
    CLEANSE                       = GetAI()->initSpell(CLEANSE_1);
    HAND_OF_RECKONING             = GetAI()->initSpell(HAND_OF_RECKONING_1);
    ART_OF_WAR                    = GetAI()->initSpell(ART_OF_WAR_1);
    HAMMER_OF_THE_RIGHTEOUS       = GetAI()->initSpell(HAMMER_OF_THE_RIGHTEOUS_1);

    // Warrior auras
    DEFENSIVE_STANCE              = 71;   //Def Stance
    BERSERKER_STANCE              = 2458; //Ber Stance
    BATTLE_STANCE                 = 2457; //Bat Stance

    FORBEARANCE                   = 25771; // cannot be protected

    RECENTLY_BANDAGED             = 11196; // first aid check

    // racial
    ARCANE_TORRENT                = GetAI()->initSpell(ARCANE_TORRENT_MANA_CLASSES);
    GIFT_OF_THE_NAARU             = GetAI()->initSpell(GIFT_OF_THE_NAARU_PALADIN); // draenei
    STONEFORM                     = GetAI()->initSpell(STONEFORM_ALL); // dwarf
    EVERY_MAN_FOR_HIMSELF         = GetAI()->initSpell(EVERY_MAN_FOR_HIMSELF_ALL); // human

    //The check doesn't work for now
    //PRAYER_OF_SHADOW_PROTECTION   = GetAI()->initSpell(PriestSpells::PRAYER_OF_SHADOW_PROTECTION_1);
}

PlayerbotPaladinAI::~PlayerbotPaladinAI() {}

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
    if (!GetAI())  return RETURN_NO_ACTION_ERROR;
    if (!m_bot) return RETURN_NO_ACTION_ERROR;
    if (!pTarget) return RETURN_NO_ACTION_INVALIDTARGET;

    // damage spells
    uint32 spec = m_bot->GetSpec();
    std::ostringstream out;

    // Make sure healer stays put, don't even melee (aggro) if in range.
    if (GetAI()->IsHealer() && GetAI()->GetCombatStyle() != PlayerbotAI::COMBAT_RANGED)
		GetAI()->SetCombatStyle(PlayerbotAI::COMBAT_RANGED);
    else if (!GetAI()->IsHealer() && GetAI()->GetCombatStyle() != PlayerbotAI::COMBAT_MELEE)
		GetAI()->SetCombatStyle(PlayerbotAI::COMBAT_MELEE);

    // Heal
    if (GetAI()->IsHealer())
    {
        if (HealPlayer(GetHealTarget()) & (RETURN_NO_ACTION_OK | RETURN_CONTINUE))
            return RETURN_CONTINUE;
    }
    else if (GetAI()->GetGroupHealer() && GetAI()->GetGroupHealer()->isAlive())
    {
        // Desirable? Debatable. We should have faith in the healer. On the other hand this low HP could be considered a crisis,
        // and DPS is not crucial so probably a good thing (which is why I put it in)
        // Of course, keep in mind we're not healing specced so it's unlikely to do much later on...
        if (!GetAI()->IsTank() && GetAI()->GetHealthPercent() < 35 && HealPlayer(m_bot) & (RETURN_NO_ACTION_OK | RETURN_CONTINUE))
            return RETURN_CONTINUE;
    }
    else
    {
        // Is this desirable? Debatable.
        // TODO: In a group/raid with a healer you'd want this bot to focus on DPS (it's not specced/geared for healing either)
        if (GetAI()->GetHealthPercent() < 50 && HealPlayer(m_bot) & (RETURN_NO_ACTION_OK | RETURN_CONTINUE))
            return RETURN_CONTINUE;
    }

    //Used to determine if this bot has highest threat
    Unit *newTarget = GetAI()->FindAttacker((PlayerbotAI::ATTACKERINFOTYPE) (PlayerbotAI::AIT_VICTIMSELF | PlayerbotAI::AIT_HIGHESTTHREAT), m_bot);
    switch (spec)
    {
        case PALADIN_SPEC_HOLY:
            if (GetAI()->IsHealer())
                return RETURN_NO_ACTION_OK;
            // else: DPS (retribution, NEVER protection)

        case PALADIN_SPEC_RETRIBUTION:
            if (HAMMER_OF_WRATH > 0 && pTarget->GetHealth() < pTarget->GetMaxHealth() * 0.20 && GetAI()->CastSpell (HAMMER_OF_WRATH, *pTarget))
                return RETURN_CONTINUE;
            if (ART_OF_WAR > 0 && EXORCISM > 0 && m_bot->IsSpellReady(EXORCISM) && m_bot->HasAura(ART_OF_WAR, EFFECT_INDEX_0) && GetAI()->CastSpell (EXORCISM, *pTarget))
                return RETURN_CONTINUE;
            if (CRUSADER_STRIKE > 0 && m_bot->IsSpellReady(CRUSADER_STRIKE) && GetAI()->CastSpell (CRUSADER_STRIKE, *pTarget))
                return RETURN_CONTINUE;
            if (DIVINE_STORM > 0 && /*GetAI()->GetAttackerCount() >= 3 && meleeReach*/ m_bot->IsSpellReady(DIVINE_STORM) && GetAI()->CastSpell (DIVINE_STORM, *pTarget))
                return RETURN_CONTINUE;
            if (JUDGEMENT_OF_LIGHT > 0 && GetAI()->CastSpell (JUDGEMENT_OF_LIGHT, *pTarget))
                return RETURN_CONTINUE;
            if (AVENGING_WRATH > 0 && GetAI()->CastSpell (AVENGING_WRATH, *m_bot))
                return RETURN_CONTINUE;
            /*if (HAMMER_OF_JUSTICE > 0 && !pTarget->HasAura(HAMMER_OF_JUSTICE, EFFECT_INDEX_0) && GetAI()->CastSpell (HAMMER_OF_JUSTICE, *pTarget))
                return RETURN_CONTINUE;*/
            /*if (SACRED_SHIELD > 0 && pVictim == m_bot && GetAI()->GetHealthPercent() < 70 && !m_bot->HasAura(SACRED_SHIELD, EFFECT_INDEX_0) && GetAI()->CastSpell (SACRED_SHIELD, *m_bot))
                return RETURN_CONTINUE;*/
            /*if (HOLY_WRATH > 0 && GetAI()->GetAttackerCount() >= 3 && meleeReach && GetAI()->CastSpell (HOLY_WRATH, *pTarget))
                return RETURN_CONTINUE;*/
            /*if (HAND_OF_SACRIFICE > 0 && pVictim == GetMaster() && !GetMaster()->HasAura(HAND_OF_SACRIFICE, EFFECT_INDEX_0) && GetAI()->CastSpell (HAND_OF_SACRIFICE, *GetMaster()))
                return RETURN_CONTINUE;*/
            /*if (DIVINE_PROTECTION > 0 && pVictim == m_bot && !m_bot->HasAura(FORBEARANCE, EFFECT_INDEX_0) && GetAI()->GetHealthPercent() < 30 && GetAI()->CastSpell (DIVINE_PROTECTION, *m_bot))
                return RETURN_CONTINUE;*/
            /*if (RIGHTEOUS_DEFENSE > 0 && pVictim != m_bot && GetAI()->GetHealthPercent() > 70 && GetAI()->CastSpell (RIGHTEOUS_DEFENSE, *pTarget))
                return RETURN_CONTINUE;*/
            /*if (DIVINE_PLEA > 0 && !m_bot->HasAura(DIVINE_PLEA, EFFECT_INDEX_0) && GetAI()->CastSpell (DIVINE_PLEA, *m_bot))
                return RETURN_CONTINUE;*/
            /*if (DIVINE_FAVOR > 0 && !m_bot->HasAura(DIVINE_FAVOR, EFFECT_INDEX_0) && GetAI()->CastSpell (DIVINE_FAVOR, *m_bot))
                return RETURN_CONTINUE;*/
            return RETURN_NO_ACTION_OK;

        case PALADIN_SPEC_PROTECTION:
            //Taunt if orders specify
            if (GetAI()->GetCombatOrder() & PlayerbotAI::ORDERS_TANK && !newTarget && HAND_OF_RECKONING > 0 && m_bot->IsSpellReady(HAND_OF_RECKONING) && GetAI()->CastSpell(HAND_OF_RECKONING, *pTarget))
                return RETURN_CONTINUE;
            if (CONSECRATION > 0 && m_bot->IsSpellReady(CONSECRATION) && GetAI()->CastSpell(CONSECRATION, *pTarget))
                return RETURN_CONTINUE;
            if (HOLY_SHIELD > 0 && !m_bot->HasAura(HOLY_SHIELD) && GetAI()->CastSpell(HOLY_SHIELD, *m_bot))
                return RETURN_CONTINUE;
            if (AVENGERS_SHIELD > 0 && m_bot->IsSpellReady(AVENGERS_SHIELD) && GetAI()->CastSpell(AVENGERS_SHIELD, *pTarget))
                return RETURN_CONTINUE;
            if (HAMMER_OF_THE_RIGHTEOUS > 0 && m_bot->IsSpellReady(HAMMER_OF_THE_RIGHTEOUS) && GetAI()->CastSpell(HAMMER_OF_THE_RIGHTEOUS, *pTarget))
                return RETURN_CONTINUE;
            if (SHIELD_OF_RIGHTEOUSNESS > 0 && m_bot->IsSpellReady(SHIELD_OF_RIGHTEOUSNESS) && GetAI()->CastSpell(SHIELD_OF_RIGHTEOUSNESS, *pTarget))
                return RETURN_CONTINUE;
            if (JUDGEMENT_OF_LIGHT > 0 && GetAI()->CastSpell (JUDGEMENT_OF_LIGHT, *pTarget))
                return RETURN_CONTINUE;
            return RETURN_NO_ACTION_OK;
    }

    //if (DIVINE_SHIELD > 0 && GetAI()->GetHealthPercent() < 30 && pVictim == m_bot && !m_bot->HasAura(FORBEARANCE, EFFECT_INDEX_0) && !m_bot->HasAura(DIVINE_SHIELD, EFFECT_INDEX_0))
    //    GetAI()->CastSpell(DIVINE_SHIELD, *m_bot);

    //if (DIVINE_SACRIFICE > 0 && GetAI()->GetHealthPercent() > 50 && pVictim != m_bot && !m_bot->HasAura(DIVINE_SACRIFICE, EFFECT_INDEX_0))
    //    GetAI()->CastSpell(DIVINE_SACRIFICE, *m_bot);

    return RETURN_NO_ACTION_OK;
}

CombatManeuverReturns PlayerbotPaladinAI::DoNextCombatManeuverPVP(Unit* pTarget)
{
    if (GetAI()->CastSpell(HAMMER_OF_JUSTICE))
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
        if (REDEMPTION && GetAI()->CastSpell(REDEMPTION, *target))
        {
            std::string msg = "Resurrecting ";
            msg += target->GetName();
            m_bot->Say(msg, LANG_UNIVERSAL);
            return RETURN_CONTINUE;
        }
        return RETURN_NO_ACTION_ERROR; // not error per se - possibly just OOM
    }

    if (PURIFY > 0 && (GetAI()->GetCombatOrder() & PlayerbotAI::ORDERS_NODISPEL) == 0)
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
                    if (GetAI()->CastSpell(DISPEL, *target))
                        return RETURN_CONTINUE;
                    return RETURN_NO_ACTION_ERROR;
                }
            }
            else if ((1 << holder->GetSpellProto()->Dispel) & dispelMask2)
            {
                if (holder->GetSpellProto()->Dispel == DISPEL_POISON)
                {
                    if (GetAI()->CastSpell(DISPEL, *target))
                        return RETURN_CONTINUE;
                    return RETURN_NO_ACTION_ERROR;
                }
            }
            else if ((1 << holder->GetSpellProto()->Dispel) & dispelMask3 & (DISPEL == CLEANSE))
            {
                if (holder->GetSpellProto()->Dispel == DISPEL_MAGIC)
                {
                    if (GetAI()->CastSpell(DISPEL, *target))
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

    if (hp < 25 && GetAI()->CastSpell(LAY_ON_HANDS, *target))
        return RETURN_CONTINUE;

    // You probably want to save this for tank/healer trouble
    if (hp < 30 && HAND_OF_PROTECTION > 0 && !target->HasAura(FORBEARANCE, EFFECT_INDEX_0)
        && !target->HasAura(HAND_OF_PROTECTION, EFFECT_INDEX_0) && !target->HasAura(DIVINE_PROTECTION, EFFECT_INDEX_0)
        && !target->HasAura(DIVINE_SHIELD, EFFECT_INDEX_0) && (GetTargetJob(target) & (JOB_HEAL | JOB_TANK))
        && GetAI()->CastSpell(HAND_OF_PROTECTION, *target))
        return RETURN_CONTINUE;

    // Isn't this more of a group heal spell?
    if (hp < 40 && GetAI()->CastSpell(FLASH_OF_LIGHT, *target))
        return RETURN_CONTINUE;

    if (hp < 60 && GetAI()->CastSpell(HOLY_SHOCK, *target))
        return RETURN_CONTINUE;

    if (hp < 90 && GetAI()->CastSpell(HOLY_LIGHT, *target))
        return RETURN_CONTINUE;

    return RETURN_NO_ACTION_UNKNOWN;
} // end HealTarget

void PlayerbotPaladinAI::CheckAuras()
{
    if (!GetAI())  return;
    if (!m_bot) return;

    uint32 spec = m_bot->GetSpec();

    // If we have resist orders, adjust accordingly
    if (GetAI()->GetCombatOrder() & PlayerbotAI::ORDERS_RESIST_FROST)
    {
        if (!m_bot->HasAura(FROST_RESISTANCE_AURA) && FROST_RESISTANCE_AURA > 0 && !m_bot->HasAura(FROST_RESISTANCE_AURA))
            GetAI()->CastSpell(FROST_RESISTANCE_AURA);
        return;
    }
    else if (GetAI()->GetCombatOrder() & PlayerbotAI::ORDERS_RESIST_FIRE)
    {
        if (!m_bot->HasAura(FIRE_RESISTANCE_AURA) && FIRE_RESISTANCE_AURA > 0 && !m_bot->HasAura(FIRE_RESISTANCE_AURA))
            GetAI()->CastSpell(FIRE_RESISTANCE_AURA);
        return;
    }
    else if (GetAI()->GetCombatOrder() & PlayerbotAI::ORDERS_RESIST_SHADOW)
    {
        // Shadow protection check is broken, they stack!
        if (!m_bot->HasAura(SHADOW_RESISTANCE_AURA) && SHADOW_RESISTANCE_AURA > 0 && !m_bot->HasAura(SHADOW_RESISTANCE_AURA)) // /*&& !m_bot->HasAura(PRAYER_OF_SHADOW_PROTECTION)*/ /*&& !m_bot->HasAura(PRAYER_OF_SHADOW_PROTECTION)*/
            GetAI()->CastSpell(SHADOW_RESISTANCE_AURA);
        return;
    }

    // If we have no resist orders, adjust aura based on spec
    if (spec == PALADIN_SPEC_HOLY)
    {
        if (CONCENTRATION_AURA > 0 && !m_bot->HasAura(CONCENTRATION_AURA))
            GetAI()->CastSpell(CONCENTRATION_AURA);
        return;
    }
    else if (spec == PALADIN_SPEC_PROTECTION)
    {
        if (DEVOTION_AURA > 0 && !m_bot->HasAura(DEVOTION_AURA))
            GetAI()->CastSpell(DEVOTION_AURA);
        return;
    }
    else if (spec == PALADIN_SPEC_RETRIBUTION)
    {
        if (RETRIBUTION_AURA > 0 && !m_bot->HasAura(RETRIBUTION_AURA))
            GetAI()->CastSpell(RETRIBUTION_AURA);
        return;
    }

}

bool PlayerbotPaladinAI::CheckSeals()
{
    if (!GetAI())  return false;
    if (!m_bot) return false;

    uint32 spec = m_bot->GetSpec();

    switch (spec)
    {
        case PALADIN_SPEC_HOLY:
            if (SEAL_OF_WISDOM > 0 && !m_bot->HasAura(SEAL_OF_WISDOM, EFFECT_INDEX_0) && GetAI()->CastSpell(SEAL_OF_WISDOM, *m_bot))
                return true;
            break;

        case PALADIN_SPEC_PROTECTION:
            if (SEAL_OF_RIGHTEOUSNESS > 0 && !m_bot->HasAura(SEAL_OF_RIGHTEOUSNESS, EFFECT_INDEX_0) && GetAI()->CastSpell(SEAL_OF_RIGHTEOUSNESS, *m_bot))
                return true;
            break;

        case PALADIN_SPEC_RETRIBUTION:
            if (SEAL_OF_COMMAND > 0 && !m_bot->HasAura(SEAL_OF_COMMAND, EFFECT_INDEX_0) && GetAI()->CastSpell(SEAL_OF_COMMAND, *m_bot))
                return true;
            else if (SEAL_OF_RIGHTEOUSNESS > 0 && !m_bot->HasAura(SEAL_OF_RIGHTEOUSNESS, EFFECT_INDEX_0) && !m_bot->HasAura(SEAL_OF_COMMAND, EFFECT_INDEX_0) && GetAI()->CastSpell(SEAL_OF_RIGHTEOUSNESS, *m_bot))
                return true;
            break;
    }
    return false;
}

void PlayerbotPaladinAI::DoNonCombatActions()
{
    if (!GetAI())   return;
    if (!m_bot)  return;

    if (!m_bot->isAlive() || m_bot->IsInDuel()) return;
    
    CheckAuras();

    //Put up RF if tank
    if (GetAI()->GetCombatOrder() & PlayerbotAI::ORDERS_TANK)
        GetAI()->SelfBuff(RIGHTEOUS_FURY);
    //Disable RF if not tank
    else if (m_bot->HasAura(RIGHTEOUS_FURY))
        m_bot->RemoveAurasDueToSpell(RIGHTEOUS_FURY);

    // Revive
    if (HealPlayer(GetResurrectionTarget()) & RETURN_CONTINUE)
        return;

    // Heal
    if (GetAI()->IsHealer())
    {
        if (HealPlayer(GetHealTarget()) & RETURN_CONTINUE)
            return;// RETURN_CONTINUE;
    }
    else
    {
        // Is this desirable? Debatable.
        // TODO: In a group/raid with a healer you'd want this bot to focus on DPS (it's not specced/geared for healing either)
        if (HealPlayer(m_bot) & RETURN_CONTINUE)
            return;// RETURN_CONTINUE;
    }

    // buff group
    if (Buff(&PlayerbotPaladinAI::BuffHelper, 1) & RETURN_CONTINUE) // Paladin's BuffHelper takes care of choosing the specific Blessing so just pass along a non-zero value
        return;

    // hp/mana check
    if (EatDrinkBandage())
        return;
    // GetAI()->TellMaster("DoNonCombatActions() - 10. past EatDrinkBandage()"); // debug
}

/**
 * BuffHelper
 * BuffHelper is a static function, takes an AI, spellId (ignored for paladin) and a target and attempts to buff them as well as their pets as
 * best as possible.
 *
 * Return bool - returns true if a buff took place.
 */
bool PlayerbotPaladinAI::BuffHelper(PlayerbotAI* ai, uint32 spellId, Unit *target)
{
    if (!ai)          return false;
    if (spellId == 0) return false;
    if (!target)      return false;

    PlayerbotPaladinAI* c = (PlayerbotPaladinAI*) ai->GetClassAI();
    uint32 bigSpellId = 0;

    Pet* pet = target->GetPet();
    uint32 petSpellId = 0, petBigSpellId = 0;

    // See which buff is appropriate according to class
    // TODO: take into account other paladins in the group
    switch (target->getClass())
    {
        case CLASS_DRUID:
        case CLASS_SHAMAN:
        case CLASS_PALADIN:
            spellId = c->BLESSING_OF_MIGHT;
            if (!spellId)
            {
                spellId = c->BLESSING_OF_KINGS;
                if (!spellId)
                {
                    spellId = c->BLESSING_OF_WISDOM;
                    if (!spellId)
                    {
                        spellId = c->BLESSING_OF_SANCTUARY;
                        if (!spellId)
                            return false;
                    }
                }
            }
            break;
        case CLASS_DEATH_KNIGHT:
        case CLASS_HUNTER:
        case CLASS_ROGUE:
        case CLASS_WARRIOR:
            spellId = c->BLESSING_OF_MIGHT;
            if (!spellId)
            {
                spellId = c->BLESSING_OF_KINGS;
                if (!spellId)
                {
                    spellId = c->BLESSING_OF_SANCTUARY;
                    if (!spellId)
                        return false;
                }
            }
            break;
        case CLASS_WARLOCK:
        case CLASS_PRIEST:
        case CLASS_MAGE:
            spellId = c->BLESSING_OF_WISDOM;
            if (!spellId)
            {
                spellId = c->BLESSING_OF_KINGS;
                if (!spellId)
                {
                    spellId = c->BLESSING_OF_SANCTUARY;
                    if (!spellId)
                        return false;
                }
            }
            break;
        default:
            // PET
            /** Hunter pet
            if (pet && ai->CanReceiveSpecificSpell(SPELL_BLESSING, pet) && !pet->HasAuraType(SPELL_AURA_MOD_UNATTACKABLE))
            {
                petSpellId = c->BLESSING_OF_MIGHT;
                if (!petSpellId)
                {
                    petSpellId = c->BLESSING_OF_KINGS;
                    if (!petSpellId)
                        petSpellId = c->BLESSING_OF_SANCTUARY;
                }
            }*/
            if (/*pet && ai->CanReceiveSpecificSpell(SPELL_BLESSING, pet) && */!target->HasAuraType(SPELL_AURA_MOD_UNATTACKABLE))
            {
                if (target->GetPowerType() == POWER_MANA)
                    spellId = c->BLESSING_OF_WISDOM;
                else
                    spellId = c->BLESSING_OF_MIGHT;

                if (!spellId)
                {
                    spellId = c->BLESSING_OF_KINGS;
                    if (!spellId)
                        spellId = c->BLESSING_OF_SANCTUARY;
                }
            }
    }

    /*if (petSpellId == c->BLESSING_OF_MIGHT)
        petBigSpellId = c->GREATER_BLESSING_OF_MIGHT;
    else if (petSpellId == c->BLESSING_OF_WISDOM)
        petBigSpellId = c->GREATER_BLESSING_OF_WISDOM;
    else if (petSpellId == c->BLESSING_OF_KINGS)
        petBigSpellId = c->GREATER_BLESSING_OF_KINGS;
    else if (petSpellId == c->BLESSING_OF_SANCTUARY)
        petBigSpellId = c->GREATER_BLESSING_OF_SANCTUARY;*/

    if (spellId == c->BLESSING_OF_MIGHT)
        bigSpellId = c->GREATER_BLESSING_OF_MIGHT;
    else if (spellId == c->BLESSING_OF_WISDOM)
        bigSpellId = c->GREATER_BLESSING_OF_WISDOM;
    else if (spellId == c->BLESSING_OF_KINGS)
        bigSpellId = c->GREATER_BLESSING_OF_KINGS;
    else if (spellId == c->BLESSING_OF_SANCTUARY)
        bigSpellId = c->GREATER_BLESSING_OF_SANCTUARY;

    if (pet && !pet->HasAuraType(SPELL_AURA_MOD_UNATTACKABLE) && ai->HasSpellReagents(petBigSpellId) && ai->Buff(petBigSpellId, pet))
        return true;
    if (ai->HasSpellReagents(bigSpellId) && ai->Buff(bigSpellId, target))
        return true;
    if ((pet && !pet->HasAuraType(SPELL_AURA_MOD_UNATTACKABLE) && ai->Buff(petSpellId, pet)) || ai->Buff(spellId, target))
        return true;
    return false;
}

// Match up with "Pull()" below
bool PlayerbotPaladinAI::CanPull()
{
    if (HAND_OF_RECKONING && m_bot->IsSpellReady(HAND_OF_RECKONING))
        return true;
    if (EXORCISM && m_bot->IsSpellReady(EXORCISM))
        return true;

    return false;
}

// Match up with "CanPull()" above
bool PlayerbotPaladinAI::Pull()
{
    if (HAND_OF_RECKONING && GetAI()->CastSpell(HAND_OF_RECKONING))
        return true;
    if (EXORCISM && GetAI()->CastSpell(EXORCISM))
        return true;

    return false;
}

bool PlayerbotPaladinAI::CastHoTOnTank()
{
    if (!GetAI()) return false;

    if ((PlayerbotAI::ORDERS_HEAL & GetAI()->GetCombatOrder()) == 0) return false;

    // Paladin: Sheath of Light (with talents), Flash of Light (with Infusion of Light talent and only on a target with the Sacred Shield buff),
    //          Holy Shock (with Tier 8 set bonus)
    // None of these are HoTs to cast before pulling (I think)

    return false;
}
