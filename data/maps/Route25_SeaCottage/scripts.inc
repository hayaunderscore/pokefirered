# 1 "data/maps/Route25_SeaCottage/scripts.pory"

# 2 "data/maps/Route25_SeaCottage/scripts.pory"
.equ BILL_IN_TELEPORTER,     FLAG_TEMP_2
# 3 "data/maps/Route25_SeaCottage/scripts.pory"
.equ RETURN_AFTER_SS_TICKET, FLAG_TEMP_3
# 4 "data/maps/Route25_SeaCottage/scripts.pory"

# 5 "data/maps/Route25_SeaCottage/scripts.pory"
Route25_SeaCottage_MapScripts::
# 6 "data/maps/Route25_SeaCottage/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route25_SeaCottage_OnTransition
# 7 "data/maps/Route25_SeaCottage/scripts.pory"
	.byte 0
# 8 "data/maps/Route25_SeaCottage/scripts.pory"

# 9 "data/maps/Route25_SeaCottage/scripts.pory"
Route25_SeaCottage_OnTransition::
# 10 "data/maps/Route25_SeaCottage/scripts.pory"
	call_if_unset FLAG_HELPED_BILL_IN_SEA_COTTAGE, Route25_SeaCottage_EventScript_HideClefairyBill
# 11 "data/maps/Route25_SeaCottage/scripts.pory"
	call_if_set FLAG_GOT_SS_TICKET, Route25_SeaCottage_EventScript_SetReturnedAfterSSTicket
# 12 "data/maps/Route25_SeaCottage/scripts.pory"
	end
# 13 "data/maps/Route25_SeaCottage/scripts.pory"

# 14 "data/maps/Route25_SeaCottage/scripts.pory"
Route25_SeaCottage_EventScript_HideClefairyBill::
# 15 "data/maps/Route25_SeaCottage/scripts.pory"
	clearflag FLAG_HIDE_BILL_CLEFAIRY
# 16 "data/maps/Route25_SeaCottage/scripts.pory"
	setobjectxyperm LOCALID_BILL_HUMAN, 3, 3
# 17 "data/maps/Route25_SeaCottage/scripts.pory"
	return
# 18 "data/maps/Route25_SeaCottage/scripts.pory"

# 19 "data/maps/Route25_SeaCottage/scripts.pory"
Route25_SeaCottage_EventScript_SetReturnedAfterSSTicket::
# 20 "data/maps/Route25_SeaCottage/scripts.pory"
	setflag RETURN_AFTER_SS_TICKET
# 21 "data/maps/Route25_SeaCottage/scripts.pory"
	return
# 22 "data/maps/Route25_SeaCottage/scripts.pory"

# 23 "data/maps/Route25_SeaCottage/scripts.pory"
Route25_SeaCottage_EventScript_Bill::
# 24 "data/maps/Route25_SeaCottage/scripts.pory"
	lock
# 25 "data/maps/Route25_SeaCottage/scripts.pory"
	faceplayer
# 26 "data/maps/Route25_SeaCottage/scripts.pory"
	goto_if_set RETURN_AFTER_SS_TICKET, Route25_SeaCottage_EventScript_BillGoLookAtPC
# 27 "data/maps/Route25_SeaCottage/scripts.pory"
	goto_if_set FLAG_GOT_SS_TICKET, Route25_SeaCottage_EventScript_BillGoToSSAnne
# 28 "data/maps/Route25_SeaCottage/scripts.pory"
	goto_if_set FLAG_HELPED_BILL_IN_SEA_COTTAGE, Route25_SeaCottage_EventScript_BillGiveSSTicket
# 29 "data/maps/Route25_SeaCottage/scripts.pory"
	checkplayergender
# 30 "data/maps/Route25_SeaCottage/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, Route25_SeaCottage_EventScript_BillAskForHelpMale
# 31 "data/maps/Route25_SeaCottage/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, Route25_SeaCottage_EventScript_BillAskForHelpFemale
# 32 "data/maps/Route25_SeaCottage/scripts.pory"
	end
# 33 "data/maps/Route25_SeaCottage/scripts.pory"

# 34 "data/maps/Route25_SeaCottage/scripts.pory"
Route25_SeaCottage_EventScript_BillAskForHelpMale::
# 35 "data/maps/Route25_SeaCottage/scripts.pory"
	msgbox Route25_SeaCottage_Text_ImBillHelpMeOutPal, MSGBOX_YESNO
