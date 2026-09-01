EventScript_CutTree::
	goto_if_questlog EventScript_ReleaseEnd
	lockall
	goto_if_unset FLAG_BADGE02_GET, EventScript_CantCutTree
	checkpartymove MOVE_CUT
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantCutTree
	setfieldeffectargument 0, VAR_RESULT
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	buffermovename STR_VAR_2, MOVE_CUT
	msgbox Text_CutTreeDown, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_DontCutTree
	msgbox Text_MonUsedMove
	closemessage
	dofieldeffect FLDEFF_USE_CUT_ON_TREE
	waitstate
	goto EventScript_CutTreeDown
	end

EventScript_FldEffCut::
	lockall
	dofieldeffect FLDEFF_USE_CUT_ON_TREE
	waitstate
	goto EventScript_CutTreeDown
	end

EventScript_CutTreeDown::
	applymovement VAR_LAST_TALKED, Movement_CutTreeDown
	waitmovement 0
	removeobject VAR_LAST_TALKED
	releaseall
	end

Movement_CutTreeDown::
	cut_tree
	step_end

EventScript_CantCutTree::
	msgbox Text_TreeCanBeCutDown, MSGBOX_SIGN
	releaseall
	end

EventScript_DontCutTree::
	closemessage
	releaseall
	end

Text_CutTreeDown::
	.string "This tree looks like it can be CUT\n"
	.string "down!\p"
	.string "Would you like to CUT it?$"

Text_MonUsedMove::
	.string "{STR_VAR_1} used {STR_VAR_2}!$"

Text_TreeCanBeCutDown::
	.string "This tree looks like it can be CUT\n"
	.string "down!$"

EventScript_RockSmash::
	goto_if_questlog EventScript_ReleaseEnd
	lockall
	goto_if_unset FLAG_BADGE06_GET, EventScript_CantSmashRock
	checkpartymove MOVE_ROCK_SMASH
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantSmashRock
	setfieldeffectargument 0, VAR_RESULT
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	buffermovename STR_VAR_2, MOVE_ROCK_SMASH
	msgbox Text_UseRockSmash, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_DontSmashRock
	msgbox Text_MonUsedMove
	closemessage
	dofieldeffect FLDEFF_USE_ROCK_SMASH
	waitstate
	goto EventScript_UseRockSmash
	end

EventScript_FldEffRockSmash::
	lockall
	dofieldeffect FLDEFF_USE_ROCK_SMASH
	waitstate
	goto EventScript_UseRockSmash
	end

EventScript_UseRockSmash::
	applymovement VAR_LAST_TALKED, Movement_BreakRock
	waitmovement 0
	removeobject VAR_LAST_TALKED
	special RockSmashWildEncounter
	goto_if_eq VAR_RESULT, FALSE, EventScript_RockSmashNoEncounter
	waitstate
	releaseall
	end

EventScript_RockSmashNoEncounter::
	releaseall
	end

Movement_BreakRock::
	rock_smash_break
	step_end

EventScript_CantSmashRock::
	msgbox Text_MonMaySmashRock, MSGBOX_SIGN
	end

EventScript_DontSmashRock::
	closemessage
	releaseall
	end

Text_UseRockSmash::
	.string "This rock appears to be breakable.\n"
	.string "Would you like to use ROCK SMASH?$"

Text_MonMaySmashRock::
	.string "It's a rugged rock, but a POKéMON\n"
	.string "may be able to smash it.$"

EventScript_StrengthBoulder::
	goto_if_questlog EventScript_ReleaseEnd
	lockall
	goto_if_unset FLAG_BADGE04_GET, EventScript_CantMoveBoulder
	goto_if_set FLAG_SYS_USE_STRENGTH, EventScript_AlreadyUsedStrength
	checkpartymove MOVE_STRENGTH
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantMoveBoulder
	setfieldeffectargument 0, VAR_RESULT
	msgbox Text_UseStrength, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_DontUseStrength
	closemessage
	dofieldeffect FLDEFF_USE_STRENGTH
	waitstate
	goto EventScript_UseStrength
	end

EventScript_FldEffStrength::
	lockall
	dofieldeffect FLDEFF_USE_STRENGTH
	waitstate
	goto EventScript_UseStrength
	end

