# speciesproc

Parses `species.json` into separate files for Pokemon species definitions.

Because it gets tiring to edit a dozen files at once.

## Things that are handled

- Basic species info (`species_info.h`)
- Evolution info (`evolution.h`)
- Level up learnset *pointers* (`level_up_learnset_pointers.h`)
- Pokedex entries (`pokedex_entries.h`)
- Pokemon graphics (all header files in `pokemon_graphics/`)

## Things that aren't handled
- Egg moves
- TM/HM learnsets
- Tutor learnsets
- Level up learnset definitions (still located in `level_up_learnsets.h`)
- Graphics pointers (still located in `graphics.c`)

## Format

Each entry is represented by its `SPECIES_` constant.
If you want the species to show up on the Pokedex, make sure to have a `NATIONAL_DEX_` entry in `include/constants/pokedex.h` as well.

As an example, here's Bulbasaur's `species.json` definition:

```json
"SPECIES_BULBASAUR": { // Make sure this matches with an existing SPECIES_ constant.
	// The actual name of the species.
	"name": "BULBASAUR",
	
	// SPECIES INFO //
	// The base stats.
	"baseHP": 45,
	"baseAttack": 49,
	"baseDefense": 49,
	"baseSpeed": 45,
	"baseSpAttack": 65,
	"baseSpDefense": 65,
	// The types of the species.
	// If it is one type, have both types be the same.
	"types": ["TYPE_GRASS", "TYPE_POISON"],
	// Catch rate.
	"catchRate": 45,
	// EXP yield.
	"expYield": 64,
	// EV yields upon defeating it in battle.
	"evYield_HP": 0,
	"evYield_Attack": 0,
	"evYield_Defense": 0,
	"evYield_Speed": 0,
	"evYield_SpAttack": 1,
	"evYield_SpDefense": 0,
	// The items the species can carry.
	"itemCommon": "ITEM_NONE",
	"itemRare": "ITEM_NONE",
	// The gender ratio.
	// Can be a number from 0-99, or "MON_MALE", "MON_FEMALE" or "MON_GENDERLESS" for mono-gender species.
	"genderRatio": 12.5,
	// Egg cycles.
	"eggCycles": 20,
	// Base friendship.
	"friendship": 70,
	// Growth rate. Must match a specific one in the constants.
	"growthRate": "GROWTH_MEDIUM_SLOW",
	// Egg groups. Must be two.
	"eggGroups": ["EGG_GROUP_MONSTER", "EGG_GROUP_GRASS"],
	// Abilities.
	"abilities": ["ABILITY_OVERGROW", "ABILITY_NONE"],
	// Flee rate in the safari zone.
	"safariZoneFleeRate": 0,
	// Body color.
	"bodyColor": "BODY_COLOR_GREEN",
	// I'm honestly not sure what this really does LMAO
	"noFlip": false,
	// Evolution data.
	// See include/constants/pokemon.h for more info.
	"evolutions": [
		{
			"method": "EVO_LEVEL",
			"param": 16,
			"species": "SPECIES_IVYSAUR"
		}
	],
	// Level up learnset.
	// Must match with an array in `level_up_learnsets.h`.
	"levelUpLearnset": "sBulbasaurLevelUpLearnset",
	// If a pokemon has a gender difference, specify the species number to use for visuals and cries.
	"genderDifferenceSpecies": "SPECIES_INDEEDEE_MALE",
	
	// SPRITES //
	// Back sprite.
	"back": {
		"size": [48, 32], // w, h
		"y_offset": 16,
		"picture": "gMonBackPic_Bulbasaur" // Must match with an array in `graphics.h`.
	},
	// Front sprite.
	"front": {
		"size": [40, 40],
		"y_offset": 16,
		"picture": "gMonFrontPic_Bulbasaur"
	},
	// The default palette.
	"palette": "gMonPalette_Bulbasaur",
	// The shiny palette.
	"shinyPalette": "gMonShinyPalette_Bulbasaur",
	// Footprint, shown in the Pokedex.
	"footprint": "gMonFootprint_Bulbasaur",
	// Icon, must match with an array in `graphics.h`.
	"icon": "gMonIcon_Bulbasaur",
	// Icon palette index, from 0-2.
	"iconPalette": 1,
	
	// POKEDEX ENTRY //
	// Category name.
	"categoryName": "SEED",
	// Info about the height and weight.
	"height": 7,
	"weight": 69,
	// Description.
	"description": [
		"There is a plant seed on its back right",
		"from the day this POKéMON is born.",
		"The seed slowly grows larger."
	],
	// Description for the other gender, if possible.
	"variationDescription": [
		"There is a plant seed on its back right",
		"from the day this POKéMON is born.",
		"The seed slowly grows larger."
	],
	// The scales of the sprite comparisons in the Pokedex.
	"pokemonScale": 356,
	"pokemonOffset": 16,
	"trainerScale": 256,
	"trainerOffset": -2
}
```
