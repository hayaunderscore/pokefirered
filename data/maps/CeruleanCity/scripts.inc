# 1 "data/maps/CeruleanCity/scripts.pory"

# 2 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_MapScripts::
# 3 "data/maps/CeruleanCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCity_OnTransition
# 4 "data/maps/CeruleanCity/scripts.pory"
	.byte 0
# 5 "data/maps/CeruleanCity/scripts.pory"

# 6 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_OnTransition::
# 7 "data/maps/CeruleanCity/scripts.pory"
	setworldmapflag FLAG_WORLD_MAP_CERULEAN_CITY
# 8 "data/maps/CeruleanCity/scripts.pory"
	call_if_unset FLAG_GOT_SS_TICKET, CeruleanCity_EventScript_BlockExits
# 9 "data/maps/CeruleanCity/scripts.pory"
	end
# 10 "data/maps/CeruleanCity/scripts.pory"

# 11 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_BlockExits::
# 12 "data/maps/CeruleanCity/scripts.pory"
	setobjectxyperm LOCALID_CERULEAN_POLICEMAN, 30, 12
# 13 "data/maps/CeruleanCity/scripts.pory"
	setobjectxyperm LOCALID_CERULEAN_SLOWBRO, 26, 31
# 14 "data/maps/CeruleanCity/scripts.pory"
	setobjectxyperm LOCALID_CERULEAN_LASS, 27, 31
# 15 "data/maps/CeruleanCity/scripts.pory"
	return
# 16 "data/maps/CeruleanCity/scripts.pory"

# 17 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_RivalTriggerLeft::
# 18 "data/maps/CeruleanCity/scripts.pory"
	lockall
# 19 "data/maps/CeruleanCity/scripts.pory"
	setvar VAR_TEMP_1, 0
# 20 "data/maps/CeruleanCity/scripts.pory"
	goto CeruleanCity_EventScript_Rival
# 21 "data/maps/CeruleanCity/scripts.pory"
	end
# 22 "data/maps/CeruleanCity/scripts.pory"

# 23 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_RivalTriggerMid::
# 24 "data/maps/CeruleanCity/scripts.pory"
	lockall
# 25 "data/maps/CeruleanCity/scripts.pory"
	setvar VAR_TEMP_1, 1
# 26 "data/maps/CeruleanCity/scripts.pory"
	setobjectxyperm LOCALID_CERULEAN_RIVAL, 23, 0
# 27 "data/maps/CeruleanCity/scripts.pory"
	goto CeruleanCity_EventScript_Rival
# 28 "data/maps/CeruleanCity/scripts.pory"
	end
# 29 "data/maps/CeruleanCity/scripts.pory"

# 30 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_RivalTriggerRight::
# 31 "data/maps/CeruleanCity/scripts.pory"
	lockall
# 32 "data/maps/CeruleanCity/scripts.pory"
	setvar VAR_TEMP_1, 2
# 33 "data/maps/CeruleanCity/scripts.pory"
	setobjectxyperm LOCALID_CERULEAN_RIVAL, 24, 0
# 34 "data/maps/CeruleanCity/scripts.pory"
	goto CeruleanCity_EventScript_Rival
# 35 "data/maps/CeruleanCity/scripts.pory"
	end
# 36 "data/maps/CeruleanCity/scripts.pory"

# 37 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_Rival::
# 38 "data/maps/CeruleanCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 39 "data/maps/CeruleanCity/scripts.pory"
	setvar VAR_MAP_SCENE_ROUTE22, 2
# 40 "data/maps/CeruleanCity/scripts.pory"
	playbgm MUS_ENCOUNTER_RIVAL, 0
# 41 "data/maps/CeruleanCity/scripts.pory"
	addobject LOCALID_CERULEAN_RIVAL
# 42 "data/maps/CeruleanCity/scripts.pory"
	applymovement LOCALID_CERULEAN_RIVAL, CeruleanCity_Movement_RivalEnter
# 43 "data/maps/CeruleanCity/scripts.pory"
	waitmovement 0
# 44 "data/maps/CeruleanCity/scripts.pory"
	msgbox CeruleanCity_Text_RivalIntro
