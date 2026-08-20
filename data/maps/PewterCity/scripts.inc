# 1 "data/maps/PewterCity/scripts.pory"

# 2 "data/maps/PewterCity/scripts.pory"
PewterCity_MapScripts::
# 3 "data/maps/PewterCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, PewterCity_OnTransition
# 4 "data/maps/PewterCity/scripts.pory"
	.byte 0
# 5 "data/maps/PewterCity/scripts.pory"

# 6 "data/maps/PewterCity/scripts.pory"
PewterCity_OnTransition::
# 7 "data/maps/PewterCity/scripts.pory"
	setworldmapflag FLAG_WORLD_MAP_PEWTER_CITY
# 8 "data/maps/PewterCity/scripts.pory"
	setvar VAR_MAP_SCENE_PEWTER_CITY_MUSEUM_1F, 0
# 9 "data/maps/PewterCity/scripts.pory"
	end
# 10 "data/maps/PewterCity/scripts.pory"

# 11 "data/maps/PewterCity/scripts.pory"
@ Impossible to speak to this NPC from a facing dir != DIR_EAST normally, so they arent checked
# 12 "data/maps/PewterCity/scripts.pory"
@ Additionally, no movement script exists for facing DIR_SOUTH, which would necessitate walking out of bounds
# 13 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_GymGuide::
# 14 "data/maps/PewterCity/scripts.pory"
	lock
# 15 "data/maps/PewterCity/scripts.pory"
	faceplayer
# 16 "data/maps/PewterCity/scripts.pory"
	msgbox PewterCity_Text_BrocksLookingForChallengersFollowMe
# 17 "data/maps/PewterCity/scripts.pory"
	closemessage
# 18 "data/maps/PewterCity/scripts.pory"
	playbgm MUS_FOLLOW_ME, 0
# 19 "data/maps/PewterCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, PewterCity_EventScript_WalkToGymEast
# 20 "data/maps/PewterCity/scripts.pory"
	msgbox PewterCity_Text_GoTakeOnBrock
# 21 "data/maps/PewterCity/scripts.pory"
	closemessage
# 22 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GymGuideExit
# 23 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 24 "data/maps/PewterCity/scripts.pory"
	fadedefaultbgm
# 25 "data/maps/PewterCity/scripts.pory"
	removeobject LOCALID_PEWTER_GYM_GUIDE
# 26 "data/maps/PewterCity/scripts.pory"
	clearflag FLAG_HIDE_PEWTER_CITY_GYM_GUIDE
# 27 "data/maps/PewterCity/scripts.pory"
	release
# 28 "data/maps/PewterCity/scripts.pory"
	end
# 29 "data/maps/PewterCity/scripts.pory"

# 30 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_WalkToGymEast::
# 31 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWaitForGuideEast
# 32 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideMoveToLeadEast
# 33 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 34 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWalkToGymEast
# 35 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideWalkToGymEast
# 36 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 37 "data/maps/PewterCity/scripts.pory"
	return
# 38 "data/maps/PewterCity/scripts.pory"

# 39 "data/maps/PewterCity/scripts.pory"
@ Unused
# 40 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_WalkToGymWest::
# 41 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWaitForGuideWest
# 42 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideMoveToLeadWest
# 43 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 44 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWalkToGymWest
# 45 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideWalkToGymWest
# 46 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 47 "data/maps/PewterCity/scripts.pory"
	return
# 48 "data/maps/PewterCity/scripts.pory"

# 49 "data/maps/PewterCity/scripts.pory"
@ Unused
# 50 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_WalkToGymNorth::
# 51 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWaitForGuideNorth
# 52 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideMoveToLeadNorth
# 53 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 54 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWalkToGymNorth
# 55 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideWalkToGymNorth
# 56 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 57 "data/maps/PewterCity/scripts.pory"
	return
# 58 "data/maps/PewterCity/scripts.pory"

# 59 "data/maps/PewterCity/scripts.pory"
.macro walk_to_gym
# 60 "data/maps/PewterCity/scripts.pory"
	walk_left
# 61 "data/maps/PewterCity/scripts.pory"
	walk_left
# 62 "data/maps/PewterCity/scripts.pory"
	walk_left
# 63 "data/maps/PewterCity/scripts.pory"
	walk_up
# 64 "data/maps/PewterCity/scripts.pory"
	walk_left
# 65 "data/maps/PewterCity/scripts.pory"
	walk_left
# 66 "data/maps/PewterCity/scripts.pory"
	walk_left
# 67 "data/maps/PewterCity/scripts.pory"
	walk_left
# 68 "data/maps/PewterCity/scripts.pory"
	walk_left
# 69 "data/maps/PewterCity/scripts.pory"
	walk_left
# 70 "data/maps/PewterCity/scripts.pory"
	walk_left
# 71 "data/maps/PewterCity/scripts.pory"
	walk_left
# 72 "data/maps/PewterCity/scripts.pory"
	walk_left
# 73 "data/maps/PewterCity/scripts.pory"
	walk_left
# 74 "data/maps/PewterCity/scripts.pory"
	walk_left
# 75 "data/maps/PewterCity/scripts.pory"
	walk_left
# 76 "data/maps/PewterCity/scripts.pory"
	walk_left
# 77 "data/maps/PewterCity/scripts.pory"
	walk_left
# 78 "data/maps/PewterCity/scripts.pory"
	walk_left
# 79 "data/maps/PewterCity/scripts.pory"
	walk_up
# 80 "data/maps/PewterCity/scripts.pory"
	walk_up
# 81 "data/maps/PewterCity/scripts.pory"
	walk_up
# 82 "data/maps/PewterCity/scripts.pory"
	walk_up
# 83 "data/maps/PewterCity/scripts.pory"
	walk_up
# 84 "data/maps/PewterCity/scripts.pory"
	walk_up
# 85 "data/maps/PewterCity/scripts.pory"
	walk_up
