# 1 "data/maps/FourIsland/scripts.pory"

# 2 "data/maps/FourIsland/scripts.pory"
FourIsland_MapScripts::
# 3 "data/maps/FourIsland/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, FourIsland_OnTransition
# 4 "data/maps/FourIsland/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FourIsland_OnFrame
# 5 "data/maps/FourIsland/scripts.pory"
	.byte 0
# 6 "data/maps/FourIsland/scripts.pory"

# 7 "data/maps/FourIsland/scripts.pory"
FourIsland_OnTransition::
# 8 "data/maps/FourIsland/scripts.pory"
	setworldmapflag FLAG_WORLD_MAP_FOUR_ISLAND
# 9 "data/maps/FourIsland/scripts.pory"
	call_if_eq VAR_MAP_SCENE_FOUR_ISLAND, 0, FourIsland_EventScript_ShowRival
# 10 "data/maps/FourIsland/scripts.pory"
	call FourIsland_EventScript_TrySetDayCareManPos
# 11 "data/maps/FourIsland/scripts.pory"
	end
# 12 "data/maps/FourIsland/scripts.pory"

# 13 "data/maps/FourIsland/scripts.pory"
FourIsland_EventScript_ShowRival::
# 14 "data/maps/FourIsland/scripts.pory"
	clearflag FLAG_HIDE_FOUR_ISLAND_RIVAL
# 15 "data/maps/FourIsland/scripts.pory"
	return
# 16 "data/maps/FourIsland/scripts.pory"

# 17 "data/maps/FourIsland/scripts.pory"
FourIsland_EventScript_TrySetDayCareManPos::
# 18 "data/maps/FourIsland/scripts.pory"
	goto_if_unset FLAG_PENDING_DAYCARE_EGG, FourIsland_EventScript_EndSetDayCareManPos
# 19 "data/maps/FourIsland/scripts.pory"
	setobjectxyperm LOCALID_FOUR_ISLAND_DAYCARE_MAN, 16, 14
# 20 "data/maps/FourIsland/scripts.pory"
FourIsland_EventScript_EndSetDayCareManPos::
# 21 "data/maps/FourIsland/scripts.pory"
	return
# 22 "data/maps/FourIsland/scripts.pory"

# 23 "data/maps/FourIsland/scripts.pory"
FourIsland_OnFrame::
# 24 "data/maps/FourIsland/scripts.pory"
	map_script_2 VAR_MAP_SCENE_FOUR_ISLAND, 0, FourIsland_EventScript_RivalScene
# 25 "data/maps/FourIsland/scripts.pory"
	.2byte 0
# 26 "data/maps/FourIsland/scripts.pory"

# 27 "data/maps/FourIsland/scripts.pory"
FourIsland_EventScript_RivalScene::
# 28 "data/maps/FourIsland/scripts.pory"
	lockall
# 29 "data/maps/FourIsland/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 30 "data/maps/FourIsland/scripts.pory"
	applymovement LOCALID_FOUR_ISLAND_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 31 "data/maps/FourIsland/scripts.pory"
	waitmovement 0
# 32 "data/maps/FourIsland/scripts.pory"
	playbgm MUS_ENCOUNTER_RIVAL, 0
# 33 "data/maps/FourIsland/scripts.pory"
	applymovement LOCALID_FOUR_ISLAND_RIVAL, Common_Movement_ExclamationMark
# 34 "data/maps/FourIsland/scripts.pory"
	waitmovement 0
# 35 "data/maps/FourIsland/scripts.pory"
	applymovement LOCALID_FOUR_ISLAND_RIVAL, Common_Movement_Delay48
# 36 "data/maps/FourIsland/scripts.pory"
	waitmovement 0
# 37 "data/maps/FourIsland/scripts.pory"
	delay 25
# 38 "data/maps/FourIsland/scripts.pory"
	applymovement LOCALID_FOUR_ISLAND_RIVAL, FourIsland_Movement_RivalApproach
# 39 "data/maps/FourIsland/scripts.pory"
	waitmovement 0
