PokemonTech_Outside_MapScripts::
	.byte 0


PokemonTech_Outside_EventScript_Woop::
# 4 "data/maps/PokemonTech_Outside/scripts.pory"
	trainerbattle_single TRAINER_YOUNGSTER_WOOP, PokemonTech_Outside_EventScript_Woop_Text_0, PokemonTech_Outside_EventScript_Woop_Text_1
# 11 "data/maps/PokemonTech_Outside/scripts.pory"
	msgbox PokemonTech_Outside_EventScript_Woop_Text_2, MSGBOX_AUTOCLOSE
	end


PokemonTech_Outside_EventScript_Brook::
# 17 "data/maps/PokemonTech_Outside/scripts.pory"
	trainerbattle_single TRAINER_BUG_CATCHER_BROOK, PokemonTech_Outside_EventScript_Brook_Text_0, PokemonTech_Outside_EventScript_Brook_Text_1
# 20 "data/maps/PokemonTech_Outside/scripts.pory"
	msgbox PokemonTech_Outside_EventScript_Brook_Text_2, MSGBOX_AUTOCLOSE
	end


PokemonTech_Outside_EventScript_Petra::
# 26 "data/maps/PokemonTech_Outside/scripts.pory"
	trainerbattle_single TRAINER_CRUSH_GIRL_PETRA, PokemonTech_Outside_EventScript_Petra_Text_0, PokemonTech_Outside_EventScript_Petra_Text_1
# 29 "data/maps/PokemonTech_Outside/scripts.pory"
	msgbox PokemonTech_Outside_EventScript_Petra_Text_2, MSGBOX_AUTOCLOSE
	end


PokemonTech_Outside_EventScript_Aran::
# 37 "data/maps/PokemonTech_Outside/scripts.pory"
	trainerbattle_single TRAINER_PICNICKER_ARAN, PokemonTech_Outside_EventScript_Aran_Text_0, PokemonTech_Outside_EventScript_Aran_Text_1
# 41 "data/maps/PokemonTech_Outside/scripts.pory"
	msgbox PokemonTech_Outside_EventScript_Aran_Text_2, MSGBOX_AUTOCLOSE
	end


PokemonTech_Outside_EventScript_Giselle::
# 47 "data/maps/PokemonTech_Outside/scripts.pory"
	trainerbattle_single TRAINER_LASS_GISELLE, PokemonTech_Outside_EventScript_Giselle_Text_0, PokemonTech_Outside_EventScript_Giselle_Text_1, PokemonTech_Outside_EventScript_GiselleAftermath, FALSE
	end


PokemonTech_Outside_EventScript_GiselleAftermath::
# 73 "data/maps/PokemonTech_Outside/scripts.pory"
	msgbox PokemonTech_Outside_EventScript_GiselleAftermath_Text_0
# 88 "data/maps/PokemonTech_Outside/scripts.pory"
	giveitem ITEM_TM55
# 89 "data/maps/PokemonTech_Outside/scripts.pory"
	message PokemonTech_Outside_EventScript_GiselleAftermath_Text_1
# 96 "data/maps/PokemonTech_Outside/scripts.pory"
	closemessage
# 97 "data/maps/PokemonTech_Outside/scripts.pory"
	playbgm MUS_RIVAL_EXIT, 0
# 98 "data/maps/PokemonTech_Outside/scripts.pory"
	applymovement LOCALID_GISELLE, PokemonTech_Outside_EventScript_GiselleAftermath_Movement_0
# 105 "data/maps/PokemonTech_Outside/scripts.pory"
	waitmovement 0
# 106 "data/maps/PokemonTech_Outside/scripts.pory"
	removeobject LOCALID_GISELLE
# 107 "data/maps/PokemonTech_Outside/scripts.pory"
	fadedefaultbgm
	return


# 98 "data/maps/PokemonTech_Outside/scripts.pory"
PokemonTech_Outside_EventScript_GiselleAftermath_Movement_0:
# 99 "data/maps/PokemonTech_Outside/scripts.pory"
	walk_down
# 99 "data/maps/PokemonTech_Outside/scripts.pory"
	walk_down
