# 1 "data/maps/VermilionCity/scripts.pory"

# 2 "data/maps/VermilionCity/scripts.pory"
VermilionCity_MapScripts::
# 3 "data/maps/VermilionCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_OnTransition
# 4 "data/maps/VermilionCity/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VermilionCity_OnFrame
# 5 "data/maps/VermilionCity/scripts.pory"
	.byte 0
# 6 "data/maps/VermilionCity/scripts.pory"

# 7 "data/maps/VermilionCity/scripts.pory"
VermilionCity_OnFrame::
# 8 "data/maps/VermilionCity/scripts.pory"
	map_script_2 VAR_MAP_SCENE_VERMILION_CITY, 2, VermilionCity_EventScript_ExitSSAnne
# 9 "data/maps/VermilionCity/scripts.pory"
	.2byte 0
# 10 "data/maps/VermilionCity/scripts.pory"

# 11 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ExitSSAnne::
# 12 "data/maps/VermilionCity/scripts.pory"
	lockall
# 13 "data/maps/VermilionCity/scripts.pory"
	applymovement LOCALID_PLAYER, VermilionCity_Movement_ExitSSAnne
# 14 "data/maps/VermilionCity/scripts.pory"
	waitmovement 0
# 15 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_MAP_SCENE_VERMILION_CITY, 3
# 16 "data/maps/VermilionCity/scripts.pory"
	releaseall
# 17 "data/maps/VermilionCity/scripts.pory"
	end
# 18 "data/maps/VermilionCity/scripts.pory"

# 19 "data/maps/VermilionCity/scripts.pory"
VermilionCity_Movement_ExitSSAnne::
# 20 "data/maps/VermilionCity/scripts.pory"
	walk_up
# 21 "data/maps/VermilionCity/scripts.pory"
	walk_up
# 22 "data/maps/VermilionCity/scripts.pory"
	step_end
# 23 "data/maps/VermilionCity/scripts.pory"

# 24 "data/maps/VermilionCity/scripts.pory"
VermilionCity_OnTransition::
# 25 "data/maps/VermilionCity/scripts.pory"
	setworldmapflag FLAG_WORLD_MAP_VERMILION_CITY
# 26 "data/maps/VermilionCity/scripts.pory"
	call_if_set FLAG_TALKED_TO_OAKS_AIDE_IN_VERMILION, VermilionCity_EventScript_HideOaksAide
# 27 "data/maps/VermilionCity/scripts.pory"
	end
# 28 "data/maps/VermilionCity/scripts.pory"

# 29 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_HideOaksAide::
# 30 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_HIDE_VERMILION_CITY_OAKS_AIDE
# 31 "data/maps/VermilionCity/scripts.pory"
	return
# 32 "data/maps/VermilionCity/scripts.pory"

# 33 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_Woman::
# 34 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_GrimerMultipliesInSludge, MSGBOX_NPC
# 35 "data/maps/VermilionCity/scripts.pory"
	end
# 36 "data/maps/VermilionCity/scripts.pory"

# 37 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_OldMan1::
# 38 "data/maps/VermilionCity/scripts.pory"
	lock
# 39 "data/maps/VermilionCity/scripts.pory"
	faceplayer
# 40 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_VERMILION_CITY, 3, VermilionCity_EventScript_OldMan1SSAnneLeft
# 41 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DidYouSeeSSAnneInHarbor
# 42 "data/maps/VermilionCity/scripts.pory"
	release
# 43 "data/maps/VermilionCity/scripts.pory"
	end
# 44 "data/maps/VermilionCity/scripts.pory"

# 45 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_OldMan1SSAnneLeft::
# 46 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_SSAnneHasDepartedForYear
# 47 "data/maps/VermilionCity/scripts.pory"
	release
# 48 "data/maps/VermilionCity/scripts.pory"
	end
# 49 "data/maps/VermilionCity/scripts.pory"

# 50 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_FerrySailor::
# 51 "data/maps/VermilionCity/scripts.pory"
	lock
# 52 "data/maps/VermilionCity/scripts.pory"
	faceplayer
# 53 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_VERMILION_CITY, 3, VermilionCity_EventScript_CheckSeagallopPresent
# 54 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_WelcomeToTheSSAnne
# 55 "data/maps/VermilionCity/scripts.pory"
	release
# 56 "data/maps/VermilionCity/scripts.pory"
	end
# 57 "data/maps/VermilionCity/scripts.pory"

# 58 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckHasMysticTicket::
# 59 "data/maps/VermilionCity/scripts.pory"
	goto_if_unset FLAG_ENABLE_SHIP_NAVEL_ROCK, EventScript_SetResultFalse
