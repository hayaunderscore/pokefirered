AUTO_GEN_TARGETS += src/data/pokemon/species_info.h
AUTO_GEN_TARGETS += src/data/pokemon/pokedex_entries.h

src/data/pokemon/species_info.h src/data/pokemon/pokedex_entries.h &:
	$(SPECIESPROC) "src/data/species.json" "."
