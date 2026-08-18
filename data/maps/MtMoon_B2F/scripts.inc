MtMoon_B2F_MapScripts::
# 2 "data/maps/MtMoon_B2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MtMoon_B2F_OnTransition
	.byte 0


MtMoon_B2F_OnTransition::
# 6 "data/maps/MtMoon_B2F/scripts.pory"
	call_if_unset FLAG_GOT_FOSSIL_FROM_MT_MOON, MtMoon_B2F_EventScript_ShowFossils
# 11 "data/maps/MtMoon_B2F/scripts.pory"
	goto_if_set FLAG_CANNOT_TRY_LUCKY_EGG_ON_MT_MOON, MtMoon_B2F_OnTransition_2
# 16 "data/maps/MtMoon_B2F/scripts.pory"
	goto_if_unset FLAG_GOT_FOSSIL_FROM_MT_MOON, MtMoon_B2F_OnTransition_5
# 20 "data/maps/MtMoon_B2F/scripts.pory"
	clearflag FLAG_HIDE_ABBY_IN_MT_MOON
# 21 "data/maps/MtMoon_B2F/scripts.pory"
	setflag FLAG_HIDE_MIGUEL_IN_MT_MOON
	return

MtMoon_B2F_OnTransition_2:
	end

MtMoon_B2F_OnTransition_5:
	end


MtMoon_B2F_Abby::
# 25 "data/maps/MtMoon_B2F/scripts.pory"
	lockall
# 26 "data/maps/MtMoon_B2F/scripts.pory"
	faceplayer
# 27 "data/maps/MtMoon_B2F/scripts.pory"
	fadenewbgm MUS_DUMMY
# 28 "data/maps/MtMoon_B2F/scripts.pory"
	setweather WEATHER_SHADE
# 29 "data/maps/MtMoon_B2F/scripts.pory"
	doweather
# 30 "data/maps/MtMoon_B2F/scripts.pory"
	delay 60
# 31 "data/maps/MtMoon_B2F/scripts.pory"
	msgbox MtMoon_B2F_Abby_Text_0
# 39 "data/maps/MtMoon_B2F/scripts.pory"
	giveitem ITEM_LUCKY_EGG
# 40 "data/maps/MtMoon_B2F/scripts.pory"
	msgbox MtMoon_B2F_Abby_Text_1
# 41 "data/maps/MtMoon_B2F/scripts.pory"
	closemessage
# 42 "data/maps/MtMoon_B2F/scripts.pory"
	applymovement LOCALID_PLAYER, MtMoon_B2F_Abby_Movement_0
# 45 "data/maps/MtMoon_B2F/scripts.pory"
	applymovement LOCALID_ABBY, MtMoon_B2F_Abby_Movement_1
# 53 "data/maps/MtMoon_B2F/scripts.pory"
	waitmovement 0
# 54 "data/maps/MtMoon_B2F/scripts.pory"
	removeobject LOCALID_ABBY
# 56 "data/maps/MtMoon_B2F/scripts.pory"
	setflag FLAG_CANNOT_TRY_LUCKY_EGG_ON_MT_MOON
# 57 "data/maps/MtMoon_B2F/scripts.pory"
	setvar VAR_MAP_SCENE_LUCKY_EGG_EVENT, 1
# 58 "data/maps/MtMoon_B2F/scripts.pory"
	releaseall
	end


# 62 "data/maps/MtMoon_B2F/scripts.pory"

# 63 "data/maps/MtMoon_B2F/scripts.pory"
MtMoon_B2F_EventScript_ShowFossils::
# 64 "data/maps/MtMoon_B2F/scripts.pory"
	clearflag FLAG_HIDE_DOME_FOSSIL
# 65 "data/maps/MtMoon_B2F/scripts.pory"
	clearflag FLAG_HIDE_HELIX_FOSSIL
