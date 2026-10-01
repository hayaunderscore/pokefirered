@ Morph (transformation) Commands
	@ Change the graphics the object event with `localId` using the transformation method `type` (enum MorphType)
	@ If no `map` is specified, then the current map is used.
	.macro morphobject localId:req, type:req, graphicsId=NUM_OBJ_EVENT_GFX, map
	.ifb \map
		.byte 0xdc
		.byte \localId
		.2byte \graphicsId
		.byte \type
	.else
		.byte 0xdd
		.byte \localId
		.2byte \graphicsId
		.byte \type
		map \map
	.endif
	.endm

	@ instantmorph, mosaicmorph and spinmorph are wrappers around morph object that already specify the transformation type and include a sound effect
	.macro instantmorph localId:req, graphicsId=NUM_OBJ_EVENT_GFX, map
	playse SE_BALL_THROW
	.ifb \map
		morphobject \localId, INSTANT_MORPH, \graphicsId
	.else
		morphobject \localId, INSTANT_MORPH, \graphicsId. \map
	.endif
	.endm

	.macro mosaicmorph localId:req, graphicsId=NUM_OBJ_EVENT_GFX, map
	playse SE_M_TELEPORT
	.ifb \map
		morphobject \localId, MOSAIC_MORPH, \graphicsId
	.else
		morphobject \localId, MOSAIC_MORPH, \graphicsId. \map
	.endif
	.endm

	.macro spinmorph localId:req, graphicsId=NUM_OBJ_EVENT_GFX, map
	playse SE_ROTATING_GATE
	.ifb \map
		morphobject \localId, SPIN_MORPH, \graphicsId
	.else
		morphobject \localId, SPIN_MORPH, \graphicsId. \map
	.endif
	.endm