# 45 "data/maps/CeruleanCity/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_CERULEAN_RIVAL
# 46 "data/maps/CeruleanCity/scripts.pory"
	call_if_eq VAR_STARTER_MON, 2, CeruleanCity_EventScript_RivalSquirtle
# 47 "data/maps/CeruleanCity/scripts.pory"
	call_if_eq VAR_STARTER_MON, 1, CeruleanCity_EventScript_RivalBulbasaur
# 48 "data/maps/CeruleanCity/scripts.pory"
	call_if_eq VAR_STARTER_MON, 0, CeruleanCity_EventScript_RivalCharmander
# 49 "data/maps/CeruleanCity/scripts.pory"
	famechecker FAMECHECKER_BILL, 0
# 50 "data/maps/CeruleanCity/scripts.pory"
	msgbox CeruleanCity_Text_RivalPostBattle
# 51 "data/maps/CeruleanCity/scripts.pory"
	closemessage
# 52 "data/maps/CeruleanCity/scripts.pory"
	playbgm MUS_RIVAL_EXIT, 0
# 53 "data/maps/CeruleanCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, CeruleanCity_EventScript_RivalStartExit
# 54 "data/maps/CeruleanCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, CeruleanCity_EventScript_RivalStartExit
# 55 "data/maps/CeruleanCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, CeruleanCity_EventScript_RivalStartExitRight
# 56 "data/maps/CeruleanCity/scripts.pory"
	msgbox CeruleanCity_Text_OhRightLittlePresentAsFavor
# 57 "data/maps/CeruleanCity/scripts.pory"
	setvar VAR_MAP_SCENE_CERULEAN_CITY_RIVAL, 1
# 58 "data/maps/CeruleanCity/scripts.pory"
	setflag FLAG_GOT_FAME_CHECKER
# 59 "data/maps/CeruleanCity/scripts.pory"
	giveitem ITEM_FAME_CHECKER
# 60 "data/maps/CeruleanCity/scripts.pory"
	msgbox CeruleanCity_Text_ExplainFameCheckerSmellYa
# 61 "data/maps/CeruleanCity/scripts.pory"
	closemessage
# 62 "data/maps/CeruleanCity/scripts.pory"
	applymovement LOCALID_CERULEAN_RIVAL, CeruleanCity_Movement_RivalExit
# 63 "data/maps/CeruleanCity/scripts.pory"
	waitmovement 0
# 64 "data/maps/CeruleanCity/scripts.pory"
	fadedefaultbgm
# 65 "data/maps/CeruleanCity/scripts.pory"
	removeobject LOCALID_CERULEAN_RIVAL
# 66 "data/maps/CeruleanCity/scripts.pory"
	releaseall
# 67 "data/maps/CeruleanCity/scripts.pory"
	end
# 68 "data/maps/CeruleanCity/scripts.pory"

# 69 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_RivalSquirtle::
# 70 "data/maps/CeruleanCity/scripts.pory"
	trainerbattle_no_intro TRAINER_RIVAL_CERULEAN_SQUIRTLE, CeruleanCity_Text_RivalDefeat
# 71 "data/maps/CeruleanCity/scripts.pory"
	return
# 72 "data/maps/CeruleanCity/scripts.pory"

# 73 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_RivalBulbasaur::
# 74 "data/maps/CeruleanCity/scripts.pory"
	trainerbattle_no_intro TRAINER_RIVAL_CERULEAN_BULBASAUR, CeruleanCity_Text_RivalDefeat
# 75 "data/maps/CeruleanCity/scripts.pory"
	return
# 76 "data/maps/CeruleanCity/scripts.pory"

# 77 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_RivalCharmander::
# 78 "data/maps/CeruleanCity/scripts.pory"
	trainerbattle_no_intro TRAINER_RIVAL_CERULEAN_CHARMANDER, CeruleanCity_Text_RivalDefeat
# 79 "data/maps/CeruleanCity/scripts.pory"
	return
# 80 "data/maps/CeruleanCity/scripts.pory"