# 36 "data/maps/Route25_SeaCottage/scripts.pory"
	goto Route25_SeaCottage_EventScript_BillAskForHelp
# 37 "data/maps/Route25_SeaCottage/scripts.pory"
	end
# 38 "data/maps/Route25_SeaCottage/scripts.pory"

# 39 "data/maps/Route25_SeaCottage/scripts.pory"
Route25_SeaCottage_EventScript_BillAskForHelpFemale::
# 40 "data/maps/Route25_SeaCottage/scripts.pory"
	msgbox Route25_SeaCottage_Text_ImBillHelpMeOutLady, MSGBOX_YESNO
# 41 "data/maps/Route25_SeaCottage/scripts.pory"
	goto Route25_SeaCottage_EventScript_BillAskForHelp
# 42 "data/maps/Route25_SeaCottage/scripts.pory"
	end
# 43 "data/maps/Route25_SeaCottage/scripts.pory"

# 44 "data/maps/Route25_SeaCottage/scripts.pory"
Route25_SeaCottage_EventScript_BillAskForHelp::
# 45 "data/maps/Route25_SeaCottage/scripts.pory"
	call_if_eq VAR_RESULT, NO, Route25_SeaCottage_EventScript_DeclineHelpBill
# 46 "data/maps/Route25_SeaCottage/scripts.pory"
	msgbox Route25_SeaCottage_Text_RunCellSeparationOnPC
# 47 "data/maps/Route25_SeaCottage/scripts.pory"
	closemessage
# 48 "data/maps/Route25_SeaCottage/scripts.pory"
	delay 10
# 49 "data/maps/Route25_SeaCottage/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, Route25_SeaCottage_EventScript_BillWalkToTeleporterSouth
# 50 "data/maps/Route25_SeaCottage/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, Route25_SeaCottage_EventScript_BillWalkToTeleporter
# 51 "data/maps/Route25_SeaCottage/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, Route25_SeaCottage_EventScript_BillWalkToTeleporter
# 52 "data/maps/Route25_SeaCottage/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, Route25_SeaCottage_EventScript_BillWalkToTeleporter
# 53 "data/maps/Route25_SeaCottage/scripts.pory"
	opendoor 10, 3
# 54 "data/maps/Route25_SeaCottage/scripts.pory"
	waitdooranim
# 55 "data/maps/Route25_SeaCottage/scripts.pory"
	applymovement LOCALID_BILL_CLEFAIRY, Route25_SeaCottage_Movement_BillEnterTeleporter
# 56 "data/maps/Route25_SeaCottage/scripts.pory"
	waitmovement 0
# 57 "data/maps/Route25_SeaCottage/scripts.pory"
	removeobject LOCALID_BILL_CLEFAIRY
# 58 "data/maps/Route25_SeaCottage/scripts.pory"
	playse SE_CONTEST_CURTAIN_FALL
# 59 "data/maps/Route25_SeaCottage/scripts.pory"
	closedoor 10, 3
# 60 "data/maps/Route25_SeaCottage/scripts.pory"
	waitdooranim
# 61 "data/maps/Route25_SeaCottage/scripts.pory"
	setflag BILL_IN_TELEPORTER
# 62 "data/maps/Route25_SeaCottage/scripts.pory"
	release
# 63 "data/maps/Route25_SeaCottage/scripts.pory"
	end
# 64 "data/maps/Route25_SeaCottage/scripts.pory"

# 65 "data/maps/Route25_SeaCottage/scripts.pory"
@ Just returns after message, execution continues as if player had said yes
# 66 "data/maps/Route25_SeaCottage/scripts.pory"
Route25_SeaCottage_EventScript_DeclineHelpBill::
# 67 "data/maps/Route25_SeaCottage/scripts.pory"
	checkplayergender
# 68 "data/maps/Route25_SeaCottage/scripts.pory"
	call_if_eq VAR_RESULT, MALE, Route25_SeaCottage_EventScript_DeclineHelpBillMale
# 69 "data/maps/Route25_SeaCottage/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, Route25_SeaCottage_EventScript_DeclineHelpBillFemale
# 70 "data/maps/Route25_SeaCottage/scripts.pory"
	return
