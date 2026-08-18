# 1 "data/maps/SevenIsland_House_Room1/scripts.pory"

# 2 "data/maps/SevenIsland_House_Room1/scripts.pory"
.equ TRAINER_VISITING, VAR_TEMP_1
# 3 "data/maps/SevenIsland_House_Room1/scripts.pory"

# 4 "data/maps/SevenIsland_House_Room1/scripts.pory"
SevenIsland_House_Room1_MapScripts::
# 5 "data/maps/SevenIsland_House_Room1/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SevenIsland_House_Room1_OnTransition
# 6 "data/maps/SevenIsland_House_Room1/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SevenIsland_House_Room1_OnFrame
# 7 "data/maps/SevenIsland_House_Room1/scripts.pory"
	.byte 0
# 8 "data/maps/SevenIsland_House_Room1/scripts.pory"

# 9 "data/maps/SevenIsland_House_Room1/scripts.pory"
SevenIsland_House_Room1_OnTransition::
# 10 "data/maps/SevenIsland_House_Room1/scripts.pory"
	special ValidateEReaderTrainer
# 11 "data/maps/SevenIsland_House_Room1/scripts.pory"
	call_if_eq VAR_RESULT, 0, SevenIsland_House_Room1_EventScript_SetTrainerVisitingLayout
# 12 "data/maps/SevenIsland_House_Room1/scripts.pory"
	call_if_ne VAR_MAP_SCENE_SEVEN_ISLAND_HOUSE_ROOM1, 0, SevenIsland_House_Room1_EventScript_MoveOldWomanToDoor
# 13 "data/maps/SevenIsland_House_Room1/scripts.pory"
	end
# 14 "data/maps/SevenIsland_House_Room1/scripts.pory"

# 15 "data/maps/SevenIsland_House_Room1/scripts.pory"
SevenIsland_House_Room1_EventScript_SetTrainerVisitingLayout::
# 16 "data/maps/SevenIsland_House_Room1/scripts.pory"
	setvar TRAINER_VISITING, TRUE
# 17 "data/maps/SevenIsland_House_Room1/scripts.pory"
	setobjectxyperm LOCALID_SEVEN_ISLAND_HOUSE_OLD_WOMAN, 4, 2
# 18 "data/maps/SevenIsland_House_Room1/scripts.pory"
	setobjectmovementtype LOCALID_SEVEN_ISLAND_HOUSE_OLD_WOMAN, MOVEMENT_TYPE_FACE_DOWN
# 19 "data/maps/SevenIsland_House_Room1/scripts.pory"
	setmaplayoutindex LAYOUT_SEVEN_ISLAND_HOUSE_ROOM1_DOOR_OPEN
# 20 "data/maps/SevenIsland_House_Room1/scripts.pory"
	return
# 21 "data/maps/SevenIsland_House_Room1/scripts.pory"

# 22 "data/maps/SevenIsland_House_Room1/scripts.pory"
SevenIsland_House_Room1_EventScript_MoveOldWomanToDoor::
# 23 "data/maps/SevenIsland_House_Room1/scripts.pory"
	setobjectxyperm LOCALID_SEVEN_ISLAND_HOUSE_OLD_WOMAN, 3, 2
# 24 "data/maps/SevenIsland_House_Room1/scripts.pory"
	setobjectmovementtype LOCALID_SEVEN_ISLAND_HOUSE_OLD_WOMAN, MOVEMENT_TYPE_FACE_RIGHT
# 25 "data/maps/SevenIsland_House_Room1/scripts.pory"
	return
# 26 "data/maps/SevenIsland_House_Room1/scripts.pory"

# 27 "data/maps/SevenIsland_House_Room1/scripts.pory"
SevenIsland_House_Room1_OnFrame::
# 28 "data/maps/SevenIsland_House_Room1/scripts.pory"
	map_script_2 VAR_MAP_SCENE_SEVEN_ISLAND_HOUSE_ROOM1, 1, SevenIsland_House_Room1_EventScript_OldWomanCommentOnBattle
# 29 "data/maps/SevenIsland_House_Room1/scripts.pory"
	map_script_2 VAR_MAP_SCENE_SEVEN_ISLAND_HOUSE_ROOM1, 2, SevenIsland_House_Room1_EventScript_OldWomanCommentOnBattle