# 66 "data/maps/MtMoon_B2F/scripts.pory"
	clearflag FLAG_HIDE_MIGUEL_IN_MT_MOON
# 67 "data/maps/MtMoon_B2F/scripts.pory"
	setflag FLAG_HIDE_ABBY_IN_MT_MOON
# 68 "data/maps/MtMoon_B2F/scripts.pory"
	return
# 69 "data/maps/MtMoon_B2F/scripts.pory"

# 70 "data/maps/MtMoon_B2F/scripts.pory"
MtMoon_B2F_EventScript_MiguelTrigger::
# 71 "data/maps/MtMoon_B2F/scripts.pory"
	lockall
# 72 "data/maps/MtMoon_B2F/scripts.pory"
	applymovement LOCALID_MIGUEL, Common_Movement_WalkInPlaceFasterRight
# 73 "data/maps/MtMoon_B2F/scripts.pory"
	waitmovement 0
# 74 "data/maps/MtMoon_B2F/scripts.pory"
	call MtMoon_B2F_EventScript_BattleMiguel
# 75 "data/maps/MtMoon_B2F/scripts.pory"
	releaseall
# 76 "data/maps/MtMoon_B2F/scripts.pory"
	end
# 77 "data/maps/MtMoon_B2F/scripts.pory"

# 78 "data/maps/MtMoon_B2F/scripts.pory"
MtMoon_B2F_EventScript_Miguel::
# 79 "data/maps/MtMoon_B2F/scripts.pory"
	lock
# 80 "data/maps/MtMoon_B2F/scripts.pory"
	faceplayer
# 81 "data/maps/MtMoon_B2F/scripts.pory"
	goto_if_set FLAG_GOT_FOSSIL_FROM_MT_MOON, MtMoon_B2F_EventScript_MiguelFossilPicked
# 82 "data/maps/MtMoon_B2F/scripts.pory"
	goto_if_defeated TRAINER_SUPER_NERD_MIGUEL, MtMoon_B2F_EventScript_MiguelGoPickFossil
# 83 "data/maps/MtMoon_B2F/scripts.pory"
	call MtMoon_B2F_EventScript_BattleMiguel
# 84 "data/maps/MtMoon_B2F/scripts.pory"
	release
# 85 "data/maps/MtMoon_B2F/scripts.pory"
	end
# 86 "data/maps/MtMoon_B2F/scripts.pory"

# 87 "data/maps/MtMoon_B2F/scripts.pory"
MtMoon_B2F_EventScript_BattleMiguel::
# 88 "data/maps/MtMoon_B2F/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 89 "data/maps/MtMoon_B2F/scripts.pory"
	message MtMoon_B2F_Text_MiguelIntro
# 90 "data/maps/MtMoon_B2F/scripts.pory"
	waitmessage
# 91 "data/maps/MtMoon_B2F/scripts.pory"
	playbgm MUS_ENCOUNTER_GYM_LEADER, 0
# 92 "data/maps/MtMoon_B2F/scripts.pory"
	waitbuttonpress
# 93 "data/maps/MtMoon_B2F/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_MIGUEL
# 94 "data/maps/MtMoon_B2F/scripts.pory"
	trainerbattle_no_intro TRAINER_SUPER_NERD_MIGUEL, MtMoon_B2F_Text_MiguelDefeat
# 95 "data/maps/MtMoon_B2F/scripts.pory"
	setvar VAR_MAP_SCENE_MT_MOON_B2F, 1
# 96 "data/maps/MtMoon_B2F/scripts.pory"
	msgbox MtMoon_B2F_Text_WellEachTakeAFossil
# 97 "data/maps/MtMoon_B2F/scripts.pory"
	return
# 98 "data/maps/MtMoon_B2F/scripts.pory"

# 99 "data/maps/MtMoon_B2F/scripts.pory"
MtMoon_B2F_EventScript_MiguelFossilPicked::
# 100 "data/maps/MtMoon_B2F/scripts.pory"
	msgbox MtMoon_B2F_Text_LabOnCinnabarRegeneratesFossils