# 71 "data/maps/Route25_SeaCottage/scripts.pory"

# 72 "data/maps/Route25_SeaCottage/scripts.pory"
Route25_SeaCottage_EventScript_DeclineHelpBillMale::
# 73 "data/maps/Route25_SeaCottage/scripts.pory"
	msgbox Route25_SeaCottage_Text_NoPleaseChief
# 74 "data/maps/Route25_SeaCottage/scripts.pory"
	return
# 75 "data/maps/Route25_SeaCottage/scripts.pory"

# 76 "data/maps/Route25_SeaCottage/scripts.pory"
Route25_SeaCottage_EventScript_DeclineHelpBillFemale::
# 77 "data/maps/Route25_SeaCottage/scripts.pory"
	msgbox Route25_SeaCottage_Text_NoPleaseBeautiful
# 78 "data/maps/Route25_SeaCottage/scripts.pory"
	return
# 79 "data/maps/Route25_SeaCottage/scripts.pory"

# 80 "data/maps/Route25_SeaCottage/scripts.pory"
Route25_SeaCottage_EventScript_BillWalkToTeleporterSouth::
# 81 "data/maps/Route25_SeaCottage/scripts.pory"
	applymovement LOCALID_BILL_CLEFAIRY, Route25_SeaCottage_Movement_BillWalkToTeleporterSouth
# 82 "data/maps/Route25_SeaCottage/scripts.pory"
	waitmovement 0
# 83 "data/maps/Route25_SeaCottage/scripts.pory"
	return
# 84 "data/maps/Route25_SeaCottage/scripts.pory"

# 85 "data/maps/Route25_SeaCottage/scripts.pory"
Route25_SeaCottage_EventScript_BillWalkToTeleporter::
# 86 "data/maps/Route25_SeaCottage/scripts.pory"
	applymovement LOCALID_BILL_CLEFAIRY, Route25_SeaCottage_Movement_BillWalkToTeleporter
# 87 "data/maps/Route25_SeaCottage/scripts.pory"
	waitmovement 0
# 88 "data/maps/Route25_SeaCottage/scripts.pory"
	return
# 89 "data/maps/Route25_SeaCottage/scripts.pory"

# 90 "data/maps/Route25_SeaCottage/scripts.pory"
Route25_SeaCottage_EventScript_BillGoToSSAnne::
# 91 "data/maps/Route25_SeaCottage/scripts.pory"
	msgbox Route25_SeaCottage_Text_SSAnnePartyYouGoInstead
# 92 "data/maps/Route25_SeaCottage/scripts.pory"
	release
# 93 "data/maps/Route25_SeaCottage/scripts.pory"
	end
# 94 "data/maps/Route25_SeaCottage/scripts.pory"

# 95 "data/maps/Route25_SeaCottage/scripts.pory"
Route25_SeaCottage_EventScript_BillGiveSSTicket::
# 96 "data/maps/Route25_SeaCottage/scripts.pory"
	famechecker FAMECHECKER_BILL, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
# 97 "data/maps/Route25_SeaCottage/scripts.pory"
	checkplayergender
# 98 "data/maps/Route25_SeaCottage/scripts.pory"
	call_if_eq VAR_RESULT, MALE, Route25_SeaCottage_EventScript_BillThanksMale
# 99 "data/maps/Route25_SeaCottage/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, Route25_SeaCottage_EventScript_BillThanksFemale
# 100 "data/maps/Route25_SeaCottage/scripts.pory"
	checkitemspace ITEM_SS_TICKET
# 101 "data/maps/Route25_SeaCottage/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route25_SeaCottage_EventScript_NoRoomForSSTicket
# 102 "data/maps/Route25_SeaCottage/scripts.pory"
	giveitem_msg Route25_SeaCottage_Text_ReceivedSSTicketFromBill, ITEM_SS_TICKET, 1, MUS_OBTAIN_KEY_ITEM
# 103 "data/maps/Route25_SeaCottage/scripts.pory"
	setflag FLAG_GOT_SS_TICKET_DUP
# 104 "data/maps/Route25_SeaCottage/scripts.pory"
	setflag FLAG_HIDE_NUGGET_BRIDGE_ROCKET
