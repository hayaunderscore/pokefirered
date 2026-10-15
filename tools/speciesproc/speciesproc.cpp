// speciesproc
// Converts JSON species data into equivalent header files

#include "./nlohmann/json.hpp"
#include <algorithm>
#include <fstream>
#include <regex>
#include <sstream>
#include <string>
#include <unordered_map>

#define TYPES_PER_MON		   2
#define EGG_GROUPS_PER_MON	   2
#define ABILITIES_PER_MON	   2
#define EVOS_PER_MON		   5

#define SPECIESINFO_MALE	   0x00
#define SPECIESINFO_FEMALE	   0xFE
#define SPECIESINFO_GENDERLESS 0xFF

// specific paths to write to:
#define POKEMON_DATA_PATH		   "src/data/pokemon/" // For basic species data
#define POKEMON_GRAPHICS_DATA_PATH "src/data/pokemon_graphics/" // For graphic data

#define PATH_SPECIES_INFO		   POKEMON_DATA_PATH "species_info.h"
#define PATH_POKEDEX_TEXT		   POKEMON_DATA_PATH "pokedex_text_fr.h" // I might want to preserve LeafGreen's dex entries for later...
#define PATH_POKEDEX_ENTRIES	   POKEMON_DATA_PATH "pokedex_entries.h"
#define PATH_EVOLUTION_INFO		   POKEMON_DATA_PATH "evolution.h"
#define PATH_LEVEL_UP_INFO		   POKEMON_DATA_PATH "level_up_learnset_pointers.h"
#define PATH_GENDER_DIFFERENCE	   POKEMON_DATA_PATH "gender_difference_species.h"
#define PATH_SPECIES_NAMES		   "src/data/text/species_names.h"

#define PATH_BACK_PIC_COORDS	   POKEMON_GRAPHICS_DATA_PATH "back_pic_coordinates.h"
#define PATH_BACK_PIC_TABLE		   POKEMON_GRAPHICS_DATA_PATH "back_pic_table.h"
#define PATH_MON_ELEVATION		   POKEMON_GRAPHICS_DATA_PATH "enemy_mon_elevation.h"
#define PATH_MON_FOOTPRINTS		   POKEMON_GRAPHICS_DATA_PATH "footprint_table.h"
#define PATH_FRONT_PIC_COORDS	   POKEMON_GRAPHICS_DATA_PATH "front_pic_coordinates.h"
#define PATH_FRONT_PIC_TABLE	   POKEMON_GRAPHICS_DATA_PATH "front_pic_table.h"
#define PATH_PALETTE_TABLE		   POKEMON_GRAPHICS_DATA_PATH "palette_table.h"
#define PATH_SHINY_PALETTE_TABLE   POKEMON_GRAPHICS_DATA_PATH "shiny_palette_table.h"
#define PATH_ICON_TABLE			   POKEMON_GRAPHICS_DATA_PATH "icon_table.h"

// dex related things: we only check for national dex
#define PATH_POKEDEX_CONSTANTS "include/constants/pokedex.h"

template <typename T>
struct StatData {
	T hp, atk, def, spAtk, spDef, spd;
};

struct SpriteData {
	struct {
		uint8_t w, h;
	} size;
	uint8_t yOffset;
	std::string pointer;
};

struct EvolutionData {
	std::string method, param, species;
};

struct SpeciesData {
	std::string species;

	// Basic species info
	std::string name;
	StatData<uint8_t> baseStats;
	std::string types[TYPES_PER_MON];
	uint8_t catchRate;
	uint8_t expYield;
	StatData<uint16_t> evYield;
	std::string itemCommon;
	std::string itemRare;
	double genderRatio;
	uint16_t eggCycles;
	uint16_t friendship;
	std::string growthRate;
	std::string eggGroups[EGG_GROUPS_PER_MON];
	std::string abilities[ABILITIES_PER_MON];
	uint8_t safariZoneFleeRate;
	std::string bodyColor;
	bool noFlip;
	std::string levelUpLearnsetPointer;
	std::string genderDifferenceSpecies;
	uint8_t enemyMonElevation;
	std::vector<EvolutionData> evolutions;

	// Sprite data
	SpriteData back;
	SpriteData front;
	std::string palettePointer;
	std::string shinyPalettePointer;

