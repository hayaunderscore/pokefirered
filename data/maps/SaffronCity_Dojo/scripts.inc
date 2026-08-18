# 1 "data/maps/SaffronCity_Dojo/scripts.pory"

# 2 "data/maps/SaffronCity_Dojo/scripts.pory"
SaffronCity_Dojo_MapScripts::
# 3 "data/maps/SaffronCity_Dojo/scripts.pory"
	.byte 0
# 4 "data/maps/SaffronCity_Dojo/scripts.pory"

# 5 "data/maps/SaffronCity_Dojo/scripts.pory"
SaffronCity_Dojo_EventScript_TriggerMasterBattleLeft::
# 6 "data/maps/SaffronCity_Dojo/scripts.pory"
	lockall
# 7 "data/maps/SaffronCity_Dojo/scripts.pory"
	setvar VAR_MAP_SCENE_SAFFRON_CITY_DOJO, 1
# 8 "data/maps/SaffronCity_Dojo/scripts.pory"
	applymovement LOCALID_KARATE_MASTER, Common_Movement_WalkInPlaceFasterLeft
# 9 "data/maps/SaffronCity_Dojo/scripts.pory"
	waitmovement 0
# 10 "data/maps/SaffronCity_Dojo/scripts.pory"
	releaseall
# 11 "data/maps/SaffronCity_Dojo/scripts.pory"
	end
# 12 "data/maps/SaffronCity_Dojo/scripts.pory"

# 13 "data/maps/SaffronCity_Dojo/scripts.pory"
SaffronCity_Dojo_EventScript_TriggerMasterBattleRight::
# 14 "data/maps/SaffronCity_Dojo/scripts.pory"
	lockall
# 15 "data/maps/SaffronCity_Dojo/scripts.pory"
	setvar VAR_MAP_SCENE_SAFFRON_CITY_DOJO, 1
# 16 "data/maps/SaffronCity_Dojo/scripts.pory"
	applymovement LOCALID_KARATE_MASTER, Common_Movement_WalkInPlaceFasterRight
# 17 "data/maps/SaffronCity_Dojo/scripts.pory"
	waitmovement 0
# 18 "data/maps/SaffronCity_Dojo/scripts.pory"
	releaseall
# 19 "data/maps/SaffronCity_Dojo/scripts.pory"
	end
# 20 "data/maps/SaffronCity_Dojo/scripts.pory"

# 21 "data/maps/SaffronCity_Dojo/scripts.pory"
SaffronCity_Dojo_EventScript_HitmonleeBall::
# 22 "data/maps/SaffronCity_Dojo/scripts.pory"
	lock
# 23 "data/maps/SaffronCity_Dojo/scripts.pory"
	faceplayer
# 24 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_GOT_HITMON_FROM_DOJO, SaffronCity_Dojo_EventScript_AlreadyGotHitmon
# 25 "data/maps/SaffronCity_Dojo/scripts.pory"
	showmonpic SPECIES_HITMONLEE, 10, 3
# 26 "data/maps/SaffronCity_Dojo/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_HITMONLEE
# 27 "data/maps/SaffronCity_Dojo/scripts.pory"
	applymovement LOCALID_KARATE_MASTER, Common_Movement_WalkInPlaceFasterUp
# 28 "data/maps/SaffronCity_Dojo/scripts.pory"
	waitmovement 0
# 29 "data/maps/SaffronCity_Dojo/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 30 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_YouWantHitmonlee, MSGBOX_YESNO
# 31 "data/maps/SaffronCity_Dojo/scripts.pory"
	call EventScript_RestorePrevTextColor
# 32 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_eq VAR_RESULT, YES, SaffronCity_Dojo_EventScript_GiveHitmon
# 33 "data/maps/SaffronCity_Dojo/scripts.pory"
	hidemonpic
# 34 "data/maps/SaffronCity_Dojo/scripts.pory"
	release
# 35 "data/maps/SaffronCity_Dojo/scripts.pory"
	end
