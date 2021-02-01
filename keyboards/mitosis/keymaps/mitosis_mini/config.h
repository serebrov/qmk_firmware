#pragma once

// I set shorter TAPPING_TERM to have it the same as autoshift timeout.
// This way u / U / : / ; (tap-dance) has the same delay to produce U
// as AutoShift (and tap dance relies on TAPPING_TERM to decide on hold state).
// Negative effcts are:
// - It is harder to use GUI/Enter: I should hit Enter faster to aviod triggering
// GUI. This could be solved with RETRO_TAPPING enabled.
// - It is harder to use OSM Ctrl: looks like I usually hold it for longer time than
// 125ms
// - It is harder to use spaces (as they are also Mod-Taps), should also be solved
// with RETRO_TAPPING
// Anyway, it could either get used to this or enable RETRO_TAPPING.
#define TAPPING_TERM 125
#define RETRO_TAPPING

#define AUTO_SHIFT_TIMEOUT 125

// #define COMBO_COUNT 1
// #define COMBO_TERM 50

// https://beta.docs.qmk.fm/using-qmk/software-features/tap_hold#tapping-force-hold
//
// TLDR: tap force hold is good to have OFF (default) when dual-function keys are used,
// allows to still get autorepeat for letters.
// With AutoShift, it is OK to disable and it solves a problem of getting space repeated in
// situations where I don't want/expect that (because I use left space hold to get right space
// to be backpace).
//
// Problem: sometimes backspace doesn't work and while holding the left space,
// the right one still produces spaces
//
// It looks like this is a behavior controlled by the Tapping Force Hold setting
// >  By default, when holding a dual-function key shortly after tapping it,
// > the tapped key will begin repeating. This is handy for fast typists when 
// > typing words with double letters, such as "happy". If you turn this setting ON,
// > it will be counted as a held modifier instead. Note: enabling this will 
// > override any tap toggle behavior such as One Shot Tap Toggle
//
// I don't have now dual-function modifiers on any of the letters,
// so it should not affect anything (maybe only wired behaviors with modifiers
// locking when I am holding for too long, which should be what One Shot Tap Toggle does)
//
// Note: without auto-shift, the tapping force hold OFF was good,
// I remember using it on J where I can either hold to get Shift or tap+tap-and-hold
// to get J repeated. With auto-shift that doesn't work anyway,
// as holding produces capital J and holding for a longer time does nothing.
//
#define TAPPING_FORCE_HOLD