# 81 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_RivalStartExit::
# 82 "data/maps/CeruleanCity/scripts.pory"
	applymovement LOCALID_PLAYER, CeruleanCity_Movement_PlayerWatchRivalExit
# 83 "data/maps/CeruleanCity/scripts.pory"
	applymovement LOCALID_CERULEAN_RIVAL, CeruleanCity_Movement_RivalStartExit
# 84 "data/maps/CeruleanCity/scripts.pory"
	waitmovement 0
# 85 "data/maps/CeruleanCity/scripts.pory"
	return
# 86 "data/maps/CeruleanCity/scripts.pory"

# 87 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_RivalStartExitRight::
# 88 "data/maps/CeruleanCity/scripts.pory"
	applymovement LOCALID_PLAYER, CeruleanCity_Movement_PlayerWatchRivalExitRight
# 89 "data/maps/CeruleanCity/scripts.pory"
	applymovement LOCALID_CERULEAN_RIVAL, CeruleanCity_Movement_RivalStartExitRight
# 90 "data/maps/CeruleanCity/scripts.pory"
	waitmovement 0
# 91 "data/maps/CeruleanCity/scripts.pory"
	return
# 92 "data/maps/CeruleanCity/scripts.pory"

# 93 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_Movement_PlayerWatchRivalExit::
# 94 "data/maps/CeruleanCity/scripts.pory"
	delay_16
# 95 "data/maps/CeruleanCity/scripts.pory"
	delay_8
# 96 "data/maps/CeruleanCity/scripts.pory"
	walk_in_place_faster_right
# 97 "data/maps/CeruleanCity/scripts.pory"
	delay_16
# 98 "data/maps/CeruleanCity/scripts.pory"
	walk_in_place_faster_down
# 99 "data/maps/CeruleanCity/scripts.pory"
	step_end
# 100 "data/maps/CeruleanCity/scripts.pory"

# 101 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_Movement_PlayerWatchRivalExitRight::
# 102 "data/maps/CeruleanCity/scripts.pory"
	delay_16
# 103 "data/maps/CeruleanCity/scripts.pory"
	delay_8
# 104 "data/maps/CeruleanCity/scripts.pory"
	walk_in_place_faster_left
# 105 "data/maps/CeruleanCity/scripts.pory"
	delay_16
# 106 "data/maps/CeruleanCity/scripts.pory"
	walk_in_place_faster_down
# 107 "data/maps/CeruleanCity/scripts.pory"
	step_end
# 108 "data/maps/CeruleanCity/scripts.pory"

# 109 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_Movement_RivalEnter::
# 110 "data/maps/CeruleanCity/scripts.pory"
	walk_down
# 111 "data/maps/CeruleanCity/scripts.pory"
	walk_down
# 112 "data/maps/CeruleanCity/scripts.pory"
	walk_down
# 113 "data/maps/CeruleanCity/scripts.pory"
	walk_down
# 114 "data/maps/CeruleanCity/scripts.pory"
	walk_down
# 115 "data/maps/CeruleanCity/scripts.pory"
	step_end
# 116 "data/maps/CeruleanCity/scripts.pory"

# 117 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_Movement_RivalStartExit::
# 118 "data/maps/CeruleanCity/scripts.pory"
	walk_right
# 119 "data/maps/CeruleanCity/scripts.pory"
	walk_down
# 120 "data/maps/CeruleanCity/scripts.pory"
	walk_down
# 121 "data/maps/CeruleanCity/scripts.pory"
	walk_down
# 122 "data/maps/CeruleanCity/scripts.pory"
	walk_down
# 123 "data/maps/CeruleanCity/scripts.pory"
	walk_down
# 124 "data/maps/CeruleanCity/scripts.pory"
	walk_down
# 125 "data/maps/CeruleanCity/scripts.pory"
	walk_down
# 126 "data/maps/CeruleanCity/scripts.pory"
	delay_16
# 127 "data/maps/CeruleanCity/scripts.pory"
	delay_16
# 128 "data/maps/CeruleanCity/scripts.pory"
	walk_left
# 129 "data/maps/CeruleanCity/scripts.pory"
	walk_up
# 130 "data/maps/CeruleanCity/scripts.pory"
	walk_up