	struct {
		std::string pointer;
		uint8_t paletteIdx;
	} icon;

	// Pokedex data
	std::string category;
	uint16_t height, weight;
	std::string description;
	std::string variationDescription;
	int16_t pokemonScale, pokemonOffset;
	int16_t trainerScale, trainerOffset;
};

static SpeciesData createSpeciesData(const std::string species, const nlohmann::ordered_json value);

static void dumpSpeciesInfo(void);
static void dumpPokedex(void);
static void dumpEvolutionInfo(void);
static void dumpLevelUpLearnsetInfo(void);
static void dumpGenderDifferences(void);
static void dumpEnemyMonElevation(void);
static void dumpSpeciesNames(void);

// static void dumpBackSpriteInfo(void);
// static void dumpFrontSpriteInfo(void);
// static void dumpFootprints(void);
// static void dumpPaletteTables(void);
// static void dumpIconInfo(void);

std::vector<SpeciesData> speciesMap;
std::string speciesDexConstants;

int main(int argc, char* argv[])
{
	if (argc != 3) {
		std::fprintf(stderr,
			"USAGE: speciesproc <species-path> <data-folder-path>");
		exit(1);
	}

	std::ifstream entries(PATH_POKEDEX_CONSTANTS);
	if (!entries.is_open()) {
		std::fprintf(stderr, "FAILED to open %s!", PATH_POKEDEX_CONSTANTS);
		exit(1);
	}
	std::stringstream buf;
	buf << entries.rdbuf();
	speciesDexConstants = buf.str();

	std::string speciesPath = argv[1];
	std::ifstream file(speciesPath);

	nlohmann::ordered_json j = nlohmann::ordered_json::parse(file);
	for (auto& [species, info] : j.items()) {
		speciesMap.push_back(createSpeciesData(species, info));
		std::printf("Processed data for %s\n", species.c_str());
	}

	dumpSpeciesInfo();
	dumpPokedex();
	dumpEvolutionInfo();
	dumpLevelUpLearnsetInfo();
	dumpGenderDifferences();
	dumpEnemyMonElevation();
	dumpSpeciesNames();

	return 0;
}

static SpriteData createSpriteData(const nlohmann::ordered_json value)
{
	SpriteData data { };

	data.yOffset = value.value("y_offset", 0);
	data.pointer = value.value("picture", "NULL");

	if (value.contains("size") && value.at("size").is_array()) {
		const auto& j = value.at("size");
		data.size.w = j.at(0).get<uint8_t>();
		data.size.h = j.at(1).get<uint8_t>();
	}

	return data;
}

std::string stringFromJsonStrArray(const nlohmann::ordered_json value)
{
	std::string str;
	auto vec = value.get<std::vector<std::string>>();
	for (const auto& line : vec) {
		if (!str.empty())
			str.append("\n");
		str.append(line);
	}
	return str;
}

