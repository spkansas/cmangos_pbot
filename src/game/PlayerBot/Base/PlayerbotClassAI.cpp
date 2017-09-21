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

#include "PlayerbotClassAI.h"
#include "Common.h"

#include "Grids/Cell.h"
#include "Grids/CellImpl.h"
#include "Grids/GridNotifiers.h"
#include "Grids/GridNotifiersImpl.h"

// PlayerbotClassAIData

bool PlayerbotClassAIData::DB_LoadData(void)
{
	QueryResult *result = NULL;
	
	m_uiBotSpec = m_bot->GetSpec();

	//result = CharacterDatabase.PQuery("SELECT DISTINCT c.guid, c.name, c.online, c.race, c.class, c.map FROM %s WHERE (c.account='%d' %s'%u') LIMIT 20", fromTable.c_str(), accountId, wherestr.c_str(), guid);
	return true;

	if (!result)
	{
		delete result;
		return false;
	}

	do
	{
		Field *fields = result->Fetch();
	} while (result->NextRow());
	delete result;
	return true;
}

bool PlayerbotClassAIData::DB_SaveData(void)
{
	QueryResult *result = NULL;

	return true;
}

// PlayerbotClassAI

PlayerbotClassAI::PlayerbotClassAI(Player* const master, Player* const bot, PlayerbotAI* const ai)
{
    m_MinHealthPercentTank = 80;
    m_MinHealthPercentHealer = 60;
    m_MinHealthPercentDPS = 30;
    m_MinHealthPercentMaster = m_MinHealthPercentDPS;

    // Initial Core Bot Data
    m_botdata = new PlayerbotClassAIData(master, bot, ai);

    ClearWait();
}

PlayerbotClassAI::~PlayerbotClassAI() 
{
	for (int i = 0; i < 10; i++)
	{
		if (buff_list[i]) delete buff_list[i];
		buff_list[i] = nullptr;
	}

	delete m_botdata;
}

bool PlayerbotClassAI::PlayerbotClassAI_ClassAIInit(void)
{
//	DEBUG_LOG("[PlayerbotClassAI::PlayerbotClassAI_ClassAIInit] - Entered");
    return true;
}

// Combat - Start
CombatManeuverReturns PlayerbotClassAI::DoManeuver_Combat_Start_Class_Prep(Unit *pTarget)
{
//	DEBUG_LOG("[PlayerbotClassAI::DoManeuver_Combat_Start_Class_Prep] - Entered");
	return RETURN_NO_ACTION_OK;
}

CombatManeuverReturns PlayerbotClassAI::DoManeuver_Combat_Start(Unit *pTarget)
{
//	DEBUG_LOG("[PlayerbotClassAI::DoManeuver_Combat_Start] - Entered");

	CombatManeuverReturns ret_val = DoManeuver_Combat_Start_Class_Prep(pTarget);

	if (ret_val & RETURN_ANY_OK)
	{
		PlayerbotAI::CombatOrderType cmbt_orders = m_botdata->GetAI()->GetCombatOrder();

		// There are NPCs in BGs and Open World PvP, so don't filter this on PvP scenarios (of course if PvP targets anyone but tank, all bets are off anyway)
		// Wait until the tank says so, until any non-tank gains aggro or X seconds - whichever is shortest
		if (cmbt_orders & PlayerbotAI::ORDERS_TEMP_WAIT_TANKAGGRO)
		{
			if (m_WaitUntil > m_botdata->GetAI()->CurrentTime() && m_botdata->GetAI()->GroupTankHoldsAggro())
			{
				if (PlayerbotAI::ORDERS_TANK & cmbt_orders)
				{
					bool meleeReach = m_botdata->GetBot()->CanReachWithMeleeAttack(pTarget);

					if (meleeReach)
					{
						// Set everyone's UpdateAI() waiting to 2 seconds
						m_botdata->GetAI()->SetGroupIgnoreUpdateTime(2);
						// Clear their TEMP_WAIT_TANKAGGRO flag
						m_botdata->GetAI()->ClearGroupCombatOrder(PlayerbotAI::ORDERS_TEMP_WAIT_TANKAGGRO);
						// Start attacking, force target on current target
						m_botdata->GetAI()->Attack(m_botdata->GetAI()->GetCurrentTarget());

						// While everyone else is waiting 2 second, we need to build up aggro, so don't return
						ret_val = RETURN_CONTINUE;
					}
					else
					{
						// TODO: add check if target is ranged
						ret_val = RETURN_NO_ACTION_OK; // wait for target to get nearer
					}
				}
				else if (PlayerbotAI::ORDERS_HEAL & cmbt_orders)
				{
					ret_val = DoNextManeuver_Heal(pTarget);
				}
				else
				{
					ret_val = RETURN_NO_ACTION_OK; // wait it out
				}
			}
			else
			{
				// Bot has now waited, clear wait flag
				m_botdata->GetAI()->ClearGroupCombatOrder(PlayerbotAI::ORDERS_TEMP_WAIT_TANKAGGRO);

				ret_val = RETURN_NO_ACTION_OK;
			}
		}

		if (ret_val & RETURN_ANY_OK)
		{
			if (cmbt_orders & PlayerbotAI::ORDERS_TEMP_WAIT_OOC)
			{
				// TODO: Logic works but ugly - change
				if (m_WaitUntil > m_botdata->GetAI()->CurrentTime() && !m_botdata->GetAI()->IsGroupInCombat())
				{
					ret_val = RETURN_NO_ACTION_OK; // wait it out
				}
				else
				{
					m_botdata->GetAI()->ClearGroupCombatOrder(PlayerbotAI::ORDERS_TEMP_WAIT_OOC);
					ret_val = RETURN_NO_ACTION_OK; 
				}
			}

			if (ret_val & RETURN_ANY_OK)
			{
				ret_val = DoManeuver_Combat_Start_Class_Post(pTarget);
			}
		}
	}

	return ret_val;
}

CombatManeuverReturns PlayerbotClassAI::DoManeuver_Combat_Start_Class_Post(Unit *pTarget)
{
//	DEBUG_LOG("[PlayerbotClassAI::DoManeuver_Combat_Start_Class_Post] - Entered");
	return RETURN_NO_ACTION_OK;
}

// Combat - Move

CombatManeuverReturns PlayerbotClassAI::DoManeuver_Combat_Move_Class_Prep(Unit *pTarget)
{
//	DEBUG_LOG("[PlayerbotClassAI::DoManeuver_Combat_Move_Class_Prep] - Entered");
	return RETURN_CONTINUE;
}

CombatManeuverReturns PlayerbotClassAI::DoManeuver_Combat_Move(Unit *pTarget)
{
//	DEBUG_LOG("[PlayerbotClassAI::DoManeuver_Combat_Move] - Entered");

	CombatManeuverReturns ret_val = RETURN_NO_ACTION_ERROR;

	if (m_botdata->GetAI()->m_targetCombat)
	{
		ret_val = DoManeuver_Combat_Move_Class_Prep(pTarget);

		if (ret_val & RETURN_ANY_OK)
		{
			bool meleeReach = m_botdata->GetBot()->CanReachWithMeleeAttack(m_botdata->GetAI()->m_targetCombat);

			if (m_botdata->GetAI()->m_combatStyle == PlayerbotAI::COMBAT_MELEE
				&& !m_botdata->GetBot()->hasUnitState(UNIT_STAT_CHASE)
				&& ((m_botdata->GetAI()->m_movementOrder == PlayerbotAI::MOVEMENT_STAY && meleeReach) || m_botdata->GetAI()->m_movementOrder != PlayerbotAI::MOVEMENT_STAY)
				&& GetWaitUntil() == 0) // Not waiting
			{
				// melee combat - chase target if in range or if we are not forced to stay
				m_botdata->GetBot()->GetMotionMaster()->Clear(false);
				m_botdata->GetBot()->GetMotionMaster()->MoveChase(m_botdata->GetAI()->m_targetCombat);
			}
			else if (m_botdata->GetAI()->m_combatStyle == PlayerbotAI::COMBAT_RANGED
				&& m_botdata->GetAI()->m_movementOrder != PlayerbotAI::MOVEMENT_STAY
				&& GetWaitUntil() == 0) // Not waiting
			{
				// ranged combat - just move within spell range if bot does not have heal orders
				if (!m_botdata->GetAI()->CanReachWithSpellAttack(m_botdata->GetAI()->m_targetCombat) && !m_botdata->GetAI()->IsHealer())
				{
					m_botdata->GetBot()->GetMotionMaster()->Clear(false);
					m_botdata->GetBot()->GetMotionMaster()->MoveChase(m_botdata->GetAI()->m_targetCombat);
				}
				else
					m_botdata->GetAI()->MovementClear();
			}

			ret_val = DoManeuver_Combat_Move_Class_Post(pTarget);
		}
	}

	return ret_val;
}

