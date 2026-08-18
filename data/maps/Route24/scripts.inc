# 1 "data/maps/Route24/scripts.pory"

# 2 "data/maps/Route24/scripts.pory"
Route24_MapScripts::
# 3 "data/maps/Route24/scripts.pory"
	.byte 0
# 4 "data/maps/Route24/scripts.pory"

# 5 "data/maps/Route24/scripts.pory"
Route24_EventScript_Rocket::
# 6 "data/maps/Route24/scripts.pory"
	lock
# 7 "data/maps/Route24/scripts.pory"
	faceplayer
# 8 "data/maps/Route24/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_ROUTE24, 1, Route24_EventScript_RocketPostBattle
# 9 "data/maps/Route24/scripts.pory"
	msgbox Route24_Text_JustEarnedFabulousPrize
# 10 "data/maps/Route24/scripts.pory"
	checkitemspace ITEM_NUGGET
# 11 "data/maps/Route24/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route24_EventScript_NoRoomForNugget
# 12 "data/maps/Route24/scripts.pory"
	call Route24_EventScript_BattleRocket
# 13 "data/maps/Route24/scripts.pory"
	release
# 14 "data/maps/Route24/scripts.pory"
	end
# 15 "data/maps/Route24/scripts.pory"

# 16 "data/maps/Route24/scripts.pory"
Route24_EventScript_NoRoomForNugget::
# 17 "data/maps/Route24/scripts.pory"
	msgbox Route24_Text_YouDontHaveAnyRoom
# 18 "data/maps/Route24/scripts.pory"
	release
# 19 "data/maps/Route24/scripts.pory"
	end
# 20 "data/maps/Route24/scripts.pory"

# 21 "data/maps/Route24/scripts.pory"
Route24_EventScript_RocketPostBattle::
# 22 "data/maps/Route24/scripts.pory"
	msgbox Route24_Text_YoudBecomeTopRocketLeader
# 23 "data/maps/Route24/scripts.pory"
	release
# 24 "data/maps/Route24/scripts.pory"
	end
# 25 "data/maps/Route24/scripts.pory"

# 26 "data/maps/Route24/scripts.pory"
Route24_EventScript_RocketTriggerLeft::
# 27 "data/maps/Route24/scripts.pory"
	lockall
# 28 "data/maps/Route24/scripts.pory"
	setvar VAR_TEMP_1, 0
# 29 "data/maps/Route24/scripts.pory"
	goto Route24_EventScript_RocketTrigger
# 30 "data/maps/Route24/scripts.pory"
	end
# 31 "data/maps/Route24/scripts.pory"

# 32 "data/maps/Route24/scripts.pory"
Route24_EventScript_RocketTriggerRight::
# 33 "data/maps/Route24/scripts.pory"
	lockall
# 34 "data/maps/Route24/scripts.pory"
	setvar VAR_TEMP_1, 1
# 35 "data/maps/Route24/scripts.pory"
	goto Route24_EventScript_RocketTrigger
# 36 "data/maps/Route24/scripts.pory"
	end
# 37 "data/maps/Route24/scripts.pory"

# 38 "data/maps/Route24/scripts.pory"
Route24_EventScript_RocketTrigger::
# 39 "data/maps/Route24/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 40 "data/maps/Route24/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, Route24_EventScript_RocketApproachPlayer
# 41 "data/maps/Route24/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, Route24_EventScript_RocketMotionToPlayer
# 42 "data/maps/Route24/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 43 "data/maps/Route24/scripts.pory"
	waitmovement 0
# 44 "data/maps/Route24/scripts.pory"
	msgbox Route24_Text_JustEarnedFabulousPrize
# 45 "data/maps/Route24/scripts.pory"
	checkitemspace ITEM_NUGGET
# 46 "data/maps/Route24/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route24_EventScript_NoRoomForNuggetTrigger
# 47 "data/maps/Route24/scripts.pory"
	call Route24_EventScript_BattleRocket
# 48 "data/maps/Route24/scripts.pory"
	releaseall
# 49 "data/maps/Route24/scripts.pory"
	end
# 50 "data/maps/Route24/scripts.pory"

# 51 "data/maps/Route24/scripts.pory"
Route24_EventScript_BattleRocket::
# 52 "data/maps/Route24/scripts.pory"
	giveitem_msg Route24_Text_ReceivedNuggetFromMysteryTrainer, ITEM_NUGGET
