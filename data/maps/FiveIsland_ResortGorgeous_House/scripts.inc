# 1 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"

# 2 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
.equ SHOWN_REQUESTED_MON, FLAG_TEMP_2
# 3 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"

# 4 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
FiveIsland_ResortGorgeous_House_MapScripts::
# 5 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	.byte 0
# 6 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"

# 7 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
FiveIsland_ResortGorgeous_House_EventScript_Selphy::
# 8 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 9 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	special QuestLog_CutRecording
# 10 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	lock
# 11 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	faceplayer
# 12 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	goto_if_set SHOWN_REQUESTED_MON, FiveIsland_ResortGorgeous_House_EventScript_JustFulfilledRequest
# 13 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	goto_if_eq VAR_RESORT_GORGEOUS_REQUESTED_MON, 0xFFFF, FiveIsland_ResortGorgeous_House_EventScript_RequestTookTooLong
# 14 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	goto_if_ne VAR_RESORT_GORGEOUS_REQUESTED_MON, SPECIES_NONE, FiveIsland_ResortGorgeous_House_EventScript_CheckForRequestedMon
# 15 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	msgbox FiveIsland_ResortGorgeous_House_Text_PleaseHearMyWish
# 16 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	goto FiveIsland_ResortGorgeous_House_EventScript_RequestMon
# 17 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	end
# 18 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"

# 19 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
FiveIsland_ResortGorgeous_House_EventScript_RequestMon::
# 20 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	special SampleResortGorgeousMonAndReward
# 21 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	msgbox FiveIsland_ResortGorgeous_House_Text_WishToSeeMonPlease
# 22 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	release
# 23 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	end
# 24 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"

# 25 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
FiveIsland_ResortGorgeous_House_EventScript_RequestTookTooLong::
# 26 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	msgbox FiveIsland_ResortGorgeous_House_Text_OhImTiredOfWaiting
# 27 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	goto FiveIsland_ResortGorgeous_House_EventScript_RequestMon
# 28 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	end
# 29 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"

# 30 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
FiveIsland_ResortGorgeous_House_EventScript_CheckForRequestedMon::
# 31 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	copyvar VAR_0x8004, VAR_RESORT_GORGEOUS_REQUESTED_MON
# 32 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	specialvar VAR_RESULT, DoesPlayerPartyContainSpecies
# 33 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, FiveIsland_ResortGorgeous_House_EventScript_ShowRequestedMon
# 34 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	goto FiveIsland_ResortGorgeous_House_EventScript_RequestMon
# 35 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	end
# 36 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"

# 37 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
FiveIsland_ResortGorgeous_House_EventScript_ShowRequestedMon::
# 38 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	special SampleResortGorgeousMonAndReward
# 39 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	msgbox FiveIsland_ResortGorgeous_House_Text_MonYouCaughtForMeThankYou
# 40 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	addobject LOCALID_RESORT_GORGEOUS_HOUSE_BUTLER
# 41 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	applymovement LOCALID_RESORT_GORGEOUS_HOUSE_BUTLER, FiveIsland_ResortGorgeous_House_Movement_ButlerEnter
# 42 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	waitmovement 0
# 43 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 44 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	msgbox FiveIsland_ResortGorgeous_House_Text_ButlerYesMyLady
# 45 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	applymovement LOCALID_RESORT_GORGEOUS_HOUSE_SELPHY, Common_Movement_WalkInPlaceFasterUp
# 46 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	waitmovement 0
# 47 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 48 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	msgbox FiveIsland_ResortGorgeous_House_Text_SelphyGiveTokenOfAppreciation
# 49 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 50 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	msgbox FiveIsland_ResortGorgeous_House_Text_ButlerIShallDoAsYouBid
# 51 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	closemessage
# 52 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, FiveIsland_ResortGorgeous_House_EventScript_ButlerApproachPlayerNorth
# 53 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, FiveIsland_ResortGorgeous_House_EventScript_ButlerApproachPlayerSouth
# 54 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, FiveIsland_ResortGorgeous_House_EventScript_ButlerApproachPlayerEast
# 55 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, FiveIsland_ResortGorgeous_House_EventScript_ButlerApproachPlayerWest
# 56 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	copyobjectxytoperm LOCALID_RESORT_GORGEOUS_HOUSE_BUTLER
# 57 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	msgbox FiveIsland_ResortGorgeous_House_Text_ButlerPleaseAcceptThisAsHerThanks
# 58 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	giveitem VAR_RESORT_GORGEOUS_REWARD
# 59 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, FiveIsland_ResortGorgeous_House_EventScript_NoRoomForReward
# 60 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	setflag SHOWN_REQUESTED_MON
# 61 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	setvar VAR_RESORT_GORGEOUS_REQUESTED_MON, SPECIES_NONE
# 62 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	release
# 63 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	end
# 64 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"

