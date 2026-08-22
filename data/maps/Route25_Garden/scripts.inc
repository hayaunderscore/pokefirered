Route25_Garden_MapScripts::
# 2 "data/maps/Route25_Garden/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route25_Garden_EventScript_OnTransition
	.byte 0


Route25_Garden_EventScript_OnTransition::
# 8 "data/maps/Route25_Garden/scripts.pory"
	setflag FLAG_ABYSS_ROUTE
# 10 "data/maps/Route25_Garden/scripts.pory"
	setflag FLAG_SS_ANNE_DELAYED
	return


Route25_Garden_EventScript_Boy::
# 14 "data/maps/Route25_Garden/scripts.pory"
	faceplayer
# 15 "data/maps/Route25_Garden/scripts.pory"
	msgbox Route25_Garden_EventScript_Boy_Text_0
# 25 "data/maps/Route25_Garden/scripts.pory"
	closemessage
# 26 "data/maps/Route25_Garden/scripts.pory"
	setobjectmovementtype LOCALID_BOY, MOVEMENT_TYPE_WANDER_AROUND
	end


Route25_Garden_EventScript_Girl::
# 31 "data/maps/Route25_Garden/scripts.pory"
	faceplayer
# 32 "data/maps/Route25_Garden/scripts.pory"
	msgbox Route25_Garden_EventScript_Girl_Text_0
# 44 "data/maps/Route25_Garden/scripts.pory"
	closemessage
# 45 "data/maps/Route25_Garden/scripts.pory"
	setobjectmovementtype LOCALID_GIRL, MOVEMENT_TYPE_WANDER_AROUND
	end


Route25_Garden_EventScript_Sign::
# 50 "data/maps/Route25_Garden/scripts.pory"
	msgbox Route25_Garden_EventScript_Sign_Text_0, MSGBOX_SIGN
# 54 "data/maps/Route25_Garden/scripts.pory"
	closemessage
	end


Route25_Garden_EventScript_Boy_Text_0:
# 15 "data/maps/Route25_Garden/scripts.pory"
	.string "I didn't know BILL started a\n"
	.string "garden around here!\l"
	.string "The flowers are quite nice.\p"
	.string "Though it is confusing when I\n"
	.string "asked BILL about it…\p"
	.string "He said that there was always a\n"
	.string "garden here.\l"
	.string "Not sure how I never noticed it!$"

Route25_Garden_EventScript_Girl_Text_0:
# 32 "data/maps/Route25_Garden/scripts.pory"
	.string "I would probably be more excited\n"
	.string "being here…\p"
	.string "If the only POKéMON here weren't\n"
	.string "just MARILL and PHANPY.\p"
	.string "No wonder I never noticed it.\n"
	.string "It's forgettable!\p"
	.string "Curious about that cave entrance\n"
	.string "at the top there…\l"
	.string "I wonder where it leads?$"

Route25_Garden_EventScript_Sign_Text_0:
# 50 "data/maps/Route25_Garden/scripts.pory"
	.string "THE GARDEN\p"
	.string "Please mind the flowers.\n"
	.string "I worked hard on them.$"
