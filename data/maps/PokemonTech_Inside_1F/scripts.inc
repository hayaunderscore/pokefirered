PokemonTech_Inside_1F_MapScripts::
# 2 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, PokemonTech_Inside_1F_EventScript_OnTransition
	.byte 0


PokemonTech_Inside_1F_EventScript_OnTransition::
# 6 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	setflag FLAG_HIDE_POKETECH_BULLY
# 8 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	goto_if_set FLAG_SCHOOL_OF_HARD_KNOCKS, PokemonTech_Inside_1F_EventScript_OnTransition_1
	return

PokemonTech_Inside_1F_EventScript_OnTransition_1:
# 9 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	clearflag FLAG_HIDE_POKETECH_BULLY
	return


PokemonTech_Inside_1F_EventScript_Nurse::
# 14 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	lock
# 15 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	faceplayer
# 16 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	call EventScript_PkmnCenterNurse
# 17 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	release
	end


PokemonTech_Inside_1F_EventScript_Youngster::
# 22 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	lock
# 23 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	faceplayer
# 24 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	goto_if_set FLAG_SCHOOL_OF_HARD_KNOCKS, PokemonTech_Inside_1F_EventScript_Youngster_2
# 30 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	msgbox PokemonTech_Inside_1F_EventScript_Youngster_Text_1
PokemonTech_Inside_1F_EventScript_Youngster_1:
# 36 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	release
	end

PokemonTech_Inside_1F_EventScript_Youngster_2:
# 25 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	msgbox PokemonTech_Inside_1F_EventScript_Youngster_Text_0
	goto PokemonTech_Inside_1F_EventScript_Youngster_1


PokemonTech_Inside_1F_EventScript_Girl::
# 41 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	lock
# 42 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	faceplayer
# 43 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	goto_if_set FLAG_SCHOOL_OF_HARD_KNOCKS, PokemonTech_Inside_1F_EventScript_Girl_2
# 50 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	msgbox PokemonTech_Inside_1F_EventScript_Girl_Text_1
PokemonTech_Inside_1F_EventScript_Girl_1:
# 57 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	release
	end

PokemonTech_Inside_1F_EventScript_Girl_2:
# 44 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	msgbox PokemonTech_Inside_1F_EventScript_Girl_Text_0
	goto PokemonTech_Inside_1F_EventScript_Girl_1


PokemonTech_Inside_1F_EventScript_OldLady::
# 62 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	lock
# 63 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	faceplayer
# 64 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	msgbox PokemonTech_Inside_1F_EventScript_OldLady_Text_0
# 69 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	release
	end


PokemonTech_Inside_1F_EventScript_UpstairsKid::
# 74 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	lock
# 75 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	faceplayer
# 76 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	msgbox PokemonTech_Inside_1F_EventScript_UpstairsKid_Text_0
# 81 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	release
	end


PokemonTech_Inside_1F_EventScript_Lass::
# 86 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	lock
# 87 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	faceplayer
# 88 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	goto_if_set FLAG_SCHOOL_OF_HARD_KNOCKS, PokemonTech_Inside_1F_EventScript_Lass_2
# 95 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	msgbox PokemonTech_Inside_1F_EventScript_Lass_Text_1
PokemonTech_Inside_1F_EventScript_Lass_1:
# 102 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	release
	end

PokemonTech_Inside_1F_EventScript_Lass_2:
# 89 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	msgbox PokemonTech_Inside_1F_EventScript_Lass_Text_0
	goto PokemonTech_Inside_1F_EventScript_Lass_1


PokemonTech_Inside_1F_EventScript_PlaygroundSign::
# 107 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	msgbox PokemonTech_Inside_1F_EventScript_PlaygroundSign_Text_0, MSGBOX_SIGN
# 108 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	release
	end


PokemonTech_Inside_1F_EventScript_Class1_1Sign::
# 113 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	msgbox PokemonTech_Inside_1F_EventScript_Class1_1Sign_Text_0, MSGBOX_SIGN
# 114 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	release
	end


PokemonTech_Inside_1F_EventScript_Class1_2Sign::
# 119 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	msgbox PokemonTech_Inside_1F_EventScript_Class1_2Sign_Text_0, MSGBOX_SIGN
# 120 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	release
	end


PokemonTech_Inside_1F_EventScript_Bully::
# 125 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	lock
# 126 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	faceplayer
# 127 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	msgbox PokemonTech_Inside_1F_EventScript_Bully_Text_0
# 131 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	release
	end


