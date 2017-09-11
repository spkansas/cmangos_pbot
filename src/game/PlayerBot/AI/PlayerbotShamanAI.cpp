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

#include "PlayerbotShamanAI.h"
#include "PlayerbotDeathKnightAI.h"
#include "../../Spells/SpellAuras.h"
#include "../../Entities/Totem.h"

class PlayerbotAI;
PlayerbotShamanAI::PlayerbotShamanAI(Player* const master, Player* const bot, PlayerbotAI* const ai) : PlayerbotClassAI(master, bot, ai)
{
    // restoration
    CHAIN_HEAL               = GetAI()->initSpell(CHAIN_HEAL_1);
    HEALING_WAVE             = GetAI()->initSpell(HEALING_WAVE_1);
    LESSER_HEALING_WAVE      = GetAI()->initSpell(LESSER_HEALING_WAVE_1);
    RIPTIDE                  = GetAI()->initSpell(RIPTIDE_1);
    ANCESTRAL_SPIRIT         = GetAI()->initSpell(ANCESTRAL_SPIRIT_1);
    EARTH_SHIELD             = GetAI()->initSpell(EARTH_SHIELD_1);
    WATER_SHIELD             = GetAI()->initSpell(WATER_SHIELD_1);
    EARTHLIVING_WEAPON       = GetAI()->initSpell(EARTHLIVING_WEAPON_1);
    TREMOR_TOTEM             = GetAI()->initSpell(TREMOR_TOTEM_1); // totems
    HEALING_STREAM_TOTEM     = GetAI()->initSpell(HEALING_STREAM_TOTEM_1);
    MANA_SPRING_TOTEM        = GetAI()->initSpell(MANA_SPRING_TOTEM_1);
    MANA_TIDE_TOTEM          = GetAI()->initSpell(MANA_TIDE_TOTEM_1);
    CURE_TOXINS              = GetAI()->initSpell(CURE_TOXINS_1);
    CLEANSE_SPIRIT           = GetAI()->initSpell(CLEANSE_SPIRIT_1);
    NATURES_SWIFTNESS_SHAMAN = GetAI()->initSpell(NATURES_SWIFTNESS_SHAMAN_1);
    TIDAL_FORCE              = GetAI()->initSpell(TIDAL_FORCE_1);
    // enhancement
    FOCUSED                  = 0; // Focused what?
    STORMSTRIKE              = GetAI()->initSpell(STORMSTRIKE_1);
    LAVA_LASH                = GetAI()->initSpell(LAVA_LASH_1);
    SHAMANISTIC_RAGE         = GetAI()->initSpell(SHAMANISTIC_RAGE_1);
    BLOODLUST                = GetAI()->initSpell(BLOODLUST_1);
    HEROISM                  = GetAI()->initSpell(HEROISM_1);
    FERAL_SPIRIT             = GetAI()->initSpell(FERAL_SPIRIT_1);
    LIGHTNING_SHIELD         = GetAI()->initSpell(LIGHTNING_SHIELD_1);
    ROCKBITER_WEAPON         = GetAI()->initSpell(ROCKBITER_WEAPON_1);
    FLAMETONGUE_WEAPON       = GetAI()->initSpell(FLAMETONGUE_WEAPON_1);
    FROSTBRAND_WEAPON        = GetAI()->initSpell(FROSTBRAND_WEAPON_1);
    WINDFURY_WEAPON          = GetAI()->initSpell(WINDFURY_WEAPON_1);
    STONESKIN_TOTEM          = GetAI()->initSpell(STONESKIN_TOTEM_1); // totems
    STRENGTH_OF_EARTH_TOTEM  = GetAI()->initSpell(STRENGTH_OF_EARTH_TOTEM_1);
    FROST_RESISTANCE_TOTEM   = GetAI()->initSpell(FROST_RESISTANCE_TOTEM_1);
    FLAMETONGUE_TOTEM        = GetAI()->initSpell(FLAMETONGUE_TOTEM_1);
    FIRE_RESISTANCE_TOTEM    = GetAI()->initSpell(FIRE_RESISTANCE_TOTEM_1);
    GROUNDING_TOTEM          = GetAI()->initSpell(GROUNDING_TOTEM_1);
    NATURE_RESISTANCE_TOTEM  = GetAI()->initSpell(NATURE_RESISTANCE_TOTEM_1);
    WIND_FURY_TOTEM          = GetAI()->initSpell(WINDFURY_TOTEM_1);
    STONESKIN_TOTEM          = GetAI()->initSpell(STONESKIN_TOTEM_1);
    WRATH_OF_AIR_TOTEM       = GetAI()->initSpell(WRATH_OF_AIR_TOTEM_1);
    EARTH_ELEMENTAL_TOTEM    = GetAI()->initSpell(EARTH_ELEMENTAL_TOTEM_1);
    MAELSTROM_WEAPON         = GetAI()->initSpell(MAELSTROM_WEAPON_1);
    // elemental
    LIGHTNING_BOLT           = GetAI()->initSpell(LIGHTNING_BOLT_1);
    EARTH_SHOCK              = GetAI()->initSpell(EARTH_SHOCK_1);
    FLAME_SHOCK              = GetAI()->initSpell(FLAME_SHOCK_1);
    PURGE                    = GetAI()->initSpell(PURGE_1);
    WIND_SHOCK               = 0; //NPC spell
    FROST_SHOCK              = GetAI()->initSpell(FROST_SHOCK_1);
    CHAIN_LIGHTNING          = GetAI()->initSpell(CHAIN_LIGHTNING_1);
    LAVA_BURST               = GetAI()->initSpell(LAVA_BURST_1);
    HEX                      = GetAI()->initSpell(HEX_1);
    STONECLAW_TOTEM          = GetAI()->initSpell(STONECLAW_TOTEM_1); // totems
    SEARING_TOTEM            = GetAI()->initSpell(SEARING_TOTEM_1);
    FIRE_NOVA_TOTEM          = 0; // NPC only spell, check FIRE_NOVA_1
    MAGMA_TOTEM              = GetAI()->initSpell(MAGMA_TOTEM_1);
    EARTHBIND_TOTEM          = GetAI()->initSpell(EARTHBIND_TOTEM_1);
    TOTEM_OF_WRATH           = GetAI()->initSpell(TOTEM_OF_WRATH_1);
    FIRE_ELEMENTAL_TOTEM     = GetAI()->initSpell(FIRE_ELEMENTAL_TOTEM_1);
    ELEMENTAL_MASTERY        = GetAI()->initSpell(ELEMENTAL_MASTERY_1);
    THUNDERSTORM             = GetAI()->initSpell(THUNDERSTORM_1);

    RECENTLY_BANDAGED        = 11196; // first aid check

    // racial
    GIFT_OF_THE_NAARU        = GetAI()->initSpell(GIFT_OF_THE_NAARU_SHAMAN); // draenei
    BLOOD_FURY               = GetAI()->initSpell(BLOOD_FURY_SHAMAN); // orc
    WAR_STOMP                = GetAI()->initSpell(WAR_STOMP_ALL); // tauren
    BERSERKING               = GetAI()->initSpell(BERSERKING_ALL); // troll

    // totem buffs
    STRENGTH_OF_EARTH_EFFECT    = GetAI()->initSpell(STRENGTH_OF_EARTH_EFFECT_1);
    FLAMETONGUE_EFFECT          = GetAI()->initSpell(FLAMETONGUE_EFFECT_1);
    MAGMA_TOTEM_EFFECT          = GetAI()->initSpell(MAGMA_TOTEM_EFFECT_1);
    STONECLAW_EFFECT            = GetAI()->initSpell(STONECLAW_EFFECT_1);
    FIRE_RESISTANCE_EFFECT      = GetAI()->initSpell(FIRE_RESISTANCE_EFFECT_1);
    FROST_RESISTANCE_EFFECT     = GetAI()->initSpell(FROST_RESISTANCE_EFFECT_1);
    GROUDNING_EFFECT            = GetAI()->initSpell(GROUDNING_EFFECT_1);
    NATURE_RESISTANCE_EFFECT    = GetAI()->initSpell(NATURE_RESISTANCE_EFFECT_1);
    STONESKIN_EFFECT            = GetAI()->initSpell(STONESKIN_EFFECT_1);
    WINDFURY_EFFECT             = GetAI()->initSpell(WINDFURY_EFFECT_1);
    WRATH_OF_AIR_EFFECT         = GetAI()->initSpell(WRATH_OF_AIR_EFFECT_1);
    CLEANSING_TOTEM_EFFECT      = GetAI()->initSpell(CLEANSING_TOTEM_EFFECT_1);
    HEALING_STREAM_EFFECT       = GetAI()->initSpell(HEALING_STREAM_EFFECT_1);
    MANA_SPRING_EFFECT          = GetAI()->initSpell(MANA_SPRING_EFFECT_1);
    TREMOR_TOTEM_EFFECT         = GetAI()->initSpell(TREMOR_TOTEM_EFFECT_1);
    TOTEM_OF_WRATH_EFFECT       = GetAI()->initSpell(TOTEM_OF_WRATH_EFFECT_1);
    STONECLAW_EFFECT            = GetAI()->initSpell(STONECLAW_EFFECT_1);
    EARTHBIND_EFFECT            = GetAI()->initSpell(EARTHBIND_EFFECT_1);

    // Buffs that don't stack with totems
    IMPROVED_ICY_TALONS     = GetAI()->initSpell(IMPROVED_ICY_TALONS_1);
    HORN_OF_WINTER          = GetAI()->initSpell(HORN_OF_WINTER_1);
}

