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

#include "PlayerbotWarlockAI.h"

class PlayerbotAI;
PlayerbotWarlockAI::PlayerbotWarlockAI(Player* const master, Player* const bot, PlayerbotAI* const ai) : PlayerbotClassAI(master, bot, ai)
{
    // DESTRUCTION
    SHADOW_BOLT           = GetAI()->initSpell(SHADOW_BOLT_1);
    IMMOLATE              = GetAI()->initSpell(IMMOLATE_1);
    INCINERATE            = GetAI()->initSpell(INCINERATE_1);
    SEARING_PAIN          = GetAI()->initSpell(SEARING_PAIN_1);
    CONFLAGRATE           = GetAI()->initSpell(CONFLAGRATE_1);
    SHADOWFURY            = GetAI()->initSpell(SHADOWFURY_1);
    CHAOS_BOLT            = GetAI()->initSpell(CHAOS_BOLT_1);
    SHADOWFLAME           = GetAI()->initSpell(SHADOWFLAME_1);
    HELLFIRE              = GetAI()->initSpell(HELLFIRE_1);
    RAIN_OF_FIRE          = GetAI()->initSpell(RAIN_OF_FIRE_1);
    SOUL_FIRE             = GetAI()->initSpell(SOUL_FIRE_1); // soul shard spells
    SHADOWBURN            = GetAI()->initSpell(SHADOWBURN_1);
    // CURSE
    CURSE_OF_WEAKNESS     = GetAI()->initSpell(CURSE_OF_WEAKNESS_1);
    CURSE_OF_THE_ELEMENTS = GetAI()->initSpell(CURSE_OF_THE_ELEMENTS_1);
    CURSE_OF_AGONY        = GetAI()->initSpell(CURSE_OF_AGONY_1);
    CURSE_OF_EXHAUSTION   = GetAI()->initSpell(CURSE_OF_EXHAUSTION_1);
    CURSE_OF_TONGUES      = GetAI()->initSpell(CURSE_OF_TONGUES_1);
    CURSE_OF_DOOM         = GetAI()->initSpell(CURSE_OF_DOOM_1);
    // AFFLICTION
    CORRUPTION            = GetAI()->initSpell(CORRUPTION_1);
    DRAIN_SOUL            = GetAI()->initSpell(DRAIN_SOUL_1);
    DRAIN_LIFE            = GetAI()->initSpell(DRAIN_LIFE_1);
    DRAIN_MANA            = GetAI()->initSpell(DRAIN_MANA_1);
    LIFE_TAP              = GetAI()->initSpell(LIFE_TAP_1);
    UNSTABLE_AFFLICTION   = GetAI()->initSpell(UNSTABLE_AFFLICTION_1);
    HAUNT                 = GetAI()->initSpell(HAUNT_1);
    SEED_OF_CORRUPTION    = GetAI()->initSpell(SEED_OF_CORRUPTION_1);
    DARK_PACT             = GetAI()->initSpell(DARK_PACT_1);
    HOWL_OF_TERROR        = GetAI()->initSpell(HOWL_OF_TERROR_1);
    FEAR                  = GetAI()->initSpell(FEAR_1);
    // DEMONOLOGY
    DEMON_SKIN            = GetAI()->initSpell(DEMON_SKIN_1);
    DEMON_ARMOR           = GetAI()->initSpell(DEMON_ARMOR_1);
    DEMONIC_EMPOWERMENT   = GetAI()->initSpell(DEMONIC_EMPOWERMENT_1);
    FEL_ARMOR             = GetAI()->initSpell(FEL_ARMOR_1);
    SHADOW_WARD           = GetAI()->initSpell(SHADOW_WARD_1);
    SOULSHATTER           = GetAI()->initSpell(SOULSHATTER_1);
    SOUL_LINK             = GetAI()->initSpell(SOUL_LINK_1);
    SOUL_LINK_AURA        = 25228; // dummy aura applied, after spell SOUL_LINK
    HEALTH_FUNNEL         = GetAI()->initSpell(HEALTH_FUNNEL_1);
    DETECT_INVISIBILITY   = GetAI()->initSpell(DETECT_INVISIBILITY_1);
    CREATE_FIRESTONE      = GetAI()->initSpell(CREATE_FIRESTONE_1);
    CREATE_HEALTHSTONE    = GetAI()->initSpell(CREATE_HEALTHSTONE_1);
    CREATE_SOULSTONE      = GetAI()->initSpell(CREATE_SOULSTONE_1);
    CREATE_SPELLSTONE     = GetAI()->initSpell(CREATE_SPELLSTONE_1);
    // demon summon
    SUMMON_IMP            = GetAI()->initSpell(SUMMON_IMP_1);
    SUMMON_VOIDWALKER     = GetAI()->initSpell(SUMMON_VOIDWALKER_1);
    SUMMON_SUCCUBUS       = GetAI()->initSpell(SUMMON_SUCCUBUS_1);
    SUMMON_FELHUNTER      = GetAI()->initSpell(SUMMON_FELHUNTER_1);
    SUMMON_FELGUARD       = GetAI()->initSpell(SUMMON_FELGUARD_1);
    // demon skills should be initialized on demons
    BLOOD_PACT            = 0; // imp skill
    CONSUME_SHADOWS       = 0; // voidwalker skill
    FEL_INTELLIGENCE      = 0; // felhunter skill
    // RANGED COMBAT
    SHOOT                 = GetAI()->initSpell(SHOOT_3);

    RECENTLY_BANDAGED     = 11196; // first aid check

    // racial
    ARCANE_TORRENT        = GetAI()->initSpell(ARCANE_TORRENT_MANA_CLASSES); // blood elf
    ESCAPE_ARTIST         = GetAI()->initSpell(ESCAPE_ARTIST_ALL); // gnome
    EVERY_MAN_FOR_HIMSELF = GetAI()->initSpell(EVERY_MAN_FOR_HIMSELF_ALL); // human
    BLOOD_FURY            = GetAI()->initSpell(BLOOD_FURY_WARLOCK); // orc
    WILL_OF_THE_FORSAKEN  = GetAI()->initSpell(WILL_OF_THE_FORSAKEN_ALL); // undead

    m_lastDemon           = 0;
    m_demonOfChoice       = DEMON_IMP;
    m_isTempImp           = false;
}