# 60 "data/maps/VermilionCity/scripts.pory"
	checkitem ITEM_MYSTIC_TICKET
# 61 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, EventScript_SetResultFalse
# 62 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SetResultTrue
# 63 "data/maps/VermilionCity/scripts.pory"
	end
# 64 "data/maps/VermilionCity/scripts.pory"

# 65 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckHasAuroraTicket::
# 66 "data/maps/VermilionCity/scripts.pory"
	goto_if_unset FLAG_ENABLE_SHIP_BIRTH_ISLAND, EventScript_SetResultFalse
# 67 "data/maps/VermilionCity/scripts.pory"
	checkitem ITEM_AURORA_TICKET
# 68 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, EventScript_SetResultFalse
# 69 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SetResultTrue
# 70 "data/maps/VermilionCity/scripts.pory"
	end
# 71 "data/maps/VermilionCity/scripts.pory"

# 72 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckSeagallopPresent::
# 73 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 74 "data/maps/VermilionCity/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 5, VermilionCity_EventScript_ChooseSeagallopDestRainbowPass
# 75 "data/maps/VermilionCity/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 1, VermilionCity_EventScript_ChooseSeagallopDestTriPass
# 76 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_TheShipSetSail
# 77 "data/maps/VermilionCity/scripts.pory"
	release
# 78 "data/maps/VermilionCity/scripts.pory"
	end
# 79 "data/maps/VermilionCity/scripts.pory"

# 80 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ChooseSeagallopDestRainbowPass::
# 81 "data/maps/VermilionCity/scripts.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 82 "data/maps/VermilionCity/scripts.pory"
	special QuestLog_CutRecording
# 83 "data/maps/VermilionCity/scripts.pory"
	call VermilionCity_EventScript_CheckHasMysticTicket
# 84 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, VermilionCity_EventScript_HasMysticTicket
# 85 "data/maps/VermilionCity/scripts.pory"
	call VermilionCity_EventScript_CheckHasAuroraTicket
# 86 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, VermilionCity_EventScript_HasAuroraTicket
# 87 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 88 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopRainbowPass
# 89 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 90 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SeviiDestinationsPage1
# 91 "data/maps/VermilionCity/scripts.pory"
	end
# 92 "data/maps/VermilionCity/scripts.pory"

# 93 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_HasMysticTicket::
# 94 "data/maps/VermilionCity/scripts.pory"
	call VermilionCity_EventScript_CheckHasAuroraTicket
# 95 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, VermilionCity_EventScript_HasMysticAndAuroraTickets
# 96 "data/maps/VermilionCity/scripts.pory"
	call_if_unset FLAG_SHOWN_MYSTIC_TICKET, VermilionCity_EventScript_ShowMysticTicket
# 97 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopFerry
# 98 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 99 "data/maps/VermilionCity/scripts.pory"
	multichoice 17, 6, MULTICHOICE_SEVII_NAVEL, FALSE
# 100 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 101 "data/maps/VermilionCity/scripts.pory"
	case 0, EventScript_SeviiDestinationsPage1
# 102 "data/maps/VermilionCity/scripts.pory"
	case 1, EventScript_SailToNavelRock
# 103 "data/maps/VermilionCity/scripts.pory"
	case 2, EventScript_CancelSail
# 104 "data/maps/VermilionCity/scripts.pory"
	case 127, EventScript_CancelSail
# 105 "data/maps/VermilionCity/scripts.pory"
	end
# 106 "data/maps/VermilionCity/scripts.pory"

# 107 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ShowMysticTicket::
# 108 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_SHOWN_MYSTIC_TICKET
# 109 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_OhMysticTicketTakeYouToNavelRock
# 110 "data/maps/VermilionCity/scripts.pory"
	return
# 111 "data/maps/VermilionCity/scripts.pory"

# 112 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_HasAuroraTicket::
# 113 "data/maps/VermilionCity/scripts.pory"
	call_if_unset FLAG_SHOWN_AURORA_TICKET, VermilionCity_EventScript_ShowAuroraTicket
# 114 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopFerry
# 115 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 116 "data/maps/VermilionCity/scripts.pory"
	multichoice 13, 6, MULTICHOICE_SEVII_BIRTH, FALSE
# 117 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 118 "data/maps/VermilionCity/scripts.pory"
	case 0, EventScript_SeviiDestinationsPage1
# 119 "data/maps/VermilionCity/scripts.pory"
	case 1, EventScript_SailToBirthIsland
# 120 "data/maps/VermilionCity/scripts.pory"
	case 2, EventScript_CancelSail
