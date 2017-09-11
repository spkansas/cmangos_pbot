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

#include "PlayerbotPriestAI.h"

class PlayerbotAI;

PlayerbotPriestAI::PlayerbotPriestAI(Player* const master, Player* const bot, PlayerbotAI* const ai) : PlayerbotClassAI(master, bot, ai)
{
    RENEW                         = GetAI()->initSpell(RENEW_1);
    LESSER_HEAL                   = GetAI()->initSpell(LESSER_HEAL_1);
    FLASH_HEAL                    = GetAI()->initSpell(FLASH_HEAL_1);
    (FLASH_HEAL > 0) ? FLASH_HEAL : FLASH_HEAL = LESSER_HEAL;
    HEAL                          = GetAI()->initSpell(HEAL_1);
    (HEAL > 0) ? HEAL : HEAL = FLASH_HEAL;
    GREATER_HEAL                  = GetAI()->initSpell(GREATER_HEAL_1);
    (GREATER_HEAL > 0) ? GREATER_HEAL : GREATER_HEAL = HEAL;
    RESURRECTION                  = GetAI()->initSpell(RESURRECTION_1);
    SMITE                         = GetAI()->initSpell(SMITE_1);
    MANA_BURN                     = GetAI()->initSpell(MANA_BURN_1);
    HOLY_NOVA                     = GetAI()->initSpell(HOLY_NOVA_1);
    HOLY_FIRE                     = GetAI()->initSpell(HOLY_FIRE_1);
    DESPERATE_PRAYER              = GetAI()->initSpell(DESPERATE_PRAYER_1);
    PRAYER_OF_HEALING             = GetAI()->initSpell(PRAYER_OF_HEALING_1);
    CIRCLE_OF_HEALING             = GetAI()->initSpell(CIRCLE_OF_HEALING_1);
    BINDING_HEAL                  = GetAI()->initSpell(BINDING_HEAL_1);
    PRAYER_OF_MENDING             = GetAI()->initSpell(PRAYER_OF_MENDING_1);
    CURE_DISEASE                  = GetAI()->initSpell(CURE_DISEASE_1);

    // SHADOW
    FADE                          = GetAI()->initSpell(FADE_1);
    SHADOW_WORD_PAIN              = GetAI()->initSpell(SHADOW_WORD_PAIN_1);
    MIND_BLAST                    = GetAI()->initSpell(MIND_BLAST_1);
    SCREAM                        = GetAI()->initSpell(PSYCHIC_SCREAM_1);
    MIND_FLAY                     = GetAI()->initSpell(MIND_FLAY_1);
    DEVOURING_PLAGUE              = GetAI()->initSpell(DEVOURING_PLAGUE_1);
    SHADOW_PROTECTION             = GetAI()->initSpell(SHADOW_PROTECTION_1);
    VAMPIRIC_TOUCH                = GetAI()->initSpell(VAMPIRIC_TOUCH_1);
    PRAYER_OF_SHADOW_PROTECTION   = GetAI()->initSpell(PRAYER_OF_SHADOW_PROTECTION_1);
    SHADOWFIEND                   = GetAI()->initSpell(SHADOWFIEND_1);
    MIND_SEAR                     = GetAI()->initSpell(MIND_SEAR_1);
    SHADOWFORM                    = GetAI()->initSpell(SHADOWFORM_1);
    VAMPIRIC_EMBRACE              = GetAI()->initSpell(VAMPIRIC_EMBRACE_1);

    // RANGED COMBAT
    SHOOT                         = GetAI()->initSpell(SHOOT_1);

    // DISCIPLINE
    PENANCE                       = GetAI()->initSpell(PENANCE_1);
    INNER_FIRE                    = GetAI()->initSpell(INNER_FIRE_1);
    POWER_WORD_SHIELD             = GetAI()->initSpell(POWER_WORD_SHIELD_1);
    POWER_WORD_FORTITUDE          = GetAI()->initSpell(POWER_WORD_FORTITUDE_1);
    PRAYER_OF_FORTITUDE           = GetAI()->initSpell(PRAYER_OF_FORTITUDE_1);
    FEAR_WARD                     = GetAI()->initSpell(FEAR_WARD_1);
    DIVINE_SPIRIT                 = GetAI()->initSpell(DIVINE_SPIRIT_1);
    PRAYER_OF_SPIRIT              = GetAI()->initSpell(PRAYER_OF_SPIRIT_1);
    MASS_DISPEL                   = GetAI()->initSpell(MASS_DISPEL_1);
    POWER_INFUSION                = GetAI()->initSpell(POWER_INFUSION_1);
    INNER_FOCUS                   = GetAI()->initSpell(INNER_FOCUS_1);

    RECENTLY_BANDAGED  = 11196; // first aid check

    // racial
    ARCANE_TORRENT                = GetAI()->initSpell(ARCANE_TORRENT_MANA_CLASSES);
    GIFT_OF_THE_NAARU             = GetAI()->initSpell(GIFT_OF_THE_NAARU_PRIEST); // draenei
    STONEFORM                     = GetAI()->initSpell(STONEFORM_ALL); // dwarf
    EVERY_MAN_FOR_HIMSELF         = GetAI()->initSpell(EVERY_MAN_FOR_HIMSELF_ALL); // human
    SHADOWMELD                    = GetAI()->initSpell(SHADOWMELD_ALL);
    BERSERKING                    = GetAI()->initSpell(BERSERKING_ALL); // troll
    WILL_OF_THE_FORSAKEN          = GetAI()->initSpell(WILL_OF_THE_FORSAKEN_ALL); // undead
}

