#pragma once

// Handwired Atreus 44, built on handwired/pteron44: same 4x12 matrix size,
// MCU, bootloader and diode direction, different wiring.

#undef VENDOR_ID
#undef PRODUCT_ID
#undef DEVICE_VER
#undef MANUFACTURER
#undef PRODUCT
#define VENDOR_ID 0x1209
#define PRODUCT_ID 0xA1E5
#define DEVICE_VER 0x0008
#define MANUFACTURER "Ziv"
#define PRODUCT "Atreus44"

#undef MATRIX_ROW_PINS
#undef MATRIX_COL_PINS
#define MATRIX_ROW_PINS { F4, F5, F6, F7 }
#define MATRIX_COL_PINS { B1, B3, B2, B6, B5, B4, E6, D7, C6, D4, D0, D1 }

#define ENCODER_A_PINS { D2 }
#define ENCODER_B_PINS { D3 }
#define ENCODER_DIRECTION_FLIP
#define ENCODER_RESOLUTION 2