# 86 "data/maps/PewterCity/scripts.pory"
	walk_up
# 87 "data/maps/PewterCity/scripts.pory"
	walk_up
# 88 "data/maps/PewterCity/scripts.pory"
	walk_up
# 89 "data/maps/PewterCity/scripts.pory"
	walk_left
# 90 "data/maps/PewterCity/scripts.pory"
	walk_left
# 91 "data/maps/PewterCity/scripts.pory"
	walk_left
# 92 "data/maps/PewterCity/scripts.pory"
	walk_left
# 93 "data/maps/PewterCity/scripts.pory"
	walk_left
# 94 "data/maps/PewterCity/scripts.pory"
	walk_left
# 95 "data/maps/PewterCity/scripts.pory"
	walk_left
# 96 "data/maps/PewterCity/scripts.pory"
	walk_left
# 97 "data/maps/PewterCity/scripts.pory"
	walk_left
# 98 "data/maps/PewterCity/scripts.pory"
	walk_left
# 99 "data/maps/PewterCity/scripts.pory"
	walk_left
# 100 "data/maps/PewterCity/scripts.pory"
	walk_left
# 101 "data/maps/PewterCity/scripts.pory"
	walk_left
# 102 "data/maps/PewterCity/scripts.pory"
	walk_left
# 103 "data/maps/PewterCity/scripts.pory"
	walk_left
# 104 "data/maps/PewterCity/scripts.pory"
	walk_left
# 105 "data/maps/PewterCity/scripts.pory"
	walk_down
# 106 "data/maps/PewterCity/scripts.pory"
	walk_down
# 107 "data/maps/PewterCity/scripts.pory"
	walk_down
# 108 "data/maps/PewterCity/scripts.pory"
	walk_down
# 109 "data/maps/PewterCity/scripts.pory"
	walk_down
# 110 "data/maps/PewterCity/scripts.pory"
	walk_down
# 111 "data/maps/PewterCity/scripts.pory"
	walk_down
# 112 "data/maps/PewterCity/scripts.pory"
	walk_down
# 113 "data/maps/PewterCity/scripts.pory"
	walk_right
# 114 "data/maps/PewterCity/scripts.pory"
	walk_right
# 115 "data/maps/PewterCity/scripts.pory"
	walk_right
# 116 "data/maps/PewterCity/scripts.pory"
	walk_right
# 117 "data/maps/PewterCity/scripts.pory"
	walk_right
# 118 "data/maps/PewterCity/scripts.pory"
	walk_right
# 119 "data/maps/PewterCity/scripts.pory"
	walk_right
# 120 "data/maps/PewterCity/scripts.pory"
	walk_right
# 121 "data/maps/PewterCity/scripts.pory"
.endm
# 122 "data/maps/PewterCity/scripts.pory"

# 123 "data/maps/PewterCity/scripts.pory"
.macro walk_to_gym_alt
# 124 "data/maps/PewterCity/scripts.pory"
	walk_left
# 125 "data/maps/PewterCity/scripts.pory"
	walk_left
# 126 "data/maps/PewterCity/scripts.pory"
	walk_left
# 127 "data/maps/PewterCity/scripts.pory"
	walk_left
# 128 "data/maps/PewterCity/scripts.pory"
	walk_left
# 129 "data/maps/PewterCity/scripts.pory"
	walk_left
# 130 "data/maps/PewterCity/scripts.pory"
	walk_left
# 131 "data/maps/PewterCity/scripts.pory"
	walk_left
# 132 "data/maps/PewterCity/scripts.pory"
	walk_left
# 133 "data/maps/PewterCity/scripts.pory"
	walk_left
# 134 "data/maps/PewterCity/scripts.pory"
	walk_left
# 135 "data/maps/PewterCity/scripts.pory"
	walk_left
# 136 "data/maps/PewterCity/scripts.pory"
	walk_left
# 137 "data/maps/PewterCity/scripts.pory"
	walk_left
# 138 "data/maps/PewterCity/scripts.pory"
	walk_left
# 139 "data/maps/PewterCity/scripts.pory"
	walk_up
# 140 "data/maps/PewterCity/scripts.pory"
	walk_up
# 141 "data/maps/PewterCity/scripts.pory"
	walk_up
# 142 "data/maps/PewterCity/scripts.pory"
	walk_up
# 143 "data/maps/PewterCity/scripts.pory"
	walk_up
# 144 "data/maps/PewterCity/scripts.pory"
	walk_up
# 145 "data/maps/PewterCity/scripts.pory"
	walk_up
# 146 "data/maps/PewterCity/scripts.pory"
	walk_left
# 147 "data/maps/PewterCity/scripts.pory"
	walk_left
# 148 "data/maps/PewterCity/scripts.pory"
	walk_left
# 149 "data/maps/PewterCity/scripts.pory"
	walk_left
# 150 "data/maps/PewterCity/scripts.pory"
	walk_left
# 151 "data/maps/PewterCity/scripts.pory"
	walk_left
# 152 "data/maps/PewterCity/scripts.pory"
	walk_left
# 153 "data/maps/PewterCity/scripts.pory"
	walk_left
# 154 "data/maps/PewterCity/scripts.pory"
	walk_left
# 155 "data/maps/PewterCity/scripts.pory"
	walk_left
# 156 "data/maps/PewterCity/scripts.pory"
	walk_down
# 157 "data/maps/PewterCity/scripts.pory"
	walk_down
# 158 "data/maps/PewterCity/scripts.pory"
	walk_down
# 159 "data/maps/PewterCity/scripts.pory"
	walk_down
# 160 "data/maps/PewterCity/scripts.pory"
	walk_down
# 161 "data/maps/PewterCity/scripts.pory"
	walk_down
# 162 "data/maps/PewterCity/scripts.pory"
	walk_right
# 163 "data/maps/PewterCity/scripts.pory"
.endm
# 164 "data/maps/PewterCity/scripts.pory"

