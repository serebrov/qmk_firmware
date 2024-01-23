#!/bin/bash

# Connect the keyboard, run this script
# Reset the left part, wait for flash to complete
qmk flash -kb handwired/dactyl_minidox -km via -bl avrdude-split-left

# Connect the right side via USB
# Reset the right side, wait for flash to complete
qmk flash -kb handwired/dactyl_minidox -km via -bl avrdude-split-right