CombatManeuverReturns PlayerbotClassAI::DoManeuver_Combat_Move_Class_Post(Unit* pTarget)
{
//	DEBUG_LOG("[PlayerbotClassAI::DoManeuver_Combat_Move_Class_Post] - Entered");
	return RETURN_CONTINUE;
}

// Combat - Execute

CombatManeuverReturns PlayerbotClassAI::DoManeuver_Combat_Exec_Class_Prep(Unit* pTarget)
{
//	DEBUG_LOG("[PlayerbotClassAI::DoManeuver_Combat_Exec_Class_Prep] - Entered");
	return RETURN_CONTINUE;
}

CombatManeuverReturns PlayerbotClassAI::DoManeuver_Combat_Exec(Unit *pTarget)
{
//	DEBUG_LOG("[PlayerbotClassAI::DoManeuver_Combat_Exec] - Entered");

	CombatManeuverReturns ret_val = DoManeuver_Combat_Exec_Class_Prep(pTarget);

	if (ret_val & RETURN_ANY_OK)
	{
		switch (m_botdata->GetAI()->GetScenarioType())
		{
		case PlayerbotAI::SCENARIO_PVP_DUEL:
		case PlayerbotAI::SCENARIO_PVP_BG:
		case PlayerbotAI::SCENARIO_PVP_ARENA:
		case PlayerbotAI::SCENARIO_PVP_OPENWORLD:
			return DoNextCombatManeuverPVP(pTarget);
		case PlayerbotAI::SCENARIO_PVE:
		case PlayerbotAI::SCENARIO_PVE_ELITE:
		case PlayerbotAI::SCENARIO_PVE_RAID:
		default:
			return DoNextCombatManeuverPVE(pTarget);
			break;
		}
	}

	return ret_val;
}

CombatManeuverReturns PlayerbotClassAI::DoManeuver_Combat_Exec_Class_Post(Unit* pTarget)
{
//	DEBUG_LOG("[PlayerbotClassAI::DoManeuver_Combat_Exec_Class_Post] - Entered");
	return RETURN_CONTINUE;
}

// Combat Heal

CombatManeuverReturns PlayerbotClassAI::DoNextManeuver_Heal_ClassSetup(Unit* pTarget)
{
	sLog.outError("[PlayerbotClassAI::DoNextManeuver_Heal_ClassSetup]: Warning: Base class function used rather than class specific function");
	return RETURN_NO_ACTION_ERROR;
}


CombatManeuverReturns PlayerbotClassAI::DoFirstCombatManeuverPVE(Unit *pTarget)
{
//	DEBUG_LOG("[PlayerbotClassAI::DoFirstCombatManeuverPVE] - Entered");
	return RETURN_NO_ACTION_OK; 
}


CombatManeuverReturns PlayerbotClassAI::DoFirstCombatManeuverPVP(Unit *pTarget)
{ 
//	DEBUG_LOG("[PlayerbotClassAI::DoFirstCombatManeuverPVE] - Entered");
	return RETURN_NO_ACTION_OK; 
}


CombatManeuverReturns PlayerbotClassAI::DoNextManeuver_Heal(Unit* pTarget)
{
	//	DEBUG_LOG("[PlayerbotClassAI::DoNextManeuver_Heal] - Entered");

	CombatManeuverReturns ret_val = DoNextManeuver_Heal_ClassSetup(pTarget);

	if (ret_val == RETURN_CONTINUE)
	{
		ret_val = HealPlayer(GetHealTarget());

		if (ret_val & RETURN_ANY_OK)
		{
			return RETURN_CONTINUE;
		}
	}

	return ret_val;
}

CombatManeuverReturns PlayerbotClassAI::DoNextCombatManeuverPVE(Unit *pTarget) 
{
//	DEBUG_LOG("[PlayerbotClassAI::DoNextCombatManeuverPVE] - Entered");
	return RETURN_NO_ACTION_OK;
}


CombatManeuverReturns PlayerbotClassAI::DoNextCombatManeuverPVP(Unit *pTarget) 
{
//	DEBUG_LOG("[PlayerbotClassAI::DoNextCombatManeuverPVP] - Entered");
	return RETURN_NO_ACTION_OK;
}


void PlayerbotClassAI::DoNonCombatActions()
{
//	DEBUG_LOG("[PlayerbotClassAI::DoNonCombatActions] - Entered");

    if (!PBotNewAI())
    {
        sLog.outError("[PlayerbotAI]: Warning: Using PlayerbotClassAI::DoNonCombatActions() rather than class specific function");
        return;
    }


	if (!m_botdata->GetBot()->isAlive()  || 
		 m_botdata->GetBot()->IsInDuel() || 
		 m_botdata->GetBot()->isInCombat()) return;

	// Form control - Start of process
	if (DoManeuver_Idle_Forms_Start() & RETURN_CONTINUE) return;

    // Self Buff
    if (DoManeuver_Idle_SelfBuff() & RETURN_CONTINUE) return;

    // Ressurect
    if (m_botdata->GetRezSpell())
    {
        Player *m_Player2Rez = GetResurrectionTarget();

		if (m_Player2Rez)
        {
			if (RessurectTarget(m_Player2Rez, m_botdata->GetRezSpell()) & RETURN_CONTINUE) return;
        }
    }

    // Healing 
    if (m_botdata->GetRoles() & BOT_ROLE::ROLE_HEAL)
    {
        Player *m_Player2Heal = (m_botdata->GetAI()->IsHealer() ? GetHealTarget() : m_botdata->GetBot());

        // TODO: Enable logic for raid, group, and better healing regardless of orders
        if (m_Player2Heal)
        {
			if (DoManeuver_Idle_Heal(m_Player2Heal) & RETURN_CONTINUE) return;
        }
    }

	// Group Buffing
	if (m_botdata->GetRoles() & BOT_ROLE::ROLE_BUFF)
	{
		if (DoManeuver_Idle_Buff() & RETURN_CONTINUE) return;
	}

	// Pet Management
	if (DoManeuver_Idle_Pet_Summon() & RETURN_CONTINUE) return;

	// Pet Healing
	if (DoManeuver_Idle_Pet_BuffnHeal() & RETURN_CONTINUE) return;

	if (EatDrinkBandage())  return;

	// Form control - End of process
	if (DoManeuver_Idle_Forms_End() & RETURN_CONTINUE) return;

    return;
}


CombatManeuverReturns PlayerbotClassAI::DoManeuver_Idle_Cure_Detremental(void)
{
	if (m_botdata->GetCanCure())
	{
		// Remove curse on group members
		if (Player* pCursedTarget = GetDispelTarget(DISPEL_CURSE))
		{
			Unit::SpellAuraHolderMap const& auras = pCursedTarget->GetSpellAuraHolderMap();

			for (Unit::SpellAuraHolderMap::const_iterator itr = auras.begin(); itr != auras.end(); ++itr)
			{
				SpellAuraHolder *holder = itr->second;

				if ((holder->GetSpellProto()->Dispel == DISPEL_DISEASE) && m_botdata->GetDispellDiseaseSpell())
				{
					if (m_botdata->GetAI()->CastSpell(m_botdata->GetDispellDiseaseSpell(), *pCursedTarget))
					{
						return RETURN_CONTINUE;
					}

					return RETURN_NO_ACTION_ERROR;
				}
				else if ((holder->GetSpellProto()->Dispel == DISPEL_POISON) && m_botdata->GetDispellPosionSpell())
				{
					if (m_botdata->GetAI()->CastSpell(m_botdata->GetDispellPosionSpell(), *pCursedTarget))
					{
						return RETURN_CONTINUE;
					}

					return RETURN_NO_ACTION_ERROR;
				}
				else if ((holder->GetSpellProto()->Dispel == DISPEL_MAGIC) && m_botdata->GetDispellMagicSpell())
				{
					if (m_botdata->GetAI()->CastSpell(m_botdata->GetDispellMagicSpell(), *pCursedTarget))
					{
						return RETURN_CONTINUE;
					}

					return RETURN_NO_ACTION_ERROR;
				}
				else if ((holder->GetSpellProto()->Dispel == DISPEL_CURSE) && m_botdata->GetDispellCurseSpell())
				{
					if (m_botdata->GetAI()->CastSpell(m_botdata->GetDispellCurseSpell(), *pCursedTarget))
					{
						return RETURN_CONTINUE;
					}

					return RETURN_NO_ACTION_ERROR;
				}
			}
		}
	}

	return RETURN_NO_ACTION_OK;
}