# 165 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_PlayerWaitForGuideEast::
# 166 "data/maps/PewterCity/scripts.pory"
	delay_16
# 167 "data/maps/PewterCity/scripts.pory"
	delay_16
# 168 "data/maps/PewterCity/scripts.pory"
	delay_4
# 169 "data/maps/PewterCity/scripts.pory"
	walk_in_place_faster_down
# 170 "data/maps/PewterCity/scripts.pory"
	step_end
# 171 "data/maps/PewterCity/scripts.pory"

# 172 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_PlayerWalkToGymEast::
# 173 "data/maps/PewterCity/scripts.pory"
	walk_down
# 174 "data/maps/PewterCity/scripts.pory"
	walk_to_gym
# 175 "data/maps/PewterCity/scripts.pory"
	step_end
# 176 "data/maps/PewterCity/scripts.pory"

# 177 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_PlayerWaitForGuideWest::
# 178 "data/maps/PewterCity/scripts.pory"
	delay_16
# 179 "data/maps/PewterCity/scripts.pory"
	step_end
# 180 "data/maps/PewterCity/scripts.pory"

# 181 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_PlayerWalkToGymWest::
# 182 "data/maps/PewterCity/scripts.pory"
	walk_left
# 183 "data/maps/PewterCity/scripts.pory"
	walk_left
# 184 "data/maps/PewterCity/scripts.pory"
	walk_left
# 185 "data/maps/PewterCity/scripts.pory"
	walk_left
# 186 "data/maps/PewterCity/scripts.pory"
	walk_left
# 187 "data/maps/PewterCity/scripts.pory"
	walk_to_gym_alt
# 188 "data/maps/PewterCity/scripts.pory"
	step_end
# 189 "data/maps/PewterCity/scripts.pory"

# 190 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_PlayerWaitForGuideNorth::
# 191 "data/maps/PewterCity/scripts.pory"
	delay_16
# 192 "data/maps/PewterCity/scripts.pory"
	step_end
# 193 "data/maps/PewterCity/scripts.pory"

# 194 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_PlayerWalkToGymNorth::
# 195 "data/maps/PewterCity/scripts.pory"
	walk_up
# 196 "data/maps/PewterCity/scripts.pory"
	walk_left
# 197 "data/maps/PewterCity/scripts.pory"
	walk_left
# 198 "data/maps/PewterCity/scripts.pory"
	walk_left
# 199 "data/maps/PewterCity/scripts.pory"
	walk_left
# 200 "data/maps/PewterCity/scripts.pory"
	walk_to_gym_alt
# 201 "data/maps/PewterCity/scripts.pory"
	step_end
# 202 "data/maps/PewterCity/scripts.pory"

# 203 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_GuideMoveToLeadEast::
# 204 "data/maps/PewterCity/scripts.pory"
	walk_down
# 205 "data/maps/PewterCity/scripts.pory"
	walk_left
# 206 "data/maps/PewterCity/scripts.pory"
	walk_in_place_faster_up
# 207 "data/maps/PewterCity/scripts.pory"
	walk_in_place_up
# 208 "data/maps/PewterCity/scripts.pory"
	step_end
# 209 "data/maps/PewterCity/scripts.pory"

# 210 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_GuideWalkToGymEast::
# 211 "data/maps/PewterCity/scripts.pory"
	walk_to_gym
# 212 "data/maps/PewterCity/scripts.pory"
	walk_right
# 213 "data/maps/PewterCity/scripts.pory"
	walk_in_place_faster_left
# 214 "data/maps/PewterCity/scripts.pory"
	step_end
# 215 "data/maps/PewterCity/scripts.pory"

# 216 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_GuideMoveToLeadWest::
# 217 "data/maps/PewterCity/scripts.pory"
	walk_in_place_right
# 218 "data/maps/PewterCity/scripts.pory"
	step_end
# 219 "data/maps/PewterCity/scripts.pory"

# 220 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_GuideWalkToGymWest::
# 221 "data/maps/PewterCity/scripts.pory"
	walk_left
# 222 "data/maps/PewterCity/scripts.pory"
	walk_left
# 223 "data/maps/PewterCity/scripts.pory"
	walk_left
# 224 "data/maps/PewterCity/scripts.pory"
	walk_left
# 225 "data/maps/PewterCity/scripts.pory"
	walk_to_gym_alt
# 226 "data/maps/PewterCity/scripts.pory"
	walk_right
# 227 "data/maps/PewterCity/scripts.pory"
	walk_in_place_faster_left
# 228 "data/maps/PewterCity/scripts.pory"
	step_end
# 229 "data/maps/PewterCity/scripts.pory"

# 230 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_GuideMoveToLeadNorth::
# 231 "data/maps/PewterCity/scripts.pory"
	walk_in_place_down
# 232 "data/maps/PewterCity/scripts.pory"
	step_end
# 233 "data/maps/PewterCity/scripts.pory"

# 234 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_GuideWalkToGymNorth::
# 235 "data/maps/PewterCity/scripts.pory"
	walk_left
# 236 "data/maps/PewterCity/scripts.pory"
	walk_left
# 237 "data/maps/PewterCity/scripts.pory"
	walk_left
# 238 "data/maps/PewterCity/scripts.pory"
	walk_left
# 239 "data/maps/PewterCity/scripts.pory"
	walk_to_gym_alt
# 240 "data/maps/PewterCity/scripts.pory"
	walk_right
# 241 "data/maps/PewterCity/scripts.pory"
	walk_in_place_faster_left
# 242 "data/maps/PewterCity/scripts.pory"
	step_end
# 243 "data/maps/PewterCity/scripts.pory"

# 244 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_GymGuideExit::
# 245 "data/maps/PewterCity/scripts.pory"
	walk_down
# 246 "data/maps/PewterCity/scripts.pory"
	walk_left
# 247 "data/maps/PewterCity/scripts.pory"
	walk_left