PokemonTech_Inside_1F_EventScript_Eli::
# 136 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	trainerbattle_single TRAINER_BUG_CATCHER_ELI, PokemonTech_Inside_1F_EventScript_Eli_Text_0, PokemonTech_Inside_1F_EventScript_Eli_Text_1
# 140 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	msgbox PokemonTech_Inside_1F_EventScript_Eli_Text_2, MSGBOX_AUTOCLOSE
	end


PokemonTech_Inside_1F_EventScript_Hana::
# 146 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	trainerbattle_single TRAINER_LASS_HANA, PokemonTech_Inside_1F_EventScript_Hana_Text_0, PokemonTech_Inside_1F_EventScript_Hana_Text_1
# 150 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	msgbox PokemonTech_Inside_1F_EventScript_Hana_Text_2, MSGBOX_AUTOCLOSE
	end


PokemonTech_Inside_1F_EventScript_Youngster_Text_0:
# 25 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	.string "What's HER deal?\p"
	.string "No matter what, I won't let anyone\n"
	.string "say that my RATTATA is worthless!$"

PokemonTech_Inside_1F_EventScript_Youngster_Text_1:
# 30 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	.string "This school is awesome!\p"
	.string "With this knowledge, I can finally\n"
	.string "become the best RATTATA trainer\l"
	.string "the world has ever seen!$"

PokemonTech_Inside_1F_EventScript_Girl_Text_0:
# 44 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	.string "I'm worried about this school if a\n"
	.string "single student can lock down the\l"
	.string "entire place like this.\p"
	.string "Is she TEAM ROCKET in disguise?$"

PokemonTech_Inside_1F_EventScript_Girl_Text_1:
# 50 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	.string "Not sure what all the commotion is\n"
	.string "about with this place.\p"
	.string "I don't get it. You get to learn a\n"
	.string "lot more when you go on a POKéMON\l"
	.string "journey yourself!$"

PokemonTech_Inside_1F_EventScript_OldLady_Text_0:
# 64 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	.string "Waiting for my granddaughter to\n"
	.string "finish her classes…\p"
	.string "I don't think this school is that\n"
	.string "serious to warrant 9-5 study hours…$"

PokemonTech_Inside_1F_EventScript_UpstairsKid_Text_0:
# 76 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	.string "Sorry mate, upstairs area is still\n"
	.string "being mopped.\p"
	.string "Can't have anyone slipping and sliding\n"
	.string "now, would I?$"

PokemonTech_Inside_1F_EventScript_Lass_Text_0:
# 89 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	.string "Despite the fact that it's break time\n"
	.string "I still cannot leave from here…\p"
	.string "I can still hold on… Hoo boy……$"

PokemonTech_Inside_1F_EventScript_Lass_Text_1:
# 95 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	.string "Class is under session here!\p"
	.string "…I got too rowdy and now I'm carrying\n"
	.string "buckets of water…\p"
	.string "So heavy…$"

PokemonTech_Inside_1F_EventScript_PlaygroundSign_Text_0:
# 107 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	.string "PLAYGROUND$"

PokemonTech_Inside_1F_EventScript_Class1_1Sign_Text_0:
# 113 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	.string "CLASS 1-1$"

PokemonTech_Inside_1F_EventScript_Class1_2Sign_Text_0:
# 119 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	.string "CLASS 1-2$"

PokemonTech_Inside_1F_EventScript_Bully_Text_0:
# 127 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	.string "HALT!\p"
	.string "You are forbidden from leaving unless\n"
	.string "we get permission to by the boss!$"

PokemonTech_Inside_1F_EventScript_Eli_Text_0:
# 137 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	.string "Fear the wrath of my bug-type\n"
	.string "POKéMON!$"

PokemonTech_Inside_1F_EventScript_Eli_Text_1:
# 139 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	.string "Aw shucks…$"

PokemonTech_Inside_1F_EventScript_Eli_Text_2:
# 140 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	.string "Could you not say to people that I\n"
	.string "lost to you?$"

PokemonTech_Inside_1F_EventScript_Hana_Text_0:
# 147 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	.string "My POKéMON are cute! Wanna fight\n"
	.string "with them?$"

PokemonTech_Inside_1F_EventScript_Hana_Text_1:
# 149 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	.string "Meanie!$"

PokemonTech_Inside_1F_EventScript_Hana_Text_2:
# 150 "data/maps/PokemonTech_Inside_1F/scripts.pory"
	.string "I should've probably listened\n"
	.string "to my instructors more…$"
