# 1 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"

# 2 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
PokemonLeague_ChampionsRoom_MapScripts::
# 3 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PokemonLeague_ChampionsRoom_OnWarp
# 4 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_ChampionsRoom_OnResume
# 5 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PokemonLeague_ChampionsRoom_OnFrame
# 6 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	.byte 0
# 7 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"

# 8 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
PokemonLeague_ChampionsRoom_OnResume::
# 9 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	setvar VAR_0x8004, 4
# 10 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	call PokemonLeague_EventScript_DoLightingEffect
# 11 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	call_if_eq VAR_STARTER_MON, 2, PokemonLeague_ChampionsRoom_EventScript_CheckStopTriggerSquirtle
# 12 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	call_if_eq VAR_STARTER_MON, 1, PokemonLeague_ChampionsRoom_EventScript_CheckStopTriggerBulbasaur
# 13 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	call_if_eq VAR_STARTER_MON, 0, PokemonLeague_ChampionsRoom_EventScript_CheckStopTriggerCharmander
# 14 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	end
# 15 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"

# 16 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
PokemonLeague_ChampionsRoom_EventScript_CheckStopTriggerSquirtle::
# 17 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	goto_if_defeated TRAINER_CHAMPION_FIRST_SQUIRTLE, PokemonLeague_ChampionsRoom_EventScript_StopSceneTrigger
# 18 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	goto_if_defeated TRAINER_CHAMPION_REMATCH_SQUIRTLE, PokemonLeague_ChampionsRoom_EventScript_StopSceneTrigger
# 19 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	return
# 20 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"

# 21 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
PokemonLeague_ChampionsRoom_EventScript_CheckStopTriggerBulbasaur::
# 22 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	goto_if_defeated TRAINER_CHAMPION_FIRST_BULBASAUR, PokemonLeague_ChampionsRoom_EventScript_StopSceneTrigger
# 23 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	goto_if_defeated TRAINER_CHAMPION_REMATCH_BULBASAUR, PokemonLeague_ChampionsRoom_EventScript_StopSceneTrigger
# 24 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	return
# 25 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"

# 26 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
PokemonLeague_ChampionsRoom_EventScript_CheckStopTriggerCharmander::
# 27 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	goto_if_defeated TRAINER_CHAMPION_FIRST_CHARMANDER, PokemonLeague_ChampionsRoom_EventScript_StopSceneTrigger
# 28 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	goto_if_defeated TRAINER_CHAMPION_REMATCH_CHARMANDER, PokemonLeague_ChampionsRoom_EventScript_StopSceneTrigger
# 29 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	return
# 30 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"

# 31 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
PokemonLeague_ChampionsRoom_EventScript_StopSceneTrigger::
# 32 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 33 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	return
# 34 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"

# 35 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
PokemonLeague_ChampionsRoom_OnWarp::
# 36 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, PokemonLeague_ChampionsRoom_EventScript_TurnPlayerNorth
# 37 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	.2byte 0
# 38 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"

# 39 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
PokemonLeague_ChampionsRoom_EventScript_TurnPlayerNorth::
# 40 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 41 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	end
# 42 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"

# 43 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
PokemonLeague_ChampionsRoom_OnFrame::
# 44 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, PokemonLeague_ChampionsRoom_EventScript_EnterRoom
# 45 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	.2byte 0
# 46 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"

