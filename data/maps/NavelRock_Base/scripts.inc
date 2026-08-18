# 1 "data/maps/NavelRock_Base/scripts.pory"

# 2 "data/maps/NavelRock_Base/scripts.pory"
NavelRock_Base_MapScripts::
# 3 "data/maps/NavelRock_Base/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, NavelRock_Base_OnTransition
# 4 "data/maps/NavelRock_Base/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, NavelRock_Base_OnResume
# 5 "data/maps/NavelRock_Base/scripts.pory"
	.byte 0
# 6 "data/maps/NavelRock_Base/scripts.pory"

# 7 "data/maps/NavelRock_Base/scripts.pory"
NavelRock_Base_OnTransition::
# 8 "data/maps/NavelRock_Base/scripts.pory"
	call_if_set FLAG_FOUGHT_LUGIA, NavelRock_Base_EventScript_HideLugia
# 9 "data/maps/NavelRock_Base/scripts.pory"
	call_if_unset FLAG_FOUGHT_LUGIA, NavelRock_Base_EventScript_TryShowLugia
# 10 "data/maps/NavelRock_Base/scripts.pory"
	end
# 11 "data/maps/NavelRock_Base/scripts.pory"

# 12 "data/maps/NavelRock_Base/scripts.pory"
NavelRock_Base_EventScript_HideLugia::
# 13 "data/maps/NavelRock_Base/scripts.pory"
	setflag FLAG_HIDE_LUGIA
# 14 "data/maps/NavelRock_Base/scripts.pory"
	return
# 15 "data/maps/NavelRock_Base/scripts.pory"

# 16 "data/maps/NavelRock_Base/scripts.pory"
NavelRock_Base_EventScript_TryShowLugia::
# 17 "data/maps/NavelRock_Base/scripts.pory"
	goto_if_set FLAG_LUGIA_FLEW_AWAY, EventScript_Return
# 18 "data/maps/NavelRock_Base/scripts.pory"
	clearflag FLAG_HIDE_LUGIA
# 19 "data/maps/NavelRock_Base/scripts.pory"
	return
# 20 "data/maps/NavelRock_Base/scripts.pory"

# 21 "data/maps/NavelRock_Base/scripts.pory"
NavelRock_Base_OnResume::
# 22 "data/maps/NavelRock_Base/scripts.pory"
	call_if_set FLAG_SYS_SPECIAL_WILD_BATTLE, NavelRock_Base_EventScript_TryRemoveLugia
# 23 "data/maps/NavelRock_Base/scripts.pory"
	end
# 24 "data/maps/NavelRock_Base/scripts.pory"

# 25 "data/maps/NavelRock_Base/scripts.pory"
NavelRock_Base_EventScript_TryRemoveLugia::
# 26 "data/maps/NavelRock_Base/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 27 "data/maps/NavelRock_Base/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, EventScript_Return
# 28 "data/maps/NavelRock_Base/scripts.pory"
	removeobject LOCALID_NAVEL_ROCK_LUGIA
# 29 "data/maps/NavelRock_Base/scripts.pory"
	return
# 30 "data/maps/NavelRock_Base/scripts.pory"

# 31 "data/maps/NavelRock_Base/scripts.pory"
NavelRock_Base_EventScript_Lugia::
# 32 "data/maps/NavelRock_Base/scripts.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 33 "data/maps/NavelRock_Base/scripts.pory"
	special QuestLog_CutRecording
# 34 "data/maps/NavelRock_Base/scripts.pory"
	lock
# 35 "data/maps/NavelRock_Base/scripts.pory"
	faceplayer
# 36 "data/maps/NavelRock_Base/scripts.pory"
	waitse
# 37 "data/maps/NavelRock_Base/scripts.pory"
	delay 20
# 38 "data/maps/NavelRock_Base/scripts.pory"
	playse SE_THUNDERSTORM_STOP
# 39 "data/maps/NavelRock_Base/scripts.pory"
	setvar VAR_0x8004, 0  @ Vertical pan
# 40 "data/maps/NavelRock_Base/scripts.pory"
	setvar VAR_0x8005, 3  @ Horizontal pan
