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
    // TODO: fail on non-postivie return
    PlayerbotClassAI_ClassAIInit();
}


PlayerbotWarlockAI::~PlayerbotWarlockAI() 
{
}


bool PlayerbotWarlockAI::PlayerbotClassAI_ClassAIInit(void)
{
    // DESTRUCTION
    SHADOW_BOLT           = m_botdata->GetAI()->initSpell(SHADOW_BOLT_1);
    IMMOLATE              = m_botdata->GetAI()->initSpell(IMMOLATE_1);
    INCINERATE            = m_botdata->GetAI()->initSpell(INCINERATE_1);
    SEARING_PAIN          = m_botdata->GetAI()->initSpell(SEARING_PAIN_1);
    CONFLAGRATE           = m_botdata->GetAI()->initSpell(CONFLAGRATE_1);
    SHADOWFURY            = m_botdata->GetAI()->initSpell(SHADOWFURY_1);
    CHAOS_BOLT            = m_botdata->GetAI()->initSpell(CHAOS_BOLT_1);
    SHADOWFLAME           = m_botdata->GetAI()->initSpell(SHADOWFLAME_1);
    HELLFIRE              = m_botdata->GetAI()->initSpell(HELLFIRE_1);
    RAIN_OF_FIRE          = m_botdata->GetAI()->initSpell(RAIN_OF_FIRE_1);
    SOUL_FIRE             = m_botdata->GetAI()->initSpell(SOUL_FIRE_1); // soul shard spells
    SHADOWBURN            = m_botdata->GetAI()->initSpell(SHADOWBURN_1);
    // CURSE
    CURSE_OF_WEAKNESS     = m_botdata->GetAI()->initSpell(CURSE_OF_WEAKNESS_1);
    CURSE_OF_THE_ELEMENTS = m_botdata->GetAI()->initSpell(CURSE_OF_THE_ELEMENTS_1);
    CURSE_OF_AGONY        = m_botdata->GetAI()->initSpell(CURSE_OF_AGONY_1);
    CURSE_OF_EXHAUSTION   = m_botdata->GetAI()->initSpell(CURSE_OF_EXHAUSTION_1);
    CURSE_OF_TONGUES      = m_botdata->GetAI()->initSpell(CURSE_OF_TONGUES_1);
    CURSE_OF_DOOM         = m_botdata->GetAI()->initSpell(CURSE_OF_DOOM_1);
    // AFFLICTION
    CORRUPTION            = m_botdata->GetAI()->initSpell(CORRUPTION_1);
    DRAIN_SOUL            = m_botdata->GetAI()->initSpell(DRAIN_SOUL_1);
    DRAIN_LIFE            = m_botdata->GetAI()->initSpell(DRAIN_LIFE_1);
    DRAIN_MANA            = m_botdata->GetAI()->initSpell(DRAIN_MANA_1);
    LIFE_TAP              = m_botdata->GetAI()->initSpell(LIFE_TAP_1);
    UNSTABLE_AFFLICTION   = m_botdata->GetAI()->initSpell(UNSTABLE_AFFLICTION_1);
    HAUNT                 = m_botdata->GetAI()->initSpell(HAUNT_1);
    SEED_OF_CORRUPTION    = m_botdata->GetAI()->initSpell(SEED_OF_CORRUPTION_1);
    DARK_PACT             = m_botdata->GetAI()->initSpell(DARK_PACT_1);
    HOWL_OF_TERROR        = m_botdata->GetAI()->initSpell(HOWL_OF_TERROR_1);
    FEAR                  = m_botdata->GetAI()->initSpell(FEAR_1);
    // DEMONOLOGY
    DEMON_SKIN            = m_botdata->GetAI()->initSpell(DEMON_SKIN_1);
    DEMON_ARMOR           = m_botdata->GetAI()->initSpell(DEMON_ARMOR_1);
    DEMONIC_EMPOWERMENT   = m_botdata->GetAI()->initSpell(DEMONIC_EMPOWERMENT_1);
    FEL_ARMOR             = m_botdata->GetAI()->initSpell(FEL_ARMOR_1);
    SHADOW_WARD           = m_botdata->GetAI()->initSpell(SHADOW_WARD_1);
    SOULSHATTER           = m_botdata->GetAI()->initSpell(SOULSHATTER_1);
    SOUL_LINK             = m_botdata->GetAI()->initSpell(SOUL_LINK_1);
    SOUL_LINK_AURA        = 25228; // dummy aura applied, after spell SOUL_LINK
    HEALTH_FUNNEL         = m_botdata->GetAI()->initSpell(HEALTH_FUNNEL_1);
    DETECT_INVISIBILITY   = m_botdata->GetAI()->initSpell(DETECT_INVISIBILITY_1);
    CREATE_FIRESTONE      = m_botdata->GetAI()->initSpell(CREATE_FIRESTONE_1);
    CREATE_HEALTHSTONE    = m_botdata->GetAI()->initSpell(CREATE_HEALTHSTONE_1);
    CREATE_SOULSTONE      = m_botdata->GetAI()->initSpell(CREATE_SOULSTONE_1);
    CREATE_SPELLSTONE     = m_botdata->GetAI()->initSpell(CREATE_SPELLSTONE_1);
    // demon summon
    SUMMON_IMP            = m_botdata->GetAI()->initSpell(SUMMON_IMP_1);
    SUMMON_VOIDWALKER     = m_botdata->GetAI()->initSpell(SUMMON_VOIDWALKER_1);
    SUMMON_SUCCUBUS       = m_botdata->GetAI()->initSpell(SUMMON_SUCCUBUS_1);
    SUMMON_FELHUNTER      = m_botdata->GetAI()->initSpell(SUMMON_FELHUNTER_1);
    SUMMON_FELGUARD       = m_botdata->GetAI()->initSpell(SUMMON_FELGUARD_1);
    // demon skills should be initialized on demons
    BLOOD_PACT            = 0; // imp skill
    CONSUME_SHADOWS       = 0; // voidwalker skill
    FEL_INTELLIGENCE      = 0; // felhunter skill
    // RANGED COMBAT
    SHOOT                 = m_botdata->GetAI()->initSpell(SHOOT_3);

    // racial
    ARCANE_TORRENT        = m_botdata->GetAI()->initSpell(ARCANE_TORRENT_MANA_CLASSES); // blood elf
    ESCAPE_ARTIST         = m_botdata->GetAI()->initSpell(ESCAPE_ARTIST_ALL); // gnome
    EVERY_MAN_FOR_HIMSELF = m_botdata->GetAI()->initSpell(EVERY_MAN_FOR_HIMSELF_ALL); // human
    BLOOD_FURY            = m_botdata->GetAI()->initSpell(BLOOD_FURY_WARLOCK); // orc
    WILL_OF_THE_FORSAKEN  = m_botdata->GetAI()->initSpell(WILL_OF_THE_FORSAKEN_ALL); // undead

	m_botdata->SetRolePrimary(BOT_ROLE::ROLE_DPS_CASTER);

    return PlayerbotClassAI::PlayerbotClassAI_ClassAIInit();
}