# 101 "data/maps/MtMoon_B2F/scripts.pory"
	release
# 102 "data/maps/MtMoon_B2F/scripts.pory"
	end
# 103 "data/maps/MtMoon_B2F/scripts.pory"

# 104 "data/maps/MtMoon_B2F/scripts.pory"
MtMoon_B2F_EventScript_MiguelGoPickFossil::
# 105 "data/maps/MtMoon_B2F/scripts.pory"
	msgbox MtMoon_B2F_Text_WellEachTakeAFossil
# 106 "data/maps/MtMoon_B2F/scripts.pory"
	release
# 107 "data/maps/MtMoon_B2F/scripts.pory"
	end
# 108 "data/maps/MtMoon_B2F/scripts.pory"

# 109 "data/maps/MtMoon_B2F/scripts.pory"
MtMoon_B2F_EventScript_DomeFossil::
# 110 "data/maps/MtMoon_B2F/scripts.pory"
	lock
# 111 "data/maps/MtMoon_B2F/scripts.pory"
	faceplayer
# 112 "data/maps/MtMoon_B2F/scripts.pory"
	msgbox MtMoon_B2F_Text_YouWantDomeFossil, MSGBOX_YESNO
# 113 "data/maps/MtMoon_B2F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MtMoon_B2F_EventScript_DontTakeFossil
# 114 "data/maps/MtMoon_B2F/scripts.pory"
	removeobject LOCALID_DOME_FOSSIL
# 115 "data/maps/MtMoon_B2F/scripts.pory"
	giveitem_msg MtMoon_B2F_Text_ObtainedDomeFossil, ITEM_DOME_FOSSIL, 1, MUS_OBTAIN_KEY_ITEM
# 116 "data/maps/MtMoon_B2F/scripts.pory"
	closemessage
# 117 "data/maps/MtMoon_B2F/scripts.pory"
	special QuestLog_CutRecording
# 118 "data/maps/MtMoon_B2F/scripts.pory"
	delay 10
# 119 "data/maps/MtMoon_B2F/scripts.pory"
	applymovement LOCALID_MIGUEL, MtMoon_B2F_Movement_MiguelToHelixFossil
# 120 "data/maps/MtMoon_B2F/scripts.pory"
	waitmovement 0
# 121 "data/maps/MtMoon_B2F/scripts.pory"
	copyobjectxytoperm LOCALID_MIGUEL
# 122 "data/maps/MtMoon_B2F/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 123 "data/maps/MtMoon_B2F/scripts.pory"
	playfanfare MUS_OBTAIN_KEY_ITEM
# 124 "data/maps/MtMoon_B2F/scripts.pory"
	message MtMoon_B2F_Text_ThenThisFossilIsMine
# 125 "data/maps/MtMoon_B2F/scripts.pory"
	waitmessage
# 126 "data/maps/MtMoon_B2F/scripts.pory"
	waitfanfare
# 127 "data/maps/MtMoon_B2F/scripts.pory"
	removeobject LOCALID_HELIX_FOSSIL
# 128 "data/maps/MtMoon_B2F/scripts.pory"
	setflag FLAG_GOT_DOME_FOSSIL
# 129 "data/maps/MtMoon_B2F/scripts.pory"
	setflag FLAG_GOT_FOSSIL_FROM_MT_MOON
# 130 "data/maps/MtMoon_B2F/scripts.pory"
	release
# 131 "data/maps/MtMoon_B2F/scripts.pory"
	end
# 132 "data/maps/MtMoon_B2F/scripts.pory"

# 133 "data/maps/MtMoon_B2F/scripts.pory"
MtMoon_B2F_Movement_MiguelToHelixFossil::
# 134 "data/maps/MtMoon_B2F/scripts.pory"
	walk_right
# 135 "data/maps/MtMoon_B2F/scripts.pory"
	walk_up
