# 1 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"

# 2 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
.equ PLAYER_X_POS, VAR_0x8004
# 3 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
.equ PLAYER_Y_POS, VAR_0x8005
# 4 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"

# 5 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
FiveIsland_RocketWarehouse_MapScripts::
# 6 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, FiveIsland_RocketWarehouse_OnLoad
# 7 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, FiveIsland_RocketWarehouse_OnTransition
# 8 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	.byte 0
# 9 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"

# 10 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
FiveIsland_RocketWarehouse_OnTransition::
# 11 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	setworldmapflag FLAG_WORLD_MAP_FIVE_ISLAND_ROCKET_WAREHOUSE
# 12 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	end
# 13 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"

# 14 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
FiveIsland_RocketWarehouse_OnLoad::
# 15 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	call_if_defeated TRAINER_TEAM_ROCKET_ADMIN, FiveIsland_RocketWarehouse_EventScript_SetArrowsForReEntry
# 16 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	end
# 17 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"

# 18 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
FiveIsland_RocketWarehouse_EventScript_SetArrowsForReEntry::
# 19 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	setmetatile 26, 20, METATILE_SilphCo_Arrow_Up, 0
# 20 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	setmetatile 27, 20, METATILE_SilphCo_Arrow_Up, 0
# 21 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	return
# 22 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"

# 23 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
FiveIsland_RocketWarehouse_EventScript_Cage::
# 24 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	lockall
# 25 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	goto_if_set FLAG_DEFEATED_ROCKETS_IN_WAREHOUSE, FiveIsland_RocketWarehouse_EventScript_CageUnlocked
# 26 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	msgbox FiveIsland_RocketWarehouse_Text_ManyMonsLockedInPen
# 27 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	releaseall
# 28 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	end
# 29 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"

# 30 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
FiveIsland_RocketWarehouse_EventScript_CageUnlocked::
# 31 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	msgbox FiveIsland_RocketWarehouse_Text_PenUnlockedMonsFled
# 32 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	releaseall
# 33 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	end
# 34 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"

# 35 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
FiveIsland_RocketWarehouse_EventScript_Computer::
# 36 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	msgbox FiveIsland_RocketWarehouse_Text_ReportWithGraphsAndText, MSGBOX_SIGN
# 37 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	end
# 38 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"

# 39 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
FiveIsland_RocketWarehouse_EventScript_Admin2Trigger::
# 40 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	lockall
# 41 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	applymovement LOCALID_WAREHOUSE_ADMIN2, Common_Movement_WalkInPlaceFasterLeft
# 42 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	waitmovement 0
# 43 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	setvar VAR_MAP_SCENE_ROCKET_WAREHOUSE, 1
# 44 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	releaseall
# 45 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	end
# 46 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"

# 47 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
FiveIsland_RocketWarehouse_EventScript_Gideon::
# 48 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	trainerbattle_single TRAINER_SCIENTIST_GIDEON, FiveIsland_RocketWarehouse_Text_GideonIntro, FiveIsland_RocketWarehouse_Text_GideonDefeat, FiveIsland_RocketWarehouse_EventScript_DefeatedGideon
# 49 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	goto_if_set FLAG_SYS_CAN_LINK_WITH_RS, FiveIsland_RocketWarehouse_EventScript_MentionGiovannisKid
# 50 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	msgbox FiveIsland_RocketWarehouse_Text_GetLostLeaveMeBe, MSGBOX_AUTOCLOSE
# 51 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	end
# 52 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"

# 53 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
FiveIsland_RocketWarehouse_EventScript_MentionGiovannisKid::
# 54 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	famechecker FAMECHECKER_GIOVANNI, 5
# 55 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	msgbox FiveIsland_RocketWarehouse_Text_GiovannisKidHasRedHair, MSGBOX_AUTOCLOSE
# 56 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	end
# 57 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"

# 58 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
FiveIsland_RocketWarehouse_EventScript_DefeatedGideon::
# 59 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	msgbox FiveIsland_RocketWarehouse_Text_GideonPostBattle
# 60 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	setflag FLAG_RECOVERED_SAPPHIRE
# 61 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	giveitem ITEM_SAPPHIRE
# 62 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	release
# 63 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	end
# 64 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"

