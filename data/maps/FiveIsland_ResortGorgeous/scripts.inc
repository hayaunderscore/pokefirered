# 1 "data/maps/FiveIsland_ResortGorgeous/scripts.pory"

# 2 "data/maps/FiveIsland_ResortGorgeous/scripts.pory"
FiveIsland_ResortGorgeous_MapScripts::
# 3 "data/maps/FiveIsland_ResortGorgeous/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FiveIsland_ResortGorgeous_OnWarp
# 4 "data/maps/FiveIsland_ResortGorgeous/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FiveIsland_ResortGorgeous_OnFrame
# 5 "data/maps/FiveIsland_ResortGorgeous/scripts.pory"
	.byte 0
# 6 "data/maps/FiveIsland_ResortGorgeous/scripts.pory"

# 7 "data/maps/FiveIsland_ResortGorgeous/scripts.pory"
FiveIsland_ResortGorgeous_OnWarp::
# 8 "data/maps/FiveIsland_ResortGorgeous/scripts.pory"
	map_script_2 VAR_MAP_SCENE_FIVE_ISLAND_RESORT_GORGEOUS, 1, FiveIsland_ResortGorgeous_EventScript_TurnPlayerNorth
# 9 "data/maps/FiveIsland_ResortGorgeous/scripts.pory"
	.2byte 0
# 10 "data/maps/FiveIsland_ResortGorgeous/scripts.pory"

# 11 "data/maps/FiveIsland_ResortGorgeous/scripts.pory"
FiveIsland_ResortGorgeous_EventScript_TurnPlayerNorth::
# 12 "data/maps/FiveIsland_ResortGorgeous/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 13 "data/maps/FiveIsland_ResortGorgeous/scripts.pory"
	end
# 14 "data/maps/FiveIsland_ResortGorgeous/scripts.pory"

# 15 "data/maps/FiveIsland_ResortGorgeous/scripts.pory"
FiveIsland_ResortGorgeous_OnFrame::
# 16 "data/maps/FiveIsland_ResortGorgeous/scripts.pory"
	map_script_2 VAR_MAP_SCENE_FIVE_ISLAND_RESORT_GORGEOUS, 1, FiveIsland_ResortGorgeous_EventScript_SelphyReturnHomeScene
# 17 "data/maps/FiveIsland_ResortGorgeous/scripts.pory"
	.2byte 0
# 18 "data/maps/FiveIsland_ResortGorgeous/scripts.pory"

# 19 "data/maps/FiveIsland_ResortGorgeous/scripts.pory"
FiveIsland_ResortGorgeous_EventScript_SelphyReturnHomeScene::
# 20 "data/maps/FiveIsland_ResortGorgeous/scripts.pory"
	lockall
# 21 "data/maps/FiveIsland_ResortGorgeous/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 22 "data/maps/FiveIsland_ResortGorgeous/scripts.pory"
	msgbox FiveIsland_ResortGorgeous_Text_SelphyThanksYouMayGoNow
# 23 "data/maps/FiveIsland_ResortGorgeous/scripts.pory"
	closemessage
# 24 "data/maps/FiveIsland_ResortGorgeous/scripts.pory"
	applymovement LOCALID_RESORT_GORGEOUS_SELPHY, Common_Movement_WalkInPlaceFasterUp
# 25 "data/maps/FiveIsland_ResortGorgeous/scripts.pory"
	waitmovement 0
# 26 "data/maps/FiveIsland_ResortGorgeous/scripts.pory"
	opendoor 39, 8
# 27 "data/maps/FiveIsland_ResortGorgeous/scripts.pory"
	waitdooranim
# 28 "data/maps/FiveIsland_ResortGorgeous/scripts.pory"
	applymovement LOCALID_RESORT_GORGEOUS_SELPHY, FiveIsland_ResortGorgeous_Movement_SelphyEnterHome
# 29 "data/maps/FiveIsland_ResortGorgeous/scripts.pory"
	waitmovement 0
# 30 "data/maps/FiveIsland_ResortGorgeous/scripts.pory"
	closedoor 39, 8
# 31 "data/maps/FiveIsland_ResortGorgeous/scripts.pory"
	waitdooranim
# 32 "data/maps/FiveIsland_ResortGorgeous/scripts.pory"
	removeobject LOCALID_RESORT_GORGEOUS_SELPHY
# 33 "data/maps/FiveIsland_ResortGorgeous/scripts.pory"
	clearflag FLAG_HIDE_RESORT_GORGEOUS_INSIDE_SELPHY
# 34 "data/maps/FiveIsland_ResortGorgeous/scripts.pory"
	setvar VAR_MAP_SCENE_FIVE_ISLAND_RESORT_GORGEOUS, 2
# 35 "data/maps/FiveIsland_ResortGorgeous/scripts.pory"
	releaseall
# 36 "data/maps/FiveIsland_ResortGorgeous/scripts.pory"
	end
# 37 "data/maps/FiveIsland_ResortGorgeous/scripts.pory"

# 38 "data/maps/FiveIsland_ResortGorgeous/scripts.pory"
FiveIsland_ResortGorgeous_Movement_SelphyEnterHome::
# 39 "data/maps/FiveIsland_ResortGorgeous/scripts.pory"
	walk_up
# 40 "data/maps/FiveIsland_ResortGorgeous/scripts.pory"
	set_invisible
# 41 "data/maps/FiveIsland_ResortGorgeous/scripts.pory"
	step_end
# 42 "data/maps/FiveIsland_ResortGorgeous/scripts.pory"

# 43 "data/maps/FiveIsland_ResortGorgeous/scripts.pory"
FiveIsland_ResortGorgeous_EventScript_SelphysHouseSign::
# 44 "data/maps/FiveIsland_ResortGorgeous/scripts.pory"
	msgbox FiveIsland_ResortGorgeous_Text_SelphysHouse, MSGBOX_SIGN
# 45 "data/maps/FiveIsland_ResortGorgeous/scripts.pory"
	end