# 248 "data/maps/PewterCity/scripts.pory"
	walk_left
# 249 "data/maps/PewterCity/scripts.pory"
	walk_left
# 250 "data/maps/PewterCity/scripts.pory"
	walk_left
# 251 "data/maps/PewterCity/scripts.pory"
	walk_left
# 252 "data/maps/PewterCity/scripts.pory"
	walk_left
# 253 "data/maps/PewterCity/scripts.pory"
	walk_left
# 254 "data/maps/PewterCity/scripts.pory"
	walk_left
# 255 "data/maps/PewterCity/scripts.pory"
	step_end
# 256 "data/maps/PewterCity/scripts.pory"

# 257 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_GymGuideTriggerTop::
# 258 "data/maps/PewterCity/scripts.pory"
	lockall
# 259 "data/maps/PewterCity/scripts.pory"
	setvar VAR_TEMP_1, 0
# 260 "data/maps/PewterCity/scripts.pory"
	goto PewterCity_EventScript_GymGuideTrigger
# 261 "data/maps/PewterCity/scripts.pory"
	end
# 262 "data/maps/PewterCity/scripts.pory"

# 263 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_GymGuideTriggerMid::
# 264 "data/maps/PewterCity/scripts.pory"
	lockall
# 265 "data/maps/PewterCity/scripts.pory"
	setvar VAR_TEMP_1, 1
# 266 "data/maps/PewterCity/scripts.pory"
	goto PewterCity_EventScript_GymGuideTrigger
# 267 "data/maps/PewterCity/scripts.pory"
	end
# 268 "data/maps/PewterCity/scripts.pory"

# 269 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_GymGuideTriggerBottom::
# 270 "data/maps/PewterCity/scripts.pory"
	lockall
# 271 "data/maps/PewterCity/scripts.pory"
	setvar VAR_TEMP_1, 2
# 272 "data/maps/PewterCity/scripts.pory"
	goto PewterCity_EventScript_GymGuideTrigger
# 273 "data/maps/PewterCity/scripts.pory"
	end
# 274 "data/maps/PewterCity/scripts.pory"

# 275 "data/maps/PewterCity/scripts.pory"
@ This trigger is inaccessible and its corresponding movement script isnt linked
# 276 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_GymGuideTriggerRight::
# 277 "data/maps/PewterCity/scripts.pory"
	lockall
# 278 "data/maps/PewterCity/scripts.pory"
	setvar VAR_TEMP_1, 3
# 279 "data/maps/PewterCity/scripts.pory"
	goto PewterCity_EventScript_GymGuideTrigger
# 280 "data/maps/PewterCity/scripts.pory"
	end
# 281 "data/maps/PewterCity/scripts.pory"

# 282 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_GymGuideTrigger::
# 283 "data/maps/PewterCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 284 "data/maps/PewterCity/scripts.pory"
	msgbox PewterCity_Text_BrocksLookingForChallengersFollowMe
# 285 "data/maps/PewterCity/scripts.pory"
	closemessage
# 286 "data/maps/PewterCity/scripts.pory"
	playbgm MUS_FOLLOW_ME, 0
# 287 "data/maps/PewterCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, PewterCity_EventScript_WalkToGymTop
# 288 "data/maps/PewterCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, PewterCity_EventScript_WalkToGymMid
# 289 "data/maps/PewterCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, PewterCity_EventScript_WalkToGymBottom
# 290 "data/maps/PewterCity/scripts.pory"
	msgbox PewterCity_Text_GoTakeOnBrock
# 291 "data/maps/PewterCity/scripts.pory"
	closemessage
# 292 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GymGuideExit
# 293 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 294 "data/maps/PewterCity/scripts.pory"
	fadedefaultbgm
# 295 "data/maps/PewterCity/scripts.pory"
	removeobject LOCALID_PEWTER_GYM_GUIDE
# 296 "data/maps/PewterCity/scripts.pory"
	clearflag FLAG_HIDE_PEWTER_CITY_GYM_GUIDE
# 297 "data/maps/PewterCity/scripts.pory"
	releaseall
# 298 "data/maps/PewterCity/scripts.pory"
	end
# 299 "data/maps/PewterCity/scripts.pory"

# 300 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_WalkToGymTop::
# 301 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideMoveToLeadTop
# 302 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 303 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWalkToGymTop
# 304 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideWalkToGymTop
# 305 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 306 "data/maps/PewterCity/scripts.pory"
	return
# 307 "data/maps/PewterCity/scripts.pory"

# 308 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_WalkToGymMid::
# 309 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideMoveToLeadMid
# 310 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 311 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWalkToGymMid
# 312 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideWalkToGymMid
# 313 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 314 "data/maps/PewterCity/scripts.pory"
	return
# 315 "data/maps/PewterCity/scripts.pory"

# 316 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_WalkToGymBottom::
# 317 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideMoveToLeadBottom
# 318 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 319 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWalkToGymBottom
# 320 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideWalkToGymBottom
# 321 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 322 "data/maps/PewterCity/scripts.pory"
	return
# 323 "data/maps/PewterCity/scripts.pory"

# 324 "data/maps/PewterCity/scripts.pory"
@ Unused
# 325 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_WalkToGymRight::
# 326 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideApproachPlayerRight
# 327 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 328 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWalkToGymRight
# 329 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideWalkToGymRight
# 330 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 331 "data/maps/PewterCity/scripts.pory"
	return
# 332 "data/maps/PewterCity/scripts.pory"

# 333 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_PlayerWalkToGymTop::
# 334 "data/maps/PewterCity/scripts.pory"
	walk_left
# 335 "data/maps/PewterCity/scripts.pory"
	walk_to_gym
# 336 "data/maps/PewterCity/scripts.pory"
	step_end
# 337 "data/maps/PewterCity/scripts.pory"

# 338 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_PlayerWalkToGymMid::
# 339 "data/maps/PewterCity/scripts.pory"
	walk_up