# 105 "data/maps/Route25_SeaCottage/scripts.pory"
	setflag FLAG_GOT_SS_TICKET
# 106 "data/maps/Route25_SeaCottage/scripts.pory"
	setflag FLAG_SYS_NOT_SOMEONES_PC
# 107 "data/maps/Route25_SeaCottage/scripts.pory"
	goto Route25_SeaCottage_EventScript_BillGoToSSAnne
# 108 "data/maps/Route25_SeaCottage/scripts.pory"
	end
# 109 "data/maps/Route25_SeaCottage/scripts.pory"

# 110 "data/maps/Route25_SeaCottage/scripts.pory"
Route25_SeaCottage_EventScript_BillThanksMale::
# 111 "data/maps/Route25_SeaCottage/scripts.pory"
	msgbox Route25_SeaCottage_Text_ThanksBudTakeThis
# 112 "data/maps/Route25_SeaCottage/scripts.pory"
	return
# 113 "data/maps/Route25_SeaCottage/scripts.pory"

# 114 "data/maps/Route25_SeaCottage/scripts.pory"
Route25_SeaCottage_EventScript_BillThanksFemale::
# 115 "data/maps/Route25_SeaCottage/scripts.pory"
	msgbox Route25_SeaCottage_Text_ThanksLadyTakeThis
# 116 "data/maps/Route25_SeaCottage/scripts.pory"
	return
# 117 "data/maps/Route25_SeaCottage/scripts.pory"

# 118 "data/maps/Route25_SeaCottage/scripts.pory"
Route25_SeaCottage_EventScript_NoRoomForSSTicket::
# 119 "data/maps/Route25_SeaCottage/scripts.pory"
	msgbox Route25_SeaCottage_Text_YouveGotTooMuchStuff
# 120 "data/maps/Route25_SeaCottage/scripts.pory"
	release
# 121 "data/maps/Route25_SeaCottage/scripts.pory"
	end
# 122 "data/maps/Route25_SeaCottage/scripts.pory"

# 123 "data/maps/Route25_SeaCottage/scripts.pory"
Route25_SeaCottage_EventScript_BillGoLookAtPC::
# 124 "data/maps/Route25_SeaCottage/scripts.pory"
	msgbox Route25_SeaCottage_Text_CheckOutRareMonsOnPC
# 125 "data/maps/Route25_SeaCottage/scripts.pory"
	release
# 126 "data/maps/Route25_SeaCottage/scripts.pory"
	end
# 127 "data/maps/Route25_SeaCottage/scripts.pory"

# 128 "data/maps/Route25_SeaCottage/scripts.pory"
Route25_SeaCottage_Movement_BillWalkToTeleporter::
# 129 "data/maps/Route25_SeaCottage/scripts.pory"
	walk_up
# 130 "data/maps/Route25_SeaCottage/scripts.pory"
	walk_up
# 131 "data/maps/Route25_SeaCottage/scripts.pory"
	step_end
# 132 "data/maps/Route25_SeaCottage/scripts.pory"

# 133 "data/maps/Route25_SeaCottage/scripts.pory"
Route25_SeaCottage_Movement_BillWalkToTeleporterSouth::
# 134 "data/maps/Route25_SeaCottage/scripts.pory"
	walk_right
# 135 "data/maps/Route25_SeaCottage/scripts.pory"
	walk_up
# 136 "data/maps/Route25_SeaCottage/scripts.pory"
	walk_up
# 137 "data/maps/Route25_SeaCottage/scripts.pory"
	walk_left
# 138 "data/maps/Route25_SeaCottage/scripts.pory"
	walk_in_place_faster_up
# 139 "data/maps/Route25_SeaCottage/scripts.pory"
	step_end
# 140 "data/maps/Route25_SeaCottage/scripts.pory"

# 141 "data/maps/Route25_SeaCottage/scripts.pory"
Route25_SeaCottage_Movement_BillEnterTeleporter::
# 142 "data/maps/Route25_SeaCottage/scripts.pory"
	walk_up
# 143 "data/maps/Route25_SeaCottage/scripts.pory"
	step_end
# 144 "data/maps/Route25_SeaCottage/scripts.pory"

# 145 "data/maps/Route25_SeaCottage/scripts.pory"
Route25_SeaCottage_EventScript_Computer::
# 146 "data/maps/Route25_SeaCottage/scripts.pory"
	lockall
