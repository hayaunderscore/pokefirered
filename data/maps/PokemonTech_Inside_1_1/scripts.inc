PokemonTech_Inside_1_1_MapScripts::
	.byte 0


PokemonTech_Inside_1_1_EventScript_Camper::
# 4 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	lock
# 5 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	faceplayer
# 6 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	msgbox PokemonTech_Inside_1_1_EventScript_Camper_Text_0
# 8 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	applymovement LOCALID_CAMPER, PokemonTech_Inside_1_1_EventScript_Camper_Movement_0
# 11 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	waitmovement 0
# 12 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	release
	end


PokemonTech_Inside_1_1_EventScript_Picnicker::
# 17 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	lock
# 18 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	faceplayer
# 19 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	msgbox PokemonTech_Inside_1_1_EventScript_Picnicker_Text_0
# 23 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	applymovement LOCALID_PICNICKER, PokemonTech_Inside_1_1_EventScript_Camper_Movement_0
# 26 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	waitmovement 0
# 27 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	release
	end


PokemonTech_Inside_1_1_EventScript_Lass::
# 32 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	lock
# 33 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	faceplayer
# 34 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	msgbox PokemonTech_Inside_1_1_EventScript_Lass_Text_0
# 37 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	applymovement LOCALID_LASS, PokemonTech_Inside_1_1_EventScript_Camper_Movement_0
# 40 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	waitmovement 0
# 41 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	release
	end


PokemonTech_Inside_1_1_EventScript_Kid::
# 46 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	lock
# 47 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	faceplayer
# 48 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	msgbox PokemonTech_Inside_1_1_EventScript_Kid_Text_0
# 50 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	applymovement LOCALID_KID, PokemonTech_Inside_1_1_EventScript_Camper_Movement_0
# 53 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	waitmovement 0
# 54 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	release
	end


PokemonTech_Inside_1_1_EventScript_Teacher::
# 59 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	lock
# 60 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	faceplayer
# 61 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	msgbox PokemonTech_Inside_1_1_EventScript_Teacher_Text_0
# 64 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	release
	end


PokemonTech_Inside_1_1_EventScript_Joe::
# 69 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	lock
# 70 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	faceplayer
# 71 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	goto_if_set FLAG_SCHOOL_OF_HARD_KNOCKS, PokemonTech_Inside_1_1_EventScript_Joe_2
# 80 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	checktrainerflag TRAINER_LASS_GISELLE
	goto_if 1, PokemonTech_Inside_1_1_EventScript_Joe_5
# 94 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	msgbox PokemonTech_Inside_1_1_EventScript_Joe_Text_2
# 97 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 98 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	playfanfare MUS_OBTAIN_TMHM
# 99 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	message PokemonTech_Inside_1_1_EventScript_Joe_Text_3
# 100 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	waitmessage
# 101 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	waitfanfare
# 102 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	call EventScript_RestorePrevTextColor
# 103 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	removeitem ITEM_LETTER
# 104 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	msgbox PokemonTech_Inside_1_1_EventScript_Joe_Text_4
# 108 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	closemessage
# 109 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	playse SE_BANG
# 110 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	delay 30
# 111 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	fadenewbgm MUS_ENCOUNTER_ROCKET
# 112 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	applymovement LOCALID_JOE, PokemonTech_Inside_1_1_EventScript_Joe_Movement_0
# 116 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	applymovement LOCALID_PLAYER, PokemonTech_Inside_1_1_EventScript_Joe_Movement_1
# 119 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	waitmovement 0
# 120 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	delay 40
# 121 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	msgbox PokemonTech_Inside_1_1_EventScript_Joe_Text_5
# 131 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	release
# 132 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	fadenewbgm MUS_SEVII_67
# 133 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	setflag FLAG_SCHOOL_OF_HARD_KNOCKS
	end

PokemonTech_Inside_1_1_EventScript_Joe_2:
# 72 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	msgbox PokemonTech_Inside_1_1_EventScript_Joe_Text_0
# 77 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	release
	end

PokemonTech_Inside_1_1_EventScript_Joe_5:
# 81 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	msgbox PokemonTech_Inside_1_1_EventScript_Joe_Text_1
# 91 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	release
	end


# 8 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
PokemonTech_Inside_1_1_EventScript_Camper_Movement_0:
# 9 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	face_original_direction
	step_end

# 112 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
PokemonTech_Inside_1_1_EventScript_Joe_Movement_0:
# 113 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	face_down
# 114 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	emote_exclamation_mark
	step_end

# 116 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
PokemonTech_Inside_1_1_EventScript_Joe_Movement_1:
# 117 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	face_down
	step_end

PokemonTech_Inside_1_1_EventScript_Camper_Text_0:
# 6 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	.string "Hey! Quit bugging me!\n"
	.string "I'm studying!$"

PokemonTech_Inside_1_1_EventScript_Picnicker_Text_0:
# 19 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	.string "Sorry if my partner rudely told\n"
	.string "you to stop bugging him.\p"
	.string "He gets agitated way too easily.$"

PokemonTech_Inside_1_1_EventScript_Lass_Text_0:
# 34 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	.string "I'm not really sure if I'm\n"
	.string "learning any meaningful things\l"
	.string "around here…$"

PokemonTech_Inside_1_1_EventScript_Kid_Text_0:
# 48 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	.string "I like learning things!\n"
	.string "It makes my brain tingle!$"

PokemonTech_Inside_1_1_EventScript_Teacher_Text_0:
# 61 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	.string "I'm the teacher for this class.\p"
	.string "Hm? You're not from around here.$"

PokemonTech_Inside_1_1_EventScript_Joe_Text_0:
# 72 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	.string "You might wanna leave as soon\n"
	.string "as possible…\p"
	.string "Unless of course, one of her goons\n"
	.string "are already at the door…$"

PokemonTech_Inside_1_1_EventScript_Joe_Text_1:
# 81 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	.string "Oh, you defeated her?\n"
	.string "Good job.\p"
	.string "No, I do not know where she ran\n"
	.string "off to.\p"
	.string "…Hey, ain't that an S.S. TICKET?\p"
	.string "The S.S. ANNE should probably be\n"
	.string "on VERMILLION HARBOR now.$"

PokemonTech_Inside_1_1_EventScript_Joe_Text_2:
# 94 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	.string "Hi. My name is JOE.\p"
	.string "Oh? You have something for me?$"

PokemonTech_Inside_1_1_EventScript_Joe_Text_3:
# 99 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	.string "{PLAYER} delivered LETTER to JOE.$"

PokemonTech_Inside_1_1_EventScript_Joe_Text_4:
# 104 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	.string "A letter? From whom?\p"
	.string "Oh, from THE SAILOR! I knew I\n"
	.string "forgot something back home…$"

PokemonTech_Inside_1_1_EventScript_Joe_Text_5:
# 121 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	.string "Uh oh… Looks like it's break time…\p"
	.string "And that's the time SHE riles up\n"
	.string "the student body for her gain…\p"
	.string "You might wanna leave as soon\n"
	.string "as possible…\p"
	.string "Unless one of her goons are\n"
	.string "already at the door…$"