# 131 "data/maps/CeruleanCity/scripts.pory"
	walk_up
# 132 "data/maps/CeruleanCity/scripts.pory"
	walk_up
# 133 "data/maps/CeruleanCity/scripts.pory"
	walk_up
# 134 "data/maps/CeruleanCity/scripts.pory"
	step_end
# 135 "data/maps/CeruleanCity/scripts.pory"

# 136 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_Movement_RivalStartExitRight::
# 137 "data/maps/CeruleanCity/scripts.pory"
	walk_left
# 138 "data/maps/CeruleanCity/scripts.pory"
	walk_down
# 139 "data/maps/CeruleanCity/scripts.pory"
	walk_down
# 140 "data/maps/CeruleanCity/scripts.pory"
	walk_down
# 141 "data/maps/CeruleanCity/scripts.pory"
	walk_down
# 142 "data/maps/CeruleanCity/scripts.pory"
	walk_down
# 143 "data/maps/CeruleanCity/scripts.pory"
	walk_down
# 144 "data/maps/CeruleanCity/scripts.pory"
	walk_down
# 145 "data/maps/CeruleanCity/scripts.pory"
	delay_16
# 146 "data/maps/CeruleanCity/scripts.pory"
	delay_16
# 147 "data/maps/CeruleanCity/scripts.pory"
	walk_right
# 148 "data/maps/CeruleanCity/scripts.pory"
	walk_up
# 149 "data/maps/CeruleanCity/scripts.pory"
	walk_up
# 150 "data/maps/CeruleanCity/scripts.pory"
	walk_up
# 151 "data/maps/CeruleanCity/scripts.pory"
	walk_up
# 152 "data/maps/CeruleanCity/scripts.pory"
	walk_up
# 153 "data/maps/CeruleanCity/scripts.pory"
	step_end
# 154 "data/maps/CeruleanCity/scripts.pory"

# 155 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_Movement_RivalExit::
# 156 "data/maps/CeruleanCity/scripts.pory"
	walk_down
# 157 "data/maps/CeruleanCity/scripts.pory"
	walk_down
# 158 "data/maps/CeruleanCity/scripts.pory"
	walk_down
# 159 "data/maps/CeruleanCity/scripts.pory"
	walk_down
# 160 "data/maps/CeruleanCity/scripts.pory"
	walk_down
# 161 "data/maps/CeruleanCity/scripts.pory"
	walk_down
# 162 "data/maps/CeruleanCity/scripts.pory"
	walk_down
# 163 "data/maps/CeruleanCity/scripts.pory"
	step_end
# 164 "data/maps/CeruleanCity/scripts.pory"

# 165 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_Grunt::
# 166 "data/maps/CeruleanCity/scripts.pory"
	lock
# 167 "data/maps/CeruleanCity/scripts.pory"
	faceplayer
# 168 "data/maps/CeruleanCity/scripts.pory"
	goto_if_defeated TRAINER_TEAM_ROCKET_GRUNT_5, CeruleanCity_EventScript_GruntDefeated
# 169 "data/maps/CeruleanCity/scripts.pory"
	message CeruleanCity_Text_GruntIntro
# 170 "data/maps/CeruleanCity/scripts.pory"
	waitmessage
# 171 "data/maps/CeruleanCity/scripts.pory"
	playbgm MUS_ENCOUNTER_ROCKET, 0
# 172 "data/maps/CeruleanCity/scripts.pory"
	waitbuttonpress
# 173 "data/maps/CeruleanCity/scripts.pory"
	trainerbattle_no_intro TRAINER_TEAM_ROCKET_GRUNT_5, CeruleanCity_Text_GruntDefeat
# 174 "data/maps/CeruleanCity/scripts.pory"
	setvar VAR_MAP_SCENE_CERULEAN_CITY_ROCKET, 1
# 175 "data/maps/CeruleanCity/scripts.pory"
	goto CeruleanCity_EventScript_GruntDefeated
# 176 "data/maps/CeruleanCity/scripts.pory"
	end
# 177 "data/maps/CeruleanCity/scripts.pory"

