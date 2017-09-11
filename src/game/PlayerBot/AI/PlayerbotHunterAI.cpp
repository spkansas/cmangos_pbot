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

#include "PlayerbotHunterAI.h"
#include "../Base/PlayerbotMgr.h"
#include "../../Spells/SpellAuras.h"

class PlayerbotAI;

PlayerbotHunterAI::PlayerbotHunterAI(Player* const master, Player* const bot, PlayerbotAI* const ai) : PlayerbotClassAI(master, bot, ai)
{
    // PET CTRL
    PET_SUMMON                    = GetAI()->initSpell(CALL_PET_1);
    PET_DISMISS                   = GetAI()->initSpell(DISMISS_PET_1);
    PET_REVIVE                    = GetAI()->initSpell(REVIVE_PET_1);
    PET_MEND                      = GetAI()->initSpell(MEND_PET_1);
    PET_FEED                      = 1539;

    INTIMIDATION                  = GetAI()->initSpell(INTIMIDATION_1); // (generic)

    // PET SKILLS must be initialized by pets
    SONIC_BLAST                   = 0; // bat
    DEMORALIZING_SCREECH          = 0;
    BAD_ATTITUDE                  = 0; // crocolisk
    NETHER_SHOCK                  = 0;

    // RANGED COMBAT
    AUTO_SHOT                     = GetAI()->initSpell(AUTO_SHOT_1);
    HUNTERS_MARK                  = GetAI()->initSpell(HUNTERS_MARK_1);
    ARCANE_SHOT                   = GetAI()->initSpell(ARCANE_SHOT_1);
    CONCUSSIVE_SHOT               = GetAI()->initSpell(CONCUSSIVE_SHOT_1);
    DISTRACTING_SHOT              = GetAI()->initSpell(DISTRACTING_SHOT_1);
    MULTI_SHOT                    = GetAI()->initSpell(MULTISHOT_1);
    EXPLOSIVE_SHOT                = GetAI()->initSpell(EXPLOSIVE_SHOT_1);
    SERPENT_STING                 = GetAI()->initSpell(SERPENT_STING_1);
    SCORPID_STING                 = GetAI()->initSpell(SCORPID_STING_1);
    WYVERN_STING                  = GetAI()->initSpell(WYVERN_STING_1);
    VIPER_STING                   = GetAI()->initSpell(VIPER_STING_1);
    AIMED_SHOT                    = GetAI()->initSpell(AIMED_SHOT_1);
    STEADY_SHOT                   = GetAI()->initSpell(STEADY_SHOT_1);
    CHIMERA_SHOT                  = GetAI()->initSpell(CHIMERA_SHOT_1);
    VOLLEY                        = GetAI()->initSpell(VOLLEY_1);
    BLACK_ARROW                   = GetAI()->initSpell(BLACK_ARROW_1);
    KILL_SHOT                     = GetAI()->initSpell(KILL_SHOT_1);

    // MELEE
    RAPTOR_STRIKE                 = GetAI()->initSpell(RAPTOR_STRIKE_1);
    WING_CLIP                     = GetAI()->initSpell(WING_CLIP_1);
    MONGOOSE_BITE                 = GetAI()->initSpell(MONGOOSE_BITE_1);
    DISENGAGE                     = GetAI()->initSpell(DISENGAGE_1);
    MISDIRECTION                  = GetAI()->initSpell(MISDIRECTION_1);
    DETERRENCE                    = GetAI()->initSpell(DETERRENCE_1);

    // TRAPS
    BEAR_TRAP                     = 0; // non-player spell
    FREEZING_TRAP                 = GetAI()->initSpell(FREEZING_TRAP_1);
    IMMOLATION_TRAP               = GetAI()->initSpell(IMMOLATION_TRAP_1);
    FROST_TRAP                    = GetAI()->initSpell(FROST_TRAP_1);
    EXPLOSIVE_TRAP                = GetAI()->initSpell(EXPLOSIVE_TRAP_1);
    ARCANE_TRAP                   = 0; // non-player spell
    SNAKE_TRAP                    = GetAI()->initSpell(SNAKE_TRAP_1);

    // BUFFS
    ASPECT_OF_THE_HAWK            = GetAI()->initSpell(ASPECT_OF_THE_HAWK_1);
    ASPECT_OF_THE_MONKEY          = GetAI()->initSpell(ASPECT_OF_THE_MONKEY_1);
    RAPID_FIRE                    = GetAI()->initSpell(RAPID_FIRE_1);
    TRUESHOT_AURA                 = GetAI()->initSpell(TRUESHOT_AURA_1);

    RECENTLY_BANDAGED             = 11196; // first aid check

    // racial
    ARCANE_TORRENT                = GetAI()->initSpell(ARCANE_TORRENT_MANA_CLASSES);
    GIFT_OF_THE_NAARU             = GetAI()->initSpell(GIFT_OF_THE_NAARU_HUNTER); // draenei
    STONEFORM                     = GetAI()->initSpell(STONEFORM_ALL); // dwarf
    SHADOWMELD                    = GetAI()->initSpell(SHADOWMELD_ALL);
    BLOOD_FURY                    = GetAI()->initSpell(BLOOD_FURY_MELEE_CLASSES); // orc
    WAR_STOMP                     = GetAI()->initSpell(WAR_STOMP_ALL); // tauren
    BERSERKING                    = GetAI()->initSpell(BERSERKING_ALL); // troll

    m_petSummonFailed = false;
    m_rangedCombat = true;
}

