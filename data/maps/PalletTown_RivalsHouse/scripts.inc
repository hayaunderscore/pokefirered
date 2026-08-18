# 1 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 2 "data/maps/PalletTown_RivalsHouse/scripts.pory"
.equ RECEIVED_TOWN_MAP, VAR_TEMP_1
# 3 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 4 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_MapScripts::
# 5 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_RivalsHouse_OnTransition
# 6 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	.byte 0
# 7 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 8 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_OnTransition::
# 9 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	call_if_lt VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2, PalletTown_RivalsHouse_EventScript_MoveDaisyToTable
# 10 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	call_if_ge VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2, PalletTown_RivalsHouse_EventScript_AlreadyReceivedTownMap
# 11 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
# 12 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 13 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_MoveDaisyToTable::
# 14 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	setobjectmovementtype LOCALID_DAISY, MOVEMENT_TYPE_FACE_RIGHT
# 15 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	setobjectxyperm LOCALID_DAISY, 5, 4
# 16 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	return
# 17 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 18 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_AlreadyReceivedTownMap::
# 19 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	setvar RECEIVED_TOWN_MAP, TRUE
# 20 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	return
# 21 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 22 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_Daisy::
# 23 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	lock
# 24 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	faceplayer
# 25 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	famechecker FAMECHECKER_DAISY, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
# 26 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, PalletTown_RivalsHouse_EventScript_GroomMon
# 27 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	goto_if_eq RECEIVED_TOWN_MAP, TRUE, PalletTown_RivalsHouse_EventScript_PleaseGiveMonsRest
# 28 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2, PalletTown_RivalsHouse_EventScript_ExplainTownMap
# 29 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 1, PalletTown_RivalsHouse_EventScript_GiveTownMap
# 30 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 1, PalletTown_RivalsHouse_EventScript_HeardBattledRival
# 31 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_HiBrothersAtLab
# 32 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	closemessage
# 33 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	applymovement LOCALID_DAISY, Common_Movement_FaceOriginalDirection
# 34 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	waitmovement 0
# 35 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	release
# 36 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
# 37 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 38 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_HeardBattledRival::
# 39 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_HeardYouBattledRival
# 40 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	release
# 41 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
# 42 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 43 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_GroomMon::
# 44 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 45 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	special QuestLog_CutRecording
# 46 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	goto_if_lt VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 500, PalletTown_RivalsHouse_EventScript_RateMonFriendship
# 47 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_LikeMeToGroomMon, MSGBOX_YESNO
# 48 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PalletTown_RivalsHouse_EventScript_DeclineGrooming
# 49 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_GroomWhichOne
# 50 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	special ChoosePartyMon
# 51 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	waitstate
# 52 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	lock
# 53 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	faceplayer
# 54 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	goto_if_ge VAR_0x8004, PARTY_SIZE, PalletTown_RivalsHouse_EventScript_DeclineGrooming
# 55 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	specialvar VAR_RESULT, GetPartyMonSpecies
# 56 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	goto_if_eq VAR_RESULT, SPECIES_EGG, PalletTown_RivalsHouse_EventScript_CantGroomEgg
# 57 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_LookingNiceInNoTime
# 58 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	closemessage
# 59 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	fadescreen FADE_TO_BLACK
# 60 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	playfanfare MUS_HEAL
# 61 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	waitfanfare
# 62 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	special DaisyMassageServices
# 63 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 64 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	special BufferMonNickname
# 65 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_ThereYouGoAllDone
# 66 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	release
# 67 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
# 68 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 69 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_CantGroomEgg::
# 70 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_CantGroomAnEgg
# 71 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	release
# 72 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
# 73 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 74 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_DeclineGrooming::
# 75 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_DontNeedAnyGrooming
# 76 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	release
# 77 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
# 78 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 79 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_RateMonFriendship::
# 80 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_MayISeeFirstMon
# 81 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	specialvar VAR_RESULT, GetLeadMonFriendship
# 82 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	switch VAR_RESULT
# 83 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	case 0, PalletTown_RivalsHouse_EventScript_MonFriendshipLowest
# 84 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	case 1, PalletTown_RivalsHouse_EventScript_MonFriendshipLower
# 85 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	case 2, PalletTown_RivalsHouse_EventScript_MonFriendshipLow
# 86 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	case 3, PalletTown_RivalsHouse_EventScript_MonFriendshipMid
# 87 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	case 4, PalletTown_RivalsHouse_EventScript_MonFriendshipHigh
# 88 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	case 5, PalletTown_RivalsHouse_EventScript_MonFriendshipHigher
# 89 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	case 6, PalletTown_RivalsHouse_EventScript_MonFriendshipHighest
# 90 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
# 91 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 92 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_MonFriendshipLowest::
# 93 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_WhyWouldMonHateYouSoMuch
# 94 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	release
# 95 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
# 96 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 97 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_MonFriendshipLower::
# 98 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_DontLikeWayItGlaresAtYou
# 99 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	release
# 100 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
# 101 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 102 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_MonFriendshipLow::
# 103 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_NotFamiliarWithYouYet
# 104 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	release
# 105 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
# 106 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 107 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_MonFriendshipMid::
# 108 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_ItsWarmingUpToYou
# 109 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	release
# 110 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
# 111 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 112 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_MonFriendshipHigh::
# 113 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_ItsQuiteFriendly
# 114 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	release
# 115 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
# 116 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 117 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_MonFriendshipHigher::
# 118 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_ItLooksVeryHappy
# 119 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	release
# 120 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
# 121 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 122 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_MonFriendshipHighest::
# 123 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_CouldntLoveYouMore
# 124 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	release
# 125 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
# 126 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 127 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_PleaseGiveMonsRest::
# 128 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_PleaseGiveMonsRest
# 129 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	release
# 130 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
# 131 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 132 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_GiveTownMap::
# 133 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_ErrandForGrandpaThisWillHelp
# 134 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	closemessage
# 135 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	checkitemspace ITEM_TOWN_MAP
# 136 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, PalletTown_RivalsHouse_EventScript_NoRoomForTownMap
# 137 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	applymovement LOCALID_DAISY, Common_Movement_WalkInPlaceFasterRight
# 138 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	waitmovement 0
# 139 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	removeobject LOCALID_TOWN_MAP
# 140 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2
# 141 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	delay 15
# 142 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	applymovement LOCALID_DAISY, Common_Movement_FacePlayer
# 143 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	waitmovement 0
# 144 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	delay 12
# 145 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	giveitem_msg PalletTown_RivalsHouse_Text_ReceivedTownMapFromDaisy, ITEM_TOWN_MAP, 1, MUS_OBTAIN_KEY_ITEM
# 146 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	release
# 147 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
# 148 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 149 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_NoRoomForTownMap::
# 150 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_DontHaveSpaceForThis
# 151 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	release
# 152 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
# 153 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 154 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_ExplainTownMap::
# 155 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_ExplainTownMap
# 156 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	release
# 157 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
# 158 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 159 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_TownMap::
# 160 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_ItsBigMapOfKanto, MSGBOX_NPC
# 161 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
# 162 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 163 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_Bookshelf::
# 164 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_ShelvesCrammedFullOfBooks, MSGBOX_SIGN
# 165 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
# 166 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 167 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_Picture::
# 168 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_LovelyAndSweetClefairy, MSGBOX_SIGN
# 169 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