# 30 "data/maps/SevenIsland_House_Room1/scripts.pory"
	map_script_2 VAR_MAP_SCENE_SEVEN_ISLAND_HOUSE_ROOM1, 3, SevenIsland_House_Room1_EventScript_OldWomanCommentOnBattle
# 31 "data/maps/SevenIsland_House_Room1/scripts.pory"
	.2byte 0
# 32 "data/maps/SevenIsland_House_Room1/scripts.pory"

# 33 "data/maps/SevenIsland_House_Room1/scripts.pory"
SevenIsland_House_Room1_EventScript_OldWomanCommentOnBattle::
# 34 "data/maps/SevenIsland_House_Room1/scripts.pory"
	lockall
# 35 "data/maps/SevenIsland_House_Room1/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 36 "data/maps/SevenIsland_House_Room1/scripts.pory"
	applymovement LOCALID_PLAYER, SevenIsland_House_Room1_Movement_PlayerReEnterRoom
# 37 "data/maps/SevenIsland_House_Room1/scripts.pory"
	waitmovement 0
# 38 "data/maps/SevenIsland_House_Room1/scripts.pory"
	applymovement LOCALID_SEVEN_ISLAND_HOUSE_OLD_WOMAN, SevenIsland_House_Room1_Movement_OldWomanWalkBehindPlayer
# 39 "data/maps/SevenIsland_House_Room1/scripts.pory"
	waitmovement 0
# 40 "data/maps/SevenIsland_House_Room1/scripts.pory"
	copyobjectxytoperm LOCALID_SEVEN_ISLAND_HOUSE_OLD_WOMAN
# 41 "data/maps/SevenIsland_House_Room1/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 42 "data/maps/SevenIsland_House_Room1/scripts.pory"
	waitmovement 0
# 43 "data/maps/SevenIsland_House_Room1/scripts.pory"
	call_if_eq VAR_MAP_SCENE_SEVEN_ISLAND_HOUSE_ROOM1, 1, SevenIsland_House_Room1_EventScript_BattleWonComment
# 44 "data/maps/SevenIsland_House_Room1/scripts.pory"
	call_if_eq VAR_MAP_SCENE_SEVEN_ISLAND_HOUSE_ROOM1, 2, SevenIsland_House_Room1_EventScript_BattleLostComment
# 45 "data/maps/SevenIsland_House_Room1/scripts.pory"
	call_if_eq VAR_MAP_SCENE_SEVEN_ISLAND_HOUSE_ROOM1, 3, SevenIsland_House_Room1_EventScript_BattleTiedComment
# 46 "data/maps/SevenIsland_House_Room1/scripts.pory"
	special LoadPlayerParty
# 47 "data/maps/SevenIsland_House_Room1/scripts.pory"
	setvar VAR_MAP_SCENE_SEVEN_ISLAND_HOUSE_ROOM1, 0
# 48 "data/maps/SevenIsland_House_Room1/scripts.pory"
	releaseall
# 49 "data/maps/SevenIsland_House_Room1/scripts.pory"
	end
# 50 "data/maps/SevenIsland_House_Room1/scripts.pory"

# 51 "data/maps/SevenIsland_House_Room1/scripts.pory"
SevenIsland_House_Room1_EventScript_BattleWonComment::
# 52 "data/maps/SevenIsland_House_Room1/scripts.pory"
	msgbox SevenIsland_House_Room1_Text_AstoundingBattle
# 53 "data/maps/SevenIsland_House_Room1/scripts.pory"
	return
# 54 "data/maps/SevenIsland_House_Room1/scripts.pory"

# 55 "data/maps/SevenIsland_House_Room1/scripts.pory"
SevenIsland_House_Room1_EventScript_BattleLostComment::
# 56 "data/maps/SevenIsland_House_Room1/scripts.pory"
	msgbox SevenIsland_House_Room1_Text_FeelYourDisappointment
# 57 "data/maps/SevenIsland_House_Room1/scripts.pory"
	return
# 58 "data/maps/SevenIsland_House_Room1/scripts.pory"

# 59 "data/maps/SevenIsland_House_Room1/scripts.pory"
SevenIsland_House_Room1_EventScript_BattleTiedComment::
# 60 "data/maps/SevenIsland_House_Room1/scripts.pory"
	msgbox SevenIsland_House_Room1_Text_DrawWasIt
# 61 "data/maps/SevenIsland_House_Room1/scripts.pory"
	return
# 62 "data/maps/SevenIsland_House_Room1/scripts.pory"

