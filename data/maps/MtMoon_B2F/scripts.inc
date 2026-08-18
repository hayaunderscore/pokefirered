# 1 "data/maps/MtMoon_B2F/scripts.pory"

# 2 "data/maps/MtMoon_B2F/scripts.pory"
MtMoon_B2F_MapScripts::
# 3 "data/maps/MtMoon_B2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MtMoon_B2F_OnTransition
# 4 "data/maps/MtMoon_B2F/scripts.pory"
	.byte 0
# 5 "data/maps/MtMoon_B2F/scripts.pory"

# 6 "data/maps/MtMoon_B2F/scripts.pory"
MtMoon_B2F_OnTransition::
# 7 "data/maps/MtMoon_B2F/scripts.pory"
	call_if_unset FLAG_GOT_FOSSIL_FROM_MT_MOON, MtMoon_B2F_EventScript_ShowFossils
# 8 "data/maps/MtMoon_B2F/scripts.pory"
	end
# 9 "data/maps/MtMoon_B2F/scripts.pory"

# 10 "data/maps/MtMoon_B2F/scripts.pory"
MtMoon_B2F_EventScript_ShowFossils::
# 11 "data/maps/MtMoon_B2F/scripts.pory"
	clearflag FLAG_HIDE_DOME_FOSSIL
# 12 "data/maps/MtMoon_B2F/scripts.pory"
	clearflag FLAG_HIDE_HELIX_FOSSIL
# 13 "data/maps/MtMoon_B2F/scripts.pory"
	return
# 14 "data/maps/MtMoon_B2F/scripts.pory"

# 15 "data/maps/MtMoon_B2F/scripts.pory"
MtMoon_B2F_EventScript_MiguelTrigger::
# 16 "data/maps/MtMoon_B2F/scripts.pory"
	lockall
# 17 "data/maps/MtMoon_B2F/scripts.pory"
	applymovement LOCALID_MIGUEL, Common_Movement_WalkInPlaceFasterRight
# 18 "data/maps/MtMoon_B2F/scripts.pory"
	waitmovement 0
# 19 "data/maps/MtMoon_B2F/scripts.pory"
	call MtMoon_B2F_EventScript_BattleMiguel
# 20 "data/maps/MtMoon_B2F/scripts.pory"
	releaseall
# 21 "data/maps/MtMoon_B2F/scripts.pory"
	end
# 22 "data/maps/MtMoon_B2F/scripts.pory"

# 23 "data/maps/MtMoon_B2F/scripts.pory"
MtMoon_B2F_EventScript_Miguel::
# 24 "data/maps/MtMoon_B2F/scripts.pory"
	lock
# 25 "data/maps/MtMoon_B2F/scripts.pory"
	faceplayer
# 26 "data/maps/MtMoon_B2F/scripts.pory"
	goto_if_set FLAG_GOT_FOSSIL_FROM_MT_MOON, MtMoon_B2F_EventScript_MiguelFossilPicked
# 27 "data/maps/MtMoon_B2F/scripts.pory"
	goto_if_defeated TRAINER_SUPER_NERD_MIGUEL, MtMoon_B2F_EventScript_MiguelGoPickFossil
# 28 "data/maps/MtMoon_B2F/scripts.pory"
	call MtMoon_B2F_EventScript_BattleMiguel
# 29 "data/maps/MtMoon_B2F/scripts.pory"
	release
# 30 "data/maps/MtMoon_B2F/scripts.pory"
	end
# 31 "data/maps/MtMoon_B2F/scripts.pory"

# 32 "data/maps/MtMoon_B2F/scripts.pory"
MtMoon_B2F_EventScript_BattleMiguel::
# 33 "data/maps/MtMoon_B2F/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 34 "data/maps/MtMoon_B2F/scripts.pory"
	message MtMoon_B2F_Text_MiguelIntro
# 35 "data/maps/MtMoon_B2F/scripts.pory"
	waitmessage
# 36 "data/maps/MtMoon_B2F/scripts.pory"
	playbgm MUS_ENCOUNTER_GYM_LEADER, 0
# 37 "data/maps/MtMoon_B2F/scripts.pory"
	waitbuttonpress
# 38 "data/maps/MtMoon_B2F/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_MIGUEL
# 39 "data/maps/MtMoon_B2F/scripts.pory"
	trainerbattle_no_intro TRAINER_SUPER_NERD_MIGUEL, MtMoon_B2F_Text_MiguelDefeat
# 40 "data/maps/MtMoon_B2F/scripts.pory"
	setvar VAR_MAP_SCENE_MT_MOON_B2F, 1
# 41 "data/maps/MtMoon_B2F/scripts.pory"
	msgbox MtMoon_B2F_Text_WellEachTakeAFossil
# 42 "data/maps/MtMoon_B2F/scripts.pory"
	return
# 43 "data/maps/MtMoon_B2F/scripts.pory"

# 44 "data/maps/MtMoon_B2F/scripts.pory"
MtMoon_B2F_EventScript_MiguelFossilPicked::
# 45 "data/maps/MtMoon_B2F/scripts.pory"
	msgbox MtMoon_B2F_Text_LabOnCinnabarRegeneratesFossils