# 340 "data/maps/PewterCity/scripts.pory"
	walk_left
# 341 "data/maps/PewterCity/scripts.pory"
	walk_to_gym
# 342 "data/maps/PewterCity/scripts.pory"
	step_end
# 343 "data/maps/PewterCity/scripts.pory"

# 344 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_PlayerWalkToGymBottom::
# 345 "data/maps/PewterCity/scripts.pory"
	walk_up
# 346 "data/maps/PewterCity/scripts.pory"
	walk_up
# 347 "data/maps/PewterCity/scripts.pory"
	walk_left
# 348 "data/maps/PewterCity/scripts.pory"
	walk_to_gym
# 349 "data/maps/PewterCity/scripts.pory"
	step_end
# 350 "data/maps/PewterCity/scripts.pory"

# 351 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_PlayerWalkToGymRight::
# 352 "data/maps/PewterCity/scripts.pory"
	walk_left
# 353 "data/maps/PewterCity/scripts.pory"
	walk_left
# 354 "data/maps/PewterCity/scripts.pory"
	walk_left
# 355 "data/maps/PewterCity/scripts.pory"
	walk_left
# 356 "data/maps/PewterCity/scripts.pory"
	walk_up
# 357 "data/maps/PewterCity/scripts.pory"
	walk_left
# 358 "data/maps/PewterCity/scripts.pory"
	walk_left
# 359 "data/maps/PewterCity/scripts.pory"
	walk_left
# 360 "data/maps/PewterCity/scripts.pory"
	walk_up
# 361 "data/maps/PewterCity/scripts.pory"
	walk_up
# 362 "data/maps/PewterCity/scripts.pory"
	walk_to_gym_alt
# 363 "data/maps/PewterCity/scripts.pory"
	step_end
# 364 "data/maps/PewterCity/scripts.pory"

# 365 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_GuideMoveToLeadTop::
# 366 "data/maps/PewterCity/scripts.pory"
	walk_left
# 367 "data/maps/PewterCity/scripts.pory"
	walk_down
# 368 "data/maps/PewterCity/scripts.pory"
	walk_in_place_faster_right
# 369 "data/maps/PewterCity/scripts.pory"
	walk_in_place_right
# 370 "data/maps/PewterCity/scripts.pory"
	step_end
# 371 "data/maps/PewterCity/scripts.pory"

# 372 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_GuideMoveToLeadMid::
# 373 "data/maps/PewterCity/scripts.pory"
	walk_down
# 374 "data/maps/PewterCity/scripts.pory"
	walk_in_place_down
# 375 "data/maps/PewterCity/scripts.pory"
	step_end
# 376 "data/maps/PewterCity/scripts.pory"

# 377 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_GuideMoveToLeadBottom::
# 378 "data/maps/PewterCity/scripts.pory"
	walk_down
# 379 "data/maps/PewterCity/scripts.pory"
	walk_down
# 380 "data/maps/PewterCity/scripts.pory"
	walk_in_place_down
# 381 "data/maps/PewterCity/scripts.pory"
	step_end
# 382 "data/maps/PewterCity/scripts.pory"

# 383 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_GuideApproachPlayerRight::
# 384 "data/maps/PewterCity/scripts.pory"
	walk_down
# 385 "data/maps/PewterCity/scripts.pory"
	walk_down
# 386 "data/maps/PewterCity/scripts.pory"
	walk_right
# 387 "data/maps/PewterCity/scripts.pory"
	walk_down
# 388 "data/maps/PewterCity/scripts.pory"
	walk_right
# 389 "data/maps/PewterCity/scripts.pory"
	walk_in_place_right
# 390 "data/maps/PewterCity/scripts.pory"
	step_end
# 391 "data/maps/PewterCity/scripts.pory"

# 392 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_GuideWalkToGymTop::
# 393 "data/maps/PewterCity/scripts.pory"
	walk_to_gym
# 394 "data/maps/PewterCity/scripts.pory"
	walk_right
# 395 "data/maps/PewterCity/scripts.pory"
	walk_in_place_faster_left
# 396 "data/maps/PewterCity/scripts.pory"
	step_end
# 397 "data/maps/PewterCity/scripts.pory"

# 398 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_GuideWalkToGymMid::
# 399 "data/maps/PewterCity/scripts.pory"
	walk_left
# 400 "data/maps/PewterCity/scripts.pory"
	walk_to_gym
# 401 "data/maps/PewterCity/scripts.pory"
	walk_right
# 402 "data/maps/PewterCity/scripts.pory"
	walk_in_place_faster_left
# 403 "data/maps/PewterCity/scripts.pory"
	step_end
# 404 "data/maps/PewterCity/scripts.pory"

# 405 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_GuideWalkToGymBottom::
# 406 "data/maps/PewterCity/scripts.pory"
	walk_up
# 407 "data/maps/PewterCity/scripts.pory"
	walk_left
# 408 "data/maps/PewterCity/scripts.pory"
	walk_to_gym
# 409 "data/maps/PewterCity/scripts.pory"
	walk_right
# 410 "data/maps/PewterCity/scripts.pory"
	walk_in_place_faster_left
# 411 "data/maps/PewterCity/scripts.pory"
	step_end
# 412 "data/maps/PewterCity/scripts.pory"

# 413 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_GuideWalkToGymRight::
# 414 "data/maps/PewterCity/scripts.pory"
	walk_left
# 415 "data/maps/PewterCity/scripts.pory"
	walk_left
# 416 "data/maps/PewterCity/scripts.pory"
	walk_left
# 417 "data/maps/PewterCity/scripts.pory"
	walk_up
# 418 "data/maps/PewterCity/scripts.pory"
	walk_left
# 419 "data/maps/PewterCity/scripts.pory"
	walk_left
# 420 "data/maps/PewterCity/scripts.pory"
	walk_left
# 421 "data/maps/PewterCity/scripts.pory"
	walk_up
