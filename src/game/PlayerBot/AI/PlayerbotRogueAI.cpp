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

#include "PlayerbotRogueAI.h"
#include "../Base/PlayerbotMgr.h"

class PlayerbotAI;
PlayerbotRogueAI::PlayerbotRogueAI(Player* const master, Player* const bot, PlayerbotAI* const ai) : PlayerbotClassAI(master, bot, ai)
{
    SINISTER_STRIKE          = GetAI()->initSpell(SINISTER_STRIKE_1);
    BACKSTAB                 = GetAI()->initSpell(BACKSTAB_1);
    KICK                     = GetAI()->initSpell(KICK_1);
    FEINT                    = GetAI()->initSpell(FEINT_1);
    FAN_OF_KNIVES            = GetAI()->initSpell(FAN_OF_KNIVES_1);
    GOUGE                    = GetAI()->initSpell(GOUGE_1);
    SPRINT                   = GetAI()->initSpell(SPRINT_1);

    SHADOWSTEP               = GetAI()->initSpell(SHADOWSTEP_1);
    STEALTH                  = GetAI()->initSpell(STEALTH_1);
    VANISH                   = GetAI()->initSpell(VANISH_1);
    EVASION                  = GetAI()->initSpell(EVASION_1);
    CLOAK_OF_SHADOWS         = GetAI()->initSpell(CLOAK_OF_SHADOWS_1);
    HEMORRHAGE               = GetAI()->initSpell(HEMORRHAGE_1);
    GHOSTLY_STRIKE           = GetAI()->initSpell(GHOSTLY_STRIKE_1);
    SHADOW_DANCE             = GetAI()->initSpell(SHADOW_DANCE_1);
    BLIND                    = GetAI()->initSpell(BLIND_1);
    DISTRACT                 = GetAI()->initSpell(DISTRACT_1);
    PREPARATION              = GetAI()->initSpell(PREPARATION_1);
    PREMEDITATION            = GetAI()->initSpell(PREMEDITATION_1);
    PICK_POCKET              = GetAI()->initSpell(PICK_POCKET_1);

    EVISCERATE               = GetAI()->initSpell(EVISCERATE_1);
    KIDNEY_SHOT              = GetAI()->initSpell(KIDNEY_SHOT_1);
    SLICE_DICE               = GetAI()->initSpell(SLICE_AND_DICE_1);
    GARROTE                  = GetAI()->initSpell(GARROTE_1);
    EXPOSE_ARMOR             = GetAI()->initSpell(EXPOSE_ARMOR_1);
    RUPTURE                  = GetAI()->initSpell(RUPTURE_1);
    DISMANTLE                = GetAI()->initSpell(DISMANTLE_1);
    CHEAP_SHOT               = GetAI()->initSpell(CHEAP_SHOT_1);
    AMBUSH                   = GetAI()->initSpell(AMBUSH_1);
    MUTILATE                 = GetAI()->initSpell(MUTILATE_1);

    RECENTLY_BANDAGED   = 11196; // first aid check
    // racial
    ARCANE_TORRENT           = GetAI()->initSpell(ARCANE_TORRENT_ROGUE);
    STONEFORM                = GetAI()->initSpell(STONEFORM_ALL); // dwarf
    ESCAPE_ARTIST            = GetAI()->initSpell(ESCAPE_ARTIST_ALL); // gnome
    EVERY_MAN_FOR_HIMSELF    = GetAI()->initSpell(EVERY_MAN_FOR_HIMSELF_ALL); // human
    SHADOWMELD               = GetAI()->initSpell(SHADOWMELD_ALL);
    BLOOD_FURY               = GetAI()->initSpell(BLOOD_FURY_MELEE_CLASSES); // orc
    BERSERKING               = GetAI()->initSpell(BERSERKING_ALL); // troll
    WILL_OF_THE_FORSAKEN     = GetAI()->initSpell(WILL_OF_THE_FORSAKEN_ALL); // undead
}

PlayerbotRogueAI::~PlayerbotRogueAI() {}