# 46 "data/maps/MtMoon_B2F/scripts.pory"
	release
# 47 "data/maps/MtMoon_B2F/scripts.pory"
	end
# 48 "data/maps/MtMoon_B2F/scripts.pory"

# 49 "data/maps/MtMoon_B2F/scripts.pory"
MtMoon_B2F_EventScript_MiguelGoPickFossil::
# 50 "data/maps/MtMoon_B2F/scripts.pory"
	msgbox MtMoon_B2F_Text_WellEachTakeAFossil
# 51 "data/maps/MtMoon_B2F/scripts.pory"
	release
# 52 "data/maps/MtMoon_B2F/scripts.pory"
	end
# 53 "data/maps/MtMoon_B2F/scripts.pory"

# 54 "data/maps/MtMoon_B2F/scripts.pory"
MtMoon_B2F_EventScript_DomeFossil::
# 55 "data/maps/MtMoon_B2F/scripts.pory"
	lock
# 56 "data/maps/MtMoon_B2F/scripts.pory"
	faceplayer
# 57 "data/maps/MtMoon_B2F/scripts.pory"
	msgbox MtMoon_B2F_Text_YouWantDomeFossil, MSGBOX_YESNO
# 58 "data/maps/MtMoon_B2F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MtMoon_B2F_EventScript_DontTakeFossil
# 59 "data/maps/MtMoon_B2F/scripts.pory"
	removeobject LOCALID_DOME_FOSSIL
# 60 "data/maps/MtMoon_B2F/scripts.pory"
	giveitem_msg MtMoon_B2F_Text_ObtainedDomeFossil, ITEM_DOME_FOSSIL, 1, MUS_OBTAIN_KEY_ITEM
# 61 "data/maps/MtMoon_B2F/scripts.pory"
	closemessage
# 62 "data/maps/MtMoon_B2F/scripts.pory"
	special QuestLog_CutRecording
# 63 "data/maps/MtMoon_B2F/scripts.pory"
	delay 10
# 64 "data/maps/MtMoon_B2F/scripts.pory"
	applymovement LOCALID_MIGUEL, MtMoon_B2F_Movement_MiguelToHelixFossil
# 65 "data/maps/MtMoon_B2F/scripts.pory"
	waitmovement 0
# 66 "data/maps/MtMoon_B2F/scripts.pory"
	copyobjectxytoperm LOCALID_MIGUEL
# 67 "data/maps/MtMoon_B2F/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 68 "data/maps/MtMoon_B2F/scripts.pory"
	playfanfare MUS_OBTAIN_KEY_ITEM
# 69 "data/maps/MtMoon_B2F/scripts.pory"
	message MtMoon_B2F_Text_ThenThisFossilIsMine
# 70 "data/maps/MtMoon_B2F/scripts.pory"
	waitmessage
# 71 "data/maps/MtMoon_B2F/scripts.pory"
	waitfanfare
# 72 "data/maps/MtMoon_B2F/scripts.pory"
	removeobject LOCALID_HELIX_FOSSIL
# 73 "data/maps/MtMoon_B2F/scripts.pory"
	setflag FLAG_GOT_DOME_FOSSIL
# 74 "data/maps/MtMoon_B2F/scripts.pory"
	setflag FLAG_GOT_FOSSIL_FROM_MT_MOON
# 75 "data/maps/MtMoon_B2F/scripts.pory"
	release
# 76 "data/maps/MtMoon_B2F/scripts.pory"
	end
# 77 "data/maps/MtMoon_B2F/scripts.pory"

# 78 "data/maps/MtMoon_B2F/scripts.pory"
MtMoon_B2F_Movement_MiguelToHelixFossil::
# 79 "data/maps/MtMoon_B2F/scripts.pory"
	walk_right
# 80 "data/maps/MtMoon_B2F/scripts.pory"
	walk_up
# 81 "data/maps/MtMoon_B2F/scripts.pory"
	walk_up
# 82 "data/maps/MtMoon_B2F/scripts.pory"
	walk_up
# 83 "data/maps/MtMoon_B2F/scripts.pory"
	step_end
# 84 "data/maps/MtMoon_B2F/scripts.pory"

# 85 "data/maps/MtMoon_B2F/scripts.pory"
MtMoon_B2F_EventScript_HelixFossil::
# 86 "data/maps/MtMoon_B2F/scripts.pory"
	lock
# 87 "data/maps/MtMoon_B2F/scripts.pory"
	faceplayer
# 88 "data/maps/MtMoon_B2F/scripts.pory"
	msgbox MtMoon_B2F_Text_YouWantHelixFossil, MSGBOX_YESNO
# 89 "data/maps/MtMoon_B2F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MtMoon_B2F_EventScript_DontTakeFossil
# 90 "data/maps/MtMoon_B2F/scripts.pory"
	removeobject LOCALID_HELIX_FOSSIL
# 91 "data/maps/MtMoon_B2F/scripts.pory"
	giveitem_msg MtMoon_B2F_Text_ObtainedHelixFossil, ITEM_HELIX_FOSSIL, 1, MUS_OBTAIN_KEY_ITEM