CombatManeuverReturns PlayerbotClassAI::DoManeuver_Idle_SelfBuff(void)
{
    return RETURN_NO_ACTION_OK;
}


CombatManeuverReturns PlayerbotClassAI::DoManeuver_Idle_Forms_Start(void)
{
	return RETURN_NO_ACTION_OK;
}


CombatManeuverReturns PlayerbotClassAI::DoManeuver_Idle_Forms_End(void)
{
	return RETURN_NO_ACTION_OK;
}


CombatManeuverReturns PlayerbotClassAI::DoManeuver_Idle_Pet_Summon(void)
{
	return RETURN_NO_ACTION_OK;
}


CombatManeuverReturns PlayerbotClassAI::DoManeuver_Idle_Pet_BuffnHeal(void)
{
	return RETURN_NO_ACTION_OK;
}


CombatManeuverReturns PlayerbotClassAI::DoManeuver_Idle_Rez_Prep(Player* target)
{
    return RETURN_NO_ACTION_OK;
}


CombatManeuverReturns PlayerbotClassAI::DoManeuver_Idle_Rez(Player* target)
{
    CombatManeuverReturns ret_val;

    ret_val = DoManeuver_Idle_Rez_Prep(target);

    if (ret_val & RETURN_ANY_OK)
    {
        ret_val = RessurectTarget(target, m_botdata->GetRezSpell());

        if (ret_val & RETURN_ANY_OK)
        {
            ret_val = DoManeuver_Idle_Rez_Post(target);
        }
    }

    return ret_val;
}


CombatManeuverReturns PlayerbotClassAI::DoManeuver_Idle_Rez_Post(Player* target)
{
    return RETURN_CONTINUE;
}


CombatManeuverReturns PlayerbotClassAI::DoManeuver_Idle_Heal_Prep(Player* target)
{
    return RETURN_NO_ACTION_OK;
}


CombatManeuverReturns PlayerbotClassAI::DoManeuver_Idle_Heal(Player* target)
{
    CombatManeuverReturns ret_val;

    ret_val = DoManeuver_Idle_Heal_Prep(target);

    if (ret_val & RETURN_CONTINUE)
    {
		if (m_botdata->GetHealSpell())
		{
			ret_val = HealTarget(target, m_botdata->GetHealSpell());

			if (ret_val & RETURN_ANY_OK)
			{
				DoManeuver_Idle_Heal_Post(target);
			}
		}
		else
		{
			ret_val = RETURN_NO_ACTION_OK;
		}
    }

    return ret_val;
}


CombatManeuverReturns PlayerbotClassAI::DoManeuver_Idle_Heal_Post(Player* target)
{
    return RETURN_CONTINUE;
}


CombatManeuverReturns PlayerbotClassAI::DoManeuver_Idle_Buff_Prep(void)
{
    return RETURN_NO_ACTION_OK;
}