CombatManeuverReturns PlayerbotRogueAI::DoFirstCombatManeuverPVE(Unit *pTarget)
{
    if (STEALTH > 0 && !m_bot->HasAura(STEALTH, EFFECT_INDEX_0) && GetAI()->CastSpell(STEALTH, *m_bot))
    {
        m_bot->addUnitState(UNIT_STAT_CHASE); // ensure that the bot does not use MoveChase(), as this doesn't seem to work with STEALTH
        return RETURN_FINISHED_FIRST_MOVES; // DoNextCombatManeuver handles active stealth
    }
    else if (m_bot->HasAura(STEALTH, EFFECT_INDEX_0))
    {
        m_bot->GetMotionMaster()->MoveFollow(pTarget, 4.5f, m_bot->GetOrientation()); // TODO: this isn't the place for movement code, is it?
        return RETURN_FINISHED_FIRST_MOVES; // DoNextCombatManeuver handles active stealth
    }

    // Not in stealth, can't cast stealth; Off to DoNextCombatManeuver
    return RETURN_NO_ACTION_OK;
}

// TODO: blatant copy of PVE for now, please PVP-port it
CombatManeuverReturns PlayerbotRogueAI::DoFirstCombatManeuverPVP(Unit *pTarget)
{
    if (STEALTH > 0 && !m_bot->HasAura(STEALTH, EFFECT_INDEX_0) && GetAI()->CastSpell(STEALTH, *m_bot))
    {
        m_bot->addUnitState(UNIT_STAT_CHASE); // ensure that the bot does not use MoveChase(), as this doesn't seem to work with STEALTH
        return RETURN_FINISHED_FIRST_MOVES; // DoNextCombatManeuver handles active stealth
    }
    else if (m_bot->HasAura(STEALTH, EFFECT_INDEX_0))
    {
        m_bot->GetMotionMaster()->MoveFollow(pTarget, 4.5f, m_bot->GetOrientation()); // TODO: this isn't the place for movement code, is it?
        return RETURN_FINISHED_FIRST_MOVES; // DoNextCombatManeuver handles active stealth
    }

    // Not in stealth, can't cast stealth; Off to DoNextCombatManeuver
    return RETURN_NO_ACTION_OK;
}

