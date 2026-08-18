# 1 "data/maps/BirthIsland_Exterior/scripts.pory"

# 2 "data/maps/BirthIsland_Exterior/scripts.pory"
BirthIsland_Exterior_MapScripts::
# 3 "data/maps/BirthIsland_Exterior/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, BirthIsland_Exterior_OnTransition
# 4 "data/maps/BirthIsland_Exterior/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, BirthIsland_Exterior_OnResume
# 5 "data/maps/BirthIsland_Exterior/scripts.pory"
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, BirthIsland_Exterior_OnReturnToField
# 6 "data/maps/BirthIsland_Exterior/scripts.pory"
	.byte 0
# 7 "data/maps/BirthIsland_Exterior/scripts.pory"

# 8 "data/maps/BirthIsland_Exterior/scripts.pory"
BirthIsland_Exterior_OnReturnToField::
# 9 "data/maps/BirthIsland_Exterior/scripts.pory"
	special SetDeoxysTrianglePalette
# 10 "data/maps/BirthIsland_Exterior/scripts.pory"
	end
# 11 "data/maps/BirthIsland_Exterior/scripts.pory"

# 12 "data/maps/BirthIsland_Exterior/scripts.pory"
BirthIsland_Exterior_OnTransition::
# 13 "data/maps/BirthIsland_Exterior/scripts.pory"
	setworldmapflag FLAG_WORLD_MAP_BIRTH_ISLAND_EXTERIOR
# 14 "data/maps/BirthIsland_Exterior/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_DEOXYS_N
# 15 "data/maps/BirthIsland_Exterior/scripts.pory"
	setvar VAR_DEOXYS_INTERACTION_STEP_COUNTER, 0
# 16 "data/maps/BirthIsland_Exterior/scripts.pory"
	setvar VAR_DEOXYS_INTERACTION_NUM, 0
# 17 "data/maps/BirthIsland_Exterior/scripts.pory"
	call_if_set FLAG_FOUGHT_DEOXYS, BirthIsland_Exterior_EventScript_HideDeoxysAndPuzzle
# 18 "data/maps/BirthIsland_Exterior/scripts.pory"
	call_if_unset FLAG_FOUGHT_DEOXYS, BirthIsland_Exterior_EventScript_TryShowDeoxysPuzzle
# 19 "data/maps/BirthIsland_Exterior/scripts.pory"
	end
# 20 "data/maps/BirthIsland_Exterior/scripts.pory"

# 21 "data/maps/BirthIsland_Exterior/scripts.pory"
BirthIsland_Exterior_EventScript_HideDeoxysAndPuzzle::
# 22 "data/maps/BirthIsland_Exterior/scripts.pory"
	setflag FLAG_HIDE_DEOXYS
# 23 "data/maps/BirthIsland_Exterior/scripts.pory"
	setflag FLAG_HIDE_BIRTH_ISLAND_METEORITE
# 24 "data/maps/BirthIsland_Exterior/scripts.pory"
	return
# 25 "data/maps/BirthIsland_Exterior/scripts.pory"

# 26 "data/maps/BirthIsland_Exterior/scripts.pory"
BirthIsland_Exterior_EventScript_TryShowDeoxysPuzzle::
# 27 "data/maps/BirthIsland_Exterior/scripts.pory"
	goto_if_set FLAG_DEOXYS_FLEW_AWAY, EventScript_Return
# 28 "data/maps/BirthIsland_Exterior/scripts.pory"
	clearflag FLAG_HIDE_BIRTH_ISLAND_METEORITE
# 29 "data/maps/BirthIsland_Exterior/scripts.pory"
	clearflag FLAG_SYS_DEOXYS_AWAKENED
# 30 "data/maps/BirthIsland_Exterior/scripts.pory"
	return
# 31 "data/maps/BirthIsland_Exterior/scripts.pory"

# 32 "data/maps/BirthIsland_Exterior/scripts.pory"
BirthIsland_Exterior_OnResume::
# 33 "data/maps/BirthIsland_Exterior/scripts.pory"
	call_if_set FLAG_SYS_SPECIAL_WILD_BATTLE, BirthIsland_Exterior_EventScript_TryRemoveDeoxys
# 34 "data/maps/BirthIsland_Exterior/scripts.pory"
	end
# 35 "data/maps/BirthIsland_Exterior/scripts.pory"