CombatManeuverReturns PlayerbotClassAI::DoManeuver_Idle_Buff(void)
{
    CombatManeuverReturns ret_val;

    ret_val = DoManeuver_Idle_Buff_Prep();

    if (ret_val & RETURN_ANY_OK)
    {
		ret_val = RETURN_NO_ACTION_OK;

		for (int i = 0; ((i < 10) && (buff_list[i]) && (buff_list[i]->spellid.group) | (buff_list[i]->spellid.single)); i++)
		{
			if ((!buff_list[i]->spec_required) || (m_botdata->GetSpec() == buff_list[i]->spec_required))
			{
				uint8 numberOfGroupTargets = 0;

				if (buff_list[i]->spellid.group && m_botdata->GetBot()->GetGroup())
				{
					Group::MemberSlotList const& groupSlot = m_botdata->GetBot()->GetGroup()->GetMemberSlots();

					for (Group::member_citerator itr = groupSlot.begin(); itr != groupSlot.end(); itr++)
					{
						Player *groupMember = sObjectMgr.GetPlayer(itr->guid);

						if (!groupMember || !groupMember->isAlive() || groupMember->IsInDuel()) continue;

						if (!groupMember->HasAura(buff_list[i]->spellid.group, EFFECT_INDEX_0))
						{
							if (!buff_list[i]->spellid.single && !buff_list[i]->spellid.single_enhanced)
							{
								// Here we have any group member that needs the group buff,
								// and there are no single version of the buff.  So we simulate
								// needing the group buff.
								numberOfGroupTargets = 3;
								break;
							}
							else if ((buff_list[i]->spellid.single && !groupMember->HasAura(buff_list[i]->spellid.single, EFFECT_INDEX_0)) &&
								     (buff_list[i]->spellid.single_enhanced && !groupMember->HasAura(buff_list[i]->spellid.single_enhanced, EFFECT_INDEX_0)))
							{
								numberOfGroupTargets++;

								if (numberOfGroupTargets > 2) break;
							}
						}

						// Don't forget about pet
						Pet * pet = groupMember->GetPet();

						if (pet && !pet->HasAura(buff_list[i]->spellid.group, EFFECT_INDEX_0))
						{
							if (!buff_list[i]->spellid.single && !buff_list[i]->spellid.single_enhanced)
							{
								// Here we have any group member that needs the group buff,
								// and there are no single version of the buff.  So we simulate
								// needing the group buff.
								numberOfGroupTargets = 3;
								break;
							}
							else if ((buff_list[i]->spellid.single && !pet->HasAura(buff_list[i]->spellid.single, EFFECT_INDEX_0)) &&
								     (buff_list[i]->spellid.single_enhanced && !pet->HasAura(buff_list[i]->spellid.single_enhanced, EFFECT_INDEX_0)))
							{
								numberOfGroupTargets++;

								if (numberOfGroupTargets > 2) break;
							}
						}
					}
				}

				if (numberOfGroupTargets > 2)
				{
					ret_val = (m_botdata->GetAI()->Buff(buff_list[i]->spellid.group, GetPlayerBot(), m_ActionBeforeCast) ? RETURN_CONTINUE : RETURN_NO_ACTION_OK);
				}
				else
				{
					// TODO:  This section needs to be re-written to support the enhanced and regants
					uint32 spellId = (buff_list[i]->spellid.single_enhanced ? buff_list[i]->spellid.single_enhanced : buff_list[i]->spellid.single);

					if (!spellId) 
					{ 
						sLog.outError("[PlayerbotClassAI::DoManeuver_Idle_Buff] - spellId is zero - setting RETURN_NO_ACTION_ERROR and breaking.");
						ret_val = RETURN_NO_ACTION_ERROR;
						break;
					}

					if (m_botdata->GetBot()->GetGroup())
					{
						DEBUG_LOG("[PlayerbotClassAI::DoManeuver_Idle_Buff] - m_botdata->GetBot()->GetGroup()");
						Group::MemberSlotList const& groupSlot = m_botdata->GetBot()->GetGroup()->GetMemberSlots();

						for (Group::member_citerator itr = groupSlot.begin(); itr != groupSlot.end(); itr++)
						{
							Player *groupMember = sObjectMgr.GetPlayer(itr->guid);

							if (!groupMember || !groupMember->isAlive() || groupMember->IsInDuel())
							{
								continue;
							}
							
							DEBUG_LOG("[PlayerbotClassAI::Buff] - Preping to buff Group Member Pet.");

							Pet* pet = groupMember->GetPet();

							if (pet && buff_list[i]->CheckPet(pet->getPetType()))
							{
								// If pet is available and (any buff OR mana buff and pet is mana)
								if (!pet->HasAuraType(SPELL_AURA_MOD_UNATTACKABLE) && !pet->HasAura(spellId, EFFECT_INDEX_0))
								{
									sLog.outError("[PlayerbotClassAI::Buff] - Buffing Group Member (%s) Pet (%s).", groupMember->GetName(), pet->GetName());

									if (m_botdata->GetAI()->Buff(spellId, pet, m_ActionBeforeCast))
									{
										sLog.outError("[PlayerbotClassAI::Buff] - Buffed Pet - setting RETURN_CONTINUE and breaking loop.");
										ret_val = RETURN_CONTINUE;
										break;
									}
								}
							}

							DEBUG_LOG("[PlayerbotClassAI::Buff] - Preping to buff Group Member.");

							// Check if group member has buff
							if (!groupMember->HasAura(spellId, EFFECT_INDEX_0))
							{
								// Check if group member wants buff
								if (groupMember->GetPlayerbotAI())
								{
									if (!(groupMember->GetPlayerbotAI()->GetClassAI()->m_botdata->GetRolePrimary() & buff_list[i]->caston_bot_role)) continue;
								}
								else
								{
									if (!buff_list[i]->CheckClass(groupMember->getClass())) continue;
								}

								sLog.outError("[PlayerbotClassAI::Buff] - %s is buffing Group Member %s with (%u).", m_botdata->GetBot()->GetName(), groupMember->GetName(), spellId);

								if (m_botdata->GetAI()->Buff(spellId, groupMember, m_ActionBeforeCast))
								{
									sLog.outError("[PlayerbotClassAI::Buff] - Buffed Group Member - setting RETURN_CONTINUE and breaking loop.");
									ret_val = RETURN_CONTINUE;
									break;
								}
							}

							DEBUG_LOG("[PlayerbotClassAI::Buff] - No buff needed - Checking for another group member.");
						}
					}
					else
					{
						sLog.outError("[PlayerbotClassAI::Buff] - No Group - Attempting to buffing Master and Master's Pet.");

						if (!m_botdata->GetMaster() || !m_botdata->GetMaster()->isAlive() || m_botdata->GetMaster()->IsInDuel())
						{
							DEBUG_LOG("[PlayerbotClassAI::Buff] -  (!m_botdata->GetMaster() || !m_botdata->GetMaster()->isAlive() || m_botdata->GetMaster()->IsInDuel()) - loooping");
							break;
						}

						// Check if Master has buff
						if (!m_botdata->GetMaster()->HasAura(spellId, EFFECT_INDEX_0))
						{
							sLog.outError("[PlayerbotClassAI::Buff] - Buffing Master (%s).", m_botdata->GetMaster()->GetName());

							if (m_botdata->GetAI()->Buff(spellId, m_botdata->GetMaster(), m_ActionBeforeCast))
							{
								DEBUG_LOG("[PlayerbotClassAI::Buff] - Buffed Master - setting RETURN_CONTINUE and breaking loop.");
								ret_val = RETURN_CONTINUE;
								break;
							}
						}

						Pet* pet = m_botdata->GetMaster()->GetPet();

						if (pet)
						{
							if (!pet->HasAura(spellId, EFFECT_INDEX_0) && buff_list[i]->CheckPet(pet->getPetType()))
							{
								if (!pet->HasAuraType(SPELL_AURA_MOD_UNATTACKABLE))
								{
									sLog.outError("[PlayerbotClassAI::Buff] - Buffing Masters (%s) Pet (%s).", m_botdata->GetMaster()->GetName(), pet->GetName());

									if (m_botdata->GetAI()->Buff(spellId, pet, m_ActionBeforeCast))
									{
										DEBUG_LOG("[PlayerbotClassAI::Buff] - Buffed Pet - setting RETURN_CONTINUE and breaking loop.");
										ret_val = RETURN_CONTINUE;
										break;
									}
								}
							}
						}

						DEBUG_LOG("[PlayerbotClassAI::Buff] - No Group - Attempting to buffing self and pet.");

						if (!m_botdata->GetBot() || !m_botdata->GetBot()->isAlive() || m_botdata->GetBot()->IsInDuel())
						{
							DEBUG_LOG("[PlayerbotClassAI::Buff] -  (!m_botdata->GetBot() || !m_botdata->GetBot()->isAlive() || m_botdata->GetBot()->IsInDuel()) - loooping");
							continue;
						}

						// Check if Self has buff
						if (!m_botdata->GetBot()->HasAura(spellId, EFFECT_INDEX_0))
						{
							sLog.outError("[PlayerbotClassAI::Buff] - Buffing Self (%s).", m_botdata->GetMaster()->GetName());

							if (m_botdata->GetAI()->Buff(spellId, m_botdata->GetBot(), m_ActionBeforeCast))
							{
								DEBUG_LOG("[PlayerbotClassAI::Buff] - Buffed Self - setting RETURN_CONTINUE and breaking loop.");
								ret_val = RETURN_CONTINUE;
								break;
							}
						}

						pet = m_botdata->GetBot()->GetPet();

						if (pet)
						{
							if (!pet->HasAura(spellId, EFFECT_INDEX_0) && buff_list[i]->CheckPet(pet->getPetType()))
							{
								// If pet is available and (any buff OR mana buff and pet is mana)
								if (!pet->HasAuraType(SPELL_AURA_MOD_UNATTACKABLE))
								{
									sLog.outError("[PlayerbotClassAI::Buff] - Buffing Self (%s) Pet (%s).", m_botdata->GetMaster()->GetName(), pet->GetName());

									if (m_botdata->GetAI()->Buff(spellId, pet, m_ActionBeforeCast))
									{
										DEBUG_LOG("[PlayerbotClassAI::Buff] - Buffed Self Pet - setting RETURN_CONTINUE and breaking loop.");
										ret_val = RETURN_CONTINUE;
										break;
									}
								}
							}
						}
					}
				}
			}
			else
			{
				ret_val = RETURN_NO_ACTION_OK;
			}

			if (ret_val == RETURN_CONTINUE) break;
		}

        if (ret_val & RETURN_ANY_OK)
        {
            DoManeuver_Idle_Buff_Post();
        }
    }

    return ret_val;
}


CombatManeuverReturns PlayerbotClassAI::DoManeuver_Idle_Buff_Helper(uint32 spellId, Unit *target)
{
	if (spellId == 0) return RETURN_NO_ACTION_ERROR;
	if (!target)      return RETURN_NO_ACTION_INVALIDTARGET;

	DEBUG_LOG("[DoManeuver_Idle_Buff_Helper] spell id %u at target %s", spellId, target->GetName());

	Pet *pet = target->GetPet();

	if (pet && !pet->HasAuraType(SPELL_AURA_MOD_UNATTACKABLE) && m_botdata->GetAI()->Buff(spellId, pet))
		return RETURN_CONTINUE;

	if (m_botdata->GetAI()->Buff(spellId, target, m_ActionBeforeCast))
	{
		return RETURN_CONTINUE;
	}

	return RETURN_NO_ACTION_OK;
}


CombatManeuverReturns PlayerbotClassAI::DoManeuver_Idle_Buff_Post(void)
{
    return RETURN_CONTINUE;
}