static SpeciesData createSpeciesData(const std::string species, const nlohmann::ordered_json value)
{
	SpeciesData spec { };
	int i;

	spec.species = species;

	// do basic info first
	spec.name = value.value("name", ""); // Empty string means we do not put it in species_names.h
	// base stats
	spec.baseStats.hp = value.value("baseHP", 0);
	spec.baseStats.atk = value.value("baseAttack", 0);
	spec.baseStats.def = value.value("baseDefense", 0);
	spec.baseStats.spd = value.value("baseSpeed", 0);
	spec.baseStats.spAtk = value.value("baseSpAttack", 0);
	spec.baseStats.spDef = value.value("baseSpDefense", 0);

	if (value.contains("types")) {
		for (i = 0; i < TYPES_PER_MON; i++)
			spec.types[i] = value.at("types").at(i);
	} else {
		spec.types[0] = "TYPE_NORMAL";
		spec.types[1] = "TYPE_NORMAL";
	}

	spec.catchRate = value.value("catchRate", 0);
	spec.expYield = value.value("expYield", 0);

	spec.evYield.hp = value.value("evYield_HP", 0);
	spec.evYield.atk = value.value("evYield_Attack", 0);
	spec.evYield.def = value.value("evYield_Defense", 0);
	spec.evYield.spd = value.value("evYield_Speed", 0);
	spec.evYield.spAtk = value.value("evYield_SpAttack", 0);
	spec.evYield.spDef = value.value("evYield_SpDefense", 0);

	spec.itemCommon = value.value("itemCommon", "ITEM_NONE");
	spec.itemRare = value.value("itemRare", "ITEM_NONE");

	if (value.contains("genderRatio")) {
		bool isString = value.at("genderRatio").is_string();
		if (isString) {
			std::string v = value.at("genderRatio").get<std::string>();
			if (v == "MON_MALE") {
				spec.genderRatio = 0;
			} else if (v == "MON_FEMALE") {
				spec.genderRatio = 254;
			} else if (v == "MON_GENDERLESS") {
				spec.genderRatio = 255;
			}
		} else {
			// Clamp this just in case
			spec.genderRatio = std::clamp<double>(value.at("genderRatio").get<double>(), 0.0f, 100.0f);
		}
	}

	spec.eggCycles = value.value("eggCycles", 0);
	spec.friendship = value.value("friendship", 70);
	spec.growthRate = value.value("growthRate", "GROWTH_FAST");

	if (value.contains("eggGroups")) {
		for (i = 0; i < EGG_GROUPS_PER_MON; i++)
			spec.eggGroups[i] = value.at("eggGroups").at(i);
	} else {
		spec.eggGroups[0] = "EGG_GROUP_NONE";
		spec.eggGroups[1] = "EGG_GROUP_NONE";
	}

	if (value.contains("abilities")) {
		for (i = 0; i < ABILITIES_PER_MON; i++)
			spec.abilities[i] = value.at("abilities").at(i);
	} else {
		spec.abilities[0] = "ABILITY_NONE";
		spec.abilities[1] = "ABILITY_NONE";
	}

	spec.safariZoneFleeRate = value.value("safariZoneFleeRate", 0);
	spec.bodyColor = value.value("bodyColor", "BODY_COLOR_BLACK");
	spec.noFlip = value.value("noFlip", false);
	// TODO: Ideally, I'd want this to be it's own array so you can directly edit it in species.json
	spec.levelUpLearnsetPointer = value.value("levelUpLearnset", "sBulbasaurLevelUpLearnset");
	spec.genderDifferenceSpecies = value.value("genderDifferenceSpecies", "");
	spec.enemyMonElevation = value.value("enemyMonElevation", 0);

	if (value.contains("evolutions")) {
		int count = 0;
		for (const auto& evo : value.at("evolutions")) {
			count++;
			if (count > EVOS_PER_MON)
				break; // Too many!

			EvolutionData evoData { };
			evoData.method = evo.at("method");
			// Param might be a number and not a string
			if (evo.at("param").is_number())
				evoData.param = std::to_string(evo.at("param").get<int>());
			else if (evo.at("param").is_string())
				evoData.param = evo.at("param");
			evoData.species = evo.at("species");

			spec.evolutions.push_back(evoData);
		}
	}

	// Sprite data
	if (value.contains("back"))
		spec.back = createSpriteData(value.at("back"));
	if (value.contains("front"))
		spec.front = createSpriteData(value.at("front"));
	spec.palettePointer = value.value("palette", "NULL");
	spec.shinyPalettePointer = value.value("shinyPalette", "NULL");
	spec.icon.pointer = value.value("icon", "NULL");
	spec.icon.paletteIdx = value.value("iconPalette", 0);

	// Pokedex info
	spec.category = value.value("categoryName", "");
	spec.height = value.value("height", 0);
	spec.weight = value.value("weight", 0);
	if (value.contains("description"))
		spec.description = stringFromJsonStrArray(value.at("description"));
	if (value.contains("variationDescription"))
		spec.variationDescription = stringFromJsonStrArray(value.at("variationDescription"));
	spec.pokemonScale = value.value("pokemonScale", 0);
	spec.pokemonOffset = value.value("pokemonOffset", 0);
	spec.trainerScale = value.value("trainerScale", 0);
	spec.trainerOffset = value.value("trainerOffset", 0);

	return spec;
}

#define ADD_NAMED_ARG(name, eqv) \
	out << "\t\t." << name << " = " << std::to_string(v.eqv) << ",\n";

#define ADD_NAMED_ARG_BOOLEAN(name, eqv) \
	out << "\t\t." << name << " = " << (v.eqv ? "TRUE" : "FALSE") << ",\n";