PlayerbotShamanAI::~PlayerbotShamanAI() {}

CombatManeuverReturns PlayerbotShamanAI::DoNextManeuver_Heal_ClassSetup(Unit* pTarget)
{
	// No healing setup needed, so pass success
	return RETURN_CONTINUE;
}

CombatManeuverReturns PlayerbotShamanAI::DoFirstCombatManeuverPVE(Unit* /*pTarget*/)
{
    return RETURN_NO_ACTION_OK;
}

CombatManeuverReturns PlayerbotShamanAI::DoFirstCombatManeuverPVP(Unit* /*pTarget*/)
{
    return RETURN_NO_ACTION_OK;
}

CombatManeuverReturns PlayerbotShamanAI::DoNextCombatManeuverPVE(Unit *pTarget)
{
    if (!GetAI())  return RETURN_NO_ACTION_ERROR;
    if (!m_bot) return RETURN_NO_ACTION_ERROR;

    uint32 spec = m_bot->GetSpec();

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
    else
    {
        // Is this desirable? Debatable.
        // TODO: In a group/raid with a healer you'd want this bot to focus on DPS (it's not specced/geared for healing either)
        if (HealPlayer(m_bot) & RETURN_CONTINUE)
            return RETURN_CONTINUE;
    }

    // Damage Spells
    DropTotems();
    CheckShields();
    UseCooldowns();
    switch (spec)
    {
        case SHAMAN_SPEC_ENHANCEMENT:
            if (STORMSTRIKE > 0 && (m_bot->IsSpellReady(STORMSTRIKE)) && GetAI()->CastSpell(STORMSTRIKE, *pTarget))
                return RETURN_CONTINUE;
            if (FLAME_SHOCK > 0 && (!pTarget->HasAura(FLAME_SHOCK)) && GetAI()->CastSpell(FLAME_SHOCK, *pTarget))
                return RETURN_CONTINUE;
            if (EARTH_SHOCK > 0 && (m_bot->IsSpellReady(EARTH_SHOCK)) && GetAI()->CastSpell(EARTH_SHOCK, *pTarget))
                return RETURN_CONTINUE;
            if (LAVA_LASH > 0 && (m_bot->IsSpellReady(LAVA_LASH)) && GetAI()->CastSpell(LAVA_LASH, *pTarget))
                return RETURN_CONTINUE;
            if (MAELSTROM_WEAPON > 0 && LIGHTNING_BOLT > 0 && m_bot->HasAura(MAELSTROM_WEAPON) && GetAI()->CastSpell(LIGHTNING_BOLT, *pTarget))
                return RETURN_CONTINUE;
            /*if (FOCUSED > 0 && GetAI()->CastSpell(FOCUSED, *pTarget))
                return RETURN_CONTINUE;*/
            break;

        case SHAMAN_SPEC_RESTORATION:
            // fall through to elemental

        case SHAMAN_SPEC_ELEMENTAL:
            if (FLAME_SHOCK > 0 && (!pTarget->HasAura(FLAME_SHOCK)) && GetAI()->CastSpell(FLAME_SHOCK, *pTarget))
                return RETURN_CONTINUE;
            if (LAVA_BURST > 0 && (pTarget->HasAura(FLAME_SHOCK)) && (m_bot->IsSpellReady(LAVA_BURST)) && GetAI()->CastSpell(LAVA_BURST, *pTarget))
                return RETURN_CONTINUE;
            if (LIGHTNING_BOLT > 0 && GetAI()->CastSpell(LIGHTNING_BOLT, *pTarget))
                return RETURN_CONTINUE;
            /*if (PURGE > 0 && GetAI()->CastSpell(PURGE, *pTarget))
                return RETURN_CONTINUE;*/
            /*if (WIND_SHOCK > 0 && GetAI()->CastSpell(WIND_SHOCK, *pTarget))
                return RETURN_CONTINUE;*/
            /*if (FROST_SHOCK > 0 && !pTarget->HasAura(FROST_SHOCK, EFFECT_INDEX_0) && GetAI()->CastSpell(FROST_SHOCK, *pTarget))
                return RETURN_CONTINUE;*/
            /*if (CHAIN_LIGHTNING > 0 && GetAI()->CastSpell(CHAIN_LIGHTNING, *pTarget))
                return RETURN_CONTINUE;*/
            /*if (HEX > 0 && !pTarget->HasAura(HEX, EFFECT_INDEX_0) && GetAI()->CastSpell(HEX))
                return RETURN_CONTINUE;*/
    }

    return RETURN_NO_ACTION_OK;
} // end DoNextCombatManeuver

