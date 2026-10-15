AUTO_GEN_SPECIES_RULES := src/data/pokemon/species_info.h
AUTO_GEN_SPECIES_RULES += src/data/pokemon/pokedex_entries.h
AUTO_GEN_SPECIES_RULES += src/data/pokemon/evolution.h
AUTO_GEN_SPECIES_RULES += src/data/pokemon/level_up_learnset_pointers.h
AUTO_GEN_SPECIES_RULES += src/data/pokemon/gender_difference_species.h
AUTO_GEN_SPECIES_RULES += src/data/pokemon_graphics/*.h

AUTO_GEN_TARGETS += $(AUTO_GEN_SPECIES_RULES)

$(AUTO_GEN_SPECIES_RULES) &: src/data/species.json
	$(SPECIESPROC) "src/data/species.json" "."