# 422 "data/maps/PewterCity/scripts.pory"
	walk_up
# 423 "data/maps/PewterCity/scripts.pory"
	walk_to_gym_alt
# 424 "data/maps/PewterCity/scripts.pory"
	walk_right
# 425 "data/maps/PewterCity/scripts.pory"
	walk_in_place_faster_left
# 426 "data/maps/PewterCity/scripts.pory"
	step_end
# 427 "data/maps/PewterCity/scripts.pory"

# 428 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_Lass::
# 429 "data/maps/PewterCity/scripts.pory"
	msgbox PewterCity_Text_ClefairyCameFromMoon, MSGBOX_NPC
# 430 "data/maps/PewterCity/scripts.pory"
	end
# 431 "data/maps/PewterCity/scripts.pory"

# 432 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_MuseumGuide::
# 433 "data/maps/PewterCity/scripts.pory"
	lock
# 434 "data/maps/PewterCity/scripts.pory"
	faceplayer
# 435 "data/maps/PewterCity/scripts.pory"
	msgbox PewterCity_Text_DidYouCheckOutMuseum, MSGBOX_YESNO
# 436 "data/maps/PewterCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PewterCity_EventScript_CheckedOutMuseum
# 437 "data/maps/PewterCity/scripts.pory"
	msgbox PewterCity_Text_ReallyYouHaveToGo
# 438 "data/maps/PewterCity/scripts.pory"
	closemessage
# 439 "data/maps/PewterCity/scripts.pory"
	delay 10
# 440 "data/maps/PewterCity/scripts.pory"
	playbgm MUS_FOLLOW_ME, 0
# 441 "data/maps/PewterCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, PewterCity_EventScript_LeadToMuseumNorth
# 442 "data/maps/PewterCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, PewterCity_EventScript_LeadToMuseumSouth
# 443 "data/maps/PewterCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, PewterCity_EventScript_LeadToMuseumWest
# 444 "data/maps/PewterCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, PewterCity_EventScript_LeadToMuseumEast
# 445 "data/maps/PewterCity/scripts.pory"
	msgbox PewterCity_Text_ThisIsTheMuseum
# 446 "data/maps/PewterCity/scripts.pory"
	closemessage
# 447 "data/maps/PewterCity/scripts.pory"
	delay 10
# 448 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_MUSEUM_GUIDE, PewterCity_Movement_MuseumGuideExit
# 449 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 450 "data/maps/PewterCity/scripts.pory"
	fadedefaultbgm
# 451 "data/maps/PewterCity/scripts.pory"
	removeobject LOCALID_PEWTER_MUSEUM_GUIDE
# 452 "data/maps/PewterCity/scripts.pory"
	clearflag FLAG_HIDE_PEWTER_MUSEUM_GUIDE
# 453 "data/maps/PewterCity/scripts.pory"
	release
# 454 "data/maps/PewterCity/scripts.pory"
	end
# 455 "data/maps/PewterCity/scripts.pory"

# 456 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_LeadToMuseumNorth::
# 457 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_MUSEUM_GUIDE, PewterCity_Movement_GuideWalkToMuseumNorth
# 458 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWalkToMuseumNorth
# 459 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 460 "data/maps/PewterCity/scripts.pory"
	return
# 461 "data/maps/PewterCity/scripts.pory"

# 462 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_LeadToMuseumSouth::
# 463 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_MUSEUM_GUIDE, PewterCity_Movement_GuideWalkToMuseumSouth
# 464 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWalkToMuseumSouth
# 465 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 466 "data/maps/PewterCity/scripts.pory"
	return
# 467 "data/maps/PewterCity/scripts.pory"

# 468 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_LeadToMuseumWest::
# 469 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_MUSEUM_GUIDE, PewterCity_Movement_GuideWalkToMuseumWest
# 470 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWalkToMuseumWest
# 471 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 472 "data/maps/PewterCity/scripts.pory"
	return
# 473 "data/maps/PewterCity/scripts.pory"

# 474 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_LeadToMuseumEast::
# 475 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_MUSEUM_GUIDE, PewterCity_Movement_GuideWalkToMuseumEast
# 476 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWalkToMuseumEast
# 477 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 478 "data/maps/PewterCity/scripts.pory"
	return
# 479 "data/maps/PewterCity/scripts.pory"

# 480 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_CheckedOutMuseum::
# 481 "data/maps/PewterCity/scripts.pory"
	msgbox PewterCity_Text_WerentThoseFossilsAmazing
# 482 "data/maps/PewterCity/scripts.pory"
	release
# 483 "data/maps/PewterCity/scripts.pory"
	end
# 484 "data/maps/PewterCity/scripts.pory"

# 485 "data/maps/PewterCity/scripts.pory"
.macro walk_to_museum
# 486 "data/maps/PewterCity/scripts.pory"
	walk_up
# 487 "data/maps/PewterCity/scripts.pory"
	walk_up
# 488 "data/maps/PewterCity/scripts.pory"
	walk_up
# 489 "data/maps/PewterCity/scripts.pory"
	walk_up
# 490 "data/maps/PewterCity/scripts.pory"
	walk_left
# 491 "data/maps/PewterCity/scripts.pory"
	walk_left
# 492 "data/maps/PewterCity/scripts.pory"
	walk_left
# 493 "data/maps/PewterCity/scripts.pory"
	walk_left
# 494 "data/maps/PewterCity/scripts.pory"
	walk_left
# 495 "data/maps/PewterCity/scripts.pory"
	walk_left
# 496 "data/maps/PewterCity/scripts.pory"
	walk_left
# 497 "data/maps/PewterCity/scripts.pory"
	walk_left
# 498 "data/maps/PewterCity/scripts.pory"
	walk_left
# 499 "data/maps/PewterCity/scripts.pory"
	walk_left
# 500 "data/maps/PewterCity/scripts.pory"
	walk_up
# 501 "data/maps/PewterCity/scripts.pory"
	walk_up