PlayerbotPriestAI::~PlayerbotPriestAI() {}

CombatManeuverReturns PlayerbotPriestAI::DoNextManeuver_Heal_ClassSetup(Unit* pTarget)
{
	// No healing setup needed, so pass success
	return RETURN_CONTINUE;
}

CombatManeuverReturns PlayerbotPriestAI::DoFirstCombatManeuverPVE(Unit* /*pTarget*/)
{
    if (!GetAI())  return RETURN_NO_ACTION_ERROR;
    if (!m_bot) return RETURN_NO_ACTION_ERROR;

    if (GetAI()->IsHealer())
    {
        // TODO: This must be done with toggles: FullHealth allowed
        Unit* healTarget = GetHealTarget(JOB_TANK);
        // This is cast on a target, which activates (and switches to another target within the group) upon receiving+healing damage
        // Mana efficient even at one use
        if (healTarget && PRAYER_OF_MENDING > 0 && GetAI()->In_Reach(healTarget,PRAYER_OF_MENDING) && !healTarget->HasAura(PRAYER_OF_MENDING, EFFECT_INDEX_0) && CastSpell(PRAYER_OF_MENDING, healTarget) & RETURN_CONTINUE)
            return RETURN_FINISHED_FIRST_MOVES;
    }
    return RETURN_NO_ACTION_OK;
}

CombatManeuverReturns PlayerbotPriestAI::DoFirstCombatManeuverPVP(Unit* /*pTarget*/)
{
    return RETURN_NO_ACTION_OK;
}

