/*
Copyright 2017 Danny Nguyen <danny@hexwire.com>

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

#pragma once

#undef RGBLED_NUM
#undef RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 12

#undef RGBLIGHT_HUE_STEP
#undef RGBLIGHT_SAT_STEP
#undef RGBLIGHT_VAL_STEP

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_TERM 250

