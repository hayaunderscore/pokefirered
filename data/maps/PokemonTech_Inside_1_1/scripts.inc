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
	msgbox PokemonTech_Inside_1_1_EventScript_Joe_Text_1
# 83 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 84 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	playfanfare MUS_OBTAIN_TMHM
# 85 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	message PokemonTech_Inside_1_1_EventScript_Joe_Text_2
# 86 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	waitmessage
# 87 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	waitfanfare
# 88 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	call EventScript_RestorePrevTextColor
# 89 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	removeitem ITEM_LETTER
# 90 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	msgbox PokemonTech_Inside_1_1_EventScript_Joe_Text_3
# 94 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	closemessage
# 95 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	playse SE_BANG
# 96 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	delay 30
# 97 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	fadenewbgm MUS_ENCOUNTER_ROCKET
# 98 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	applymovement LOCALID_JOE, PokemonTech_Inside_1_1_EventScript_Joe_Movement_0
# 102 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	applymovement LOCALID_PLAYER, PokemonTech_Inside_1_1_EventScript_Joe_Movement_1
# 105 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	waitmovement 0
# 106 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	delay 40
# 107 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	msgbox PokemonTech_Inside_1_1_EventScript_Joe_Text_4
# 117 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	release
# 118 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	fadenewbgm MUS_SEVII_67
# 119 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	setflag FLAG_SCHOOL_OF_HARD_KNOCKS
	end

PokemonTech_Inside_1_1_EventScript_Joe_2:
# 72 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	msgbox PokemonTech_Inside_1_1_EventScript_Joe_Text_0
# 77 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	release
	end


# 8 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
PokemonTech_Inside_1_1_EventScript_Camper_Movement_0:
# 9 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	face_original_direction
	step_end

# 98 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
PokemonTech_Inside_1_1_EventScript_Joe_Movement_0:
# 99 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	face_down
# 100 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	emote_exclamation_mark
	step_end

# 102 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
PokemonTech_Inside_1_1_EventScript_Joe_Movement_1:
# 103 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
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
# 80 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	.string "Hi. My name is JOE.\p"
	.string "Oh? You have something for me?$"

PokemonTech_Inside_1_1_EventScript_Joe_Text_2:
# 85 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	.string "{PLAYER} delivered LETTER to JOE.$"

PokemonTech_Inside_1_1_EventScript_Joe_Text_3:
# 90 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	.string "A letter? From whom?\p"
	.string "Oh, from THE SAILOR! I knew I\n"
	.string "forgot something back home…$"

PokemonTech_Inside_1_1_EventScript_Joe_Text_4:
# 107 "data/maps/PokemonTech_Inside_1_1/scripts.pory"
	.string "Uh oh… Looks like it's break time…\p"
	.string "And that's the time SHE riles up\n"
	.string "the student body for her gain…\p"
	.string "You might wanna leave as soon\n"
	.string "as possible…\p"
	.string "Unless one of her goons are\n"
	.string "already at the door…$"