# 121 "data/maps/VermilionCity/scripts.pory"
	case 127, EventScript_CancelSail
# 122 "data/maps/VermilionCity/scripts.pory"
	end
# 123 "data/maps/VermilionCity/scripts.pory"

# 124 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ShowAuroraTicket::
# 125 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_SHOWN_AURORA_TICKET
# 126 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_OhAuroraTicketTakeYouToBirthIsland
# 127 "data/maps/VermilionCity/scripts.pory"
	return
# 128 "data/maps/VermilionCity/scripts.pory"

# 129 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_HasMysticAndAuroraTickets::
# 130 "data/maps/VermilionCity/scripts.pory"
	call_if_unset FLAG_SHOWN_MYSTIC_TICKET, VermilionCity_EventScript_ShowMysticTicket
# 131 "data/maps/VermilionCity/scripts.pory"
	call_if_unset FLAG_SHOWN_AURORA_TICKET, VermilionCity_EventScript_ShowAuroraTicket
# 132 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopFerry
# 133 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 134 "data/maps/VermilionCity/scripts.pory"
	multichoice 13, 5, MULTICHOICE_SEVII_NAVEL_BIRTH, FALSE
# 135 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 136 "data/maps/VermilionCity/scripts.pory"
	case 0, EventScript_SeviiDestinationsPage1
# 137 "data/maps/VermilionCity/scripts.pory"
	case 1, EventScript_SailToNavelRock
# 138 "data/maps/VermilionCity/scripts.pory"
	case 2, EventScript_SailToBirthIsland
# 139 "data/maps/VermilionCity/scripts.pory"
	case 3, EventScript_CancelSail
# 140 "data/maps/VermilionCity/scripts.pory"
	case 127, EventScript_CancelSail
# 141 "data/maps/VermilionCity/scripts.pory"
	end
# 142 "data/maps/VermilionCity/scripts.pory"

# 143 "data/maps/VermilionCity/scripts.pory"
EventScript_SailToNavelRock::
# 144 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_Seagallop10Departing
# 145 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 146 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8006, SEAGALLOP_NAVEL_ROCK
# 147 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SetSail
# 148 "data/maps/VermilionCity/scripts.pory"
	end
# 149 "data/maps/VermilionCity/scripts.pory"

# 150 "data/maps/VermilionCity/scripts.pory"
EventScript_SailToBirthIsland::
# 151 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_Seagallop12Departing
# 152 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 153 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8006, SEAGALLOP_BIRTH_ISLAND
# 154 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SetSail
# 155 "data/maps/VermilionCity/scripts.pory"
	end
# 156 "data/maps/VermilionCity/scripts.pory"

# 157 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ChooseSeagallopDestTriPass::
# 158 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopTriPass
# 159 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 160 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 161 "data/maps/VermilionCity/scripts.pory"
	multichoice 19, 5, MULTICHOICE_SEAGALLOP_123, FALSE
# 162 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 163 "data/maps/VermilionCity/scripts.pory"
	case 0, EventScript_SailToOneIsland2
# 164 "data/maps/VermilionCity/scripts.pory"
	case 1, EventScript_SailToTwoIsland2
# 165 "data/maps/VermilionCity/scripts.pory"
	case 2, EventScript_SailToThreeIsland2
# 166 "data/maps/VermilionCity/scripts.pory"
	case 3, EventScript_CancelSail
# 167 "data/maps/VermilionCity/scripts.pory"
	case 127, EventScript_CancelSail
# 168 "data/maps/VermilionCity/scripts.pory"
	end
# 169 "data/maps/VermilionCity/scripts.pory"

# 170 "data/maps/VermilionCity/scripts.pory"
@ Unreachable
# 171 "data/maps/VermilionCity/scripts.pory"
Vermilion_EventScript_Unused::
# 172 "data/maps/VermilionCity/scripts.pory"
	release
# 173 "data/maps/VermilionCity/scripts.pory"
	end
# 174 "data/maps/VermilionCity/scripts.pory"

# 175 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckTicketLeft::
# 176 "data/maps/VermilionCity/scripts.pory"
	lockall
# 177 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_CheckTicket
# 178 "data/maps/VermilionCity/scripts.pory"
	end
# 179 "data/maps/VermilionCity/scripts.pory"

# 180 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckTicketRight::
# 181 "data/maps/VermilionCity/scripts.pory"
	lockall
# 182 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_CheckTicket
# 183 "data/maps/VermilionCity/scripts.pory"
	end
# 184 "data/maps/VermilionCity/scripts.pory"

