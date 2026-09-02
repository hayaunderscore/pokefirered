INTERFACEGFXDIR := graphics/interface
BTLANMSPRGFXDIR := graphics/battle_anims/sprites
UNUSEDGFXDIR := graphics/unused
BATINTGFXDIR := graphics/battle_interface
JPCONTESTGFXDIR := graphics/contest/japanese

CASTFORMGFXDIR := graphics/pokemon/castform
$(CASTFORMGFXDIR)/front.4bpp: $(CASTFORMGFXDIR)/normal/front.4bpp \
											$(CASTFORMGFXDIR)/sunny/front.4bpp \
											$(CASTFORMGFXDIR)/rainy/front.4bpp \
											$(CASTFORMGFXDIR)/snowy/front.4bpp
	@cat $^ >$@

$(CASTFORMGFXDIR)/back.4bpp: $(CASTFORMGFXDIR)/normal/back.4bpp \
									 $(CASTFORMGFXDIR)/sunny/back.4bpp \
									 $(CASTFORMGFXDIR)/rainy/back.4bpp \
									 $(CASTFORMGFXDIR)/snowy/back.4bpp
	@cat $^ >$@

$(CASTFORMGFXDIR)/normal.gbapal: $(CASTFORMGFXDIR)/normal/normal.gbapal \
									 $(CASTFORMGFXDIR)/sunny/normal.gbapal \
									 $(CASTFORMGFXDIR)/rainy/normal.gbapal \
									 $(CASTFORMGFXDIR)/snowy/normal.gbapal
	@cat $^ >$@

$(CASTFORMGFXDIR)/shiny.gbapal: $(CASTFORMGFXDIR)/normal/shiny.gbapal \
									$(CASTFORMGFXDIR)/sunny/shiny.gbapal \
									$(CASTFORMGFXDIR)/rainy/shiny.gbapal \
									$(CASTFORMGFXDIR)/snowy/shiny.gbapal
	@cat $^ >$@

$(BTLANMSPRGFXDIR)/ice_cube.4bpp: $(BTLANMSPRGFXDIR)/ice_cube_0.4bpp \
						  $(BTLANMSPRGFXDIR)/ice_cube_1.4bpp \
						  $(BTLANMSPRGFXDIR)/ice_cube_2.4bpp \
						  $(BTLANMSPRGFXDIR)/ice_cube_3.4bpp
	@cat $^ >$@

$(UNUSEDGFXDIR)/obi_palpak1.gbapal: $(UNUSEDGFXDIR)/old_pal1.gbapal \
									$(UNUSEDGFXDIR)/old_pal2.gbapal \
									$(UNUSEDGFXDIR)/old_pal3.gbapal
	@cat $^ >$@

$(UNUSEDGFXDIR)/obi_palpak3.gbapal: $(UNUSEDGFXDIR)/old_pal5.gbapal \
									$(UNUSEDGFXDIR)/old_pal6.gbapal \
									$(UNUSEDGFXDIR)/old_pal7.gbapal
	@cat $^ >$@

$(UNUSEDGFXDIR)/obi1.4bpp: $(UNUSEDGFXDIR)/old_bulbasaur.4bpp \
						   $(UNUSEDGFXDIR)/old_charizard.4bpp
	@cat $^ >$@

$(UNUSEDGFXDIR)/obi2.4bpp: $(UNUSEDGFXDIR)/old_bulbasaur2.4bpp \
						   $(UNUSEDGFXDIR)/old_battle_interface_1.4bpp \
						   $(UNUSEDGFXDIR)/old_battle_interface_2.4bpp \
						   $(UNUSEDGFXDIR)/old_battle_interface_3.4bpp
	@cat $^ >$@

$(INTERFACEGFXDIR)/hp_numbers.4bpp: $(INTERFACEGFXDIR)/hp_bar_anim.4bpp \
							$(INTERFACEGFXDIR)/numbers1.4bpp \
							$(INTERFACEGFXDIR)/numbers2.4bpp
	@cat $^ >$@

$(UNUSEDGFXDIR)/redyellowgreen_frame.bin: $(UNUSEDGFXDIR)/red_frame.bin \
										  $(UNUSEDGFXDIR)/yellow_frame.bin \
										  $(UNUSEDGFXDIR)/green_frame.bin \
										  $(UNUSEDGFXDIR)/blank_frame.bin
	@cat $^ >$@

$(BATINTGFXDIR)/textbox.gbapal: $(BATINTGFXDIR)/textbox1.gbapal $(BATINTGFXDIR)/textbox2.gbapal
	cat $^ > $@

$(JPCONTESTGFXDIR)/composite_1.4bpp: $(JPCONTESTGFXDIR)/frame_1.4bpp \
								  $(JPCONTESTGFXDIR)/floor.4bpp \
								  $(JPCONTESTGFXDIR)/frame_2.4bpp \
								  $(JPCONTESTGFXDIR)/symbols.4bpp \
								  $(JPCONTESTGFXDIR)/meter.4bpp \
								  $(JPCONTESTGFXDIR)/classes.4bpp \
								  $(JPCONTESTGFXDIR)/numbers_2.4bpp
	@cat $^ >$@

$(JPCONTESTGFXDIR)/composite_2.4bpp: $(JPCONTESTGFXDIR)/interface.4bpp \
									$(JPCONTESTGFXDIR)/audience.4bpp
	@cat $^ >$@

$(BTLANMSPRGFXDIR)/ice_crystals.4bpp: $(BTLANMSPRGFXDIR)/ice_crystals_0.4bpp \
						  $(BTLANMSPRGFXDIR)/ice_crystals_1.4bpp \
						  $(BTLANMSPRGFXDIR)/ice_crystals_2.4bpp \
						  $(BTLANMSPRGFXDIR)/ice_crystals_3.4bpp \
						  $(BTLANMSPRGFXDIR)/ice_crystals_4.4bpp
	@cat $^ >$@

$(BTLANMSPRGFXDIR)/mud_sand.4bpp: $(BTLANMSPRGFXDIR)/mud_sand_0.4bpp \
						  $(BTLANMSPRGFXDIR)/mud_sand_1.4bpp
	@cat $^ >$@

$(BTLANMSPRGFXDIR)/flower.4bpp: $(BTLANMSPRGFXDIR)/flower_0.4bpp \
						  $(BTLANMSPRGFXDIR)/flower_1.4bpp
	@cat $^ >$@

$(BTLANMSPRGFXDIR)/spark.4bpp: $(BTLANMSPRGFXDIR)/spark_0.4bpp \
						  $(BTLANMSPRGFXDIR)/spark_1.4bpp
	@cat $^ >$@

POKEDEXAREAMARKERSDATADIR := graphics/pokedex/area_markers

POKEDEXAREAMARKERFILES := \
	$(POKEDEXAREAMARKERSDATADIR)/marker_0.4bpp \
	$(POKEDEXAREAMARKERSDATADIR)/marker_1.4bpp \
	$(POKEDEXAREAMARKERSDATADIR)/marker_2.4bpp \
	$(POKEDEXAREAMARKERSDATADIR)/marker_3.4bpp \
	$(POKEDEXAREAMARKERSDATADIR)/marker_4.4bpp \
	$(POKEDEXAREAMARKERSDATADIR)/marker_5.4bpp \
	$(POKEDEXAREAMARKERSDATADIR)/marker_6.4bpp

$(POKEDEXAREAMARKERSDATADIR)/marker.4bpp: $(POKEDEXAREAMARKERFILES)
	cat $^ > $@