bool PlayerbotClassAI::EatDrinkBandage(bool bMana, unsigned char foodPercent, unsigned char drinkPercent, unsigned char bandagePercent)
{
    Item* drinkItem = nullptr;
    Item* foodItem = nullptr;
    if (bMana && m_botdata->GetAI()->GetManaPercent() < drinkPercent)
        drinkItem = m_botdata->GetAI()->FindDrink();
    if (m_botdata->GetAI()->GetHealthPercent() < foodPercent)
        foodItem = m_botdata->GetAI()->FindFood();
    if (drinkItem || foodItem)
    {
        if (drinkItem)
        {
            m_botdata->GetAI()->TellMaster("I could use a drink.");
            m_botdata->GetAI()->UseItem(drinkItem);
        }
        if (foodItem)
        {
            m_botdata->GetAI()->TellMaster("I could use some food.");
            m_botdata->GetAI()->UseItem(foodItem);
        }
        return true;
    }

    if (m_botdata->GetAI()->GetHealthPercent() < bandagePercent && !m_botdata->GetBot()->HasAura(RECENTLY_BANDAGED))
    {
        Item* bandageItem = m_botdata->GetAI()->FindBandage();
        if (bandageItem)
        {
            m_botdata->GetAI()->TellMaster("I could use first aid.");
            m_botdata->GetAI()->UseItem(bandageItem);
            return true;
        }
    }

    return false;
}

bool PlayerbotClassAI::CanPull()
{
    sLog.outError("[PlayerbotAI]: Warning: Using PlayerbotClassAI::CanPull() rather than class specific function");
    return false;
}

bool PlayerbotClassAI::CastHoTOnTank()
{
    sLog.outError("[PlayerbotAI]: Warning: Using PlayerbotClassAI::CastHoTOnTank() rather than class specific function");
    return false;
}

CombatManeuverReturns PlayerbotClassAI::HealPlayer(Player* target) 
{
    if (!target) return RETURN_NO_ACTION_INVALIDTARGET;
    if (target->IsInDuel()) return RETURN_NO_ACTION_INVALIDTARGET;

    return RETURN_NO_ACTION_OK;
}

/**
 * NeedGroupBuff()
 * return boolean Returns true if more than two targets in the bot's group need the group buff.
 *
 * params:groupBuffSpellId uint32 the spell ID of the group buff like Arcane Brillance
 * params:singleBuffSpellId uint32 the spell ID of the single target buff equivalent of the group buff like Arcane Intellect for group buff Arcane Brillance
 * return false if false is returned, the bot is expected to perform a buff check for the single target buff of the group buff.
 *
 */
bool PlayerbotClassAI::NeedGroupBuff(uint32 groupBuffSpellId, uint32 singleBuffSpellId, uint32 singleGreaterBuffSpellId)
{
    if (!m_botdata->GetBot()) return false;

    uint8 numberOfGroupTargets = 0;
    // Check group players to avoid using regeant and mana with an expensive group buff
    // when only two players or less need it
    if (m_botdata->GetBot()->GetGroup())
    {
        Group::MemberSlotList const& groupSlot = m_botdata->GetBot()->GetGroup()->GetMemberSlots();
        for (Group::member_citerator itr = groupSlot.begin(); itr != groupSlot.end(); itr++)
        {
            Player *groupMember = sObjectMgr.GetPlayer(itr->guid);
            if (!groupMember || !groupMember->isAlive())
                continue;
            // Check if group member needs buff
            if (!groupMember->HasAura(groupBuffSpellId, EFFECT_INDEX_0) && !groupMember->HasAura(singleBuffSpellId, EFFECT_INDEX_0))
                numberOfGroupTargets++;
            // Don't forget about pet
            Pet * pet = groupMember->GetPet();
            if (pet && !pet->HasAuraType(SPELL_AURA_MOD_UNATTACKABLE) && (pet->HasAura(groupBuffSpellId, EFFECT_INDEX_0) || pet->HasAura(singleBuffSpellId, EFFECT_INDEX_0)))
                numberOfGroupTargets++;
        }
        // treshold set to 2 targets because beyond that value, the group buff cost is cheaper in mana
        if (numberOfGroupTargets < 3)
            return false;

        // In doubt, buff everyone
        return true;
    }
    else
        return false;   // no group, no group buff
}

/**
 * GetHealTarget()
 * return Unit* Returns unit to be healed. First checks 'critical' Healer(s), next Tank(s), next Master (if different from:), next DPS.
 * If none of the healths are low enough (or multiple valid targets) against these checks, the lowest health is healed. Having a target
 * returned does not guarantee it's worth healing, merely that the target does not have 100% health.
 *
 * return NULL If NULL is returned, no healing is required. At all.
 *
 * Will need extensive re-write for co-operation amongst multiple healers. As it stands, multiple healers would all pick the same 'ideal'
 * healing target.
 */
Player* PlayerbotClassAI::GetHealTarget(JOB_TYPE type)
{
    if (!m_botdata->GetAI())  return nullptr;
    if (!m_botdata->GetBot()) return nullptr;
    if (!m_botdata->GetBot()->isAlive() || m_botdata->GetBot()->IsInDuel()) return nullptr;

    // define seperately for sorting purposes - DO NOT CHANGE ORDER!
    std::vector<heal_priority> targets;

    // First, fill the list of targets
    if (m_botdata->GetBot()->GetGroup())
    {
        Group::MemberSlotList const& groupSlot = m_botdata->GetBot()->GetGroup()->GetMemberSlots();
        for (Group::member_citerator itr = groupSlot.begin(); itr != groupSlot.end(); itr++)
        {
            Player *groupMember = sObjectMgr.GetPlayer(itr->guid);
            if (!groupMember || !groupMember->isAlive() || groupMember->IsInDuel())
                continue;
            JOB_TYPE job = GetTargetJob(groupMember);
            if (job & type)
                targets.push_back( heal_priority(groupMember, (groupMember->GetHealth() * 100 / groupMember->GetMaxHealth()), job) );
        }
    }
    else
    {
        targets.push_back( heal_priority(m_botdata->GetBot(), m_botdata->GetBot()->GetHealthPercent(), GetTargetJob(m_botdata->GetBot())) );
        if (m_botdata->GetMaster() && !m_botdata->GetMaster()->IsInDuel())
            targets.push_back( heal_priority(m_botdata->GetMaster(), (m_botdata->GetMaster()->GetHealth() * 100 / m_botdata->GetMaster()->GetMaxHealth()), GetTargetJob(m_botdata->GetMaster())) );
    }

    // Sorts according to type: Healers first, tanks next, then master followed by DPS, thanks to the order of the TYPE enum
    std::sort(targets.begin(), targets.end());

    uint8 uCount = 0,i = 0;
    // x is used as 'target found' variable; i is used as the targets iterator throughout all 4 types.
    int16 x = -1;

    // Try to find a healer in need of healing (if multiple, the lowest health one)
    while (true)
    {
        // This works because we sorted it above
        if (uint32(uCount + i) >= uint32(targets.size()) || !(targets.at(uCount).type & JOB_HEAL)) break;
        uCount++;
    }

    // We have uCount healers in the targets, check if any qualify for priority healing
    for (; uCount > 0; uCount--, i++)
    {
        if (targets.at(i).hp <= m_MinHealthPercentHealer)
            if (x == -1 || targets.at(x).hp > targets.at(i).hp)
                x = i;
    }
    if (x > -1) return targets.at(x).p;

    // Try to find a tank in need of healing (if multiple, the lowest health one)
    while (true)
    {
        if (uint32(uCount + i) >= uint32(targets.size()) || !(targets.at(uCount).type & JOB_TANK)) break;
        uCount++;
    }

    for (; uCount > 0; uCount--, i++)
    {
        if (targets.at(i).hp <= m_MinHealthPercentTank)
            if (x == -1 || targets.at(x).hp > targets.at(i).hp)
                x = i;
    }
    if (x > -1) return targets.at(x).p;

    // Try to find master in need of healing (lowest health one first)
    if (m_MinHealthPercentMaster != m_MinHealthPercentDPS)
    {
        while (true)
        {
            if (uint32(uCount + i) >= uint32(targets.size()) || !(targets.at(uCount).type & JOB_MASTER)) break;
            uCount++;
        }

        for (; uCount > 0; uCount--, i++)
        {
            if (targets.at(i).hp <= m_MinHealthPercentMaster)
                if (x == -1 || targets.at(x).hp > targets.at(i).hp)
                    x = i;
        }
        if (x > -1) return targets.at(x).p;
    }

    // Try to find anyone else in need of healing (lowest health one first)
    while (true)
    {
        if (uint32(uCount + i) >= uint32(targets.size())) break;
        uCount++;
    }

    for (; uCount > 0; uCount--, i++)
    {
        if (targets.at(i).hp <= m_MinHealthPercentDPS)
            if (x == -1 || targets.at(x).hp > targets.at(i).hp)
                x = i;
    }
    if (x > -1) return targets.at(x).p;

    // Nobody is critical, find anyone hurt at all, return lowest (let the healer sort out if it's worth healing or not)
    for (i = 0, uCount = targets.size(); uCount > 0; uCount--, i++)
    {
        if (targets.at(i).hp < 100)
            if (x == -1 || targets.at(x).hp > targets.at(i).hp)
                x = i;
    }
    if (x > -1) return targets.at(x).p;

    return nullptr;
}

