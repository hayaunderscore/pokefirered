#!/usr/bin/env bash

compiledb --exclude "^data/" --exclude "^build/" --exclude "^graphics/" make -j8
mgba-qt ./pokefirered.gba