CombatManeuverReturns PlayerbotPriestAI::DoNextCombatManeuverPVE(Unit *pTarget)
{
    if (!GetAI())  return RETURN_NO_ACTION_ERROR;
    if (!m_bot) return RETURN_NO_ACTION_ERROR;

    bool meleeReach = m_bot->CanReachWithMeleeAttack(pTarget);
    uint32 spec = m_bot->GetSpec();

    if (GetAI()->GetCombatStyle() != PlayerbotAI::COMBAT_RANGED && !meleeReach)
        GetAI()->SetCombatStyle(PlayerbotAI::COMBAT_RANGED);
    // if in melee range OR can't shoot OR have no ranged (wand) equipped
    else if(GetAI()->GetCombatStyle() != PlayerbotAI::COMBAT_MELEE 
            && (SHOOT == 0 || !m_bot->GetWeaponForAttack(RANGED_ATTACK, true, true))
            && !GetAI()->IsHealer())
        GetAI()->SetCombatStyle(PlayerbotAI::COMBAT_MELEE);

    //Used to determine if this bot is highest on threat
    Unit* newTarget = GetAI()->FindAttacker((PlayerbotAI::ATTACKERINFOTYPE) (PlayerbotAI::AIT_VICTIMSELF | PlayerbotAI::AIT_HIGHESTTHREAT), m_bot);
    if (newTarget) // TODO: && party has a tank
    {
        if (newTarget && FADE > 0 && !m_bot->HasAura(FADE, EFFECT_INDEX_0))
        {
            if (CastSpell(FADE, m_bot))
            {
                //GetAI()->TellMaster("I'm casting fade.");
                return RETURN_CONTINUE;
            }
            else
                GetAI()->TellMaster("I have AGGRO.");
        }

        // Heal myself
        // TODO: move to HealTarget code
        // TODO: you forgot to check for the 'temporarily immune to PW:S because you only just got it cast on you' effect
        //       - which is different effect from the actual shield.
        if (GetAI()->GetHealthPercent() < 25 && POWER_WORD_SHIELD > 0 && !m_bot->HasAura(POWER_WORD_SHIELD, EFFECT_INDEX_0))
        {
            if (CastSpell(POWER_WORD_SHIELD) & RETURN_CONTINUE)
            {
                //GetAI()->TellMaster("I'm casting PW:S on myself.");
                return RETURN_CONTINUE;
            }
            else if (GetAI()->IsHealer()) // Even if any other RETURN_ANY_OK - aside from RETURN_CONTINUE
                GetAI()->TellMaster("Your healer's about TO DIE. HELP ME.");
        }
        if (GetAI()->GetHealthPercent() < 35 && DESPERATE_PRAYER > 0 && GetAI()->In_Reach(m_bot,DESPERATE_PRAYER) && CastSpell(DESPERATE_PRAYER, m_bot) & RETURN_CONTINUE)
        {
            //GetAI()->TellMaster("I'm casting desperate prayer.");
            return RETURN_CONTINUE;
        }

        // Already healed self or tank. If healer, do nothing else to anger mob.
        if (GetAI()->IsHealer())
            return RETURN_NO_ACTION_OK; // In a sense, mission accomplished.

        // Have threat, can't quickly lower it. 3 options remain: Stop attacking, lowlevel damage (wand), keep on keeping on.
        if (newTarget->GetHealthPercent() > 25)
        {
            // If elite, do nothing and pray tank gets aggro off you
            // TODO: Is there an IsElite function? If so, find it and insert.
            //if (newTarget->IsElite())
            //    return;

            // Not an elite. You could insert PSYCHIC SCREAM here but in any PvE situation that's 90-95% likely
            // to worsen the situation for the group. ... So please don't.
            return CastSpell(SHOOT, pTarget);
        }
    }

    // Heal
    if (GetAI()->IsHealer())
    {
        if (HealPlayer(GetHealTarget()) & RETURN_CONTINUE)
            return RETURN_CONTINUE;
    }
    else
    {
        // Is this desirable? Debatable.
        // ... Certainly could be very detrimental to a shadow priest
        // TODO: In a group/raid with a healer you'd want this bot to focus on DPS (it's not specced/geared for healing either)
        if (HealPlayer(m_bot) & RETURN_CONTINUE)
            return RETURN_CONTINUE;
    }

    // Do damage tweaking for healers here
    if (GetAI()->IsHealer())
    {
        // TODO: elite exception
        //if (Any target is an Elite)
        //    return;

        return CastSpell(SHOOT, pTarget);
    }

    // Damage Spells
    switch (spec)
    {
        case PRIEST_SPEC_HOLY:
            if (HOLY_FIRE > 0 && GetAI()->In_Reach(pTarget,HOLY_FIRE) && !pTarget->HasAura(HOLY_FIRE, EFFECT_INDEX_0) && CastSpell(HOLY_FIRE, pTarget))
                return RETURN_CONTINUE;
            if (SMITE > 0 && GetAI()->In_Reach(pTarget,SMITE) && CastSpell(SMITE, pTarget))
                return RETURN_CONTINUE;
            //if (HOLY_NOVA > 0 && GetAI()->In_Reach(pTarget,HOLY_NOVA) && meleeReach && GetAI()->CastSpell(HOLY_NOVA))
            //    return RETURN_CONTINUE;
            break;

        case PRIEST_SPEC_SHADOW:
            if (DEVOURING_PLAGUE > 0 && GetAI()->In_Reach(pTarget,DEVOURING_PLAGUE) && !pTarget->HasAura(DEVOURING_PLAGUE, EFFECT_INDEX_0) && CastSpell(DEVOURING_PLAGUE, pTarget))
                return RETURN_CONTINUE;
            if (VAMPIRIC_TOUCH > 0 && GetAI()->In_Reach(pTarget,VAMPIRIC_TOUCH) && !pTarget->HasAura(VAMPIRIC_TOUCH, EFFECT_INDEX_0) && CastSpell(VAMPIRIC_TOUCH, pTarget))
                return RETURN_CONTINUE;
            if (SHADOW_WORD_PAIN > 0 && GetAI()->In_Reach(pTarget,SHADOW_WORD_PAIN) && !pTarget->HasAura(SHADOW_WORD_PAIN, EFFECT_INDEX_0) && CastSpell(SHADOW_WORD_PAIN, pTarget))
                return RETURN_CONTINUE;
            if (MIND_BLAST > 0 && GetAI()->In_Reach(pTarget,MIND_BLAST) && (m_bot->IsSpellReady(MIND_BLAST)) && CastSpell(MIND_BLAST, pTarget))
                return RETURN_CONTINUE;
            if (MIND_FLAY > 0 && GetAI()->In_Reach(pTarget,MIND_FLAY) && CastSpell(MIND_FLAY, pTarget))
            {
                GetAI()->SetIgnoreUpdateTime(3);
                return RETURN_CONTINUE;
            }
            if (SHADOWFIEND > 0 && GetAI()->In_Reach(pTarget,SHADOWFIEND) && !m_bot->GetPet() && CastSpell(SHADOWFIEND))
                return RETURN_CONTINUE;
            /*if (MIND_SEAR > 0 && GetAI()->GetAttackerCount() >= 3 && CastSpell(MIND_SEAR, pTarget))
            {
                GetAI()->SetIgnoreUpdateTime(5);
                return RETURN_CONTINUE;
            }*/
            if (SHADOWFORM == 0 && MIND_FLAY == 0 && SMITE > 0 && GetAI()->In_Reach(pTarget,SMITE) && CastSpell(SMITE, pTarget)) // low levels
                return RETURN_CONTINUE;
            break;

        case PRIEST_SPEC_DISCIPLINE:
            if (POWER_INFUSION > 0 && GetAI()->In_Reach(GetMaster(),POWER_INFUSION) && CastSpell(POWER_INFUSION, GetMaster())) // TODO: just master?
                return RETURN_CONTINUE;
            if (INNER_FOCUS > 0 && GetAI()->In_Reach(m_bot,INNER_FOCUS) && !m_bot->HasAura(INNER_FOCUS, EFFECT_INDEX_0) && CastSpell(INNER_FOCUS, m_bot))
                return RETURN_CONTINUE;
            if (PENANCE > 0 && CastSpell(PENANCE))
                return RETURN_CONTINUE;
            if (SMITE > 0 && GetAI()->In_Reach(pTarget,SMITE) && CastSpell(SMITE, pTarget))
                return RETURN_CONTINUE;
            break;
    }

    // No spec due to low level OR no spell found yet
    if (MIND_BLAST > 0 && GetAI()->In_Reach(pTarget,MIND_BLAST) && (m_bot->IsSpellReady(MIND_BLAST)) && CastSpell(MIND_BLAST, pTarget))
        return RETURN_CONTINUE;
    if (SHADOW_WORD_PAIN > 0 && GetAI()->In_Reach(pTarget,SHADOW_WORD_PAIN) && !pTarget->HasAura(SHADOW_WORD_PAIN, EFFECT_INDEX_0) && CastSpell(SHADOW_WORD_PAIN, pTarget))
        return RETURN_CONTINUE;
    if (MIND_FLAY > 0 && GetAI()->In_Reach(pTarget,MIND_FLAY) && CastSpell(MIND_FLAY, pTarget))
    {
        GetAI()->SetIgnoreUpdateTime(3);
        return RETURN_CONTINUE;
    }
    if (SHADOWFORM == 0 && SMITE > 0 && GetAI()->In_Reach(pTarget,SMITE) && CastSpell(SMITE, pTarget))
        return RETURN_CONTINUE;

    return RETURN_NO_ACTION_OK;
} // end DoNextCombatManeuver