# 178 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_GruntDefeated::
# 179 "data/maps/CeruleanCity/scripts.pory"
	msgbox CeruleanCity_Text_OkayIllReturnStolenTM
# 180 "data/maps/CeruleanCity/scripts.pory"
	checkitemspace ITEM_TM28
# 181 "data/maps/CeruleanCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_EventScript_NoRoomForTM28
# 182 "data/maps/CeruleanCity/scripts.pory"
	giveitem_msg CeruleanCity_Text_RecoveredTM28FromGrunt, ITEM_TM28
# 183 "data/maps/CeruleanCity/scripts.pory"
	msgbox CeruleanCity_Text_BetterGetMovingBye
# 184 "data/maps/CeruleanCity/scripts.pory"
	closemessage
# 185 "data/maps/CeruleanCity/scripts.pory"
	fadescreen FADE_TO_BLACK
# 186 "data/maps/CeruleanCity/scripts.pory"
	removeobject LOCALID_CERULEAN_GRUNT
# 187 "data/maps/CeruleanCity/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 188 "data/maps/CeruleanCity/scripts.pory"
	setflag FLAG_GOT_TM28_FROM_ROCKET
# 189 "data/maps/CeruleanCity/scripts.pory"
	release
# 190 "data/maps/CeruleanCity/scripts.pory"
	end
# 191 "data/maps/CeruleanCity/scripts.pory"

# 192 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_NoRoomForTM28::
# 193 "data/maps/CeruleanCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 194 "data/maps/CeruleanCity/scripts.pory"
	msgbox CeruleanCity_Text_MakeRoomForThisCantRun
# 195 "data/maps/CeruleanCity/scripts.pory"
	release
# 196 "data/maps/CeruleanCity/scripts.pory"
	end
# 197 "data/maps/CeruleanCity/scripts.pory"

# 198 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_GruntTriggerTop::
# 199 "data/maps/CeruleanCity/scripts.pory"
	lockall
# 200 "data/maps/CeruleanCity/scripts.pory"
	setvar VAR_TEMP_1, 0
# 201 "data/maps/CeruleanCity/scripts.pory"
	applymovement LOCALID_CERULEAN_GRUNT, Common_Movement_WalkInPlaceFasterUp
# 202 "data/maps/CeruleanCity/scripts.pory"
	waitmovement 0
# 203 "data/maps/CeruleanCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 204 "data/maps/CeruleanCity/scripts.pory"
	waitmovement 0
# 205 "data/maps/CeruleanCity/scripts.pory"
	goto CeruleanCity_EventScript_GruntTrigger
# 206 "data/maps/CeruleanCity/scripts.pory"
	end
# 207 "data/maps/CeruleanCity/scripts.pory"

# 208 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_GruntTriggerBottom::
# 209 "data/maps/CeruleanCity/scripts.pory"
	lockall
# 210 "data/maps/CeruleanCity/scripts.pory"
	setvar VAR_TEMP_1, 1
# 211 "data/maps/CeruleanCity/scripts.pory"
	applymovement LOCALID_CERULEAN_GRUNT, Common_Movement_WalkInPlaceFasterDown
# 212 "data/maps/CeruleanCity/scripts.pory"
	waitmovement 0
# 213 "data/maps/CeruleanCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 214 "data/maps/CeruleanCity/scripts.pory"
	waitmovement 0
# 215 "data/maps/CeruleanCity/scripts.pory"
	goto CeruleanCity_EventScript_GruntTrigger
# 216 "data/maps/CeruleanCity/scripts.pory"
	end
# 217 "data/maps/CeruleanCity/scripts.pory"

# 218 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_GruntTrigger::
# 219 "data/maps/CeruleanCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 220 "data/maps/CeruleanCity/scripts.pory"
	msgbox CeruleanCity_Text_GruntIntro
# 221 "data/maps/CeruleanCity/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_CERULEAN_GRUNT
# 222 "data/maps/CeruleanCity/scripts.pory"
	trainerbattle_no_intro TRAINER_TEAM_ROCKET_GRUNT_5, CeruleanCity_Text_GruntDefeat
