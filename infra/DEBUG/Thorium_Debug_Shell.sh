#!/bin/bash

# Copyright (c) 2022 Alex313031.

LD_LIBRARY_PATH="$(pwd)/lib"
export LD_LIBRARY_PATH

./thorium_debug_shell --debug