# 41 "data/maps/NavelRock_Base/scripts.pory"
	setvar VAR_0x8006, 4  @ Num shakes
# 42 "data/maps/NavelRock_Base/scripts.pory"
	setvar VAR_0x8007, 2  @ Shake delay
# 43 "data/maps/NavelRock_Base/scripts.pory"
	special ShakeScreen
# 44 "data/maps/NavelRock_Base/scripts.pory"
	delay 30
# 45 "data/maps/NavelRock_Base/scripts.pory"
	playse SE_THUNDERSTORM_STOP
# 46 "data/maps/NavelRock_Base/scripts.pory"
	setvar VAR_0x8004, 0  @ Vertical pan
# 47 "data/maps/NavelRock_Base/scripts.pory"
	setvar VAR_0x8005, 3  @ Horizontal pan
# 48 "data/maps/NavelRock_Base/scripts.pory"
	setvar VAR_0x8006, 4  @ Num shakes
# 49 "data/maps/NavelRock_Base/scripts.pory"
	setvar VAR_0x8007, 2  @ Shake delay
# 50 "data/maps/NavelRock_Base/scripts.pory"
	special ShakeScreen
# 51 "data/maps/NavelRock_Base/scripts.pory"
	delay 30
# 52 "data/maps/NavelRock_Base/scripts.pory"
	delay 50
# 53 "data/maps/NavelRock_Base/scripts.pory"
	waitse
# 54 "data/maps/NavelRock_Base/scripts.pory"
	playmoncry SPECIES_LUGIA, CRY_MODE_ENCOUNTER
# 55 "data/maps/NavelRock_Base/scripts.pory"
	waitmoncry
# 56 "data/maps/NavelRock_Base/scripts.pory"
	delay 20
# 57 "data/maps/NavelRock_Base/scripts.pory"
	seteventmon SPECIES_LUGIA, 70
# 58 "data/maps/NavelRock_Base/scripts.pory"
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
# 59 "data/maps/NavelRock_Base/scripts.pory"
	special StartLegendaryBattle
# 60 "data/maps/NavelRock_Base/scripts.pory"
	waitstate
# 61 "data/maps/NavelRock_Base/scripts.pory"
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
# 62 "data/maps/NavelRock_Base/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 63 "data/maps/NavelRock_Base/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, NavelRock_Base_EventScript_DefeatedLugia
# 64 "data/maps/NavelRock_Base/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, NavelRock_Base_EventScript_RanFromLugia
# 65 "data/maps/NavelRock_Base/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, NavelRock_Base_EventScript_RanFromLugia
# 66 "data/maps/NavelRock_Base/scripts.pory"
	setflag FLAG_FOUGHT_LUGIA
# 67 "data/maps/NavelRock_Base/scripts.pory"
	release
# 68 "data/maps/NavelRock_Base/scripts.pory"
	end
# 69 "data/maps/NavelRock_Base/scripts.pory"

# 70 "data/maps/NavelRock_Base/scripts.pory"
NavelRock_Base_EventScript_DefeatedLugia::
# 71 "data/maps/NavelRock_Base/scripts.pory"
	setflag FLAG_LUGIA_FLEW_AWAY
# 72 "data/maps/NavelRock_Base/scripts.pory"
	setvar VAR_0x8004, SPECIES_LUGIA
# 73 "data/maps/NavelRock_Base/scripts.pory"
	goto EventScript_MonFlewAway
# 74 "data/maps/NavelRock_Base/scripts.pory"
	end
# 75 "data/maps/NavelRock_Base/scripts.pory"

# 76 "data/maps/NavelRock_Base/scripts.pory"
NavelRock_Base_EventScript_RanFromLugia::
# 77 "data/maps/NavelRock_Base/scripts.pory"
	setvar VAR_0x8004, SPECIES_LUGIA
# 78 "data/maps/NavelRock_Base/scripts.pory"
	goto EventScript_MonFlewAway
# 79 "data/maps/NavelRock_Base/scripts.pory"
	end
