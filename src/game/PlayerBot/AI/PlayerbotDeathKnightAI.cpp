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

#include "PlayerbotDeathKnightAI.h"
#include "../Base/PlayerbotMgr.h"

class PlayerbotAI;
PlayerbotDeathKnightAI::PlayerbotDeathKnightAI(Player* const master, Player* const bot, PlayerbotAI* const ai) : PlayerbotClassAI(master, bot, ai)
{

    PLAGUE_STRIKE     = GetAI()->initSpell(PLAGUE_STRIKE_1); // Unholy
    DEATH_GRIP        = GetAI()->initSpell(DEATH_GRIP_1);
    DEATH_COIL        = GetAI()->initSpell(DEATH_COIL_DEATH_KNIGHT_1);
    DEATH_STRIKE      = GetAI()->initSpell(DEATH_STRIKE_1);
    UNHOLY_BLIGHT     = 0; // Passive
    SCOURGE_STRIKE    = GetAI()->initSpell(SCOURGE_STRIKE_1);
    DEATH_AND_DECAY   = GetAI()->initSpell(DEATH_AND_DECAY_1);
    CORPSE_EXPLOSION  = GetAI()->initSpell(CORPSE_EXPLOSION_1);
    BONE_SHIELD       = GetAI()->initSpell(BONE_SHIELD_1); // buffs
    ANTI_MAGIC_SHELL  = GetAI()->initSpell(ANTI_MAGIC_SHELL_1);
    ANTI_MAGIC_ZONE   = GetAI()->initSpell(ANTI_MAGIC_ZONE_1);
    GHOUL_FRENZY      = GetAI()->initSpell(GHOUL_FRENZY_1);
    RAISE_DEAD        = GetAI()->initSpell(RAISE_DEAD_1); // pets
    SUMMON_GARGOYLE   = GetAI()->initSpell(SUMMON_GARGOYLE_1);
    ARMY_OF_THE_DEAD  = GetAI()->initSpell(ARMY_OF_THE_DEAD_1);
    ICY_TOUCH         = GetAI()->initSpell(ICY_TOUCH_1); // Frost
    OBLITERATE        = GetAI()->initSpell(OBLITERATE_1);
    HOWLING_BLAST     = GetAI()->initSpell(HOWLING_BLAST_1);
    FROST_STRIKE      = GetAI()->initSpell(FROST_STRIKE_1);
    CHAINS_OF_ICE     = GetAI()->initSpell(CHAINS_OF_ICE_1);
    RUNE_STRIKE       = GetAI()->initSpell(RUNE_STRIKE_1);
    ICY_CLUTCH        = 0; // No such spell
    MIND_FREEZE       = GetAI()->initSpell(MIND_FREEZE_1);
    HUNGERING_COLD    = GetAI()->initSpell(HUNGERING_COLD_1);
    KILLING_MACHINE   = 0; // Passive
    DEATHCHILL        = GetAI()->initSpell(DEATHCHILL_1);
    HORN_OF_WINTER    = GetAI()->initSpell(HORN_OF_WINTER_1);
    ICEBOUND_FORTITUDE = GetAI()->initSpell(ICEBOUND_FORTITUDE_1);
    EMPOWER_WEAPON    = GetAI()->initSpell(EMPOWER_RUNE_WEAPON_1);
    UNBREAKABLE_ARMOR = GetAI()->initSpell(UNBREAKABLE_ARMOR_1);
    BLOOD_STRIKE      = GetAI()->initSpell(BLOOD_STRIKE_1); // Blood
    PESTILENCE        = GetAI()->initSpell(PESTILENCE_1);
    STRANGULATE       = GetAI()->initSpell(STRANGULATE_1);
    BLOOD_BOIL        = GetAI()->initSpell(BLOOD_BOIL_1);
    HEART_STRIKE      = GetAI()->initSpell(HEART_STRIKE_1);
    DANCING_WEAPON    = GetAI()->initSpell(DANCING_RUNE_WEAPON_1);
    DARK_COMMAND      = GetAI()->initSpell(DARK_COMMAND_1);
    MARK_OF_BLOOD     = GetAI()->initSpell(MARK_OF_BLOOD_1); // buffs
    RUNE_TAP          = GetAI()->initSpell(RUNE_TAP_1);
    VAMPIRIC_BLOOD    = GetAI()->initSpell(VAMPIRIC_BLOOD_1);
    DEATH_PACT        = GetAI()->initSpell(DEATH_PACT_1);
    HYSTERIA          = GetAI()->initSpell(HYSTERIA_1);
    UNHOLY_PRESENCE   = GetAI()->initSpell(UNHOLY_PRESENCE_1); // presence (TODO: better spell == presence)
    FROST_PRESENCE    = GetAI()->initSpell(FROST_PRESENCE_1);
    BLOOD_PRESENCE    = GetAI()->initSpell(BLOOD_PRESENCE_1);

    RECENTLY_BANDAGED = 11196; // first aid check

    // racial
    ARCANE_TORRENT          = GetAI()->initSpell(ARCANE_TORRENT_DEATH_KNIGHT); // blood elf
    GIFT_OF_THE_NAARU       = GetAI()->initSpell(GIFT_OF_THE_NAARU_DEATH_KNIGHT); // draenei
    STONEFORM               = GetAI()->initSpell(STONEFORM_ALL); // dwarf
    ESCAPE_ARTIST           = GetAI()->initSpell(ESCAPE_ARTIST_ALL); // gnome
    EVERY_MAN_FOR_HIMSELF   = GetAI()->initSpell(EVERY_MAN_FOR_HIMSELF_ALL); // human
    BLOOD_FURY              = GetAI()->initSpell(BLOOD_FURY_MELEE_CLASSES); // orc
    WAR_STOMP               = GetAI()->initSpell(WAR_STOMP_ALL); // tauren
    BERSERKING              = GetAI()->initSpell(BERSERKING_ALL); // troll
    WILL_OF_THE_FORSAKEN    = GetAI()->initSpell(WILL_OF_THE_FORSAKEN_ALL); // undead
}

