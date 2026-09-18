#include "global.h"
#include "pokedex.h"
#include "save.h"
#include "pokemon.h"
#include "pokemon_storage_system.h"

#define OLD_NATIONAL_POKEDEX_UNOWN_KING 388
#define OLD_NATIONAL_POKEDEX_PETILIL 410
#define OLD_NATIONAL_POKEDEX_LILLIGANT 411

bool8 UpdateSave_v1_v2(const struct SaveSectorLocation *locations)
{
	// No real structure data is changed, only national dex data is
	const struct SaveBlock2* sOldSaveBlock2Ptr = (struct SaveBlock2*)(locations[0].data); // SECTOR_ID_SAVEBLOCK2
    const struct SaveBlock1* sOldSaveBlock1Ptr = (struct SaveBlock1*)(locations[1].data); // SECTOR_ID_SAVEBLOCK1_START
    struct PokemonStorage* sOldPokemonStoragePtr = (struct PokemonStorage*)(locations[5].data); // SECTOR_ID_PKMN_STORAGE_START
    s32 seen, caught;

    *gSaveBlock1Ptr = *sOldSaveBlock1Ptr;
    *gSaveBlock2Ptr = *sOldSaveBlock2Ptr;
    *gPokemonStoragePtr = *sOldPokemonStoragePtr;

#define CHANGE_NAT_DEX_ID(species) \
	seen = GetSetPokedexFlag(OLD_NATIONAL_POKEDEX_ ## species, FLAG_GET_SEEN); \
	caught = GetSetPokedexFlag(OLD_NATIONAL_POKEDEX_ ## species, FLAG_GET_CAUGHT); \
	if (seen) { \
		GetSetPokedexFlag(OLD_NATIONAL_POKEDEX_ ## species, FLAG_TOGGLE_SEEN); \
		GetSetPokedexFlag(NATIONAL_DEX_ ## species, FLAG_SET_SEEN); \
	} \
	if (caught) { \
		GetSetPokedexFlag(OLD_NATIONAL_POKEDEX_ ## species, FLAG_TOGGLE_CAUGHT); \
		GetSetPokedexFlag(NATIONAL_DEX_ ## species, FLAG_TOGGLE_CAUGHT); \
	}
    
    // Fix Pokedex flags from previous version
    CHANGE_NAT_DEX_ID(UNOWN_KING)
    CHANGE_NAT_DEX_ID(PETILIL)
    CHANGE_NAT_DEX_ID(LILLIGANT)
    
    gSaveBlock2Ptr->saveVersion = 2;

    return 1;
}