# 223 "data/maps/CeruleanCity/scripts.pory"
	setvar VAR_MAP_SCENE_CERULEAN_CITY_ROCKET, 1
# 224 "data/maps/CeruleanCity/scripts.pory"
	goto CeruleanCity_EventScript_GruntDefeated
# 225 "data/maps/CeruleanCity/scripts.pory"
	end
# 226 "data/maps/CeruleanCity/scripts.pory"

# 227 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_Policeman::
# 228 "data/maps/CeruleanCity/scripts.pory"
	lock
# 229 "data/maps/CeruleanCity/scripts.pory"
	faceplayer
# 230 "data/maps/CeruleanCity/scripts.pory"
	msgbox CeruleanCity_Text_PeopleHereWereRobbed
# 231 "data/maps/CeruleanCity/scripts.pory"
	closemessage
# 232 "data/maps/CeruleanCity/scripts.pory"
	applymovement LOCALID_CERULEAN_POLICEMAN, Common_Movement_FaceOriginalDirection
# 233 "data/maps/CeruleanCity/scripts.pory"
	waitmovement 0
# 234 "data/maps/CeruleanCity/scripts.pory"
	release
# 235 "data/maps/CeruleanCity/scripts.pory"
	end
# 236 "data/maps/CeruleanCity/scripts.pory"

# 237 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_LittleBoy::
# 238 "data/maps/CeruleanCity/scripts.pory"
	lock
# 239 "data/maps/CeruleanCity/scripts.pory"
	faceplayer
# 240 "data/maps/CeruleanCity/scripts.pory"
	goto_if_set FLAG_GOT_SS_TICKET, CeruleanCity_EventScript_LittleBoySlowbroMoved
# 241 "data/maps/CeruleanCity/scripts.pory"
	msgbox CeruleanCity_Text_IfSlowbroWasntThereCouldCutTree
# 242 "data/maps/CeruleanCity/scripts.pory"
	release
# 243 "data/maps/CeruleanCity/scripts.pory"
	end
# 244 "data/maps/CeruleanCity/scripts.pory"

# 245 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_LittleBoySlowbroMoved::
# 246 "data/maps/CeruleanCity/scripts.pory"
	msgbox CeruleanCity_Text_YouCanCutDownSmallTrees
# 247 "data/maps/CeruleanCity/scripts.pory"
	release
# 248 "data/maps/CeruleanCity/scripts.pory"
	end
# 249 "data/maps/CeruleanCity/scripts.pory"

# 250 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_BaldingMan::
# 251 "data/maps/CeruleanCity/scripts.pory"
	msgbox CeruleanCity_Text_PokemonEncyclopediaAmusing, MSGBOX_NPC
# 252 "data/maps/CeruleanCity/scripts.pory"
	end
# 253 "data/maps/CeruleanCity/scripts.pory"

# 254 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_Youngster::
# 255 "data/maps/CeruleanCity/scripts.pory"
	msgbox CeruleanCity_Text_TrainerLifeIsToughIsntIt, MSGBOX_NPC
# 256 "data/maps/CeruleanCity/scripts.pory"
	end
# 257 "data/maps/CeruleanCity/scripts.pory"

# 258 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_CeruleanCaveGuard::
# 259 "data/maps/CeruleanCity/scripts.pory"
	msgbox CeruleanCity_Text_ThisIsCeruleanCave, MSGBOX_NPC
# 260 "data/maps/CeruleanCity/scripts.pory"
	end
# 261 "data/maps/CeruleanCity/scripts.pory"

# 262 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_Woman::
# 263 "data/maps/CeruleanCity/scripts.pory"
	lock
# 264 "data/maps/CeruleanCity/scripts.pory"
	faceplayer
# 265 "data/maps/CeruleanCity/scripts.pory"
	msgbox CeruleanCity_Text_WantBrightRedBicycle
# 266 "data/maps/CeruleanCity/scripts.pory"
	closemessage
# 267 "data/maps/CeruleanCity/scripts.pory"
	applymovement LOCALID_CERULEAN_WOMAN, Common_Movement_FaceOriginalDirection
