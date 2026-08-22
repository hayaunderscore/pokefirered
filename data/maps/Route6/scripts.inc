# 1 "data/maps/Route6/scripts.pory"

# 2 "data/maps/Route6/scripts.pory"
Route6_MapScripts::
# 3 "data/maps/Route6/scripts.pory"
	.byte 0
# 4 "data/maps/Route6/scripts.pory"

# 5 "data/maps/Route6/scripts.pory"
Route6_EventScript_UndergroundPathSign::
# 6 "data/maps/Route6/scripts.pory"
	msgbox Route6_Text_UndergroundPathSign, MSGBOX_SIGN
# 7 "data/maps/Route6/scripts.pory"
	end

Route6_EventScript_SaffronSign::
# 11 "data/maps/Route6/scripts.pory"
	msgbox Route6_EventScript_SaffronSign_Text_0, MSGBOX_SIGN
	end


Route6_EventScript_PokemonTech_GuardScript::
# 21 "data/maps/Route6/scripts.pory"
	compare VAR_MAP_SCENE_POKETECH_GUARD, 1
	goto_if_eq Route6_EventScript_PokemonTech_GuardScript_2
# 28 "data/maps/Route6/scripts.pory"
	goto_if_unset FLAG_DELIVERING_SS_ANNE_LETTER, Route6_EventScript_PokemonTech_GuardScript_5
# 43 "data/maps/Route6/scripts.pory"
	lockall
# 44 "data/maps/Route6/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 45 "data/maps/Route6/scripts.pory"
	msgbox Route6_EventScript_PokemonTech_GuardScript_Text_2
# 52 "data/maps/Route6/scripts.pory"
	setvar VAR_MAP_SCENE_POKETECH_GUARD, 1
# 53 "data/maps/Route6/scripts.pory"
	releaseall
	return

Route6_EventScript_PokemonTech_GuardScript_2:
# 22 "data/maps/Route6/scripts.pory"
	lockall
# 23 "data/maps/Route6/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 24 "data/maps/Route6/scripts.pory"
	msgbox Route6_EventScript_PokemonTech_GuardScript_Text_0
# 25 "data/maps/Route6/scripts.pory"
	releaseall
	return

Route6_EventScript_PokemonTech_GuardScript_5:
# 29 "data/maps/Route6/scripts.pory"
	lockall
# 30 "data/maps/Route6/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 31 "data/maps/Route6/scripts.pory"
	msgbox Route6_EventScript_PokemonTech_GuardScript_Text_1
# 39 "data/maps/Route6/scripts.pory"
	releaseall
# 40 "data/maps/Route6/scripts.pory"
	applymovement LOCALID_POKETECH_GUARD, Common_Movement_FaceOriginalDirection
	return


Route6_EventScript_PokemonTech_Guard::
# 57 "data/maps/Route6/scripts.pory"
	faceplayer
# 58 "data/maps/Route6/scripts.pory"
	call Route6_EventScript_PokemonTech_GuardScript
	end


Route6_EventScript_PokemonTech_GuardTrigger::
# 63 "data/maps/Route6/scripts.pory"
	call Route6_EventScript_PokemonTech_GuardScript
# 64 "data/maps/Route6/scripts.pory"
	goto_if_unset FLAG_DELIVERING_SS_ANNE_LETTER, Route6_EventScript_PokemonTech_GuardTrigger_2
Route6_EventScript_PokemonTech_GuardTrigger_1:
	end

Route6_EventScript_PokemonTech_GuardTrigger_2:
# 65 "data/maps/Route6/scripts.pory"
	applymovement LOCALID_PLAYER, Route6_EventScript_PokemonTech_GuardTrigger_Movement_0
	goto Route6_EventScript_PokemonTech_GuardTrigger_1


# 65 "data/maps/Route6/scripts.pory"
Route6_EventScript_PokemonTech_GuardTrigger_Movement_0:
# 66 "data/maps/Route6/scripts.pory"
	walk_right
	step_end

Route6_EventScript_SaffronSign_Text_0:
# 11 "data/maps/Route6/scripts.pory"
	.string "ROUTE 6\n"
	.string "SAFFRON CITY - VERMILLION CITY\p"
	.string "{UP_ARROW} SAFFRON CITY\n"
	.string "{LEFT_ARROW} POKéMON TECH\l"
	.string "{DOWN_ARROW} VERMILLION CITY$"

Route6_EventScript_PokemonTech_GuardScript_Text_0:
# 24 "data/maps/Route6/scripts.pory"
	.string "Hi, how's it going?$"

Route6_EventScript_PokemonTech_GuardScript_Text_1:
# 31 "data/maps/Route6/scripts.pory"
	.string "I'm on guard duty.\n"
	.string "Are you a student?\p"
	.string "…No?\p"
	.string "I'm sorry, but unless you're a\n"
	.string "relative, I can't allow you to go\l"
	.string "any further.$"

Route6_EventScript_PokemonTech_GuardScript_Text_2:
# 45 "data/maps/Route6/scripts.pory"
	.string "I'm on guard duty.\n"
	.string "Are you a student?\p"
	.string "…You have a letter to send to\n"
	.string "someone here?\p"
	.string "Sure, you can go on through.$"