# 147 "data/maps/Route25_SeaCottage/scripts.pory"
	goto_if_set RETURN_AFTER_SS_TICKET, Route25_SeaCottage_EventScript_OpenBillsMonList
# 148 "data/maps/Route25_SeaCottage/scripts.pory"
	goto_if_set BILL_IN_TELEPORTER, Route25_SeaCottage_EventScript_RunCellSeparator
# 149 "data/maps/Route25_SeaCottage/scripts.pory"
	msgbox Route25_SeaCottage_Text_TeleporterIsDisplayed
# 150 "data/maps/Route25_SeaCottage/scripts.pory"
	releaseall
# 151 "data/maps/Route25_SeaCottage/scripts.pory"
	end
# 152 "data/maps/Route25_SeaCottage/scripts.pory"

# 153 "data/maps/Route25_SeaCottage/scripts.pory"
Route25_SeaCottage_EventScript_RunCellSeparator::
# 154 "data/maps/Route25_SeaCottage/scripts.pory"
	fadeoutbgm 0
# 155 "data/maps/Route25_SeaCottage/scripts.pory"
	msgbox Route25_SeaCottage_Text_InitiatedTeleportersCellSeparator
# 156 "data/maps/Route25_SeaCottage/scripts.pory"
	closemessage
# 157 "data/maps/Route25_SeaCottage/scripts.pory"
	clearflag BILL_IN_TELEPORTER
# 158 "data/maps/Route25_SeaCottage/scripts.pory"
	setflag FLAG_HELPED_BILL_IN_SEA_COTTAGE
# 159 "data/maps/Route25_SeaCottage/scripts.pory"
	special SpawnCameraObject
# 160 "data/maps/Route25_SeaCottage/scripts.pory"
	applymovement LOCALID_CAMERA, Route25_SeaCottage_Movement_CameraPanToTeleporters
# 161 "data/maps/Route25_SeaCottage/scripts.pory"
	waitmovement 0
# 162 "data/maps/Route25_SeaCottage/scripts.pory"
	delay 35
# 163 "data/maps/Route25_SeaCottage/scripts.pory"
	playse SE_PIN
# 164 "data/maps/Route25_SeaCottage/scripts.pory"
	waitse
# 165 "data/maps/Route25_SeaCottage/scripts.pory"
	setvar VAR_0x8004, 0
# 166 "data/maps/Route25_SeaCottage/scripts.pory"
	special AnimateTeleporterHousing
# 167 "data/maps/Route25_SeaCottage/scripts.pory"
	delay 10
# 168 "data/maps/Route25_SeaCottage/scripts.pory"
	call Route25_SeaCottage_EventScript_PlayTeleporterBeepSE
# 169 "data/maps/Route25_SeaCottage/scripts.pory"
	call Route25_SeaCottage_EventScript_PlayTeleporterBeepSE
# 170 "data/maps/Route25_SeaCottage/scripts.pory"
	call Route25_SeaCottage_EventScript_PlayTeleporterBeepSE
# 171 "data/maps/Route25_SeaCottage/scripts.pory"
	call Route25_SeaCottage_EventScript_PlayTeleporterBeepSE
# 172 "data/maps/Route25_SeaCottage/scripts.pory"
	call Route25_SeaCottage_EventScript_PlayTeleporterBeepSE
# 173 "data/maps/Route25_SeaCottage/scripts.pory"
	call Route25_SeaCottage_EventScript_PlayTeleporterBeepSE
# 174 "data/maps/Route25_SeaCottage/scripts.pory"
	call Route25_SeaCottage_EventScript_PlayTeleporterBeepSE
# 175 "data/maps/Route25_SeaCottage/scripts.pory"
	setvar VAR_0x8004, 1
# 176 "data/maps/Route25_SeaCottage/scripts.pory"
	special AnimateTeleporterHousing
# 177 "data/maps/Route25_SeaCottage/scripts.pory"
	playse SE_WARP_IN
# 178 "data/maps/Route25_SeaCottage/scripts.pory"
	special AnimateTeleporterCable
# 179 "data/maps/Route25_SeaCottage/scripts.pory"
	waitse
# 180 "data/maps/Route25_SeaCottage/scripts.pory"
	call Route25_SeaCottage_EventScript_PlayTeleporterBeepSE
