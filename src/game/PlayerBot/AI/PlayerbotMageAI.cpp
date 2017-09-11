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

#include "PlayerbotMageAI.h"

class PlayerbotAI;

PlayerbotMageAI::PlayerbotMageAI(Player* const master, Player* const bot, PlayerbotAI* const ai) : PlayerbotClassAI(master, bot, ai)
{
    ARCANE_MISSILES         = GetAI()->initSpell(ARCANE_MISSILES_1);
    ARCANE_EXPLOSION        = GetAI()->initSpell(ARCANE_EXPLOSION_1);
    COUNTERSPELL            = GetAI()->initSpell(COUNTERSPELL_1);
    SLOW                    = GetAI()->initSpell(SLOW_1);
    ARCANE_BARRAGE          = GetAI()->initSpell(ARCANE_BARRAGE_1);
    ARCANE_BLAST            = GetAI()->initSpell(ARCANE_BLAST_1);
    ARCANE_POWER            = GetAI()->initSpell(ARCANE_POWER_1);
    DAMPEN_MAGIC            = GetAI()->initSpell(DAMPEN_MAGIC_1);
    AMPLIFY_MAGIC           = GetAI()->initSpell(AMPLIFY_MAGIC_1);
    MAGE_ARMOR              = GetAI()->initSpell(MAGE_ARMOR_1);
    MIRROR_IMAGE            = GetAI()->initSpell(MIRROR_IMAGE_1);
    ARCANE_INTELLECT        = GetAI()->initSpell(ARCANE_INTELLECT_1);
    ARCANE_BRILLIANCE       = GetAI()->initSpell(ARCANE_BRILLIANCE_1);
    DALARAN_INTELLECT       = GetAI()->initSpell(DALARAN_INTELLECT_1);
    DALARAN_BRILLIANCE      = GetAI()->initSpell(DALARAN_BRILLIANCE_1);
    MANA_SHIELD             = GetAI()->initSpell(MANA_SHIELD_1);
    CONJURE_WATER           = GetAI()->initSpell(CONJURE_WATER_1);
    CONJURE_FOOD            = GetAI()->initSpell(CONJURE_FOOD_1);
    FIREBALL                = GetAI()->initSpell(FIREBALL_1);
    FIRE_BLAST              = GetAI()->initSpell(FIRE_BLAST_1);
    FLAMESTRIKE             = GetAI()->initSpell(FLAMESTRIKE_1);
    SCORCH                  = GetAI()->initSpell(SCORCH_1);
    PYROBLAST               = GetAI()->initSpell(PYROBLAST_1);
    BLAST_WAVE              = GetAI()->initSpell(BLAST_WAVE_1);
    COMBUSTION              = GetAI()->initSpell(COMBUSTION_1);
    DRAGONS_BREATH          = GetAI()->initSpell(DRAGONS_BREATH_1);
    LIVING_BOMB             = GetAI()->initSpell(LIVING_BOMB_1);
    FROSTFIRE_BOLT          = GetAI()->initSpell(FROSTFIRE_BOLT_1);
    FIRE_WARD               = GetAI()->initSpell(FIRE_WARD_1);
    MOLTEN_ARMOR            = GetAI()->initSpell(MOLTEN_ARMOR_1);
    ICY_VEINS               = GetAI()->initSpell(ICY_VEINS_1);
    DEEP_FREEZE             = GetAI()->initSpell(DEEP_FREEZE_1);
    FROSTBOLT               = GetAI()->initSpell(FROSTBOLT_1);
    FROST_NOVA              = GetAI()->initSpell(FROST_NOVA_1);
    BLIZZARD                = GetAI()->initSpell(BLIZZARD_1);
    CONE_OF_COLD            = GetAI()->initSpell(CONE_OF_COLD_1);
    ICE_BARRIER             = GetAI()->initSpell(ICE_BARRIER_1);
    SUMMON_WATER_ELEMENTAL  = GetAI()->initSpell(SUMMON_WATER_ELEMENTAL_1);
    FROST_WARD              = GetAI()->initSpell(FROST_WARD_1);
    ICE_LANCE               = GetAI()->initSpell(ICE_LANCE_1);
    FROST_ARMOR             = GetAI()->initSpell(FROST_ARMOR_1);
    ICE_ARMOR               = GetAI()->initSpell(ICE_ARMOR_1);
    ICE_BLOCK               = GetAI()->initSpell(ICE_BLOCK_1);
    COLD_SNAP               = GetAI()->initSpell(COLD_SNAP_1);
    MAGE_REMOVE_CURSE       = GetAI()->initSpell(REMOVE_CURSE_MAGE_1);

    // RANGED COMBAT
    SHOOT                   = GetAI()->initSpell(SHOOT_2);

    RECENTLY_BANDAGED       = 11196; // first aid check

    // racial
    ARCANE_TORRENT          = GetAI()->initSpell(ARCANE_TORRENT_MANA_CLASSES); // blood elf
    GIFT_OF_THE_NAARU       = GetAI()->initSpell(GIFT_OF_THE_NAARU_MAGE); // draenei
    ESCAPE_ARTIST           = GetAI()->initSpell(ESCAPE_ARTIST_ALL); // gnome
    EVERY_MAN_FOR_HIMSELF   = GetAI()->initSpell(EVERY_MAN_FOR_HIMSELF_ALL); // human
    BERSERKING              = GetAI()->initSpell(BERSERKING_ALL); // troll
    WILL_OF_THE_FORSAKEN    = GetAI()->initSpell(WILL_OF_THE_FORSAKEN_ALL); // undead
}