# 47 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
PokemonLeague_ChampionsRoom_EventScript_EnterRoom::
# 48 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	lockall
# 49 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 50 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	setflag FLAG_TEMP_2
# 51 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, PokemonLeague_ChampionsRoom_Movement_PlayerEnter
# 52 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	waitmovement 0
# 53 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	delay 20
# 54 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	call_if_unset FLAG_SYS_GAME_CLEAR, PokemonLeague_ChampionsRoom_EventScript_Intro
# 55 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	call_if_set FLAG_SYS_GAME_CLEAR, PokemonLeague_ChampionsRoom_EventScript_RematchIntro
# 56 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	goto_if_questlog PokemonLeague_ChampionsRoom_EventScript_QuestLogEnd
# 57 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	setflag FLAG_TEMP_3
# 58 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	setflag FLAG_TEMP_5
# 59 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	savebgm MUS_VICTORY_GYM_LEADER
# 60 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	call_if_unset FLAG_SYS_CAN_LINK_WITH_RS, PokemonLeague_ChampionsRoom_EventScript_Battle
# 61 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	call_if_set FLAG_SYS_CAN_LINK_WITH_RS, PokemonLeague_ChampionsRoom_EventScript_Rematch
# 62 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	setflag FLAG_TEMP_4
# 63 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	clearflag FLAG_TEMP_5
# 64 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	setflag FLAG_DEFEATED_CHAMP
# 65 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	setflag FLAG_TEMP_4
# 66 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	msgbox PokemonLeague_ChampionsRoom_Text_PostBattle
# 67 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	playbgm MUS_SLOW_PALLET, 0
# 68 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	addobject LOCALID_CHAMPIONS_ROOM_PROF_OAK
# 69 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	msgbox PokemonLeague_ChampionsRoom_Text_OakPlayer
# 70 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	closemessage
# 71 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, PokemonLeague_ChampionsRoom_Movement_PlayerWatchOakEnter
# 72 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, PokemonLeague_ChampionsRoom_Movement_RivalWatchOakEnter
# 73 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_PROF_OAK, PokemonLeague_ChampionsRoom_Movement_OakEnter
# 74 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	waitmovement 0
# 75 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	delay 25
# 76 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	specialvar VAR_RESULT, GetStarterSpecies
# 77 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_RESULT
# 78 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	msgbox PokemonLeague_ChampionsRoom_Text_OakCongratulations
# 79 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_PROF_OAK, Common_Movement_WalkInPlaceFasterRight
# 80 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_WalkInPlaceFasterLeft
# 81 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	waitmovement 0
# 82 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	msgbox PokemonLeague_ChampionsRoom_Text_OakImDisappointedRival
# 83 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	closemessage
# 84 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_PROF_OAK, Common_Movement_WalkInPlaceFasterDown
# 85 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	waitmovement 0
# 86 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	delay 20
# 87 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	msgbox PokemonLeague_ChampionsRoom_Text_OakPlayerComeWithMe
# 88 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	closemessage
# 89 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	delay 13
# 90 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_PROF_OAK, PokemonLeague_ChampionsRoom_Movement_OakExit
# 91 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, PokemonLeague_ChampionsRoom_Movement_PlayerExit
# 92 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	waitmovement 0
# 93 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 94 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	warp MAP_POKEMON_LEAGUE_HALL_OF_FAME, 5, 12
# 95 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	waitstate
# 96 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	releaseall
# 97 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	end
# 98 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"

# 99 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
PokemonLeague_ChampionsRoom_EventScript_QuestLogEnd::
# 100 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	call PokemonLeague_ChampionsRoom_EventScript_StopSceneTrigger
# 101 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	releaseall
# 102 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	end
# 103 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"

# 104 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
PokemonLeague_ChampionsRoom_EventScript_Battle::
# 105 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	call_if_eq VAR_STARTER_MON, 2, PokemonLeague_ChampionsRoom_EventScript_BattleSquirtle
# 106 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	call_if_eq VAR_STARTER_MON, 1, PokemonLeague_ChampionsRoom_EventScript_BattleBulbasaur
# 107 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	call_if_eq VAR_STARTER_MON, 0, PokemonLeague_ChampionsRoom_EventScript_BattleCharmander
# 108 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	return
# 109 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"

# 110 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
PokemonLeague_ChampionsRoom_EventScript_Rematch::
# 111 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	call_if_eq VAR_STARTER_MON, 2, PokemonLeague_ChampionsRoom_EventScript_RematchSquirtle
# 112 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	call_if_eq VAR_STARTER_MON, 1, PokemonLeague_ChampionsRoom_EventScript_RematchBulbasaur
# 113 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	call_if_eq VAR_STARTER_MON, 0, PokemonLeague_ChampionsRoom_EventScript_RematchCharmander
# 114 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	return
# 115 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"

# 116 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
PokemonLeague_ChampionsRoom_EventScript_Intro::
# 117 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	msgbox PokemonLeague_ChampionsRoom_Text_Intro
# 118 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	return
# 119 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"

# 120 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
PokemonLeague_ChampionsRoom_EventScript_RematchIntro::
# 121 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	msgbox PokemonLeague_ChampionsRoom_Text_RematchIntro
# 122 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	return
# 123 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"