CombatManeuverReturns PlayerbotRogueAI::DoNextCombatManeuverPVE(Unit *pTarget)
{
    if (!pTarget) return RETURN_NO_ACTION_ERROR;
    if (!GetAI())    return RETURN_NO_ACTION_ERROR;
    if (!m_bot)   return RETURN_NO_ACTION_ERROR;

    Unit* pVictim = pTarget->getVictim();
    bool meleeReach = m_bot->CanReachWithMeleeAttack(pTarget);

    // TODO: make this work better...
    /*if (pVictim)
       {
        if( pVictim!=m_bot && !m_bot->hasUnitState(UNIT_STAT_FOLLOW) && !pTarget->isInBackInMap(m_bot,10) ) {
            GetAI()->TellMaster( "getting behind target" );
            m_bot->GetMotionMaster()->Clear( true );
            m_bot->GetMotionMaster()->MoveFollow( pTarget, 1, 2*M_PI );
        }
        else if( pVictim==m_bot && m_bot->hasUnitState(UNIT_STAT_FOLLOW) )
        {
            GetAI()->TellMaster( "chasing attacking target" );
            m_bot->GetMotionMaster()->Clear( true );
            m_bot->GetMotionMaster()->MoveChase( pTarget );
        }
       }*/

    // Rogue like behaviour ^^
    /*if (VANISH > 0 && GetMaster()->isDead()) { //Causes the server to crash :( removed for now.
        m_bot->AttackStop();
        m_bot->RemoveAllAttackers();
        GetAI()->CastSpell(VANISH);
        //m_bot->RemoveAllSpellCooldown();
        GetAI()->TellMaster("AttackStop, CombatStop, Vanish");
    }*/

    // decide what to do:
    if (pVictim == m_bot && CLOAK_OF_SHADOWS > 0 && m_bot->HasAura(SPELL_AURA_PERIODIC_DAMAGE) && !m_bot->HasAura(CLOAK_OF_SHADOWS, EFFECT_INDEX_0) && GetAI()->CastSpell(CLOAK_OF_SHADOWS))
    {
        if (GetAI()->GetManager()->m_confDebugWhisper)
            GetAI()->TellMaster("CoS!");
        return RETURN_CONTINUE;
    }
    else if (m_bot->HasAura(STEALTH, EFFECT_INDEX_0))
        SpellSequence = RogueStealth;
    else if (pTarget->IsNonMeleeSpellCasted(true))
        SpellSequence = RogueSpellPreventing;
    else if (pVictim == m_bot && GetAI()->GetHealthPercent() < 40)
        SpellSequence = RogueThreat;
    else
        SpellSequence = RogueCombat;

    // we fight in melee, target is not in range, skip the next part!
    if (!meleeReach)
        return RETURN_CONTINUE;

    std::ostringstream out;
    switch (SpellSequence)
    {
        case RogueStealth:
            if (PICK_POCKET > 0 && (pTarget->GetCreatureTypeMask() & CREATURE_TYPEMASK_HUMANOID_OR_UNDEAD) != 0 && GetAI()->PickPocket(pTarget))
                return RETURN_CONTINUE;
            if (PREMEDITATION > 0 && GetAI()->CastSpell(PREMEDITATION, *pTarget))
                return RETURN_CONTINUE;
            if (AMBUSH > 0 && GetAI()->CastSpell(AMBUSH, *pTarget))
                return RETURN_CONTINUE;
            if (CHEAP_SHOT > 0 && !pTarget->HasAura(CHEAP_SHOT, EFFECT_INDEX_0) && GetAI()->CastSpell(CHEAP_SHOT, *pTarget))
                return RETURN_CONTINUE;
            if (GARROTE > 0 && GetAI()->CastSpell(GARROTE, *pTarget))
                return RETURN_CONTINUE;

            // No appropriate action found, remove stealth
            m_bot->RemoveSpellsCausingAura(SPELL_AURA_MOD_STEALTH);
            return RETURN_CONTINUE;

        case RogueThreat:
            if (GOUGE > 0 && !pTarget->HasAura(GOUGE, EFFECT_INDEX_0) && GetAI()->CastSpell(GOUGE, *pTarget))
                return RETURN_CONTINUE;
            if (EVASION > 0 && GetAI()->GetHealthPercent() <= 35 && !m_bot->HasAura(EVASION, EFFECT_INDEX_0) && GetAI()->CastSpell(EVASION))
                return RETURN_CONTINUE;
            if (BLIND > 0 && GetAI()->GetHealthPercent() <= 30 && !pTarget->HasAura(BLIND, EFFECT_INDEX_0) && GetAI()->CastSpell(BLIND, *pTarget))
                return RETURN_CONTINUE;
            if (FEINT > 0 && GetAI()->GetHealthPercent() <= 25 && GetAI()->CastSpell(FEINT))
                return RETURN_CONTINUE;
            if (VANISH > 0 && GetAI()->GetHealthPercent() <= 20 && !m_bot->HasAura(FEINT, EFFECT_INDEX_0) && GetAI()->CastSpell(VANISH))
                return RETURN_CONTINUE;
            if (PREPARATION > 0 && GetAI()->CastSpell(PREPARATION))
                return RETURN_CONTINUE;
            if (m_bot->getRace() == RACE_NIGHTELF && GetAI()->GetHealthPercent() <= 15 && !m_bot->HasAura(SHADOWMELD, EFFECT_INDEX_0) && GetAI()->CastSpell(SHADOWMELD, *m_bot))
                return RETURN_CONTINUE;
            break;

        case RogueSpellPreventing:
            if (KIDNEY_SHOT > 0 && m_bot->GetComboPoints() >= 2 && GetAI()->CastSpell(KIDNEY_SHOT, *pTarget))
                return RETURN_CONTINUE;
            else if (KICK > 0 && GetAI()->CastSpell(KICK, *pTarget))
                return RETURN_CONTINUE;
            // break; // No action? Go combat!

        case RogueCombat:
        default:
            if (m_bot->GetComboPoints() >= 5)
            {
                // wait for energy
                if (GetAI()->GetEnergyAmount() < 25 && (KIDNEY_SHOT || SLICE_DICE || EXPOSE_ARMOR))
                    return RETURN_NO_ACTION_OK;

                switch (pTarget->getClass())
                {
                case CLASS_SHAMAN:
                    if (KIDNEY_SHOT > 0 && GetAI()->CastSpell(KIDNEY_SHOT, *pTarget)) // 25 energy (checked above)
                        return RETURN_CONTINUE;
                    break;

                case CLASS_WARLOCK:
                case CLASS_HUNTER:
                    if (SLICE_DICE > 0 && GetAI()->CastSpell(SLICE_DICE, *pTarget)) // 25 energy (checked above)
                       return RETURN_CONTINUE;
                    break;

                case CLASS_WARRIOR:
                case CLASS_PALADIN:
                case CLASS_DEATH_KNIGHT:
                    if (EXPOSE_ARMOR > 0 && !pTarget->HasAura(EXPOSE_ARMOR, EFFECT_INDEX_0) && GetAI()->CastSpell(EXPOSE_ARMOR, *pTarget)) // 25 energy (checked above)
                        return RETURN_CONTINUE;
                    break;


                case CLASS_MAGE:
                case CLASS_PRIEST:
                    if (RUPTURE > 0 && GetAI()->CastSpell(RUPTURE, *pTarget)) // 25 energy (checked above)
                        return RETURN_CONTINUE;
                    break;

                case CLASS_ROGUE:
                case CLASS_DRUID:
                default:
                    break; // fall through to below
                }

                // default combo action for rogue/druid or if other combo action is unavailable/failed
                // wait for energy
                if (GetAI()->GetEnergyAmount() < 35 && EVISCERATE)
                    return RETURN_NO_ACTION_OK;
                if (EVISCERATE > 0 && GetAI()->CastSpell(EVISCERATE, *pTarget))
                    return RETURN_CONTINUE;

                // failed for some (non-energy related) reason, fall through to normal attacks to maximize DPS
            }

            if (SHADOW_DANCE > 0 && !m_bot->HasAura(SHADOW_DANCE, EFFECT_INDEX_0) && GetAI()->CastSpell(SHADOW_DANCE, *m_bot))
                return RETURN_CONTINUE;
            if (CHEAP_SHOT > 0 && m_bot->HasAura(SHADOW_DANCE, EFFECT_INDEX_0) && !pTarget->HasAura(CHEAP_SHOT, EFFECT_INDEX_0) && GetAI()->CastSpell(CHEAP_SHOT, *pTarget))
                return RETURN_CONTINUE;
            if (AMBUSH > 0 && m_bot->HasAura(SHADOW_DANCE, EFFECT_INDEX_0) && GetAI()->CastSpell(AMBUSH, *pTarget))
                return RETURN_CONTINUE;
            if (GARROTE > 0 && m_bot->HasAura(SHADOW_DANCE, EFFECT_INDEX_0) && GetAI()->CastSpell(GARROTE, *pTarget))
                return RETURN_CONTINUE;
            if (BACKSTAB > 0 && pTarget->isInBackInMap(m_bot, 1) && GetAI()->CastSpell(BACKSTAB, *pTarget))
                return RETURN_CONTINUE;
            if (MUTILATE > 0 && GetAI()->CastSpell(MUTILATE, *pTarget))
                return RETURN_CONTINUE;
            if (SINISTER_STRIKE > 0 && GetAI()->CastSpell(SINISTER_STRIKE, *pTarget))
                return RETURN_CONTINUE;
            if (GHOSTLY_STRIKE > 0 && GetAI()->CastSpell(GHOSTLY_STRIKE, *pTarget))
                return RETURN_CONTINUE;
            if (HEMORRHAGE > 0 && GetAI()->CastSpell(HEMORRHAGE, *pTarget))
                return RETURN_CONTINUE;
            if (DISMANTLE > 0 && !pTarget->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISARMED) && GetAI()->CastSpell(DISMANTLE, *pTarget))
                return RETURN_CONTINUE;
            if (SHADOWSTEP > 0 && GetAI()->CastSpell(SHADOWSTEP, *pTarget))
                return RETURN_CONTINUE;
            if (m_bot->getRace() == RACE_BLOODELF && !pTarget->HasAura(ARCANE_TORRENT, EFFECT_INDEX_0) && GetAI()->CastSpell(ARCANE_TORRENT, *pTarget))
                return RETURN_CONTINUE;
            if (m_bot->getRace() == RACE_HUMAN && (m_bot->hasUnitState(UNIT_STAT_STUNNED) || m_bot->HasAuraType(SPELL_AURA_MOD_FEAR) || m_bot->HasAuraType(SPELL_AURA_MOD_DECREASE_SPEED) || m_bot->HasAuraType(SPELL_AURA_MOD_CHARM)) && GetAI()->CastSpell(EVERY_MAN_FOR_HIMSELF, *m_bot))
                return RETURN_CONTINUE;
            if (m_bot->getRace() == RACE_UNDEAD && (m_bot->HasAuraType(SPELL_AURA_MOD_FEAR) || m_bot->HasAuraType(SPELL_AURA_MOD_CHARM)) && GetAI()->CastSpell(WILL_OF_THE_FORSAKEN, *m_bot))
                return RETURN_CONTINUE;
            if (m_bot->getRace() == RACE_DWARF && m_bot->HasAuraState(AURA_STATE_DEADLY_POISON) && GetAI()->CastSpell(STONEFORM, *m_bot))
                return RETURN_CONTINUE;
            if (m_bot->getRace() == RACE_GNOME && (m_bot->hasUnitState(UNIT_STAT_STUNNED) || m_bot->HasAuraType(SPELL_AURA_MOD_DECREASE_SPEED)) && GetAI()->CastSpell(ESCAPE_ARTIST, *m_bot))
                return RETURN_CONTINUE;
            else if (m_bot->getRace() == RACE_ORC && !m_bot->HasAura(BLOOD_FURY, EFFECT_INDEX_0) && GetAI()->CastSpell(BLOOD_FURY, *m_bot))
                return RETURN_CONTINUE;
            else if (m_bot->getRace() == RACE_TROLL && !m_bot->HasAura(BERSERKING, EFFECT_INDEX_0) && GetAI()->CastSpell(BERSERKING, *m_bot))
                return RETURN_CONTINUE;
            break;
    }

    return RETURN_NO_ACTION_OK;
} // end DoNextCombatManeuver