PlayerbotWarlockAI::~PlayerbotWarlockAI() {}

CombatManeuverReturns PlayerbotWarlockAI::DoFirstCombatManeuverPVE(Unit* /*pTarget*/)
{
    return RETURN_NO_ACTION_OK;
}

CombatManeuverReturns PlayerbotWarlockAI::DoFirstCombatManeuverPVP(Unit* /*pTarget*/)
{
    return RETURN_NO_ACTION_OK;
}

CombatManeuverReturns PlayerbotWarlockAI::DoNextCombatManeuverPVE(Unit *pTarget)
{
    if (!GetAI())  return RETURN_NO_ACTION_ERROR;
    if (!m_bot) return RETURN_NO_ACTION_ERROR;

    //Unit* pVictim = pTarget->getVictim();
    bool meleeReach = m_bot->CanReachWithMeleeAttack(pTarget);
    Pet *pet = m_bot->GetPet();
    uint32 spec = m_bot->GetSpec();
    uint8 shardCount = m_bot->GetItemCount(SOUL_SHARD, false, nullptr);

    //If we have UA it will replace immolate in our rotation
    uint32 FIRE = (UNSTABLE_AFFLICTION > 0 ? UNSTABLE_AFFLICTION : IMMOLATE);

    // Voidwalker is near death - sacrifice it for a shield
    if (pet && pet->GetEntry() == DEMON_VOIDWALKER && SACRIFICE && !m_bot->HasAura(SACRIFICE) && pet->GetHealthPercent() < 10)
        GetAI()->CastPetSpell(SACRIFICE);

    // Use healthstone
    if (GetAI()->GetHealthPercent() < 30)
    {
        Item* healthStone = GetAI()->FindConsumable(HEALTHSTONE_DISPLAYID);
        if (healthStone)
            GetAI()->UseItem(healthStone);
    }

    // Voidwalker sacrifice gives shield - but you lose the pet (and it's DPS/tank) - use only as last resort for your own health!
    if (GetAI()->GetHealthPercent() < 20 && pet && pet->GetEntry() == DEMON_VOIDWALKER && SACRIFICE && !m_bot->HasAura(SACRIFICE))
        GetAI()->CastPetSpell(SACRIFICE);

    if (GetAI()->GetCombatStyle() != PlayerbotAI::COMBAT_RANGED && !meleeReach)
        GetAI()->SetCombatStyle(PlayerbotAI::COMBAT_RANGED);
    // if in melee range OR can't shoot OR have no ranged (wand) equipped
    else if(GetAI()->GetCombatStyle() != PlayerbotAI::COMBAT_MELEE && (meleeReach || SHOOT == 0 || !m_bot->GetWeaponForAttack(RANGED_ATTACK, true, true)))
        GetAI()->SetCombatStyle(PlayerbotAI::COMBAT_MELEE);

    //Used to determine if this bot is highest on threat
    Unit *newTarget = GetAI()->FindAttacker((PlayerbotAI::ATTACKERINFOTYPE) (PlayerbotAI::AIT_VICTIMSELF | PlayerbotAI::AIT_HIGHESTTHREAT), m_bot);
    if (newTarget) // TODO: && party has a tank
    {
        if (SOULSHATTER > 0 && shardCount > 0 && m_bot->IsSpellReady(SOULSHATTER))
            if (CastSpell(SOULSHATTER, m_bot))
                return RETURN_CONTINUE;

        // Have threat, can't quickly lower it. 3 options remain: Stop attacking, lowlevel damage (wand), keep on keeping on.
        if (newTarget->GetHealthPercent() > 25)
        {
            // If elite, do nothing and pray tank gets aggro off you
            // TODO: Is there an IsElite function? If so, find it and insert.
            //if (newTarget->IsElite())
            //    return;

            // Not an elite. You could insert FEAR here but in any PvE situation that's 90-95% likely
            // to worsen the situation for the group. ... So please don't.
            return CastSpell(SHOOT, pTarget);
        }
    }
    
    // Create soul shard 
    uint8 freeSpace = GetAI()->GetFreeBagSpace();
    if (DRAIN_SOUL && pTarget->GetHealth() < pTarget->GetMaxHealth() * 0.20 && GetAI()->In_Reach(pTarget, DRAIN_SOUL) && 
        !pTarget->HasAura(DRAIN_SOUL) && (shardCount < MAX_SHARD_COUNT && freeSpace > 0) && CastSpell(DRAIN_SOUL, pTarget))
    {
        GetAI()->SetIgnoreUpdateTime(15);
        return RETURN_CONTINUE;
    }


    // Damage Spells
    switch (spec)
    {
        case WARLOCK_SPEC_AFFLICTION:
            if (CURSE_OF_AGONY && GetAI()->In_Reach(pTarget,CURSE_OF_AGONY) && !pTarget->HasAura(CURSE_OF_AGONY) && CastSpell(CURSE_OF_AGONY, pTarget))
                return RETURN_CONTINUE;
            if (CORRUPTION && GetAI()->In_Reach(pTarget,CORRUPTION) && !pTarget->HasAura(CORRUPTION) && CastSpell(CORRUPTION, pTarget))
                return RETURN_CONTINUE;
            if (FIRE && GetAI()->In_Reach(pTarget,FIRE) && !pTarget->HasAura(FIRE) && CastSpell(FIRE, pTarget))
                return RETURN_CONTINUE;
            if (HAUNT && GetAI()->In_Reach(pTarget,HAUNT) && m_bot->IsSpellReady(HAUNT) && CastSpell(HAUNT, pTarget))
                return RETURN_CONTINUE;
            if (SHADOW_BOLT && GetAI()->In_Reach(pTarget,SHADOW_BOLT) && CastSpell(SHADOW_BOLT, pTarget))
                return RETURN_CONTINUE;

            return RETURN_NO_ACTION_OK;

        case WARLOCK_SPEC_DEMONOLOGY:
            if (pet && DEMONIC_EMPOWERMENT && m_bot->IsSpellReady(DEMONIC_EMPOWERMENT) && CastSpell(DEMONIC_EMPOWERMENT))
                return RETURN_CONTINUE;
            if (CURSE_OF_AGONY && GetAI()->In_Reach(pTarget,CURSE_OF_AGONY) && !pTarget->HasAura(CURSE_OF_AGONY) && CastSpell(CURSE_OF_AGONY, pTarget))
                return RETURN_CONTINUE;
            if (CORRUPTION && GetAI()->In_Reach(pTarget,CORRUPTION) && !pTarget->HasAura(CORRUPTION) && CastSpell(CORRUPTION, pTarget))
                return RETURN_CONTINUE;
            if (FIRE && GetAI()->In_Reach(pTarget,FIRE) && !pTarget->HasAura(FIRE) && CastSpell(FIRE, pTarget))
                return RETURN_CONTINUE;
            if (INCINERATE && GetAI()->In_Reach(pTarget,INCINERATE) && pTarget->HasAura(FIRE) && CastSpell(INCINERATE, pTarget))
                return RETURN_CONTINUE;
            if (SHADOW_BOLT && GetAI()->In_Reach(pTarget,SHADOW_BOLT) && CastSpell(SHADOW_BOLT, pTarget))
                return RETURN_CONTINUE;

            return RETURN_NO_ACTION_OK;

        case WARLOCK_SPEC_DESTRUCTION:
            if (CURSE_OF_AGONY && GetAI()->In_Reach(pTarget,CURSE_OF_AGONY) && !pTarget->HasAura(CURSE_OF_AGONY) && CastSpell(CURSE_OF_AGONY, pTarget))
                return RETURN_CONTINUE;
            if (CORRUPTION && GetAI()->In_Reach(pTarget,CORRUPTION) && !pTarget->HasAura(CORRUPTION) && CastSpell(CORRUPTION, pTarget))
                return RETURN_CONTINUE;
            if (FIRE && GetAI()->In_Reach(pTarget,FIRE) && !pTarget->HasAura(FIRE) && CastSpell(FIRE, pTarget))
                return RETURN_CONTINUE;
            if (CONFLAGRATE && GetAI()->In_Reach(pTarget,CONFLAGRATE) && pTarget->HasAura(FIRE) && m_bot->IsSpellReady(CONFLAGRATE) && CastSpell(CONFLAGRATE, pTarget))
                return RETURN_CONTINUE;
            if (CHAOS_BOLT && GetAI()->In_Reach(pTarget,CHAOS_BOLT) && m_bot->IsSpellReady(CHAOS_BOLT) && CastSpell(CHAOS_BOLT, pTarget))
                return RETURN_CONTINUE;
            if (INCINERATE && GetAI()->In_Reach(pTarget,INCINERATE) && pTarget->HasAura(FIRE) && CastSpell(INCINERATE, pTarget))
                return RETURN_CONTINUE;
            if (SHADOW_BOLT && GetAI()->In_Reach(pTarget,SHADOW_BOLT) && CastSpell(SHADOW_BOLT, pTarget))
                return RETURN_CONTINUE;

            return RETURN_NO_ACTION_OK;

            //if (LIFE_TAP && LastSpellAffliction < 1 && GetAI()->GetManaPercent() <= 50 && GetAI()->GetHealthPercent() > 50)
            //    GetAI()->CastSpell(LIFE_TAP, *m_bot);
            //else if (DRAIN_SOUL && pTarget->GetHealth() < pTarget->GetMaxHealth() * 0.40 && !pTarget->HasAura(DRAIN_SOUL) && LastSpellAffliction < 3)
            //    GetAI()->CastSpell(DRAIN_SOUL, *pTarget);
            //    //GetAI()->SetIgnoreUpdateTime(15);
            //else if (DRAIN_LIFE && LastSpellAffliction < 4 && !pTarget->HasAura(DRAIN_SOUL) && !pTarget->HasAura(SEED_OF_CORRUPTION) && !pTarget->HasAura(DRAIN_LIFE) && !pTarget->HasAura(DRAIN_MANA) && GetAI()->GetHealthPercent() <= 70)
            //    GetAI()->CastSpell(DRAIN_LIFE, *pTarget);
            //    //GetAI()->SetIgnoreUpdateTime(5);
            //else if (SEED_OF_CORRUPTION && !pTarget->HasAura(SEED_OF_CORRUPTION) && LastSpellAffliction < 7)
            //    GetAI()->CastSpell(SEED_OF_CORRUPTION, *pTarget);
            //else if (HOWL_OF_TERROR && !pTarget->HasAura(HOWL_OF_TERROR) && GetAI()->GetAttackerCount() > 3 && LastSpellAffliction < 8)
            //    GetAI()->CastSpell(HOWL_OF_TERROR, *pTarget);
            //    GetAI()->TellMaster("casting howl of terror!");
            //else if (FEAR && !pTarget->HasAura(FEAR) && pVictim == m_bot && GetAI()->GetAttackerCount() >= 2 && LastSpellAffliction < 9)
            //    GetAI()->CastSpell(FEAR, *pTarget);
            //    //GetAI()->TellMaster("casting fear!");
            //    //GetAI()->SetIgnoreUpdateTime(1.5);
            //else if ((pet) && (DARK_PACT > 0 && GetAI()->GetManaPercent() <= 50 && LastSpellAffliction < 10 && pet->GetPower(POWER_MANA) > 0))
            //    GetAI()->CastSpell(DARK_PACT, *m_bot);
            //if (SHADOWFURY && LastSpellDestruction < 1 && !pTarget->HasAura(SHADOWFURY))
            //    GetAI()->CastSpell(SHADOWFURY, *pTarget);
            //else if (RAIN_OF_FIRE && LastSpellDestruction < 3 && GetAI()->GetAttackerCount() >= 3)
            //    GetAI()->CastSpell(RAIN_OF_FIRE, *pTarget);
            //    //GetAI()->TellMaster("casting rain of fire!");
            //    //GetAI()->SetIgnoreUpdateTime(8);
            //else if (SHADOWFLAME && !pTarget->HasAura(SHADOWFLAME) && LastSpellDestruction < 4)
            //    GetAI()->CastSpell(SHADOWFLAME, *pTarget);
            //else if (SEARING_PAIN && LastSpellDestruction < 8)
            //    GetAI()->CastSpell(SEARING_PAIN, *pTarget);
            //else if (SOUL_FIRE && LastSpellDestruction < 9)
            //    GetAI()->CastSpell(SOUL_FIRE, *pTarget);
            //    //GetAI()->SetIgnoreUpdateTime(6);
            //else if (SHADOWBURN && LastSpellDestruction < 11 && pTarget->GetHealth() < pTarget->GetMaxHealth() * 0.20 && !pTarget->HasAura(SHADOWBURN))
            //    GetAI()->CastSpell(SHADOWBURN, *pTarget);
            //else if (HELLFIRE && LastSpellDestruction < 12 && !m_bot->HasAura(HELLFIRE) && GetAI()->GetAttackerCount() >= 5 && GetAI()->GetHealthPercent() >= 50)
            //    GetAI()->CastSpell(HELLFIRE);
            //    GetAI()->TellMaster("casting hellfire!");
            //    //GetAI()->SetIgnoreUpdateTime(15);
            //else if (CURSE_OF_THE_ELEMENTS && !pTarget->HasAura(CURSE_OF_THE_ELEMENTS) && !pTarget->HasAura(SHADOWFLAME) && !pTarget->HasAura(CURSE_OF_AGONY) && !pTarget->HasAura(CURSE_OF_WEAKNESS) && LastSpellCurse < 2)
            //    GetAI()->CastSpell(CURSE_OF_THE_ELEMENTS, *pTarget);
            //else if (CURSE_OF_WEAKNESS && !pTarget->HasAura(CURSE_OF_WEAKNESS) && !pTarget->HasAura(SHADOWFLAME) && !pTarget->HasAura(CURSE_OF_AGONY) && !pTarget->HasAura(CURSE_OF_THE_ELEMENTS) && LastSpellCurse < 3)
            //    GetAI()->CastSpell(CURSE_OF_WEAKNESS, *pTarget);
            //else if (CURSE_OF_TONGUES && !pTarget->HasAura(CURSE_OF_TONGUES) && !pTarget->HasAura(SHADOWFLAME) && !pTarget->HasAura(CURSE_OF_WEAKNESS) && !pTarget->HasAura(CURSE_OF_AGONY) && !pTarget->HasAura(CURSE_OF_THE_ELEMENTS) && LastSpellCurse < 4)
            //    GetAI()->CastSpell(CURSE_OF_TONGUES, *pTarget);
    }

    // No spec due to low level OR no spell found yet
    if (CORRUPTION && GetAI()->In_Reach(pTarget,CORRUPTION) && !pTarget->HasAura(CORRUPTION) && CastSpell(CORRUPTION, pTarget))
        return RETURN_CONTINUE;
    if (FIRE && GetAI()->In_Reach(pTarget,FIRE) && !pTarget->HasAura(FIRE) && CastSpell(FIRE, pTarget))
        return RETURN_CONTINUE;
    if (SHADOW_BOLT && GetAI()->In_Reach(pTarget,SHADOW_BOLT))
        return CastSpell(SHADOW_BOLT, pTarget);

    return RETURN_NO_ACTION_OK;
} // end DoNextCombatManeuver