PlayerbotHunterAI::~PlayerbotHunterAI() {}

CombatManeuverReturns PlayerbotHunterAI::DoManeuver_Combat_Start_Class_Prep(Unit* pTarget)
{
	m_has_ammo = m_bot->HasItemCount(m_bot->GetUInt32Value(PLAYER_AMMO_ID), 1);
	//DEBUG_LOG("current ammo (%u)",m_bot->GetUInt32Value(PLAYER_AMMO_ID));

	m_bot->setAttackTimer(RANGED_ATTACK, 0);

	if (!m_has_ammo)
	{
		GetAI()->FindAmmo();
		//DEBUG_LOG("new ammo (%u)",m_bot->GetUInt32Value(PLAYER_AMMO_ID));
		m_has_ammo = m_bot->HasItemCount(m_bot->GetUInt32Value(PLAYER_AMMO_ID), 1);
	}

	return RETURN_CONTINUE;
}

CombatManeuverReturns PlayerbotHunterAI::DoFirstCombatManeuverPVE(Unit* /*pTarget*/)
{
    return RETURN_NO_ACTION_OK;
}

CombatManeuverReturns PlayerbotHunterAI::DoFirstCombatManeuverPVP(Unit* /*pTarget*/)
{
    return RETURN_NO_ACTION_OK;
}