# 124 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
PokemonLeague_ChampionsRoom_EventScript_BattleSquirtle::
# 125 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_CHAMPION_FIRST_SQUIRTLE, PokemonLeague_ChampionsRoom_Text_Defeat
# 126 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	return
# 127 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"

# 128 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
PokemonLeague_ChampionsRoom_EventScript_BattleBulbasaur::
# 129 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_CHAMPION_FIRST_BULBASAUR, PokemonLeague_ChampionsRoom_Text_Defeat
# 130 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	return
# 131 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"

# 132 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
PokemonLeague_ChampionsRoom_EventScript_BattleCharmander::
# 133 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_CHAMPION_FIRST_CHARMANDER, PokemonLeague_ChampionsRoom_Text_Defeat
# 134 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	return
# 135 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"

# 136 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
PokemonLeague_ChampionsRoom_EventScript_RematchSquirtle::
# 137 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_CHAMPION_REMATCH_SQUIRTLE, PokemonLeague_ChampionsRoom_Text_Defeat
# 138 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	return
# 139 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"

# 140 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
PokemonLeague_ChampionsRoom_EventScript_RematchBulbasaur::
# 141 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_CHAMPION_REMATCH_BULBASAUR, PokemonLeague_ChampionsRoom_Text_Defeat
# 142 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	return
# 143 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"

# 144 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
PokemonLeague_ChampionsRoom_EventScript_RematchCharmander::
# 145 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_CHAMPION_REMATCH_CHARMANDER, PokemonLeague_ChampionsRoom_Text_Defeat
# 146 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	return
# 147 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"

# 148 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
PokemonLeague_ChampionsRoom_Movement_PlayerEnter::
# 149 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	walk_up
# 150 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	walk_up
# 151 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	walk_up
# 152 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	walk_up
# 153 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	walk_up
# 154 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	walk_up
# 155 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	walk_up
# 156 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	walk_up
# 157 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	walk_up
# 158 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	walk_up
# 159 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	step_end
# 160 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"

# 161 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
PokemonLeague_ChampionsRoom_Movement_PlayerExit::
# 162 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	delay_16
# 163 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	walk_left
# 164 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	walk_up
# 165 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	walk_up
# 166 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	walk_up
# 167 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	walk_right
# 168 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	walk_up
# 169 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	walk_up
# 170 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	walk_up
# 171 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	walk_up
# 172 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	delay_8
# 173 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	set_invisible
# 174 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	step_end
# 175 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"

# 176 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
PokemonLeague_ChampionsRoom_Movement_PlayerWatchOakEnter::
# 177 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	delay_8
# 178 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	walk_in_place_faster_down
# 179 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	delay_16
# 180 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	delay_16
# 181 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	delay_16
# 182 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	delay_16
# 183 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	delay_16
# 184 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	delay_16
# 185 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	delay_16
# 186 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	walk_in_place_faster_left
# 187 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	step_end
# 188 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"

# 189 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
PokemonLeague_ChampionsRoom_Movement_OakEnter::
# 190 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	delay_16
# 191 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	delay_16
# 192 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	walk_up
# 193 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	walk_up
# 194 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	walk_up
# 195 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	walk_up
# 196 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	walk_up
# 197 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	walk_left
# 198 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	walk_up
# 199 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	walk_up
# 200 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	walk_in_place_faster_down
# 201 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	delay_16
# 202 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	step_end
# 203 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"

# 204 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
PokemonLeague_ChampionsRoom_Movement_OakExit::
# 205 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	walk_up
# 206 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	walk_up
# 207 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	walk_right
# 208 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	walk_up
# 209 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	walk_up
# 210 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	walk_up
# 211 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	walk_up
# 212 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	delay_8
# 213 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	set_invisible
# 214 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	step_end
# 215 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"

# 216 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
PokemonLeague_ChampionsRoom_Movement_RivalWatchOakEnter::
# 217 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	delay_16
# 218 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	delay_16
# 219 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	delay_16
# 220 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	delay_16
# 221 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	delay_16
# 222 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	delay_16
# 223 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	delay_16
# 224 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	delay_16
# 225 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	delay_16
# 226 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	walk_in_place_faster_left
# 227 "data/maps/PokemonLeague_ChampionsRoom/scripts.pory"
	step_end