# 65 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
FiveIsland_RocketWarehouse_EventScript_Grunt2::
# 66 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_47, FiveIsland_RocketWarehouse_Text_Grunt2Intro, FiveIsland_RocketWarehouse_Text_Grunt2Defeat
# 67 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	msgbox FiveIsland_RocketWarehouse_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
# 68 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	end
# 69 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"

# 70 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
FiveIsland_RocketWarehouse_EventScript_Grunt3::
# 71 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_48, FiveIsland_RocketWarehouse_Text_Grunt3Intro, FiveIsland_RocketWarehouse_Text_Grunt3Defeat
# 72 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	msgbox FiveIsland_RocketWarehouse_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
# 73 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	end
# 74 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"

# 75 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
FiveIsland_RocketWarehouse_EventScript_Admin2::
# 76 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	trainerbattle_single TRAINER_TEAM_ROCKET_ADMIN_2, FiveIsland_RocketWarehouse_Text_Admin2Intro, FiveIsland_RocketWarehouse_Text_Admin2Defeat, FiveIsland_RocketWarehouse_EventScript_DefeatedAdmin2
# 77 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	msgbox FiveIsland_RocketWarehouse_Text_Admin2PostBattle, MSGBOX_AUTOCLOSE
# 78 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	end
# 79 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"

# 80 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
FiveIsland_RocketWarehouse_EventScript_DefeatedAdmin2::
# 81 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	getplayerxy PLAYER_X_POS, PLAYER_Y_POS
# 82 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	call_if_le PLAYER_X_POS, 24, FiveIsland_RocketWarehouse_EventScript_PlayerFaceAdmin2
# 83 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	msgbox FiveIsland_RocketWarehouse_Text_Admin2PostBattle
# 84 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	closemessage
# 85 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	fadescreen FADE_TO_BLACK
# 86 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	removeobject LOCALID_WAREHOUSE_GRUNT2
# 87 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	removeobject LOCALID_WAREHOUSE_GRUNT3
# 88 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	removeobject LOCALID_WAREHOUSE_ADMIN2
# 89 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	removeobject LOCALID_WAREHOUSE_ADMIN1
# 90 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	setflag FLAG_HIDE_FIVE_ISLAND_ROCKETS
# 91 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 92 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	setvar VAR_MAP_SCENE_ROCKET_WAREHOUSE, 1
# 93 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	setflag FLAG_DEFEATED_ROCKETS_IN_WAREHOUSE
# 94 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	release
# 95 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	end
# 96 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"

# 97 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
FiveIsland_RocketWarehouse_EventScript_PlayerFaceAdmin2::
# 98 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 99 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	waitmovement 0
# 100 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	return
# 101 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"

# 102 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
FiveIsland_RocketWarehouse_EventScript_Grunt1::
# 103 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_42, FiveIsland_RocketWarehouse_Text_Grunt1Intro, FiveIsland_RocketWarehouse_Text_Grunt1Defeat
# 104 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	msgbox FiveIsland_RocketWarehouse_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
# 105 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	end
# 106 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"

# 107 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
FiveIsland_RocketWarehouse_EventScript_Admin1::
# 108 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	trainerbattle_single TRAINER_TEAM_ROCKET_ADMIN, FiveIsland_RocketWarehouse_Text_Admin1Intro, FiveIsland_RocketWarehouse_Text_Admin1Defeat, FiveIsland_RocketWarehouse_EventScript_DefeatedAdmin1
# 109 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	msgbox FiveIsland_RocketWarehouse_Text_MadeItSoYouCanComeBackThrough, MSGBOX_AUTOCLOSE
# 110 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	end
# 111 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"