# 63 "data/maps/SevenIsland_House_Room1/scripts.pory"
SevenIsland_House_Room1_Movement_PlayerReEnterRoom::
# 64 "data/maps/SevenIsland_House_Room1/scripts.pory"
	walk_down
# 65 "data/maps/SevenIsland_House_Room1/scripts.pory"
	step_end
# 66 "data/maps/SevenIsland_House_Room1/scripts.pory"

# 67 "data/maps/SevenIsland_House_Room1/scripts.pory"
SevenIsland_House_Room1_Movement_OldWomanWalkBehindPlayer::
# 68 "data/maps/SevenIsland_House_Room1/scripts.pory"
	walk_right
# 69 "data/maps/SevenIsland_House_Room1/scripts.pory"
	walk_in_place_faster_down
# 70 "data/maps/SevenIsland_House_Room1/scripts.pory"
	step_end
# 71 "data/maps/SevenIsland_House_Room1/scripts.pory"

# 72 "data/maps/SevenIsland_House_Room1/scripts.pory"
SevenIsland_House_Room1_EventScript_OldWoman::
# 73 "data/maps/SevenIsland_House_Room1/scripts.pory"
	lock
# 74 "data/maps/SevenIsland_House_Room1/scripts.pory"
	faceplayer
# 75 "data/maps/SevenIsland_House_Room1/scripts.pory"
	special ValidateEReaderTrainer
# 76 "data/maps/SevenIsland_House_Room1/scripts.pory"
	call_if_eq VAR_RESULT, 1, SevenIsland_House_Room1_EventScript_InvalidVisitingTrainer
# 77 "data/maps/SevenIsland_House_Room1/scripts.pory"
	goto_if_eq TRAINER_VISITING, TRUE, SevenIsland_House_Room1_EventScript_TrainerVisiting
# 78 "data/maps/SevenIsland_House_Room1/scripts.pory"
	msgbox SevenIsland_House_Room1_Text_OnlyEnjoymentWatchingBattles
# 79 "data/maps/SevenIsland_House_Room1/scripts.pory"
	release
# 80 "data/maps/SevenIsland_House_Room1/scripts.pory"
	end
# 81 "data/maps/SevenIsland_House_Room1/scripts.pory"

# 82 "data/maps/SevenIsland_House_Room1/scripts.pory"
SevenIsland_House_Room1_EventScript_InvalidVisitingTrainer::
# 83 "data/maps/SevenIsland_House_Room1/scripts.pory"
	msgbox SevenIsland_House_Room1_Text_OnlyEnjoymentWatchingBattles
# 84 "data/maps/SevenIsland_House_Room1/scripts.pory"
	release
# 85 "data/maps/SevenIsland_House_Room1/scripts.pory"
	end
# 86 "data/maps/SevenIsland_House_Room1/scripts.pory"

# 87 "data/maps/SevenIsland_House_Room1/scripts.pory"
SevenIsland_House_Room1_EventScript_TrainerVisiting::
# 88 "data/maps/SevenIsland_House_Room1/scripts.pory"
	special SavePlayerParty
# 89 "data/maps/SevenIsland_House_Room1/scripts.pory"
	special BufferEReaderTrainerName
# 90 "data/maps/SevenIsland_House_Room1/scripts.pory"
	msgbox SevenIsland_House_Room1_Text_ChallengeVisitingTrainer, MSGBOX_YESNO
# 91 "data/maps/SevenIsland_House_Room1/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SevenIsland_House_Room1_EventScript_DeclineBattle
# 92 "data/maps/SevenIsland_House_Room1/scripts.pory"
	call SevenIsland_House_Room1_EventScript_ChooseParty
# 93 "data/maps/SevenIsland_House_Room1/scripts.pory"
	goto_if_eq VAR_RESULT, 0, SevenIsland_House_Room1_EventScript_DeclineBattle
# 94 "data/maps/SevenIsland_House_Room1/scripts.pory"
	msgbox SevenIsland_House_Room1_Text_SaveProgressBeforeBattle, MSGBOX_YESNO
# 95 "data/maps/SevenIsland_House_Room1/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SevenIsland_House_Room1_EventScript_DeclineBattle
# 96 "data/maps/SevenIsland_House_Room1/scripts.pory"
	special LoadPlayerParty
# 97 "data/maps/SevenIsland_House_Room1/scripts.pory"
	call EventScript_AskSaveGame
