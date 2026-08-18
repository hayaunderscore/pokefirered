# 1 "data/maps/CeruleanCity_House4/scripts.pory"

# 2 "data/maps/CeruleanCity_House4/scripts.pory"
.set REWARD_TYPE, VAR_0x8004
# 3 "data/maps/CeruleanCity_House4/scripts.pory"
.set REWARD_ITEM, VAR_0x8008
# 4 "data/maps/CeruleanCity_House4/scripts.pory"

# 5 "data/maps/CeruleanCity_House4/scripts.pory"
CeruleanCity_House4_MapScripts::
# 6 "data/maps/CeruleanCity_House4/scripts.pory"
	.byte 0
# 7 "data/maps/CeruleanCity_House4/scripts.pory"

# 8 "data/maps/CeruleanCity_House4/scripts.pory"
CeruleanCity_House4_EventScript_WonderNewsBerryMan::
# 9 "data/maps/CeruleanCity_House4/scripts.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 10 "data/maps/CeruleanCity_House4/scripts.pory"
	special QuestLog_CutRecording
# 11 "data/maps/CeruleanCity_House4/scripts.pory"
	lock
# 12 "data/maps/CeruleanCity_House4/scripts.pory"
	specialvar REWARD_TYPE, WonderNews_GetRewardInfo
# 13 "data/maps/CeruleanCity_House4/scripts.pory"
	copyvar REWARD_ITEM, VAR_RESULT
# 14 "data/maps/CeruleanCity_House4/scripts.pory"
	goto_if_eq REWARD_TYPE, NEWS_REWARD_NONE,       CeruleanCity_House4_EventScript_NoNews
# 15 "data/maps/CeruleanCity_House4/scripts.pory"
	goto_if_eq REWARD_TYPE, NEWS_REWARD_RECV_SMALL, CeruleanCity_House4_EventScript_Reward_RecvSmall
# 16 "data/maps/CeruleanCity_House4/scripts.pory"
	goto_if_eq REWARD_TYPE, NEWS_REWARD_RECV_BIG,   CeruleanCity_House4_EventScript_Reward_RecvBig
# 17 "data/maps/CeruleanCity_House4/scripts.pory"
	goto_if_eq REWARD_TYPE, NEWS_REWARD_WAITING,    CeruleanCity_House4_EventScript_Waiting
# 18 "data/maps/CeruleanCity_House4/scripts.pory"
	goto_if_eq REWARD_TYPE, NEWS_REWARD_SENT_SMALL, CeruleanCity_House4_EventScript_Reward_SentSmall
# 19 "data/maps/CeruleanCity_House4/scripts.pory"
	goto_if_eq REWARD_TYPE, NEWS_REWARD_SENT_BIG,   CeruleanCity_House4_EventScript_Reward_SentBig
# 20 "data/maps/CeruleanCity_House4/scripts.pory"
	goto_if_eq REWARD_TYPE, NEWS_REWARD_AT_MAX,     CeruleanCity_House4_EventScript_AtMax
# 21 "data/maps/CeruleanCity_House4/scripts.pory"
	end
# 22 "data/maps/CeruleanCity_House4/scripts.pory"

# 23 "data/maps/CeruleanCity_House4/scripts.pory"
@ Mystery Gift is not enabled, or the player has no saved Wonder News
# 24 "data/maps/CeruleanCity_House4/scripts.pory"
CeruleanCity_House4_EventScript_NoNews::
# 25 "data/maps/CeruleanCity_House4/scripts.pory"
	msgbox CeruleanCity_House4_Text_NothingEntertaining
# 26 "data/maps/CeruleanCity_House4/scripts.pory"
	release
# 27 "data/maps/CeruleanCity_House4/scripts.pory"
	end
# 28 "data/maps/CeruleanCity_House4/scripts.pory"

# 29 "data/maps/CeruleanCity_House4/scripts.pory"
@ Small reward for receiving Wonder News from friend
# 30 "data/maps/CeruleanCity_House4/scripts.pory"
CeruleanCity_House4_EventScript_Reward_RecvSmall::
# 31 "data/maps/CeruleanCity_House4/scripts.pory"
	call CeruleanCity_House4_EventScript_MovementReactionToNews
# 32 "data/maps/CeruleanCity_House4/scripts.pory"
	msgbox CeruleanCity_House4_Text_NewNewsInformativeHaveThis
# 33 "data/maps/CeruleanCity_House4/scripts.pory"
	giveitem REWARD_ITEM
# 34 "data/maps/CeruleanCity_House4/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_House4_EventScript_NoRoomForBerries
# 35 "data/maps/CeruleanCity_House4/scripts.pory"
	release
# 36 "data/maps/CeruleanCity_House4/scripts.pory"
	end
# 37 "data/maps/CeruleanCity_House4/scripts.pory"

# 38 "data/maps/CeruleanCity_House4/scripts.pory"
@ Big reward for receiving Wonder News from non-friend source
# 39 "data/maps/CeruleanCity_House4/scripts.pory"
CeruleanCity_House4_EventScript_Reward_RecvBig::
# 40 "data/maps/CeruleanCity_House4/scripts.pory"
	call CeruleanCity_House4_EventScript_MovementReactionToNews
# 41 "data/maps/CeruleanCity_House4/scripts.pory"
	msgbox CeruleanCity_House4_Text_IncredibleNewsHaveBerries
# 42 "data/maps/CeruleanCity_House4/scripts.pory"
	giveitem REWARD_ITEM, 4
# 43 "data/maps/CeruleanCity_House4/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_House4_EventScript_NoRoomForBerries
# 44 "data/maps/CeruleanCity_House4/scripts.pory"
	release