#define ADD_NAMED_ARG_STR(name, eqv) \
	out << "\t\t." << name << " = " << v.eqv << ",\n";

#define ADD_NAMED_ARG_FORMAT_STR(name, eqv) \
	out << "\t\t." << name << " = _(" << '"' << v.eqv << '"' << "),\n";

#define ADD_NAMED_ARG_FORMAT_COMPOUND_STR(name, eqv) \
	out << "\t\t." << name << " = COMPOUND_STRING(" << v.eqv << "),\n";

// Source - https://stackoverflow.com/a/13172514
// Posted by Some programmer dude, modified by community. See post 'Timeline' for change history
// Retrieved 2026-10-14, License - CC BY-SA 4.0

std::vector<std::string> split_string(const std::string& str,
	const std::string& delimiter)
{
	std::vector<std::string> strings;

	std::string::size_type pos = 0;
	std::string::size_type prev = 0;
	while ((pos = str.find(delimiter, prev)) != std::string::npos) {
		strings.push_back(str.substr(prev, pos - prev));
		prev = pos + delimiter.size();
	}

	// To get the last substring (or only, if delimiter is not found)
	strings.push_back(str.substr(prev));

	return strings;
}

#define ADD_NAMED_ARG_FORMAT_COMPOUND_STR_MULTILINE(name, eqv) \
	out << "\t\t." << name << " = COMPOUND_STRING(\n";         \
	{                                                          \
		auto lines = split_string(v.eqv, "\n");                \
		for (size_t i = 0; i < lines.size(); i++) {            \
			out << "\t\t\t";                                   \
			out << '"';                                        \
			out << lines[i];                                   \
			if (i < lines.size() - 1)                          \
				out << "\\n";                                  \
			out << '"';                                        \
			if (i < lines.size() - 1)                          \
				out << "\n";                                   \
		}                                                      \
	}                                                          \
	out << "),\n";

#define ADD_VALUED_ARG(name, eqv) \
	out << "\t\t." << name << " = " << eqv << ",\n";

#define ADD_NAMED_ARRAY(name, eqv, size) \
	out << "\t\t." << name << " = {";    \
	for (int i = 0; i < size; i++) {     \
		out << v.eqv[i];                 \
		if (i < size - 1)                \
			out << ", ";                 \
		else                             \
			out << "},\n";               \
	}

#define ADD_NAMED_ARRAY_STRING(name, eqv, size)     \
	out << "\t\t." << name << " = {";               \
	for (int i = 0; i < size; i++) {                \
		out << (v.eqv[i].empty() ? "0" : v.eqv[i]); \
		if (i < size - 1)                           \
			out << ", ";                            \
		else                                        \
			out << "},\n";                          \
	}

#define ADD_NAMED_ARG_DEFINE(name, eqv, def) \
	out << "\t\t." << name << " = " << def << "(" << std::to_string(v.eqv) << "),\n";

static void printHeader(std::ofstream& out)
{
	out << "//\n//DO NOT MODIFY THIS FILE! It is auto-generated from src/data/species.json\n//\n";
}