CombatManeuverReturns PlayerbotShamanAI::DoNextCombatManeuverPVP(Unit* pTarget)
{
    DropTotems();
    CheckShields();
    UseCooldowns();

    Player* healTarget = (GetAI()->GetScenarioType() == PlayerbotAI::SCENARIO_PVP_DUEL) ? GetHealTarget() : m_bot;
    if (HealPlayer(healTarget) & (RETURN_NO_ACTION_OK | RETURN_CONTINUE))
        return RETURN_CONTINUE;
    if (GetAI()->CastSpell(LIGHTNING_BOLT))
        return RETURN_CONTINUE;

    return DoNextCombatManeuverPVE(pTarget); // TODO: bad idea perhaps, but better than the alternative
}

CombatManeuverReturns PlayerbotShamanAI::HealPlayer(Player* target)
{
    CombatManeuverReturns r = PlayerbotClassAI::HealPlayer(target);
    if (r != RETURN_NO_ACTION_OK)
        return r;

    if (!target->isAlive())
    {
        if (ANCESTRAL_SPIRIT && GetAI()->CastSpell(ANCESTRAL_SPIRIT, *target))
        {
            std::string msg = "Resurrecting ";
            msg += target->GetName();
            m_bot->Say(msg, LANG_UNIVERSAL);
            return RETURN_CONTINUE;
        }
        return RETURN_NO_ACTION_ERROR; // not error per se - possibly just OOM
    }

    // Dispel if necessary
    if (CURE_TOXINS > 0 && (GetAI()->GetCombatOrder() & PlayerbotAI::ORDERS_NODISPEL) == 0)
    {
        uint32 DISPEL = CLEANSE_SPIRIT > 0 ? CLEANSE_SPIRIT : CURE_TOXINS;
        uint32 dispelMask  = GetDispellMask(DISPEL_POISON);
        uint32 dispelMask2  = GetDispellMask(DISPEL_DISEASE);
        uint32 dispelMask3  = GetDispellMask(DISPEL_CURSE);
        Unit::SpellAuraHolderMap const& auras = target->GetSpellAuraHolderMap();
        for (Unit::SpellAuraHolderMap::const_iterator itr = auras.begin(); itr != auras.end(); ++itr)
        {
            SpellAuraHolder *holder = itr->second;
            if ((1 << holder->GetSpellProto()->Dispel) & dispelMask)
            {
                if (holder->GetSpellProto()->Dispel == DISPEL_POISON)
                {
                    if (GetAI()->CastSpell(DISPEL, *target))
                        return RETURN_CONTINUE;
                    return RETURN_NO_ACTION_ERROR;
                }
            }
            else if ((1 << holder->GetSpellProto()->Dispel) & dispelMask2)
            {
                if (holder->GetSpellProto()->Dispel == DISPEL_DISEASE)
                {
                    if (GetAI()->CastSpell(DISPEL, *target))
                        return RETURN_CONTINUE;
                    return RETURN_NO_ACTION_ERROR;
                }
            }
            else if ((1 << holder->GetSpellProto()->Dispel) & dispelMask3 & (DISPEL == CLEANSE_SPIRIT))
            {
                if (holder->GetSpellProto()->Dispel == DISPEL_CURSE)
                {
                    if (GetAI()->CastSpell(DISPEL, *target))
                        return RETURN_CONTINUE;
                    return RETURN_NO_ACTION_ERROR;
                }
            }
        }
    }

    // Everyone is healthy enough, return OK. MUST correlate to highest value below (should be last HP check)
    if (target->GetHealthPercent() >= 80)
        return RETURN_NO_ACTION_OK;

    // Technically the best rotation is CHAIN + LHW + LHW, or RIPTIDE + LHW + LHW (proc Tidal Waves then two short LHW), subbing in HW for trouble (bad mana efficiency)
    if (target->GetHealthPercent() < 30 && HEALING_WAVE > 0 && GetAI()->CastSpell(HEALING_WAVE, *target))
        return RETURN_CONTINUE;
    if (target->GetHealthPercent() < 50 && LESSER_HEALING_WAVE > 0 && GetAI()->CastSpell(LESSER_HEALING_WAVE, *target))
        return RETURN_CONTINUE;
    if (target->GetHealthPercent() < 60 && RIPTIDE > 0 && !target->HasAura(RIPTIDE, EFFECT_INDEX_0) && GetAI()->CastSpell(RIPTIDE, *target))
        return RETURN_CONTINUE;
    if (target->GetHealthPercent() < 80 && CHAIN_HEAL > 0 && GetAI()->CastSpell(CHAIN_HEAL, *target))
        return RETURN_CONTINUE;

    return RETURN_NO_ACTION_UNKNOWN;
} // end HealTarget