# 136 "data/maps/MtMoon_B2F/scripts.pory"
	walk_up
# 137 "data/maps/MtMoon_B2F/scripts.pory"
	walk_up
# 138 "data/maps/MtMoon_B2F/scripts.pory"
	step_end
# 139 "data/maps/MtMoon_B2F/scripts.pory"

# 140 "data/maps/MtMoon_B2F/scripts.pory"
MtMoon_B2F_EventScript_HelixFossil::
# 141 "data/maps/MtMoon_B2F/scripts.pory"
	lock
# 142 "data/maps/MtMoon_B2F/scripts.pory"
	faceplayer
# 143 "data/maps/MtMoon_B2F/scripts.pory"
	msgbox MtMoon_B2F_Text_YouWantHelixFossil, MSGBOX_YESNO
# 144 "data/maps/MtMoon_B2F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MtMoon_B2F_EventScript_DontTakeFossil
# 145 "data/maps/MtMoon_B2F/scripts.pory"
	removeobject LOCALID_HELIX_FOSSIL
# 146 "data/maps/MtMoon_B2F/scripts.pory"
	giveitem_msg MtMoon_B2F_Text_ObtainedHelixFossil, ITEM_HELIX_FOSSIL, 1, MUS_OBTAIN_KEY_ITEM
# 147 "data/maps/MtMoon_B2F/scripts.pory"
	closemessage
# 148 "data/maps/MtMoon_B2F/scripts.pory"
	special QuestLog_CutRecording
# 149 "data/maps/MtMoon_B2F/scripts.pory"
	delay 10
# 150 "data/maps/MtMoon_B2F/scripts.pory"
	applymovement LOCALID_MIGUEL, MtMoon_B2F_Movement_MiguelToDomeFossil
# 151 "data/maps/MtMoon_B2F/scripts.pory"
	waitmovement 0
# 152 "data/maps/MtMoon_B2F/scripts.pory"
	copyobjectxytoperm LOCALID_MIGUEL
# 153 "data/maps/MtMoon_B2F/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 154 "data/maps/MtMoon_B2F/scripts.pory"
	playfanfare MUS_OBTAIN_KEY_ITEM
# 155 "data/maps/MtMoon_B2F/scripts.pory"
	message MtMoon_B2F_Text_ThenThisFossilIsMine
# 156 "data/maps/MtMoon_B2F/scripts.pory"
	waitmessage
# 157 "data/maps/MtMoon_B2F/scripts.pory"
	waitfanfare
# 158 "data/maps/MtMoon_B2F/scripts.pory"
	removeobject LOCALID_DOME_FOSSIL
# 159 "data/maps/MtMoon_B2F/scripts.pory"
	setflag FLAG_GOT_HELIX_FOSSIL
# 160 "data/maps/MtMoon_B2F/scripts.pory"
	setflag FLAG_GOT_FOSSIL_FROM_MT_MOON
# 161 "data/maps/MtMoon_B2F/scripts.pory"
	release
# 162 "data/maps/MtMoon_B2F/scripts.pory"
	end
# 163 "data/maps/MtMoon_B2F/scripts.pory"

# 164 "data/maps/MtMoon_B2F/scripts.pory"
MtMoon_B2F_EventScript_DontTakeFossil::
# 165 "data/maps/MtMoon_B2F/scripts.pory"
	release
# 166 "data/maps/MtMoon_B2F/scripts.pory"
	end
# 167 "data/maps/MtMoon_B2F/scripts.pory"

# 168 "data/maps/MtMoon_B2F/scripts.pory"
MtMoon_B2F_Movement_MiguelToDomeFossil::
# 169 "data/maps/MtMoon_B2F/scripts.pory"
	walk_up
# 170 "data/maps/MtMoon_B2F/scripts.pory"
	walk_up
# 171 "data/maps/MtMoon_B2F/scripts.pory"
	walk_up
