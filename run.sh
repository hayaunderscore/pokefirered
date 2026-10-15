#!/usr/bin/env bash

MODERN=1

compiledb --exclude "^data/" --exclude "^build/" --exclude "^graphics/" make -j8
mgba-qt champrumble.gba