# 502 "data/maps/PewterCity/scripts.pory"
	walk_up
# 503 "data/maps/PewterCity/scripts.pory"
	walk_up
# 504 "data/maps/PewterCity/scripts.pory"
	walk_left
# 505 "data/maps/PewterCity/scripts.pory"
	walk_left
# 506 "data/maps/PewterCity/scripts.pory"
	walk_left
# 507 "data/maps/PewterCity/scripts.pory"
	walk_left
# 508 "data/maps/PewterCity/scripts.pory"
	walk_left
# 509 "data/maps/PewterCity/scripts.pory"
	walk_left
# 510 "data/maps/PewterCity/scripts.pory"
.endm
# 511 "data/maps/PewterCity/scripts.pory"

# 512 "data/maps/PewterCity/scripts.pory"
.macro walk_to_museum_south
# 513 "data/maps/PewterCity/scripts.pory"
	walk_up
# 514 "data/maps/PewterCity/scripts.pory"
	walk_up
# 515 "data/maps/PewterCity/scripts.pory"
	walk_up
# 516 "data/maps/PewterCity/scripts.pory"
	walk_left
# 517 "data/maps/PewterCity/scripts.pory"
	walk_left
# 518 "data/maps/PewterCity/scripts.pory"
	walk_left
# 519 "data/maps/PewterCity/scripts.pory"
	walk_left
# 520 "data/maps/PewterCity/scripts.pory"
	walk_left
# 521 "data/maps/PewterCity/scripts.pory"
	walk_left
# 522 "data/maps/PewterCity/scripts.pory"
	walk_left
# 523 "data/maps/PewterCity/scripts.pory"
	walk_left
# 524 "data/maps/PewterCity/scripts.pory"
	walk_left
# 525 "data/maps/PewterCity/scripts.pory"
	walk_up
# 526 "data/maps/PewterCity/scripts.pory"
	walk_up
# 527 "data/maps/PewterCity/scripts.pory"
	walk_up
# 528 "data/maps/PewterCity/scripts.pory"
	walk_up
# 529 "data/maps/PewterCity/scripts.pory"
	walk_left
# 530 "data/maps/PewterCity/scripts.pory"
	walk_left
# 531 "data/maps/PewterCity/scripts.pory"
	walk_left
# 532 "data/maps/PewterCity/scripts.pory"
	walk_left
# 533 "data/maps/PewterCity/scripts.pory"
	walk_left
# 534 "data/maps/PewterCity/scripts.pory"
	walk_left
# 535 "data/maps/PewterCity/scripts.pory"
.endm
# 536 "data/maps/PewterCity/scripts.pory"

# 537 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_PlayerWalkToMuseumNorth::
# 538 "data/maps/PewterCity/scripts.pory"
	walk_up
# 539 "data/maps/PewterCity/scripts.pory"
	walk_to_museum
# 540 "data/maps/PewterCity/scripts.pory"
	delay_8
# 541 "data/maps/PewterCity/scripts.pory"
	walk_in_place_faster_up
# 542 "data/maps/PewterCity/scripts.pory"
	step_end
# 543 "data/maps/PewterCity/scripts.pory"

# 544 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_GuideWalkToMuseumNorth::
# 545 "data/maps/PewterCity/scripts.pory"
	walk_to_museum
# 546 "data/maps/PewterCity/scripts.pory"
	walk_left
# 547 "data/maps/PewterCity/scripts.pory"
	walk_in_place_faster_up
# 548 "data/maps/PewterCity/scripts.pory"
	step_end
# 549 "data/maps/PewterCity/scripts.pory"

# 550 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_PlayerWalkToMuseumSouth::
# 551 "data/maps/PewterCity/scripts.pory"
	delay_16
# 552 "data/maps/PewterCity/scripts.pory"
	delay_16
# 553 "data/maps/PewterCity/scripts.pory"
	walk_left
# 554 "data/maps/PewterCity/scripts.pory"
	walk_to_museum_south
# 555 "data/maps/PewterCity/scripts.pory"
	delay_8
# 556 "data/maps/PewterCity/scripts.pory"
	walk_in_place_faster_up
# 557 "data/maps/PewterCity/scripts.pory"
	step_end
# 558 "data/maps/PewterCity/scripts.pory"

# 559 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_GuideWalkToMuseumSouth::
# 560 "data/maps/PewterCity/scripts.pory"
	walk_left
# 561 "data/maps/PewterCity/scripts.pory"
	walk_up
# 562 "data/maps/PewterCity/scripts.pory"
	walk_to_museum_south
# 563 "data/maps/PewterCity/scripts.pory"
	walk_left
# 564 "data/maps/PewterCity/scripts.pory"
	walk_in_place_faster_up
# 565 "data/maps/PewterCity/scripts.pory"
	step_end
# 566 "data/maps/PewterCity/scripts.pory"

# 567 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_PlayerWalkToMuseumWest::
# 568 "data/maps/PewterCity/scripts.pory"
	walk_left
# 569 "data/maps/PewterCity/scripts.pory"
	walk_to_museum
# 570 "data/maps/PewterCity/scripts.pory"
	delay_8
# 571 "data/maps/PewterCity/scripts.pory"
	walk_in_place_faster_up
# 572 "data/maps/PewterCity/scripts.pory"
	step_end
# 573 "data/maps/PewterCity/scripts.pory"

# 574 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_GuideWalkToMuseumWest::
# 575 "data/maps/PewterCity/scripts.pory"
	walk_to_museum
# 576 "data/maps/PewterCity/scripts.pory"
	walk_left
# 577 "data/maps/PewterCity/scripts.pory"
	walk_in_place_faster_up
# 578 "data/maps/PewterCity/scripts.pory"
	step_end
# 579 "data/maps/PewterCity/scripts.pory"

# 580 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_PlayerWalkToMuseumEast::
# 581 "data/maps/PewterCity/scripts.pory"
	walk_right