CombatManeuverReturns PlayerbotHunterAI::DoNextCombatManeuverPVE(Unit *pTarget)
{
    if (!GetAI())    return RETURN_NO_ACTION_ERROR;
    if (!m_bot)   return RETURN_NO_ACTION_ERROR;
    if (!pTarget) return RETURN_NO_ACTION_ERROR;

    Unit* pVictim = pTarget->getVictim();

    // check for pet and heal if neccessary
    Pet *pet = m_bot->GetPet();
    // TODO: clarify/simplify: !pet->getDeathState() != ALIVE
    if (pet && PET_MEND > 0 && pet->isAlive() && pet->GetHealthPercent() < 50 && pVictim != m_bot && !pet->HasAura(PET_MEND, EFFECT_INDEX_0) && GetAI()->CastSpell(PET_MEND, *m_bot))
    {
        GetAI()->TellMaster("healing pet.");
        return RETURN_CONTINUE;
    }
    else if (pet && INTIMIDATION > 0 && pVictim == pet && !pet->HasAura(INTIMIDATION, EFFECT_INDEX_0) && GetAI()->CastSpell(INTIMIDATION, *m_bot))
        return RETURN_CONTINUE;

    // racial traits
    if (m_bot->getRace() == RACE_ORC && !m_bot->HasAura(BLOOD_FURY, EFFECT_INDEX_0))
        GetAI()->CastSpell(BLOOD_FURY, *m_bot);
    else if (m_bot->getRace() == RACE_TROLL && !m_bot->HasAura(BERSERKING, EFFECT_INDEX_0))
        GetAI()->CastSpell(BERSERKING, *m_bot);

    // check if ranged combat is possible
    bool meleeReach = m_bot->CanReachWithMeleeAttack(pTarget);

    if (meleeReach || !m_has_ammo)
    {
        // switch to melee combat (target in melee range, out of ammo)
        m_rangedCombat = false;
        GetAI()->SetCombatStyle(PlayerbotAI::COMBAT_MELEE);
        if (!m_bot->GetUInt32Value(PLAYER_AMMO_ID))
            GetAI()->TellMaster("Out of ammo!");

        // become monkey (increases dodge chance)...
        if (ASPECT_OF_THE_MONKEY > 0 && !m_bot->HasAura(ASPECT_OF_THE_MONKEY, EFFECT_INDEX_0))
            GetAI()->CastSpell(ASPECT_OF_THE_MONKEY, *m_bot);

    }
    else if (!meleeReach)
    {
        // switch to ranged combat
        m_rangedCombat = true;
        GetAI()->SetCombatStyle(PlayerbotAI::COMBAT_RANGED);

        // increase ranged attack power...
        if (ASPECT_OF_THE_HAWK > 0 && !m_bot->HasAura(ASPECT_OF_THE_HAWK, EFFECT_INDEX_0))
            GetAI()->CastSpell(ASPECT_OF_THE_HAWK, *m_bot);

        // GetAI()->TellMaster("target dist %f",m_bot->GetCombatDistance(pTarget,true));
        if (AUTO_SHOT > 0)
        {
            if (m_bot->isAttackReady(RANGED_ATTACK))
                m_bot->CastSpell(pTarget, AUTO_SHOT, TRIGGERED_OLD_TRIGGERED);

            m_bot->setAttackTimer(RANGED_ATTACK,500);

            const SpellEntry* spellInfo = sSpellTemplate.LookupEntry<SpellEntry>(AUTO_SHOT);
            if (!spellInfo)
                return RETURN_CONTINUE;

            if (!GetAI()->CheckBotCast(spellInfo))
                m_bot->InterruptNonMeleeSpells(true, AUTO_SHOT);
        }
    }

    // damage spells
    if (GetAI()->GetCombatStyle() == PlayerbotAI::COMBAT_RANGED)
    {
        if (HUNTERS_MARK > 0 && GetAI()->In_Reach(pTarget,HUNTERS_MARK) && !pTarget->HasAura(HUNTERS_MARK, EFFECT_INDEX_0) && GetAI()->CastSpell(HUNTERS_MARK, *pTarget))
            return RETURN_CONTINUE;
        else if (RAPID_FIRE > 0 && GetAI()->In_Reach(pTarget,RAPID_FIRE) && !m_bot->HasAura(RAPID_FIRE, EFFECT_INDEX_0) && GetAI()->CastSpell(RAPID_FIRE, *m_bot))
            return RETURN_CONTINUE;
        else if (MULTI_SHOT > 0 && GetAI()->In_Reach(pTarget,MULTI_SHOT) && GetAI()->GetAttackerCount() >= 3 && GetAI()->CastSpell(MULTI_SHOT, *pTarget))
            return RETURN_CONTINUE;
        else if (ARCANE_SHOT > 0 && GetAI()->In_Reach(pTarget,ARCANE_SHOT) && GetAI()->CastSpell(ARCANE_SHOT, *pTarget))
            return RETURN_CONTINUE;
        else if (CONCUSSIVE_SHOT > 0 && GetAI()->In_Reach(pTarget,CONCUSSIVE_SHOT) && !pTarget->HasAura(CONCUSSIVE_SHOT, EFFECT_INDEX_0) && GetAI()->CastSpell(CONCUSSIVE_SHOT, *pTarget))
            return RETURN_CONTINUE;
        else if (EXPLOSIVE_SHOT > 0 && GetAI()->In_Reach(pTarget,EXPLOSIVE_SHOT) && !pTarget->HasAura(EXPLOSIVE_SHOT, EFFECT_INDEX_0) && GetAI()->CastSpell(EXPLOSIVE_SHOT, *pTarget))
            return RETURN_CONTINUE;
        else if (VIPER_STING > 0 && GetAI()->In_Reach(pTarget,VIPER_STING) && pTarget->GetPower(POWER_MANA) > 0 && GetAI()->GetManaPercent() < 70 && !pTarget->HasAura(VIPER_STING, EFFECT_INDEX_0) && GetAI()->CastSpell(VIPER_STING, *pTarget))
            return RETURN_CONTINUE;
        else if (SERPENT_STING > 0 && GetAI()->In_Reach(pTarget,SERPENT_STING) && !pTarget->HasAura(SERPENT_STING, EFFECT_INDEX_0) && !pTarget->HasAura(SCORPID_STING, EFFECT_INDEX_0) &&  !pTarget->HasAura(VIPER_STING, EFFECT_INDEX_0) && GetAI()->CastSpell(SERPENT_STING, *pTarget))
            return RETURN_CONTINUE;
        else if (SCORPID_STING > 0 && GetAI()->In_Reach(pTarget,SCORPID_STING) && !pTarget->HasAura(WYVERN_STING, EFFECT_INDEX_0) && !pTarget->HasAura(SCORPID_STING, EFFECT_INDEX_0) && !pTarget->HasAura(SERPENT_STING, EFFECT_INDEX_0) && !pTarget->HasAura(VIPER_STING, EFFECT_INDEX_0) && GetAI()->CastSpell(SCORPID_STING, *pTarget))
            return RETURN_CONTINUE;
        else if (CHIMERA_SHOT > 0 && GetAI()->In_Reach(pTarget,CHIMERA_SHOT) && GetAI()->CastSpell(CHIMERA_SHOT, *pTarget))
            return RETURN_CONTINUE;
        else if (VOLLEY > 0 && GetAI()->In_Reach(pTarget,VOLLEY) && GetAI()->GetAttackerCount() >= 3 && GetAI()->CastSpell(VOLLEY, *pTarget))
            return RETURN_CONTINUE;
        else if (BLACK_ARROW > 0 && GetAI()->In_Reach(pTarget,BLACK_ARROW) && !pTarget->HasAura(BLACK_ARROW, EFFECT_INDEX_0) && GetAI()->CastSpell(BLACK_ARROW, *pTarget))
            return RETURN_CONTINUE;
        else if (AIMED_SHOT > 0 && GetAI()->In_Reach(pTarget,AIMED_SHOT) && GetAI()->CastSpell(AIMED_SHOT, *pTarget))
            return RETURN_CONTINUE;
        else if (STEADY_SHOT > 0 && GetAI()->In_Reach(pTarget,STEADY_SHOT) && GetAI()->CastSpell(STEADY_SHOT, *pTarget))
            return RETURN_CONTINUE;
        else if (KILL_SHOT > 0 && GetAI()->In_Reach(pTarget,KILL_SHOT) && pTarget->GetHealthPercent() < 20 && GetAI()->CastSpell(KILL_SHOT, *pTarget))
            return RETURN_CONTINUE;
        else
            return RETURN_NO_ACTION_OK;
    }
    else
    {
        if (RAPTOR_STRIKE > 0 && GetAI()->In_Reach(pTarget,RAPTOR_STRIKE) && GetAI()->CastSpell(RAPTOR_STRIKE, *pTarget))
            return RETURN_CONTINUE;
        else if (EXPLOSIVE_TRAP > 0 && !pTarget->HasAura(EXPLOSIVE_TRAP, EFFECT_INDEX_0) && !pTarget->HasAura(ARCANE_TRAP, EFFECT_INDEX_0) && !pTarget->HasAura(IMMOLATION_TRAP, EFFECT_INDEX_0) && !pTarget->HasAura(FROST_TRAP, EFFECT_INDEX_0) && !pTarget->HasAura(BEAR_TRAP, EFFECT_INDEX_0) && GetAI()->CastSpell(EXPLOSIVE_TRAP, *pTarget))
            return RETURN_CONTINUE;
        else if (WING_CLIP > 0 && GetAI()->In_Reach(pTarget,WING_CLIP) && !pTarget->HasAura(WING_CLIP, EFFECT_INDEX_0) && GetAI()->CastSpell(WING_CLIP, *pTarget))
            return RETURN_CONTINUE;
        else if (IMMOLATION_TRAP > 0 && !pTarget->HasAura(IMMOLATION_TRAP, EFFECT_INDEX_0) && !pTarget->HasAura(ARCANE_TRAP, EFFECT_INDEX_0) && !pTarget->HasAura(EXPLOSIVE_TRAP, EFFECT_INDEX_0) && !pTarget->HasAura(FROST_TRAP, EFFECT_INDEX_0) && !pTarget->HasAura(BEAR_TRAP, EFFECT_INDEX_0) && GetAI()->CastSpell(IMMOLATION_TRAP, *pTarget))
            return RETURN_CONTINUE;
        else if (MONGOOSE_BITE > 0 && GetAI()->Impulse() && GetAI()->CastSpell(MONGOOSE_BITE, *pTarget))
            return RETURN_CONTINUE;
        else if (FROST_TRAP > 0 && !pTarget->HasAura(FROST_TRAP, EFFECT_INDEX_0) && !pTarget->HasAura(ARCANE_TRAP, EFFECT_INDEX_0) && !pTarget->HasAura(IMMOLATION_TRAP, EFFECT_INDEX_0) && !pTarget->HasAura(EXPLOSIVE_TRAP, EFFECT_INDEX_0) && !pTarget->HasAura(BEAR_TRAP, EFFECT_INDEX_0) && GetAI()->CastSpell(FROST_TRAP, *pTarget))
            return RETURN_CONTINUE;
        else if (ARCANE_TRAP > 0 && !pTarget->HasAura(ARCANE_TRAP, EFFECT_INDEX_0) && !pTarget->HasAura(BEAR_TRAP, EFFECT_INDEX_0) && !pTarget->HasAura(EXPLOSIVE_TRAP, EFFECT_INDEX_0) && !pTarget->HasAura(IMMOLATION_TRAP, EFFECT_INDEX_0) && !pTarget->HasAura(FROST_TRAP, EFFECT_INDEX_0) && GetAI()->CastSpell(ARCANE_TRAP, *pTarget))
            return RETURN_CONTINUE;
        else if (DETERRENCE > 0 && pVictim == m_bot && m_bot->GetHealthPercent() < 50 && !m_bot->HasAura(DETERRENCE, EFFECT_INDEX_0) && GetAI()->CastSpell(DETERRENCE, *m_bot))
            return RETURN_CONTINUE;
        else if (m_bot->getRace() == RACE_TAUREN && !pTarget->HasAura(WAR_STOMP, EFFECT_INDEX_0) && GetAI()->CastSpell(WAR_STOMP, *pTarget))
            return RETURN_CONTINUE;
        else if (m_bot->getRace() == RACE_BLOODELF && !pTarget->HasAura(ARCANE_TORRENT, EFFECT_INDEX_0) && GetAI()->CastSpell(ARCANE_TORRENT, *pTarget))
            return RETURN_CONTINUE;
        else if (m_bot->getRace() == RACE_DWARF && m_bot->HasAuraState(AURA_STATE_DEADLY_POISON) && GetAI()->CastSpell(STONEFORM, *m_bot))
            return RETURN_CONTINUE;
        else if (m_bot->getRace() == RACE_NIGHTELF && pVictim == m_bot && GetAI()->GetHealthPercent() < 25 && !m_bot->HasAura(SHADOWMELD, EFFECT_INDEX_0) && GetAI()->CastSpell(SHADOWMELD, *m_bot))
            return RETURN_CONTINUE;
        else if (m_bot->getRace() == RACE_DRAENEI && GetAI()->GetHealthPercent() < 25 && !m_bot->HasAura(GIFT_OF_THE_NAARU, EFFECT_INDEX_0) && GetAI()->CastSpell(GIFT_OF_THE_NAARU, *m_bot))
            return RETURN_CONTINUE;
        else if (pet && pet->isAlive() && MISDIRECTION > 0 && GetAI()->In_Reach(pet,MISDIRECTION) && pVictim == m_bot && !m_bot->HasAura(MISDIRECTION, EFFECT_INDEX_0) && GetAI()->CastSpell(MISDIRECTION, *pet))
            return RETURN_CONTINUE;
        /*else if(FREEZING_TRAP > 0 && !pTarget->HasAura(FREEZING_TRAP, EFFECT_INDEX_0) && !pTarget->HasAura(ARCANE_TRAP, EFFECT_INDEX_0) && !pTarget->HasAura(EXPLOSIVE_TRAP, EFFECT_INDEX_0) && !pTarget->HasAura(BEAR_TRAP, EFFECT_INDEX_0) && !pTarget->HasAura(IMMOLATION_TRAP, EFFECT_INDEX_0) && !pTarget->HasAura(FROST_TRAP, EFFECT_INDEX_0) && GetAI()->CastSpell(FREEZING_TRAP,*pTarget) )
            out << " > Freezing Trap"; // this can trap your bots too
           else if(BEAR_TRAP > 0 && !pTarget->HasAura(BEAR_TRAP, EFFECT_INDEX_0) && !pTarget->HasAura(ARCANE_TRAP, EFFECT_INDEX_0) && !pTarget->HasAura(EXPLOSIVE_TRAP, EFFECT_INDEX_0) && !pTarget->HasAura(IMMOLATION_TRAP, EFFECT_INDEX_0) && !pTarget->HasAura(FROST_TRAP, EFFECT_INDEX_0) && GetAI()->CastSpell(BEAR_TRAP,*pTarget) )
            out << " > Bear Trap"; // this was just too annoying :)
           else if(DISENGAGE > 0 && pVictim && GetAI()->CastSpell(DISENGAGE,*pTarget) )
            out << " > Disengage!"; // attempt to return to ranged combat*/
    }

    return RETURN_NO_ACTION_OK;
} // end DoNextCombatManeuver