# 36 "data/maps/SaffronCity_Dojo/scripts.pory"

# 37 "data/maps/SaffronCity_Dojo/scripts.pory"
SaffronCity_Dojo_EventScript_AlreadyGotHitmon::
# 38 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_BetterNotGetGreedy
# 39 "data/maps/SaffronCity_Dojo/scripts.pory"
	release
# 40 "data/maps/SaffronCity_Dojo/scripts.pory"
	end
# 41 "data/maps/SaffronCity_Dojo/scripts.pory"

# 42 "data/maps/SaffronCity_Dojo/scripts.pory"
SaffronCity_Dojo_EventScript_HitmonchanBall::
# 43 "data/maps/SaffronCity_Dojo/scripts.pory"
	lock
# 44 "data/maps/SaffronCity_Dojo/scripts.pory"
	faceplayer
# 45 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_GOT_HITMON_FROM_DOJO, SaffronCity_Dojo_EventScript_AlreadyGotHitmon
# 46 "data/maps/SaffronCity_Dojo/scripts.pory"
	showmonpic SPECIES_HITMONCHAN, 10, 3
# 47 "data/maps/SaffronCity_Dojo/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_HITMONCHAN
# 48 "data/maps/SaffronCity_Dojo/scripts.pory"
	applymovement LOCALID_KARATE_MASTER, Common_Movement_WalkInPlaceFasterUp
# 49 "data/maps/SaffronCity_Dojo/scripts.pory"
	waitmovement 0
# 50 "data/maps/SaffronCity_Dojo/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 51 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_YouWantHitmonchan, MSGBOX_YESNO
# 52 "data/maps/SaffronCity_Dojo/scripts.pory"
	call EventScript_RestorePrevTextColor
# 53 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_eq VAR_RESULT, YES, SaffronCity_Dojo_EventScript_GiveHitmon
# 54 "data/maps/SaffronCity_Dojo/scripts.pory"
	hidemonpic
# 55 "data/maps/SaffronCity_Dojo/scripts.pory"
	release
# 56 "data/maps/SaffronCity_Dojo/scripts.pory"
	end
# 57 "data/maps/SaffronCity_Dojo/scripts.pory"

# 58 "data/maps/SaffronCity_Dojo/scripts.pory"
SaffronCity_Dojo_EventScript_GiveHitmon::
# 59 "data/maps/SaffronCity_Dojo/scripts.pory"
	hidemonpic
# 60 "data/maps/SaffronCity_Dojo/scripts.pory"
	givemon VAR_TEMP_1, 25
# 61 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_eq VAR_RESULT, 0, SaffronCity_Dojo_EventScript_ReceivedHitmonParty
# 62 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_eq VAR_RESULT, 1, SaffronCity_Dojo_EventScript_ReceivedHitmonPC
# 63 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_eq VAR_RESULT, 2, EventScript_NoMoreRoomForPokemon
# 64 "data/maps/SaffronCity_Dojo/scripts.pory"
	release
# 65 "data/maps/SaffronCity_Dojo/scripts.pory"
	end
# 66 "data/maps/SaffronCity_Dojo/scripts.pory"

# 67 "data/maps/SaffronCity_Dojo/scripts.pory"
SaffronCity_Dojo_EventScript_ReceivedHitmonParty::
# 68 "data/maps/SaffronCity_Dojo/scripts.pory"
	removeobject VAR_LAST_TALKED
# 69 "data/maps/SaffronCity_Dojo/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
# 70 "data/maps/SaffronCity_Dojo/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 71 "data/maps/SaffronCity_Dojo/scripts.pory"
	message SaffronCity_Dojo_Text_ReceivedMonFromKarateMaster
# 72 "data/maps/SaffronCity_Dojo/scripts.pory"
	waitmessage
# 73 "data/maps/SaffronCity_Dojo/scripts.pory"
	waitfanfare
# 74 "data/maps/SaffronCity_Dojo/scripts.pory"
	setflag FLAG_GOT_HITMON_FROM_DOJO
