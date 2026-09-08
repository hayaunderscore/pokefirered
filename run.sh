#!/usr/bin/env bash

compiledb -n --exclude "^data/" --exclude "^build/" --exclude "^graphics/" make -j8
mgba-qt ./pokefirered.gba