CombatManeuverReturns PlayerbotWarlockAI::DoNextCombatManeuverPVP(Unit* pTarget)
{
    if (FEAR && GetAI()->In_Reach(pTarget,FEAR) && GetAI()->CastSpell(FEAR, *pTarget))
        return RETURN_CONTINUE;
    if (SHADOW_BOLT && GetAI()->In_Reach(pTarget,SHADOW_BOLT) && GetAI()->CastSpell(SHADOW_BOLT))
        return RETURN_CONTINUE;

    return DoNextCombatManeuverPVE(pTarget); // TODO: bad idea perhaps, but better than the alternative
}

void PlayerbotWarlockAI::CheckDemon()
{
    uint32 spec = m_bot->GetSpec();
    uint8 shardCount = m_bot->GetItemCount(SOUL_SHARD, false, nullptr);
    Pet *pet = m_bot->GetPet();

    //Assign demon of choice
    if (spec == WARLOCK_SPEC_AFFLICTION)
        m_demonOfChoice = DEMON_FELHUNTER;
    else if (spec == WARLOCK_SPEC_DEMONOLOGY)
        m_demonOfChoice = (DEMON_FELGUARD > 0 ? DEMON_FELGUARD : DEMON_SUCCUBUS);
    else if (spec == WARLOCK_SPEC_DESTRUCTION)
        m_demonOfChoice = DEMON_IMP;

    // Summon demon
    if (!pet || m_isTempImp || pet->GetEntry() != m_demonOfChoice)
    {
        uint32 summonSpellId;
        if (m_demonOfChoice != DEMON_IMP && shardCount > 0)
        {
            switch (m_demonOfChoice)
            {
                case DEMON_VOIDWALKER:
                    summonSpellId = SUMMON_VOIDWALKER;
                    break;

                case DEMON_FELGUARD:
                    summonSpellId = SUMMON_FELGUARD;
                    break;

                case DEMON_FELHUNTER:
                    summonSpellId = SUMMON_FELHUNTER;
                    break;

                case DEMON_SUCCUBUS:
                    summonSpellId = SUMMON_SUCCUBUS;
                    break;

                default:
                    summonSpellId = 0;
            }

            if (GetAI()->CastSpell(summonSpellId))
            {
                //GetAI()->TellMaster("Summoning favorite demon...");
                m_isTempImp = false;
                return;
            }
        }
        else if (!pet && SUMMON_IMP && GetAI()->CastSpell(SUMMON_IMP))
        {
            if (m_demonOfChoice != DEMON_IMP)
                m_isTempImp = true;

            //GetAI()->TellMaster("Summoning Imp...");
            return;
        }
    }
}