# 65 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
FiveIsland_ResortGorgeous_House_EventScript_ButlerApproachPlayerNorth::
# 66 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	applymovement LOCALID_RESORT_GORGEOUS_HOUSE_SELPHY, Common_Movement_WalkInPlaceFasterDown
# 67 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	applymovement LOCALID_RESORT_GORGEOUS_HOUSE_BUTLER, FiveIsland_ResortGorgeous_House_Movement_ButlerApproachPlayerNorth
# 68 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	waitmovement 0
# 69 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 70 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	waitmovement 0
# 71 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	return
# 72 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"

# 73 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
FiveIsland_ResortGorgeous_House_EventScript_ButlerApproachPlayerSouth::
# 74 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	applymovement LOCALID_RESORT_GORGEOUS_HOUSE_BUTLER, FiveIsland_ResortGorgeous_House_Movement_ButlerApproachPlayerSouth
# 75 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	waitmovement 0
# 76 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 77 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	waitmovement 0
# 78 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	return
# 79 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"

# 80 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
FiveIsland_ResortGorgeous_House_EventScript_ButlerApproachPlayerEast::
# 81 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	applymovement LOCALID_RESORT_GORGEOUS_HOUSE_SELPHY, Common_Movement_WalkInPlaceFasterLeft
# 82 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	applymovement LOCALID_RESORT_GORGEOUS_HOUSE_BUTLER, FiveIsland_ResortGorgeous_House_Movement_ButlerApproachPlayerEast
# 83 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	waitmovement 0
# 84 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 85 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	waitmovement 0
# 86 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	return
# 87 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"

# 88 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
FiveIsland_ResortGorgeous_House_EventScript_ButlerApproachPlayerWest::
# 89 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	applymovement LOCALID_RESORT_GORGEOUS_HOUSE_BUTLER, FiveIsland_ResortGorgeous_House_Movement_ButlerApproachPlayerWest
# 90 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	waitmovement 0
# 91 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	return
# 92 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"

# 93 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
FiveIsland_ResortGorgeous_House_EventScript_NoRoomForReward::
# 94 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 95 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	msgbox FiveIsland_ResortGorgeous_House_Text_ButlerBagAppearsToBeFull
# 96 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 97 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	msgbox FiveIsland_ResortGorgeous_House_Text_OhHowDisappointing
# 98 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	setflag SHOWN_REQUESTED_MON
# 99 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	setvar VAR_RESORT_GORGEOUS_REQUESTED_MON, SPECIES_NONE
# 100 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	release
# 101 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	end
# 102 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"

# 103 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
FiveIsland_ResortGorgeous_House_EventScript_JustFulfilledRequest::
# 104 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	msgbox FiveIsland_ResortGorgeous_House_Text_SelphyWishYouBestOfLuck
# 105 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	release
# 106 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	end
# 107 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"

# 108 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
FiveIsland_ResortGorgeous_House_Movement_ButlerApproachPlayerNorth::
# 109 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	walk_left
# 110 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	walk_left
# 111 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	walk_left
# 112 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	walk_down
# 113 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	walk_down
# 114 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	walk_down
# 115 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	walk_in_place_faster_right
# 116 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	step_end
# 117 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"

# 118 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
FiveIsland_ResortGorgeous_House_Movement_ButlerApproachPlayerSouth::
# 119 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	walk_left
# 120 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	walk_left
# 121 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	walk_in_place_faster_down
# 122 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	step_end
# 123 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"

# 124 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
FiveIsland_ResortGorgeous_House_Movement_ButlerApproachPlayerEast::
# 125 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	walk_left
# 126 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	walk_left
# 127 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	walk_left
# 128 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	walk_down
# 129 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	step_end
# 130 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"

# 131 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
@ Very odd. If the player is talking to Selphy facing West, then the player has clipped through the table
# 132 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
@ In this case rather than approach the player the Butler walks up, which clips the Butler into a wall
# 133 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
FiveIsland_ResortGorgeous_House_Movement_ButlerApproachPlayerWest::
# 134 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	walk_up
# 135 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	step_end
# 136 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"

# 137 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
FiveIsland_ResortGorgeous_House_Movement_ButlerEnter::
# 138 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	walk_in_place_down
# 139 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	step_end
# 140 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"

# 141 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
@ Addressed as "Sebastian" but speaks only as "Butler"
# 142 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
FiveIsland_ResortGorgeous_House_EventScript_Butler::
# 143 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	msgbox FiveIsland_ResortGorgeous_House_Text_LadySelphySmileHasBrillianceOfSun, MSGBOX_NPC
# 144 "data/maps/FiveIsland_ResortGorgeous_House/scripts.pory"
	end
