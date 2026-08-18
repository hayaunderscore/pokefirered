# 1 "data/maps/ThreeIsland_BerryForest/scripts.pory"

# 2 "data/maps/ThreeIsland_BerryForest/scripts.pory"
ThreeIsland_BerryForest_MapScripts::
# 3 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, ThreeIsland_BerryForest_OnTransition
# 4 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	.byte 0
# 5 "data/maps/ThreeIsland_BerryForest/scripts.pory"

# 6 "data/maps/ThreeIsland_BerryForest/scripts.pory"
ThreeIsland_BerryForest_OnTransition::
# 7 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	setworldmapflag FLAG_WORLD_MAP_THREE_ISLAND_BERRY_FOREST
# 8 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	setescapewarp MAP_THREE_ISLAND_BOND_BRIDGE, 12, 6
# 9 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	end
# 10 "data/maps/ThreeIsland_BerryForest/scripts.pory"

# 11 "data/maps/ThreeIsland_BerryForest/scripts.pory"
ThreeIsland_BerryForest_EventScript_Lostelle::
# 12 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	lock
# 13 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	faceplayer
# 14 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	msgbox ThreeIsland_BerryForest_Text_HelpScaryPokemon
# 15 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	playse SE_PIN
# 16 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	applymovement LOCALID_BERRY_FOREST_LOSTELLE, Common_Movement_ExclamationMark
# 17 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	waitmovement 0
# 18 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	applymovement LOCALID_BERRY_FOREST_LOSTELLE, ThreeIsland_BerryForest_Movement_LostelleLookAround
# 19 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	waitmovement 0
# 20 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	msgbox ThreeIsland_BerryForest_Text_HereItComesAgain
# 21 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 22 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	waitse
# 23 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	playmoncry SPECIES_HYPNO, CRY_MODE_ENCOUNTER
# 24 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	waitmoncry
# 25 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	setwildbattle SPECIES_HYPNO, 30
# 26 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	dowildbattle
# 27 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	special QuestLog_CutRecording
# 28 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	applymovement LOCALID_BERRY_FOREST_LOSTELLE, Common_Movement_FacePlayer
# 29 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	waitmovement 0
# 30 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	msgbox ThreeIsland_BerryForest_Text_ThankYouHaveThis
# 31 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	giveitem ITEM_IAPAPA_BERRY
# 32 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, ThreeIsland_BerryForest_EventScript_NoRoomForBerry
# 33 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	special BufferBigGuyOrBigGirlString
# 34 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	msgbox ThreeIsland_BerryForest_Text_LetsGoHome
# 35 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	closemessage
# 36 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	setflag FLAG_RESCUED_LOSTELLE
# 37 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	setflag FLAG_HIDE_LOSTELLE_IN_BERRY_FOREST
# 38 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	setvar VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER, 2
# 39 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	clearflag FLAG_HIDE_TWO_ISLAND_GAME_CORNER_LOSTELLE
# 40 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	warp MAP_TWO_ISLAND_JOYFUL_GAME_CORNER, 6, 6
# 41 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	waitstate
# 42 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	release
# 43 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	end
# 44 "data/maps/ThreeIsland_BerryForest/scripts.pory"

# 45 "data/maps/ThreeIsland_BerryForest/scripts.pory"
ThreeIsland_BerryForest_EventScript_NoRoomForBerry::
# 46 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	msgbox ThreeIsland_BerryForest_Text_BerryPouchIsFull
# 47 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	return
# 48 "data/maps/ThreeIsland_BerryForest/scripts.pory"

# 49 "data/maps/ThreeIsland_BerryForest/scripts.pory"
ThreeIsland_BerryForest_Movement_LostelleLookAround::
# 50 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	walk_in_place_faster_left
# 51 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	delay_16
# 52 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	walk_in_place_faster_right
# 53 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	delay_8
# 54 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	walk_in_place_faster_left
# 55 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	step_end
# 56 "data/maps/ThreeIsland_BerryForest/scripts.pory"

# 57 "data/maps/ThreeIsland_BerryForest/scripts.pory"
ThreeIsland_BerryForest_EventScript_WelcomeSign::
# 58 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	msgbox ThreeIsland_BerryForest_Text_WelcomeToBerryForest, MSGBOX_SIGN
# 59 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	end
# 60 "data/maps/ThreeIsland_BerryForest/scripts.pory"

# 61 "data/maps/ThreeIsland_BerryForest/scripts.pory"
ThreeIsland_BerryForest_EventScript_BewareSign::
# 62 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	msgbox ThreeIsland_BerryForest_Text_BewareWildBerryLovingMons, MSGBOX_SIGN
# 63 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	end
