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
    // TODO: fail on non-postivie return
    PlayerbotClassAI_ClassAIInit();
}

PlayerbotRogueAI::~PlayerbotRogueAI() 
{
}


bool PlayerbotRogueAI::PlayerbotClassAI_ClassAIInit(void)
{
    SINISTER_STRIKE          = m_botdata->GetAI()->initSpell(SINISTER_STRIKE_1);
    BACKSTAB                 = m_botdata->GetAI()->initSpell(BACKSTAB_1);
    KICK                     = m_botdata->GetAI()->initSpell(KICK_1);
    FEINT                    = m_botdata->GetAI()->initSpell(FEINT_1);
    FAN_OF_KNIVES            = m_botdata->GetAI()->initSpell(FAN_OF_KNIVES_1);
    GOUGE                    = m_botdata->GetAI()->initSpell(GOUGE_1);
    SPRINT                   = m_botdata->GetAI()->initSpell(SPRINT_1);

    SHADOWSTEP               = m_botdata->GetAI()->initSpell(SHADOWSTEP_1);
    STEALTH                  = m_botdata->GetAI()->initSpell(STEALTH_1);
    VANISH                   = m_botdata->GetAI()->initSpell(VANISH_1);
    EVASION                  = m_botdata->GetAI()->initSpell(EVASION_1);
    CLOAK_OF_SHADOWS         = m_botdata->GetAI()->initSpell(CLOAK_OF_SHADOWS_1);
    HEMORRHAGE               = m_botdata->GetAI()->initSpell(HEMORRHAGE_1);
    GHOSTLY_STRIKE           = m_botdata->GetAI()->initSpell(GHOSTLY_STRIKE_1);
    SHADOW_DANCE             = m_botdata->GetAI()->initSpell(SHADOW_DANCE_1);
    BLIND                    = m_botdata->GetAI()->initSpell(BLIND_1);
    DISTRACT                 = m_botdata->GetAI()->initSpell(DISTRACT_1);
    PREPARATION              = m_botdata->GetAI()->initSpell(PREPARATION_1);
    PREMEDITATION            = m_botdata->GetAI()->initSpell(PREMEDITATION_1);
    PICK_POCKET              = m_botdata->GetAI()->initSpell(PICK_POCKET_1);

    EVISCERATE               = m_botdata->GetAI()->initSpell(EVISCERATE_1);
    KIDNEY_SHOT              = m_botdata->GetAI()->initSpell(KIDNEY_SHOT_1);
    SLICE_DICE               = m_botdata->GetAI()->initSpell(SLICE_AND_DICE_1);
    GARROTE                  = m_botdata->GetAI()->initSpell(GARROTE_1);
    EXPOSE_ARMOR             = m_botdata->GetAI()->initSpell(EXPOSE_ARMOR_1);
    RUPTURE                  = m_botdata->GetAI()->initSpell(RUPTURE_1);
    DISMANTLE                = m_botdata->GetAI()->initSpell(DISMANTLE_1);
    CHEAP_SHOT               = m_botdata->GetAI()->initSpell(CHEAP_SHOT_1);
    AMBUSH                   = m_botdata->GetAI()->initSpell(AMBUSH_1);
    MUTILATE                 = m_botdata->GetAI()->initSpell(MUTILATE_1);

    // racial
    ARCANE_TORRENT           = m_botdata->GetAI()->initSpell(ARCANE_TORRENT_ROGUE);
    STONEFORM                = m_botdata->GetAI()->initSpell(STONEFORM_ALL); // dwarf
    ESCAPE_ARTIST            = m_botdata->GetAI()->initSpell(ESCAPE_ARTIST_ALL); // gnome
    EVERY_MAN_FOR_HIMSELF    = m_botdata->GetAI()->initSpell(EVERY_MAN_FOR_HIMSELF_ALL); // human
    SHADOWMELD               = m_botdata->GetAI()->initSpell(SHADOWMELD_ALL);
    BLOOD_FURY               = m_botdata->GetAI()->initSpell(BLOOD_FURY_MELEE_CLASSES); // orc
    BERSERKING               = m_botdata->GetAI()->initSpell(BERSERKING_ALL); // troll
    WILL_OF_THE_FORSAKEN     = m_botdata->GetAI()->initSpell(WILL_OF_THE_FORSAKEN_ALL); // undead

    return PlayerbotClassAI::PlayerbotClassAI_ClassAIInit();
}