CombatManeuverReturns PlayerbotPriestAI::DoNextCombatManeuverPVP(Unit* pTarget)
{
    switch (GetAI()->GetScenarioType())
    {
        case PlayerbotAI::SCENARIO_PVP_DUEL:
            // TODO: spec tweaking
            if (GetAI()->HasAura(SCREAM, *pTarget) && GetAI()->GetHealthPercent() < 60 && HEAL && GetAI()->In_Reach(pTarget,HEAL) && CastSpell(HEAL) & RETURN_ANY_OK)
                return RETURN_CONTINUE;

            if (SHADOW_WORD_PAIN && GetAI()->In_Reach(pTarget,SHADOW_WORD_PAIN) && CastSpell(SHADOW_WORD_PAIN) & RETURN_ANY_OK) // TODO: Check whether enemy has it active yet
                return RETURN_CONTINUE;

            if (GetAI()->GetHealthPercent() < 80 && RENEW && GetAI()->In_Reach(pTarget,RENEW) && CastSpell(RENEW) & RETURN_ANY_OK) // TODO: Check whether you have renew active on you
                return RETURN_CONTINUE;

            if (SCREAM && GetAI()->In_Reach(pTarget,SCREAM) && CastSpell(SCREAM) & RETURN_ANY_OK) // TODO: Check for cooldown
                return RETURN_CONTINUE;

            if (MIND_BLAST && GetAI()->In_Reach(pTarget,MIND_BLAST) && CastSpell(MIND_BLAST) & RETURN_ANY_OK) // TODO: Check for cooldown
                return RETURN_CONTINUE;

            if (GetAI()->GetHealthPercent() < 50 && GREATER_HEAL && GetAI()->In_Reach(pTarget,GREATER_HEAL) && CastSpell(GREATER_HEAL) & RETURN_ANY_OK)
                return RETURN_CONTINUE;

            if (SMITE && GetAI()->In_Reach(pTarget,SMITE) && CastSpell(SMITE) & RETURN_ANY_OK)
                return RETURN_CONTINUE;

            GetAI()->TellMaster("Couldn't find a spell to cast while dueling");
        default:
            break;
    }

    return DoNextCombatManeuverPVE(pTarget); // TODO: bad idea perhaps, but better than the alternative
}