# 75 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 76 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SaffronCity_Dojo_EventScript_EndGiveMon
# 77 "data/maps/SaffronCity_Dojo/scripts.pory"
	call EventScript_GetGiftMonPartySlot
# 78 "data/maps/SaffronCity_Dojo/scripts.pory"
	call EventScript_ChangePokemonNickname
# 79 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto SaffronCity_Dojo_EventScript_EndGiveMon
# 80 "data/maps/SaffronCity_Dojo/scripts.pory"
	end
# 81 "data/maps/SaffronCity_Dojo/scripts.pory"

# 82 "data/maps/SaffronCity_Dojo/scripts.pory"
SaffronCity_Dojo_EventScript_ReceivedHitmonPC::
# 83 "data/maps/SaffronCity_Dojo/scripts.pory"
	removeobject VAR_LAST_TALKED
# 84 "data/maps/SaffronCity_Dojo/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
# 85 "data/maps/SaffronCity_Dojo/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 86 "data/maps/SaffronCity_Dojo/scripts.pory"
	message SaffronCity_Dojo_Text_ReceivedMonFromKarateMaster
# 87 "data/maps/SaffronCity_Dojo/scripts.pory"
	waitmessage
# 88 "data/maps/SaffronCity_Dojo/scripts.pory"
	waitfanfare
# 89 "data/maps/SaffronCity_Dojo/scripts.pory"
	setflag FLAG_GOT_HITMON_FROM_DOJO
# 90 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 91 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SaffronCity_Dojo_EventScript_TransferredHitmonToPC
# 92 "data/maps/SaffronCity_Dojo/scripts.pory"
	call EventScript_NameReceivedBoxMon
# 93 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto SaffronCity_Dojo_EventScript_TransferredHitmonToPC
# 94 "data/maps/SaffronCity_Dojo/scripts.pory"
	end
# 95 "data/maps/SaffronCity_Dojo/scripts.pory"

# 96 "data/maps/SaffronCity_Dojo/scripts.pory"
SaffronCity_Dojo_EventScript_TransferredHitmonToPC::
# 97 "data/maps/SaffronCity_Dojo/scripts.pory"
	call EventScript_TransferredToPC
# 98 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto SaffronCity_Dojo_EventScript_EndGiveMon
# 99 "data/maps/SaffronCity_Dojo/scripts.pory"
	end
# 100 "data/maps/SaffronCity_Dojo/scripts.pory"

# 101 "data/maps/SaffronCity_Dojo/scripts.pory"
SaffronCity_Dojo_EventScript_EndGiveMon::
# 102 "data/maps/SaffronCity_Dojo/scripts.pory"
	release
# 103 "data/maps/SaffronCity_Dojo/scripts.pory"
	end
# 104 "data/maps/SaffronCity_Dojo/scripts.pory"

# 105 "data/maps/SaffronCity_Dojo/scripts.pory"
SaffronCity_Dojo_EventScript_Statue::
# 106 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_FightingDojo, MSGBOX_SIGN
# 107 "data/maps/SaffronCity_Dojo/scripts.pory"
	end
# 108 "data/maps/SaffronCity_Dojo/scripts.pory"

# 109 "data/maps/SaffronCity_Dojo/scripts.pory"
SaffronCity_Dojo_EventScript_LeftScroll::
# 110 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_EnemiesOnEverySide, MSGBOX_SIGN
# 111 "data/maps/SaffronCity_Dojo/scripts.pory"
	end
# 112 "data/maps/SaffronCity_Dojo/scripts.pory"

# 113 "data/maps/SaffronCity_Dojo/scripts.pory"
SaffronCity_Dojo_EventScript_RightScroll::
# 114 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_GoesAroundComesAround, MSGBOX_SIGN
# 115 "data/maps/SaffronCity_Dojo/scripts.pory"
	end
# 116 "data/maps/SaffronCity_Dojo/scripts.pory"