# 181 "data/maps/Route25_SeaCottage/scripts.pory"
	call Route25_SeaCottage_EventScript_PlayTeleporterBeepSE
# 182 "data/maps/Route25_SeaCottage/scripts.pory"
	call Route25_SeaCottage_EventScript_PlayTeleporterBeepSE
# 183 "data/maps/Route25_SeaCottage/scripts.pory"
	call Route25_SeaCottage_EventScript_PlayTeleporterBeepSE
# 184 "data/maps/Route25_SeaCottage/scripts.pory"
	call Route25_SeaCottage_EventScript_PlayTeleporterBeepSE
# 185 "data/maps/Route25_SeaCottage/scripts.pory"
	opendoor 3, 3
# 186 "data/maps/Route25_SeaCottage/scripts.pory"
	waitdooranim
# 187 "data/maps/Route25_SeaCottage/scripts.pory"
	fadeinbgm 0
# 188 "data/maps/Route25_SeaCottage/scripts.pory"
	addobject LOCALID_BILL_HUMAN
# 189 "data/maps/Route25_SeaCottage/scripts.pory"
	clearflag FLAG_HIDE_BILL_HUMAN_SEA_COTTAGE
# 190 "data/maps/Route25_SeaCottage/scripts.pory"
	delay 50
# 191 "data/maps/Route25_SeaCottage/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 192 "data/maps/Route25_SeaCottage/scripts.pory"
	applymovement LOCALID_BILL_HUMAN, Route25_SeaCottage_Movement_BillExitTeleporter
# 193 "data/maps/Route25_SeaCottage/scripts.pory"
	waitmovement 0
# 194 "data/maps/Route25_SeaCottage/scripts.pory"
	waitfanfare
# 195 "data/maps/Route25_SeaCottage/scripts.pory"
	applymovement LOCALID_CAMERA, Route25_SeaCottage_Movement_CameraPanBackFromTeleporters
# 196 "data/maps/Route25_SeaCottage/scripts.pory"
	waitmovement 0
# 197 "data/maps/Route25_SeaCottage/scripts.pory"
	playse SE_CONTEST_CURTAIN_FALL
# 198 "data/maps/Route25_SeaCottage/scripts.pory"
	closedoor 3, 3
# 199 "data/maps/Route25_SeaCottage/scripts.pory"
	waitdooranim
# 200 "data/maps/Route25_SeaCottage/scripts.pory"
	applymovement LOCALID_BILL_HUMAN, Route25_SeaCottage_Movement_BillWalkToMiddleOfRoom
# 201 "data/maps/Route25_SeaCottage/scripts.pory"
	waitmovement 0
# 202 "data/maps/Route25_SeaCottage/scripts.pory"
	special RemoveCameraObject
# 203 "data/maps/Route25_SeaCottage/scripts.pory"
	releaseall
# 204 "data/maps/Route25_SeaCottage/scripts.pory"
	end
# 205 "data/maps/Route25_SeaCottage/scripts.pory"

# 206 "data/maps/Route25_SeaCottage/scripts.pory"
Route25_SeaCottage_EventScript_PlayTeleporterBeepSE::
# 207 "data/maps/Route25_SeaCottage/scripts.pory"
	playse SE_BALL
# 208 "data/maps/Route25_SeaCottage/scripts.pory"
	waitse
# 209 "data/maps/Route25_SeaCottage/scripts.pory"
	delay 20
# 210 "data/maps/Route25_SeaCottage/scripts.pory"
	return
# 211 "data/maps/Route25_SeaCottage/scripts.pory"

# 212 "data/maps/Route25_SeaCottage/scripts.pory"
Route25_SeaCottage_Movement_CameraPanToTeleporters::
# 213 "data/maps/Route25_SeaCottage/scripts.pory"
	walk_up
# 214 "data/maps/Route25_SeaCottage/scripts.pory"
	walk_up
# 215 "data/maps/Route25_SeaCottage/scripts.pory"
	walk_right
# 216 "data/maps/Route25_SeaCottage/scripts.pory"
	walk_right
# 217 "data/maps/Route25_SeaCottage/scripts.pory"
	step_end
# 218 "data/maps/Route25_SeaCottage/scripts.pory"