# 172 "data/maps/MtMoon_B2F/scripts.pory"
	step_end
# 173 "data/maps/MtMoon_B2F/scripts.pory"

# 174 "data/maps/MtMoon_B2F/scripts.pory"
MtMoon_B2F_EventScript_Grunt1::
# 175 "data/maps/MtMoon_B2F/scripts.pory"
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT, MtMoon_B2F_Text_Grunt1Intro, MtMoon_B2F_Text_Grunt1Defeat
# 176 "data/maps/MtMoon_B2F/scripts.pory"
	msgbox MtMoon_B2F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
# 177 "data/maps/MtMoon_B2F/scripts.pory"
	end
# 178 "data/maps/MtMoon_B2F/scripts.pory"

# 179 "data/maps/MtMoon_B2F/scripts.pory"
MtMoon_B2F_EventScript_Grunt2::
# 180 "data/maps/MtMoon_B2F/scripts.pory"
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_2, MtMoon_B2F_Text_Grunt2Intro, MtMoon_B2F_Text_Grunt2Defeat
# 181 "data/maps/MtMoon_B2F/scripts.pory"
	msgbox MtMoon_B2F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
# 182 "data/maps/MtMoon_B2F/scripts.pory"
	end
# 183 "data/maps/MtMoon_B2F/scripts.pory"

# 184 "data/maps/MtMoon_B2F/scripts.pory"
MtMoon_B2F_EventScript_Grunt3::
# 185 "data/maps/MtMoon_B2F/scripts.pory"
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_3, MtMoon_B2F_Text_Grunt3Intro, MtMoon_B2F_Text_Grunt3Defeat
# 186 "data/maps/MtMoon_B2F/scripts.pory"
	msgbox MtMoon_B2F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
# 187 "data/maps/MtMoon_B2F/scripts.pory"
	end
# 188 "data/maps/MtMoon_B2F/scripts.pory"

# 189 "data/maps/MtMoon_B2F/scripts.pory"
MtMoon_B2F_EventScript_Grunt4::
# 190 "data/maps/MtMoon_B2F/scripts.pory"
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_4, MtMoon_B2F_Text_Grunt4Intro, MtMoon_B2F_Text_Grunt4Defeat
# 191 "data/maps/MtMoon_B2F/scripts.pory"
	msgbox MtMoon_B2F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
# 192 "data/maps/MtMoon_B2F/scripts.pory"
	end

# 42 "data/maps/MtMoon_B2F/scripts.pory"
MtMoon_B2F_Abby_Movement_0:
# 43 "data/maps/MtMoon_B2F/scripts.pory"
	walk_in_place_down
	step_end

# 45 "data/maps/MtMoon_B2F/scripts.pory"
MtMoon_B2F_Abby_Movement_1:
# 46 "data/maps/MtMoon_B2F/scripts.pory"
	walk_down
# 47 "data/maps/MtMoon_B2F/scripts.pory"
	walk_down
# 48 "data/maps/MtMoon_B2F/scripts.pory"
	walk_down
# 49 "data/maps/MtMoon_B2F/scripts.pory"
	walk_down
# 50 "data/maps/MtMoon_B2F/scripts.pory"
	walk_down
# 51 "data/maps/MtMoon_B2F/scripts.pory"
	walk_down
	step_end

MtMoon_B2F_Abby_Text_0:
# 31 "data/maps/MtMoon_B2F/scripts.pory"
	.string "…\p"
	.string "TRYING THIS PATH AGAIN?\p"
	.string "AREN'T YOU GETTING TIRED OF\n"
	.string "DOING THIS OVER AND OVER?\p"
	.string "REGARDLESS, {COLOR BLUE}I'M {COLOR RED}NOT ONE TO JUDGE.$"

MtMoon_B2F_Abby_Text_1:
# 40 "data/maps/MtMoon_B2F/scripts.pory"
	.string "…USE IT WISELY.$"