CombatManeuverReturns PlayerbotWarlockAI::DoFirstCombatManeuverPVE(Unit *pTarget)
{
    return RETURN_NO_ACTION_OK;
}

CombatManeuverReturns PlayerbotWarlockAI::DoFirstCombatManeuverPVP(Unit *pTarget)
{
    return RETURN_NO_ACTION_OK;
}

CombatManeuverReturns PlayerbotWarlockAI::DoNextCombatManeuverPVE(Unit *pTarget)
{
    if (!m_botdata->GetAI())  return RETURN_NO_ACTION_ERROR;
    if (!m_botdata->GetBot()) return RETURN_NO_ACTION_ERROR;

    //Unit* pVictim = pTarget->getVictim();
    bool meleeReach = m_botdata->GetBot()->CanReachWithMeleeAttack(pTarget);
    Pet *pet = m_botdata->GetBot()->GetPet();
    uint32 spec = m_botdata->GetBot()->GetSpec();
    uint8 shardCount = m_botdata->GetBot()->GetItemCount(SOUL_SHARD, false, nullptr);

    //If we have UA it will replace immolate in our rotation
    uint32 FIRE = (UNSTABLE_AFFLICTION > 0 ? UNSTABLE_AFFLICTION : IMMOLATE);

    // Voidwalker is near death - sacrifice it for a shield
    if (pet && pet->GetEntry() == DEMON_VOIDWALKER && SACRIFICE && !m_botdata->GetBot()->HasAura(SACRIFICE) && pet->GetHealthPercent() < 10)
        m_botdata->GetAI()->CastPetSpell(SACRIFICE);

    // Use healthstone
    if (m_botdata->GetAI()->GetHealthPercent() < 30)
    {
        Item* healthStone = m_botdata->GetAI()->FindConsumable(HEALTHSTONE_DISPLAYID);
        if (healthStone)
            m_botdata->GetAI()->UseItem(healthStone);
    }

    // Voidwalker sacrifice gives shield - but you lose the pet (and it's DPS/tank) - use only as last resort for your own health!
    if (m_botdata->GetAI()->GetHealthPercent() < 20 && pet && pet->GetEntry() == DEMON_VOIDWALKER && SACRIFICE && !m_botdata->GetBot()->HasAura(SACRIFICE))
        m_botdata->GetAI()->CastPetSpell(SACRIFICE);

    if (m_botdata->GetAI()->GetCombatStyle() != PlayerbotAI::COMBAT_RANGED && !meleeReach)
        m_botdata->GetAI()->SetCombatStyle(PlayerbotAI::COMBAT_RANGED);
    // if in melee range OR can't shoot OR have no ranged (wand) equipped
    else if(m_botdata->GetAI()->GetCombatStyle() != PlayerbotAI::COMBAT_MELEE && (meleeReach || SHOOT == 0 || !m_botdata->GetBot()->GetWeaponForAttack(RANGED_ATTACK, true, true)))
        m_botdata->GetAI()->SetCombatStyle(PlayerbotAI::COMBAT_MELEE);

    //Used to determine if this bot is highest on threat
    Unit *newTarget = m_botdata->GetAI()->FindAttacker((PlayerbotAI::ATTACKERINFOTYPE) (PlayerbotAI::AIT_VICTIMSELF | PlayerbotAI::AIT_HIGHESTTHREAT), m_botdata->GetBot());
    if (newTarget) // TODO: && party has a tank
    {
        if (SOULSHATTER > 0 && shardCount > 0 && m_botdata->GetBot()->IsSpellReady(SOULSHATTER))
            if (CastSpell(SOULSHATTER, m_botdata->GetBot()))
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
    uint8 freeSpace = m_botdata->GetAI()->GetFreeBagSpace();
    if (DRAIN_SOUL && pTarget->GetHealth() < pTarget->GetMaxHealth() * 0.20 && m_botdata->GetAI()->In_Reach(pTarget, DRAIN_SOUL) && 
        !pTarget->HasAura(DRAIN_SOUL) && (shardCount < MAX_SHARD_COUNT && freeSpace > 0) && CastSpell(DRAIN_SOUL, pTarget))
    {
        m_botdata->GetAI()->SetIgnoreUpdateTime(15);
        return RETURN_CONTINUE;
    }

    // Damage Spells
    switch (spec)
    {
        case WARLOCK_SPEC_AFFLICTION:
            if (CURSE_OF_AGONY && m_botdata->GetAI()->In_Reach(pTarget,CURSE_OF_AGONY) && !pTarget->HasAura(CURSE_OF_AGONY) && CastSpell(CURSE_OF_AGONY, pTarget))
                return RETURN_CONTINUE;
            if (CORRUPTION && m_botdata->GetAI()->In_Reach(pTarget,CORRUPTION) && !pTarget->HasAura(CORRUPTION) && CastSpell(CORRUPTION, pTarget))
                return RETURN_CONTINUE;
            if (FIRE && m_botdata->GetAI()->In_Reach(pTarget,FIRE) && !pTarget->HasAura(FIRE) && CastSpell(FIRE, pTarget))
                return RETURN_CONTINUE;
            if (HAUNT && m_botdata->GetAI()->In_Reach(pTarget,HAUNT) && m_botdata->GetBot()->IsSpellReady(HAUNT) && CastSpell(HAUNT, pTarget))
                return RETURN_CONTINUE;
            if (SHADOW_BOLT && m_botdata->GetAI()->In_Reach(pTarget,SHADOW_BOLT) && CastSpell(SHADOW_BOLT, pTarget))
                return RETURN_CONTINUE;

            return RETURN_NO_ACTION_OK;

        case WARLOCK_SPEC_DEMONOLOGY:
            if (pet && DEMONIC_EMPOWERMENT && m_botdata->GetBot()->IsSpellReady(DEMONIC_EMPOWERMENT) && CastSpell(DEMONIC_EMPOWERMENT))
                return RETURN_CONTINUE;
            if (CURSE_OF_AGONY && m_botdata->GetAI()->In_Reach(pTarget,CURSE_OF_AGONY) && !pTarget->HasAura(CURSE_OF_AGONY) && CastSpell(CURSE_OF_AGONY, pTarget))
                return RETURN_CONTINUE;
            if (CORRUPTION && m_botdata->GetAI()->In_Reach(pTarget,CORRUPTION) && !pTarget->HasAura(CORRUPTION) && CastSpell(CORRUPTION, pTarget))
                return RETURN_CONTINUE;
            if (FIRE && m_botdata->GetAI()->In_Reach(pTarget,FIRE) && !pTarget->HasAura(FIRE) && CastSpell(FIRE, pTarget))
                return RETURN_CONTINUE;
            if (INCINERATE && m_botdata->GetAI()->In_Reach(pTarget,INCINERATE) && pTarget->HasAura(FIRE) && CastSpell(INCINERATE, pTarget))
                return RETURN_CONTINUE;
            if (SHADOW_BOLT && m_botdata->GetAI()->In_Reach(pTarget,SHADOW_BOLT) && CastSpell(SHADOW_BOLT, pTarget))
                return RETURN_CONTINUE;

            return RETURN_NO_ACTION_OK;

        case WARLOCK_SPEC_DESTRUCTION:
            if (CURSE_OF_AGONY && m_botdata->GetAI()->In_Reach(pTarget,CURSE_OF_AGONY) && !pTarget->HasAura(CURSE_OF_AGONY) && CastSpell(CURSE_OF_AGONY, pTarget))
                return RETURN_CONTINUE;
            if (CORRUPTION && m_botdata->GetAI()->In_Reach(pTarget,CORRUPTION) && !pTarget->HasAura(CORRUPTION) && CastSpell(CORRUPTION, pTarget))
                return RETURN_CONTINUE;
            if (FIRE && m_botdata->GetAI()->In_Reach(pTarget,FIRE) && !pTarget->HasAura(FIRE) && CastSpell(FIRE, pTarget))
                return RETURN_CONTINUE;
            if (CONFLAGRATE && m_botdata->GetAI()->In_Reach(pTarget,CONFLAGRATE) && pTarget->HasAura(FIRE) && m_botdata->GetBot()->IsSpellReady(CONFLAGRATE) && CastSpell(CONFLAGRATE, pTarget))
                return RETURN_CONTINUE;
            if (CHAOS_BOLT && m_botdata->GetAI()->In_Reach(pTarget,CHAOS_BOLT) && m_botdata->GetBot()->IsSpellReady(CHAOS_BOLT) && CastSpell(CHAOS_BOLT, pTarget))
                return RETURN_CONTINUE;
            if (INCINERATE && m_botdata->GetAI()->In_Reach(pTarget,INCINERATE) && pTarget->HasAura(FIRE) && CastSpell(INCINERATE, pTarget))
                return RETURN_CONTINUE;
            if (SHADOW_BOLT && m_botdata->GetAI()->In_Reach(pTarget,SHADOW_BOLT) && CastSpell(SHADOW_BOLT, pTarget))
                return RETURN_CONTINUE;

            return RETURN_NO_ACTION_OK;

            //if (LIFE_TAP && LastSpellAffliction < 1 && m_botdata->GetAI()->GetManaPercent() <= 50 && m_botdata->GetAI()->GetHealthPercent() > 50)
            //    m_botdata->GetAI()->CastSpell(LIFE_TAP, *m_botdata->GetBot());
            //else if (DRAIN_SOUL && pTarget->GetHealth() < pTarget->GetMaxHealth() * 0.40 && !pTarget->HasAura(DRAIN_SOUL) && LastSpellAffliction < 3)
            //    m_botdata->GetAI()->CastSpell(DRAIN_SOUL, *pTarget);
            //    //m_botdata->GetAI()->SetIgnoreUpdateTime(15);
            //else if (DRAIN_LIFE && LastSpellAffliction < 4 && !pTarget->HasAura(DRAIN_SOUL) && !pTarget->HasAura(SEED_OF_CORRUPTION) && !pTarget->HasAura(DRAIN_LIFE) && !pTarget->HasAura(DRAIN_MANA) && m_botdata->GetAI()->GetHealthPercent() <= 70)
            //    m_botdata->GetAI()->CastSpell(DRAIN_LIFE, *pTarget);
            //    //m_botdata->GetAI()->SetIgnoreUpdateTime(5);
            //else if (SEED_OF_CORRUPTION && !pTarget->HasAura(SEED_OF_CORRUPTION) && LastSpellAffliction < 7)
            //    m_botdata->GetAI()->CastSpell(SEED_OF_CORRUPTION, *pTarget);
            //else if (HOWL_OF_TERROR && !pTarget->HasAura(HOWL_OF_TERROR) && m_botdata->GetAI()->GetAttackerCount() > 3 && LastSpellAffliction < 8)
            //    m_botdata->GetAI()->CastSpell(HOWL_OF_TERROR, *pTarget);
            //    m_botdata->GetAI()->TellMaster("casting howl of terror!");
            //else if (FEAR && !pTarget->HasAura(FEAR) && pVictim == m_botdata->GetBot() && m_botdata->GetAI()->GetAttackerCount() >= 2 && LastSpellAffliction < 9)
            //    m_botdata->GetAI()->CastSpell(FEAR, *pTarget);
            //    //m_botdata->GetAI()->TellMaster("casting fear!");
            //    //m_botdata->GetAI()->SetIgnoreUpdateTime(1.5);
            //else if ((pet) && (DARK_PACT > 0 && m_botdata->GetAI()->GetManaPercent() <= 50 && LastSpellAffliction < 10 && pet->GetPower(POWER_MANA) > 0))
            //    m_botdata->GetAI()->CastSpell(DARK_PACT, *m_botdata->GetBot());
            //if (SHADOWFURY && LastSpellDestruction < 1 && !pTarget->HasAura(SHADOWFURY))
            //    m_botdata->GetAI()->CastSpell(SHADOWFURY, *pTarget);
            //else if (RAIN_OF_FIRE && LastSpellDestruction < 3 && m_botdata->GetAI()->GetAttackerCount() >= 3)
            //    m_botdata->GetAI()->CastSpell(RAIN_OF_FIRE, *pTarget);
            //    //m_botdata->GetAI()->TellMaster("casting rain of fire!");
            //    //m_botdata->GetAI()->SetIgnoreUpdateTime(8);
            //else if (SHADOWFLAME && !pTarget->HasAura(SHADOWFLAME) && LastSpellDestruction < 4)
            //    m_botdata->GetAI()->CastSpell(SHADOWFLAME, *pTarget);
            //else if (SEARING_PAIN && LastSpellDestruction < 8)
            //    m_botdata->GetAI()->CastSpell(SEARING_PAIN, *pTarget);
            //else if (SOUL_FIRE && LastSpellDestruction < 9)
            //    m_botdata->GetAI()->CastSpell(SOUL_FIRE, *pTarget);
            //    //m_botdata->GetAI()->SetIgnoreUpdateTime(6);
            //else if (SHADOWBURN && LastSpellDestruction < 11 && pTarget->GetHealth() < pTarget->GetMaxHealth() * 0.20 && !pTarget->HasAura(SHADOWBURN))
            //    m_botdata->GetAI()->CastSpell(SHADOWBURN, *pTarget);
            //else if (HELLFIRE && LastSpellDestruction < 12 && !m_botdata->GetBot()->HasAura(HELLFIRE) && m_botdata->GetAI()->GetAttackerCount() >= 5 && m_botdata->GetAI()->GetHealthPercent() >= 50)
            //    m_botdata->GetAI()->CastSpell(HELLFIRE);
            //    m_botdata->GetAI()->TellMaster("casting hellfire!");
            //    //m_botdata->GetAI()->SetIgnoreUpdateTime(15);
            //else if (CURSE_OF_THE_ELEMENTS && !pTarget->HasAura(CURSE_OF_THE_ELEMENTS) && !pTarget->HasAura(SHADOWFLAME) && !pTarget->HasAura(CURSE_OF_AGONY) && !pTarget->HasAura(CURSE_OF_WEAKNESS) && LastSpellCurse < 2)
            //    m_botdata->GetAI()->CastSpell(CURSE_OF_THE_ELEMENTS, *pTarget);
            //else if (CURSE_OF_WEAKNESS && !pTarget->HasAura(CURSE_OF_WEAKNESS) && !pTarget->HasAura(SHADOWFLAME) && !pTarget->HasAura(CURSE_OF_AGONY) && !pTarget->HasAura(CURSE_OF_THE_ELEMENTS) && LastSpellCurse < 3)
            //    m_botdata->GetAI()->CastSpell(CURSE_OF_WEAKNESS, *pTarget);
            //else if (CURSE_OF_TONGUES && !pTarget->HasAura(CURSE_OF_TONGUES) && !pTarget->HasAura(SHADOWFLAME) && !pTarget->HasAura(CURSE_OF_WEAKNESS) && !pTarget->HasAura(CURSE_OF_AGONY) && !pTarget->HasAura(CURSE_OF_THE_ELEMENTS) && LastSpellCurse < 4)
            //    m_botdata->GetAI()->CastSpell(CURSE_OF_TONGUES, *pTarget);
    }

    // No spec due to low level OR no spell found yet
    if (CORRUPTION && m_botdata->GetAI()->In_Reach(pTarget,CORRUPTION) && !pTarget->HasAura(CORRUPTION) && CastSpell(CORRUPTION, pTarget))
        return RETURN_CONTINUE;
    if (FIRE && m_botdata->GetAI()->In_Reach(pTarget,FIRE) && !pTarget->HasAura(FIRE) && CastSpell(FIRE, pTarget))
        return RETURN_CONTINUE;
    if (SHADOW_BOLT && m_botdata->GetAI()->In_Reach(pTarget,SHADOW_BOLT))
        return CastSpell(SHADOW_BOLT, pTarget);

    return RETURN_NO_ACTION_OK;
} // end DoNextCombatManeuver

CombatManeuverReturns PlayerbotWarlockAI::DoNextCombatManeuverPVP(Unit* pTarget)
{
    if (FEAR && m_botdata->GetAI()->In_Reach(pTarget,FEAR) && m_botdata->GetAI()->CastSpell(FEAR, *pTarget))
        return RETURN_CONTINUE;
    if (SHADOW_BOLT && m_botdata->GetAI()->In_Reach(pTarget,SHADOW_BOLT) && m_botdata->GetAI()->CastSpell(SHADOW_BOLT))
        return RETURN_CONTINUE;

    return DoNextCombatManeuverPVE(pTarget); // TODO: bad idea perhaps, but better than the alternative
}

CombatManeuverReturns PlayerbotWarlockAI::DoManeuver_Idle_SelfBuff(void)
{
	// Destroy extra soul shards
	uint8 shardCount = m_botdata->GetBot()->GetItemCount(SOUL_SHARD, false, nullptr);
	uint8 freeSpace = m_botdata->GetAI()->GetFreeBagSpace();

	if (shardCount > MAX_SHARD_COUNT || (freeSpace == 0 && shardCount > 1))
	{
		m_botdata->GetBot()->DestroyItemCount(SOUL_SHARD, shardCount > MAX_SHARD_COUNT ? shardCount - MAX_SHARD_COUNT : 1, true, false);
	}

	// buff myself DEMON_SKIN, DEMON_ARMOR, FEL_ARMOR - Strongest one available is chosen
	if (FEL_ARMOR)
	{
		if (m_botdata->GetAI()->SelfBuff(FEL_ARMOR))
		{
			return RETURN_CONTINUE;
		}
	}
	else if (DEMON_ARMOR)
	{
		if (m_botdata->GetAI()->SelfBuff(DEMON_ARMOR))
		{
			return RETURN_CONTINUE;
		}
	}
	else if (DEMON_SKIN)
	{
		if (m_botdata->GetAI()->SelfBuff(DEMON_SKIN))
		{
			return RETURN_CONTINUE;
		}
	}
	else
	{
		return RETURN_NO_ACTION_ERROR;
	}

	// healthstone creation
	if (CREATE_HEALTHSTONE && shardCount > 0)
	{
		Item* const healthStone = m_botdata->GetAI()->FindConsumable(HEALTHSTONE_DISPLAYID);

		if (!healthStone)
		{
			if (m_botdata->GetAI()->CastSpell(CREATE_HEALTHSTONE))
			{
				return RETURN_CONTINUE;
			}

			m_botdata->GetBot()->GetPlayerbotAI()->TellMaster("CastSpell(CREATE_HEALTHSTONE) - FAILED.");

			return RETURN_NO_ACTION_ERROR;
		}
	}

	// soulstone creation and use
	if (CREATE_SOULSTONE && shardCount > 0)
	{
		Item* soulStone = m_botdata->GetAI()->FindConsumable(SOULSTONE_DISPLAYID);

		if (!soulStone)
		{
			if (m_botdata->GetBot()->IsSpellReady(CREATE_SOULSTONE))
			{
				if (m_botdata->GetAI()->CastSpell(CREATE_SOULSTONE))
				{
					return RETURN_CONTINUE;
				}

				m_botdata->GetBot()->GetPlayerbotAI()->TellMaster("CastSpell(CREATE_SOULSTONE) - FAILED.");

				return RETURN_NO_ACTION_ERROR;
			}
		}
		else
		{
			uint32 soulStoneSpell = soulStone->GetProto()->Spells[0].SpellId;
			Player* master = m_botdata->GetMaster();

			// TODO: first choice: healer. Second choice: anyone else with revive spell. Third choice: self or master.
			if (!master->HasAura(soulStoneSpell))
			{
				if (m_botdata->GetBot()->IsSpellReady(soulStoneSpell))
				{
					m_botdata->GetAI()->UseItem(soulStone, master);

					return RETURN_CONTINUE;
				}
			}
		}
	}

	// Spellstone creation and use (Spellstone dominates firestone completely as I understand it)
	Item* const weapon = m_botdata->GetBot()->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);

	if (weapon && weapon->GetEnchantmentId(TEMP_ENCHANTMENT_SLOT) == 0)
	{
		Item* const stone = m_botdata->GetAI()->FindConsumable(SPELLSTONE_DISPLAYID);
		Item* const stone2 = m_botdata->GetAI()->FindConsumable(FIRESTONE_DISPLAYID);

		uint8 spellstone_count = m_botdata->GetBot()->GetItemCount(SPELLSTONE, false, nullptr);

		if (spellstone_count == 0)
			spellstone_count = m_botdata->GetBot()->GetItemCount(GREATER_SPELLSTONE, false, nullptr);
		if (spellstone_count == 0)
			spellstone_count = m_botdata->GetBot()->GetItemCount(MAJOR_SPELLSTONE, false, nullptr);

		uint8 firestone_count = m_botdata->GetBot()->GetItemCount(LESSER_FIRESTONE, false, nullptr);

		if (firestone_count == 0)
			firestone_count = m_botdata->GetBot()->GetItemCount(FIRESTONE, false, nullptr);
		if (firestone_count == 0)
			firestone_count = m_botdata->GetBot()->GetItemCount(GREATER_FIRESTONE, false, nullptr);
		if (firestone_count == 0)
			firestone_count = m_botdata->GetBot()->GetItemCount(MAJOR_FIRESTONE, false, nullptr);

		if (spellstone_count == 0 && firestone_count == 0)
		{
			if (shardCount > 0)
			{
				if (CREATE_SPELLSTONE)
				{
					m_botdata->GetBot()->GetPlayerbotAI()->TellMaster("Attempting to CREATE_SPELLSTONE.  Have %u already and stone (%u) stone2 (%u)", spellstone_count, stone, stone2);

					if (m_botdata->GetAI()->CastSpell(CREATE_SPELLSTONE))
					{
						return RETURN_CONTINUE;
					}

					m_botdata->GetBot()->GetPlayerbotAI()->TellMaster("CastSpell(CREATE_SPELLSTONE) - FAILED.");

					return RETURN_NO_ACTION_ERROR;
				}
				else if (CREATE_FIRESTONE)
				{
					m_botdata->GetBot()->GetPlayerbotAI()->TellMaster("Attempting to CREATE_FIRESTONE.  Have %u already and stone (%u) stone2 (%u)", firestone_count, stone, stone2);

					if (m_botdata->GetAI()->CastSpell(CREATE_FIRESTONE))
					{
						return RETURN_CONTINUE;
					}

					m_botdata->GetBot()->GetPlayerbotAI()->TellMaster("CastSpell(CREATE_FIRESTONE) - FAILED.");

					return RETURN_NO_ACTION_ERROR;
				}
				else
				{
					m_botdata->GetBot()->GetPlayerbotAI()->TellMaster("CREATE_SPELLSTONE and CREATE_FIRESTONE uninitialized.");

					return RETURN_NO_ACTION_ERROR;
				}

			}
		}
		else if (stone)
		{
			m_botdata->GetBot()->GetPlayerbotAI()->TellMaster("Attempting to UseItem(stone, EQUIPMENT_SLOT_MAINHAND).");

			//m_botdata->GetAI()->UseItem(stone, EQUIPMENT_SLOT_OFFHAND);
			m_botdata->GetAI()->UseItem(stone, EQUIPMENT_SLOT_MAINHAND);

			return RETURN_CONTINUE;
		}
		else if (stone2)
		{
			m_botdata->GetBot()->GetPlayerbotAI()->TellMaster("Attempting to UseItem(stone2, EQUIPMENT_SLOT_MAINHAND).");

			//m_botdata->GetAI()->UseItem(stone2, EQUIPMENT_SLOT_OFFHAND);
			m_botdata->GetAI()->UseItem(stone2, EQUIPMENT_SLOT_MAINHAND);

			return RETURN_CONTINUE;
		}
	}

	Pet *pet = m_botdata->GetBot()->GetPet();

	// hp/mana check
	if (pet && DARK_PACT && (pet->GetPower(POWER_MANA) / pet->GetMaxPower(POWER_MANA)) > 40 && m_botdata->GetAI()->GetManaPercent() <= 50)
	{
		if (m_botdata->GetAI()->CastSpell(DARK_PACT, *m_botdata->GetBot()))
		{
			return RETURN_CONTINUE;
		}
	}

	if (LIFE_TAP && m_botdata->GetAI()->GetManaPercent() <= 60 && m_botdata->GetAI()->GetHealthPercent() > 60)
	{
		if (m_botdata->GetAI()->CastSpell(LIFE_TAP, *m_botdata->GetBot()))
		{
			return RETURN_CONTINUE;
		}
	}

	return RETURN_NO_ACTION_OK;
}

