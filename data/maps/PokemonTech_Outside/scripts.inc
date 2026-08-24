PokemonTech_Outside_MapScripts::
# 2 "data/maps/PokemonTech_Outside/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, PokemonTech_Outside_EventScript_OnTransition
	.byte 0


PokemonTech_Outside_EventScript_OnTransition::
# 6 "data/maps/PokemonTech_Outside/scripts.pory"
	checktrainerflag TRAINER_LASS_GISELLE
	goto_if 1, PokemonTech_Outside_EventScript_OnTransition_2
# 11 "data/maps/PokemonTech_Outside/scripts.pory"
	setflag FLAG_HIDE_POKETECH_BULLY
# 12 "data/maps/PokemonTech_Outside/scripts.pory"
	goto_if_set FLAG_SCHOOL_OF_HARD_KNOCKS, PokemonTech_Outside_EventScript_OnTransition_4
	return

PokemonTech_Outside_EventScript_OnTransition_2:
# 7 "data/maps/PokemonTech_Outside/scripts.pory"
	clearflag FLAG_SCHOOL_OF_HARD_KNOCKS
# 8 "data/maps/PokemonTech_Outside/scripts.pory"
	setflag FLAG_HIDE_POKETECH_BULLY
	return

PokemonTech_Outside_EventScript_OnTransition_4:
# 13 "data/maps/PokemonTech_Outside/scripts.pory"
	clearflag FLAG_HIDE_POKETECH_BULLY
	return


PokemonTech_Outside_EventScript_Woop::
# 18 "data/maps/PokemonTech_Outside/scripts.pory"
	trainerbattle_single TRAINER_YOUNGSTER_WOOP, PokemonTech_Outside_EventScript_Woop_Text_0, PokemonTech_Outside_EventScript_Woop_Text_1
# 25 "data/maps/PokemonTech_Outside/scripts.pory"
	msgbox PokemonTech_Outside_EventScript_Woop_Text_2, MSGBOX_AUTOCLOSE
	end


PokemonTech_Outside_EventScript_Brook::
# 31 "data/maps/PokemonTech_Outside/scripts.pory"
	trainerbattle_single TRAINER_BUG_CATCHER_BROOK, PokemonTech_Outside_EventScript_Brook_Text_0, PokemonTech_Outside_EventScript_Brook_Text_1
# 34 "data/maps/PokemonTech_Outside/scripts.pory"
	msgbox PokemonTech_Outside_EventScript_Brook_Text_2, MSGBOX_AUTOCLOSE
	end


PokemonTech_Outside_EventScript_Petra::
# 40 "data/maps/PokemonTech_Outside/scripts.pory"
	trainerbattle_single TRAINER_LASS_PETRA, PokemonTech_Outside_EventScript_Petra_Text_0, PokemonTech_Outside_EventScript_Petra_Text_1
# 43 "data/maps/PokemonTech_Outside/scripts.pory"
	msgbox PokemonTech_Outside_EventScript_Petra_Text_2, MSGBOX_AUTOCLOSE
	end


PokemonTech_Outside_EventScript_Aran::
# 51 "data/maps/PokemonTech_Outside/scripts.pory"
	trainerbattle_single TRAINER_PICNICKER_ARAN, PokemonTech_Outside_EventScript_Aran_Text_0, PokemonTech_Outside_EventScript_Aran_Text_1
# 55 "data/maps/PokemonTech_Outside/scripts.pory"
	msgbox PokemonTech_Outside_EventScript_Aran_Text_2, MSGBOX_AUTOCLOSE
	end


PokemonTech_Outside_EventScript_Giselle::
# 61 "data/maps/PokemonTech_Outside/scripts.pory"
	trainerbattle_single TRAINER_LASS_GISELLE, PokemonTech_Outside_EventScript_Giselle_Text_0, PokemonTech_Outside_EventScript_Giselle_Text_1, PokemonTech_Outside_EventScript_GiselleAftermath, FALSE
	end


PokemonTech_Outside_EventScript_GiselleAftermath::
# 87 "data/maps/PokemonTech_Outside/scripts.pory"
	msgbox PokemonTech_Outside_EventScript_GiselleAftermath_Text_0
# 102 "data/maps/PokemonTech_Outside/scripts.pory"
	giveitem ITEM_TM55
# 103 "data/maps/PokemonTech_Outside/scripts.pory"
	msgbox PokemonTech_Outside_EventScript_GiselleAftermath_Text_1
# 110 "data/maps/PokemonTech_Outside/scripts.pory"
	closemessage
# 111 "data/maps/PokemonTech_Outside/scripts.pory"
	playbgm MUS_RIVAL_EXIT, 0
# 112 "data/maps/PokemonTech_Outside/scripts.pory"
	applymovement LOCALID_GISELLE, PokemonTech_Outside_EventScript_GiselleAftermath_Movement_0
# 119 "data/maps/PokemonTech_Outside/scripts.pory"
	waitmovement 0
# 120 "data/maps/PokemonTech_Outside/scripts.pory"
	removeobject LOCALID_GISELLE
# 121 "data/maps/PokemonTech_Outside/scripts.pory"
	clearflag FLAG_SCHOOL_OF_HARD_KNOCKS
# 122 "data/maps/PokemonTech_Outside/scripts.pory"
	clearflag FLAG_SS_ANNE_DELAYED
# 123 "data/maps/PokemonTech_Outside/scripts.pory"
	clearflag FLAG_DELIVERING_SS_ANNE_LETTER
# 124 "data/maps/PokemonTech_Outside/scripts.pory"
	fadedefaultbgm
	return


PokemonTech_Outside_EventScript_Sign::
# 128 "data/maps/PokemonTech_Outside/scripts.pory"
	msgbox PokemonTech_Outside_EventScript_Sign_Text_0, MSGBOX_SIGN
	return