# 53 "data/maps/Route24/scripts.pory"
	message Route24_Text_JoinTeamRocket
# 54 "data/maps/Route24/scripts.pory"
	waitmessage
# 55 "data/maps/Route24/scripts.pory"
	playbgm MUS_ENCOUNTER_ROCKET, 0
# 56 "data/maps/Route24/scripts.pory"
	waitbuttonpress
# 57 "data/maps/Route24/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_ROUTE24_ROCKET
# 58 "data/maps/Route24/scripts.pory"
	trainerbattle_no_intro TRAINER_TEAM_ROCKET_GRUNT_6, Route24_Text_RocketDefeat
# 59 "data/maps/Route24/scripts.pory"
	msgbox Route24_Text_YoudBecomeTopRocketLeader
# 60 "data/maps/Route24/scripts.pory"
	setvar VAR_MAP_SCENE_ROUTE24, 1
# 61 "data/maps/Route24/scripts.pory"
	return
# 62 "data/maps/Route24/scripts.pory"

# 63 "data/maps/Route24/scripts.pory"
Route24_EventScript_RocketApproachPlayer::
# 64 "data/maps/Route24/scripts.pory"
	applymovement LOCALID_ROUTE24_ROCKET, Route24_Movement_RocketApproachPlayer
# 65 "data/maps/Route24/scripts.pory"
	waitmovement 0
# 66 "data/maps/Route24/scripts.pory"
	return
# 67 "data/maps/Route24/scripts.pory"

# 68 "data/maps/Route24/scripts.pory"
Route24_EventScript_RocketMotionToPlayer::
# 69 "data/maps/Route24/scripts.pory"
	applymovement LOCALID_ROUTE24_ROCKET, Common_Movement_WalkInPlaceFasterLeft
# 70 "data/maps/Route24/scripts.pory"
	waitmovement 0
# 71 "data/maps/Route24/scripts.pory"
	return
# 72 "data/maps/Route24/scripts.pory"

# 73 "data/maps/Route24/scripts.pory"
Route24_EventScript_NoRoomForNuggetTrigger::
# 74 "data/maps/Route24/scripts.pory"
	msgbox Route24_Text_YouDontHaveAnyRoom
# 75 "data/maps/Route24/scripts.pory"
	closemessage
# 76 "data/maps/Route24/scripts.pory"
	applymovement LOCALID_PLAYER, Route24_Movement_WalkDown
# 77 "data/maps/Route24/scripts.pory"
	waitmovement 0
# 78 "data/maps/Route24/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, Route24_EventScript_RocketWalkBackToPos
# 79 "data/maps/Route24/scripts.pory"
	release
# 80 "data/maps/Route24/scripts.pory"
	end
# 81 "data/maps/Route24/scripts.pory"

# 82 "data/maps/Route24/scripts.pory"
Route24_EventScript_RocketWalkBackToPos::
# 83 "data/maps/Route24/scripts.pory"
	applymovement LOCALID_ROUTE24_ROCKET, Route24_Movement_RocketWalkBackToPos
# 84 "data/maps/Route24/scripts.pory"
	waitmovement 0
# 85 "data/maps/Route24/scripts.pory"
	return
# 86 "data/maps/Route24/scripts.pory"

# 87 "data/maps/Route24/scripts.pory"
Route24_Movement_RocketApproachPlayer::
# 88 "data/maps/Route24/scripts.pory"
	walk_left
# 89 "data/maps/Route24/scripts.pory"
	step_end
# 90 "data/maps/Route24/scripts.pory"

# 91 "data/maps/Route24/scripts.pory"
Route24_Movement_RocketWalkBackToPos::
# 92 "data/maps/Route24/scripts.pory"
	walk_right
# 93 "data/maps/Route24/scripts.pory"
	walk_in_place_faster_left
# 94 "data/maps/Route24/scripts.pory"
	step_end
# 95 "data/maps/Route24/scripts.pory"

# 96 "data/maps/Route24/scripts.pory"
Route24_Movement_WalkDown::
# 97 "data/maps/Route24/scripts.pory"
	walk_down
# 98 "data/maps/Route24/scripts.pory"
	step_end