# 268 "data/maps/CeruleanCity/scripts.pory"
	waitmovement 0
# 269 "data/maps/CeruleanCity/scripts.pory"
	release
# 270 "data/maps/CeruleanCity/scripts.pory"
	end
# 271 "data/maps/CeruleanCity/scripts.pory"

# 272 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_Lass::
# 273 "data/maps/CeruleanCity/scripts.pory"
	lock
# 274 "data/maps/CeruleanCity/scripts.pory"
	random 3
# 275 "data/maps/CeruleanCity/scripts.pory"
	copyvar VAR_0x8008, VAR_RESULT
# 276 "data/maps/CeruleanCity/scripts.pory"
	call_if_eq VAR_0x8008, 0, CeruleanCity_EventScript_SlowbroCommand1
# 277 "data/maps/CeruleanCity/scripts.pory"
	call_if_eq VAR_0x8008, 1, CeruleanCity_EventScript_SlowbroCommand2
# 278 "data/maps/CeruleanCity/scripts.pory"
	call_if_eq VAR_0x8008, 2, CeruleanCity_EventScript_SlowbroCommand3
# 279 "data/maps/CeruleanCity/scripts.pory"
	waitmessage
# 280 "data/maps/CeruleanCity/scripts.pory"
	delay 40
# 281 "data/maps/CeruleanCity/scripts.pory"
	playse SE_PIN
# 282 "data/maps/CeruleanCity/scripts.pory"
	applymovement LOCALID_CERULEAN_SLOWBRO, Common_Movement_QuestionMark
# 283 "data/maps/CeruleanCity/scripts.pory"
	waitmovement 0
# 284 "data/maps/CeruleanCity/scripts.pory"
	delay 30
# 285 "data/maps/CeruleanCity/scripts.pory"
	call_if_eq VAR_0x8008, 0, CeruleanCity_EventScript_SlowbroFailed1
# 286 "data/maps/CeruleanCity/scripts.pory"
	call_if_eq VAR_0x8008, 1, CeruleanCity_EventScript_SlowbroFailed2
# 287 "data/maps/CeruleanCity/scripts.pory"
	call_if_eq VAR_0x8008, 2, CeruleanCity_EventScript_SlowbroFailed3
# 288 "data/maps/CeruleanCity/scripts.pory"
	release
# 289 "data/maps/CeruleanCity/scripts.pory"
	end
# 290 "data/maps/CeruleanCity/scripts.pory"

# 291 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_SlowbroCommand1::
# 292 "data/maps/CeruleanCity/scripts.pory"
	message CeruleanCity_Text_SlowbroUseSonicboom
# 293 "data/maps/CeruleanCity/scripts.pory"
	return
# 294 "data/maps/CeruleanCity/scripts.pory"

# 295 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_SlowbroCommand2::
# 296 "data/maps/CeruleanCity/scripts.pory"
	message CeruleanCity_Text_SlowbroPunch
# 297 "data/maps/CeruleanCity/scripts.pory"
	return
# 298 "data/maps/CeruleanCity/scripts.pory"

# 299 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_SlowbroCommand3::
# 300 "data/maps/CeruleanCity/scripts.pory"
	message CeruleanCity_Text_SlowbroWithdraw
# 301 "data/maps/CeruleanCity/scripts.pory"
	return
# 302 "data/maps/CeruleanCity/scripts.pory"

# 303 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_SlowbroFailed1::
# 304 "data/maps/CeruleanCity/scripts.pory"
	msgbox CeruleanCity_Text_SlowbroPayAttention
# 305 "data/maps/CeruleanCity/scripts.pory"
	return
# 306 "data/maps/CeruleanCity/scripts.pory"

# 307 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_SlowbroFailed2::
# 308 "data/maps/CeruleanCity/scripts.pory"
	msgbox CeruleanCity_Text_NoYouBlewItAgain
# 309 "data/maps/CeruleanCity/scripts.pory"
	return
# 310 "data/maps/CeruleanCity/scripts.pory"

# 311 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_SlowbroFailed3::
# 312 "data/maps/CeruleanCity/scripts.pory"
	msgbox CeruleanCity_Text_HardToControlMonsObedience