CombatManeuverReturns PlayerbotPriestAI::HealPlayer(Player* target)
{
    CombatManeuverReturns r = PlayerbotClassAI::HealPlayer(target);
    if (r != RETURN_NO_ACTION_OK)
        return r;

    if (!target->isAlive())
    {
        if (RESURRECTION && GetAI()->In_Reach(target,RESURRECTION) && GetAI()->CastSpell(RESURRECTION, *target))
        {
            std::string msg = "Resurrecting ";
            msg += target->GetName();
            m_bot->Say(msg, LANG_UNIVERSAL);
            return RETURN_CONTINUE;
        }
        return RETURN_NO_ACTION_ERROR; // not error per se - possibly just OOM
    }

    if (CURE_DISEASE > 0 && (GetAI()->GetCombatOrder() & PlayerbotAI::ORDERS_NODISPEL) == 0)
    {
        uint32 dispelMask  = GetDispellMask(DISPEL_DISEASE);
        Unit::SpellAuraHolderMap const& auras = target->GetSpellAuraHolderMap();
        for (Unit::SpellAuraHolderMap::const_iterator itr = auras.begin(); itr != auras.end(); ++itr)
        {
            SpellAuraHolder *holder = itr->second;
            if ((1 << holder->GetSpellProto()->Dispel) & dispelMask)
            {
                if (holder->GetSpellProto()->Dispel == DISPEL_DISEASE)
                {
                    GetAI()->CastSpell(CURE_DISEASE, *target);
                    return RETURN_CONTINUE;
                }
            }
        }
    }

    uint8 hp = target->GetHealthPercent();
    uint8 hpSelf = GetAI()->GetHealthPercent();

    if (hp >= 90)
        return RETURN_NO_ACTION_OK;

    // TODO: Integrate shield here
    if (hp < 35 && FLASH_HEAL > 0 && GetAI()->In_Reach(target,FLASH_HEAL) && GetAI()->CastSpell(FLASH_HEAL, *target))
        return RETURN_CONTINUE;
    if (hp < 45 && GREATER_HEAL > 0 && GetAI()->In_Reach(target,GREATER_HEAL) && GetAI()->CastSpell(GREATER_HEAL, *target))
        return RETURN_CONTINUE;
    // Heals target AND self for equal amount
    if (hp < 60 && hpSelf < 80 && BINDING_HEAL > 0 && GetAI()->In_Reach(target,BINDING_HEAL) && GetAI()->CastSpell(BINDING_HEAL, *target))
        return RETURN_CONTINUE;
    if (hp < 60 && PRAYER_OF_MENDING > 0 && GetAI()->In_Reach(target,PRAYER_OF_MENDING) && !target->HasAura(PRAYER_OF_MENDING, EFFECT_INDEX_0) && CastSpell(PRAYER_OF_MENDING, target))
        return RETURN_FINISHED_FIRST_MOVES;
    if (hp < 60 && HEAL > 0 && GetAI()->In_Reach(target,HEAL) && GetAI()->CastSpell(HEAL, *target))
        return RETURN_CONTINUE;
    if (hp < 90 && RENEW > 0 && GetAI()->In_Reach(target,RENEW) && !target->HasAura(RENEW) && GetAI()->CastSpell(RENEW, *target))
        return RETURN_CONTINUE;

    // Group heal. Not really useful until a group check is available?
    //if (hp < 40 && PRAYER_OF_HEALING > 0 && GetAI()->CastSpell(PRAYER_OF_HEALING, *target) & RETURN_CONTINUE)
    //    return RETURN_CONTINUE;
    // Group heal. Not really useful until a group check is available?
    //if (hp < 50 && CIRCLE_OF_HEALING > 0 && GetAI()->CastSpell(CIRCLE_OF_HEALING, *target) & RETURN_CONTINUE)
    //    return RETURN_CONTINUE;

    return RETURN_NO_ACTION_OK;
} // end HealTarget