# 219 "data/maps/Route25_SeaCottage/scripts.pory"
Route25_SeaCottage_Movement_CameraPanBackFromTeleporters::
# 220 "data/maps/Route25_SeaCottage/scripts.pory"
	delay_16
# 221 "data/maps/Route25_SeaCottage/scripts.pory"
	delay_16
# 222 "data/maps/Route25_SeaCottage/scripts.pory"
	walk_down
# 223 "data/maps/Route25_SeaCottage/scripts.pory"
	walk_down
# 224 "data/maps/Route25_SeaCottage/scripts.pory"
	walk_left
# 225 "data/maps/Route25_SeaCottage/scripts.pory"
	walk_left
# 226 "data/maps/Route25_SeaCottage/scripts.pory"
	step_end
# 227 "data/maps/Route25_SeaCottage/scripts.pory"

# 228 "data/maps/Route25_SeaCottage/scripts.pory"
Route25_SeaCottage_EventScript_OpenBillsMonList::
# 229 "data/maps/Route25_SeaCottage/scripts.pory"
	msgbox Route25_SeaCottage_Text_BillsFavoriteMonList
# 230 "data/maps/Route25_SeaCottage/scripts.pory"
	goto Route25_SeaCottage_EventScript_BillsMonList
# 231 "data/maps/Route25_SeaCottage/scripts.pory"
	end
# 232 "data/maps/Route25_SeaCottage/scripts.pory"

# 233 "data/maps/Route25_SeaCottage/scripts.pory"
Route25_SeaCottage_EventScript_BillsMonList::
# 234 "data/maps/Route25_SeaCottage/scripts.pory"
	message Route25_SeaCottage_Text_SeeWhichMon
# 235 "data/maps/Route25_SeaCottage/scripts.pory"
	waitmessage
# 236 "data/maps/Route25_SeaCottage/scripts.pory"
	multichoice 0, 0, MULTICHOICE_EEVEELUTIONS, FALSE
# 237 "data/maps/Route25_SeaCottage/scripts.pory"
	switch VAR_RESULT
# 238 "data/maps/Route25_SeaCottage/scripts.pory"
	case 0, Route25_SeaCottage_EventScript_ViewEevee
# 239 "data/maps/Route25_SeaCottage/scripts.pory"
	case 1, Route25_SeaCottage_EventScript_ViewFlareon
# 240 "data/maps/Route25_SeaCottage/scripts.pory"
	case 2, Route25_SeaCottage_EventScript_ViewJolteon
# 241 "data/maps/Route25_SeaCottage/scripts.pory"
	case 3, Route25_SeaCottage_EventScript_ViewVaporeon
# 242 "data/maps/Route25_SeaCottage/scripts.pory"
	case 4, Route25_SeaCottage_EventScript_ExitBillsMonList
# 243 "data/maps/Route25_SeaCottage/scripts.pory"
	case 127, Route25_SeaCottage_EventScript_ExitBillsMonList
# 244 "data/maps/Route25_SeaCottage/scripts.pory"
	end
# 245 "data/maps/Route25_SeaCottage/scripts.pory"

# 246 "data/maps/Route25_SeaCottage/scripts.pory"
Route25_SeaCottage_EventScript_ViewEevee::
# 247 "data/maps/Route25_SeaCottage/scripts.pory"
	showmonpic SPECIES_EEVEE, 10, 3
# 248 "data/maps/Route25_SeaCottage/scripts.pory"
	waitbuttonpress
# 249 "data/maps/Route25_SeaCottage/scripts.pory"
	hidemonpic
# 250 "data/maps/Route25_SeaCottage/scripts.pory"
	setvar VAR_0x8004, SPECIES_EEVEE
# 251 "data/maps/Route25_SeaCottage/scripts.pory"
	special SetSeenMon
# 252 "data/maps/Route25_SeaCottage/scripts.pory"
	goto Route25_SeaCottage_EventScript_BillsMonList
# 253 "data/maps/Route25_SeaCottage/scripts.pory"
	end
# 254 "data/maps/Route25_SeaCottage/scripts.pory"

# 255 "data/maps/Route25_SeaCottage/scripts.pory"
Route25_SeaCottage_EventScript_ViewFlareon::
# 256 "data/maps/Route25_SeaCottage/scripts.pory"
	showmonpic SPECIES_FLAREON, 10, 3