# 40 "data/maps/FourIsland/scripts.pory"
	msgbox FourIsland_Text_RivalAlreadyGotEggBeSmellingYa
# 41 "data/maps/FourIsland/scripts.pory"
	closemessage
# 42 "data/maps/FourIsland/scripts.pory"
	applymovement LOCALID_PLAYER, FourIsland_Movement_PlayerWatchRivalExit
# 43 "data/maps/FourIsland/scripts.pory"
	applymovement LOCALID_FOUR_ISLAND_RIVAL, FourIsland_Movement_RivalExit
# 44 "data/maps/FourIsland/scripts.pory"
	waitmovement 0
# 45 "data/maps/FourIsland/scripts.pory"
	fadedefaultbgm
# 46 "data/maps/FourIsland/scripts.pory"
	playse SE_EXIT
# 47 "data/maps/FourIsland/scripts.pory"
	delay 35
# 48 "data/maps/FourIsland/scripts.pory"
	removeobject LOCALID_FOUR_ISLAND_RIVAL
# 49 "data/maps/FourIsland/scripts.pory"
	setvar VAR_MAP_SCENE_FOUR_ISLAND, 1
# 50 "data/maps/FourIsland/scripts.pory"
	releaseall
# 51 "data/maps/FourIsland/scripts.pory"
	end
# 52 "data/maps/FourIsland/scripts.pory"

# 53 "data/maps/FourIsland/scripts.pory"
FourIsland_Movement_RivalApproach::
# 54 "data/maps/FourIsland/scripts.pory"
	walk_right
# 55 "data/maps/FourIsland/scripts.pory"
	walk_right
# 56 "data/maps/FourIsland/scripts.pory"
	walk_down
# 57 "data/maps/FourIsland/scripts.pory"
	walk_down
# 58 "data/maps/FourIsland/scripts.pory"
	step_end
# 59 "data/maps/FourIsland/scripts.pory"

# 60 "data/maps/FourIsland/scripts.pory"
FourIsland_Movement_RivalExit::
# 61 "data/maps/FourIsland/scripts.pory"
	delay_16
# 62 "data/maps/FourIsland/scripts.pory"
	delay_4
# 63 "data/maps/FourIsland/scripts.pory"
	walk_down
# 64 "data/maps/FourIsland/scripts.pory"
	step_end
# 65 "data/maps/FourIsland/scripts.pory"

# 66 "data/maps/FourIsland/scripts.pory"
FourIsland_Movement_PlayerWatchRivalExit::
# 67 "data/maps/FourIsland/scripts.pory"
	walk_left
# 68 "data/maps/FourIsland/scripts.pory"
	walk_in_place_faster_right
# 69 "data/maps/FourIsland/scripts.pory"
	step_end
# 70 "data/maps/FourIsland/scripts.pory"

# 71 "data/maps/FourIsland/scripts.pory"
FourIsland_EventScript_DaycareMan::
# 72 "data/maps/FourIsland/scripts.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 73 "data/maps/FourIsland/scripts.pory"
	special QuestLog_CutRecording
# 74 "data/maps/FourIsland/scripts.pory"
	lock
# 75 "data/maps/FourIsland/scripts.pory"
	faceplayer
# 76 "data/maps/FourIsland/scripts.pory"
	special GetDaycareMonNicknames
# 77 "data/maps/FourIsland/scripts.pory"
	specialvar VAR_RESULT, GetDaycareState
# 78 "data/maps/FourIsland/scripts.pory"
	goto_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, FourIsland_EventScript_DaycareEggWaiting
# 79 "data/maps/FourIsland/scripts.pory"
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, FourIsland_EventScript_CheckOnOneMon
# 80 "data/maps/FourIsland/scripts.pory"
	goto_if_eq VAR_RESULT, DAYCARE_TWO_MONS, FourIsland_EventScript_CheckOnTwoMons
# 81 "data/maps/FourIsland/scripts.pory"
	msgbox DayCare_Text_ImDaycareManSpeakToMyWife