# 92 "data/maps/MtMoon_B2F/scripts.pory"
	closemessage
# 93 "data/maps/MtMoon_B2F/scripts.pory"
	special QuestLog_CutRecording
# 94 "data/maps/MtMoon_B2F/scripts.pory"
	delay 10
# 95 "data/maps/MtMoon_B2F/scripts.pory"
	applymovement LOCALID_MIGUEL, MtMoon_B2F_Movement_MiguelToDomeFossil
# 96 "data/maps/MtMoon_B2F/scripts.pory"
	waitmovement 0
# 97 "data/maps/MtMoon_B2F/scripts.pory"
	copyobjectxytoperm LOCALID_MIGUEL
# 98 "data/maps/MtMoon_B2F/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 99 "data/maps/MtMoon_B2F/scripts.pory"
	playfanfare MUS_OBTAIN_KEY_ITEM
# 100 "data/maps/MtMoon_B2F/scripts.pory"
	message MtMoon_B2F_Text_ThenThisFossilIsMine
# 101 "data/maps/MtMoon_B2F/scripts.pory"
	waitmessage
# 102 "data/maps/MtMoon_B2F/scripts.pory"
	waitfanfare
# 103 "data/maps/MtMoon_B2F/scripts.pory"
	removeobject LOCALID_DOME_FOSSIL
# 104 "data/maps/MtMoon_B2F/scripts.pory"
	setflag FLAG_GOT_HELIX_FOSSIL
# 105 "data/maps/MtMoon_B2F/scripts.pory"
	setflag FLAG_GOT_FOSSIL_FROM_MT_MOON
# 106 "data/maps/MtMoon_B2F/scripts.pory"
	release
# 107 "data/maps/MtMoon_B2F/scripts.pory"
	end
# 108 "data/maps/MtMoon_B2F/scripts.pory"

# 109 "data/maps/MtMoon_B2F/scripts.pory"
MtMoon_B2F_EventScript_DontTakeFossil::
# 110 "data/maps/MtMoon_B2F/scripts.pory"
	release
# 111 "data/maps/MtMoon_B2F/scripts.pory"
	end
# 112 "data/maps/MtMoon_B2F/scripts.pory"

# 113 "data/maps/MtMoon_B2F/scripts.pory"
MtMoon_B2F_Movement_MiguelToDomeFossil::
# 114 "data/maps/MtMoon_B2F/scripts.pory"
	walk_up
# 115 "data/maps/MtMoon_B2F/scripts.pory"
	walk_up
# 116 "data/maps/MtMoon_B2F/scripts.pory"
	walk_up
# 117 "data/maps/MtMoon_B2F/scripts.pory"
	step_end
# 118 "data/maps/MtMoon_B2F/scripts.pory"

# 119 "data/maps/MtMoon_B2F/scripts.pory"
MtMoon_B2F_EventScript_Grunt1::
# 120 "data/maps/MtMoon_B2F/scripts.pory"
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT, MtMoon_B2F_Text_Grunt1Intro, MtMoon_B2F_Text_Grunt1Defeat
# 121 "data/maps/MtMoon_B2F/scripts.pory"
	msgbox MtMoon_B2F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
# 122 "data/maps/MtMoon_B2F/scripts.pory"
	end
# 123 "data/maps/MtMoon_B2F/scripts.pory"

# 124 "data/maps/MtMoon_B2F/scripts.pory"
MtMoon_B2F_EventScript_Grunt2::
# 125 "data/maps/MtMoon_B2F/scripts.pory"
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_2, MtMoon_B2F_Text_Grunt2Intro, MtMoon_B2F_Text_Grunt2Defeat
# 126 "data/maps/MtMoon_B2F/scripts.pory"
	msgbox MtMoon_B2F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
# 127 "data/maps/MtMoon_B2F/scripts.pory"
	end
# 128 "data/maps/MtMoon_B2F/scripts.pory"

# 129 "data/maps/MtMoon_B2F/scripts.pory"
MtMoon_B2F_EventScript_Grunt3::
# 130 "data/maps/MtMoon_B2F/scripts.pory"
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_3, MtMoon_B2F_Text_Grunt3Intro, MtMoon_B2F_Text_Grunt3Defeat
# 131 "data/maps/MtMoon_B2F/scripts.pory"
	msgbox MtMoon_B2F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
# 132 "data/maps/MtMoon_B2F/scripts.pory"
	end
# 133 "data/maps/MtMoon_B2F/scripts.pory"

# 134 "data/maps/MtMoon_B2F/scripts.pory"
MtMoon_B2F_EventScript_Grunt4::
# 135 "data/maps/MtMoon_B2F/scripts.pory"
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_4, MtMoon_B2F_Text_Grunt4Intro, MtMoon_B2F_Text_Grunt4Defeat
# 136 "data/maps/MtMoon_B2F/scripts.pory"
	msgbox MtMoon_B2F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
# 137 "data/maps/MtMoon_B2F/scripts.pory"
	end