CombatManeuverReturns PlayerbotRogueAI::DoNextCombatManeuverPVP(Unit* pTarget)
{
    //if (GetAI()->CastSpell(SINISTER_STRIKE))
    //    return RETURN_CONTINUE;

    return DoNextCombatManeuverPVE(pTarget); // TODO: bad idea perhaps, but better than the alternative
}

void PlayerbotRogueAI::DoNonCombatActions()
{
    if (!GetAI())  return;
    if (!m_bot) return;

    // remove stealth
    if (m_bot->HasAura(STEALTH))
        m_bot->RemoveSpellsCausingAura(SPELL_AURA_MOD_STEALTH);

    // hp check
    if (EatDrinkBandage(false))
        return;

    // Search and apply poisons to weapons
    // Mainhand ...
    Item * poison, * weapon;
    weapon = m_bot->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
    if (weapon && weapon->GetEnchantmentId(TEMP_ENCHANTMENT_SLOT) == 0)
    {
        poison = GetAI()->FindConsumable(INSTANT_POISON_DISPLAYID);
        if (!poison)
            poison = GetAI()->FindConsumable(WOUND_POISON_DISPLAYID);
        if (!poison)
            poison = GetAI()->FindConsumable(DEADLY_POISON_DISPLAYID);
        if (poison)
        {
            GetAI()->UseItem(poison, EQUIPMENT_SLOT_MAINHAND);
            GetAI()->SetIgnoreUpdateTime(5);
        }
    }
    //... and offhand
    weapon = m_bot->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);
    if (weapon && weapon->GetEnchantmentId(TEMP_ENCHANTMENT_SLOT) == 0)
    {
        poison = GetAI()->FindConsumable(DEADLY_POISON_DISPLAYID);
        if (!poison)
            poison = GetAI()->FindConsumable(WOUND_POISON_DISPLAYID);
        if (!poison)
            poison = GetAI()->FindConsumable(INSTANT_POISON_DISPLAYID);
        if (poison)
        {
            GetAI()->UseItem(poison, EQUIPMENT_SLOT_OFFHAND);
            GetAI()->SetIgnoreUpdateTime(5);
        }
    }
} // end DoNonCombatActions