# 82 "data/maps/FourIsland/scripts.pory"
	release
# 83 "data/maps/FourIsland/scripts.pory"
	end
# 84 "data/maps/FourIsland/scripts.pory"

# 85 "data/maps/FourIsland/scripts.pory"
FourIsland_EventScript_DaycareEggWaiting::
# 86 "data/maps/FourIsland/scripts.pory"
	msgbox DayCare_Text_DoYouWantEgg, MSGBOX_YESNO
# 87 "data/maps/FourIsland/scripts.pory"
	goto_if_eq VAR_RESULT, YES, FourIsland_EventScript_DaycareAcceptEgg
# 88 "data/maps/FourIsland/scripts.pory"
	msgbox DayCare_Text_IWillKeepDoYouWantIt, MSGBOX_YESNO
# 89 "data/maps/FourIsland/scripts.pory"
	goto_if_eq VAR_RESULT, YES, FourIsland_EventScript_DaycareAcceptEgg
# 90 "data/maps/FourIsland/scripts.pory"
	msgbox DayCare_Text_IllKeepIt
# 91 "data/maps/FourIsland/scripts.pory"
	clearflag FLAG_PENDING_DAYCARE_EGG
# 92 "data/maps/FourIsland/scripts.pory"
	special RejectEggFromDayCare
# 93 "data/maps/FourIsland/scripts.pory"
	release
# 94 "data/maps/FourIsland/scripts.pory"
	end
# 95 "data/maps/FourIsland/scripts.pory"

# 96 "data/maps/FourIsland/scripts.pory"
FourIsland_EventScript_DaycareAcceptEgg::
# 97 "data/maps/FourIsland/scripts.pory"
	specialvar VAR_RESULT, CalculatePlayerPartyCount
# 98 "data/maps/FourIsland/scripts.pory"
	goto_if_ne VAR_RESULT, PARTY_SIZE, FourIsland_EventScript_DaycareReceivedEgg
# 99 "data/maps/FourIsland/scripts.pory"
	msgbox DayCare_Text_YouHaveNoRoomForIt
# 100 "data/maps/FourIsland/scripts.pory"
	release
# 101 "data/maps/FourIsland/scripts.pory"
	end
# 102 "data/maps/FourIsland/scripts.pory"

# 103 "data/maps/FourIsland/scripts.pory"
FourIsland_EventScript_DaycareReceivedEgg::
# 104 "data/maps/FourIsland/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 105 "data/maps/FourIsland/scripts.pory"
	message DayCare_Text_ReceivedEgg
# 106 "data/maps/FourIsland/scripts.pory"
	call EventScript_RestorePrevTextColor
# 107 "data/maps/FourIsland/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 108 "data/maps/FourIsland/scripts.pory"
	waitfanfare
# 109 "data/maps/FourIsland/scripts.pory"
	waitbuttonpress
# 110 "data/maps/FourIsland/scripts.pory"
	msgbox DayCare_Text_TakeGoodCareOfIt
# 111 "data/maps/FourIsland/scripts.pory"
	special GiveEggFromDaycare
# 112 "data/maps/FourIsland/scripts.pory"
	clearflag FLAG_PENDING_DAYCARE_EGG
# 113 "data/maps/FourIsland/scripts.pory"
	release
# 114 "data/maps/FourIsland/scripts.pory"
	end
# 115 "data/maps/FourIsland/scripts.pory"

# 116 "data/maps/FourIsland/scripts.pory"
FourIsland_EventScript_CheckOnOneMon::
# 117 "data/maps/FourIsland/scripts.pory"
	special GetDaycareMonNicknames
# 118 "data/maps/FourIsland/scripts.pory"
	msgbox DayCare_Text_YourMonIsDoingFine
# 119 "data/maps/FourIsland/scripts.pory"
	release
# 120 "data/maps/FourIsland/scripts.pory"
	end
# 121 "data/maps/FourIsland/scripts.pory"

