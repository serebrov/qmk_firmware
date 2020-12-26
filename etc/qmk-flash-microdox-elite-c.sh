#!/bin/bash

# See https://beta.docs.qmk.fm/developing-qmk/qmk-reference/config_options#setting-handedness
#
# I use dfu-split-right to explicitly set the elite-c part to be right
# and pro-micro to be left (in ./qmk-flash-microdox-pro-micro.sh)
# Otherwise they are mirrored (right half produces qwert and left - yuiop)
qmk flash -kb boardsource/microdox -km cole -bl dfu-split-right