# 582 "data/maps/PewterCity/scripts.pory"
	walk_to_museum
# 583 "data/maps/PewterCity/scripts.pory"
	delay_8
# 584 "data/maps/PewterCity/scripts.pory"
	walk_in_place_faster_up
# 585 "data/maps/PewterCity/scripts.pory"
	step_end
# 586 "data/maps/PewterCity/scripts.pory"

# 587 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_GuideWalkToMuseumEast::
# 588 "data/maps/PewterCity/scripts.pory"
	walk_to_museum
# 589 "data/maps/PewterCity/scripts.pory"
	walk_left
# 590 "data/maps/PewterCity/scripts.pory"
	walk_in_place_faster_up
# 591 "data/maps/PewterCity/scripts.pory"
	step_end
# 592 "data/maps/PewterCity/scripts.pory"

# 593 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_MuseumGuideExit::
# 594 "data/maps/PewterCity/scripts.pory"
	walk_down
# 595 "data/maps/PewterCity/scripts.pory"
	walk_right
# 596 "data/maps/PewterCity/scripts.pory"
	walk_right
# 597 "data/maps/PewterCity/scripts.pory"
	walk_right
# 598 "data/maps/PewterCity/scripts.pory"
	walk_right
# 599 "data/maps/PewterCity/scripts.pory"
	walk_right
# 600 "data/maps/PewterCity/scripts.pory"
	walk_right
# 601 "data/maps/PewterCity/scripts.pory"
	walk_right
# 602 "data/maps/PewterCity/scripts.pory"
	walk_down
# 603 "data/maps/PewterCity/scripts.pory"
	walk_down
# 604 "data/maps/PewterCity/scripts.pory"
	walk_down
# 605 "data/maps/PewterCity/scripts.pory"
	walk_right
# 606 "data/maps/PewterCity/scripts.pory"
	walk_right
# 607 "data/maps/PewterCity/scripts.pory"
	walk_right
# 608 "data/maps/PewterCity/scripts.pory"
	step_end
# 609 "data/maps/PewterCity/scripts.pory"

# 610 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_FatMan::
# 611 "data/maps/PewterCity/scripts.pory"
	lock
# 612 "data/maps/PewterCity/scripts.pory"
	faceplayer
# 613 "data/maps/PewterCity/scripts.pory"
	famechecker FAMECHECKER_BROCK, 2
# 614 "data/maps/PewterCity/scripts.pory"
	msgbox PewterCity_Text_BrockOnlySeriousTrainerHere
# 615 "data/maps/PewterCity/scripts.pory"
	release
# 616 "data/maps/PewterCity/scripts.pory"
	end
# 617 "data/maps/PewterCity/scripts.pory"

# 618 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_BugCatcher::
# 619 "data/maps/PewterCity/scripts.pory"
	lock
# 620 "data/maps/PewterCity/scripts.pory"
	faceplayer
# 621 "data/maps/PewterCity/scripts.pory"
	msgbox PewterCity_Text_DoYouKnowWhatImDoing, MSGBOX_YESNO
# 622 "data/maps/PewterCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PewterCity_EventScript_KnowWhatTheyreDoing
# 623 "data/maps/PewterCity/scripts.pory"
	msgbox PewterCity_Text_SprayingRepelToKeepWildMonsOut
# 624 "data/maps/PewterCity/scripts.pory"
	release
# 625 "data/maps/PewterCity/scripts.pory"
	end
# 626 "data/maps/PewterCity/scripts.pory"

# 627 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_KnowWhatTheyreDoing::
# 628 "data/maps/PewterCity/scripts.pory"
	msgbox PewterCity_Text_ThatsRightItsHardWork
# 629 "data/maps/PewterCity/scripts.pory"
	release
# 630 "data/maps/PewterCity/scripts.pory"
	end
# 631 "data/maps/PewterCity/scripts.pory"

# 632 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_TrainerTips::
# 633 "data/maps/PewterCity/scripts.pory"
	msgbox PewterCity_Text_TrainerTipsEarningEXP, MSGBOX_SIGN
# 634 "data/maps/PewterCity/scripts.pory"
	end
# 635 "data/maps/PewterCity/scripts.pory"

# 636 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_PoliceNotice::
# 637 "data/maps/PewterCity/scripts.pory"
	msgbox PewterCity_Text_CallPoliceIfInfoOnThieves, MSGBOX_SIGN
# 638 "data/maps/PewterCity/scripts.pory"
	end
# 639 "data/maps/PewterCity/scripts.pory"

# 640 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_MuseumSign::
# 641 "data/maps/PewterCity/scripts.pory"
	msgbox PewterCity_Text_MuseumOfScience, MSGBOX_SIGN
# 642 "data/maps/PewterCity/scripts.pory"
	end
# 643 "data/maps/PewterCity/scripts.pory"

# 644 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_GymSign::
# 645 "data/maps/PewterCity/scripts.pory"
	lockall
# 646 "data/maps/PewterCity/scripts.pory"
	famechecker FAMECHECKER_BROCK, 0
# 647 "data/maps/PewterCity/scripts.pory"
	msgbox PewterCity_Text_GymSign
# 648 "data/maps/PewterCity/scripts.pory"
	releaseall
# 649 "data/maps/PewterCity/scripts.pory"
	end
# 650 "data/maps/PewterCity/scripts.pory"

# 651 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_CitySign::
# 652 "data/maps/PewterCity/scripts.pory"
	msgbox PewterCity_Text_CitySign, MSGBOX_SIGN
# 653 "data/maps/PewterCity/scripts.pory"
	end
# 654 "data/maps/PewterCity/scripts.pory"

# 655 "data/maps/PewterCity/scripts.pory"
@ Unused
# 656 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_WalkInPlaceLeft::
# 657 "data/maps/PewterCity/scripts.pory"
	walk_in_place_left
# 658 "data/maps/PewterCity/scripts.pory"
	step_end