PlayerbotDeathKnightAI::~PlayerbotDeathKnightAI() {}

CombatManeuverReturns PlayerbotDeathKnightAI::DoFirstCombatManeuverPVE(Unit* /*pTarget*/)
{
    return RETURN_NO_ACTION_OK;
}

CombatManeuverReturns PlayerbotDeathKnightAI::DoFirstCombatManeuverPVP(Unit* /*pTarget*/)
{
    return RETURN_NO_ACTION_OK;
}

CombatManeuverReturns PlayerbotDeathKnightAI::DoNextCombatManeuverPVE(Unit *pTarget)
{
    if (!GetAI())  return RETURN_NO_ACTION_ERROR;
    if (!m_bot) return RETURN_NO_ACTION_ERROR;

    // DK Attacks: Unholy, Frost & Blood

    // damage spells
    Unit* pVictim = pTarget->getVictim();
    Pet *pet = m_bot->GetPet();
    float dist = m_bot->GetCombatDistance(pTarget, true);
    std::ostringstream out;

    switch (SpellSequence)
    {
        case SPELL_DK_UNHOLY:
            if (UNHOLY_PRESENCE > 0 && !m_bot->HasAura(UNHOLY_PRESENCE, EFFECT_INDEX_0) && !m_bot->HasAura(BLOOD_PRESENCE, EFFECT_INDEX_0) && !m_bot->HasAura(FROST_PRESENCE, EFFECT_INDEX_0) && GetAI()->CastSpell(UNHOLY_PRESENCE, *m_bot))
                return RETURN_CONTINUE;

            // check for BONE_SHIELD in combat
            if (BONE_SHIELD > 0 && !m_bot->HasAura(BONE_SHIELD, EFFECT_INDEX_0) && !m_bot->HasAura(ARMY_OF_THE_DEAD, EFFECT_INDEX_0) && GetAI()->CastSpell(BONE_SHIELD, *m_bot))
                return RETURN_CONTINUE;

            if (ARMY_OF_THE_DEAD > 0 && GetAI()->GetAttackerCount() >= 5 && LastSpellUnholyDK < 1 && GetAI()->CastSpell(ARMY_OF_THE_DEAD) && m_bot->HasAura(ARMY_OF_THE_DEAD, EFFECT_INDEX_0))
            {
                out << " summoning Army of the Dead!";
                GetAI()->SetIgnoreUpdateTime(7);
                SpellSequence = SPELL_DK_FROST;
                LastSpellUnholyDK = LastSpellUnholyDK + 1;
                return RETURN_CONTINUE;
            }
            if (PLAGUE_STRIKE > 0 && !pTarget->HasAura(PLAGUE_STRIKE, EFFECT_INDEX_0) && LastSpellUnholyDK < 2 && GetAI()->CastSpell(PLAGUE_STRIKE, *pTarget))
            {
                out << " Plague Strike";
                SpellSequence = SPELL_DK_FROST;
                LastSpellUnholyDK = LastSpellUnholyDK + 1;
                return RETURN_CONTINUE;
            }
            if (DEATH_GRIP > 0 && !pTarget->HasAura(DEATH_GRIP, EFFECT_INDEX_0) && LastSpellUnholyDK < 3 && GetAI()->CastSpell(DEATH_GRIP, *pTarget))
            {
                out << " Death Grip";
                SpellSequence = SPELL_DK_FROST;
                LastSpellUnholyDK = LastSpellUnholyDK + 1;
                return RETURN_CONTINUE;
            }
            if (DEATH_COIL > 0 && LastSpellUnholyDK < 4 && GetAI()->CastSpell(DEATH_COIL, *pTarget))
            {
                out << " Death Coil";
                SpellSequence = SPELL_DK_FROST;
                LastSpellUnholyDK = LastSpellUnholyDK + 1;
                return RETURN_CONTINUE;
            }
            if (DEATH_STRIKE > 0 && !pTarget->HasAura(DEATH_STRIKE, EFFECT_INDEX_0) && LastSpellUnholyDK < 5 && GetAI()->CastSpell(DEATH_STRIKE, *pTarget))
            {
                out << " Death Strike";
                SpellSequence = SPELL_DK_FROST;
                LastSpellUnholyDK = LastSpellUnholyDK + 1;
                return RETURN_CONTINUE;
            }
            if (UNHOLY_BLIGHT > 0 && !pTarget->HasAura(UNHOLY_BLIGHT, EFFECT_INDEX_0) && LastSpellUnholyDK < 6 && GetAI()->CastSpell(UNHOLY_BLIGHT))
            {
                out << " Unholy Blight";
                SpellSequence = SPELL_DK_FROST;
                LastSpellUnholyDK = LastSpellUnholyDK + 1;
                return RETURN_CONTINUE;
            }
            if (SCOURGE_STRIKE > 0 && LastSpellUnholyDK < 7 && GetAI()->CastSpell(SCOURGE_STRIKE, *pTarget))
            {
                out << " Scourge Strike";
                SpellSequence = SPELL_DK_FROST;
                LastSpellUnholyDK = LastSpellUnholyDK + 1;
                return RETURN_CONTINUE;
            }
            if (DEATH_AND_DECAY > 0 && GetAI()->GetAttackerCount() >= 3 && dist <= ATTACK_DISTANCE && !pTarget->HasAura(DEATH_AND_DECAY, EFFECT_INDEX_0) && LastSpellUnholyDK < 8 && GetAI()->CastSpell(DEATH_AND_DECAY))
            {
                out << " Death and Decay";
                GetAI()->SetIgnoreUpdateTime(1);
                SpellSequence = SPELL_DK_FROST;
                LastSpellUnholyDK = LastSpellUnholyDK + 1;
                return RETURN_CONTINUE;
            }
            if (SUMMON_GARGOYLE > 0 && !m_bot->HasAura(ARMY_OF_THE_DEAD, EFFECT_INDEX_0) && !pTarget->HasAura(SUMMON_GARGOYLE, EFFECT_INDEX_0) && LastSpellUnholyDK < 9 && GetAI()->CastSpell(SUMMON_GARGOYLE, *pTarget))
            {
                out << " summoning Gargoyle";
                GetAI()->SetIgnoreUpdateTime(2);
                SpellSequence = SPELL_DK_FROST;
                LastSpellUnholyDK = LastSpellUnholyDK + 1;
                return RETURN_CONTINUE;
            }
            if (CORPSE_EXPLOSION > 0 && dist <= ATTACK_DISTANCE && LastSpellUnholyDK < 10 && GetAI()->CastSpell(CORPSE_EXPLOSION, *pTarget))
            {
                out << " Corpse Explosion";
                SpellSequence = SPELL_DK_FROST;
                LastSpellUnholyDK = LastSpellUnholyDK + 1;
                return RETURN_CONTINUE;
            }
            if (ANTI_MAGIC_SHELL > 0 && pTarget->IsNonMeleeSpellCasted(true) && !m_bot->HasAura(ANTI_MAGIC_SHELL, EFFECT_INDEX_0) && LastSpellUnholyDK < 11 && GetAI()->CastSpell(ANTI_MAGIC_SHELL, *m_bot))
            {
                out << " Anti-Magic Shell";
                SpellSequence = SPELL_DK_FROST;
                LastSpellUnholyDK = LastSpellUnholyDK + 1;
                return RETURN_CONTINUE;
            }
            if (ANTI_MAGIC_ZONE > 0 && pTarget->IsNonMeleeSpellCasted(true) && !m_bot->HasAura(ANTI_MAGIC_SHELL, EFFECT_INDEX_0) && LastSpellUnholyDK < 12 && GetAI()->CastSpell(ANTI_MAGIC_ZONE, *m_bot))
            {
                out << " Anti-Magic Zone";
                SpellSequence = SPELL_DK_FROST;
                LastSpellUnholyDK = LastSpellUnholyDK + 1;
                return RETURN_CONTINUE;
            }
            if (!pet && RAISE_DEAD > 0 && !m_bot->HasAura(ARMY_OF_THE_DEAD, EFFECT_INDEX_0) && LastSpellUnholyDK < 13 && GetAI()->CastSpell(RAISE_DEAD))
            {
                out << " summoning Ghoul";
                SpellSequence = SPELL_DK_FROST;
                LastSpellUnholyDK = LastSpellUnholyDK + 1;
                return RETURN_CONTINUE;
            }
            if (pet && GHOUL_FRENZY > 0 && pVictim == pet && !pet->HasAura(GHOUL_FRENZY, EFFECT_INDEX_0) && LastSpellUnholyDK < 14 && GetAI()->CastSpell(GHOUL_FRENZY, *pet))
            {
                out << " casting Ghoul Frenzy on pet";
                SpellSequence = SPELL_DK_FROST;
                LastSpellUnholyDK = LastSpellUnholyDK + 1;
                return RETURN_CONTINUE;
            }
            if (LastSpellUnholyDK > 15)
            {
                LastSpellUnholyDK = 0;
                SpellSequence = SPELL_DK_FROST;
                return RETURN_NO_ACTION_OK; // Not really OK but that's just how the DK rotation works right now
            }

            LastSpellUnholyDK = 0;

        case SPELL_DK_FROST:
            if (FROST_PRESENCE > 0 && !m_bot->HasAura(FROST_PRESENCE, EFFECT_INDEX_0) && !m_bot->HasAura(BLOOD_PRESENCE, EFFECT_INDEX_0) && !m_bot->HasAura(UNHOLY_PRESENCE, EFFECT_INDEX_0) && GetAI()->CastSpell (FROST_PRESENCE, *m_bot))
                return RETURN_CONTINUE;

            if (DEATHCHILL > 0)
            {
                if (!m_bot->HasAura(DEATHCHILL, EFFECT_INDEX_0) && !m_bot->HasAura(KILLING_MACHINE, EFFECT_INDEX_0) && GetAI()->CastSpell (DEATHCHILL, *m_bot))
                    return RETURN_CONTINUE;
            }
            else if (KILLING_MACHINE > 0)
            {
                if (!m_bot->HasAura(KILLING_MACHINE, EFFECT_INDEX_0) && !m_bot->HasAura(DEATHCHILL, EFFECT_INDEX_0) && GetAI()->CastSpell (KILLING_MACHINE, *m_bot))
                    return RETURN_CONTINUE;
            }

            if (ICY_TOUCH > 0 && !pTarget->HasAura(ICY_TOUCH, EFFECT_INDEX_0) && LastSpellFrostDK < 1 && GetAI()->CastSpell(ICY_TOUCH, *pTarget))
            {
                out << " Icy Touch";
                SpellSequence = SPELL_DK_BLOOD;
                LastSpellFrostDK = LastSpellFrostDK + 1;
                return RETURN_CONTINUE;
            }
            if (OBLITERATE > 0 && LastSpellFrostDK < 2 && GetAI()->CastSpell(OBLITERATE, *pTarget))
            {
                out << " Obliterate";
                SpellSequence = SPELL_DK_BLOOD;
                LastSpellFrostDK = LastSpellFrostDK + 1;
                return RETURN_CONTINUE;
            }
            if (FROST_STRIKE > 0 && LastSpellFrostDK < 3 && GetAI()->CastSpell(FROST_STRIKE, *pTarget))
            {
                out << " Frost Strike";
                SpellSequence = SPELL_DK_BLOOD;
                LastSpellFrostDK = LastSpellFrostDK + 1;
                return RETURN_CONTINUE;
            }
            if (HOWLING_BLAST > 0 && GetAI()->GetAttackerCount() >= 3 && LastSpellFrostDK < 4 && GetAI()->CastSpell(HOWLING_BLAST, *pTarget))
            {
                out << " Howling Blast";
                SpellSequence = SPELL_DK_BLOOD;
                LastSpellFrostDK = LastSpellFrostDK + 1;
                return RETURN_CONTINUE;
            }
            if (CHAINS_OF_ICE > 0 && !pTarget->HasAura(CHAINS_OF_ICE, EFFECT_INDEX_0) && LastSpellFrostDK < 5 && GetAI()->CastSpell(CHAINS_OF_ICE, *pTarget))
            {
                out << " Chains of Ice";
                SpellSequence = SPELL_DK_BLOOD;
                LastSpellFrostDK = LastSpellFrostDK + 1;
                return RETURN_CONTINUE;
            }
            if (RUNE_STRIKE > 0 && LastSpellFrostDK < 6 && GetAI()->CastSpell(RUNE_STRIKE, *pTarget))
            {
                out << " Rune Strike";
                SpellSequence = SPELL_DK_BLOOD;
                LastSpellFrostDK = LastSpellFrostDK + 1;
                return RETURN_CONTINUE;
            }
            if (ICY_CLUTCH > 0 && !pTarget->HasAura(ICY_CLUTCH, EFFECT_INDEX_0) && LastSpellFrostDK < 7 && GetAI()->CastSpell(ICY_CLUTCH, *pTarget))
            {
                out << " Icy Clutch";
                SpellSequence = SPELL_DK_BLOOD;
                LastSpellFrostDK = LastSpellFrostDK + 1;
                return RETURN_CONTINUE;
            }
            if (ICEBOUND_FORTITUDE > 0 && GetAI()->GetHealthPercent() < 50 && pVictim == m_bot && !m_bot->HasAura(ICEBOUND_FORTITUDE, EFFECT_INDEX_0) && LastSpellFrostDK < 8 && GetAI()->CastSpell(ICEBOUND_FORTITUDE, *m_bot))
            {
                out << " Icebound Fortitude";
                SpellSequence = SPELL_DK_BLOOD;
                LastSpellFrostDK = LastSpellFrostDK + 1;
                return RETURN_CONTINUE;
            }
            if (MIND_FREEZE > 0 && pTarget->IsNonMeleeSpellCasted(true) && dist <= ATTACK_DISTANCE && LastSpellFrostDK < 9 && GetAI()->CastSpell(MIND_FREEZE, *pTarget))
            {
                out << " Mind Freeze";
                SpellSequence = SPELL_DK_BLOOD;
                LastSpellFrostDK = LastSpellFrostDK + 1;
                return RETURN_CONTINUE;
            }
            if (HUNGERING_COLD > 0 && GetAI()->GetAttackerCount() >= 3 && dist <= ATTACK_DISTANCE && LastSpellFrostDK < 10 && GetAI()->CastSpell(HUNGERING_COLD, *pTarget))
            {
                out << " Hungering Cold";
                SpellSequence = SPELL_DK_BLOOD;
                LastSpellFrostDK = LastSpellFrostDK + 1;
                return RETURN_CONTINUE;
            }
            if (EMPOWER_WEAPON > 0 && LastSpellFrostDK < 11 && GetAI()->CastSpell(EMPOWER_WEAPON, *m_bot))
            {
                out << " Empower Rune Weapon";
                SpellSequence = SPELL_DK_BLOOD;
                LastSpellFrostDK = LastSpellFrostDK + 1;
                return RETURN_CONTINUE;
            }
            if (UNBREAKABLE_ARMOR > 0 && !m_bot->HasAura(UNBREAKABLE_ARMOR, EFFECT_INDEX_0) && GetAI()->GetHealthPercent() < 70 && pVictim == m_bot && LastSpellFrostDK < 12 && GetAI()->CastSpell(UNBREAKABLE_ARMOR, *m_bot))
            {
                out << " Unbreakable Armor";
                SpellSequence = SPELL_DK_BLOOD;
                LastSpellFrostDK = LastSpellFrostDK + 1;
                return RETURN_CONTINUE;
            }
            if (LastSpellFrostDK > 13)
            {
                LastSpellFrostDK = 0;
                SpellSequence = SPELL_DK_BLOOD;
                return RETURN_NO_ACTION_OK; // Not really OK, but that's just how the DK rotation works right now
            }

            LastSpellFrostDK = 0;

        case SPELL_DK_BLOOD:
            if (BLOOD_PRESENCE > 0 && !m_bot->HasAura(BLOOD_PRESENCE, EFFECT_INDEX_0) && !m_bot->HasAura(UNHOLY_PRESENCE, EFFECT_INDEX_0) && !m_bot->HasAura(FROST_PRESENCE, EFFECT_INDEX_0) && GetAI()->CastSpell (BLOOD_PRESENCE, *m_bot))
                return RETURN_CONTINUE;

            if (MARK_OF_BLOOD > 0 && !pTarget->HasAura(MARK_OF_BLOOD, EFFECT_INDEX_0) && LastSpellBloodDK < 1 && GetAI()->CastSpell(MARK_OF_BLOOD, *pTarget))
            {
                out << " Mark of Blood";
                SpellSequence = SPELL_DK_UNHOLY;
                LastSpellBloodDK = LastSpellBloodDK + 1;
                return RETURN_CONTINUE;
            }
            if (BLOOD_STRIKE > 0 && LastSpellBloodDK < 2 && GetAI()->CastSpell(BLOOD_STRIKE, *pTarget))
            {
                out << " Blood Strike";
                SpellSequence = SPELL_DK_UNHOLY;
                LastSpellBloodDK =  LastSpellBloodDK + 1;
                return RETURN_CONTINUE;
            }
            if (PESTILENCE > 0 && GetAI()->GetAttackerCount() >= 3 && LastSpellBloodDK < 3 && GetAI()->CastSpell(PESTILENCE, *pTarget))
            {
                out << " Pestilence";
                SpellSequence = SPELL_DK_UNHOLY;
                LastSpellBloodDK = LastSpellBloodDK + 1;
                return RETURN_CONTINUE;
            }
            if (STRANGULATE > 0 && !pTarget->HasAura(STRANGULATE, EFFECT_INDEX_0) && LastSpellBloodDK < 4 && GetAI()->CastSpell(STRANGULATE, *pTarget))
            {
                out << " Strangulate";
                SpellSequence = SPELL_DK_UNHOLY;
                LastSpellBloodDK = LastSpellBloodDK + 1;
                return RETURN_CONTINUE;
            }
            if (BLOOD_BOIL > 0 && GetAI()->GetAttackerCount() >= 5 && dist <= ATTACK_DISTANCE && LastSpellBloodDK < 5 && GetAI()->CastSpell(BLOOD_BOIL, *pTarget))
            {
                out << " Blood Boil";
                SpellSequence = SPELL_DK_UNHOLY;
                LastSpellBloodDK = LastSpellBloodDK + 1;
                return RETURN_CONTINUE;
            }
            if (HEART_STRIKE > 0 && LastSpellBloodDK < 6 && GetAI()->CastSpell(HEART_STRIKE, *pTarget))
            {
                out << " Heart Strike";
                SpellSequence = SPELL_DK_UNHOLY;
                LastSpellBloodDK = LastSpellBloodDK + 1;
                return RETURN_CONTINUE;
            }
            if (VAMPIRIC_BLOOD > 0 && GetAI()->GetHealthPercent() < 70 && !m_bot->HasAura(VAMPIRIC_BLOOD, EFFECT_INDEX_0) && LastSpellBloodDK < 7 && GetAI()->CastSpell(VAMPIRIC_BLOOD, *m_bot))
            {
                out << " Vampiric Blood";
                SpellSequence = SPELL_DK_UNHOLY;
                LastSpellBloodDK = LastSpellBloodDK + 1;
                return RETURN_CONTINUE;
            }
            if (RUNE_TAP > 0 && GetAI()->GetHealthPercent() < 70 && !m_bot->HasAura(VAMPIRIC_BLOOD, EFFECT_INDEX_0) && LastSpellBloodDK < 8 && GetAI()->CastSpell(RUNE_TAP, *m_bot))
            {
                out << " Rune Tap";
                SpellSequence = SPELL_DK_UNHOLY;
                LastSpellBloodDK = LastSpellBloodDK + 1;
                return RETURN_CONTINUE;
            }
            if (HYSTERIA > 0 && GetAI()->GetHealthPercent() > 25 && !m_bot->HasAura(HYSTERIA, EFFECT_INDEX_0) && LastSpellBloodDK < 9 && GetAI()->CastSpell(HYSTERIA, *m_bot))
            {
                out << " Hysteria";
                SpellSequence = SPELL_DK_UNHOLY;
                LastSpellBloodDK = LastSpellBloodDK + 1;
                return RETURN_CONTINUE;
            }
            if (DANCING_WEAPON > 0 && !m_bot->HasAura(DANCING_WEAPON, EFFECT_INDEX_0) && LastSpellBloodDK < 10 && GetAI()->CastSpell(DANCING_WEAPON, *pTarget))
            {
                out << " summoning Dancing Rune Weapon";
                SpellSequence = SPELL_DK_UNHOLY;
                LastSpellBloodDK = LastSpellBloodDK + 1;
                return RETURN_CONTINUE;
            }
            if (DARK_COMMAND > 0 && GetAI()->GetHealthPercent() > 50 && pVictim != m_bot && !pTarget->HasAura(DARK_COMMAND, EFFECT_INDEX_0) && LastSpellBloodDK < 11 && GetAI()->CastSpell(DARK_COMMAND, *pTarget))
            {
                out << " Dark Command";
                SpellSequence = SPELL_DK_UNHOLY;
                LastSpellBloodDK = LastSpellBloodDK + 1;
                return RETURN_CONTINUE;
            }
            if (pet && DEATH_PACT > 0 && GetAI()->GetHealthPercent() < 50 && LastSpellBloodDK < 12 && GetAI()->CastSpell(DEATH_PACT, *pet))
            {
                out << " Death Pact (sacrifice pet)";
                SpellSequence = SPELL_DK_UNHOLY;
                LastSpellBloodDK = LastSpellBloodDK + 1;
                return RETURN_CONTINUE;
            }
            if (LastSpellBloodDK > 13)
            {
                LastSpellBloodDK = 0;
                SpellSequence = SPELL_DK_UNHOLY;
                return RETURN_NO_ACTION_OK; // Not really OK but that's just how DK rotation works right now
            }
    }
    //if (GetAI()->GetManager()->m_confDebugWhisper)
    //    GetAI()->TellMaster(out.str().c_str());

    return RETURN_NO_ACTION_UNKNOWN;
} // end DoNextCombatManeuver

