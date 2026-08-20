Route25_Garden_MapScripts::
	.byte 0


Route25_Garden_EventScript_Boy::
# 4 "data/maps/Route25_Garden/scripts.pory"
	faceplayer
# 5 "data/maps/Route25_Garden/scripts.pory"
	msgbox Route25_Garden_EventScript_Boy_Text_0
# 15 "data/maps/Route25_Garden/scripts.pory"
	closemessage
# 16 "data/maps/Route25_Garden/scripts.pory"
	setobjectmovementtype LOCALID_BOY, MOVEMENT_TYPE_WANDER_AROUND
	end


Route25_Garden_EventScript_Girl::
# 21 "data/maps/Route25_Garden/scripts.pory"
	faceplayer
# 22 "data/maps/Route25_Garden/scripts.pory"
	msgbox Route25_Garden_EventScript_Girl_Text_0
# 34 "data/maps/Route25_Garden/scripts.pory"
	closemessage
# 35 "data/maps/Route25_Garden/scripts.pory"
	setobjectmovementtype LOCALID_GIRL, MOVEMENT_TYPE_WANDER_AROUND
	end


Route25_Garden_EventScript_Sign::
# 40 "data/maps/Route25_Garden/scripts.pory"
	msgbox Route25_Garden_EventScript_Sign_Text_0, MSGBOX_SIGN
# 44 "data/maps/Route25_Garden/scripts.pory"
	closemessage
	end


Route25_Garden_EventScript_Boy_Text_0:
# 5 "data/maps/Route25_Garden/scripts.pory"
	.string "I didn't know BILL started a\n"
	.string "garden around here!\l"
	.string "The flowers are quite nice.\p"
	.string "Though it is confusing when I\n"
	.string "asked BILL about it…\p"
	.string "He said that there was always a\n"
	.string "garden.\l"
	.string "Not sure how I never noticed it!$"

Route25_Garden_EventScript_Girl_Text_0:
# 22 "data/maps/Route25_Garden/scripts.pory"
	.string "I would probably be more excited\n"
	.string "being here…\p"
	.string "If the only POKéMON here weren't\n"
	.string "just MARILL and DONPHAN.\p"
	.string "No wonder I never noticed it.\n"
	.string "It's forgettable!\p"
	.string "Curious about that cave entrance\n"
	.string "at the top there…\l"
	.string "I wonder where it leads?$"

Route25_Garden_EventScript_Sign_Text_0:
# 40 "data/maps/Route25_Garden/scripts.pory"
	.string "THE GARDEN\p"
	.string "Please mind the flowers.\n"
	.string "I worked hard on them.$"