# 36 "data/maps/BirthIsland_Exterior/scripts.pory"
BirthIsland_Exterior_EventScript_TryRemoveDeoxys::
# 37 "data/maps/BirthIsland_Exterior/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 38 "data/maps/BirthIsland_Exterior/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, EventScript_Return
# 39 "data/maps/BirthIsland_Exterior/scripts.pory"
	removeobject LOCALID_BIRTH_ISLAND_DEOXYS
# 40 "data/maps/BirthIsland_Exterior/scripts.pory"
	return
# 41 "data/maps/BirthIsland_Exterior/scripts.pory"

# 42 "data/maps/BirthIsland_Exterior/scripts.pory"
BirthIsland_Exterior_EventScript_Triangle::
# 43 "data/maps/BirthIsland_Exterior/scripts.pory"
	lock
# 44 "data/maps/BirthIsland_Exterior/scripts.pory"
	faceplayer
# 45 "data/maps/BirthIsland_Exterior/scripts.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 46 "data/maps/BirthIsland_Exterior/scripts.pory"
	special QuestLog_CutRecording
# 47 "data/maps/BirthIsland_Exterior/scripts.pory"
	special DoDeoxysTriangleInteraction
# 48 "data/maps/BirthIsland_Exterior/scripts.pory"
	waitstate
# 49 "data/maps/BirthIsland_Exterior/scripts.pory"
	switch VAR_RESULT
# 50 "data/maps/BirthIsland_Exterior/scripts.pory"
	case 0, BirthIsland_Exterior_EventScript_NotSolved1
# 51 "data/maps/BirthIsland_Exterior/scripts.pory"
	case 1, BirthIsland_Exterior_EventScript_NotSolved2
# 52 "data/maps/BirthIsland_Exterior/scripts.pory"
	case 2, BirthIsland_Exterior_EventScript_Deoxys
# 53 "data/maps/BirthIsland_Exterior/scripts.pory"
	case 3, BirthIsland_Exterior_EventScript_NotSolved3
# 54 "data/maps/BirthIsland_Exterior/scripts.pory"
	end
# 55 "data/maps/BirthIsland_Exterior/scripts.pory"

# 56 "data/maps/BirthIsland_Exterior/scripts.pory"
BirthIsland_Exterior_EventScript_NotSolved1::
# 57 "data/maps/BirthIsland_Exterior/scripts.pory"
	release
# 58 "data/maps/BirthIsland_Exterior/scripts.pory"
	end
# 59 "data/maps/BirthIsland_Exterior/scripts.pory"

# 60 "data/maps/BirthIsland_Exterior/scripts.pory"
BirthIsland_Exterior_EventScript_NotSolved2::
# 61 "data/maps/BirthIsland_Exterior/scripts.pory"
	release
# 62 "data/maps/BirthIsland_Exterior/scripts.pory"
	end
# 63 "data/maps/BirthIsland_Exterior/scripts.pory"

# 64 "data/maps/BirthIsland_Exterior/scripts.pory"
BirthIsland_Exterior_EventScript_NotSolved3::
# 65 "data/maps/BirthIsland_Exterior/scripts.pory"
	release
# 66 "data/maps/BirthIsland_Exterior/scripts.pory"
	end
# 67 "data/maps/BirthIsland_Exterior/scripts.pory"

# 68 "data/maps/BirthIsland_Exterior/scripts.pory"
BirthIsland_Exterior_EventScript_Deoxys::
# 69 "data/maps/BirthIsland_Exterior/scripts.pory"
	addobject LOCALID_BIRTH_ISLAND_DEOXYS
# 70 "data/maps/BirthIsland_Exterior/scripts.pory"
	waitse
# 71 "data/maps/BirthIsland_Exterior/scripts.pory"
	setfieldeffectargument 0, LOCALID_BIRTH_ISLAND_EXTERIOR_ROCK
# 72 "data/maps/BirthIsland_Exterior/scripts.pory"
	setfieldeffectargument 1, MAP_NUM(MAP_BIRTH_ISLAND_EXTERIOR)
# 73 "data/maps/BirthIsland_Exterior/scripts.pory"
	setfieldeffectargument 2, MAP_GROUP(MAP_BIRTH_ISLAND_EXTERIOR)
# 74 "data/maps/BirthIsland_Exterior/scripts.pory"
	dofieldeffect FLDEFF_DESTROY_DEOXYS_ROCK
# 75 "data/maps/BirthIsland_Exterior/scripts.pory"
	playbgm MUS_ENCOUNTER_DEOXYS, 0
