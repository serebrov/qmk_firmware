/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
Copyright 2021 @dlford
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

// https://www.stlfinder.com/model/dactyl-36-key-minidox-EZsvbKhP/4318876/
// https://blog.jfedor.org/2020/11/dactyl-manuform-build-log.html
// https://github.com/jfedor2/qmk_firmware

#pragma once

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
// #undef LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
// #undef LOCKING_RESYNC_ENABLE

/* Enables This makes it easier for fast typists to use dual-function keys */
#undef PERMISSIVE_HOLD

// For some reason I had to change this parameter
// Note: the original change is in the ../../info.json
#define DIODE_DIRECTION COL2ROW

// #define RGB_DI_PIN D3
// #define RGBLED_NUM 12

// Without this there is no communication via TRRS, left half works,
// but the right half doesn't (if not connected via a second USB cable).
#define SPLIT_USB_DETECT

#define USE_SERIAL

// Auto-detect master half, flash in two steps
// Connect the left side via USB, reset when prompted
// qmk flash -kb handwired/dactyl_minidox -km via -bl avrdude-split-left
// Connect the right side via USB
// Reset the right side, wait for flash to complete
// qmk flash -kb handwired/dactyl_minidox -km via -bl avrdude-split-right
#define EE_HANDS
//#define MASTER_LEFT