CombatManeuverReturns PlayerbotWarlockAI::DoManeuver_Idle_Pet_Summon(void)
{
	CombatManeuverReturns ret_val;
	uint32	m_demonOfChoice;  // Preferred demon entry

	//Assign demon of choice
	if (m_botdata->GetSpec() == WARLOCK_SPEC_AFFLICTION)
	{
		m_demonOfChoice = DEMON_FELHUNTER;
	}
	else if (m_botdata->GetSpec() == WARLOCK_SPEC_DEMONOLOGY)
	{
		m_demonOfChoice = (DEMON_FELGUARD > 0 ? DEMON_FELGUARD : DEMON_SUCCUBUS);
	}
	else
	{
		m_demonOfChoice = DEMON_IMP;
	}

	Pet *pet		 = m_botdata->GetBot()->GetPet();

	// Summon demon
	if (!pet ||  pet->GetEntry() != m_demonOfChoice)
	{
		uint8  shardCount = m_botdata->GetBot()->GetItemCount(SOUL_SHARD, false, nullptr);
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

		}
		else
		{
			summonSpellId = SUMMON_IMP;
		}

		if (summonSpellId)
		{
			if (m_botdata->GetAI()->CastSpell(summonSpellId))
			{
				pet = m_botdata->GetBot()->GetPet();

				if (!pet)
				{
					ret_val = RETURN_NO_ACTION_ERROR;
				}
				else
				{
					ret_val = RETURN_CONTINUE;
				}
			}
			else
			{
				ret_val = RETURN_NO_ACTION_ERROR;
			}
		}
		else
		{
			ret_val = RETURN_NO_ACTION_ERROR;
		}
	}
	else
	{
		ret_val = RETURN_NO_ACTION_OK;
	}

	// Initialize pet spells
	if (pet && pet->GetEntry() != m_lastDemon)
	{
		switch (pet->GetEntry())
		{
			case DEMON_IMP:
				BLOOD_PACT = m_botdata->GetAI()->initPetSpell(BLOOD_PACT_ICON);
				FIREBOLT = m_botdata->GetAI()->initPetSpell(FIREBOLT_ICON);
				FIRE_SHIELD = m_botdata->GetAI()->initPetSpell(FIRE_SHIELD_ICON);
				break;

			case DEMON_VOIDWALKER:
				CONSUME_SHADOWS = m_botdata->GetAI()->initPetSpell(CONSUME_SHADOWS_ICON);
				SACRIFICE = m_botdata->GetAI()->initPetSpell(SACRIFICE_ICON);
				SUFFERING = m_botdata->GetAI()->initPetSpell(SUFFERING_ICON);
				TORMENT = m_botdata->GetAI()->initPetSpell(TORMENT_ICON);
				break;

			case DEMON_SUCCUBUS:
				LASH_OF_PAIN = m_botdata->GetAI()->initPetSpell(LASH_OF_PAIN_ICON);
				SEDUCTION = m_botdata->GetAI()->initPetSpell(SEDUCTION_ICON);
				SOOTHING_KISS = m_botdata->GetAI()->initPetSpell(SOOTHING_KISS_ICON);
				break;

			case DEMON_FELHUNTER:
				DEVOUR_MAGIC = m_botdata->GetAI()->initPetSpell(DEVOUR_MAGIC_ICON);
				FEL_INTELLIGENCE = m_botdata->GetAI()->initPetSpell(FEL_INTELLIGENCE_ICON);
				SHADOW_BITE = m_botdata->GetAI()->initPetSpell(SHADOW_BITE_ICON);
				SPELL_LOCK = m_botdata->GetAI()->initPetSpell(SPELL_LOCK_ICON);
				break;

			case DEMON_FELGUARD:
				ANGUISH = m_botdata->GetAI()->initPetSpell(ANGUISH_ICON);
				CLEAVE = m_botdata->GetAI()->initPetSpell(CLEAVE_ICON);
				INTERCEPT = m_botdata->GetAI()->initPetSpell(INTERCEPT_ICON);
				break;
		}

		m_lastDemon = pet->GetEntry();

		ret_val = RETURN_CONTINUE;
	}

	return ret_val;
}