EventScript_UseStrength::
	setflag FLAG_SYS_USE_STRENGTH
	msgbox Text_MonUsedStrengthCanMoveBoulders, MSGBOX_SIGN
	end

EventScript_CantMoveBoulder::
	msgbox Text_MonMayPushBoulder, MSGBOX_SIGN
	end

EventScript_AlreadyUsedStrength::
	msgbox Text_StrengthMadeMovingBouldersPossible, MSGBOX_SIGN
	end

EventScript_DontUseStrength::
	closemessage
	releaseall
	end

Text_UseStrength::
	.string "It's a big boulder, but a POKéMON\n"
	.string "may be able to push it aside.\p"
	.string "Would you like to use STRENGTH?$"

Text_MonUsedStrengthCanMoveBoulders::
	.string "{STR_VAR_1} used STRENGTH!\p"
	.string "{STR_VAR_1}'s STRENGTH made it\n"
	.string "possible to move boulders around!$"

Text_MonMayPushBoulder::
	.string "It's a big boulder, but a POKéMON\n"
	.string "may be able to push it aside.$"

Text_StrengthMadeMovingBouldersPossible::
	.string "STRENGTH made it possible to move\n"
	.string "boulders around.$"

EventScript_Waterfall::
	goto_if_questlog EventScript_ReleaseEnd
	lockall
	checkpartymove MOVE_WATERFALL
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_WaterCrashingDown
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	msgbox Text_UseWaterfall, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_EndWaterfall
	msgbox Text_MonUsedWaterfall
	call FollowerIntoPlayerScript
    callnative HideFollower
	dofieldeffect FLDEFF_USE_WATERFALL
	callnative FollowMe_WarpSetEnd
	goto EventScript_EndWaterfall

EventScript_CantUseWaterfall::
	lockall
EventScript_WaterCrashingDown:
	msgbox Text_WallOfWaterCrashingDown
EventScript_EndWaterfall:
	releaseall
	end

Text_WallOfWaterCrashingDown::
	.string "A wall of water is crashing down\n"
	.string "with a mighty roar.$"

Text_UseWaterfall::
	.string "It's a large waterfall.\n"
	.string "Would you like to use WATERFALL?$"

Text_MonUsedWaterfall::
	.string "{STR_VAR_1} used WATERFALL.$"

@ Unused leftover from R/S
EventScript_DeepWater::
	lockall
	checkpartymove MOVE_DIVE
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_MayGoUnderwater
	copyvar 0x8004 VAR_RESULT
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	setfieldeffectargument 1, 1
	msgbox Text_SeaIsDeepUseDive, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_EndDive
	msgbox Text_MonUsedDive
	call FollowerIntoPlayerScript
	callnative HideFollower
	setfieldeffectargument 0, VAR_0x8004
	setfieldeffectargument 1, 1
	dofieldeffect FLDEFF_USE_DIVE
	goto EventScript_EndDive

EventScript_CantDive::
	lockall
EventScript_MayGoUnderwater:
	msgbox Text_MonMayGoUnderwater
EventScript_EndDive:
	releaseall
	end

EventScript_TrySurface::
	lockall
	checkpartymove MOVE_DIVE
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantSurface
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	setfieldeffectargument 1, 1
	msgbox Text_LightFilteringUseDive, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_EndSurface
	msgbox Text_MonUsedDive
	dofieldeffect FLDEFF_USE_DIVE
	goto EventScript_EndSurface

EventScript_CantSurface::
	lockall
	msgbox Text_MonMaySurface
	goto EventScript_EndSurface

EventScript_ObstacleCantSurface::
	lockall
	msgbox Text_DiveCantBeUsedHere
EventScript_EndSurface:
	releaseall
	end

Text_MonMayGoUnderwater::
	.string "The sea is deep here. A POKéMON\n"
	.string "may be able to go underwater.$"

Text_SeaIsDeepUseDive::
	.string "The sea is deep here.\n"
	.string "Would you like to use DIVE?$"

Text_MonUsedDive::
	.string "{STR_VAR_1} used DIVE.$"

Text_MonMaySurface::
	.string "Light is filtering down from above.\n"
	.string "A POKéMON may be able to surface.$"

Text_LightFilteringUseDive::
	.string "Light is filtering down from above.\n"
	.string "Would you like to use DIVE?$"