# 185 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ExitedTicketCheck::
# 186 "data/maps/VermilionCity/scripts.pory"
	lockall
# 187 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_VERMILION_CITY_TICKET_CHECK_TRIGGER, 0
# 188 "data/maps/VermilionCity/scripts.pory"
	releaseall
# 189 "data/maps/VermilionCity/scripts.pory"
	end
# 190 "data/maps/VermilionCity/scripts.pory"

# 191 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_DontHaveSSTicket::
# 192 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DontHaveNeededSSTicket
# 193 "data/maps/VermilionCity/scripts.pory"
	closemessage
# 194 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_WalkUpPier
# 195 "data/maps/VermilionCity/scripts.pory"
	end
# 196 "data/maps/VermilionCity/scripts.pory"

# 197 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckSeagallopPresentTrigger::
# 198 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 199 "data/maps/VermilionCity/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 5, VermilionCity_EventScript_ChooseSeagallopDestRainbowPass
# 200 "data/maps/VermilionCity/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 1, VermilionCity_EventScript_ChooseSeagallopDestTriPass
# 201 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_TheShipSetSail
# 202 "data/maps/VermilionCity/scripts.pory"
	closemessage
# 203 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_WalkUpPier
# 204 "data/maps/VermilionCity/scripts.pory"
	end
# 205 "data/maps/VermilionCity/scripts.pory"

# 206 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_Sailor::
# 207 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_SSAnneVisitsOnceAYear, MSGBOX_NPC
# 208 "data/maps/VermilionCity/scripts.pory"
	end
# 209 "data/maps/VermilionCity/scripts.pory"

# 210 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_OaksAide::
# 211 "data/maps/VermilionCity/scripts.pory"
	lock
# 212 "data/maps/VermilionCity/scripts.pory"
	faceplayer
# 213 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_TALKED_TO_OAKS_AIDE_IN_VERMILION
# 214 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_Route2AideHasPackageForYou
# 215 "data/maps/VermilionCity/scripts.pory"
	release
# 216 "data/maps/VermilionCity/scripts.pory"
	end
# 217 "data/maps/VermilionCity/scripts.pory"

# 218 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_OldMan2::
# 219 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_BuildingOnThisLand, MSGBOX_NPC
# 220 "data/maps/VermilionCity/scripts.pory"
	end
# 221 "data/maps/VermilionCity/scripts.pory"

# 222 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_Machop::
# 223 "data/maps/VermilionCity/scripts.pory"
	lock
# 224 "data/maps/VermilionCity/scripts.pory"
	faceplayer
# 225 "data/maps/VermilionCity/scripts.pory"
	waitse
# 226 "data/maps/VermilionCity/scripts.pory"
	playmoncry SPECIES_MACHOP, CRY_MODE_NORMAL
# 227 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_Machop
# 228 "data/maps/VermilionCity/scripts.pory"
	waitmoncry
# 229 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_MachopStompingLandFlat
# 230 "data/maps/VermilionCity/scripts.pory"
	release
# 231 "data/maps/VermilionCity/scripts.pory"
	end
# 232 "data/maps/VermilionCity/scripts.pory"

# 233 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CitySign::
# 234 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_CitySign, MSGBOX_SIGN
# 235 "data/maps/VermilionCity/scripts.pory"
	end
# 236 "data/maps/VermilionCity/scripts.pory"

# 237 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_SnorlaxNotice::
# 238 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_SnorlaxBlockingRoute12, MSGBOX_SIGN
# 239 "data/maps/VermilionCity/scripts.pory"
	end
# 240 "data/maps/VermilionCity/scripts.pory"

# 241 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_PokemonFanClubSign::
# 242 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_PokemonFanClubSign, MSGBOX_SIGN
# 243 "data/maps/VermilionCity/scripts.pory"
	end
# 244 "data/maps/VermilionCity/scripts.pory"

# 245 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_GymSign::
# 246 "data/maps/VermilionCity/scripts.pory"
	lockall
# 247 "data/maps/VermilionCity/scripts.pory"
	famechecker FAMECHECKER_LTSURGE, 0
# 248 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_GymSign
# 249 "data/maps/VermilionCity/scripts.pory"
	releaseall
# 250 "data/maps/VermilionCity/scripts.pory"
	end
# 251 "data/maps/VermilionCity/scripts.pory"

# 252 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_HarborSign::
# 253 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_VermilionHarbor, MSGBOX_SIGN
# 254 "data/maps/VermilionCity/scripts.pory"
	end

VermilionCity_EventScript_CheckTicket::
# 258 "data/maps/VermilionCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 259 "data/maps/VermilionCity/scripts.pory"
	applymovement LOCALID_VERMILION_FERRY_SAILOR, Common_Movement_WalkInPlaceFasterLeft
