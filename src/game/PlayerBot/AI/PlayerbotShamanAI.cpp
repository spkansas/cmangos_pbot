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
    // TODO: fail on non-postivie return
    PlayerbotClassAI_ClassAIInit();
}


PlayerbotShamanAI::~PlayerbotShamanAI() 
{
}


bool PlayerbotShamanAI::PlayerbotClassAI_ClassAIInit(void)
{
    // restoration
    CHAIN_HEAL               = m_botdata->GetAI()->initSpell(CHAIN_HEAL_1);
    HEALING_WAVE             = m_botdata->GetAI()->initSpell(HEALING_WAVE_1);
    LESSER_HEALING_WAVE      = m_botdata->GetAI()->initSpell(LESSER_HEALING_WAVE_1);
    RIPTIDE                  = m_botdata->GetAI()->initSpell(RIPTIDE_1);
    ANCESTRAL_SPIRIT         = m_botdata->GetAI()->initSpell(ANCESTRAL_SPIRIT_1);
    EARTH_SHIELD             = m_botdata->GetAI()->initSpell(EARTH_SHIELD_1);
    WATER_SHIELD             = m_botdata->GetAI()->initSpell(WATER_SHIELD_1);
    EARTHLIVING_WEAPON       = m_botdata->GetAI()->initSpell(EARTHLIVING_WEAPON_1);
    TREMOR_TOTEM             = m_botdata->GetAI()->initSpell(TREMOR_TOTEM_1); // totems
    HEALING_STREAM_TOTEM     = m_botdata->GetAI()->initSpell(HEALING_STREAM_TOTEM_1);
    MANA_SPRING_TOTEM        = m_botdata->GetAI()->initSpell(MANA_SPRING_TOTEM_1);
    MANA_TIDE_TOTEM          = m_botdata->GetAI()->initSpell(MANA_TIDE_TOTEM_1);
    CURE_TOXINS              = m_botdata->GetAI()->initSpell(CURE_TOXINS_1);
    CLEANSE_SPIRIT           = m_botdata->GetAI()->initSpell(CLEANSE_SPIRIT_1);
    NATURES_SWIFTNESS_SHAMAN = m_botdata->GetAI()->initSpell(NATURES_SWIFTNESS_SHAMAN_1);
    TIDAL_FORCE              = m_botdata->GetAI()->initSpell(TIDAL_FORCE_1);
    // enhancement
    FOCUSED                  = 0; // Focused what?
    STORMSTRIKE              = m_botdata->GetAI()->initSpell(STORMSTRIKE_1);
    LAVA_LASH                = m_botdata->GetAI()->initSpell(LAVA_LASH_1);
    SHAMANISTIC_RAGE         = m_botdata->GetAI()->initSpell(SHAMANISTIC_RAGE_1);
    BLOODLUST                = m_botdata->GetAI()->initSpell(BLOODLUST_1);
    HEROISM                  = m_botdata->GetAI()->initSpell(HEROISM_1);
    FERAL_SPIRIT             = m_botdata->GetAI()->initSpell(FERAL_SPIRIT_1);
    LIGHTNING_SHIELD         = m_botdata->GetAI()->initSpell(LIGHTNING_SHIELD_1);
    ROCKBITER_WEAPON         = m_botdata->GetAI()->initSpell(ROCKBITER_WEAPON_1);
    FLAMETONGUE_WEAPON       = m_botdata->GetAI()->initSpell(FLAMETONGUE_WEAPON_1);
    FROSTBRAND_WEAPON        = m_botdata->GetAI()->initSpell(FROSTBRAND_WEAPON_1);
    WINDFURY_WEAPON          = m_botdata->GetAI()->initSpell(WINDFURY_WEAPON_1);
    STONESKIN_TOTEM          = m_botdata->GetAI()->initSpell(STONESKIN_TOTEM_1); // totems
    STRENGTH_OF_EARTH_TOTEM  = m_botdata->GetAI()->initSpell(STRENGTH_OF_EARTH_TOTEM_1);
    FROST_RESISTANCE_TOTEM   = m_botdata->GetAI()->initSpell(FROST_RESISTANCE_TOTEM_1);
    FLAMETONGUE_TOTEM        = m_botdata->GetAI()->initSpell(FLAMETONGUE_TOTEM_1);
    FIRE_RESISTANCE_TOTEM    = m_botdata->GetAI()->initSpell(FIRE_RESISTANCE_TOTEM_1);
    GROUNDING_TOTEM          = m_botdata->GetAI()->initSpell(GROUNDING_TOTEM_1);
    NATURE_RESISTANCE_TOTEM  = m_botdata->GetAI()->initSpell(NATURE_RESISTANCE_TOTEM_1);
    WIND_FURY_TOTEM          = m_botdata->GetAI()->initSpell(WINDFURY_TOTEM_1);
    STONESKIN_TOTEM          = m_botdata->GetAI()->initSpell(STONESKIN_TOTEM_1);
    WRATH_OF_AIR_TOTEM       = m_botdata->GetAI()->initSpell(WRATH_OF_AIR_TOTEM_1);
    EARTH_ELEMENTAL_TOTEM    = m_botdata->GetAI()->initSpell(EARTH_ELEMENTAL_TOTEM_1);
    MAELSTROM_WEAPON         = m_botdata->GetAI()->initSpell(MAELSTROM_WEAPON_1);
    // elemental
    LIGHTNING_BOLT           = m_botdata->GetAI()->initSpell(LIGHTNING_BOLT_1);
    EARTH_SHOCK              = m_botdata->GetAI()->initSpell(EARTH_SHOCK_1);
    FLAME_SHOCK              = m_botdata->GetAI()->initSpell(FLAME_SHOCK_1);
    PURGE                    = m_botdata->GetAI()->initSpell(PURGE_1);
    WIND_SHOCK               = 0; //NPC spell
    FROST_SHOCK              = m_botdata->GetAI()->initSpell(FROST_SHOCK_1);
    CHAIN_LIGHTNING          = m_botdata->GetAI()->initSpell(CHAIN_LIGHTNING_1);
    LAVA_BURST               = m_botdata->GetAI()->initSpell(LAVA_BURST_1);
    HEX                      = m_botdata->GetAI()->initSpell(HEX_1);
    STONECLAW_TOTEM          = m_botdata->GetAI()->initSpell(STONECLAW_TOTEM_1); // totems
    SEARING_TOTEM            = m_botdata->GetAI()->initSpell(SEARING_TOTEM_1);
    FIRE_NOVA_TOTEM          = 0; // NPC only spell, check FIRE_NOVA_1
    MAGMA_TOTEM              = m_botdata->GetAI()->initSpell(MAGMA_TOTEM_1);
    EARTHBIND_TOTEM          = m_botdata->GetAI()->initSpell(EARTHBIND_TOTEM_1);
    TOTEM_OF_WRATH           = m_botdata->GetAI()->initSpell(TOTEM_OF_WRATH_1);
    FIRE_ELEMENTAL_TOTEM     = m_botdata->GetAI()->initSpell(FIRE_ELEMENTAL_TOTEM_1);
    ELEMENTAL_MASTERY        = m_botdata->GetAI()->initSpell(ELEMENTAL_MASTERY_1);
    THUNDERSTORM             = m_botdata->GetAI()->initSpell(THUNDERSTORM_1);

    // racial
    GIFT_OF_THE_NAARU        = m_botdata->GetAI()->initSpell(GIFT_OF_THE_NAARU_SHAMAN); // draenei
    BLOOD_FURY               = m_botdata->GetAI()->initSpell(BLOOD_FURY_SHAMAN); // orc
    WAR_STOMP                = m_botdata->GetAI()->initSpell(WAR_STOMP_ALL); // tauren
    BERSERKING               = m_botdata->GetAI()->initSpell(BERSERKING_ALL); // troll

    // totem buffs
    STRENGTH_OF_EARTH_EFFECT    = m_botdata->GetAI()->initSpell(STRENGTH_OF_EARTH_EFFECT_1);
    FLAMETONGUE_EFFECT          = m_botdata->GetAI()->initSpell(FLAMETONGUE_EFFECT_1);
    MAGMA_TOTEM_EFFECT          = m_botdata->GetAI()->initSpell(MAGMA_TOTEM_EFFECT_1);
    STONECLAW_EFFECT            = m_botdata->GetAI()->initSpell(STONECLAW_EFFECT_1);
    FIRE_RESISTANCE_EFFECT      = m_botdata->GetAI()->initSpell(FIRE_RESISTANCE_EFFECT_1);
    FROST_RESISTANCE_EFFECT     = m_botdata->GetAI()->initSpell(FROST_RESISTANCE_EFFECT_1);
    GROUDNING_EFFECT            = m_botdata->GetAI()->initSpell(GROUDNING_EFFECT_1);
    NATURE_RESISTANCE_EFFECT    = m_botdata->GetAI()->initSpell(NATURE_RESISTANCE_EFFECT_1);
    STONESKIN_EFFECT            = m_botdata->GetAI()->initSpell(STONESKIN_EFFECT_1);
    WINDFURY_EFFECT             = m_botdata->GetAI()->initSpell(WINDFURY_EFFECT_1);
    WRATH_OF_AIR_EFFECT         = m_botdata->GetAI()->initSpell(WRATH_OF_AIR_EFFECT_1);
    CLEANSING_TOTEM_EFFECT      = m_botdata->GetAI()->initSpell(CLEANSING_TOTEM_EFFECT_1);
    HEALING_STREAM_EFFECT       = m_botdata->GetAI()->initSpell(HEALING_STREAM_EFFECT_1);
    MANA_SPRING_EFFECT          = m_botdata->GetAI()->initSpell(MANA_SPRING_EFFECT_1);
    TREMOR_TOTEM_EFFECT         = m_botdata->GetAI()->initSpell(TREMOR_TOTEM_EFFECT_1);
    TOTEM_OF_WRATH_EFFECT       = m_botdata->GetAI()->initSpell(TOTEM_OF_WRATH_EFFECT_1);
    STONECLAW_EFFECT            = m_botdata->GetAI()->initSpell(STONECLAW_EFFECT_1);
    EARTHBIND_EFFECT            = m_botdata->GetAI()->initSpell(EARTHBIND_EFFECT_1);

    // Buffs that don't stack with totems
    IMPROVED_ICY_TALONS     = m_botdata->GetAI()->initSpell(IMPROVED_ICY_TALONS_1);
    HORN_OF_WINTER          = m_botdata->GetAI()->initSpell(HORN_OF_WINTER_1);

    return PlayerbotClassAI::PlayerbotClassAI_ClassAIInit();
}


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
    if (!m_botdata->GetAI())  return RETURN_NO_ACTION_ERROR;
    if (!m_botdata->GetBot()) return RETURN_NO_ACTION_ERROR;

    uint32 spec = m_botdata->GetBot()->GetSpec();

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
    else
    {
        // Is this desirable? Debatable.
        // TODO: In a group/raid with a healer you'd want this bot to focus on DPS (it's not specced/geared for healing either)
        if (HealPlayer(m_botdata->GetBot()) & RETURN_CONTINUE)
            return RETURN_CONTINUE;
    }

    // Damage Spells
    DropTotems();
    CheckShields();
    UseCooldowns();
    switch (spec)
    {
        case SHAMAN_SPEC_ENHANCEMENT:
            if (STORMSTRIKE > 0 && (m_botdata->GetBot()->IsSpellReady(STORMSTRIKE)) && m_botdata->GetAI()->CastSpell(STORMSTRIKE, *pTarget))
                return RETURN_CONTINUE;
            if (FLAME_SHOCK > 0 && (!pTarget->HasAura(FLAME_SHOCK)) && m_botdata->GetAI()->CastSpell(FLAME_SHOCK, *pTarget))
                return RETURN_CONTINUE;
            if (EARTH_SHOCK > 0 && (m_botdata->GetBot()->IsSpellReady(EARTH_SHOCK)) && m_botdata->GetAI()->CastSpell(EARTH_SHOCK, *pTarget))
                return RETURN_CONTINUE;
            if (LAVA_LASH > 0 && (m_botdata->GetBot()->IsSpellReady(LAVA_LASH)) && m_botdata->GetAI()->CastSpell(LAVA_LASH, *pTarget))
                return RETURN_CONTINUE;
            if (MAELSTROM_WEAPON > 0 && LIGHTNING_BOLT > 0 && m_botdata->GetBot()->HasAura(MAELSTROM_WEAPON) && m_botdata->GetAI()->CastSpell(LIGHTNING_BOLT, *pTarget))
                return RETURN_CONTINUE;
            /*if (FOCUSED > 0 && m_botdata->GetAI()->CastSpell(FOCUSED, *pTarget))
                return RETURN_CONTINUE;*/
            break;

        case SHAMAN_SPEC_RESTORATION:
            // fall through to elemental

        case SHAMAN_SPEC_ELEMENTAL:
            if (FLAME_SHOCK > 0 && (!pTarget->HasAura(FLAME_SHOCK)) && m_botdata->GetAI()->CastSpell(FLAME_SHOCK, *pTarget))
                return RETURN_CONTINUE;
            if (LAVA_BURST > 0 && (pTarget->HasAura(FLAME_SHOCK)) && (m_botdata->GetBot()->IsSpellReady(LAVA_BURST)) && m_botdata->GetAI()->CastSpell(LAVA_BURST, *pTarget))
                return RETURN_CONTINUE;
            if (LIGHTNING_BOLT > 0 && m_botdata->GetAI()->CastSpell(LIGHTNING_BOLT, *pTarget))
                return RETURN_CONTINUE;
            /*if (PURGE > 0 && m_botdata->GetAI()->CastSpell(PURGE, *pTarget))
                return RETURN_CONTINUE;*/
            /*if (WIND_SHOCK > 0 && m_botdata->GetAI()->CastSpell(WIND_SHOCK, *pTarget))
                return RETURN_CONTINUE;*/
            /*if (FROST_SHOCK > 0 && !pTarget->HasAura(FROST_SHOCK, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(FROST_SHOCK, *pTarget))
                return RETURN_CONTINUE;*/
            /*if (CHAIN_LIGHTNING > 0 && m_botdata->GetAI()->CastSpell(CHAIN_LIGHTNING, *pTarget))
                return RETURN_CONTINUE;*/
            /*if (HEX > 0 && !pTarget->HasAura(HEX, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(HEX))
                return RETURN_CONTINUE;*/
    }

    return RETURN_NO_ACTION_OK;
} // end DoNextCombatManeuver