void PlayerbotPriestAI::DoNonCombatActions()
{
    if (!GetAI())   return;
    if (!m_bot)  return;

    if (!m_bot->isAlive() || m_bot->IsInDuel()) return;

    uint32 spec = m_bot->GetSpec();

    // selfbuff goes first
    if (GetAI()->SelfBuff(INNER_FIRE))
        return;

    // Revive
    if (HealPlayer(GetResurrectionTarget()) & RETURN_CONTINUE)
        return;

    // After revive
    if (spec == PRIEST_SPEC_SHADOW && SHADOWFORM > 0)
        GetAI()->SelfBuff(SHADOWFORM);
    if (VAMPIRIC_EMBRACE > 0)
        GetAI()->SelfBuff(VAMPIRIC_EMBRACE);

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

    // Buffing
    // the check for group targets is performed by NeedGroupBuff (if group is found for bots by the function)
    if (NeedGroupBuff(PRAYER_OF_FORTITUDE, POWER_WORD_FORTITUDE) && GetAI()->HasSpellReagents(PRAYER_OF_FORTITUDE))
    {
        if (Buff(&PlayerbotPriestAI::BuffHelper, PRAYER_OF_FORTITUDE) & RETURN_CONTINUE)
            return;
    }
    else if (Buff(&PlayerbotPriestAI::BuffHelper, POWER_WORD_FORTITUDE) & RETURN_CONTINUE)
        return;

    if (NeedGroupBuff(PRAYER_OF_SPIRIT, DIVINE_SPIRIT) && GetAI()->HasSpellReagents(PRAYER_OF_FORTITUDE))
    {
        if (Buff(&PlayerbotPriestAI::BuffHelper, PRAYER_OF_SPIRIT) & RETURN_CONTINUE)
            return;
    }
    else if (Buff(&PlayerbotPriestAI::BuffHelper, DIVINE_SPIRIT, (JOB_ALL | JOB_MANAONLY)) & RETURN_CONTINUE)
        return;

    if (NeedGroupBuff(PRAYER_OF_SHADOW_PROTECTION, SHADOW_PROTECTION) && GetAI()->HasSpellReagents(PRAYER_OF_FORTITUDE))
    {
        if (GetAI()->GetCombatOrder() & PlayerbotAI::ORDERS_RESIST_SHADOW && Buff(&PlayerbotPriestAI::BuffHelper, PRAYER_OF_SHADOW_PROTECTION) & RETURN_CONTINUE)
            return;
    }
    else if (GetAI()->GetCombatOrder() & PlayerbotAI::ORDERS_RESIST_SHADOW && Buff(&PlayerbotPriestAI::BuffHelper, SHADOW_PROTECTION) & RETURN_CONTINUE)
        return;

    if (EatDrinkBandage())
        return;
} // end DoNonCombatActions