# 122 "data/maps/FourIsland/scripts.pory"
FourIsland_EventScript_CheckOnTwoMons::
# 123 "data/maps/FourIsland/scripts.pory"
	special GetDaycareMonNicknames
# 124 "data/maps/FourIsland/scripts.pory"
	msgbox DayCare_Text_YourMonsAreDoingFine
# 125 "data/maps/FourIsland/scripts.pory"
	special SetDaycareCompatibilityString
# 126 "data/maps/FourIsland/scripts.pory"
	special ShowFieldMessageStringVar4
# 127 "data/maps/FourIsland/scripts.pory"
	waitmessage
# 128 "data/maps/FourIsland/scripts.pory"
	waitbuttonpress
# 129 "data/maps/FourIsland/scripts.pory"
	release
# 130 "data/maps/FourIsland/scripts.pory"
	end
# 131 "data/maps/FourIsland/scripts.pory"

# 132 "data/maps/FourIsland/scripts.pory"
FourIsland_EventScript_OldWoman::
# 133 "data/maps/FourIsland/scripts.pory"
	lock
# 134 "data/maps/FourIsland/scripts.pory"
	faceplayer
# 135 "data/maps/FourIsland/scripts.pory"
	goto_if_set FLAG_SYS_CAN_LINK_WITH_RS, FourIsland_EventScript_OldWomanLoreleiLeft
# 136 "data/maps/FourIsland/scripts.pory"
	msgbox FourIsland_Text_LoreleiHasReturned
# 137 "data/maps/FourIsland/scripts.pory"
	release
# 138 "data/maps/FourIsland/scripts.pory"
	end
# 139 "data/maps/FourIsland/scripts.pory"

# 140 "data/maps/FourIsland/scripts.pory"
FourIsland_EventScript_OldWomanLoreleiLeft::
# 141 "data/maps/FourIsland/scripts.pory"
	famechecker FAMECHECKER_LORELEI, 5
# 142 "data/maps/FourIsland/scripts.pory"
	msgbox FourIsland_Text_LoreleiMetLaprasAsChild
# 143 "data/maps/FourIsland/scripts.pory"
	release
# 144 "data/maps/FourIsland/scripts.pory"
	end
# 145 "data/maps/FourIsland/scripts.pory"

# 146 "data/maps/FourIsland/scripts.pory"
FourIsland_EventScript_LittleGirl::
# 147 "data/maps/FourIsland/scripts.pory"
	lock
# 148 "data/maps/FourIsland/scripts.pory"
	faceplayer
# 149 "data/maps/FourIsland/scripts.pory"
	famechecker FAMECHECKER_LORELEI, 4
# 150 "data/maps/FourIsland/scripts.pory"
	msgbox FourIsland_Text_LoreleiHasLotsOfStuffedDolls
# 151 "data/maps/FourIsland/scripts.pory"
	release
# 152 "data/maps/FourIsland/scripts.pory"
	end
# 153 "data/maps/FourIsland/scripts.pory"

# 154 "data/maps/FourIsland/scripts.pory"
FourIsland_EventScript_FatMan::
# 155 "data/maps/FourIsland/scripts.pory"
	msgbox FourIsland_Text_MadeSlushieUsingIcefallCaveIce, MSGBOX_NPC
# 156 "data/maps/FourIsland/scripts.pory"
	end
# 157 "data/maps/FourIsland/scripts.pory"

# 158 "data/maps/FourIsland/scripts.pory"
FourIsland_EventScript_IslandSign::
# 159 "data/maps/FourIsland/scripts.pory"
	msgbox FourIsland_Text_IslandSign, MSGBOX_SIGN
# 160 "data/maps/FourIsland/scripts.pory"
	end
# 161 "data/maps/FourIsland/scripts.pory"

# 162 "data/maps/FourIsland/scripts.pory"
FourIsland_EventScript_LoreleisHouseSign::
# 163 "data/maps/FourIsland/scripts.pory"
	msgbox FourIsland_Text_LoreleisHouse, MSGBOX_SIGN
# 164 "data/maps/FourIsland/scripts.pory"
	end
