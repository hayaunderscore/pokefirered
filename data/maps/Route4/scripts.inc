Route4_EventScript_HideLuckyEggEvent::
# 2 "data/maps/Route4/scripts.pory"
	setflag FLAG_CANNOT_TRY_LUCKY_EGG_ON_MT_MOON
# 3 "data/maps/Route4/scripts.pory"
	setvar VAR_MAP_SCENE_LUCKY_EGG_EVENT, 1
	return


# 6 "data/maps/Route4/scripts.pory"

# 7 "data/maps/Route4/scripts.pory"
Route4_MapScripts::
# 8 "data/maps/Route4/scripts.pory"
	.byte 0
# 9 "data/maps/Route4/scripts.pory"

# 10 "data/maps/Route4/scripts.pory"
Route4_EventScript_Unused::
# 11 "data/maps/Route4/scripts.pory"
	end
# 12 "data/maps/Route4/scripts.pory"

# 13 "data/maps/Route4/scripts.pory"
Route4_EventScript_Woman::
# 14 "data/maps/Route4/scripts.pory"
	msgbox Route4_Text_TrippedOverGeodude, MSGBOX_NPC
# 15 "data/maps/Route4/scripts.pory"
	end
# 16 "data/maps/Route4/scripts.pory"

# 17 "data/maps/Route4/scripts.pory"
Route4_EventScript_MtMoonSign::
# 18 "data/maps/Route4/scripts.pory"
	msgbox Route4_Text_MtMoonEntrance, MSGBOX_SIGN
# 19 "data/maps/Route4/scripts.pory"
	end
# 20 "data/maps/Route4/scripts.pory"

# 21 "data/maps/Route4/scripts.pory"
Route4_EventScript_RouteSign::
# 22 "data/maps/Route4/scripts.pory"
	msgbox Route4_Text_RouteSign, MSGBOX_SIGN
# 23 "data/maps/Route4/scripts.pory"
	end
