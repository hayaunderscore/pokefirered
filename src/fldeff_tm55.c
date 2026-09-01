#include "global.h"
#include "gflib.h"
#include "field_player_avatar.h"
#include "field_effect.h"
#include "party_menu.h"
#include "event_data.h"
#include "script.h"
#include "fldeff.h"
#include "event_scripts.h"
#include "overworld.h"
#include "event_object_movement.h"
#include "constants/songs.h"
#include "constants/event_objects.h"
#include "constants/event_object_movement.h"
#include "constants/maps.h"

static void StartTM55FieldEffect(void);

bool8 FldEff_UseTM55(void)
{
    u8 taskId = CreateFieldEffectShowMon();

    FLDEFF_SET_FUNC_TO_DATA(StartTM55FieldEffect);
    SetPlayerAvatarTransitionFlags(PLAYER_AVATAR_FLAG_ON_FOOT);
    // IncrementGameStat(GAME_STAT_USED_ROCK_SMASH);
    return FALSE;
}

static void StartTM55FieldEffect(void)
{
    // PlaySE(SE_M_ROCK_THROW);
    FieldEffectActiveListRemove(FLDEFF_USE_TM55);
    ScriptContext_Enable();
}