CombatManeuverReturns PlayerbotWarlockAI::DoManeuver_Idle_Pet_BuffnHeal(void)
{
	Pet *pet = m_botdata->GetBot()->GetPet();

    //Heal Voidwalker
	if (pet && pet->GetEntry() == DEMON_VOIDWALKER && CONSUME_SHADOWS && pet->GetHealthPercent() < 75 && !pet->HasAura(CONSUME_SHADOWS))
	{
		m_botdata->GetAI()->CastPetSpell(CONSUME_SHADOWS);
	}

    // Soul link demon
	if (pet && SOUL_LINK && !m_botdata->GetBot()->HasAura(SOUL_LINK_AURA) && m_botdata->GetAI()->CastSpell(SOUL_LINK, *m_botdata->GetBot()))
	{
		return RETURN_CONTINUE;
	}

    // Check demon buffs
	if (pet && pet->GetEntry() == DEMON_IMP && BLOOD_PACT && !m_botdata->GetBot()->HasAura(BLOOD_PACT) && m_botdata->GetAI()->CastPetSpell(BLOOD_PACT))
	{
		return RETURN_CONTINUE;
	}

	if (pet && pet->GetEntry() == DEMON_FELHUNTER && FEL_INTELLIGENCE && !m_botdata->GetBot()->HasAura(FEL_INTELLIGENCE) && m_botdata->GetAI()->CastPetSpell(FEL_INTELLIGENCE))
	{
		return RETURN_CONTINUE;
	}

	return RETURN_NO_ACTION_OK;
} 