CombatManeuverReturns PlayerbotHunterAI::DoNextCombatManeuverPVP(Unit* pTarget)
{
    if (GetAI()->CastSpell(RAPTOR_STRIKE))
        return RETURN_CONTINUE;

    return DoNextCombatManeuverPVE(pTarget); // TODO: bad idea perhaps, but better than the alternative
}

bool PlayerbotHunterAI::IsTargetEnraged(Unit* pTarget)
{
    if (!GetAI())  return false;
    if (!m_bot) return false;
    if (!pTarget) return false;

    Unit::SpellAuraHolderMap const& auras = pTarget->GetSpellAuraHolderMap();
    for (Unit::SpellAuraHolderMap::const_iterator itr = auras.begin(); itr != auras.end(); ++itr)
    {
        SpellAuraHolder *holder = itr->second;
        // Return true is target unit has aura with DISPEL_ENRAGE dispel type
        if ((1 << holder->GetSpellProto()->Dispel) & GetDispellMask(DISPEL_ENRAGE))
            return true;
    }

    return false;
}

void PlayerbotHunterAI::DoNonCombatActions()
{
    if (!GetAI())  return;
    if (!m_bot) return;

    if (!m_rangedCombat || GetAI()->GetCombatStyle() == PlayerbotAI::COMBAT_MELEE)
    {
        m_rangedCombat = true;
        GetAI()->SetCombatStyle(PlayerbotAI::COMBAT_RANGED);
    }

    // buff group
    if (TRUESHOT_AURA > 0 && !m_bot->HasAura(TRUESHOT_AURA, EFFECT_INDEX_0))
        GetAI()->CastSpell(TRUESHOT_AURA, *m_bot);

    // buff myself
    if (ASPECT_OF_THE_HAWK > 0 && !m_bot->HasAura(ASPECT_OF_THE_HAWK, EFFECT_INDEX_0))
        GetAI()->CastSpell(ASPECT_OF_THE_HAWK, *m_bot);

    // hp/mana check
    if (EatDrinkBandage())
        return;

    if (m_bot->getRace() == RACE_DRAENEI && !m_bot->HasAura(GIFT_OF_THE_NAARU, EFFECT_INDEX_0) && GetAI()->GetHealthPercent() < 70)
    {
        GetAI()->TellMaster("I'm casting gift of the naaru.");
        GetAI()->CastSpell(GIFT_OF_THE_NAARU, *m_bot);
        return;
    }

    // check for pet
    if (PET_SUMMON > 0 && !m_petSummonFailed && m_bot->GetPetGuid())
    {
        // we can summon pet, and no critical summon errors before
        Pet *pet = m_bot->GetPet();
        if (!pet)
        {
            // summon pet
            if (PET_SUMMON > 0 && GetAI()->CastSpell(PET_SUMMON, *m_bot))
                GetAI()->TellMaster("summoning pet.");
            else
            {
                m_petSummonFailed = true;
                GetAI()->TellMaster("summon pet failed!");
            }
        }
        else if (!(pet->isAlive()))
        {
            if (PET_REVIVE > 0 && GetAI()->CastSpell(PET_REVIVE, *m_bot))
                GetAI()->TellMaster("reviving pet.");
        }
        else if (pet->GetHealthPercent() < 50)
        {
            if (PET_MEND > 0 && pet->isAlive() && !pet->HasAura(PET_MEND, EFFECT_INDEX_0) && GetAI()->CastSpell(PET_MEND, *m_bot))
                GetAI()->TellMaster("healing pet.");
        }
        else if (pet->GetHappinessState() != HAPPY) // if pet is hungry
        {
            Unit *caster = (Unit *) m_bot;
            // list out items in main backpack
            for (uint8 slot = INVENTORY_SLOT_ITEM_START; slot < INVENTORY_SLOT_ITEM_END; slot++)
            {
                Item* const pItem = m_bot->GetItemByPos(INVENTORY_SLOT_BAG_0, slot);
                if (pItem)
                {
                    const ItemPrototype* const pItemProto = pItem->GetProto();
                    if (!pItemProto)
                        continue;

                    if (pet->HaveInDiet(pItemProto)) // is pItem in pets diet
                    {
                        // DEBUG_LOG ("[PlayerbotHunterAI]: DoNonCombatActions - Food for pet: %s",pItemProto->Name1);
                        caster->CastSpell(caster, 51284, TRIGGERED_OLD_TRIGGERED); // pet feed visual
                        uint32 count = 1; // number of items used
                        int32 benefit = pet->GetCurrentFoodBenefitLevel(pItemProto->ItemLevel); // nutritional value of food
                        m_bot->DestroyItemCount(pItem, count, true); // remove item from inventory
                        m_bot->CastCustomSpell(m_bot, PET_FEED, &benefit, nullptr, nullptr, TRIGGERED_OLD_TRIGGERED); // feed pet
                        GetAI()->TellMaster("feeding pet.");
                        GetAI()->SetIgnoreUpdateTime(10);
                        return;
                    }
                }
            }
            // list out items in other removable backpacks
            for (uint8 bag = INVENTORY_SLOT_BAG_START; bag < INVENTORY_SLOT_BAG_END; ++bag)
            {
                const Bag* const pBag = (Bag *) m_bot->GetItemByPos(INVENTORY_SLOT_BAG_0, bag);
                if (pBag)
                    for (uint8 slot = 0; slot < pBag->GetBagSize(); ++slot)
                    {
                        Item* const pItem = m_bot->GetItemByPos(bag, slot);
                        if (pItem)
                        {
                            const ItemPrototype* const pItemProto = pItem->GetProto();
                            if (!pItemProto)
                                continue;

                            if (pet->HaveInDiet(pItemProto)) // is pItem in pets diet
                            {
                                // DEBUG_LOG ("[PlayerbotHunterAI]: DoNonCombatActions - Food for pet: %s",pItemProto->Name1);
                                caster->CastSpell(caster, 51284, TRIGGERED_OLD_TRIGGERED); // pet feed visual
                                uint32 count = 1; // number of items used
                                int32 benefit = pet->GetCurrentFoodBenefitLevel(pItemProto->ItemLevel); // nutritional value of food
                                m_bot->DestroyItemCount(pItem, count, true); // remove item from inventory
                                m_bot->CastCustomSpell(m_bot, PET_FEED, &benefit, nullptr, nullptr, TRIGGERED_OLD_TRIGGERED); // feed pet
                                GetAI()->TellMaster("feeding pet.");
                                GetAI()->SetIgnoreUpdateTime(10);
                                return;
                            }
                        }
                    }
            }
            if (pet->HasAura(PET_MEND, EFFECT_INDEX_0) && !pet->HasAura(PET_FEED, EFFECT_INDEX_0))
                GetAI()->TellMaster("..no pet food!");
            GetAI()->SetIgnoreUpdateTime(7);
        }
    }
} // end DoNonCombatActions
