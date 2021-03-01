#!/bin/bash

# See https://beta.docs.qmk.fm/developing-qmk/qmk-reference/config_options#setting-handedness
#
# I use avrdude-split-left to explicitly set the pro micro part to be left
# and elite-c to be right (in ./qmk-flash-microdox-elite-c.sh)
# Otherwise they are mirrored (right half produces qwert and left - yuiop)
qmk flash -kb kyria/rev1 -km kyria-mini -bl avrdude-split-right