# 313 "data/maps/CeruleanCity/scripts.pory"
	return
# 314 "data/maps/CeruleanCity/scripts.pory"

# 315 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_Slowbro::
# 316 "data/maps/CeruleanCity/scripts.pory"
	lock
# 317 "data/maps/CeruleanCity/scripts.pory"
	random 4
# 318 "data/maps/CeruleanCity/scripts.pory"
	copyvar VAR_0x8008, VAR_RESULT
# 319 "data/maps/CeruleanCity/scripts.pory"
	call_if_eq VAR_0x8008, 0, CeruleanCity_EventScript_SlowbroText1
# 320 "data/maps/CeruleanCity/scripts.pory"
	call_if_eq VAR_0x8008, 1, CeruleanCity_EventScript_SlowbroText2
# 321 "data/maps/CeruleanCity/scripts.pory"
	call_if_eq VAR_0x8008, 2, CeruleanCity_EventScript_SlowbroText3
# 322 "data/maps/CeruleanCity/scripts.pory"
	call_if_eq VAR_0x8008, 3, CeruleanCity_EventScript_SlowbroText4
# 323 "data/maps/CeruleanCity/scripts.pory"
	release
# 324 "data/maps/CeruleanCity/scripts.pory"
	end
# 325 "data/maps/CeruleanCity/scripts.pory"

# 326 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_SlowbroText1::
# 327 "data/maps/CeruleanCity/scripts.pory"
	msgbox CeruleanCity_Text_SlowbroTookSnooze
# 328 "data/maps/CeruleanCity/scripts.pory"
	return
# 329 "data/maps/CeruleanCity/scripts.pory"

# 330 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_SlowbroText2::
# 331 "data/maps/CeruleanCity/scripts.pory"
	msgbox CeruleanCity_Text_SlowbroLoafingAround
# 332 "data/maps/CeruleanCity/scripts.pory"
	return
# 333 "data/maps/CeruleanCity/scripts.pory"

# 334 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_SlowbroText3::
# 335 "data/maps/CeruleanCity/scripts.pory"
	msgbox CeruleanCity_Text_SlowbroTurnedAway
# 336 "data/maps/CeruleanCity/scripts.pory"
	return
# 337 "data/maps/CeruleanCity/scripts.pory"

# 338 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_SlowbroText4::
# 339 "data/maps/CeruleanCity/scripts.pory"
	msgbox CeruleanCity_Text_SlowbroIgnoredOrders
# 340 "data/maps/CeruleanCity/scripts.pory"
	return
# 341 "data/maps/CeruleanCity/scripts.pory"

# 342 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_CitySign::
# 343 "data/maps/CeruleanCity/scripts.pory"
	msgbox CeruleanCity_Text_CitySign, MSGBOX_SIGN
# 344 "data/maps/CeruleanCity/scripts.pory"
	end
# 345 "data/maps/CeruleanCity/scripts.pory"

# 346 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_TrainerTips::
# 347 "data/maps/CeruleanCity/scripts.pory"
	msgbox CeruleanCity_Text_TrainerTipsHeldItems, MSGBOX_SIGN
# 348 "data/maps/CeruleanCity/scripts.pory"
	end
# 349 "data/maps/CeruleanCity/scripts.pory"

# 350 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_BikeShopSign::
# 351 "data/maps/CeruleanCity/scripts.pory"
	msgbox CeruleanCity_Text_BikeShopSign, MSGBOX_SIGN
# 352 "data/maps/CeruleanCity/scripts.pory"
	end
# 353 "data/maps/CeruleanCity/scripts.pory"

# 354 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_GymSign::
# 355 "data/maps/CeruleanCity/scripts.pory"
	lockall
# 356 "data/maps/CeruleanCity/scripts.pory"
	famechecker FAMECHECKER_MISTY, 0
# 357 "data/maps/CeruleanCity/scripts.pory"
	msgbox CeruleanCity_Text_GymSign
# 358 "data/maps/CeruleanCity/scripts.pory"
	releaseall
# 359 "data/maps/CeruleanCity/scripts.pory"
	end
