#include "battle.h"
#include "constants/items.h"
#include "constants/vars.h"
#include "event_data.h"
#include "battle_setup.h"
#include "script_pokemon_util.h"
#include "constants/flags.h"

#include "trainer_fly.h"

#include "data/trainer_fly.h"

bool32 IsTrainerFlyActive()
{
	return FlagGet(FLAG_SYS_TRAINER_FLY) && VarGet(VAR_TRAINER_FLY_VALUE);
}

void StoreTrainerFlyValue(u32 value, u32 level)
{
	if (value == 0) // We cannot store 0 here sorry!
		return;
	if (!FlagGet(FLAG_SYS_TRAINER_FLY))
		return; // We also can't do anything if the flag for it is disabled!

	VarSet(VAR_TRAINER_FLY_VALUE, value);
	VarSet(VAR_TRAINER_FLY_LEVEL, level);
	// VarSet(VAR_TRAINER_FLY_ACTIVE, 1);
}

void ReleaseTrainerFlyValue()
{
	FlagClear(FLAG_SYS_TRAINER_FLY);
	VarSet(VAR_TRAINER_FLY_VALUE, 0);
	VarSet(VAR_TRAINER_FLY_ACTIVE, 0);
	VarSet(VAR_TRAINER_FLY_LEVEL, 0);
}

void StartTrainerFlyBattle()
{
	if (IsTrainerFlyActive())
	{
		u32 val;
		val = VarGet(VAR_TRAINER_FLY_VALUE);

		// regular pokemon
		if (val < TRAINER_FLY_MAP_TRAINER_START)
		{
			CreateScriptedWildMon(gTrainerFlyMap[val], VarGet(VAR_TRAINER_FLY_LEVEL), ITEM_NONE);
			StartScriptedWildBattle();
		}
		else // probably a trainer...
		{
			bool32 special;
			special = FALSE;

			if (val >= TRAINER_FLY_MAP_SIZE)
			{
				val = TRAINER_FLY_MAP_SIZE;
				special = TRUE; // Reserved for 'ABYSS QUEEN ABBY', though can be used by other stuff in the future...
			}

			// Setting up trainer battles is annoying for some reason
			gTrainerBattleOpponent_A = gTrainerFlyMap[val];
			gBattleTypeFlags = BATTLE_TYPE_TRAINER;

			if (special)
				StartTrainerSpecialBattle();
			else
				StartTrainerBattle();
		}

		ReleaseTrainerFlyValue();
	}
}