# 112 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
FiveIsland_RocketWarehouse_EventScript_DefeatedAdmin1::
# 113 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	getplayerxy PLAYER_X_POS, PLAYER_Y_POS
# 114 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 115 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	call_if_eq VAR_RESULT, DIR_NORTH, FiveIsland_RocketWarehouse_EventScript_PlayerFaceAdmin1
# 116 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	msgbox FiveIsland_RocketWarehouse_Text_Admin1PostBattle
# 117 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	closemessage
# 118 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	call_if_le PLAYER_X_POS, 24, FiveIsland_RocketWarehouse_EventScript_AdminWalkToSwitchFar
# 119 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	call_if_eq PLAYER_X_POS, 25, FiveIsland_RocketWarehouse_EventScript_AdminWalkToSwitch
# 120 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	call_if_eq PLAYER_X_POS, 26, FiveIsland_RocketWarehouse_EventScript_AdminFaceSwitch
# 121 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	call_if_eq PLAYER_X_POS, 27, FiveIsland_RocketWarehouse_EventScript_AdminFaceSwitch
# 122 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	playse SE_PIN
# 123 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	call FiveIsland_RocketWarehouse_EventScript_SetArrowsForReEntry
# 124 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	special DrawWholeMapView
# 125 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	waitse
# 126 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	call_if_le PLAYER_X_POS, 24, FiveIsland_RocketWarehouse_EventScript_AdminFacePlayerLeft
# 127 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	call_if_eq PLAYER_X_POS, 25, FiveIsland_RocketWarehouse_EventScript_AdminFacePlayerLeft
# 128 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	call_if_eq PLAYER_X_POS, 26, FiveIsland_RocketWarehouse_EventScript_AdminFacePlayerLeft
# 129 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	call_if_eq PLAYER_X_POS, 27, FiveIsland_RocketWarehouse_EventScript_AdminFacePlayerDown
# 130 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	msgbox FiveIsland_RocketWarehouse_Text_MadeItSoYouCanComeBackThrough
# 131 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	release
# 132 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	end
# 133 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"

# 134 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
FiveIsland_RocketWarehouse_EventScript_PlayerFaceAdmin1::
# 135 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	goto_if_eq PLAYER_X_POS, 27, EventScript_Return
# 136 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 137 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	waitmovement 0
# 138 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	return
# 139 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"

# 140 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
FiveIsland_RocketWarehouse_EventScript_AdminWalkToSwitchFar::
# 141 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	applymovement LOCALID_WAREHOUSE_ADMIN1, FiveIsland_RocketWarehouse_Movement_AdminWalkToSwitchFar
# 142 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	waitmovement 0
# 143 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	return
# 144 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"

# 145 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
FiveIsland_RocketWarehouse_EventScript_AdminWalkToSwitch::
# 146 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	applymovement LOCALID_WAREHOUSE_ADMIN1, FiveIsland_RocketWarehouse_Movement_AdminWalkToSwitch
# 147 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	waitmovement 0
# 148 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	return
# 149 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"

# 150 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
FiveIsland_RocketWarehouse_EventScript_AdminFaceSwitch::
# 151 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	applymovement LOCALID_WAREHOUSE_ADMIN1, Common_Movement_WalkInPlaceFasterUp
# 152 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	waitmovement 0
# 153 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	return
# 154 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"

# 155 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
FiveIsland_RocketWarehouse_EventScript_AdminFacePlayerLeft::
# 156 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	applymovement LOCALID_WAREHOUSE_ADMIN1, Common_Movement_WalkInPlaceFasterLeft
# 157 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	waitmovement 0
# 158 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	return
# 159 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"

# 160 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
FiveIsland_RocketWarehouse_EventScript_AdminFacePlayerDown::
# 161 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	applymovement LOCALID_WAREHOUSE_ADMIN1, Common_Movement_WalkInPlaceFasterDown
# 162 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	waitmovement 0
# 163 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	return
# 164 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"

# 165 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
FiveIsland_RocketWarehouse_Movement_AdminWalkToSwitchFar::
# 166 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	walk_right
# 167 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	walk_right
# 168 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	walk_in_place_faster_up
# 169 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	step_end
# 170 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"

# 171 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
FiveIsland_RocketWarehouse_Movement_AdminWalkToSwitch::
# 172 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	walk_right
# 173 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	walk_in_place_faster_up
# 174 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	step_end