PlayerbotMageAI::~PlayerbotMageAI() {}

CombatManeuverReturns PlayerbotMageAI::DoFirstCombatManeuverPVE(Unit* /*pTarget*/)
{
    return RETURN_NO_ACTION_OK;
}

CombatManeuverReturns PlayerbotMageAI::DoFirstCombatManeuverPVP(Unit* /*pTarget*/)
{
    return RETURN_NO_ACTION_OK;
}

CombatManeuverReturns PlayerbotMageAI::DoNextCombatManeuverPVE(Unit *pTarget)
{
    if (!GetAI())  return RETURN_NO_ACTION_ERROR;
    if (!m_bot) return RETURN_NO_ACTION_ERROR;

    Unit* pVictim = pTarget->getVictim();
    bool meleeReach = m_bot->CanReachWithMeleeAttack(pTarget);

    uint32 spec = m_bot->GetSpec();

//	GetAI()->TellMaster("My spec is %u.", spec);

    if (GetAI()->GetCombatStyle() != PlayerbotAI::COMBAT_RANGED && !meleeReach)
        GetAI()->SetCombatStyle(PlayerbotAI::COMBAT_RANGED);
    // if can't shoot OR have no ranged (wand) equipped
    else if(GetAI()->GetCombatStyle() != PlayerbotAI::COMBAT_MELEE && (SHOOT == 0 || !m_bot->GetWeaponForAttack(RANGED_ATTACK, true, true)))
        GetAI()->SetCombatStyle(PlayerbotAI::COMBAT_MELEE);

    //Used to determine if this bot is highest on threat
    Unit *newTarget = GetAI()->FindAttacker((PlayerbotAI::ATTACKERINFOTYPE) (PlayerbotAI::AIT_VICTIMSELF | PlayerbotAI::AIT_HIGHESTTHREAT), m_bot);
    
    // Remove curse on group members
    if (Player* pCursedTarget = GetDispelTarget(DISPEL_CURSE))
    {
        if (MAGE_REMOVE_CURSE > 0 && CastSpell(MAGE_REMOVE_CURSE, pCursedTarget))
            return RETURN_CONTINUE;
    }

    if (newTarget) // TODO: && party has a tank
    {
        // Insert instant threat reducing spell (if a mage has one)

        // Have threat, can't quickly lower it. 3 options remain: Stop attacking, lowlevel damage (wand), keep on keeping on.
        if (newTarget->GetHealthPercent() > 25)
        {
            // If elite, do nothing and pray tank gets aggro off you
            // TODO: Is there an IsElite function? If so, find it and insert.
            //if (newTarget->IsElite())
            //    return;

            // Not an elite. You could insert FEAR here but in any PvE situation that's 90-95% likely
            // to worsen the situation for the group. ... So please don't.
            CastSpell(SHOOT, pTarget);
            return RETURN_CONTINUE;
        }
    }

    switch (spec)
    {
        case MAGE_SPEC_FIRE:
            if (FIRE_WARD > 0 && GetAI()->In_Reach(m_bot,FIRE_WARD) && !m_bot->HasAura(FIRE_WARD, EFFECT_INDEX_0) && CastSpell(FIRE_WARD, m_bot))
                return RETURN_CONTINUE;
            if (COMBUSTION > 0 && GetAI()->In_Reach(m_bot,COMBUSTION) && !m_bot->HasAura(COMBUSTION, EFFECT_INDEX_0) && CastSpell(COMBUSTION, m_bot))
                return RETURN_CONTINUE;
            if (FIREBALL > 0 && GetAI()->In_Reach(pTarget,FIREBALL) && CastSpell(FIREBALL, pTarget))
                return RETURN_CONTINUE;
            if (FIRE_BLAST > 0 && GetAI()->In_Reach(pTarget,FIRE_BLAST) && CastSpell(FIRE_BLAST, pTarget))
                return RETURN_CONTINUE;
            if (FLAMESTRIKE > 0 && GetAI()->In_Reach(pTarget,FLAMESTRIKE) && CastSpell(FLAMESTRIKE, pTarget))
                return RETURN_CONTINUE;
            if (SCORCH > 0 && GetAI()->In_Reach(pTarget,SCORCH) && CastSpell(SCORCH, pTarget))
                return RETURN_CONTINUE;
            if (PYROBLAST > 0 && GetAI()->In_Reach(pTarget,PYROBLAST) && !pTarget->HasAura(PYROBLAST, EFFECT_INDEX_0) && CastSpell(PYROBLAST, pTarget))
                return RETURN_CONTINUE;
            if (BLAST_WAVE > 0 && GetAI()->GetAttackerCount() >= 3 && meleeReach && CastSpell(BLAST_WAVE, pTarget))
                return RETURN_CONTINUE;
            if (DRAGONS_BREATH > 0 && meleeReach && CastSpell(DRAGONS_BREATH, pTarget))
                return RETURN_CONTINUE;
            if (LIVING_BOMB > 0 && GetAI()->In_Reach(pTarget,LIVING_BOMB) && !pTarget->HasAura(LIVING_BOMB, EFFECT_INDEX_0) && CastSpell(LIVING_BOMB, pTarget))
                return RETURN_CONTINUE;
            if (FROSTFIRE_BOLT > 0 && GetAI()->In_Reach(pTarget,FROSTFIRE_BOLT) && !pTarget->HasAura(FROSTFIRE_BOLT, EFFECT_INDEX_0) && CastSpell(FROSTFIRE_BOLT, pTarget))
                return RETURN_CONTINUE;

            if (FIREBALL > 0 && GetAI()->In_Reach(pTarget,FIREBALL))
                return CastSpell(FIREBALL, pTarget);
            break;

        case MAGE_SPEC_ARCANE:
            if (ARCANE_POWER > 0 && GetAI()->In_Reach(pTarget,ARCANE_POWER) && CastSpell(ARCANE_POWER, pTarget))
                return RETURN_CONTINUE;
            if (ARCANE_MISSILES > 0 && GetAI()->In_Reach(pTarget,ARCANE_MISSILES) && CastSpell(ARCANE_MISSILES, pTarget))
            {
                GetAI()->SetIgnoreUpdateTime(3);
                return RETURN_CONTINUE;
            }
            if (ARCANE_EXPLOSION > 0 && GetAI()->GetAttackerCount() >= 3 && meleeReach && CastSpell(ARCANE_EXPLOSION, pTarget))
                return RETURN_CONTINUE;
            if (COUNTERSPELL > 0 && pTarget->IsNonMeleeSpellCasted(true) && CastSpell(COUNTERSPELL, pTarget))
                return RETURN_CONTINUE;
            if (SLOW > 0 && GetAI()->In_Reach(pTarget,SLOW) && !pTarget->HasAura(SLOW, EFFECT_INDEX_0) && CastSpell(SLOW, pTarget))
                return RETURN_CONTINUE;
            if (ARCANE_BARRAGE > 0 && GetAI()->In_Reach(pTarget,ARCANE_BARRAGE) && CastSpell(ARCANE_BARRAGE, pTarget))
                return RETURN_CONTINUE;
            if (ARCANE_BLAST > 0 && GetAI()->In_Reach(pTarget,ARCANE_BLAST) && CastSpell(ARCANE_BLAST, pTarget))
                return RETURN_CONTINUE;
            if (MIRROR_IMAGE > 0 && GetAI()->In_Reach(pTarget,MIRROR_IMAGE) && CastSpell(MIRROR_IMAGE))
                return RETURN_CONTINUE;
            if (MANA_SHIELD > 0 && GetAI()->GetHealthPercent() < 70 && pVictim == m_bot && !m_bot->HasAura(MANA_SHIELD, EFFECT_INDEX_0) && CastSpell(MANA_SHIELD, m_bot))
                return RETURN_CONTINUE;

            if (FIREBALL > 0 && GetAI()->In_Reach(pTarget,FIREBALL))
                return CastSpell(FIREBALL, pTarget);
            break;

		default:
		case MAGE_SPEC_FROST:
			if (ICY_VEINS > 0 && GetAI()->In_Reach(m_bot, ICY_VEINS) && !m_bot->HasAura(ICY_VEINS, EFFECT_INDEX_0) && CastSpell(ICY_VEINS, m_bot))
				return RETURN_CONTINUE;
			if (ICE_BLOCK > 0 && GetAI()->In_Reach(m_bot, ICE_BLOCK) && pVictim == m_bot && !m_bot->HasAura(ICE_BLOCK, EFFECT_INDEX_0) && CastSpell(ICE_BLOCK, m_bot))
				return RETURN_CONTINUE;
			if (ICE_BARRIER > 0 && GetAI()->In_Reach(m_bot, ICE_BARRIER) && pVictim == m_bot && !m_bot->HasAura(ICE_BARRIER, EFFECT_INDEX_0) && GetAI()->GetHealthPercent() < 50 && CastSpell(ICE_BARRIER, m_bot))
				return RETURN_CONTINUE;
			if (DEEP_FREEZE > 0 && GetAI()->In_Reach(pTarget, DEEP_FREEZE) && pTarget->HasAura(AURA_STATE_FROZEN, EFFECT_INDEX_0) && !pTarget->HasAura(DEEP_FREEZE, EFFECT_INDEX_0) && CastSpell(DEEP_FREEZE, pTarget))
				return RETURN_CONTINUE;
			if (BLIZZARD > 0 && GetAI()->In_Reach(pTarget, BLIZZARD) && GetAI()->GetAttackerCount() >= 5 && CastSpell(BLIZZARD, pTarget))
			{
				GetAI()->SetIgnoreUpdateTime(8);
				return RETURN_CONTINUE;
			}
			if (CONE_OF_COLD > 0 && meleeReach && !pTarget->HasAura(CONE_OF_COLD, EFFECT_INDEX_0) && CastSpell(CONE_OF_COLD, pTarget))
				return RETURN_CONTINUE;
			if (FROSTBOLT > 0 && GetAI()->In_Reach(pTarget, FROSTBOLT) && !pTarget->HasAura(FROSTBOLT, EFFECT_INDEX_0) && CastSpell(FROSTBOLT, pTarget))
				return RETURN_CONTINUE;
			if (FROST_WARD > 0 && GetAI()->In_Reach(m_bot, FROST_WARD) && !m_bot->HasAura(FROST_WARD, EFFECT_INDEX_0) && CastSpell(FROST_WARD, m_bot))
				return RETURN_CONTINUE;
			if (FROST_NOVA > 0 && meleeReach && !pTarget->HasAura(FROST_NOVA, EFFECT_INDEX_0) && CastSpell(FROST_NOVA, pTarget))
				return RETURN_CONTINUE;
			if (ICE_LANCE > 0 && GetAI()->In_Reach(pTarget, ICE_LANCE) && CastSpell(ICE_LANCE, pTarget))
				return RETURN_CONTINUE;
			if (SUMMON_WATER_ELEMENTAL > 0 && CastSpell(SUMMON_WATER_ELEMENTAL))
				return RETURN_CONTINUE;
			if (COLD_SNAP > 0 && GetAI()->In_Reach(m_bot, COLD_SNAP) && CastSpell(COLD_SNAP, m_bot))
				return RETURN_CONTINUE;

			if (FROSTBOLT > 0 && GetAI()->In_Reach(pTarget, FROSTBOLT))
				return CastSpell(FROSTBOLT, pTarget);
			break;
	}

    // No spec due to low level OR no spell found yet
    if (FROSTBOLT > 0 && GetAI()->In_Reach(pTarget,FROSTBOLT) && !pTarget->HasAura(FROSTBOLT, EFFECT_INDEX_0))
        return CastSpell(FROSTBOLT, pTarget);
    if (FIREBALL > 0 && GetAI()->In_Reach(pTarget,FIREBALL)) // Very low levels
        return CastSpell(FIREBALL, pTarget);

    return RETURN_NO_ACTION_ERROR; // What? Not even Fireball is available?
} // end DoNextCombatManeuver