Text_DiveCantBeUsedHere::
	.string "There is an obstacle above.\n"
	.string "DIVE can't be used here.$"

EventScript_FailSweetScent::
	msgbox Text_LooksLikeNothingHere, MSGBOX_SIGN
	end

Text_LooksLikeNothingHere::
	.string "Looks like there's nothing here…$"

FollowerPositionFixScript::
	setvar 0x8000 0x0
	callnative FollowerTrainerSightingPositionFix
	compare VAR_RESULT 0xFFFF
	goto_if_eq FollowerPositionFixScriptReturn
	call WalkCall
	setvar 0x8000 0x1
	callnative FollowerTrainerSightingPositionFix
FollowerPositionFixScriptReturn:
	return

FollowerIntoPlayerScript::
	setvar 0x8000 0x0
	callnative FollowerIntoPlayer
	compare VAR_RESULT 0xFFFF
	goto_if_eq FollowerPositionFixScriptReturn
	setvar 0x8005 0xFE  @ follower
	call WalkCall
	setvar 0x8000 0x1
	callnative FollowerIntoPlayer
	return

WalkCall:
	compare VAR_RESULT 0x0
	call_if_eq WalkDownCall
	compare VAR_RESULT 0x1
	call_if_eq WalkUpCall
	compare VAR_RESULT 0x2
	call_if_eq WalkLeftCall
	compare VAR_RESULT 0x3
	call_if_eq WalkRightCall
	waitmovement 0x8005
	return

WalkDownCall:
	applymovement 0x8005 WalkDown
	return

WalkUpCall:
	applymovement 0x8005 WalkUp
	return

WalkLeftCall:
	applymovement 0x8005 WalkLeft
	return

WalkRightCall:
	applymovement 0x8005 WalkRight
	return

WalkDown:
    walk_down
    step_end

WalkUp:
    walk_up
    step_end

WalkLeft:
    walk_left
    step_end

WalkRight:
    walk_right
    step_end

EventScript_UseTM55::
	checkpartymove MOVE_ABYSS
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EventScript_UseTM55_4
EventScript_UseTM55_1:
	checkpartymove MOVE_ABYSS
	compare_var_to_value VAR_RESULT, PARTY_SIZE
	goto_if_ne EventScript_UseTM55_9
	checkpartymove MOVE_RAPTURE
	compare_var_to_value VAR_RESULT, PARTY_SIZE
	goto_if_ne EventScript_UseTM55_10
	checkpartymove MOVE_STRIKE
	compare_var_to_value VAR_RESULT, PARTY_SIZE
	goto_if_ne EventScript_UseTM55_11
EventScript_UseTM55_8:
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	buffermovename STR_VAR_2, VAR_TEMP_5
	msgbox Text_MonUsedMove
	closemessage
	dofieldeffect FLDEFF_USE_TM55
	waitstate
	goto EventScript_TM55Effect
	end

EventScript_UseTM55_2:
	end

EventScript_UseTM55_3:
	checkpartymove MOVE_STRIKE
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EventScript_UseTM55_2
	goto EventScript_UseTM55_1

EventScript_UseTM55_4:
	checkpartymove MOVE_RAPTURE
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EventScript_UseTM55_3
	goto EventScript_UseTM55_1

EventScript_UseTM55_9:
	copyvar VAR_TEMP_4, VAR_RESULT
	setvar VAR_TEMP_5, MOVE_ABYSS
	goto EventScript_UseTM55_8

EventScript_UseTM55_10:
	copyvar VAR_TEMP_4, VAR_RESULT
	setvar VAR_TEMP_5, MOVE_RAPTURE
	goto EventScript_UseTM55_8

EventScript_UseTM55_11:
	copyvar VAR_TEMP_4, VAR_RESULT
	setvar VAR_TEMP_5, MOVE_STRIKE
	goto EventScript_UseTM55_8

EventScript_FldEffTM55::
	lockall
	dofieldeffect FLDEFF_USE_TM55
	waitstate
	goto EventScript_TM55Effect
	return

EventScript_TM55Effect::
	fadescreen FADE_TO_WHITE
	delay 30
	playse SE_M_EARTHQUAKE
	waitse
	playse SE_M_DIVE
	waitse
	delay 30
	removeobject VAR_LAST_TALKED
	fadescreen FADE_FROM_WHITE
	return