# 260 "data/maps/VermilionCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 261 "data/maps/VermilionCity/scripts.pory"
	waitmovement 0
# 262 "data/maps/VermilionCity/scripts.pory"
	compare VAR_MAP_SCENE_VERMILION_CITY, 3
	goto_if_eq VermilionCity_EventScript_CheckTicket_2
VermilionCity_EventScript_CheckTicket_1:
# 265 "data/maps/VermilionCity/scripts.pory"
	goto_if_set FLAG_DELIVERING_SS_ANNE_LETTER, VermilionCity_EventScript_CheckTicket_5
# 276 "data/maps/VermilionCity/scripts.pory"
	goto_if_set FLAG_SS_ANNE_DELAYED, VermilionCity_EventScript_CheckTicket_8
# 316 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DoYouHaveATicket
# 317 "data/maps/VermilionCity/scripts.pory"
	goto_if_unset FLAG_GOT_SS_TICKET, VermilionCity_EventScript_CheckTicket_11
VermilionCity_EventScript_CheckTicket_10:
# 320 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_FlashedSSTicket
# 321 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_VERMILION_CITY_TICKET_CHECK_TRIGGER, 1
# 322 "data/maps/VermilionCity/scripts.pory"
	releaseall
	end

VermilionCity_EventScript_CheckTicket_2:
# 263 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_CheckSeagallopPresentTrigger
	goto VermilionCity_EventScript_CheckTicket_1

VermilionCity_EventScript_CheckTicket_5:
# 266 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_EventScript_CheckTicket_Text_0
# 273 "data/maps/VermilionCity/scripts.pory"
	releaseall
	end

VermilionCity_EventScript_CheckTicket_8:
# 277 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_EventScript_CheckTicket_Text_1
# 284 "data/maps/VermilionCity/scripts.pory"
	closemessage
# 285 "data/maps/VermilionCity/scripts.pory"
	setweather WEATHER_SHADE
# 286 "data/maps/VermilionCity/scripts.pory"
	doweather
# 287 "data/maps/VermilionCity/scripts.pory"
	fadenewbgm MUS_DUMMY
# 288 "data/maps/VermilionCity/scripts.pory"
	delay 60
# 289 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_EventScript_CheckTicket_Text_2
# 302 "data/maps/VermilionCity/scripts.pory"
	giveitem ITEM_LETTER, 1
# 303 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_DELIVERING_SS_ANNE_LETTER
# 304 "data/maps/VermilionCity/scripts.pory"
	fadenewbgm MUS_VERMILLION
# 305 "data/maps/VermilionCity/scripts.pory"
	setweather WEATHER_NONE
# 306 "data/maps/VermilionCity/scripts.pory"
	doweather
# 307 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_EventScript_CheckTicket_Text_3
# 313 "data/maps/VermilionCity/scripts.pory"
	releaseall
	end

VermilionCity_EventScript_CheckTicket_11:
# 318 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_DontHaveSSTicket
	goto VermilionCity_EventScript_CheckTicket_10


VermilionCity_EventScript_CheckTicket_Text_0:
# 266 "data/maps/VermilionCity/scripts.pory"
	.string "Welcome to the S.S. ANNE!\p"
	.string "…is what I would say if it were\n"
	.string "here.\p"
	.string "Still not here kid, go deliver that\n"
	.string "LETTER in the meantime.$"

VermilionCity_EventScript_CheckTicket_Text_1:
# 277 "data/maps/VermilionCity/scripts.pory"
	.string "Welcome to the S.S. ANNE!\p"
	.string "…is what I would say if it were\n"
	.string "here.\p"
	.string "Sorry kid, she's delayed for a few\n"
	.string "minutes.$"

VermilionCity_EventScript_CheckTicket_Text_2:
# 289 "data/maps/VermilionCity/scripts.pory"
	.string "… …\n"
	.string "… …\p"
	.string "Say, you look… {PAUSE 30}familiar.\n"
	.string "What's your name?\p"
	.string "… …\n"
	.string "… …\p"
	.string "{PLAYER}, huh?\p"
	.string "Could you do me a favor and send\n"
	.string "this LETTER to someone for me?$"

VermilionCity_EventScript_CheckTicket_Text_3:
# 307 "data/maps/VermilionCity/scripts.pory"
	.string "JOE's in POKéMON TECH, just west\n"
	.string "of ROUTE 6.\p"
	.string "I honestly have no idea what his\n"
	.string "parents were thinking, signing him\l"
	.string "up for that place…$"
