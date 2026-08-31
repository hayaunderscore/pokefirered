#include "global.h"
#include "field_effect.h"
#include "field_player_avatar.h"
#include "fldeff.h"
#include "party_menu.h"
#include "overworld.h"
#include "trainer_see.h"
#include "follow_me.h"

static void FieldCallback_Teleport(void);
static void Task_StartTeleport(u8 taskId);
static void StartTeleportFieldEffect(void);

bool8 SetUpFieldMove_Teleport(void)
{
	if (!CheckFollowerFlag(FOLLOWER_FLAG_CAN_LEAVE_ROUTE))
        return FALSE;
	
    if (Overworld_MapTypeAllowsTeleportAndFly(gMapHeader.mapType) == TRUE)
    {
        gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
        gPostMenuFieldCallback = FieldCallback_Teleport;
        return TRUE;
    }
    return FALSE;
}

static void FieldCallback_Teleport(void)
{
	bool32 gotTrainer = FALSE;
    Overworld_ResetStateAfterTeleport();

    gUsedFly = TRUE;
    gotTrainer = CheckForTrainersPossiblyWantingBattle(Task_StartTeleport);
    gUsedFly = FALSE;

    if (!gotTrainer)
    	CreateTask(Task_StartTeleport, 0);
}

static void Task_StartTeleport(u8 taskId)
{
	FieldEffectStart(FLDEFF_USE_TELEPORT);
    gFieldEffectArguments[0] = (u32)GetCursorSelectionMonId();
    DestroyTask(taskId);
}

bool8 FldEff_UseTeleport(void)
{
    u8 taskId = CreateFieldEffectShowMon();
    FLDEFF_SET_FUNC_TO_DATA(StartTeleportFieldEffect);
    SetPlayerAvatarTransitionFlags(PLAYER_AVATAR_FLAG_ON_FOOT);
    return FALSE;
}

static void StartTeleportFieldEffect(void)
{
    FieldEffectActiveListRemove(FLDEFF_USE_TELEPORT);
    CreateTeleportFieldEffectTask();
}
