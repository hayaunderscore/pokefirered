#include "global.h"
#include "save.h"
#include "pokemon.h"
#include "pokemon_storage_system.h"

struct SaveBlock2_v0
{
    /*0x000*/ u8 playerName[PLAYER_NAME_LENGTH + 1];
    /*0x008*/ u8 playerGender; // MALE, FEMALE
    /*0x009*/ u8 specialSaveWarpFlags;
    /*0x00A*/ u8 playerTrainerId[TRAINER_ID_LENGTH];
    /*0x00E*/ u16 playTimeHours;
    /*0x010*/ u8 playTimeMinutes;
    /*0x011*/ u8 playTimeSeconds;
    /*0x012*/ u8 playTimeVBlanks;
    /*0x013*/ u8 optionsButtonMode;  // OPTIONS_BUTTON_MODE_[LR/L_EQUALS_A]
    /*0x014*/ u16 optionsTextSpeed:3; // OPTIONS_TEXT_SPEED_[SLOW/MID/FAST]
              u16 optionsWindowFrameType:5; // Specifies one of the 20 decorative borders for text boxes
    /*0x15*/  u16 optionsSound:1; // OPTIONS_SOUND_[MONO/STEREO]
              u16 optionsBattleStyle:1; // OPTIONS_BATTLE_STYLE_[SHIFT/SET]
              u16 optionsBattleSceneOff:1; // whether battle animations are disabled
              u16 regionMapZoom:1; // whether the map is zoomed in
    /*0x018*/ struct Pokedex pokedex;
    /*0x090*/ u8 optionsQuestLog:1;
    /*0x091*/ u8 filler_90[0x7];
    /*0x098*/ struct Time localTimeOffset;
    /*0x0A0*/ struct Time lastBerryTreeUpdate;
    /*0x0A8*/ u32 gcnLinkFlags; // Read by Pokemon Colosseum/XD
    /*0x0AC*/ bool8 unkFlag1; // Set TRUE, never read
    /*0x0AD*/ bool8 unkFlag2; // Set FALSE, never read
    /*0x0B0*/ struct BattleTowerData battleTower;
    /*0x898*/ u16 mapView[0x100];
    /*0xA98*/ struct LinkBattleRecords linkBattleRecords;
    /*0xAF0*/ struct BerryCrush berryCrush;
    /*0xB00*/ struct PokemonJumpRecords pokeJump;
    /*0xB10*/ struct BerryPickingResults berryPick;
    /*0xB20*/ u8 filler_B20[0x400];
    /*0xF20*/ u32 encryptionKey;
}; // size: 0xF24

struct SaveBlock1_v0
{
    /*0x0000*/ struct Coords16 pos;
    /*0x0004*/ struct WarpData location;
    /*0x000C*/ struct WarpData continueGameWarp;
    /*0x0014*/ struct WarpData dynamicWarp;
    /*0x001C*/ struct WarpData lastHealLocation;
    /*0x0024*/ struct WarpData escapeWarp;
    /*0x002C*/ u16 savedMusic;
    /*0x002E*/ u8 weather;
    /*0x002F*/ u8 weatherCycleStage;
    /*0x0030*/ u8 flashLevel;
    /*0x0032*/ u16 mapLayoutId;
    /*0x0034*/ u8 playerPartyCount;
    /*0x0038*/ struct Pokemon playerParty[PARTY_SIZE];
    /*0x0290*/ u32 money;
    /*0x0294*/ u16 coins;
    /*0x0296*/ u16 registeredItem; // registered for use with SELECT button
    /*0x0298*/ struct ItemSlot pcItems[PC_ITEMS_COUNT];
    /*0x0310*/ struct ItemSlot bagPocket_Items[BAG_ITEMS_COUNT];
    /*0x03b8*/ struct ItemSlot bagPocket_KeyItems[BAG_KEYITEMS_COUNT];
    /*0x0430*/ struct ItemSlot bagPocket_PokeBalls[BAG_POKEBALLS_COUNT];
    /*0x0464*/ struct ItemSlot bagPocket_TMHM[BAG_TMHM_COUNT];
    /*0x054c*/ struct ItemSlot bagPocket_Berries[BAG_BERRIES_COUNT];
    /*0x05F8*/ u8 seen1[DEX_FLAGS_NO];
    /*0x062C*/ u16 berryBlenderRecords[3]; // unused
    /*0x0632*/ u8 unused_632[6];
    /*0x0638*/ u16 trainerRematchStepCounter;
    /*0x063A*/ u8 ALIGNED(2) trainerRematches[MAX_REMATCH_ENTRIES];
    /*0x06A0*/ struct ObjectEvent objectEvents[OBJECT_EVENTS_COUNT];
    /*0x08E0*/ struct ObjectEventTemplate objectEventTemplates[OBJECT_EVENT_TEMPLATES_COUNT];
    /*0x0EE0*/ u8 flags[NUM_FLAG_BYTES];
    /*0x1000*/ u16 vars[VARS_COUNT];
    /*0x1200*/ u32 gameStats[NUM_GAME_STATS];
    /*0x1300*/ struct QuestLogScene questLog[QUEST_LOG_SCENE_COUNT];
    /*0x2CA0*/ u16 easyChatProfile[EASY_CHAT_BATTLE_WORDS_COUNT];
    /*0x2CAC*/ u16 easyChatBattleStart[EASY_CHAT_BATTLE_WORDS_COUNT];
    /*0x2CB8*/ u16 easyChatBattleWon[EASY_CHAT_BATTLE_WORDS_COUNT];
    /*0x2CC4*/ u16 easyChatBattleLost[EASY_CHAT_BATTLE_WORDS_COUNT];
    /*0x2CD0*/ struct Mail mail[MAIL_COUNT];
    /*0x2F10*/ u8 additionalPhrases[NUM_ADDITIONAL_PHRASE_BYTES];
    /*0x2F18*/ OldMan oldMan; // unused
    /*0x2F54*/ struct DewfordTrend dewfordTrends[5]; // unused
    /*0x2F80*/ struct DayCare daycare;
    /*0x309C*/ u8 giftRibbons[GIFT_RIBBONS_COUNT];
    /*0x30A7*/ struct ExternalEventData externalEventData;
    /*0x30BB*/ struct ExternalEventFlags externalEventFlags;
    /*0x30D0*/ struct Roamer roamer;
    /*0x30EC*/ struct EnigmaBerry enigmaBerry;
    /*0x3120*/ struct MysteryGiftSave mysteryGift;
    /*0x348C*/ u8 unused_348C[400];
    /*0x361C*/ struct RamScript ramScript;
    /*0x3A08*/ struct RecordMixingGift recordMixingGift; // unused
    /*0x3A18*/ u8 seen2[DEX_FLAGS_NO];
    /*0x3A4C*/ u8 rivalName[PLAYER_NAME_LENGTH + 1];
    /*0x3A54*/ struct FameCheckerSaveData fameChecker[NUM_FAMECHECKER_PERSONS];
    /*0x3A94*/ u8 unused_3A94[64];
    /*0x3AD4*/ u8 registeredTexts[UNION_ROOM_KB_ROW_COUNT][21];
    /*0x3BA8*/ struct TrainerNameRecord trainerNameRecords[20];
    /*0x3C98*/ struct DaycareMon route5DayCareMon;
    /*0x3D24*/ u8 unused_3D24[16];
    /*0x3D34*/ u32 towerChallengeId;
    /*0x3D38*/ struct TrainerTower trainerTower[NUM_TOWER_CHALLENGE_TYPES];
}; // size: 0x3D68