void PlayerbotShamanAI::DropTotems()
{
    if (!GetAI())  return;
    if (!m_bot) return;

    uint32 spec = m_bot->GetSpec();

    Totem* earth = m_bot->GetTotem(TOTEM_SLOT_EARTH);
    Totem* fire = m_bot->GetTotem(TOTEM_SLOT_FIRE);
    Totem* water = m_bot->GetTotem(TOTEM_SLOT_WATER);
    Totem* air = m_bot->GetTotem(TOTEM_SLOT_AIR);

    // Earth Totems
    if ((earth == nullptr) || (m_bot->GetDistance(earth) > 30))
    {
        if (STRENGTH_OF_EARTH_TOTEM > 0 && GetAI()->CastSpell(STRENGTH_OF_EARTH_TOTEM))
            return;
    }

    // Fire Totems
    if ((fire == nullptr) || (m_bot->GetDistance(fire) > 30))
    {
        if (GetAI()->GetCombatOrder() & PlayerbotAI::ORDERS_RESIST_FROST && FROST_RESISTANCE_TOTEM > 0 && GetAI()->CastSpell(FROST_RESISTANCE_TOTEM))
            return;
        else if (spec == SHAMAN_SPEC_ELEMENTAL && TOTEM_OF_WRATH > 0 && GetAI()->CastSpell(TOTEM_OF_WRATH))
            return;
        // If the spec didn't take totem of wrath, use flametongue
        else if ((spec != SHAMAN_SPEC_ELEMENTAL || TOTEM_OF_WRATH == 0) && FLAMETONGUE_TOTEM > 0 && GetAI()->CastSpell(FLAMETONGUE_TOTEM))
            return;
    }

    // Air totems
    if ((air == nullptr) || (m_bot->GetDistance(air) > 30))
    {
        if (GetAI()->GetCombatOrder() & PlayerbotAI::ORDERS_RESIST_NATURE && NATURE_RESISTANCE_TOTEM > 0 && GetAI()->CastSpell(NATURE_RESISTANCE_TOTEM))
            return;
        else if (spec == SHAMAN_SPEC_ENHANCEMENT)
        {
            if (WIND_FURY_TOTEM > 0 /*&& !m_bot->HasAura(IMPROVED_ICY_TALONS)*/ && GetAI()->CastSpell(WIND_FURY_TOTEM))
            return;
        }
        else
        {
            if (WRATH_OF_AIR_TOTEM > 0 && GetAI()->CastSpell(WRATH_OF_AIR_TOTEM))
            return;
        }
    }

    // Water Totems
    if ((water == nullptr) || (m_bot->GetDistance(water) > 30))
    {
        if (GetAI()->GetCombatOrder() & PlayerbotAI::ORDERS_RESIST_FIRE && FIRE_RESISTANCE_TOTEM > 0 && GetAI()->CastSpell(FIRE_RESISTANCE_TOTEM))
            return;
        else if (MANA_SPRING_TOTEM > 0 && GetAI()->CastSpell(MANA_SPRING_TOTEM))
            return;
    }

    /*if (EARTH_ELEMENTAL_TOTEM > 0 && GetAI()->CastSpell(EARTH_ELEMENTAL_TOTEM))
        return RETURN_CONTINUE;*/
    /*if (EARTHBIND_TOTEM > 0 && !pTarget->HasAura(EARTHBIND_TOTEM, EFFECT_INDEX_0) && !m_bot->HasAura(STRENGTH_OF_EARTH_TOTEM, EFFECT_INDEX_0) && GetAI()->CastSpell(EARTHBIND_TOTEM))
        return RETURN_CONTINUE;*/
    /*if (FIRE_ELEMENTAL_TOTEM > 0 && GetAI()->CastSpell(FIRE_ELEMENTAL_TOTEM))
        return RETURN_CONTINUE;*/
    /*if (FIRE_NOVA_TOTEM > 0 && GetAI()->CastSpell(FIRE_NOVA_TOTEM))
        return RETURN_CONTINUE;*/
    /*if (GROUNDING_TOTEM > 0 && !m_bot->HasAura(GROUNDING_TOTEM, EFFECT_INDEX_0) && !m_bot->HasAura(WRATH_OF_AIR_TOTEM, EFFECT_INDEX_0) && !m_bot->HasAura(WIND_FURY_TOTEM, EFFECT_INDEX_0) && GetAI()->CastSpell(GROUNDING_TOTEM))
        return RETURN_CONTINUE;*/
    /*if (HEALING_STREAM_TOTEM > 0 && GetAI()->GetHealthPercent() < 50 && !m_bot->HasAura(HEALING_STREAM_TOTEM, EFFECT_INDEX_0) && !m_bot->HasAura(MANA_SPRING_TOTEM, EFFECT_INDEX_0) && GetAI()->CastSpell(HEALING_STREAM_TOTEM))
        return RETURN_CONTINUE;*/
    /*if (MAGMA_TOTEM > 0 && (!m_bot->HasAura(TOTEM_OF_WRATH, EFFECT_INDEX_0)) && GetAI()->CastSpell(MAGMA_TOTEM))
        return RETURN_CONTINUE;*/
    /*if (SEARING_TOTEM > 0 && !pTarget->HasAura(SEARING_TOTEM, EFFECT_INDEX_0) && !m_bot->HasAura(TOTEM_OF_WRATH, EFFECT_INDEX_0) && GetAI()->CastSpell(SEARING_TOTEM))
        return RETURN_CONTINUE;*/
    /*if (STONECLAW_TOTEM > 0 && GetAI()->GetHealthPercent() < 51 && !pTarget->HasAura(STONECLAW_TOTEM, EFFECT_INDEX_0) && !pTarget->HasAura(EARTHBIND_TOTEM, EFFECT_INDEX_0) && !m_bot->HasAura(STRENGTH_OF_EARTH_TOTEM, EFFECT_INDEX_0) && GetAI()->CastSpell(STONECLAW_TOTEM))
        return RETURN_CONTINUE;*/
    /*if (STONESKIN_TOTEM > 0 && !m_bot->HasAura(STONESKIN_TOTEM, EFFECT_INDEX_0) && !m_bot->HasAura(STRENGTH_OF_EARTH_TOTEM, EFFECT_INDEX_0) && GetAI()->CastSpell(STONESKIN_TOTEM))
        return RETURN_CONTINUE;*/
    /*if (TREMOR_TOTEM > 0 && !m_bot->HasAura(STRENGTH_OF_EARTH_TOTEM, EFFECT_INDEX_0) && GetAI()->CastSpell(TREMOR_TOTEM))
        return RETURN_CONTINUE;*/
}