# 98 "data/maps/SevenIsland_House_Room1/scripts.pory"
	goto_if_eq VAR_RESULT, 0, SevenIsland_House_Room1_EventScript_DeclineBattle
# 99 "data/maps/SevenIsland_House_Room1/scripts.pory"
	special SavePlayerParty
# 100 "data/maps/SevenIsland_House_Room1/scripts.pory"
	special ReducePlayerPartyToThree
# 101 "data/maps/SevenIsland_House_Room1/scripts.pory"
	msgbox SevenIsland_House_Room1_Text_DontHoldAnythingBack
# 102 "data/maps/SevenIsland_House_Room1/scripts.pory"
	closemessage
# 103 "data/maps/SevenIsland_House_Room1/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, SevenIsland_House_Room1_EventScript_EnterBattleRoomNorth
# 104 "data/maps/SevenIsland_House_Room1/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, SevenIsland_House_Room1_EventScript_EnterBattleRoomEast
# 105 "data/maps/SevenIsland_House_Room1/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, SevenIsland_House_Room1_EventScript_EnterBattleRoomWest
# 106 "data/maps/SevenIsland_House_Room1/scripts.pory"
	warp MAP_SEVEN_ISLAND_HOUSE_ROOM2, 3, 1
# 107 "data/maps/SevenIsland_House_Room1/scripts.pory"
	waitstate
# 108 "data/maps/SevenIsland_House_Room1/scripts.pory"
	release
# 109 "data/maps/SevenIsland_House_Room1/scripts.pory"
	end
# 110 "data/maps/SevenIsland_House_Room1/scripts.pory"

# 111 "data/maps/SevenIsland_House_Room1/scripts.pory"
SevenIsland_House_Room1_EventScript_DeclineBattle::
# 112 "data/maps/SevenIsland_House_Room1/scripts.pory"
	special LoadPlayerParty
# 113 "data/maps/SevenIsland_House_Room1/scripts.pory"
	msgbox SevenIsland_House_Room1_Text_OhYouWontBattle
# 114 "data/maps/SevenIsland_House_Room1/scripts.pory"
	release
# 115 "data/maps/SevenIsland_House_Room1/scripts.pory"
	end
# 116 "data/maps/SevenIsland_House_Room1/scripts.pory"

# 117 "data/maps/SevenIsland_House_Room1/scripts.pory"
SevenIsland_House_Room1_EventScript_ChooseParty::
# 118 "data/maps/SevenIsland_House_Room1/scripts.pory"
	msgbox SevenIsland_House_Room1_Text_LimitThreeMonsPerSide
# 119 "data/maps/SevenIsland_House_Room1/scripts.pory"
	fadescreen FADE_TO_BLACK
# 120 "data/maps/SevenIsland_House_Room1/scripts.pory"
	special ChooseHalfPartyForBattle
# 121 "data/maps/SevenIsland_House_Room1/scripts.pory"
	waitstate
# 122 "data/maps/SevenIsland_House_Room1/scripts.pory"
	return
# 123 "data/maps/SevenIsland_House_Room1/scripts.pory"

# 124 "data/maps/SevenIsland_House_Room1/scripts.pory"
SevenIsland_House_Room1_EventScript_EnterBattleRoomNorth::
# 125 "data/maps/SevenIsland_House_Room1/scripts.pory"
	applymovement VAR_LAST_TALKED, SevenIsland_House_Room1_Movement_OldWomanMoveAsideLeft
# 126 "data/maps/SevenIsland_House_Room1/scripts.pory"
	applymovement LOCALID_PLAYER, SevenIsland_House_Room1_Movement_PlayerEnterBattleRoomNorth
# 127 "data/maps/SevenIsland_House_Room1/scripts.pory"
	waitmovement 0
# 128 "data/maps/SevenIsland_House_Room1/scripts.pory"
	return
# 129 "data/maps/SevenIsland_House_Room1/scripts.pory"

# 130 "data/maps/SevenIsland_House_Room1/scripts.pory"
SevenIsland_House_Room1_EventScript_EnterBattleRoomEast::
# 131 "data/maps/SevenIsland_House_Room1/scripts.pory"
	applymovement VAR_LAST_TALKED, SevenIsland_House_Room1_Movement_OldWomanMoveAsideRight
# 132 "data/maps/SevenIsland_House_Room1/scripts.pory"
	applymovement LOCALID_PLAYER, SevenIsland_House_Room1_Movement_PlayerEnterBattleRoomEast