void PlayerbotWarlockAI::DoNonCombatActions()
{
    if (!GetAI())  return;
    if (!m_bot) return;

    //uint32 spec = m_bot->GetSpec();
    Pet *pet = m_bot->GetPet();

    // Initialize pet spells
    if (pet && pet->GetEntry() != m_lastDemon)
    {
        switch (pet->GetEntry())
        {
            case DEMON_IMP:
                BLOOD_PACT       = GetAI()->initPetSpell(BLOOD_PACT_ICON);
                FIREBOLT         = GetAI()->initPetSpell(FIREBOLT_ICON);
                FIRE_SHIELD      = GetAI()->initPetSpell(FIRE_SHIELD_ICON);
                break;

            case DEMON_VOIDWALKER:
                CONSUME_SHADOWS  = GetAI()->initPetSpell(CONSUME_SHADOWS_ICON);
                SACRIFICE        = GetAI()->initPetSpell(SACRIFICE_ICON);
                SUFFERING        = GetAI()->initPetSpell(SUFFERING_ICON);
                TORMENT          = GetAI()->initPetSpell(TORMENT_ICON);
                break;

            case DEMON_SUCCUBUS:
                LASH_OF_PAIN     = GetAI()->initPetSpell(LASH_OF_PAIN_ICON);
                SEDUCTION        = GetAI()->initPetSpell(SEDUCTION_ICON);
                SOOTHING_KISS    = GetAI()->initPetSpell(SOOTHING_KISS_ICON);
                break;

            case DEMON_FELHUNTER:
                DEVOUR_MAGIC     = GetAI()->initPetSpell(DEVOUR_MAGIC_ICON);
                FEL_INTELLIGENCE = GetAI()->initPetSpell(FEL_INTELLIGENCE_ICON);
                SHADOW_BITE      = GetAI()->initPetSpell(SHADOW_BITE_ICON);
                SPELL_LOCK       = GetAI()->initPetSpell(SPELL_LOCK_ICON);
                break;

            case DEMON_FELGUARD:
                ANGUISH          = GetAI()->initPetSpell(ANGUISH_ICON);
                CLEAVE           = GetAI()->initPetSpell(CLEAVE_ICON);
                INTERCEPT        = GetAI()->initPetSpell(INTERCEPT_ICON);
                break;
        }

        m_lastDemon = pet->GetEntry();

        //if (!m_isTempImp)
        //    m_demonOfChoice = pet->GetEntry();
    }

    // Destroy extra soul shards
    uint8 shardCount = m_bot->GetItemCount(SOUL_SHARD, false, nullptr);
    uint8 freeSpace = GetAI()->GetFreeBagSpace();
    if (shardCount > MAX_SHARD_COUNT || (freeSpace == 0 && shardCount > 1))
        m_bot->DestroyItemCount(SOUL_SHARD, shardCount > MAX_SHARD_COUNT ? shardCount - MAX_SHARD_COUNT : 1, true, false);

    // buff myself DEMON_SKIN, DEMON_ARMOR, FEL_ARMOR - Strongest one available is chosen
    if (FEL_ARMOR)
    {
        if (GetAI()->SelfBuff(FEL_ARMOR))
            return;
    }
    else if (DEMON_ARMOR)
    {
        if (GetAI()->SelfBuff(DEMON_ARMOR))
            return;
    }
    else if (DEMON_SKIN)
        if (GetAI()->SelfBuff(DEMON_SKIN))
            return;

    // healthstone creation
    if (CREATE_HEALTHSTONE && shardCount > 0)
    {
        Item* const healthStone = GetAI()->FindConsumable(HEALTHSTONE_DISPLAYID);
		if (!healthStone)
		{
			if (GetAI()->CastSpell(CREATE_HEALTHSTONE))
			{
				m_bot->GetPlayerbotAI()->TellMaster("Attempted to create healthstone.");
				return;
			}
			m_bot->GetPlayerbotAI()->TellMaster("CastSpell(CREATE_HEALTHSTONE) - FAILED.");
		}
    }

    // soulstone creation and use
    if (CREATE_SOULSTONE && shardCount > 0)
    {
        Item* soulStone = GetAI()->FindConsumable(SOULSTONE_DISPLAYID);

        if (!soulStone)
        {
			if (m_bot->IsSpellReady(CREATE_SOULSTONE))
			{
				if (GetAI()->CastSpell(CREATE_SOULSTONE))
				{
					m_bot->GetPlayerbotAI()->TellMaster("Attempted to create soulstone.");
					return;
				}
				m_bot->GetPlayerbotAI()->TellMaster("CastSpell(CREATE_SOULSTONE) - FAILED.");
			}
		}
		else
		{
			uint32 soulStoneSpell = soulStone->GetProto()->Spells[0].SpellId;
			Player* master = GetMaster();
			if (!master->HasAura(soulStoneSpell))
			{
				m_bot->GetPlayerbotAI()->TellMaster("!master->HasAura(soulStoneSpell).");

				if (m_bot->IsSpellReady(soulStoneSpell))
				{
					m_bot->GetPlayerbotAI()->TellMaster("About to GetAI()->UseItem(soulStone, master).");
					// TODO: first choice: healer. Second choice: anyone else with revive spell. Third choice: self or master.
					GetAI()->UseItem(soulStone, master);
					return;
				}
			}
		}
	}

    // Spellstone creation and use (Spellstone dominates firestone completely as I understand it)
    Item* const weapon = m_bot->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
    if (weapon && weapon->GetEnchantmentId(TEMP_ENCHANTMENT_SLOT) == 0)
    {
        Item* const stone = GetAI()->FindConsumable(SPELLSTONE_DISPLAYID);
        Item* const stone2 = GetAI()->FindConsumable(FIRESTONE_DISPLAYID);

        uint8 spellstone_count = m_bot->GetItemCount(SPELLSTONE, false, nullptr);

        if (spellstone_count == 0)
            spellstone_count = m_bot->GetItemCount(GREATER_SPELLSTONE, false, nullptr);
        if (spellstone_count == 0)
            spellstone_count = m_bot->GetItemCount(MAJOR_SPELLSTONE, false, nullptr);

        uint8 firestone_count = m_bot->GetItemCount(LESSER_FIRESTONE, false, nullptr);

        if (firestone_count == 0)
            firestone_count = m_bot->GetItemCount(FIRESTONE, false, nullptr);
        if (firestone_count == 0)
            firestone_count = m_bot->GetItemCount(GREATER_FIRESTONE, false, nullptr);
        if (firestone_count == 0)
            firestone_count = m_bot->GetItemCount(MAJOR_FIRESTONE, false, nullptr);

        if (spellstone_count == 0 && firestone_count == 0)
        {
			if (shardCount > 0)
			{
				if (CREATE_SPELLSTONE)
				{
					m_bot->GetPlayerbotAI()->TellMaster("Attempting to CREATE_SPELLSTONE.  Have %u already and stone (%u) stone2 (%u)", spellstone_count, stone, stone2);

					if (GetAI()->CastSpell(CREATE_SPELLSTONE))
					{
						return;
					}
				}
				else if (CREATE_FIRESTONE)
				{
					m_bot->GetPlayerbotAI()->TellMaster("Attempting to CREATE_FIRESTONE.  Have %u already and stone (%u) stone2 (%u)", firestone_count, stone, stone2);

					if (GetAI()->CastSpell(CREATE_FIRESTONE))
					{
						return;
					}
				}
			}
        }
        else if (stone)
        {
			m_bot->GetPlayerbotAI()->TellMaster("Attempting to UseItem(stone, EQUIPMENT_SLOT_MAINHAND).");
			//GetAI()->UseItem(stone, EQUIPMENT_SLOT_OFFHAND);
			GetAI()->UseItem(stone, EQUIPMENT_SLOT_MAINHAND);
			return;
        }
        else if (stone2)
        {
			m_bot->GetPlayerbotAI()->TellMaster("Attempting to UseItem(stone2, EQUIPMENT_SLOT_MAINHAND).");
			//GetAI()->UseItem(stone2, EQUIPMENT_SLOT_OFFHAND);
			GetAI()->UseItem(stone2, EQUIPMENT_SLOT_MAINHAND);
			return;
        }
    }

    // hp/mana check
    if (pet && DARK_PACT && (pet->GetPower(POWER_MANA) / pet->GetMaxPower(POWER_MANA)) > 40 && GetAI()->GetManaPercent() <= 50)
        if (GetAI()->CastSpell(DARK_PACT, *m_bot))
            return;

    if (LIFE_TAP && GetAI()->GetManaPercent() <= 60 && GetAI()->GetHealthPercent() > 60)
        if (GetAI()->CastSpell(LIFE_TAP, *m_bot))
            return;

    if (EatDrinkBandage())
        return;

    //Heal Voidwalker
    if (pet && pet->GetEntry() == DEMON_VOIDWALKER && CONSUME_SHADOWS && pet->GetHealthPercent() < 75 && !pet->HasAura(CONSUME_SHADOWS))
        GetAI()->CastPetSpell(CONSUME_SHADOWS);

    CheckDemon();

    // Soul link demon
    if (pet && SOUL_LINK && !m_bot->HasAura(SOUL_LINK_AURA) && GetAI()->CastSpell(SOUL_LINK, *m_bot))
        return;

    // Check demon buffs
    if (pet && pet->GetEntry() == DEMON_IMP && BLOOD_PACT && !m_bot->HasAura(BLOOD_PACT) && GetAI()->CastPetSpell(BLOOD_PACT))
        return;

    if (pet && pet->GetEntry() == DEMON_FELHUNTER && FEL_INTELLIGENCE && !m_bot->HasAura(FEL_INTELLIGENCE) && GetAI()->CastPetSpell(FEL_INTELLIGENCE))
        return;
} // end DoNonCombatActions
