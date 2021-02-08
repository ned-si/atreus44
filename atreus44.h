#pragma once

#include "quantum.h"
#define ___ KC_NO

// This a shortcut to help you visually see your layout.
// The first section contains all of the arguments.
// The second converts the arguments into a two-dimensional array.
// In the PCBDOWN case we need to swap the middle two keys: k35 and k36.
#define LAYOUT( \
  k00, k01, k02, k03, k04,           k05, k06, k07, k08, k09, \
  k10, k11, k12, k13, k14,           k15, k16, k17, k18, k19, \
  k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, \
  k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b \
) \
{ \
  { k00, k01, k02, k03, k04, ___, ___, k05, k06, k07, k08, k09 }, \
  { k10, k11, k12, k13, k14, ___, ___, k15, k16, k17, k18, k19 }, \
  { k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b}, \
  { k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b } \
}