static void dumpSpeciesInfo(void)
{
	std::ofstream out(PATH_SPECIES_INFO, std::ios::out | std::ios::trunc);
	if (!out.is_open()) {
		std::fprintf(stderr, "FAILED to open %s!", PATH_SPECIES_INFO);
		exit(1);
	}
	printHeader(out);
	// put the PERCENT_FEMALE define first
	out << "#define PERCENT_FEMALE(percent) min(254, ((percent * 255) / 100))\n";
	// start creating the array
	out << "const struct SpeciesInfo gSpeciesInfo[] =\n{\n";
	for (const auto& v : speciesMap) {
		const std::string k = v.species;

		// break upon encountering SPECIES_EGG; we're done here
		if (k == "SPECIES_EGG")
			break;

		// index
		out << "\t[" << k << "] = ";
		if (k == "SPECIES_NONE") // just do nothing bro
		{
			out << "{0},\n";
			continue;
		}
		out << "\n\t{\n";

		// actual stuff
		ADD_NAMED_ARG("baseHP", baseStats.hp);
		ADD_NAMED_ARG("baseAttack", baseStats.atk);
		ADD_NAMED_ARG("baseDefense", baseStats.def);
		ADD_NAMED_ARG("baseSpeed", baseStats.spd);
		ADD_NAMED_ARG("baseSpAttack", baseStats.spAtk);
		ADD_NAMED_ARG("baseSpDefense", baseStats.spDef);

		ADD_NAMED_ARRAY_STRING("types", types, TYPES_PER_MON)

		ADD_NAMED_ARG("catchRate", catchRate);
		ADD_NAMED_ARG("expYield", expYield);

		ADD_NAMED_ARG("evYield_HP", evYield.hp);
		ADD_NAMED_ARG("evYield_Attack", evYield.atk);
		ADD_NAMED_ARG("evYield_Defense", evYield.def);
		ADD_NAMED_ARG("evYield_Speed", evYield.spd);
		ADD_NAMED_ARG("evYield_SpAttack", evYield.spAtk);
		ADD_NAMED_ARG("evYield_SpDefense", evYield.spDef);

		ADD_NAMED_ARG_STR("itemCommon", itemCommon);
		ADD_NAMED_ARG_STR("itemRare", itemRare);

		// Usually a percentage, so chuck this in
		if (v.genderRatio < 100 && v.genderRatio > 0)
			ADD_NAMED_ARG_DEFINE("genderRatio", genderRatio, "PERCENT_FEMALE");
		// otherwise...
		if (v.genderRatio == SPECIESINFO_MALE)
			ADD_VALUED_ARG("genderRatio", "MON_MALE");
		if (v.genderRatio == SPECIESINFO_FEMALE)
			ADD_VALUED_ARG("genderRatio", "MON_FEMALE");
		if (v.genderRatio == SPECIESINFO_GENDERLESS)
			ADD_VALUED_ARG("genderRatio", "MON_GENDERLESS");

		ADD_NAMED_ARG("eggCycles", eggCycles);
		ADD_NAMED_ARG("friendship", friendship);
		ADD_NAMED_ARG_STR("growthRate", growthRate);

		ADD_NAMED_ARRAY_STRING("eggGroups", eggGroups, EGG_GROUPS_PER_MON)
		ADD_NAMED_ARRAY_STRING("abilities", abilities, ABILITIES_PER_MON)

		ADD_NAMED_ARG("safariZoneFleeRate", safariZoneFleeRate);
		ADD_NAMED_ARG_STR("bodyColor", bodyColor);
		ADD_NAMED_ARG_BOOLEAN("noFlip", noFlip);

		out << "\t},\n";
	}
	out << "};\n";
}

static void dumpPokedex(void)
{
	std::ofstream out(PATH_POKEDEX_ENTRIES, std::ios::out | std::ios::trunc);
	if (!out.is_open()) {
		std::fprintf(stderr, "FAILED to open %s!", PATH_POKEDEX_ENTRIES);
		exit(1);
	}
	printHeader(out);

	// start creating the array
	out << "const struct PokedexEntry gPokedexEntries[] =\n{\n";

	std::regex specRegex("SPECIES_");
	for (const auto& v : speciesMap) {
		// break upon encountering SPECIES_EGG; we're done here
		if (v.species == "SPECIES_EGG")
			break;

		const std::string k = std::regex_replace(v.species, specRegex, "NATIONAL_DEX_");

		// Skip if we couldn't find a match.
		if (speciesDexConstants.find(k) == std::string::npos)
			continue;

		// index
		out << "\t[" << k << "] = ";
		out << "\n\t{\n";

		ADD_NAMED_ARG_FORMAT_STR("categoryName", category);
		ADD_NAMED_ARG("height", height);
		ADD_NAMED_ARG("weight", weight);
		ADD_NAMED_ARG_FORMAT_COMPOUND_STR_MULTILINE("description", description);
		ADD_NAMED_ARG_FORMAT_COMPOUND_STR_MULTILINE("unusedDescription", variationDescription);
		ADD_NAMED_ARG("pokemonScale", pokemonScale);
		ADD_NAMED_ARG("pokemonOffset", pokemonOffset);
		ADD_NAMED_ARG("trainerScale", trainerScale);
		ADD_NAMED_ARG("trainerOffset", trainerOffset);

		out << "\t},\n";
	}
	out << "};\n";
}