void PlayerbotShamanAI::CheckShields()
{
    if (!GetAI())  return;
    if (!m_bot) return;

    uint32 spec = m_bot->GetSpec();

    if (spec == SHAMAN_SPEC_ENHANCEMENT && LIGHTNING_SHIELD > 0 && !m_bot->HasAura(LIGHTNING_SHIELD, EFFECT_INDEX_0))
        GetAI()->CastSpell(LIGHTNING_SHIELD, *m_bot);
    else if ((spec == SHAMAN_SPEC_ELEMENTAL || spec == SHAMAN_SPEC_RESTORATION) && WATER_SHIELD > 0 && !m_bot->HasAura(WATER_SHIELD, EFFECT_INDEX_0))
        GetAI()->CastSpell(WATER_SHIELD, *m_bot);
    if (EARTH_SHIELD > 0 && !GetMaster()->HasAura(EARTH_SHIELD, EFFECT_INDEX_0))
        GetAI()->CastSpell(EARTH_SHIELD, *(GetMaster()));
}

void PlayerbotShamanAI::UseCooldowns()
{
    if (!GetAI())  return;
    if (!m_bot) return;

    uint32 spec = m_bot->GetSpec();

    if (BLOODLUST > 0 && (!GetMaster()->HasAura(BLOODLUST, EFFECT_INDEX_0)) && GetAI()->CastSpell(BLOODLUST))
        return;
    else if (HEROISM > 0 && (!GetMaster()->HasAura(HEROISM, EFFECT_INDEX_0)) && GetAI()->CastSpell(HEROISM))
        return;

    switch (spec)
    {
        case SHAMAN_SPEC_ENHANCEMENT:
            if (SHAMANISTIC_RAGE > 0 && GetAI()->CastSpell(SHAMANISTIC_RAGE, *m_bot))
                return;
            else if (FERAL_SPIRIT > 0 && GetAI()->CastSpell(FERAL_SPIRIT))
                return;
            break;

        case SHAMAN_SPEC_ELEMENTAL:
            if (ELEMENTAL_MASTERY > 0 && GetAI()->CastSpell(ELEMENTAL_MASTERY, *m_bot))
                return;
            else if (THUNDERSTORM > 0 && GetAI()->CastSpell(THUNDERSTORM, *m_bot))
                return;
            break;

        case SHAMAN_SPEC_RESTORATION:
            if (MANA_TIDE_TOTEM > 0 && GetAI()->GetManaPercent() < 50 && GetAI()->CastSpell(MANA_TIDE_TOTEM))
                return;
            else if (NATURES_SWIFTNESS_SHAMAN > 0 && GetAI()->CastSpell(NATURES_SWIFTNESS_SHAMAN))
                return;
            else if (TIDAL_FORCE > 0 && GetAI()->CastSpell(TIDAL_FORCE))
                return;

        default:
            break;
    }
}