# 117 "data/maps/SaffronCity_Dojo/scripts.pory"
SaffronCity_Dojo_EventScript_Hitoshi::
# 118 "data/maps/SaffronCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_BLACK_BELT_HITOSHI, SaffronCity_Dojo_Text_HitoshiIntro, SaffronCity_Dojo_Text_HitoshiDefeat
# 119 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_HitoshiPostBattle, MSGBOX_AUTOCLOSE
# 120 "data/maps/SaffronCity_Dojo/scripts.pory"
	end
# 121 "data/maps/SaffronCity_Dojo/scripts.pory"

# 122 "data/maps/SaffronCity_Dojo/scripts.pory"
SaffronCity_Dojo_EventScript_Hideki::
# 123 "data/maps/SaffronCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_BLACK_BELT_HIDEKI, SaffronCity_Dojo_Text_HidekiIntro, SaffronCity_Dojo_Text_HidekiDefeat
# 124 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_HidekiPostBattle, MSGBOX_AUTOCLOSE
# 125 "data/maps/SaffronCity_Dojo/scripts.pory"
	end
# 126 "data/maps/SaffronCity_Dojo/scripts.pory"

# 127 "data/maps/SaffronCity_Dojo/scripts.pory"
SaffronCity_Dojo_EventScript_Aaron::
# 128 "data/maps/SaffronCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_BLACK_BELT_AARON, SaffronCity_Dojo_Text_AaronIntro, SaffronCity_Dojo_Text_AaronDefeat
# 129 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_AaronPostBattle, MSGBOX_AUTOCLOSE
# 130 "data/maps/SaffronCity_Dojo/scripts.pory"
	end
# 131 "data/maps/SaffronCity_Dojo/scripts.pory"

# 132 "data/maps/SaffronCity_Dojo/scripts.pory"
SaffronCity_Dojo_EventScript_Mike::
# 133 "data/maps/SaffronCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_BLACK_BELT_MIKE, SaffronCity_Dojo_Text_MikeIntro, SaffronCity_Dojo_Text_MikeDefeat
# 134 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_MikePostBattle, MSGBOX_AUTOCLOSE
# 135 "data/maps/SaffronCity_Dojo/scripts.pory"
	end
# 136 "data/maps/SaffronCity_Dojo/scripts.pory"

# 137 "data/maps/SaffronCity_Dojo/scripts.pory"
SaffronCity_Dojo_EventScript_MasterKoichi::
# 138 "data/maps/SaffronCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_BLACK_BELT_KOICHI, SaffronCity_Dojo_Text_MasterKoichiIntro, SaffronCity_Dojo_Text_MasterKoichiDefeat, SaffronCity_Dojo_EventScript_DefeatedMasterKoichi
# 139 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_GOT_HITMON_FROM_DOJO, SaffronCity_Dojo_EventScript_MasterKoichiAlreadyGotHitmon
# 140 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_ChoosePrizedFightingMon, MSGBOX_AUTOCLOSE
# 141 "data/maps/SaffronCity_Dojo/scripts.pory"
	end
# 142 "data/maps/SaffronCity_Dojo/scripts.pory"

# 143 "data/maps/SaffronCity_Dojo/scripts.pory"
SaffronCity_Dojo_EventScript_MasterKoichiAlreadyGotHitmon::
# 144 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_StayAndTrainWithUs
# 145 "data/maps/SaffronCity_Dojo/scripts.pory"
	release
# 146 "data/maps/SaffronCity_Dojo/scripts.pory"
	end
# 147 "data/maps/SaffronCity_Dojo/scripts.pory"

# 148 "data/maps/SaffronCity_Dojo/scripts.pory"
SaffronCity_Dojo_EventScript_DefeatedMasterKoichi::
# 149 "data/maps/SaffronCity_Dojo/scripts.pory"
	setvar VAR_MAP_SCENE_SAFFRON_CITY_DOJO, 1
# 150 "data/maps/SaffronCity_Dojo/scripts.pory"
	release
# 151 "data/maps/SaffronCity_Dojo/scripts.pory"
	end