// TODO: this and mage's BuffHelper are identical and thus could probably go in PlayerbotClassAI.cpp somewhere
bool PlayerbotPriestAI::BuffHelper(PlayerbotAI* ai, uint32 spellId, Unit *target)
{
    //DEBUG_LOG("..Priest_BuffHelper to the rescue!");
    if (!ai)          return false;
    if (spellId == 0) return false;
    if (!target)      return false;

    Pet * pet = target->GetPet();
    if (pet && !pet->HasAuraType(SPELL_AURA_MOD_UNATTACKABLE) && ai->Buff(spellId, pet))
        return true;

    if (ai->Buff(spellId, target))
    {
        //DEBUG_LOG("..Buffed");
        return true;
    }

    //DEBUG_LOG("..Not buffing anyone!");
    return false;
}

bool PlayerbotPriestAI::CastHoTOnTank()
{
    if (!GetAI()) return false;

    if ((PlayerbotAI::ORDERS_HEAL & GetAI()->GetCombatOrder()) == 0) return false;

    // Priest HoTs: Renew, Penance (with talents, channeled)
    if (RENEW > 0 && GetAI()->In_Reach(GetAI()->GetGroupTank(),RENEW))
        return (RETURN_CONTINUE & CastSpell(RENEW, GetAI()->GetGroupTank()));

    return false;
}