# 112 "data/maps/PokemonTech_Outside/scripts.pory"
PokemonTech_Outside_EventScript_GiselleAftermath_Movement_0:
# 113 "data/maps/PokemonTech_Outside/scripts.pory"
	walk_down
# 113 "data/maps/PokemonTech_Outside/scripts.pory"
	walk_down
# 114 "data/maps/PokemonTech_Outside/scripts.pory"
	walk_right
# 114 "data/maps/PokemonTech_Outside/scripts.pory"
	walk_right
# 114 "data/maps/PokemonTech_Outside/scripts.pory"
	walk_right
# 114 "data/maps/PokemonTech_Outside/scripts.pory"
	walk_right
# 114 "data/maps/PokemonTech_Outside/scripts.pory"
	walk_right
# 114 "data/maps/PokemonTech_Outside/scripts.pory"
	walk_right
# 115 "data/maps/PokemonTech_Outside/scripts.pory"
	jump_2_right
# 116 "data/maps/PokemonTech_Outside/scripts.pory"
	walk_right
# 116 "data/maps/PokemonTech_Outside/scripts.pory"
	walk_right
# 117 "data/maps/PokemonTech_Outside/scripts.pory"
	jump_2_right
	step_end

PokemonTech_Outside_EventScript_Woop_Text_0:
# 19 "data/maps/PokemonTech_Outside/scripts.pory"
	.string "A guy told me he beat a champion\n"
	.string "with only a WOOPER.\p"
	.string "I have a WOOPER! Let's test that\n"
	.string "theory with you!$"

PokemonTech_Outside_EventScript_Woop_Text_1:
# 24 "data/maps/PokemonTech_Outside/scripts.pory"
	.string "It appears I have been lied to…$"

PokemonTech_Outside_EventScript_Woop_Text_2:
# 25 "data/maps/PokemonTech_Outside/scripts.pory"
	.string "Maybe I shouldn't rely on only\n"
	.string "WOOPER then.$"

PokemonTech_Outside_EventScript_Brook_Text_0:
# 32 "data/maps/PokemonTech_Outside/scripts.pory"
	.string "Hey! Let me see your bug types!$"

PokemonTech_Outside_EventScript_Brook_Text_1:
# 33 "data/maps/PokemonTech_Outside/scripts.pory"
	.string "Just my luck!$"

PokemonTech_Outside_EventScript_Brook_Text_2:
# 34 "data/maps/PokemonTech_Outside/scripts.pory"
	.string "You must be a really strong\n"
	.string "POKéMON trainer!$"

PokemonTech_Outside_EventScript_Petra_Text_0:
# 41 "data/maps/PokemonTech_Outside/scripts.pory"
	.string "Tell me, do I look beautiful?$"

PokemonTech_Outside_EventScript_Petra_Text_1:
# 42 "data/maps/PokemonTech_Outside/scripts.pory"
	.string "Tell me!$"

PokemonTech_Outside_EventScript_Petra_Text_2:
# 43 "data/maps/PokemonTech_Outside/scripts.pory"
	.string "Gosh darn it!\p"
	.string "What should I do to get more\n"
	.string "attension from people?$"

PokemonTech_Outside_EventScript_Aran_Text_0:
# 52 "data/maps/PokemonTech_Outside/scripts.pory"
	.string "I am your last fight before our\n"
	.string "leader. Are you ready?$"

PokemonTech_Outside_EventScript_Aran_Text_1:
# 54 "data/maps/PokemonTech_Outside/scripts.pory"
	.string "You're more than ready!$"

PokemonTech_Outside_EventScript_Aran_Text_2:
# 55 "data/maps/PokemonTech_Outside/scripts.pory"
	.string "Never thought I'd see the day\n"
	.string "someone would have the chance…$"

PokemonTech_Outside_EventScript_Giselle_Text_0:
# 62 "data/maps/PokemonTech_Outside/scripts.pory"
	.string "Ohohoho!\n"
	.string "And who are you?\p"
	.string "A travelling, losing, POKéMON\n"
	.string "trainer?\p"
	.string "How's your badge collection looking,\n"
	.string "huh?\p"
	.string "Heh, unlike you mon chéri, I have\n"
	.string "no need for those filmsy badges!\p"
	.string "Here in POKéMON TECH, we battle\n"
	.string "with the most accurate simulations\l"
	.string "possible!\p"
	.string "It's time to show you what a REAL\n"
	.string "trainer looks like!$"

PokemonTech_Outside_EventScript_Giselle_Text_1:
# 80 "data/maps/PokemonTech_Outside/scripts.pory"
	.string "I… I lost?\p"
	.string "But how?$"

PokemonTech_Outside_EventScript_GiselleAftermath_Text_0:
# 87 "data/maps/PokemonTech_Outside/scripts.pory"
	.string "How…\p"
	.string "How… did I lose?\p"
	.string "It… it was perfect!\n"
	.string "The simulations said so!\p"
	.string "You… you…\p"
	.string "You cheated!\n"
	.string "You couldn't have beaten me!\p"
	.string "You ruined everything!\p"
	.string "Ah!$"

PokemonTech_Outside_EventScript_GiselleAftermath_Text_1:
# 103 "data/maps/PokemonTech_Outside/scripts.pory"
	.string "Grah! My TM!\p"
	.string "I'll be back, whoever you are!\p"
	.string "And the next time we'll meet,\n"
	.string "I'll prove to everyone that you are\l"
	.string "nothing more than a cheat!$"

PokemonTech_Outside_EventScript_Sign_Text_0:
# 128 "data/maps/PokemonTech_Outside/scripts.pory"
	.string "Learn about POKéMON!\n"
	.string "POKéMON TECHNICAL INSTITUTE$"