# 257 "data/maps/Route25_SeaCottage/scripts.pory"
	waitbuttonpress
# 258 "data/maps/Route25_SeaCottage/scripts.pory"
	hidemonpic
# 259 "data/maps/Route25_SeaCottage/scripts.pory"
	setvar VAR_0x8004, SPECIES_FLAREON
# 260 "data/maps/Route25_SeaCottage/scripts.pory"
	special SetSeenMon
# 261 "data/maps/Route25_SeaCottage/scripts.pory"
	goto Route25_SeaCottage_EventScript_BillsMonList
# 262 "data/maps/Route25_SeaCottage/scripts.pory"
	end
# 263 "data/maps/Route25_SeaCottage/scripts.pory"

# 264 "data/maps/Route25_SeaCottage/scripts.pory"
Route25_SeaCottage_EventScript_ViewJolteon::
# 265 "data/maps/Route25_SeaCottage/scripts.pory"
	showmonpic SPECIES_JOLTEON, 10, 3
# 266 "data/maps/Route25_SeaCottage/scripts.pory"
	waitbuttonpress
# 267 "data/maps/Route25_SeaCottage/scripts.pory"
	hidemonpic
# 268 "data/maps/Route25_SeaCottage/scripts.pory"
	setvar VAR_0x8004, SPECIES_JOLTEON
# 269 "data/maps/Route25_SeaCottage/scripts.pory"
	special SetSeenMon
# 270 "data/maps/Route25_SeaCottage/scripts.pory"
	goto Route25_SeaCottage_EventScript_BillsMonList
# 271 "data/maps/Route25_SeaCottage/scripts.pory"
	end
# 272 "data/maps/Route25_SeaCottage/scripts.pory"

# 273 "data/maps/Route25_SeaCottage/scripts.pory"
Route25_SeaCottage_EventScript_ViewVaporeon::
# 274 "data/maps/Route25_SeaCottage/scripts.pory"
	showmonpic SPECIES_VAPOREON, 10, 3
# 275 "data/maps/Route25_SeaCottage/scripts.pory"
	waitbuttonpress
# 276 "data/maps/Route25_SeaCottage/scripts.pory"
	hidemonpic
# 277 "data/maps/Route25_SeaCottage/scripts.pory"
	setvar VAR_0x8004, SPECIES_VAPOREON
# 278 "data/maps/Route25_SeaCottage/scripts.pory"
	special SetSeenMon
# 279 "data/maps/Route25_SeaCottage/scripts.pory"
	goto Route25_SeaCottage_EventScript_BillsMonList
# 280 "data/maps/Route25_SeaCottage/scripts.pory"
	end
# 281 "data/maps/Route25_SeaCottage/scripts.pory"

# 282 "data/maps/Route25_SeaCottage/scripts.pory"
Route25_SeaCottage_EventScript_ExitBillsMonList::
# 283 "data/maps/Route25_SeaCottage/scripts.pory"
	releaseall
# 284 "data/maps/Route25_SeaCottage/scripts.pory"
	end
# 285 "data/maps/Route25_SeaCottage/scripts.pory"

# 286 "data/maps/Route25_SeaCottage/scripts.pory"
Route25_SeaCottage_Movement_BillWalkToMiddleOfRoom::
# 287 "data/maps/Route25_SeaCottage/scripts.pory"
	walk_right
# 288 "data/maps/Route25_SeaCottage/scripts.pory"
	walk_right
# 289 "data/maps/Route25_SeaCottage/scripts.pory"
	walk_right
# 290 "data/maps/Route25_SeaCottage/scripts.pory"
	walk_right
# 291 "data/maps/Route25_SeaCottage/scripts.pory"
	walk_down
# 292 "data/maps/Route25_SeaCottage/scripts.pory"
	walk_down
# 293 "data/maps/Route25_SeaCottage/scripts.pory"
	step_end
# 294 "data/maps/Route25_SeaCottage/scripts.pory"

# 295 "data/maps/Route25_SeaCottage/scripts.pory"
Route25_SeaCottage_Movement_BillExitTeleporter::
# 296 "data/maps/Route25_SeaCottage/scripts.pory"
	walk_down
# 297 "data/maps/Route25_SeaCottage/scripts.pory"
	step_end