CombatManeuverReturns PlayerbotMageAI::DoNextCombatManeuverPVP(Unit* pTarget)
{
    if (FIREBALL && GetAI()->In_Reach(pTarget,FIREBALL) && GetAI()->CastSpell(FIREBALL))
        return RETURN_CONTINUE;

    return DoNextCombatManeuverPVE(pTarget); // TODO: bad idea perhaps, but better than the alternative
}

void PlayerbotMageAI::DoNonCombatActions()
{
    Player* master = GetMaster();

    if (!m_bot || !master)
        return;

    // Remove curse on group members
    if (Player* pCursedTarget = GetDispelTarget(DISPEL_CURSE))
    {
        if (MAGE_REMOVE_CURSE > 0 && CastSpell(MAGE_REMOVE_CURSE, pCursedTarget))
            return;
    }

    // Buff armor
    if (MOLTEN_ARMOR)
    {
        if (GetAI()->SelfBuff(MOLTEN_ARMOR))
            return;
    }
    else if (MAGE_ARMOR)
    {
        if (GetAI()->SelfBuff(MAGE_ARMOR))
            return;
    }
    else if (ICE_ARMOR)
    {
        if (GetAI()->SelfBuff(ICE_ARMOR))
            return;
    }
    else if (FROST_ARMOR)
        if (GetAI()->SelfBuff(FROST_ARMOR))
            return;

    // buff group
    // the check for group targets is performed by NeedGroupBuff (if group is found for bots by the function)
    if (NeedGroupBuff(ARCANE_BRILLIANCE, ARCANE_INTELLECT) && GetAI()->HasSpellReagents(ARCANE_BRILLIANCE))
    {
        if (Buff(&PlayerbotMageAI::BuffHelper, ARCANE_BRILLIANCE) & RETURN_CONTINUE)
            return;
    }
    else if (Buff(&PlayerbotMageAI::BuffHelper, ARCANE_INTELLECT, JOB_MANAONLY) & RETURN_CONTINUE)
        return;
    //DEBUG_LOG("Didn't buff. Woot!");

    // TODO: The beauty of a mage is not only its ability to supply itself with water, but to share its water
    // So, conjure at *least* 1.25 stacks, ready to trade a stack and still have some left for self
    if (GetAI()->FindDrink() == nullptr && CONJURE_WATER && GetAI()->CastSpell(CONJURE_WATER, *m_bot))
    {
        GetAI()->TellMaster("I'm conjuring some water.");
        GetAI()->SetIgnoreUpdateTime(3);
        return;
    }
    if (GetAI()->FindFood() == nullptr && CONJURE_FOOD && GetAI()->CastSpell(CONJURE_FOOD, *m_bot))
    {
        GetAI()->TellMaster("I'm conjuring some food.");
        GetAI()->SetIgnoreUpdateTime(3);
        return;
    }

    if (EatDrinkBandage())
        return;
} // end DoNonCombatActions

// TODO: this and priest's BuffHelper are identical and thus could probably go in PlayerbotClassAI.cpp somewhere
bool PlayerbotMageAI::BuffHelper(PlayerbotAI* ai, uint32 spellId, Unit *target)
{
    //DEBUG_LOG("..Mage_BuffHelper to the rescue!");
    if (!ai)          return false;
    if (spellId == 0) return false;
    if (!target)      return false;
    //DEBUG_LOG("..Sanity checks passed");

    if (ai->Buff(spellId, target))
    {
        //DEBUG_LOG("..Buffed");
        return true;
    }

    //DEBUG_LOG("..Not buffing anyone!");
    return false;
}