/**
 * FleeFromAoEIfCan()
 * return boolean Check if the bot can move out of the hostile AoE spell then try to find a proper destination and move towards it
 *                The AoE is assumed to be centered on the current bot location (this is the case most of the time)
 *
 * params: spellId uint32 the spell ID of the hostile AoE the bot is supposed to move from. It is used to find the radius of the AoE spell
 * params: pTarget Unit* the creature or gameobject the bot will use to define one of the prefered direction in which to flee
 *
 * return true if bot has found a proper destination, false if none was found
 */
bool PlayerbotClassAI::FleeFromAoEIfCan(uint32 spellId, Unit* pTarget)
{
    if (!m_botdata->GetBot()) return false;
    if (!spellId) return false;

    // Step 1: Get radius from hostile AoE spell
    float radius = 0;
    SpellEntry const* spellproto = sSpellTemplate.LookupEntry<SpellEntry>(spellId);
    if (spellproto)
        radius = GetSpellRadius(sSpellRadiusStore.LookupEntry(spellproto->EffectRadiusIndex[EFFECT_INDEX_0]));

    // Step 2: Get current bot position to move from it
    float curr_x, curr_y, curr_z;
    m_botdata->GetBot()->GetPosition(curr_x, curr_y, curr_z);
    return FleeFromPointIfCan(radius, pTarget, curr_x, curr_y, curr_z);
}

/**
 * FleeFromTrapGOIfCan()
 * return boolean Check if the bot can move from a hostile nearby trap, then try to find a proper destination and move towards it
 *
 * params: goEntry uint32 the ID of the hostile trap the bot is supposed to move from. It is used to find the radius of the trap
 * params: pTarget Unit* the creature or gameobject the bot will use to define one of the prefered direction in which to flee
 *
 * return true if bot has found a proper destination, false if none was found
 */
bool PlayerbotClassAI::FleeFromTrapGOIfCan(uint32 goEntry, Unit* pTarget)
{
    if (!m_botdata->GetBot()) return false;
    if (!goEntry) return false;

    // Step 1: check if the GO exists and find its trap radius
    GameObjectInfo const* trapInfo = sGOStorage.LookupEntry<GameObjectInfo>(goEntry);
    if (!trapInfo || trapInfo->type != GAMEOBJECT_TYPE_TRAP)
        return false;

    float trapRadius = float(trapInfo->trap.radius);

    // Step 2: find a GO in the range around player
    GameObject* pGo = nullptr;

    MaNGOS::NearestGameObjectEntryInObjectRangeCheck go_check(*m_botdata->GetBot(), goEntry, trapRadius);
    MaNGOS::GameObjectLastSearcher<MaNGOS::NearestGameObjectEntryInObjectRangeCheck> searcher(pGo, go_check);

    Cell::VisitGridObjects(m_botdata->GetBot(), searcher, trapRadius);

    if (!pGo)
        return false;

    return FleeFromPointIfCan(trapRadius, pTarget, pGo->GetPositionX(), pGo->GetPositionY(), pGo->GetPositionZ());
}

/**
 * FleeFromNpcWithAuraIfCan()
 * return boolean Check if the bot can move from a creature having a specific aura, then try to find a proper destination and move towards it
 *
 * params: goEntry uint32 the ID of the hostile trap the bot is supposed to move from. It is used to find the radius of the trap
 * params: spellId uint32 the spell ID of the aura the creature is supposed to have (directly or from triggered spell). It is used to find the radius of the aura
 * params: pTarget Unit* the creature or gameobject the bot will use to define one of the prefered direction in which to flee
 *
 * return true if bot has found a proper destination, false if none was found
 */
bool PlayerbotClassAI::FleeFromNpcWithAuraIfCan(uint32 NpcEntry, uint32 spellId, Unit* pTarget)
{
    if (!m_botdata->GetBot()) return false;
    if (!NpcEntry) return false;
    if (!spellId) return false;

    // Step 1: Get radius from hostile aura spell
    float radius = 0;
    SpellEntry const* spellproto = sSpellTemplate.LookupEntry<SpellEntry>(spellId);
    if (spellproto)
        radius = GetSpellRadius(sSpellRadiusStore.LookupEntry(spellproto->EffectRadiusIndex[EFFECT_INDEX_0]));

    if (radius == 0)
        return false;

    // Step 2: find a close creature with the right entry:
    Creature* pCreature = nullptr;

    MaNGOS::NearestCreatureEntryWithLiveStateInObjectRangeCheck creature_check(*m_botdata->GetBot(), NpcEntry, false, false, radius, true);
    MaNGOS::CreatureLastSearcher<MaNGOS::NearestCreatureEntryWithLiveStateInObjectRangeCheck> searcher(pCreature, creature_check);

    Cell::VisitGridObjects(m_botdata->GetBot(), searcher, radius);

    if (!pCreature)
        return false;

    // Force to flee on a direction opposite to the position of the creature (fleeing from it, not only avoiding it)
    return FleeFromPointIfCan(radius, pTarget, pCreature->GetPositionX(), pCreature->GetPositionY(), pCreature->GetPositionZ(), M_PI_F);
}

/**
 * FleeFromPointIfCan()
 * return boolean Check if the bot can move from a provided point (x, y, z) to given distance radius
 *
 * params: radius uint32 the minimal radius (distance) used by the bot to look for a destination from the provided position
 * params: pTarget Unit* the creature or gameobject the bot will use to define one of the prefered direction in which to flee
 * params: x0, y0, z0 float the coordinates of the origin point used to calculate the destination point
 * params: forcedAngle float (optional) when iterating to find a proper point in world to move the bot to, this angle will be prioritly used over other angles if it is provided
 *
 * return true if bot has found a proper destination, false if none was found
 */
bool PlayerbotClassAI::FleeFromPointIfCan(uint32 radius, Unit* pTarget, float x0, float y0, float z0, float forcedAngle /* = 0.0f */)
{
    if (!m_botdata->GetBot()) return false;
    if (!m_botdata->GetAI()) return false;

    // Get relative position to current target
    // the bot will try to move on a tangential axis from it
    float dist_from_target, angle_to_target;
    if (pTarget)
    {
        dist_from_target = pTarget->GetDistance(m_botdata->GetBot());
        if (dist_from_target > 0.2f)
            angle_to_target = pTarget->GetAngle(m_botdata->GetBot());
        else
            angle_to_target = frand(0, 2 * M_PI_F);
    }
    else
    {
        dist_from_target = 0.0f;
        angle_to_target = frand(0, 2 * M_PI_F);
    }

    // Find coords to move to
    // The bot will move for a distance equal to the spell radius + 1 yard for more safety
    float dist = radius + 1.0f;

    float moveAngles[3] = {- M_PI_F / 2, M_PI_F / 2, 0.0f};
    float angle, x, y, z;
    bool foundCoords;
    for (uint8 i = 0; i < 3; i++)
    {
        // define an angle tangential to target's direction
        angle = angle_to_target + moveAngles[i];
        // if an angle was provided, use it instead but only for the first iteration in case this does not lead to a valid point
        if (forcedAngle != 0.0f)
        {
            angle = forcedAngle;
            forcedAngle = 0.0f;
        }
        foundCoords = true;

        x = x0 + dist * cos(angle);
        y = y0 + dist * sin(angle);
        z = z0 + 0.5f;

        // try to fix z
        if (!m_botdata->GetBot()->GetMap()->GetHeightInRange(m_botdata->GetBot()->GetPhaseMask(), x, y, z))
            foundCoords = false;

        // check any collision
        float testZ = z + 0.5f; // needed to avoid some false positive hit detection of terrain or passable little object
        if (m_botdata->GetBot()->GetMap()->GetHitPosition(x0, y0, z0 + 0.5f, x, y, testZ, m_botdata->GetBot()->GetPhaseMask(), -0.1f))
        {
            z = testZ;
            if (!m_botdata->GetBot()->GetMap()->GetHeightInRange(m_botdata->GetBot()->GetPhaseMask(), x, y, z))
                foundCoords = false;
        }

        if (foundCoords)
        {
            m_botdata->GetAI()->InterruptCurrentCastingSpell();
            m_botdata->GetBot()->GetMotionMaster()->MovePoint(0, x, y, z);
            m_botdata->GetAI()->SetIgnoreUpdateTime(2);
            return true;
        }
    }

    return false;
}