CombatManeuverReturns PlayerbotRogueAI::DoFirstCombatManeuverPVE(Unit *pTarget)
{
    if (STEALTH > 0 && !m_botdata->GetBot()->HasAura(STEALTH, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(STEALTH, *m_botdata->GetBot()))
    {
        m_botdata->GetBot()->addUnitState(UNIT_STAT_CHASE); // ensure that the bot does not use MoveChase(), as this doesn't seem to work with STEALTH
        return RETURN_FINISHED_FIRST_MOVES; // DoNextCombatManeuver handles active stealth
    }
    else if (m_botdata->GetBot()->HasAura(STEALTH, EFFECT_INDEX_0))
    {
        m_botdata->GetBot()->GetMotionMaster()->MoveFollow(pTarget, 4.5f, m_botdata->GetBot()->GetOrientation()); // TODO: this isn't the place for movement code, is it?
        return RETURN_FINISHED_FIRST_MOVES; // DoNextCombatManeuver handles active stealth
    }

    // Not in stealth, can't cast stealth; Off to DoNextCombatManeuver
    return RETURN_NO_ACTION_OK;
}

// TODO: blatant copy of PVE for now, please PVP-port it
CombatManeuverReturns PlayerbotRogueAI::DoFirstCombatManeuverPVP(Unit *pTarget)
{
    if (STEALTH > 0 && !m_botdata->GetBot()->HasAura(STEALTH, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(STEALTH, *m_botdata->GetBot()))
    {
        m_botdata->GetBot()->addUnitState(UNIT_STAT_CHASE); // ensure that the bot does not use MoveChase(), as this doesn't seem to work with STEALTH
        return RETURN_FINISHED_FIRST_MOVES; // DoNextCombatManeuver handles active stealth
    }
    else if (m_botdata->GetBot()->HasAura(STEALTH, EFFECT_INDEX_0))
    {
        m_botdata->GetBot()->GetMotionMaster()->MoveFollow(pTarget, 4.5f, m_botdata->GetBot()->GetOrientation()); // TODO: this isn't the place for movement code, is it?
        return RETURN_FINISHED_FIRST_MOVES; // DoNextCombatManeuver handles active stealth
    }

    // Not in stealth, can't cast stealth; Off to DoNextCombatManeuver
    return RETURN_NO_ACTION_OK;
}

CombatManeuverReturns PlayerbotRogueAI::DoNextCombatManeuverPVE(Unit *pTarget)
{
    if (!pTarget) return RETURN_NO_ACTION_ERROR;
    if (!m_botdata->GetAI())    return RETURN_NO_ACTION_ERROR;
    if (!m_botdata->GetBot())   return RETURN_NO_ACTION_ERROR;

    Unit* pVictim = pTarget->getVictim();
    bool meleeReach = m_botdata->GetBot()->CanReachWithMeleeAttack(pTarget);

    // TODO: make this work better...
    /*if (pVictim)
       {
        if( pVictim!=m_botdata->GetBot() && !m_botdata->GetBot()->hasUnitState(UNIT_STAT_FOLLOW) && !pTarget->isInBackInMap(m_botdata->GetBot(),10) ) {
            m_botdata->GetAI()->TellMaster( "getting behind target" );
            m_botdata->GetBot()->GetMotionMaster()->Clear( true );
            m_botdata->GetBot()->GetMotionMaster()->MoveFollow( pTarget, 1, 2*M_PI );
        }
        else if( pVictim==m_botdata->GetBot() && m_botdata->GetBot()->hasUnitState(UNIT_STAT_FOLLOW) )
        {
            m_botdata->GetAI()->TellMaster( "chasing attacking target" );
            m_botdata->GetBot()->GetMotionMaster()->Clear( true );
            m_botdata->GetBot()->GetMotionMaster()->MoveChase( pTarget );
        }
       }*/

    // Rogue like behaviour ^^
    /*if (VANISH > 0 && m_botdata->GetMaster()->isDead()) { //Causes the server to crash :( removed for now.
        m_botdata->GetBot()->AttackStop();
        m_botdata->GetBot()->RemoveAllAttackers();
        m_botdata->GetAI()->CastSpell(VANISH);
        //m_botdata->GetBot()->RemoveAllSpellCooldown();
        m_botdata->GetAI()->TellMaster("AttackStop, CombatStop, Vanish");
    }*/

    // decide what to do:
    if (pVictim == m_botdata->GetBot() && CLOAK_OF_SHADOWS > 0 && m_botdata->GetBot()->HasAura(SPELL_AURA_PERIODIC_DAMAGE) && !m_botdata->GetBot()->HasAura(CLOAK_OF_SHADOWS, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(CLOAK_OF_SHADOWS))
    {
        if (m_botdata->GetAI()->GetManager()->m_confDebugWhisper)
            m_botdata->GetAI()->TellMaster("CoS!");
        return RETURN_CONTINUE;
    }
    else if (m_botdata->GetBot()->HasAura(STEALTH, EFFECT_INDEX_0))
        SpellSequence = RogueStealth;
    else if (pTarget->IsNonMeleeSpellCasted(true))
        SpellSequence = RogueSpellPreventing;
    else if (pVictim == m_botdata->GetBot() && m_botdata->GetAI()->GetHealthPercent() < 40)
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
            if (PICK_POCKET > 0 && (pTarget->GetCreatureTypeMask() & CREATURE_TYPEMASK_HUMANOID_OR_UNDEAD) != 0 && m_botdata->GetAI()->PickPocket(pTarget))
                return RETURN_CONTINUE;
            if (PREMEDITATION > 0 && m_botdata->GetAI()->CastSpell(PREMEDITATION, *pTarget))
                return RETURN_CONTINUE;
            if (AMBUSH > 0 && m_botdata->GetAI()->CastSpell(AMBUSH, *pTarget))
                return RETURN_CONTINUE;
            if (CHEAP_SHOT > 0 && !pTarget->HasAura(CHEAP_SHOT, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(CHEAP_SHOT, *pTarget))
                return RETURN_CONTINUE;
            if (GARROTE > 0 && m_botdata->GetAI()->CastSpell(GARROTE, *pTarget))
                return RETURN_CONTINUE;

            // No appropriate action found, remove stealth
            m_botdata->GetBot()->RemoveSpellsCausingAura(SPELL_AURA_MOD_STEALTH);
            return RETURN_CONTINUE;

        case RogueThreat:
            if (GOUGE > 0 && !pTarget->HasAura(GOUGE, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(GOUGE, *pTarget))
                return RETURN_CONTINUE;
            if (EVASION > 0 && m_botdata->GetAI()->GetHealthPercent() <= 35 && !m_botdata->GetBot()->HasAura(EVASION, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(EVASION))
                return RETURN_CONTINUE;
            if (BLIND > 0 && m_botdata->GetAI()->GetHealthPercent() <= 30 && !pTarget->HasAura(BLIND, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(BLIND, *pTarget))
                return RETURN_CONTINUE;
            if (FEINT > 0 && m_botdata->GetAI()->GetHealthPercent() <= 25 && m_botdata->GetAI()->CastSpell(FEINT))
                return RETURN_CONTINUE;
            if (VANISH > 0 && m_botdata->GetAI()->GetHealthPercent() <= 20 && !m_botdata->GetBot()->HasAura(FEINT, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(VANISH))
                return RETURN_CONTINUE;
            if (PREPARATION > 0 && m_botdata->GetAI()->CastSpell(PREPARATION))
                return RETURN_CONTINUE;
            if (m_botdata->GetBot()->getRace() == RACE_NIGHTELF && m_botdata->GetAI()->GetHealthPercent() <= 15 && !m_botdata->GetBot()->HasAura(SHADOWMELD, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(SHADOWMELD, *m_botdata->GetBot()))
                return RETURN_CONTINUE;
            break;

        case RogueSpellPreventing:
            if (KIDNEY_SHOT > 0 && m_botdata->GetBot()->GetComboPoints() >= 2 && m_botdata->GetAI()->CastSpell(KIDNEY_SHOT, *pTarget))
                return RETURN_CONTINUE;
            else if (KICK > 0 && m_botdata->GetAI()->CastSpell(KICK, *pTarget))
                return RETURN_CONTINUE;
            // break; // No action? Go combat!

        case RogueCombat:
        default:
            if (m_botdata->GetBot()->GetComboPoints() >= 5)
            {
                // wait for energy
                if (m_botdata->GetAI()->GetEnergyAmount() < 25 && (KIDNEY_SHOT || SLICE_DICE || EXPOSE_ARMOR))
                    return RETURN_NO_ACTION_OK;

                switch (pTarget->getClass())
                {
                case CLASS_SHAMAN:
                    if (KIDNEY_SHOT > 0 && m_botdata->GetAI()->CastSpell(KIDNEY_SHOT, *pTarget)) // 25 energy (checked above)
                        return RETURN_CONTINUE;
                    break;

                case CLASS_WARLOCK:
                case CLASS_HUNTER:
                    if (SLICE_DICE > 0 && m_botdata->GetAI()->CastSpell(SLICE_DICE, *pTarget)) // 25 energy (checked above)
                       return RETURN_CONTINUE;
                    break;

                case CLASS_WARRIOR:
                case CLASS_PALADIN:
                case CLASS_DEATH_KNIGHT:
                    if (EXPOSE_ARMOR > 0 && !pTarget->HasAura(EXPOSE_ARMOR, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(EXPOSE_ARMOR, *pTarget)) // 25 energy (checked above)
                        return RETURN_CONTINUE;
                    break;


                case CLASS_MAGE:
                case CLASS_PRIEST:
                    if (RUPTURE > 0 && m_botdata->GetAI()->CastSpell(RUPTURE, *pTarget)) // 25 energy (checked above)
                        return RETURN_CONTINUE;
                    break;

                case CLASS_ROGUE:
                case CLASS_DRUID:
                default:
                    break; // fall through to below
                }

                // default combo action for rogue/druid or if other combo action is unavailable/failed
                // wait for energy
                if (m_botdata->GetAI()->GetEnergyAmount() < 35 && EVISCERATE)
                    return RETURN_NO_ACTION_OK;
                if (EVISCERATE > 0 && m_botdata->GetAI()->CastSpell(EVISCERATE, *pTarget))
                    return RETURN_CONTINUE;

                // failed for some (non-energy related) reason, fall through to normal attacks to maximize DPS
            }

            if (SHADOW_DANCE > 0 && !m_botdata->GetBot()->HasAura(SHADOW_DANCE, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(SHADOW_DANCE, *m_botdata->GetBot()))
                return RETURN_CONTINUE;
            if (CHEAP_SHOT > 0 && m_botdata->GetBot()->HasAura(SHADOW_DANCE, EFFECT_INDEX_0) && !pTarget->HasAura(CHEAP_SHOT, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(CHEAP_SHOT, *pTarget))
                return RETURN_CONTINUE;
            if (AMBUSH > 0 && m_botdata->GetBot()->HasAura(SHADOW_DANCE, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(AMBUSH, *pTarget))
                return RETURN_CONTINUE;
            if (GARROTE > 0 && m_botdata->GetBot()->HasAura(SHADOW_DANCE, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(GARROTE, *pTarget))
                return RETURN_CONTINUE;
            if (BACKSTAB > 0 && pTarget->isInBackInMap(m_botdata->GetBot(), 1) && m_botdata->GetAI()->CastSpell(BACKSTAB, *pTarget))
                return RETURN_CONTINUE;
            if (MUTILATE > 0 && m_botdata->GetAI()->CastSpell(MUTILATE, *pTarget))
                return RETURN_CONTINUE;
            if (SINISTER_STRIKE > 0 && m_botdata->GetAI()->CastSpell(SINISTER_STRIKE, *pTarget))
                return RETURN_CONTINUE;
            if (GHOSTLY_STRIKE > 0 && m_botdata->GetAI()->CastSpell(GHOSTLY_STRIKE, *pTarget))
                return RETURN_CONTINUE;
            if (HEMORRHAGE > 0 && m_botdata->GetAI()->CastSpell(HEMORRHAGE, *pTarget))
                return RETURN_CONTINUE;
            if (DISMANTLE > 0 && !pTarget->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISARMED) && m_botdata->GetAI()->CastSpell(DISMANTLE, *pTarget))
                return RETURN_CONTINUE;
            if (SHADOWSTEP > 0 && m_botdata->GetAI()->CastSpell(SHADOWSTEP, *pTarget))
                return RETURN_CONTINUE;
            if (m_botdata->GetBot()->getRace() == RACE_BLOODELF && !pTarget->HasAura(ARCANE_TORRENT, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(ARCANE_TORRENT, *pTarget))
                return RETURN_CONTINUE;
            if (m_botdata->GetBot()->getRace() == RACE_HUMAN && (m_botdata->GetBot()->hasUnitState(UNIT_STAT_STUNNED) || m_botdata->GetBot()->HasAuraType(SPELL_AURA_MOD_FEAR) || m_botdata->GetBot()->HasAuraType(SPELL_AURA_MOD_DECREASE_SPEED) || m_botdata->GetBot()->HasAuraType(SPELL_AURA_MOD_CHARM)) && m_botdata->GetAI()->CastSpell(EVERY_MAN_FOR_HIMSELF, *m_botdata->GetBot()))
                return RETURN_CONTINUE;
            if (m_botdata->GetBot()->getRace() == RACE_UNDEAD && (m_botdata->GetBot()->HasAuraType(SPELL_AURA_MOD_FEAR) || m_botdata->GetBot()->HasAuraType(SPELL_AURA_MOD_CHARM)) && m_botdata->GetAI()->CastSpell(WILL_OF_THE_FORSAKEN, *m_botdata->GetBot()))
                return RETURN_CONTINUE;
            if (m_botdata->GetBot()->getRace() == RACE_DWARF && m_botdata->GetBot()->HasAuraState(AURA_STATE_DEADLY_POISON) && m_botdata->GetAI()->CastSpell(STONEFORM, *m_botdata->GetBot()))
                return RETURN_CONTINUE;
            if (m_botdata->GetBot()->getRace() == RACE_GNOME && (m_botdata->GetBot()->hasUnitState(UNIT_STAT_STUNNED) || m_botdata->GetBot()->HasAuraType(SPELL_AURA_MOD_DECREASE_SPEED)) && m_botdata->GetAI()->CastSpell(ESCAPE_ARTIST, *m_botdata->GetBot()))
                return RETURN_CONTINUE;
            else if (m_botdata->GetBot()->getRace() == RACE_ORC && !m_botdata->GetBot()->HasAura(BLOOD_FURY, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(BLOOD_FURY, *m_botdata->GetBot()))
                return RETURN_CONTINUE;
            else if (m_botdata->GetBot()->getRace() == RACE_TROLL && !m_botdata->GetBot()->HasAura(BERSERKING, EFFECT_INDEX_0) && m_botdata->GetAI()->CastSpell(BERSERKING, *m_botdata->GetBot()))
                return RETURN_CONTINUE;
            break;
    }

    return RETURN_NO_ACTION_OK;
} // end DoNextCombatManeuver

CombatManeuverReturns PlayerbotRogueAI::DoNextCombatManeuverPVP(Unit* pTarget)
{
    //if (m_botdata->GetAI()->CastSpell(SINISTER_STRIKE))
    //    return RETURN_CONTINUE;

    return DoNextCombatManeuverPVE(pTarget); // TODO: bad idea perhaps, but better than the alternative
}

void PlayerbotRogueAI::DoNonCombatActions()
{
    if (!m_botdata->GetAI())  return;
    if (!m_botdata->GetBot()) return;

    // remove stealth
    if (m_botdata->GetBot()->HasAura(STEALTH))
        m_botdata->GetBot()->RemoveSpellsCausingAura(SPELL_AURA_MOD_STEALTH);

    // hp check
    if (EatDrinkBandage(false))
        return;

    // Search and apply poisons to weapons
    // Mainhand ...
    Item * poison, * weapon;
    weapon = m_botdata->GetBot()->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
    if (weapon && weapon->GetEnchantmentId(TEMP_ENCHANTMENT_SLOT) == 0)
    {
        poison = m_botdata->GetAI()->FindConsumable(INSTANT_POISON_DISPLAYID);
        if (!poison)
            poison = m_botdata->GetAI()->FindConsumable(WOUND_POISON_DISPLAYID);
        if (!poison)
            poison = m_botdata->GetAI()->FindConsumable(DEADLY_POISON_DISPLAYID);
        if (poison)
        {
            m_botdata->GetAI()->UseItem(poison, EQUIPMENT_SLOT_MAINHAND);
            m_botdata->GetAI()->SetIgnoreUpdateTime(5);
        }
    }
    //... and offhand
    weapon = m_botdata->GetBot()->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);
    if (weapon && weapon->GetEnchantmentId(TEMP_ENCHANTMENT_SLOT) == 0)
    {
        poison = m_botdata->GetAI()->FindConsumable(DEADLY_POISON_DISPLAYID);
        if (!poison)
            poison = m_botdata->GetAI()->FindConsumable(WOUND_POISON_DISPLAYID);
        if (!poison)
            poison = m_botdata->GetAI()->FindConsumable(INSTANT_POISON_DISPLAYID);
        if (poison)
        {
            m_botdata->GetAI()->UseItem(poison, EQUIPMENT_SLOT_OFFHAND);
            m_botdata->GetAI()->SetIgnoreUpdateTime(5);
        }
    }
} // end DoNonCombatActions