static void dumpEvolutionInfo(void)
{
	std::ofstream out(PATH_EVOLUTION_INFO, std::ios::out | std::ios::trunc);
	if (!out.is_open()) {
		std::fprintf(stderr, "FAILED to open %s!", PATH_EVOLUTION_INFO);
		exit(1);
	}
	printHeader(out);

	// start creating the array
	out << "const struct Evolution gEvolutionTable[NUM_SPECIES][EVOS_PER_MON] =\n{\n";

	for (const auto& v : speciesMap) {
		const std::string k = v.species;

		// break upon encountering SPECIES_EGG; we're done here
		if (k == "SPECIES_EGG")
			break;

		if (v.evolutions.empty())
			continue;

		// index
		out << "\t[" << k << "] = {";

		for (size_t i = 0; i < v.evolutions.size(); i++) {
			out << "{";
			out << v.evolutions[i].method;
			out << ", ";
			out << v.evolutions[i].param;
			out << ", ";
			out << v.evolutions[i].species;
			out << "}";
			if (i < v.evolutions.size() - 1)
				out << ",\n";
		}

		out << "},\n";
	}
	out << "};\n";
}

static void dumpLevelUpLearnsetInfo(void)
{
	std::ofstream out(PATH_LEVEL_UP_INFO, std::ios::out | std::ios::trunc);
	if (!out.is_open()) {
		std::fprintf(stderr, "FAILED to open %s!", PATH_LEVEL_UP_INFO);
		exit(1);
	}
	printHeader(out);

	// start creating the array
	out << "const u16 *const gLevelUpLearnsets[NUM_SPECIES] =\n{\n";

	for (const auto& v : speciesMap) {
		const std::string k = v.species;

		// break upon encountering SPECIES_EGG; we're done here
		if (k == "SPECIES_EGG")
			break;

		// index
		out << "\t[" << k << "] = ";
		out << v.levelUpLearnsetPointer;
		out << ",\n";
	}
	out << "};\n";
}

static void dumpGenderDifferences(void)
{
	std::ofstream out(PATH_GENDER_DIFFERENCE, std::ios::out | std::ios::trunc);
	if (!out.is_open()) {
		std::fprintf(stderr, "FAILED to open %s!", PATH_GENDER_DIFFERENCE);
		exit(1);
	}
	printHeader(out);

	// start creating the array
	out << "const u16 gSpeciesGenderDifferences[NUM_SPECIES] =\n{\n";

	for (const auto& v : speciesMap) {
		const std::string k = v.species;

		// break upon encountering SPECIES_EGG; we're done here
		if (k == "SPECIES_EGG")
			break;

		if (v.genderDifferenceSpecies.empty())
			continue;

		// index
		out << "\t[" << k << "] = ";
		out << v.genderDifferenceSpecies;
		out << ",\n";
	}
	out << "};\n";
}

static void dumpEnemyMonElevation(void)
{
	std::ofstream out(PATH_MON_ELEVATION, std::ios::out | std::ios::trunc);
	if (!out.is_open()) {
		std::fprintf(stderr, "FAILED to open %s!", PATH_MON_ELEVATION);
		exit(1);
	}
	printHeader(out);

	// start creating the array
	out << "const u8 gEnemyMonElevation[NUM_SPECIES] =\n{\n";

	for (const auto& v : speciesMap) {
		const std::string k = v.species;

		// break upon encountering SPECIES_EGG; we're done here
		if (k == "SPECIES_EGG")
			break;

		if (v.enemyMonElevation == 0)
			continue;

		// index
		out << "\t[" << k << "] = ";
		out << std::to_string(v.enemyMonElevation);
		out << ",\n";
	}
	out << "};\n";
}

static void dumpSpeciesNames(void)
{
	std::ofstream out(PATH_SPECIES_NAMES, std::ios::out | std::ios::trunc);
	if (!out.is_open()) {
		std::fprintf(stderr, "FAILED to open %s!", PATH_SPECIES_NAMES);
		exit(1);
	}
	printHeader(out);

	// start creating the array
	out << "const u8 gSpeciesNames[][POKEMON_NAME_LENGTH + 1] =\n{\n";

	for (const auto& v : speciesMap) {
		const std::string k = v.species;

		// break upon encountering SPECIES_EGG; we're done here
		if (k == "SPECIES_EGG")
			break;

		if (v.name.empty())
			continue;

		// index
		out << "\t[" << k << "] = _(\"";
		out << v.name;
		out << "\"),\n";
	}
	out << "};\n";
}
