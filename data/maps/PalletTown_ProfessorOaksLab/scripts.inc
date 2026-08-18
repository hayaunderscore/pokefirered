# 1 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 2 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
.equ PLAYER_STARTER_NUM,      VAR_TEMP_1
# 3 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
.equ PLAYER_STARTER_SPECIES,  VAR_TEMP_2
# 4 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
.equ RIVAL_STARTER_SPECIES,   VAR_TEMP_3
# 5 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
.equ RIVAL_STARTER_ID,        VAR_TEMP_4
# 6 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 7 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
.equ SHOWED_OAK_COMPLETE_DEX, FLAG_TEMP_2
# 8 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 9 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_MapScripts::
# 10 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_ProfessorOaksLab_OnTransition
# 11 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PalletTown_ProfessorOaksLab_OnWarp
# 12 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PalletTown_ProfessorOaksLab_OnFrame
# 13 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	.byte 0
# 14 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 15 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_OnTransition::
# 16 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setflag FLAG_VISITED_OAKS_LAB
# 17 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 1, PalletTown_ProfessorOaksLab_EventScript_ReadyOakForStarterScene
# 18 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 7, PalletTown_ProfessorOaksLab_EventScript_ReadyOakForNationalDexScene
# 19 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 8, PalletTown_ProfessorOaksLab_EventScript_SetNationalDexSceneFinished
# 20 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_set FLAG_GOT_POKEBALLS_FROM_OAK_AFTER_22_RIVAL, PalletTown_ProfessorOaksLab_EventScript_SetSkipPokeBallCheck
# 21 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 22 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 23 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_SetSkipPokeBallCheck::
# 24 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setflag FLAG_OAK_SKIP_22_RIVAL_CHECK
# 25 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 26 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 27 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_SetNationalDexSceneFinished::
# 28 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 9
# 29 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 30 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 31 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_ReadyOakForStarterScene::
# 32 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setobjectxyperm LOCALID_OAKS_LAB_PROF_OAK, 6, 11
# 33 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setobjectmovementtype LOCALID_OAKS_LAB_PROF_OAK, MOVEMENT_TYPE_FACE_UP
# 34 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	savebgm MUS_OAK
# 35 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 36 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 37 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_ReadyOakForNationalDexScene::
# 38 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setobjectxyperm LOCALID_OAKS_LAB_PROF_OAK, 6, 11
# 39 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setobjectmovementtype LOCALID_OAKS_LAB_PROF_OAK, MOVEMENT_TYPE_FACE_UP
# 40 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 41 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 42 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_OnWarp::
# 43 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	map_script_2 VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 1, PalletTown_ProfessorOaksLab_EventScript_ReadyPlayerForStarterScene
# 44 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	.2byte 0
# 45 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 46 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_ReadyPlayerForStarterScene::
# 47 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 48 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 49 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 50 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_OnFrame::
# 51 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	map_script_2 VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 1, PalletTown_ProfessorOaksLab_ChooseStarterScene
# 52 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	map_script_2 VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 7, PalletTown_ProfessorOaksLab_EventScript_EnterForNationalDexScene
# 53 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	.2byte 0
# 54 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 55 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_EnterForNationalDexScene:: @ 8169002 
# 56 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	lockall
# 57 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_FACING, DIR_NORTH
# 58 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 59 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakEnter
# 60 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 61 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	removeobject LOCALID_OAKS_LAB_PROF_OAK
# 62 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setobjectxyperm LOCALID_OAKS_LAB_PROF_OAK, 6, 3
# 63 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setobjectmovementtype LOCALID_OAKS_LAB_PROF_OAK, MOVEMENT_TYPE_FACE_DOWN
# 64 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	clearflag FLAG_HIDE_OAK_IN_HIS_LAB
# 65 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PLAYER, PalletTown_ProfessorOaksLab_Movement_PlayerEnter
# 66 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 67 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_NationalDexScene
# 68 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 69 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 70 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_NationalDexScene::
# 71 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakSightingsOfRareMons
# 72 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 73 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, PalletTown_ProfessorOaksLab_EventScript_NationalDexSceneRivalEnterNorth
# 74 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, PalletTown_ProfessorOaksLab_EventScript_NationalDexSceneRivalEnterSouth
# 75 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, PalletTown_ProfessorOaksLab_EventScript_NationalDexSceneRivalEnterEastWest
# 76 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, PalletTown_ProfessorOaksLab_EventScript_NationalDexSceneRivalEnterEastWest
# 77 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalJustLetMeHandleEverything
# 78 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	fadedefaultbgm
# 79 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakNeedYourHelpTooNeedToSeePokedexes
# 80 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, PalletTown_ProfessorOaksLab_EventScript_PlayerFaceOakNorth
# 81 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, PalletTown_ProfessorOaksLab_EventScript_PlayerFaceOakWest
# 82 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 83 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakTookBothPokedexUnits
# 84 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 85 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call EventScript_RestorePrevTextColor
# 86 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, PalletTown_ProfessorOaksLab_EventScript_OakBringDexesToDeskNorth
# 87 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, PalletTown_ProfessorOaksLab_EventScript_OakBringDexesToDeskSouth
# 88 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, PalletTown_ProfessorOaksLab_EventScript_OakBringDexesToDeskEast
# 89 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, PalletTown_ProfessorOaksLab_EventScript_OakBringDexesToDeskWest
# 90 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	addobject LOCALID_POKEDEX_1
# 91 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	addobject LOCALID_POKEDEX_2
# 92 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay 30
# 93 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakNowTheseUnitsCanRecordMoreData
# 94 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 95 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	removeobject LOCALID_POKEDEX_1
# 96 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	removeobject LOCALID_POKEDEX_2
# 97 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay 30
# 98 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, PalletTown_ProfessorOaksLab_EventScript_OakBringDexesOverNorth
# 99 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, PalletTown_ProfessorOaksLab_EventScript_OakBringDexesOverSouth
# 100 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, PalletTown_ProfessorOaksLab_EventScript_OakBringDexesOverEast
# 101 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, PalletTown_ProfessorOaksLab_EventScript_OakBringDexesOverWest
# 102 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 103 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	playfanfare MUS_OBTAIN_KEY_ITEM
# 104 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	message PalletTown_ProfessorOaksLab_Text_PlayersPokedexWasUpgraded
# 105 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmessage
# 106 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitfanfare
# 107 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call EventScript_RestorePrevTextColor
# 108 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	special EnableNationalPokedex
# 109 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakMustReallyWorkToFillPokedex
# 110 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalIllCompleteThePokedex
# 111 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 112 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	playbgm MUS_RIVAL_EXIT, 0
# 113 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, PalletTown_ProfessorOaksLab_EventScript_RivalExitNorth
# 114 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, PalletTown_ProfessorOaksLab_EventScript_RivalExit
# 115 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, PalletTown_ProfessorOaksLab_EventScript_RivalExit
# 116 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, PalletTown_ProfessorOaksLab_EventScript_RivalExit
# 117 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	removeobject LOCALID_OAKS_LAB_RIVAL
# 118 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	fadedefaultbgm
# 119 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 8
# 120 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	releaseall
# 121 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 122 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 123 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_NationalDexSceneRivalEnterNorth::
# 124 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setobjectxyperm LOCALID_OAKS_LAB_RIVAL, 5, 10
# 125 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	addobject LOCALID_OAKS_LAB_RIVAL
# 126 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	playbgm MUS_ENCOUNTER_RIVAL, 0
# 127 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PLAYER, PalletTown_ProfessorOaksLab_Movement_WatchRivalEnterNorth
# 128 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalEnter
# 129 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 130 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 131 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 132 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_NationalDexSceneRivalEnterEastWest::
# 133 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setobjectxyperm LOCALID_OAKS_LAB_RIVAL, 6, 10
# 134 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	addobject LOCALID_OAKS_LAB_RIVAL
# 135 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	playbgm MUS_ENCOUNTER_RIVAL, 0
# 136 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_PROF_OAK, Common_Movement_WalkInPlaceFasterDown
# 137 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PLAYER, PalletTown_ProfessorOaksLab_Movement_WatchRivalEnterEastWest
# 138 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalEnter
# 139 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 140 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 141 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 142 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_NationalDexSceneRivalEnterSouth::
# 143 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setobjectxyperm LOCALID_OAKS_LAB_RIVAL, 6, 10
# 144 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	addobject LOCALID_OAKS_LAB_RIVAL
# 145 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	playbgm MUS_ENCOUNTER_RIVAL, 0
# 146 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_PROF_OAK, Common_Movement_WalkInPlaceFasterDown
# 147 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalEnter
# 148 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 149 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 150 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 151 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_PlayerFaceOakNorth::
# 152 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 153 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 154 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 155 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 156 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_PlayerFaceOakWest::
# 157 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 158 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 159 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 160 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 161 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_OakBringDexesToDeskNorth::
# 162 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakBringDexesToDesk
# 163 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 164 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 165 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 166 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_OakBringDexesToDeskSouth::
# 167 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakBringDexesToDeskSouth
# 168 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PLAYER, PalletTown_ProfessorOaksLab_Movement_WatchOakWalkToDesk
# 169 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_RIVAL, PalletTown_ProfessorOaksLab_Movement_WatchOakWalkToDesk
# 170 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement LOCALID_OAKS_LAB_PROF_OAK
# 171 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 172 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 173 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_OakBringDexesToDeskEast::
# 174 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakBringDexesToDesk
# 175 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PLAYER, PalletTown_ProfessorOaksLab_Movement_WatchOakWalkToDeskEast
# 176 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement LOCALID_OAKS_LAB_PROF_OAK
# 177 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 178 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 179 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_OakBringDexesToDeskWest::
# 180 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakBringDexesToDesk
# 181 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 182 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 183 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 184 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_OakBringDexesToDesk::
# 185 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 186 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 187 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_up
# 188 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 189 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_4
# 190 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 191 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 192 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_OakBringDexesToDeskSouth::
# 193 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 194 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 195 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 196 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 197 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_4
# 198 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 199 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 200 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_ChooseStarterScene::
# 201 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	lockall
# 202 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 203 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakEnter
# 204 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 205 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	removeobject LOCALID_OAKS_LAB_PROF_OAK
# 206 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setobjectxyperm LOCALID_OAKS_LAB_PROF_OAK, 6, 3
# 207 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setobjectmovementtype LOCALID_OAKS_LAB_PROF_OAK, MOVEMENT_TYPE_FACE_DOWN
# 208 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	clearflag FLAG_HIDE_OAK_IN_HIS_LAB
# 209 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PLAYER, PalletTown_ProfessorOaksLab_Movement_PlayerEnter
# 210 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 211 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_RIVAL, Common_Movement_WalkInPlaceFasterUp
# 212 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 213 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	clearflag FLAG_DONT_TRANSITION_MUSIC
# 214 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	savebgm MUS_DUMMY
# 215 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	fadedefaultbgm
# 216 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalFedUpWithWaiting
# 217 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 218 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay 60
# 219 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakThreeMonsChooseOne
# 220 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 221 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay 30
# 222 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalReact
# 223 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 224 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalNoFairWhatAboutMe
# 225 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakBePatientRival
# 226 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 2
# 227 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	releaseall
# 228 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 229 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 230 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_OakEnter::
# 231 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 232 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 233 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 234 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 235 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 236 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 237 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 238 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 239 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_PlayerEnter::
# 240 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 241 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 242 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 243 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 244 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 245 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 246 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 247 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 248 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 249 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 250 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalReact::
# 251 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_up
# 252 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_up
# 253 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 254 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 255 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_LeaveStarterSceneTrigger::
# 256 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	lockall
# 257 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 258 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_PROF_OAK, Common_Movement_FaceDown
# 259 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 260 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakHeyDontGoAwayYet
# 261 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 262 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PLAYER, PalletTown_ProfessorOaksLab_Movement_PlayerWalkUp
# 263 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 264 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	releaseall
# 265 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 266 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 267 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_PlayerWalkUp::
# 268 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 269 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 270 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 271 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalBattleTriggerLeft::
# 272 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	lockall
# 273 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_TEMP_2, 1
# 274 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalBattle
# 275 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 276 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 277 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalBattleTriggerMid::
# 278 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	lockall
# 279 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_TEMP_2, 2
# 280 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalBattle
# 281 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 282 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 283 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalBattleTriggerRight::
# 284 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	lockall
# 285 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_TEMP_2, 3
# 286 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalBattle
# 287 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 288 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 289 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalBattle::
# 290 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 291 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	playbgm MUS_ENCOUNTER_RIVAL, 0
# 292 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 293 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 294 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 295 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 296 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalLetsCheckOutMons
# 297 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 298 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_PROF_OAK, Common_Movement_FaceDown
# 299 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 300 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_STARTER_MON, 0, PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleCharmander
# 301 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_STARTER_MON, 1, PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleBulbasaur
# 302 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_STARTER_MON, 2, PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleSquirtle
# 303 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 304 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 305 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
@ The scripts for the rival approaching the player for battle are a bit bloated because
# 306 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
@ both the player and rival can be in 3 different positions, so theres 9 different approaches
# 307 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
@ NOTE: Names below refer to the Rival's mon (e.g. for RivalBattleSquirtle, player has Charmander)
# 308 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 309 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleSquirtle::
# 310 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_TEMP_2, 1, PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleSquirtleLeft
# 311 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_TEMP_2, 2, PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleSquirtleMid
# 312 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_TEMP_2, 3, PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleSquirtleRight
# 313 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 314 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 315 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleSquirtleLeft::
# 316 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalApproachForBattleSquirtleLeft
# 317 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 318 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalBattleSquirtle
# 319 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 320 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 321 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleSquirtleMid::
# 322 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalApproachForBattleSquirtleMid
# 323 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 324 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalBattleSquirtle
# 325 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 326 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 327 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleSquirtleRight::
# 328 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalApproachForBattleSquirtleRight
# 329 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 330 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalBattleSquirtle
# 331 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 332 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 333 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalBattleSquirtle::
# 334 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	trainerbattle_earlyrival TRAINER_RIVAL_OAKS_LAB_SQUIRTLE, RIVAL_BATTLE_TUTORIAL, PalletTown_ProfessorOaksLab_Text_RivalDefeat, Text_RivalVictory
# 335 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_EndRivalBattle
# 336 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 337 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 338 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalApproachForBattleSquirtleLeft::
# 339 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 340 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 341 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 342 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 343 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 344 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 345 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 346 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 347 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalApproachForBattleSquirtleMid::
# 348 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 349 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 350 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 351 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 352 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 353 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 354 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 355 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalApproachForBattleSquirtleRight::
# 356 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 357 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 358 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 359 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 360 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 361 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 362 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleCharmander::
# 363 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_TEMP_2, 1, PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleCharmanderLeft
# 364 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_TEMP_2, 2, PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleCharmanderMid
# 365 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_TEMP_2, 3, PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleCharmanderRight
# 366 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 367 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 368 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleCharmanderLeft::
# 369 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_RIVAL, PalletTown_ProfessorOaksLab_Movement_ApproachForBattleCharmanderLeft
# 370 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 371 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalBattleCharmander
# 372 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 373 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 374 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleCharmanderMid::
# 375 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_RIVAL, PalletTown_ProfessorOaksLab_Movement_ApproachForBattleCharmanderMid
# 376 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 377 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalBattleCharmander
# 378 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 379 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 380 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleCharmanderRight::
# 381 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_RIVAL, PalletTown_ProfessorOaksLab_Movement_ApproachForBattleCharmanderRight
# 382 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 383 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalBattleCharmander
# 384 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 385 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 386 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalBattleCharmander::
# 387 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	trainerbattle_earlyrival TRAINER_RIVAL_OAKS_LAB_CHARMANDER, RIVAL_BATTLE_TUTORIAL, PalletTown_ProfessorOaksLab_Text_RivalDefeat, Text_RivalVictory
# 388 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_EndRivalBattle
# 389 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 390 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 391 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_ApproachForBattleCharmanderLeft::
# 392 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 393 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 394 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 395 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 396 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 397 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 398 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 399 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 400 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 401 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_ApproachForBattleCharmanderMid::
# 402 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 403 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 404 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 405 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 406 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 407 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 408 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 409 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 410 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_ApproachForBattleCharmanderRight::
# 411 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 412 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 413 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 414 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 415 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 416 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 417 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 418 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleBulbasaur::
# 419 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_TEMP_2, 1, PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleBulbasaurLeft
# 420 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_TEMP_2, 2, PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleBulbasaurMid
# 421 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_TEMP_2, 3, PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleBulbasaurRight
# 422 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 423 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 424 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleBulbasaurLeft::
# 425 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalApproachForBattleBulbasaurLeft
# 426 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 427 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalBattleBulbasaur
# 428 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 429 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 430 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleBulbasaurMid::
# 431 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalApproachForBattleBulbasaurMid
# 432 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 433 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalBattleBulbasaur
# 434 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 435 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 436 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleBulbasaurRight::
# 437 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalApproachForBattleBulbasaurRight
# 438 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 439 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalBattleBulbasaur
# 440 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 441 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 442 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalBattleBulbasaur::
# 443 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	trainerbattle_earlyrival TRAINER_RIVAL_OAKS_LAB_BULBASAUR, RIVAL_BATTLE_TUTORIAL, PalletTown_ProfessorOaksLab_Text_RivalDefeat, Text_RivalVictory
# 444 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_EndRivalBattle
# 445 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 446 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 447 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalApproachForBattleBulbasaurLeft::
# 448 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 449 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 450 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 451 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 452 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 453 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 454 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 455 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalApproachForBattleBulbasaurMid::
# 456 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 457 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 458 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 459 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 460 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 461 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 462 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalApproachForBattleBulbasaurRight::
# 463 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 464 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 465 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 466 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 467 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 468 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_EndRivalBattle::
# 469 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	special HealPlayerParty
# 470 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalGoToughenMyMon
# 471 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 472 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	playbgm MUS_RIVAL_EXIT, 0
# 473 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_TEMP_2, 1, PalletTown_ProfessorOaksLab_EventScript_RivalExitAfterBattleLeft
# 474 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_TEMP_2, 2, PalletTown_ProfessorOaksLab_EventScript_RivalExitAfterBattleMid
# 475 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_TEMP_2, 3, PalletTown_ProfessorOaksLab_EventScript_RivalExitAfterBattleRight
# 476 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	removeobject LOCALID_OAKS_LAB_RIVAL
# 477 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	playse SE_EXIT
# 478 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	fadedefaultbgm
# 479 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 4
# 480 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setflag FLAG_BEAT_RIVAL_IN_OAKS_LAB
# 481 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	releaseall
# 482 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 483 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 484 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalExitAfterBattleLeft::
# 485 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalExitAfterBattleLeft
# 486 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PLAYER, PalletTown_ProfessorOaksLab_Movement_PlayerWatchRivalExitAfterBattle
# 487 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement LOCALID_OAKS_LAB_RIVAL
# 488 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 489 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 490 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalExitAfterBattleMid::
# 491 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalExitAfterBattleMid
# 492 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PLAYER, PalletTown_ProfessorOaksLab_Movement_PlayerWatchRivalExitAfterBattle
# 493 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement LOCALID_OAKS_LAB_RIVAL
# 494 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 495 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 496 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalExitAfterBattleRight::
# 497 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalExitAfterBattleRight
# 498 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PLAYER, PalletTown_ProfessorOaksLab_Movement_PlayerWatchRivalExitAfterBattleRight
# 499 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement LOCALID_OAKS_LAB_RIVAL
# 500 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 501 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 502 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalExitAfterBattleLeft::
# 503 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 504 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 505 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 506 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 507 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 508 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 509 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 510 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 511 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 512 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalExitAfterBattleRight::
# 513 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 514 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 515 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 516 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 517 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 518 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 519 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 520 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 521 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 522 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalExitAfterBattleMid::
# 523 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 524 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 525 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 526 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 527 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 528 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 529 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 530 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 531 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 532 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 533 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_PlayerWatchRivalExitAfterBattle::
# 534 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 535 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 536 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_right
# 537 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 538 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_down
# 539 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 540 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 541 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_PlayerWatchRivalExitAfterBattleRight::
# 542 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 543 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 544 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_left
# 545 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 546 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_down
# 547 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 548 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 549 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_Rival::
# 550 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	lock
# 551 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	faceplayer
# 552 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 3, PalletTown_ProfessorOaksLab_EventScript_RivalChoseStarter
# 553 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 2, PalletTown_ProfessorOaksLab_EventScript_RivalWaitingForStarter
# 554 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalGrampsIsntAround
# 555 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 556 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 557 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 558 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalWaitingForStarter::
# 559 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalGoChoosePlayer
# 560 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 561 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 562 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 563 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalChoseStarter::
# 564 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalMyMonLooksTougher
# 565 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 566 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 567 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 568 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_ProfOak::
# 569 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	lock
# 570 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	faceplayer
# 571 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_set SHOWED_OAK_COMPLETE_DEX, PalletTown_ProfessorOaksLab_EventScript_OakJustShownCompleteDex
# 572 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 9, PalletTown_ProfessorOaksLab_EventScript_RatePokedex
# 573 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 8, PalletTown_ProfessorOaksLab_EventScript_MonsAroundWorldWait
# 574 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, PalletTown_ProfessorOaksLab_EventScript_TryStartNationalDexScene
# 575 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_CERULEAN_CITY_RIVAL, 1, PalletTown_ProfessorOaksLab_EventScript_RatePokedex
# 576 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 6, PalletTown_ProfessorOaksLab_EventScript_RatePokedexOrTryGiveBalls
# 577 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_VIRIDIAN_CITY_MART, 1, PalletTown_ProfessorOaksLab_EventScript_ReceiveDexScene
# 578 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 4, PalletTown_ProfessorOaksLab_EventScript_OakBattleMonForItToGrow
# 579 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 3, PalletTown_ProfessorOaksLab_EventScript_OakCanReachNextTownWithMon
# 580 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakWhichOneWillYouChoose
# 581 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 582 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 583 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 584 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_OakJustShownCompleteDex::
# 585 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PokedexRating_Text_ThankYouMadeDreamReality
# 586 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 587 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 588 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 589 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_OakCanReachNextTownWithMon::
# 590 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakCanReachNextTownWithMon
# 591 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 592 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 593 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 594 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_OakBattleMonForItToGrow::
# 595 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakBattleMonForItToGrow
# 596 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 597 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 598 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 599 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_ReceiveDexScene::
# 600 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakHaveSomethingForMe
# 601 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 602 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	playfanfare MUS_OBTAIN_TMHM
# 603 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	message PalletTown_ProfessorOaksLab_Text_DeliveredOaksParcel
# 604 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmessage
# 605 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitfanfare
# 606 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call EventScript_RestorePrevTextColor
# 607 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	removeitem ITEM_OAKS_PARCEL
# 608 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakCustomBallIOrdered
# 609 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	playbgm MUS_ENCOUNTER_RIVAL, 0
# 610 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalGramps
# 611 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 612 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, PalletTown_ProfessorOaksLab_EventScript_DexSceneRivalEnterNorth
# 613 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, PalletTown_ProfessorOaksLab_EventScript_DexSceneRivalEnterSouth
# 614 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, PalletTown_ProfessorOaksLab_EventScript_DexSceneRivalEnterEastWest
# 615 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, PalletTown_ProfessorOaksLab_EventScript_DexSceneRivalEnterEastWest
# 616 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	fadedefaultbgm
# 617 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalWhatDidYouCallMeFor
# 618 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 619 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay 30
# 620 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	playse SE_PIN
# 621 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_PROF_OAK, Common_Movement_ExclamationMark
# 622 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 623 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_PROF_OAK, Common_Movement_Delay48
# 624 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 625 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, PalletTown_ProfessorOaksLab_EventScript_DexSceneOakFacePlayerAndRivalSouth
# 626 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, PalletTown_ProfessorOaksLab_EventScript_DexSceneOakFacePlayerAndRivalEast
# 627 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, PalletTown_ProfessorOaksLab_EventScript_DexSceneOakFacePlayerAndRivalWest
# 628 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, PalletTown_ProfessorOaksLab_EventScript_DexSceneOakFacePlayerAndRivalNorth
# 629 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakHaveRequestForYouTwo
# 630 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 631 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, PalletTown_ProfessorOaksLab_EventScript_DexSceneOakWalkToDeskNorth
# 632 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, PalletTown_ProfessorOaksLab_EventScript_DexSceneOakWalkToDeskSouth
# 633 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, PalletTown_ProfessorOaksLab_EventScript_DexSceneOakWalkToDeskEast
# 634 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, PalletTown_ProfessorOaksLab_EventScript_DexSceneOakWalkToDeskWest
# 635 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakPokedexOnDesk
# 636 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 637 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay 40
# 638 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakTakeTheseWithYou
# 639 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 640 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_PROF_OAK, Common_Movement_WalkInPlaceFasterUp
# 641 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 642 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	removeobject LOCALID_POKEDEX_1
# 643 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay 10
# 644 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	removeobject LOCALID_POKEDEX_2
# 645 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay 25
# 646 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, PalletTown_ProfessorOaksLab_EventScript_OakBringDexesOverNorth
# 647 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, PalletTown_ProfessorOaksLab_EventScript_OakBringDexesOverSouth
# 648 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, PalletTown_ProfessorOaksLab_EventScript_OakBringDexesOverEast
# 649 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, PalletTown_ProfessorOaksLab_EventScript_OakBringDexesOverWest
# 650 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay 10
# 651 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 652 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	playfanfare MUS_OBTAIN_KEY_ITEM
# 653 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	message PalletTown_ProfessorOaksLab_Text_ReceivedPokedexFromOak
# 654 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmessage
# 655 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitfanfare
# 656 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call EventScript_RestorePrevTextColor
# 657 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 658 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	special SetUnlockedPokedexFlags
# 659 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_MAP_SCENE_POKEMON_CENTER_TEALA, 1
# 660 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakCatchMonsForDataTakeThese
# 661 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	giveitem_msg PalletTown_ProfessorOaksLab_Text_ReceivedFivePokeBalls, ITEM_POKE_BALL, 5
# 662 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakExplainCatching
# 663 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	famechecker FAMECHECKER_OAK, 1
# 664 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakCompleteMonGuideWasMyDream
# 665 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalLeaveItToMeGramps
# 666 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, PalletTown_ProfessorOaksLab_EventScript_DexSceneRivalFacePlayerNorth
# 667 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, PalletTown_ProfessorOaksLab_EventScript_DexSceneRivalFacePlayerSouth
# 668 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, PalletTown_ProfessorOaksLab_EventScript_DexSceneRivalFacePlayerEastWest
# 669 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, PalletTown_ProfessorOaksLab_EventScript_DexSceneRivalFacePlayerEastWest
# 670 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalTellSisNotToGiveYouMap
# 671 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 672 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	playbgm MUS_RIVAL_EXIT, 0
# 673 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, PalletTown_ProfessorOaksLab_EventScript_RivalExitNorth
# 674 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, PalletTown_ProfessorOaksLab_EventScript_RivalExit
# 675 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, PalletTown_ProfessorOaksLab_EventScript_RivalExit
# 676 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, PalletTown_ProfessorOaksLab_EventScript_RivalExit
# 677 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	removeobject LOCALID_OAKS_LAB_RIVAL
# 678 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	fadedefaultbgm
# 679 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 6
# 680 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_MAP_SCENE_VIRIDIAN_CITY_MART, 2
# 681 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 1
# 682 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 1
# 683 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_MAP_SCENE_ROUTE22, 1
# 684 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 685 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 686 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 687 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_OakBringDexesOverNorth::
# 688 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakBringDexesOver
# 689 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 690 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 691 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 692 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_OakBringDexesOverSouth::
# 693 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakBringDexesOverSouth
# 694 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 695 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 696 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 697 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_OakBringDexesOverEast::
# 698 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakBringDexesOver
# 699 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PLAYER, PalletTown_ProfessorOaksLab_Movement_PlayerFaceOakForDexEast
# 700 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 701 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 702 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 703 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_OakBringDexesOverWest::
# 704 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakBringDexesOver
# 705 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 706 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 707 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 708 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_PlayerFaceOakForDexEast::
# 709 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 710 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 711 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_right
# 712 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 713 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 714 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_OakBringDexesOver::
# 715 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 716 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 717 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 718 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 719 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_OakBringDexesOverSouth::
# 720 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 721 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 722 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 723 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 724 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DexSceneOakWalkToDeskNorth::
# 725 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakWalkToDesk
# 726 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 727 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 728 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 729 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DexSceneOakWalkToDeskSouth::
# 730 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakWalkToDeskSouth
# 731 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PLAYER, PalletTown_ProfessorOaksLab_Movement_WatchOakWalkToDesk
# 732 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_RIVAL, PalletTown_ProfessorOaksLab_Movement_WatchOakWalkToDesk
# 733 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement LOCALID_OAKS_LAB_PROF_OAK
# 734 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 735 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 736 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DexSceneOakWalkToDeskEast::
# 737 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakWalkToDesk
# 738 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PLAYER, PalletTown_ProfessorOaksLab_Movement_WatchOakWalkToDeskEast
# 739 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement LOCALID_OAKS_LAB_PROF_OAK
# 740 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 741 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 742 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DexSceneOakWalkToDeskWest::
# 743 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakWalkToDesk
# 744 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 745 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 746 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 747 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_WatchOakWalkToDeskEast::
# 748 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 749 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 750 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_up
# 751 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 752 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 753 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_WatchOakWalkToDesk::
# 754 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 755 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 756 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_left
# 757 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 758 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 759 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_OakWalkToDesk::
# 760 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 761 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 762 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 763 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_down
# 764 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 765 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 766 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_OakWalkToDeskSouth::
# 767 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 768 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 769 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 770 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 771 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_right
# 772 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 773 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 774 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RatePokedexOrTryGiveBalls::
# 775 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_0x8004, 0
# 776 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	specialvar VAR_RESULT, GetPokedexCount
# 777 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	copyvar VAR_0x8008, VAR_0x8005
# 778 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	copyvar VAR_0x8009, VAR_0x8006
# 779 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_0x8008
# 780 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	buffernumberstring STR_VAR_2, VAR_0x8009
# 781 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_0x8009, 1, PalletTown_ProfessorOaksLab_EventScript_CheckIfPlayerNeedsBalls  @ Player only has starter
# 782 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RatePokedex
# 783 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 784 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 785 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RatePokedex::
# 786 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call PokedexRating_EventScript_RateInPerson
# 787 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_set FLAG_OAK_SAW_DEX_COMPLETION, PalletTown_ProfessorOaksLab_EventScript_DexCompleted
# 788 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 789 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 790 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 791 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DexCompleted::
# 792 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 793 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay 40
# 794 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	message PokedexRating_Text_Wroooaaarrr
# 795 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmessage
# 796 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, PalletTown_ProfessorOaksLab_EventScript_OakExcitedNorth
# 797 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, PalletTown_ProfessorOaksLab_EventScript_OakExcitedSouth
# 798 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, PalletTown_ProfessorOaksLab_EventScript_OakExcitedEast
# 799 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, PalletTown_ProfessorOaksLab_EventScript_OakExcitedWest
# 800 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_PROF_OAK, Common_Movement_FacePlayer
# 801 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 802 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 803 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay 70
# 804 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PokedexRating_Text_ThankYouMadeDreamReality
# 805 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setflag SHOWED_OAK_COMPLETE_DEX
# 806 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 807 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 808 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 809 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_OakExcitedNorth::
# 810 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakExcitedNorth
# 811 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 812 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 813 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 814 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_OakExcitedSouth::
# 815 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakExcitedSouth
# 816 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 817 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 818 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 819 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_OakExcitedEast::
# 820 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakExcitedEast
# 821 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 822 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 823 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 824 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_OakExcitedWest::
# 825 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakExcitedWest
# 826 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 827 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 828 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 829 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_OakExcitedNorth::
# 830 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_down
# 831 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_fast_down
# 832 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_down
# 833 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_down
# 834 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_fast_down
# 835 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_down
# 836 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 837 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 838 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_OakExcitedSouth::
# 839 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_up
# 840 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_fast_up
# 841 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_up
# 842 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_up
# 843 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_fast_up
# 844 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_up
# 845 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 846 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 847 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_OakExcitedEast::
# 848 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_left
# 849 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_fast_left
# 850 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_left
# 851 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_left
# 852 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_fast_left
# 853 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_left
# 854 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 855 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 856 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_OakExcitedWest::
# 857 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_right
# 858 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_fast_right
# 859 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_right
# 860 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_right
# 861 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_fast_right
# 862 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_right
# 863 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 864 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 865 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
@ Unused
# 866 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_Search:
# 867 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 868 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_down
# 869 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 870 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_right
# 871 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 872 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_up
# 873 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 874 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_left
# 875 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 876 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_down
# 877 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 878 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 879 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 880 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_up
# 881 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 882 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_left
# 883 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 884 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_down
# 885 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 886 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_right
# 887 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 888 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_up
# 889 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 890 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 891 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 892 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 893 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
@ Unused
# 894 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_VerticalPacing:
# 895 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 896 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 897 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 898 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_down
# 899 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 900 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 901 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 902 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 903 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 904 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 905 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_TryStartNationalDexScene::
# 906 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call PokedexRating_EventScript_RateInPerson
# 907 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 908 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_lt VAR_0x8009, 60, PalletTown_ProfessorOaksLab_EventScript_DontStartNationalDexScene
# 909 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_unset FLAG_WORLD_MAP_ONE_ISLAND, PalletTown_ProfessorOaksLab_EventScript_DontStartNationalDexScene
# 910 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay 30
# 911 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakFavorToAskYouPlayer
# 912 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_NationalDexScene
# 913 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 914 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 915 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DontStartNationalDexScene::
# 916 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 917 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 918 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 919 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_CheckIfPlayerNeedsBalls::
# 920 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 921 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	special QuestLog_CutRecording
# 922 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_set FLAG_OAK_SKIP_22_RIVAL_CHECK, PalletTown_ProfessorOaksLab_EventScript_MonsAroundWorldWait
# 923 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_set FLAG_GOT_POKEBALLS_FROM_OAK_AFTER_22_RIVAL, PalletTown_ProfessorOaksLab_EventScript_PlayerAlreadyGotBalls
# 924 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	checkitem ITEM_POKE_BALL
# 925 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, PalletTown_ProfessorOaksLab_EventScript_PlayerOutOfBalls
# 926 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_MonsAroundWorldWait
# 927 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 928 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 929 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_PlayerOutOfBalls::
# 930 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_ROUTE22, 2, PalletTown_ProfessorOaksLab_EventScript_GivePlayerMoreBalls
# 931 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_MonsAroundWorldWait
# 932 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 933 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 934 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_GivePlayerMoreBalls::
# 935 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakAddedNothingToPokedex
# 936 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	giveitem_msg PalletTown_ProfessorOaksLab_Text_ReceivedFivePokeBalls, ITEM_POKE_BALL, 5
# 937 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setflag FLAG_GOT_POKEBALLS_FROM_OAK_AFTER_22_RIVAL
# 938 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 939 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 940 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 941 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_MonsAroundWorldWait::
# 942 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakMonsAroundWorldWait
# 943 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 944 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 945 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 946 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_PlayerAlreadyGotBalls::
# 947 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakComeSeeMeSometime
# 948 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 949 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 950 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 951 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DexSceneRivalEnterNorth::
# 952 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setobjectxyperm LOCALID_OAKS_LAB_RIVAL, 5, 10
# 953 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	addobject LOCALID_OAKS_LAB_RIVAL
# 954 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PLAYER, PalletTown_ProfessorOaksLab_Movement_WatchRivalEnterNorth
# 955 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalEnter
# 956 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 957 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 958 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 959 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DexSceneRivalEnterEastWest::
# 960 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setobjectxyperm LOCALID_OAKS_LAB_RIVAL, 6, 10
# 961 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	addobject LOCALID_OAKS_LAB_RIVAL
# 962 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_PROF_OAK, Common_Movement_WalkInPlaceFasterDown
# 963 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PLAYER, PalletTown_ProfessorOaksLab_Movement_WatchRivalEnterEastWest
# 964 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalEnter
# 965 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 966 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 967 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 968 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DexSceneRivalEnterSouth::
# 969 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setobjectxyperm LOCALID_OAKS_LAB_RIVAL, 6, 10
# 970 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	addobject LOCALID_OAKS_LAB_RIVAL
# 971 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_PROF_OAK, Common_Movement_WalkInPlaceFasterDown
# 972 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalEnter
# 973 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 974 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 975 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 976 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DexSceneOakFacePlayerAndRivalSouth::
# 977 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_PROF_OAK, Common_Movement_FacePlayer
# 978 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 979 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay 15
# 980 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_PROF_OAK, Common_Movement_WalkInPlaceFasterDown
# 981 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 982 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 983 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 984 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DexSceneOakFacePlayerAndRivalWest::
# 985 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_PROF_OAK, Common_Movement_FacePlayer
# 986 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 987 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay 15
# 988 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 989 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_PROF_OAK, Common_Movement_WalkInPlaceFasterDown
# 990 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 991 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 992 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 993 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DexSceneOakFacePlayerAndRivalEast::
# 994 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_PROF_OAK, Common_Movement_FacePlayer
# 995 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 996 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay 15
# 997 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 998 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_PROF_OAK, Common_Movement_WalkInPlaceFasterDown
# 999 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 1000 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 1001 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1002 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DexSceneRivalFacePlayerNorth::
# 1003 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_RIVAL, Common_Movement_FacePlayer
# 1004 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 1005 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 1006 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 1007 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1008 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DexSceneRivalFacePlayerSouth::
# 1009 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_RIVAL, Common_Movement_WalkInPlaceFasterUp
# 1010 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 1011 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 1012 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 1013 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1014 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DexSceneRivalFacePlayerEastWest::
# 1015 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_RIVAL, Common_Movement_FacePlayer
# 1016 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 1017 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 1018 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 1019 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1020 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalExitNorth::
# 1021 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PLAYER, PalletTown_ProfessorOaksLab_Movement_WatchRivalEnterEastWest
# 1022 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalExit
# 1023 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 1024 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 1025 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1026 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalExit::
# 1027 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalExit
# 1028 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 1029 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 1030 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1031 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DexSceneOakFacePlayerAndRivalNorth::
# 1032 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 1033 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 1034 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 1035 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1036 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_WatchRivalEnterEastWest::
# 1037 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_4
# 1038 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_down
# 1039 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 1040 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1041 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_WatchRivalEnterNorth::
# 1042 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_down
# 1043 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 1044 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 1045 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 1046 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 1047 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 1048 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 1049 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_left
# 1050 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 1051 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1052 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalEnter::
# 1053 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 1054 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 1055 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 1056 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 1057 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 1058 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 1059 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 1060 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1061 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalExit::
# 1062 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 1063 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 1064 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 1065 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 1066 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 1067 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 1068 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 1069 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1070 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_BulbasaurBall::
# 1071 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	lock
# 1072 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	faceplayer
# 1073 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar PLAYER_STARTER_NUM, 0
# 1074 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar PLAYER_STARTER_SPECIES, SPECIES_BULBASAUR
# 1075 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar RIVAL_STARTER_SPECIES, SPECIES_CHARMANDER
# 1076 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar RIVAL_STARTER_ID, LOCALID_CHARMANDER_BALL
# 1077 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 3, PalletTown_ProfessorOaksLab_EventScript_LastPokeBall
# 1078 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 2, PalletTown_ProfessorOaksLab_EventScript_ConfirmStarterChoice
# 1079 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_ThoseArePokeBalls
# 1080 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 1081 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1082 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1083 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_ConfirmStarterChoice::
# 1084 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_PROF_OAK, Common_Movement_FaceRight
# 1085 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 1086 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	showmonpic PLAYER_STARTER_SPECIES, 10, 3
# 1087 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 1088 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq PLAYER_STARTER_NUM, 0, PalletTown_ProfessorOaksLab_EventScript_ConfirmBulbasaur
# 1089 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq PLAYER_STARTER_NUM, 1, PalletTown_ProfessorOaksLab_EventScript_ConfirmSquirtle
# 1090 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq PLAYER_STARTER_NUM, 2, PalletTown_ProfessorOaksLab_EventScript_ConfirmCharmander
# 1091 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1092 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1093 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_ConfirmBulbasaur::
# 1094 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakChoosingBulbasaur, MSGBOX_YESNO
# 1095 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PalletTown_ProfessorOaksLab_EventScript_ChoseStarter
# 1096 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PalletTown_ProfessorOaksLab_EventScript_DeclinedStarter
# 1097 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1098 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1099 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_ConfirmSquirtle::
# 1100 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakChoosingSquirtle, MSGBOX_YESNO
# 1101 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PalletTown_ProfessorOaksLab_EventScript_ChoseStarter
# 1102 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PalletTown_ProfessorOaksLab_EventScript_DeclinedStarter
# 1103 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1104 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1105 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_ConfirmCharmander::
# 1106 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakChoosingCharmander, MSGBOX_YESNO
# 1107 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PalletTown_ProfessorOaksLab_EventScript_ChoseStarter
# 1108 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PalletTown_ProfessorOaksLab_EventScript_DeclinedStarter
# 1109 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1110 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1111 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DeclinedStarter::
# 1112 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	hidemonpic
# 1113 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 1114 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1115 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1116 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_ChoseStarter::
# 1117 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	hidemonpic
# 1118 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	removeobject VAR_LAST_TALKED
# 1119 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakThisMonIsEnergetic
# 1120 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call EventScript_RestorePrevTextColor
# 1121 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 1122 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setflag FLAG_PALLET_LADY_NOT_BLOCKING_SIGN
# 1123 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	givemon PLAYER_STARTER_SPECIES, 5
# 1124 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	copyvar VAR_STARTER_MON, PLAYER_STARTER_NUM
# 1125 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	bufferspeciesname STR_VAR_1, PLAYER_STARTER_SPECIES
# 1126 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	message PalletTown_ProfessorOaksLab_Text_ReceivedMonFromOak
# 1127 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmessage
# 1128 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	playfanfare MUS_OBTAIN_KEY_ITEM
# 1129 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitfanfare
# 1130 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 1131 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_RESULT, YES, EventScript_GiveNicknameToStarter
# 1132 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PalletTown_ProfessorOaksLab_EventScript_RivalPicksStarter
# 1133 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1134 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1135 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
EventScript_GiveNicknameToStarter::
# 1136 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_0x8004, 0
# 1137 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call EventScript_ChangePokemonNickname
# 1138 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalPicksStarter
# 1139 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1140 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1141 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalPicksStarter::
# 1142 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 1143 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq PLAYER_STARTER_NUM, 0, PalletTown_ProfessorOaksLab_EventScript_RivalWalksToCharmander
# 1144 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq PLAYER_STARTER_NUM, 1, PalletTown_ProfessorOaksLab_EventScript_RivalWalksToBulbasaur
# 1145 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq PLAYER_STARTER_NUM, 2, PalletTown_ProfessorOaksLab_EventScript_RivalWalksToSquirtle
# 1146 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1147 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1148 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalWalksToCharmander::
# 1149 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalWalksToCharmander
# 1150 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 1151 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalTakesStarter
# 1152 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1153 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1154 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalWalksToSquirtle::
# 1155 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalWalksToSquirtle
# 1156 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 1157 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalTakesStarter
# 1158 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1159 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1160 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalWalksToBulbasaur::
# 1161 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_OAKS_LAB_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalWalksToBulbasaur
# 1162 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 1163 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalTakesStarter
# 1164 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1165 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1166 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalTakesStarter::
# 1167 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 1168 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalIllTakeThisOneThen
# 1169 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	removeobject RIVAL_STARTER_ID
# 1170 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 1171 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	bufferspeciesname STR_VAR_1, RIVAL_STARTER_SPECIES
# 1172 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	message PalletTown_ProfessorOaksLab_Text_RivalReceivedMonFromOak
# 1173 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmessage
# 1174 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	playfanfare MUS_OBTAIN_KEY_ITEM
# 1175 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitfanfare
# 1176 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 3
# 1177 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_set FLAG_OPENED_START_MENU, PalletTown_ProfessorOaksLab_EventScript_ReadyEndSignLadyScene
# 1178 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 1179 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1180 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1181 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_ReadyEndSignLadyScene::
# 1182 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1
# 1183 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 1184 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1185 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalWalksToCharmander::
# 1186 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 1187 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 1188 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 1189 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 1190 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 1191 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 1192 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 1193 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 1194 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 1195 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1196 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalWalksToSquirtle::
# 1197 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 1198 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 1199 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 1200 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 1201 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 1202 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_up
# 1203 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 1204 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1205 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalWalksToBulbasaur::
# 1206 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 1207 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 1208 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 1209 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 1210 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_up
# 1211 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 1212 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1213 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_SquirtleBall::
# 1214 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	lock
# 1215 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	faceplayer
# 1216 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar PLAYER_STARTER_NUM, 1
# 1217 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar PLAYER_STARTER_SPECIES, SPECIES_SQUIRTLE
# 1218 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar RIVAL_STARTER_SPECIES, SPECIES_BULBASAUR
# 1219 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar RIVAL_STARTER_ID, LOCALID_BULBASAUR_BALL
# 1220 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 3, PalletTown_ProfessorOaksLab_EventScript_LastPokeBall
# 1221 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 2, PalletTown_ProfessorOaksLab_EventScript_ConfirmStarterChoice
# 1222 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_ThoseArePokeBalls
# 1223 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 1224 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1225 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1226 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_CharmanderBall::
# 1227 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	lock
# 1228 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	faceplayer
# 1229 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar PLAYER_STARTER_NUM, 2
# 1230 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar PLAYER_STARTER_SPECIES, SPECIES_CHARMANDER
# 1231 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar RIVAL_STARTER_SPECIES, SPECIES_SQUIRTLE
# 1232 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar RIVAL_STARTER_ID, LOCALID_SQUIRTLE_BALL
# 1233 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 3, PalletTown_ProfessorOaksLab_EventScript_LastPokeBall
# 1234 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 2, PalletTown_ProfessorOaksLab_EventScript_ConfirmStarterChoice
# 1235 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_ThoseArePokeBalls
# 1236 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 1237 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1238 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1239 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_LastPokeBall::
# 1240 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OaksLastMon
# 1241 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 1242 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1243 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1244 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_Aide1::
# 1245 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	lock
# 1246 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	faceplayer
# 1247 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, PalletTown_ProfessorOaksLab_EventScript_Aide1GameClear
# 1248 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_StudyAsOaksAide
# 1249 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 1250 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1251 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1252 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_Aide1GameClear::
# 1253 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	famechecker FAMECHECKER_OAK, 5
# 1254 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakIsGoingToHaveRadioShow
# 1255 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 1256 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1257 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1258 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_Aide2::
# 1259 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	lock
# 1260 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	faceplayer
# 1261 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, PalletTown_ProfessorOaksLab_EventScript_Aide2GameClear
# 1262 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_StudyAsOaksAide
# 1263 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 1264 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1265 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1266 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_Aide2GameClear::
# 1267 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	famechecker FAMECHECKER_DAISY, 0
# 1268 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_DaisyWillGroomMons
# 1269 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 1270 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1271 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1272 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_Aide3::
# 1273 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	lock
# 1274 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	faceplayer
# 1275 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	famechecker FAMECHECKER_OAK, 2
# 1276 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakIsAuthorityOnMons
# 1277 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 1278 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1279 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1280 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_Pokedex::
# 1281 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_BlankEncyclopedia, MSGBOX_NPC
# 1282 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1283 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1284 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_Computer::
# 1285 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_EmailMessage, MSGBOX_SIGN
# 1286 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1287 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1288 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_LeftSign::
# 1289 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_PressStartToOpenMenu, MSGBOX_SIGN
# 1290 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1291 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1292 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RightSign::
# 1293 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	lockall
# 1294 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 6, PalletTown_ProfessorOaksLab_EventScript_RightSignAlt
# 1295 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_SaveOptionInMenu
# 1296 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	releaseall
# 1297 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1298 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1299 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RightSignAlt::
# 1300 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_AllMonTypesHaveStrongAndWeakPoints
# 1301 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	releaseall
# 1302 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
