Std_MsgboxNPC::
	lock
	faceplayer
	message 0x0
	waitmessage
	waitbuttonpress
	release
	return

Std_MsgboxSign::
	lockall
	message 0x0
	waitmessage
	waitbuttonpress
	releaseall
	return

Std_MsgboxDefault::
	message 0x0
	waitmessage
	waitbuttonpress
	return

Std_MsgboxYesNo::
	message 0x0
	waitmessage
	yesnobox 20, 8
	return

Std_ReceivedItem::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	call_if_eq VAR_0x8002, MUS_LEVEL_UP, EventScript_ReceivedItemFanfare1
	call_if_eq VAR_0x8002, MUS_OBTAIN_KEY_ITEM, EventScript_ReceivedItemFanfare2
	message 0x0
	waitmessage
	waitfanfare
	call_if_eq VAR_0x8002, MUS_LEVEL_UP, EventScript_ReceivedItemWaitFanfare
	putitemaway VAR_0x8000, VAR_0x8001
	call EventScript_RestorePrevTextColor
	return

EventScript_ReceivedItemFanfare1::
	playfanfare MUS_LEVEL_UP
	return

EventScript_ReceivedItemFanfare2::
	playfanfare MUS_OBTAIN_KEY_ITEM
	return

EventScript_ReceivedItemWaitFanfare::
	delay 50
	return

EventScript_UnusedReturn::
	return

EventScript_AskSaveGame::
	special Field_AskSaveTheGame
	waitstate
	return

EventScript_EndOfCurrentContentNPC::
	faceplayer
	lockall
	msgbox EventScript_EndOfCurrentContentNPC_Text_0
	releaseall
	end

EventScript_EndOfCurrentContentNPC_Text_0:
	.string "Hi! My name is ELLEN.\p"
	.string "This is currently the end of what\n"
	.string "this hack currently has to offer!\p"
	.string "Feel free to roam around what is\n"
	.string "currently available but…\p"
	.string "You will find nothing else beyond\n"
	.string "this mortal plane.$"