/**
 * GetDispelTarget()
 * return Unit* Returns unit to be dispelled. First checks 'critical' Healer(s), next Tank(s), next Master (if different from:), next DPS.
 *
 * return NULL If NULL is returned, no healing is required. At all.
 *
 * Will need extensive re-write for co-operation amongst multiple healers. As it stands, multiple healers would all pick the same 'ideal'
 * healing target.
 */
Player* PlayerbotClassAI::GetDispelTarget(DispelType dispelType, JOB_TYPE type, bool bMustBeOOC)
{
    if (!m_botdata->GetBot()->isAlive() || m_botdata->GetBot()->IsInDuel()) return nullptr;

    if (bMustBeOOC && m_botdata->GetBot()->isInCombat()) return nullptr;

    // First, fill the list of targets
    if (m_botdata->GetBot()->GetGroup())
    {
        // define seperately for sorting purposes - DO NOT CHANGE ORDER!
        std::vector<heal_priority> targets;

        Group::MemberSlotList const& groupSlot = m_botdata->GetBot()->GetGroup()->GetMemberSlots();
        for (Group::member_citerator itr = groupSlot.begin(); itr != groupSlot.end(); itr++)
        {
            Player *groupMember = sObjectMgr.GetPlayer(itr->guid);
            if (!groupMember || !groupMember->isAlive())
                continue;
            JOB_TYPE job = GetTargetJob(groupMember);
            if (job & type)
            {
                uint32 dispelMask  = GetDispellMask(dispelType);
                Unit::SpellAuraHolderMap const& auras = groupMember->GetSpellAuraHolderMap();
                for (Unit::SpellAuraHolderMap::const_iterator itr = auras.begin(); itr != auras.end(); ++itr)
                {
                    SpellAuraHolder *holder = itr->second;
                    // Only return group members with negative magic effect
                    if (dispelType == DISPEL_MAGIC && holder->IsPositive())
                        continue;
                    // poison, disease and curse are always negative: return everyone
                    if ((1 << holder->GetSpellProto()->Dispel) & dispelMask)
                        targets.push_back( heal_priority(groupMember, 0, job) );
                }
            }
        }

        // Sorts according to type: Healers first, tanks next, then master followed by DPS, thanks to the order of the TYPE enum
        std::sort(targets.begin(), targets.end());

        if (targets.size())
            return targets.at(0).p;
    }

    return nullptr;
}




Player* PlayerbotClassAI::GetResurrectionTarget(JOB_TYPE type, bool bMustBeOOC)
{
    if (!m_botdata->GetAI())  return nullptr;
    if (!m_botdata->GetBot()) return nullptr;
    if (!m_botdata->GetBot()->isAlive() || m_botdata->GetBot()->IsInDuel()) return nullptr;
    if (bMustBeOOC && m_botdata->GetBot()->isInCombat()) return nullptr;

    // First, fill the list of targets
    if (m_botdata->GetBot()->GetGroup())
    {
        // define seperately for sorting purposes - DO NOT CHANGE ORDER!
        std::vector<heal_priority> targets;

        Group::MemberSlotList const& groupSlot = m_botdata->GetBot()->GetGroup()->GetMemberSlots();
        for (Group::member_citerator itr = groupSlot.begin(); itr != groupSlot.end(); itr++)
        {
            Player *groupMember = sObjectMgr.GetPlayer(itr->guid);
            if (!groupMember || groupMember->isAlive())
                continue;
            JOB_TYPE job = GetTargetJob(groupMember);
            if (job & type)
                targets.push_back( heal_priority(groupMember, 0, job) );
        }

        // Sorts according to type: Healers first, tanks next, then master followed by DPS, thanks to the order of the TYPE enum
        std::sort(targets.begin(), targets.end());

        if (targets.size())
            return targets.at(0).p;
    }
    else if (!m_botdata->GetMaster()->isAlive())
        return m_botdata->GetMaster();

    return nullptr;
}

JOB_TYPE PlayerbotClassAI::GetTargetJob(Player* target)
{
    // is a bot
    if (target->GetPlayerbotAI())
    {
        if (target->GetPlayerbotAI()->IsHealer())
            return JOB_HEAL;
        if (target->GetPlayerbotAI()->IsTank())
            return JOB_TANK;
        return JOB_DPS;
    }

    // figure out what to do with human players - i.e. figure out if they're tank, DPS or healer
    uint32 uSpec = target->GetSpec();
    switch (target->getClass())
    {
        case CLASS_PALADIN:
            if (uSpec == PALADIN_SPEC_HOLY)
                return JOB_HEAL;
            if (uSpec == PALADIN_SPEC_PROTECTION)
                return JOB_TANK;
            return (m_botdata->GetMaster() == target) ? JOB_MASTER : JOB_DPS;
        case CLASS_DRUID:
            if (uSpec == DRUID_SPEC_RESTORATION)
                return JOB_HEAL;
            // Feral can be used for both Tank or DPS... play it safe and assume tank. If not... he best be good at threat management or he'll ravage the healer's mana
            else if (uSpec == DRUID_SPEC_FERAL)
                return JOB_TANK;
            return (m_botdata->GetMaster() == target) ? JOB_MASTER : JOB_DPS;
        case CLASS_PRIEST:
            // Since Discipline can be used for both healer or DPS assume DPS
            if (uSpec == PRIEST_SPEC_HOLY)
                return JOB_HEAL;
            return (m_botdata->GetMaster() == target) ? JOB_MASTER : JOB_DPS;
        case CLASS_SHAMAN:
            if (uSpec == SHAMAN_SPEC_RESTORATION)
                return JOB_HEAL;
            return (m_botdata->GetMaster() == target) ? JOB_MASTER : JOB_DPS;
        case CLASS_WARRIOR:
            if (uSpec == WARRIOR_SPEC_PROTECTION)
                return JOB_TANK;
            return (m_botdata->GetMaster() == target) ? JOB_MASTER : JOB_DPS;
        case CLASS_DEATH_KNIGHT:
            if (uSpec == DEATHKNIGHT_SPEC_FROST)
                return JOB_TANK;
            return (m_botdata->GetMaster() == target) ? JOB_MASTER : JOB_DPS;
        case CLASS_MAGE:
        case CLASS_WARLOCK:
        case CLASS_ROGUE:
        case CLASS_HUNTER:
        default:
            return (m_botdata->GetMaster() == target) ? JOB_MASTER : JOB_DPS;
    }
}

CombatManeuverReturns PlayerbotClassAI::CastSpellNoRanged(uint32 nextAction, Unit *pTarget)
{
    if (!m_botdata->GetAI())  return RETURN_NO_ACTION_ERROR;
    if (!m_botdata->GetBot()) return RETURN_NO_ACTION_ERROR;

    if (nextAction == 0)
        return RETURN_NO_ACTION_OK; // Asked to do nothing so... yeh... Dooone.

    if (pTarget != nullptr)
        return (m_botdata->GetAI()->CastSpell(nextAction, *pTarget) ? RETURN_CONTINUE : RETURN_NO_ACTION_ERROR);
    else
        return (m_botdata->GetAI()->CastSpell(nextAction) ? RETURN_CONTINUE : RETURN_NO_ACTION_ERROR);
}

