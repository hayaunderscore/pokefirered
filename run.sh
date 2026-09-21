#!/usr/bin/env bash

compiledb --exclude "^data/" --exclude "^build/" --exclude "^graphics/" make -j8
if [[ -v MODERN ]]; then
	mgba-qt ./pokefirered_modern.gba
else
	mgba-qt ./pokefirered.gba
fi