CombatManeuverReturns PlayerbotShamanAI::DoNextCombatManeuverPVP(Unit* pTarget)
{
    DropTotems();
    CheckShields();
    UseCooldowns();

    Player* healTarget = (m_botdata->GetAI()->GetScenarioType() == PlayerbotAI::SCENARIO_PVP_DUEL) ? GetHealTarget() : m_botdata->GetBot();
    if (HealPlayer(healTarget) & (RETURN_NO_ACTION_OK | RETURN_CONTINUE))
        return RETURN_CONTINUE;
    if (m_botdata->GetAI()->CastSpell(LIGHTNING_BOLT))
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
        if (ANCESTRAL_SPIRIT && m_botdata->GetAI()->CastSpell(ANCESTRAL_SPIRIT, *target))
        {
            std::string msg = "Resurrecting ";
            msg += target->GetName();
            m_botdata->GetBot()->Say(msg, LANG_UNIVERSAL);
            return RETURN_CONTINUE;
        }
        return RETURN_NO_ACTION_ERROR; // not error per se - possibly just OOM
    }

    // Dispel if necessary
    if (CURE_TOXINS > 0 && (m_botdata->GetAI()->GetCombatOrder() & PlayerbotAI::ORDERS_NODISPEL) == 0)
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
                    if (m_botdata->GetAI()->CastSpell(DISPEL, *target))
                        return RETURN_CONTINUE;
                    return RETURN_NO_ACTION_ERROR;
                }
            }
            else if ((1 << holder->GetSpellProto()->Dispel) & dispelMask2)
            {
                if (holder->GetSpellProto()->Dispel == DISPEL_DISEASE)
                {
                    if (m_botdata->GetAI()->CastSpell(DISPEL, *target))
                        return RETURN_CONTINUE;
                    return RETURN_NO_ACTION_ERROR;
                }
            }
            else if ((1 << holder->GetSpellProto()->Dispel) & dispelMask3 & (DISPEL == CLEANSE_SPIRIT))
            {
                if (holder->GetSpellProto()->Dispel == DISPEL_CURSE)
                {
                    if (m_botdata->GetAI()->CastSpell(DISPEL, *target))
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
    if (target->GetHealthPercent() < 30 && HEALING_WAVE > 0 && m_botdata->GetAI()->CastSpell(HEALING_WAVE, *target))
        return RETURN_CONTINUE;
    if (target->GetHealthPercent() < 50 && LESSER_HEALING_WAVE > 0 && m_botdata->GetAI()->CastSpell(LESSER_HEALING_WAVE, *target))
        return RETURN_CONTINUE;
    if (target->GetHealthPercent() < 60 && RIPTIDE > 0 && !target->HasAura(RIPTIDE, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(RIPTIDE, *target))
        return RETURN_CONTINUE;
    if (target->GetHealthPercent() < 80 && CHAIN_HEAL > 0 && m_botdata->GetAI()->CastSpell(CHAIN_HEAL, *target))
        return RETURN_CONTINUE;

    return RETURN_NO_ACTION_UNKNOWN;
} // end HealTarget

void PlayerbotShamanAI::DropTotems()
{
    if (!m_botdata->GetAI())  return;
    if (!m_botdata->GetBot()) return;

    uint32 spec = m_botdata->GetBot()->GetSpec();

    Totem* earth = m_botdata->GetBot()->GetTotem(TOTEM_SLOT_EARTH);
    Totem* fire = m_botdata->GetBot()->GetTotem(TOTEM_SLOT_FIRE);
    Totem* water = m_botdata->GetBot()->GetTotem(TOTEM_SLOT_WATER);
    Totem* air = m_botdata->GetBot()->GetTotem(TOTEM_SLOT_AIR);

    // Earth Totems
    if ((earth == nullptr) || (m_botdata->GetBot()->GetDistance(earth) > 30))
    {
        if (STRENGTH_OF_EARTH_TOTEM > 0 && m_botdata->GetAI()->CastSpell(STRENGTH_OF_EARTH_TOTEM))
            return;
    }

    // Fire Totems
    if ((fire == nullptr) || (m_botdata->GetBot()->GetDistance(fire) > 30))
    {
        if (m_botdata->GetAI()->GetCombatOrder() & PlayerbotAI::ORDERS_RESIST_FROST && FROST_RESISTANCE_TOTEM > 0 && m_botdata->GetAI()->CastSpell(FROST_RESISTANCE_TOTEM))
            return;
        else if (spec == SHAMAN_SPEC_ELEMENTAL && TOTEM_OF_WRATH > 0 && m_botdata->GetAI()->CastSpell(TOTEM_OF_WRATH))
            return;
        // If the spec didn't take totem of wrath, use flametongue
        else if ((spec != SHAMAN_SPEC_ELEMENTAL || TOTEM_OF_WRATH == 0) && FLAMETONGUE_TOTEM > 0 && m_botdata->GetAI()->CastSpell(FLAMETONGUE_TOTEM))
            return;
    }

    // Air totems
    if ((air == nullptr) || (m_botdata->GetBot()->GetDistance(air) > 30))
    {
        if (m_botdata->GetAI()->GetCombatOrder() & PlayerbotAI::ORDERS_RESIST_NATURE && NATURE_RESISTANCE_TOTEM > 0 && m_botdata->GetAI()->CastSpell(NATURE_RESISTANCE_TOTEM))
            return;
        else if (spec == SHAMAN_SPEC_ENHANCEMENT)
        {
            if (WIND_FURY_TOTEM > 0 /*&& !m_botdata->GetBot()->HasAura(IMPROVED_ICY_TALONS)*/ && m_botdata->GetAI()->CastSpell(WIND_FURY_TOTEM))
            return;
        }
        else
        {
            if (WRATH_OF_AIR_TOTEM > 0 && m_botdata->GetAI()->CastSpell(WRATH_OF_AIR_TOTEM))
            return;
        }
    }

    // Water Totems
    if ((water == nullptr) || (m_botdata->GetBot()->GetDistance(water) > 30))
    {
        if (m_botdata->GetAI()->GetCombatOrder() & PlayerbotAI::ORDERS_RESIST_FIRE && FIRE_RESISTANCE_TOTEM > 0 && m_botdata->GetAI()->CastSpell(FIRE_RESISTANCE_TOTEM))
            return;
        else if (MANA_SPRING_TOTEM > 0 && m_botdata->GetAI()->CastSpell(MANA_SPRING_TOTEM))
            return;
    }

    /*if (EARTH_ELEMENTAL_TOTEM > 0 && m_botdata->GetAI()->CastSpell(EARTH_ELEMENTAL_TOTEM))
        return RETURN_CONTINUE;*/
    /*if (EARTHBIND_TOTEM > 0 && !pTarget->HasAura(EARTHBIND_TOTEM, EFFECT_INDEX_0) && !m_botdata->GetBot()->HasAura(STRENGTH_OF_EARTH_TOTEM, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(EARTHBIND_TOTEM))
        return RETURN_CONTINUE;*/
    /*if (FIRE_ELEMENTAL_TOTEM > 0 && m_botdata->GetAI()->CastSpell(FIRE_ELEMENTAL_TOTEM))
        return RETURN_CONTINUE;*/
    /*if (FIRE_NOVA_TOTEM > 0 && m_botdata->GetAI()->CastSpell(FIRE_NOVA_TOTEM))
        return RETURN_CONTINUE;*/
    /*if (GROUNDING_TOTEM > 0 && !m_botdata->GetBot()->HasAura(GROUNDING_TOTEM, EFFECT_INDEX_0) && !m_botdata->GetBot()->HasAura(WRATH_OF_AIR_TOTEM, EFFECT_INDEX_0) && !m_botdata->GetBot()->HasAura(WIND_FURY_TOTEM, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(GROUNDING_TOTEM))
        return RETURN_CONTINUE;*/
    /*if (HEALING_STREAM_TOTEM > 0 && m_botdata->GetAI()->GetHealthPercent() < 50 && !m_botdata->GetBot()->HasAura(HEALING_STREAM_TOTEM, EFFECT_INDEX_0) && !m_botdata->GetBot()->HasAura(MANA_SPRING_TOTEM, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(HEALING_STREAM_TOTEM))
        return RETURN_CONTINUE;*/
    /*if (MAGMA_TOTEM > 0 && (!m_botdata->GetBot()->HasAura(TOTEM_OF_WRATH, EFFECT_INDEX_0)) && m_botdata->GetAI()->CastSpell(MAGMA_TOTEM))
        return RETURN_CONTINUE;*/
    /*if (SEARING_TOTEM > 0 && !pTarget->HasAura(SEARING_TOTEM, EFFECT_INDEX_0) && !m_botdata->GetBot()->HasAura(TOTEM_OF_WRATH, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(SEARING_TOTEM))
        return RETURN_CONTINUE;*/
    /*if (STONECLAW_TOTEM > 0 && m_botdata->GetAI()->GetHealthPercent() < 51 && !pTarget->HasAura(STONECLAW_TOTEM, EFFECT_INDEX_0) && !pTarget->HasAura(EARTHBIND_TOTEM, EFFECT_INDEX_0) && !m_botdata->GetBot()->HasAura(STRENGTH_OF_EARTH_TOTEM, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(STONECLAW_TOTEM))
        return RETURN_CONTINUE;*/
    /*if (STONESKIN_TOTEM > 0 && !m_botdata->GetBot()->HasAura(STONESKIN_TOTEM, EFFECT_INDEX_0) && !m_botdata->GetBot()->HasAura(STRENGTH_OF_EARTH_TOTEM, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(STONESKIN_TOTEM))
        return RETURN_CONTINUE;*/
    /*if (TREMOR_TOTEM > 0 && !m_botdata->GetBot()->HasAura(STRENGTH_OF_EARTH_TOTEM, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(TREMOR_TOTEM))
        return RETURN_CONTINUE;*/
}

void PlayerbotShamanAI::CheckShields()
{
    if (!m_botdata->GetAI())  return;
    if (!m_botdata->GetBot()) return;

    uint32 spec = m_botdata->GetBot()->GetSpec();

    if (spec == SHAMAN_SPEC_ENHANCEMENT && LIGHTNING_SHIELD > 0 && !m_botdata->GetBot()->HasAura(LIGHTNING_SHIELD, EFFECT_INDEX_0))
        m_botdata->GetAI()->CastSpell(LIGHTNING_SHIELD, *m_botdata->GetBot());
    else if ((spec == SHAMAN_SPEC_ELEMENTAL || spec == SHAMAN_SPEC_RESTORATION) && WATER_SHIELD > 0 && !m_botdata->GetBot()->HasAura(WATER_SHIELD, EFFECT_INDEX_0))
        m_botdata->GetAI()->CastSpell(WATER_SHIELD, *m_botdata->GetBot());
    if (EARTH_SHIELD > 0 && !m_botdata->GetMaster()->HasAura(EARTH_SHIELD, EFFECT_INDEX_0))
        m_botdata->GetAI()->CastSpell(EARTH_SHIELD, *(m_botdata->GetMaster()));
}

void PlayerbotShamanAI::UseCooldowns()
{
    if (!m_botdata->GetAI())  return;
    if (!m_botdata->GetBot()) return;

    uint32 spec = m_botdata->GetBot()->GetSpec();

    if (BLOODLUST > 0 && (!m_botdata->GetMaster()->HasAura(BLOODLUST, EFFECT_INDEX_0)) && m_botdata->GetAI()->CastSpell(BLOODLUST))
        return;
    else if (HEROISM > 0 && (!m_botdata->GetMaster()->HasAura(HEROISM, EFFECT_INDEX_0)) && m_botdata->GetAI()->CastSpell(HEROISM))
        return;

    switch (spec)
    {
        case SHAMAN_SPEC_ENHANCEMENT:
            if (SHAMANISTIC_RAGE > 0 && m_botdata->GetAI()->CastSpell(SHAMANISTIC_RAGE, *m_botdata->GetBot()))
                return;
            else if (FERAL_SPIRIT > 0 && m_botdata->GetAI()->CastSpell(FERAL_SPIRIT))
                return;
            break;

        case SHAMAN_SPEC_ELEMENTAL:
            if (ELEMENTAL_MASTERY > 0 && m_botdata->GetAI()->CastSpell(ELEMENTAL_MASTERY, *m_botdata->GetBot()))
                return;
            else if (THUNDERSTORM > 0 && m_botdata->GetAI()->CastSpell(THUNDERSTORM, *m_botdata->GetBot()))
                return;
            break;

        case SHAMAN_SPEC_RESTORATION:
            if (MANA_TIDE_TOTEM > 0 && m_botdata->GetAI()->GetManaPercent() < 50 && m_botdata->GetAI()->CastSpell(MANA_TIDE_TOTEM))
                return;
            else if (NATURES_SWIFTNESS_SHAMAN > 0 && m_botdata->GetAI()->CastSpell(NATURES_SWIFTNESS_SHAMAN))
                return;
            else if (TIDAL_FORCE > 0 && m_botdata->GetAI()->CastSpell(TIDAL_FORCE))
                return;

        default:
            break;
    }
}

void PlayerbotShamanAI::DoNonCombatActions()
{
    if (!m_botdata->GetAI())   return;
    if (!m_botdata->GetBot())  return;

    if (!m_botdata->GetBot()->isAlive() || m_botdata->GetBot()->IsInDuel()) return;

    uint32 spec = m_botdata->GetBot()->GetSpec();

    CheckShields();
/*
       // buff myself weapon
       if (ROCKBITER_WEAPON > 0)
            (!m_botdata->GetBot()->HasAura(ROCKBITER_WEAPON, EFFECT_INDEX_0) && !m_botdata->GetBot()->HasAura(EARTHLIVING_WEAPON, EFFECT_INDEX_0) && !m_botdata->GetBot()->HasAura(WINDFURY_WEAPON, EFFECT_INDEX_0) && !m_botdata->GetBot()->HasAura(FLAMETONGUE_WEAPON, EFFECT_INDEX_0) && !m_botdata->GetBot()->HasAura(FROSTBRAND_WEAPON, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(ROCKBITER_WEAPON,*m_botdata->GetBot()) );
       else if (EARTHLIVING_WEAPON > 0)
            (!m_botdata->GetBot()->HasAura(EARTHLIVING_WEAPON, EFFECT_INDEX_0) && !m_botdata->GetBot()->HasAura(EARTHLIVING_WEAPON, EFFECT_INDEX_0) && !m_botdata->GetBot()->HasAura(FLAMETONGUE_WEAPON, EFFECT_INDEX_0) && !m_botdata->GetBot()->HasAura(FROSTBRAND_WEAPON, EFFECT_INDEX_0) && !m_botdata->GetBot()->HasAura(ROCKBITER_WEAPON, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(WINDFURY_WEAPON,*m_botdata->GetBot()) );
       else if (WINDFURY_WEAPON > 0)
            (!m_botdata->GetBot()->HasAura(WINDFURY_WEAPON, EFFECT_INDEX_0) && !m_botdata->GetBot()->HasAura(EARTHLIVING_WEAPON, EFFECT_INDEX_0) && !m_botdata->GetBot()->HasAura(FLAMETONGUE_WEAPON, EFFECT_INDEX_0) && !m_botdata->GetBot()->HasAura(FROSTBRAND_WEAPON, EFFECT_INDEX_0) && !m_botdata->GetBot()->HasAura(ROCKBITER_WEAPON, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(WINDFURY_WEAPON,*m_botdata->GetBot()) );
       else if (FLAMETONGUE_WEAPON > 0)
            (!m_botdata->GetBot()->HasAura(FLAMETONGUE_WEAPON, EFFECT_INDEX_0) && !m_botdata->GetBot()->HasAura(EARTHLIVING_WEAPON, EFFECT_INDEX_0) && !m_botdata->GetBot()->HasAura(WINDFURY_WEAPON, EFFECT_INDEX_0) && !m_botdata->GetBot()->HasAura(FROSTBRAND_WEAPON, EFFECT_INDEX_0) && !m_botdata->GetBot()->HasAura(ROCKBITER_WEAPON, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(FLAMETONGUE_WEAPON,*m_botdata->GetBot()) );
       else if (FROSTBRAND_WEAPON > 0)
            (!m_botdata->GetBot()->HasAura(FROSTBRAND_WEAPON, EFFECT_INDEX_0) && !m_botdata->GetBot()->HasAura(EARTHLIVING_WEAPON, EFFECT_INDEX_0) && !m_botdata->GetBot()->HasAura(WINDFURY_WEAPON, EFFECT_INDEX_0) && !m_botdata->GetBot()->HasAura(FLAMETONGUE_WEAPON, EFFECT_INDEX_0) && !m_botdata->GetBot()->HasAura(ROCKBITER_WEAPON, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(FROSTBRAND_WEAPON,*m_botdata->GetBot()) );
 */
    // Mainhand
    Item* weapon;
    weapon = m_botdata->GetBot()->GetItemByPos(EQUIPMENT_SLOT_MAINHAND);
    if (weapon && (weapon->GetEnchantmentId(TEMP_ENCHANTMENT_SLOT) == 0) && spec == SHAMAN_SPEC_RESTORATION)
        m_botdata->GetAI()->CastSpell(EARTHLIVING_WEAPON, *m_botdata->GetBot());
    else if (weapon && (weapon->GetEnchantmentId(TEMP_ENCHANTMENT_SLOT) == 0) && spec == SHAMAN_SPEC_ELEMENTAL)
        m_botdata->GetAI()->CastSpell(FLAMETONGUE_WEAPON, *m_botdata->GetBot());
    else if (weapon && (weapon->GetEnchantmentId(TEMP_ENCHANTMENT_SLOT) == 0) && spec == SHAMAN_SPEC_ENHANCEMENT)
        m_botdata->GetAI()->CastSpell(WINDFURY_WEAPON, *m_botdata->GetBot());

    //Offhand
    weapon = m_botdata->GetBot()->GetItemByPos(EQUIPMENT_SLOT_OFFHAND);
    if (weapon && (weapon->GetEnchantmentId(TEMP_ENCHANTMENT_SLOT) == 0) && spec == SHAMAN_SPEC_ENHANCEMENT)
        m_botdata->GetAI()->CastSpell(FLAMETONGUE_WEAPON, *m_botdata->GetBot());

    // Revive
    if (HealPlayer(GetResurrectionTarget()) & RETURN_CONTINUE)
        return;

    // Heal
    if (m_botdata->GetAI()->IsHealer())
    {
        if (HealPlayer(GetHealTarget()) & RETURN_CONTINUE)
            return;// RETURN_CONTINUE;
    }
    else
    {
        // Is this desirable? Debatable.
        // TODO: In a group/raid with a healer you'd want this bot to focus on DPS (it's not specced/geared for healing either)
        if (HealPlayer(m_botdata->GetBot()) & RETURN_CONTINUE)
            return;// RETURN_CONTINUE;
    }

    // hp/mana check
    if (EatDrinkBandage())
        return;
} // end DoNonCombatActions

bool PlayerbotShamanAI::CastHoTOnTank()
{
    if (!m_botdata->GetAI()) return false;

    if ((PlayerbotAI::ORDERS_HEAL & m_botdata->GetAI()->GetCombatOrder()) == 0) return false;

    // Shaman: Healing Stream Totem, Earthliving Weapon, and Riptide (with talents)
    // None of these are cast before Pulling

    return false;
}