CombatManeuverReturns PlayerbotClassAI::CastSpellWand(uint32 nextAction, Unit *pTarget, uint32 SHOOT)
{
    if (!m_botdata->GetAI())  return RETURN_NO_ACTION_ERROR;
    if (!m_botdata->GetBot()) return RETURN_NO_ACTION_ERROR;

    if (SHOOT > 0 && m_botdata->GetBot()->FindCurrentSpellBySpellId(SHOOT) && m_botdata->GetBot()->GetWeaponForAttack(RANGED_ATTACK, true, true))
    {
        if (nextAction == SHOOT)
            // At this point we're already shooting and are asked to shoot. Don't cause a global cooldown by stopping to shoot! Leave it be.
            return RETURN_CONTINUE; // ... We're asked to shoot and are already shooting so... Task accomplished?

        // We are shooting but wish to cast a spell. Stop 'casting' shoot.
        m_botdata->GetBot()->InterruptNonMeleeSpells(true, SHOOT);
        // ai->TellMaster("Interrupting auto shot.");
    }

    // We've stopped ranged (if applicable), if no nextAction just return
    if (nextAction == 0)
        return RETURN_CONTINUE; // Asked to do nothing so... yeh... Dooone.

    if (nextAction == SHOOT)
    {
        if (SHOOT > 0 && m_botdata->GetAI()->GetCombatStyle() == PlayerbotAI::COMBAT_RANGED && !m_botdata->GetBot()->FindCurrentSpellBySpellId(SHOOT) && m_botdata->GetBot()->GetWeaponForAttack(RANGED_ATTACK, true, true))
            return (m_botdata->GetAI()->CastSpell(SHOOT, *pTarget) ? RETURN_CONTINUE : RETURN_NO_ACTION_ERROR);
        else
            // Do Melee attack
            return RETURN_NO_ACTION_UNKNOWN; // We're asked to shoot and aren't.
    }

    if (pTarget != nullptr)
        return (m_botdata->GetAI()->CastSpell(nextAction, *pTarget) ? RETURN_CONTINUE : RETURN_NO_ACTION_ERROR);
    else
        return (m_botdata->GetAI()->CastSpell(nextAction) ? RETURN_CONTINUE : RETURN_NO_ACTION_ERROR);
}

CombatManeuverReturns PlayerbotClassAI::RessurectTarget(Player* target, uint32 RezSpell)
{
    if (!target->isAlive())
    {
        if (RezSpell && m_botdata->GetAI()->In_Reach(target, RezSpell) && m_botdata->GetAI()->CastSpell(RezSpell, *target))
        {
            std::string msg = "Resurrecting ";
            msg += target->GetName();
            m_botdata->GetBot()->Say(msg, LANG_UNIVERSAL);
            return RETURN_CONTINUE;
        }
    }
	return RETURN_NO_ACTION_ERROR; // not error per se - possibly just OOM
}

CombatManeuverReturns PlayerbotClassAI::HealTarget(Player* target, uint32 HealSpell)
{
    if (!target->isAlive())
    {
        if (HealSpell && m_botdata->GetAI()->In_Reach(target, HealSpell) && m_botdata->GetAI()->CastSpell(HealSpell, *target))
        {
            std::string msg = "Healing ";
            msg += target->GetName();
            m_botdata->GetBot()->Say(msg, LANG_UNIVERSAL);
            return RETURN_CONTINUE;
        }
    }
	return RETURN_NO_ACTION_ERROR; // not error per se - possibly just OOM
}


Player* PlayerbotClassAI::Cure_Detremental_Target(DispelType dispelType, BOT_ROLE tgtRole, bool bMustBeOOC)
{

	if (m_botdata->GetBot()->GetGroup())
	{
		std::vector<role_priority> targets;

		Group::MemberSlotList const& groupSlot = m_botdata->GetBot()->GetGroup()->GetMemberSlots();

		for (Group::member_citerator itr = groupSlot.begin(); itr != groupSlot.end(); itr++)
		{
			Player *groupMember = sObjectMgr.GetPlayer(itr->guid);

			if (!groupMember || !groupMember->isAlive()) continue;

			BOT_ROLE Role = GetTargetRole(groupMember);

			if (Role & tgtRole)
			{
				uint32 dispelMask = GetDispellMask(dispelType);

				Unit::SpellAuraHolderMap const& auras = groupMember->GetSpellAuraHolderMap();

				for (Unit::SpellAuraHolderMap::const_iterator itr = auras.begin(); itr != auras.end(); ++itr)
				{
					SpellAuraHolder *holder = itr->second;

					if ((1 << holder->GetSpellProto()->Dispel) & GetDispellMask(DISPEL_DISEASE))
					{
						if (m_botdata->GetDispellDiseaseSpell() && holder->GetSpellProto()->Dispel == DISPEL_DISEASE)
						{
							targets.push_back(role_priority(groupMember, 0, Role));
						}
					}
					else if ((1 << holder->GetSpellProto()->Dispel) & GetDispellMask(DISPEL_POISON))
					{
						if (m_botdata->GetDispellPosionSpell() && holder->GetSpellProto()->Dispel == DISPEL_POISON)
						{
							targets.push_back(role_priority(groupMember, 0, Role));
						}
					}
					else if ((1 << holder->GetSpellProto()->Dispel) & GetDispellMask(DISPEL_MAGIC))
					{
						if (m_botdata->GetDispellMagicSpell() && holder->GetSpellProto()->Dispel == DISPEL_MAGIC)
						{
							targets.push_back(role_priority(groupMember, 0, Role));
						}
					}
					else if ((1 << holder->GetSpellProto()->Dispel) & GetDispellMask(DISPEL_CURSE))
					{
						if (m_botdata->GetDispellCurseSpell() && holder->GetSpellProto()->Dispel == DISPEL_CURSE)
						{
							targets.push_back(role_priority(groupMember, 0, Role));
						}
					}

					// Only return group members with negative magic effect
					if (dispelType == DISPEL_MAGIC && holder->IsPositive())		continue;

					// poison, disease and curse are always negative: return everyone
					if ((1 << holder->GetSpellProto()->Dispel) & dispelMask)
					{
						targets.push_back(role_priority(groupMember, 0, Role));
					}
				}
			}
		}

		// Sorts according to type: Healers first, tanks next, then master followed by DPS, thanks to the order of the TYPE enum
		std::sort(targets.begin(), targets.end());

		if (targets.size()) 	return targets.at(0).pPlayer;
	}

	return nullptr;
}


BOT_ROLE PlayerbotClassAI::GetTargetRole(Player* target)
{
	if (target->GetPlayerbotAI())
	{
		return m_botdata->GetRolePrimary();
	}

	// figure out what to do with human players - i.e. figure out if they're tank, DPS or healer
	uint32 uSpec = target->GetSpec();

	switch (target->getClass())
	{
		case CLASS_PALADIN:
			if (uSpec == PALADIN_SPEC_HOLY)			return ROLE_HEAL;
			if (uSpec == PALADIN_SPEC_PROTECTION)	return ROLE_TANK;
			return ROLE_DPS_MELEE;
		case CLASS_DRUID:
			if (uSpec == DRUID_SPEC_RESTORATION)	return ROLE_HEAL;
			if (uSpec == DRUID_SPEC_FERAL)			return ROLE_TANK;
			return ROLE_DPS_MELEE;
		case CLASS_PRIEST:
			if (uSpec == PRIEST_SPEC_HOLY)			return ROLE_HEAL;
			return ROLE_DPS_CASTER;
		case CLASS_SHAMAN:
			if (uSpec == SHAMAN_SPEC_RESTORATION)	return ROLE_HEAL;
			return ROLE_DPS_CASTER;
		case CLASS_WARRIOR:
			if (uSpec == WARRIOR_SPEC_PROTECTION)	return ROLE_TANK;
			return ROLE_DPS_MELEE;
		case CLASS_DEATH_KNIGHT:
			if (uSpec == DEATHKNIGHT_SPEC_FROST)	return ROLE_TANK;
			return ROLE_DPS_MELEE;
		case CLASS_MAGE:
		case CLASS_WARLOCK:
			return ROLE_DPS_CASTER;
		case CLASS_ROGUE:
		case CLASS_HUNTER:
		default:
			return ROLE_DPS_MELEE;
	}

	return ROLE_DPS_MELEE;
}