# 76 "data/maps/BirthIsland_Exterior/scripts.pory"
	waitfieldeffect FLDEFF_DESTROY_DEOXYS_ROCK
# 77 "data/maps/BirthIsland_Exterior/scripts.pory"
	applymovement LOCALID_BIRTH_ISLAND_DEOXYS, Movement_DeoxysApproach
# 78 "data/maps/BirthIsland_Exterior/scripts.pory"
	waitmovement 0
# 79 "data/maps/BirthIsland_Exterior/scripts.pory"
	waitse
# 80 "data/maps/BirthIsland_Exterior/scripts.pory"
	playmoncry SPECIES_DEOXYS, CRY_MODE_ENCOUNTER
# 81 "data/maps/BirthIsland_Exterior/scripts.pory"
	delay 40
# 82 "data/maps/BirthIsland_Exterior/scripts.pory"
	waitmoncry
# 83 "data/maps/BirthIsland_Exterior/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_BIRTH_ISLAND_DEOXYS
# 84 "data/maps/BirthIsland_Exterior/scripts.pory"
	seteventmon SPECIES_DEOXYS, 30
# 85 "data/maps/BirthIsland_Exterior/scripts.pory"
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
# 86 "data/maps/BirthIsland_Exterior/scripts.pory"
	special StartLegendaryBattle
# 87 "data/maps/BirthIsland_Exterior/scripts.pory"
	waitstate
# 88 "data/maps/BirthIsland_Exterior/scripts.pory"
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
# 89 "data/maps/BirthIsland_Exterior/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 90 "data/maps/BirthIsland_Exterior/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, BirthIsland_Exterior_EventScript_DefeatedDeoxys
# 91 "data/maps/BirthIsland_Exterior/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BirthIsland_Exterior_EventScript_RanFromDeoxys
# 92 "data/maps/BirthIsland_Exterior/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BirthIsland_Exterior_EventScript_RanFromDeoxys
# 93 "data/maps/BirthIsland_Exterior/scripts.pory"
	setflag FLAG_FOUGHT_DEOXYS
# 94 "data/maps/BirthIsland_Exterior/scripts.pory"
	release
# 95 "data/maps/BirthIsland_Exterior/scripts.pory"
	end
# 96 "data/maps/BirthIsland_Exterior/scripts.pory"

# 97 "data/maps/BirthIsland_Exterior/scripts.pory"
BirthIsland_Exterior_EventScript_DefeatedDeoxys::
# 98 "data/maps/BirthIsland_Exterior/scripts.pory"
	setflag FLAG_DEOXYS_FLEW_AWAY
# 99 "data/maps/BirthIsland_Exterior/scripts.pory"
	setvar VAR_0x8004, SPECIES_DEOXYS
# 100 "data/maps/BirthIsland_Exterior/scripts.pory"
	goto EventScript_MonFlewAway
# 101 "data/maps/BirthIsland_Exterior/scripts.pory"
	end
# 102 "data/maps/BirthIsland_Exterior/scripts.pory"

# 103 "data/maps/BirthIsland_Exterior/scripts.pory"
BirthIsland_Exterior_EventScript_RanFromDeoxys::
# 104 "data/maps/BirthIsland_Exterior/scripts.pory"
	setvar VAR_0x8004, SPECIES_DEOXYS
# 105 "data/maps/BirthIsland_Exterior/scripts.pory"
	goto EventScript_MonFlewAway
# 106 "data/maps/BirthIsland_Exterior/scripts.pory"
	end
# 107 "data/maps/BirthIsland_Exterior/scripts.pory"

# 108 "data/maps/BirthIsland_Exterior/scripts.pory"
Movement_DeoxysApproach:
# 109 "data/maps/BirthIsland_Exterior/scripts.pory"
	walk_slower_down
# 110 "data/maps/BirthIsland_Exterior/scripts.pory"
	walk_slower_down
# 111 "data/maps/BirthIsland_Exterior/scripts.pory"
	walk_slower_down
# 112 "data/maps/BirthIsland_Exterior/scripts.pory"
	walk_slower_down
# 113 "data/maps/BirthIsland_Exterior/scripts.pory"
	walk_slower_down
# 114 "data/maps/BirthIsland_Exterior/scripts.pory"
	walk_slower_down
# 115 "data/maps/BirthIsland_Exterior/scripts.pory"
	walk_slower_down
# 116 "data/maps/BirthIsland_Exterior/scripts.pory"
	step_end