# 133 "data/maps/SevenIsland_House_Room1/scripts.pory"
	waitmovement 0
# 134 "data/maps/SevenIsland_House_Room1/scripts.pory"
	return
# 135 "data/maps/SevenIsland_House_Room1/scripts.pory"

# 136 "data/maps/SevenIsland_House_Room1/scripts.pory"
SevenIsland_House_Room1_EventScript_EnterBattleRoomWest::
# 137 "data/maps/SevenIsland_House_Room1/scripts.pory"
	applymovement VAR_LAST_TALKED, SevenIsland_House_Room1_Movement_OldWomanMoveAsideLeft
# 138 "data/maps/SevenIsland_House_Room1/scripts.pory"
	applymovement LOCALID_PLAYER, SevenIsland_House_Room1_Movement_PlayerEnterBattleRoomWest
# 139 "data/maps/SevenIsland_House_Room1/scripts.pory"
	waitmovement 0
# 140 "data/maps/SevenIsland_House_Room1/scripts.pory"
	return
# 141 "data/maps/SevenIsland_House_Room1/scripts.pory"

# 142 "data/maps/SevenIsland_House_Room1/scripts.pory"
SevenIsland_House_Room1_Movement_PlayerEnterBattleRoomNorth::
# 143 "data/maps/SevenIsland_House_Room1/scripts.pory"
	delay_16
# 144 "data/maps/SevenIsland_House_Room1/scripts.pory"
	walk_up
# 145 "data/maps/SevenIsland_House_Room1/scripts.pory"
	walk_up
# 146 "data/maps/SevenIsland_House_Room1/scripts.pory"
	step_end
# 147 "data/maps/SevenIsland_House_Room1/scripts.pory"

# 148 "data/maps/SevenIsland_House_Room1/scripts.pory"
SevenIsland_House_Room1_Movement_PlayerEnterBattleRoomEast::
# 149 "data/maps/SevenIsland_House_Room1/scripts.pory"
	delay_16
# 150 "data/maps/SevenIsland_House_Room1/scripts.pory"
	walk_right
# 151 "data/maps/SevenIsland_House_Room1/scripts.pory"
	walk_up
# 152 "data/maps/SevenIsland_House_Room1/scripts.pory"
	step_end
# 153 "data/maps/SevenIsland_House_Room1/scripts.pory"

# 154 "data/maps/SevenIsland_House_Room1/scripts.pory"
SevenIsland_House_Room1_Movement_PlayerEnterBattleRoomWest::
# 155 "data/maps/SevenIsland_House_Room1/scripts.pory"
	delay_16
# 156 "data/maps/SevenIsland_House_Room1/scripts.pory"
	walk_left
# 157 "data/maps/SevenIsland_House_Room1/scripts.pory"
	walk_up
# 158 "data/maps/SevenIsland_House_Room1/scripts.pory"
	step_end
# 159 "data/maps/SevenIsland_House_Room1/scripts.pory"

# 160 "data/maps/SevenIsland_House_Room1/scripts.pory"
SevenIsland_House_Room1_Movement_OldWomanMoveAsideLeft::
# 161 "data/maps/SevenIsland_House_Room1/scripts.pory"
	walk_left
# 162 "data/maps/SevenIsland_House_Room1/scripts.pory"
	walk_in_place_faster_right
# 163 "data/maps/SevenIsland_House_Room1/scripts.pory"
	step_end
# 164 "data/maps/SevenIsland_House_Room1/scripts.pory"

# 165 "data/maps/SevenIsland_House_Room1/scripts.pory"
SevenIsland_House_Room1_Movement_OldWomanMoveAsideRight::
# 166 "data/maps/SevenIsland_House_Room1/scripts.pory"
	walk_right
# 167 "data/maps/SevenIsland_House_Room1/scripts.pory"
	walk_in_place_faster_left
# 168 "data/maps/SevenIsland_House_Room1/scripts.pory"
	step_end
# 169 "data/maps/SevenIsland_House_Room1/scripts.pory"

# 170 "data/maps/SevenIsland_House_Room1/scripts.pory"
SevenIsland_House_Room1_EventScript_Box::
# 171 "data/maps/SevenIsland_House_Room1/scripts.pory"
	msgbox SevenIsland_House_Room1_Text_SlightBreezeAroundBox, MSGBOX_SIGN
# 172 "data/maps/SevenIsland_House_Room1/scripts.pory"
	end