# 100 "data/maps/PokemonTech_Outside/scripts.pory"
	walk_right
# 100 "data/maps/PokemonTech_Outside/scripts.pory"
	walk_right
# 100 "data/maps/PokemonTech_Outside/scripts.pory"
	walk_right
# 100 "data/maps/PokemonTech_Outside/scripts.pory"
	walk_right
# 100 "data/maps/PokemonTech_Outside/scripts.pory"
	walk_right
# 100 "data/maps/PokemonTech_Outside/scripts.pory"
	walk_right
# 101 "data/maps/PokemonTech_Outside/scripts.pory"
	jump_right
# 102 "data/maps/PokemonTech_Outside/scripts.pory"
	walk_right
# 102 "data/maps/PokemonTech_Outside/scripts.pory"
	walk_right
# 103 "data/maps/PokemonTech_Outside/scripts.pory"
	jump_right
	step_end

PokemonTech_Outside_EventScript_Woop_Text_0:
# 5 "data/maps/PokemonTech_Outside/scripts.pory"
	.string "A guy told me he beat a champion\n"
	.string "with only a WOOPER.\p"
	.string "I have a WOOPER! Let's test that\n"
	.string "theory with you!$"

PokemonTech_Outside_EventScript_Woop_Text_1:
# 10 "data/maps/PokemonTech_Outside/scripts.pory"
	.string "It appears I have been lied to…$"

PokemonTech_Outside_EventScript_Woop_Text_2:
# 11 "data/maps/PokemonTech_Outside/scripts.pory"
	.string "Maybe I shouldn't rely on only\n"
	.string "WOOPER then.$"

PokemonTech_Outside_EventScript_Brook_Text_0:
# 18 "data/maps/PokemonTech_Outside/scripts.pory"
	.string "Hey! Let me see your bug types!$"

PokemonTech_Outside_EventScript_Brook_Text_1:
# 19 "data/maps/PokemonTech_Outside/scripts.pory"
	.string "Just my luck!$"

PokemonTech_Outside_EventScript_Brook_Text_2:
# 20 "data/maps/PokemonTech_Outside/scripts.pory"
	.string "You must be a really strong\n"
	.string "POKéMON trainer!$"

PokemonTech_Outside_EventScript_Petra_Text_0:
# 27 "data/maps/PokemonTech_Outside/scripts.pory"
	.string "Tell me, do I look good?$"

PokemonTech_Outside_EventScript_Petra_Text_1:
# 28 "data/maps/PokemonTech_Outside/scripts.pory"
	.string "Should really work more on my looks…$"

PokemonTech_Outside_EventScript_Petra_Text_2:
# 29 "data/maps/PokemonTech_Outside/scripts.pory"
	.string "Gosh darn it!\p"
	.string "What should I do to get more\n"
	.string "attension from people?$"

PokemonTech_Outside_EventScript_Aran_Text_0:
# 38 "data/maps/PokemonTech_Outside/scripts.pory"
	.string "I am your last fight before our\n"
	.string "leader. Are you ready?$"

PokemonTech_Outside_EventScript_Aran_Text_1:
# 40 "data/maps/PokemonTech_Outside/scripts.pory"
	.string "You're more than ready!$"

PokemonTech_Outside_EventScript_Aran_Text_2:
# 41 "data/maps/PokemonTech_Outside/scripts.pory"
	.string "Never thought I'd see the day\n"
	.string "someone would have the chance…$"

PokemonTech_Outside_EventScript_Giselle_Text_0:
# 48 "data/maps/PokemonTech_Outside/scripts.pory"
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
# 66 "data/maps/PokemonTech_Outside/scripts.pory"
	.string "I… I lost?\p"
	.string "But how?$"

PokemonTech_Outside_EventScript_GiselleAftermath_Text_0:
# 73 "data/maps/PokemonTech_Outside/scripts.pory"
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
# 89 "data/maps/PokemonTech_Outside/scripts.pory"
	.string "Grah! My TM!\p"
	.string "I'll be back, whoever you are!\p"
	.string "And the next time we'll meet,\n"
	.string "I'll prove to everyone that you are\l"
	.string "nothing more than a cheat!$"