void PlayerbotShamanAI::DoNonCombatActions()
{
    if (!GetAI())   return;
    if (!m_bot)  return;

    if (!m_bot->isAlive() || m_bot->IsInDuel()) return;

    uint32 spec = m_bot->GetSpec();

    CheckShields();
/*
       // buff myself weapon
       if (ROCKBITER_WEAPON > 0)
            (!m_bot->HasAura(ROCKBITER_WEAPON, EFFECT_INDEX_0) && !m_bot->HasAura(EARTHLIVING_WEAPON, EFFECT_INDEX_0) && !m_bot->HasAura(WINDFURY_WEAPON, EFFECT_INDEX_0) && !m_bot->HasAura(FLAMETONGUE_WEAPON, EFFECT_INDEX_0) && !m_bot->HasAura(FROSTBRAND_WEAPON, EFFECT_INDEX_0) && GetAI()->CastSpell(ROCKBITER_WEAPON,*m_bot) );
       else if (EARTHLIVING_WEAPON > 0)
            (!m_bot->HasAura(EARTHLIVING_WEAPON, EFFECT_INDEX_0) && !m_bot->HasAura(EARTHLIVING_WEAPON, EFFECT_INDEX_0) && !m_bot->HasAura(FLAMETONGUE_WEAPON, EFFECT_INDEX_0) && !m_bot->HasAura(FROSTBRAND_WEAPON, EFFECT_INDEX_0) && !m_bot->HasAura(ROCKBITER_WEAPON, EFFECT_INDEX_0) && GetAI()->CastSpell(WINDFURY_WEAPON,*m_bot) );
       else if (WINDFURY_WEAPON > 0)
            (!m_bot->HasAura(WINDFURY_WEAPON, EFFECT_INDEX_0) && !m_bot->HasAura(EARTHLIVING_WEAPON, EFFECT_INDEX_0) && !m_bot->HasAura(FLAMETONGUE_WEAPON, EFFECT_INDEX_0) && !m_bot->HasAura(FROSTBRAND_WEAPON, EFFECT_INDEX_0) && !m_bot->HasAura(ROCKBITER_WEAPON, EFFECT_INDEX_0) && GetAI()->CastSpell(WINDFURY_WEAPON,*m_bot) );
       else if (FLAMETONGUE_WEAPON > 0)
            (!m_bot->HasAura(FLAMETONGUE_WEAPON, EFFECT_INDEX_0) && !m_bot->HasAura(EARTHLIVING_WEAPON, EFFECT_INDEX_0) && !m_bot->HasAura(WINDFURY_WEAPON, EFFECT_INDEX_0) && !m_bot->HasAura(FROSTBRAND_WEAPON, EFFECT_INDEX_0) && !m_bot->HasAura(ROCKBITER_WEAPON, EFFECT_INDEX_0) && GetAI()->CastSpell(FLAMETONGUE_WEAPON,*m_bot) );
       else if (FROSTBRAND_WEAPON > 0)
            (!m_bot->HasAura(FROSTBRAND_WEAPON, EFFECT_INDEX_0) && !m_bot->HasAura(EARTHLIVING_WEAPON, EFFECT_INDEX_0) && !m_bot->HasAura(WINDFURY_WEAPON, EFFECT_INDEX_0) && !m_bot->HasAura(FLAMETONGUE_WEAPON, EFFECT_INDEX_0) && !m_bot->HasAura(ROCKBITER_WEAPON, EFFECT_INDEX_0) && GetAI()->CastSpell(FROSTBRAND_WEAPON,*m_bot) );
 */
    // Mainhand
    Item* weapon;
    weapon = m_bot->GetItemByPos(EQUIPMENT_SLOT_MAINHAND);
    if (weapon && (weapon->GetEnchantmentId(TEMP_ENCHANTMENT_SLOT) == 0) && spec == SHAMAN_SPEC_RESTORATION)
        GetAI()->CastSpell(EARTHLIVING_WEAPON, *m_bot);
    else if (weapon && (weapon->GetEnchantmentId(TEMP_ENCHANTMENT_SLOT) == 0) && spec == SHAMAN_SPEC_ELEMENTAL)
        GetAI()->CastSpell(FLAMETONGUE_WEAPON, *m_bot);
    else if (weapon && (weapon->GetEnchantmentId(TEMP_ENCHANTMENT_SLOT) == 0) && spec == SHAMAN_SPEC_ENHANCEMENT)
        GetAI()->CastSpell(WINDFURY_WEAPON, *m_bot);

    //Offhand
    weapon = m_bot->GetItemByPos(EQUIPMENT_SLOT_OFFHAND);
    if (weapon && (weapon->GetEnchantmentId(TEMP_ENCHANTMENT_SLOT) == 0) && spec == SHAMAN_SPEC_ENHANCEMENT)
        GetAI()->CastSpell(FLAMETONGUE_WEAPON, *m_bot);

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

    // hp/mana check
    if (EatDrinkBandage())
        return;
} // end DoNonCombatActions

bool PlayerbotShamanAI::CastHoTOnTank()
{
    if (!GetAI()) return false;

    if ((PlayerbotAI::ORDERS_HEAL & GetAI()->GetCombatOrder()) == 0) return false;

    // Shaman: Healing Stream Totem, Earthliving Weapon, and Riptide (with talents)
    // None of these are cast before Pulling

    return false;
}