bool8 UpdateSave_v0_v1(const struct SaveSectorLocation *locations)
{
    /** The passed locations structure has been filled with pointers to the old save data on the heap already.
     * We just need to assign the old save blocks to the pointers on the heap accordingly. (Again I'm using
     * literal numbers here as I'm being overly cautious: what if I change the SECTOR_IDs for the save blocks in 
     * later save version?)
     */ 
    const struct SaveBlock2_v0* sOldSaveBlock2Ptr = (struct SaveBlock2_v0*)(locations[0].data); // SECTOR_ID_SAVEBLOCK2
    const struct SaveBlock1_v0* sOldSaveBlock1Ptr = (struct SaveBlock1_v0*)(locations[1].data); // SECTOR_ID_SAVEBLOCK1_START
    struct PokemonStorage* sOldPokemonStoragePtr = (struct PokemonStorage*)(locations[5].data); // SECTOR_ID_PKMN_STORAGE_START
    u32 arg, i, j, k;
    
#define COPY_FIELD(field) gSaveBlock2Ptr->field = sOldSaveBlock2Ptr->field
#define COPY_BLOCK(field) CpuCopy16(&sOldSaveBlock2Ptr->field, &gSaveBlock2Ptr->field, sizeof(gSaveBlock2Ptr->field))
#define COPY_ARRAY(field) for(i = 0; i < min(ARRAY_COUNT(gSaveBlock2Ptr->field), ARRAY_COUNT(sOldSaveBlock2Ptr->field)); i++) gSaveBlock2Ptr->field[i] = sOldSaveBlock2Ptr->field[i];
    
    /** We need to fill in any data that's new in this version. */
    gSaveBlock2Ptr->_saveSentinel = 0xFF;
    gSaveBlock2Ptr->saveVersion = 1;
    
    COPY_ARRAY(playerName);
    COPY_FIELD(playerGender);
    COPY_FIELD(specialSaveWarpFlags);
    COPY_ARRAY(playerTrainerId);
    COPY_FIELD(playTimeHours);
    COPY_FIELD(playTimeMinutes);
    COPY_FIELD(playTimeSeconds);
    COPY_FIELD(playTimeVBlanks);
    COPY_FIELD(optionsButtonMode);
    COPY_FIELD(optionsTextSpeed);
    COPY_FIELD(optionsWindowFrameType);
    COPY_FIELD(optionsSound);
    COPY_FIELD(optionsBattleStyle);
    COPY_FIELD(optionsBattleSceneOff);
    COPY_FIELD(optionsQuestLog);
    COPY_FIELD(regionMapZoom);
    
    COPY_FIELD(pokedex);
    COPY_FIELD(localTimeOffset);
    COPY_FIELD(lastBerryTreeUpdate);
    COPY_FIELD(gcnLinkFlags);
    COPY_FIELD(battleTower);
    COPY_FIELD(linkBattleRecords);
    COPY_FIELD(encryptionKey);
    COPY_FIELD(berryCrush);
    COPY_FIELD(pokeJump);
    COPY_FIELD(berryPick);

#undef COPY_FIELD
#undef COPY_BLOCK
#undef COPY_ARRAY

#define COPY_FIELD(field) gSaveBlock1Ptr->field = sOldSaveBlock1Ptr->field
#define COPY_BLOCK(field) CpuCopy16(&sOldSaveBlock1Ptr->field, &gSaveBlock1Ptr->field, sizeof(gSaveBlock1Ptr->field))
#define COPY_ARRAY(field) for(i = 0; i < min(ARRAY_COUNT(gSaveBlock1Ptr->field), ARRAY_COUNT(sOldSaveBlock1Ptr->field)); i++) gSaveBlock1Ptr->field[i] = sOldSaveBlock1Ptr->field[i];
    
    COPY_FIELD(pos);
    COPY_FIELD(location);
    COPY_FIELD(continueGameWarp);
    COPY_FIELD(dynamicWarp);
    COPY_FIELD(lastHealLocation);
    COPY_FIELD(escapeWarp);
    
    /** We don't need to copy things related to the current map, see below. */
    // COPY_FIELD(weather);
    // COPY_FIELD(weatherCycleStage);
    // COPY_FIELD(flashLevel);
    // COPY_FIELD(savedMusic);
    // COPY_FIELD(mapLayoutId);
    // COPY_BLOCK(mapView);
    // COPY_BLOCK(objectEvents);
    // COPY_BLOCK(objectEventTemplates);
    
    /** The pokemon structure hasn't changed at all this version, so
     *  we don't need to do anything special to copy the pokemon over. */
    COPY_FIELD(playerPartyCount);
    COPY_ARRAY(playerParty);
    
    COPY_FIELD(money);
    COPY_FIELD(coins);
    COPY_FIELD(registeredItem);
    
    /** Because we changed the PC items, it's not gonna be a straight copy. */
    COPY_ARRAY(pcItems);
    COPY_ARRAY(bagPocket_Items);
    COPY_ARRAY(bagPocket_KeyItems);
    COPY_ARRAY(bagPocket_PokeBalls);
    COPY_ARRAY(bagPocket_TMHM);
    COPY_ARRAY(bagPocket_Berries);
    
    COPY_BLOCK(seen1);
    COPY_BLOCK(berryBlenderRecords);
    COPY_FIELD(trainerRematchStepCounter);
    COPY_BLOCK(trainerRematches);
    
    COPY_BLOCK(flags);
    COPY_BLOCK(vars);
    COPY_BLOCK(questLog);
    
    COPY_BLOCK(easyChatProfile);
    COPY_BLOCK(easyChatBattleStart);
    COPY_BLOCK(easyChatBattleWon);
    COPY_BLOCK(easyChatBattleLost);
    COPY_BLOCK(mail);
    COPY_BLOCK(additionalPhrases);
    
    COPY_FIELD(oldMan);
    COPY_BLOCK(dewfordTrends);
    COPY_FIELD(daycare);
    COPY_BLOCK(giftRibbons);
    COPY_FIELD(externalEventData);
    COPY_FIELD(externalEventFlags);
    COPY_FIELD(roamer);
    COPY_FIELD(enigmaBerry);
    COPY_FIELD(mysteryGift);
    COPY_FIELD(ramScript);
    COPY_FIELD(recordMixingGift);
    COPY_BLOCK(seen2);
    COPY_BLOCK(trainerNameRecords);
    COPY_BLOCK(registeredTexts);
    COPY_FIELD(route5DayCareMon);
    COPY_FIELD(towerChallengeId);
    COPY_ARRAY(rivalName);
    COPY_BLOCK(fameChecker);
    COPY_BLOCK(trainerTower);
    
#undef COPY_FIELD
#undef COPY_BLOCK
#undef COPY_ARRAY
    
    /**
     * The pokemon structure hasn't changed at all this version, so
     * we can just assign across the old box storage to the new.  */ 
    *gPokemonStoragePtr = *sOldPokemonStoragePtr;
    
    /**
     * The most common kind of change that might happen between major versions are 
     * map changes. The save file usually saves the area around the player and 
     * event objects currently on the map, so that when the player resumes play, 
     * everything will be exactly where it was when they saved. But if the map has
     * changed at all, this means there could be incongruity between the saved
     * version of the map and the new version in the updated ROM. So to make it so
     * that the map reloads properly, we use the "Continue Game Warp" usually used
     * when the player clears the game to place the player at a known position and
     * with a newly loaded map and event objects. Here, we're using the last location
     * that the player healed, so the player will appear in the same spot they would
     * as if they blacked out. */
    SetContinueGameWarpStatus();
    gSaveBlock1Ptr->continueGameWarp = gSaveBlock1Ptr->lastHealLocation;
    
    return 1;
}