CombatManeuverReturns PlayerbotDeathKnightAI::DoNextCombatManeuverPVP(Unit* pTarget)
{
    if (GetAI()->CastSpell(PLAGUE_STRIKE))
        return RETURN_CONTINUE;

    return DoNextCombatManeuverPVE(pTarget); // TODO: bad idea perhaps, but better than the alternative
}

void PlayerbotDeathKnightAI::DoNonCombatActions()
{
    if (!GetAI())  return;
    if (!m_bot) return;

    SpellSequence = SPELL_DK_UNHOLY;

    // buff master with HORN_OF_WINTER
    if (HORN_OF_WINTER > 0)
        (!GetMaster()->HasAura(HORN_OF_WINTER, EFFECT_INDEX_0) && GetAI()->CastSpell (HORN_OF_WINTER, *GetMaster()));

    // hp check
    if (m_bot->getStandState() != UNIT_STAND_STATE_STAND)
        m_bot->SetStandState(UNIT_STAND_STATE_STAND);

    if (EatDrinkBandage(false))
        return;
} // end DoNonCombatActions

// Match up with "Pull()" below
bool PlayerbotDeathKnightAI::CanPull()
{
    if (DEATH_GRIP && m_bot->IsSpellReady(DEATH_GRIP))
        return true;

    return false;
}

// Match up with "CanPull()" above
bool PlayerbotDeathKnightAI::Pull()
{
    if (DEATH_GRIP && GetAI()->CastSpell(DEATH_GRIP))
        return true;

    return false;
}