# 45 "data/maps/CeruleanCity_House4/scripts.pory"
	end
# 46 "data/maps/CeruleanCity_House4/scripts.pory"

# 47 "data/maps/CeruleanCity_House4/scripts.pory"
@ Player has not recently sent Wonder News
# 48 "data/maps/CeruleanCity_House4/scripts.pory"
CeruleanCity_House4_EventScript_Waiting::
# 49 "data/maps/CeruleanCity_House4/scripts.pory"
	applymovement LOCALID_WONDER_NEWS_BERRY_MAN, Common_Movement_FacePlayer
# 50 "data/maps/CeruleanCity_House4/scripts.pory"
	waitmovement 0
# 51 "data/maps/CeruleanCity_House4/scripts.pory"
	msgbox CeruleanCity_House4_Text_WishCouldShareNewsWithOthers
# 52 "data/maps/CeruleanCity_House4/scripts.pory"
	release
# 53 "data/maps/CeruleanCity_House4/scripts.pory"
	end
# 54 "data/maps/CeruleanCity_House4/scripts.pory"

# 55 "data/maps/CeruleanCity_House4/scripts.pory"
@ Small reward for sending Wonder News every 1-3 times
# 56 "data/maps/CeruleanCity_House4/scripts.pory"
CeruleanCity_House4_EventScript_Reward_SentSmall::
# 57 "data/maps/CeruleanCity_House4/scripts.pory"
	call CeruleanCity_House4_EventScript_MovementReactionToNews
# 58 "data/maps/CeruleanCity_House4/scripts.pory"
	msgbox CeruleanCity_House4_Text_ThanksForSpreadingNewsTakeThis
# 59 "data/maps/CeruleanCity_House4/scripts.pory"
	giveitem REWARD_ITEM
# 60 "data/maps/CeruleanCity_House4/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_House4_EventScript_NoRoomForBerries
# 61 "data/maps/CeruleanCity_House4/scripts.pory"
	release
# 62 "data/maps/CeruleanCity_House4/scripts.pory"
	end
# 63 "data/maps/CeruleanCity_House4/scripts.pory"

# 64 "data/maps/CeruleanCity_House4/scripts.pory"
@ Big reward for sending Wonder News every 4th time
# 65 "data/maps/CeruleanCity_House4/scripts.pory"
CeruleanCity_House4_EventScript_Reward_SentBig::
# 66 "data/maps/CeruleanCity_House4/scripts.pory"
	call CeruleanCity_House4_EventScript_MovementReactionToNews
# 67 "data/maps/CeruleanCity_House4/scripts.pory"
	msgbox CeruleanCity_House4_Text_MagnificentNewsSpreadHaveBerries
# 68 "data/maps/CeruleanCity_House4/scripts.pory"
	giveitem REWARD_ITEM, 4
# 69 "data/maps/CeruleanCity_House4/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_House4_EventScript_NoRoomForBerries
# 70 "data/maps/CeruleanCity_House4/scripts.pory"
	release
# 71 "data/maps/CeruleanCity_House4/scripts.pory"
	end
# 72 "data/maps/CeruleanCity_House4/scripts.pory"

# 73 "data/maps/CeruleanCity_House4/scripts.pory"
@ Player has hit reward limit and must wait to receive new rewards
# 74 "data/maps/CeruleanCity_House4/scripts.pory"
CeruleanCity_House4_EventScript_AtMax::
# 75 "data/maps/CeruleanCity_House4/scripts.pory"
	applymovement LOCALID_WONDER_NEWS_BERRY_MAN, Common_Movement_FacePlayer
# 76 "data/maps/CeruleanCity_House4/scripts.pory"
	waitmovement 0
# 77 "data/maps/CeruleanCity_House4/scripts.pory"
	msgbox CeruleanCity_House4_Text_EnjoyingMyselfWithAllSortsOfNews
# 78 "data/maps/CeruleanCity_House4/scripts.pory"
	release
# 79 "data/maps/CeruleanCity_House4/scripts.pory"
	end
# 80 "data/maps/CeruleanCity_House4/scripts.pory"

# 81 "data/maps/CeruleanCity_House4/scripts.pory"
CeruleanCity_House4_EventScript_MovementReactionToNews::
# 82 "data/maps/CeruleanCity_House4/scripts.pory"
	playse SE_PIN
# 83 "data/maps/CeruleanCity_House4/scripts.pory"
	applymovement LOCALID_WONDER_NEWS_BERRY_MAN, Common_Movement_ExclamationMark
# 84 "data/maps/CeruleanCity_House4/scripts.pory"
	waitmovement 0
# 85 "data/maps/CeruleanCity_House4/scripts.pory"
	applymovement LOCALID_WONDER_NEWS_BERRY_MAN, Common_Movement_FacePlayer
# 86 "data/maps/CeruleanCity_House4/scripts.pory"
	waitmovement 0
# 87 "data/maps/CeruleanCity_House4/scripts.pory"
	applymovement LOCALID_WONDER_NEWS_BERRY_MAN, Common_Movement_Delay48
# 88 "data/maps/CeruleanCity_House4/scripts.pory"
	waitmovement 0
# 89 "data/maps/CeruleanCity_House4/scripts.pory"
	return
# 90 "data/maps/CeruleanCity_House4/scripts.pory"

# 91 "data/maps/CeruleanCity_House4/scripts.pory"
CeruleanCity_House4_EventScript_NoRoomForBerries::
# 92 "data/maps/CeruleanCity_House4/scripts.pory"
	msgbox CeruleanCity_House4_Text_YourBerryPouchIsFull
# 93 "data/maps/CeruleanCity_House4/scripts.pory"
	release
# 94 "data/maps/CeruleanCity_House4/scripts.pory"
	end
