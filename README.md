# atreus44

My QMK keymap for a handwired 44-key Atreus (ATmega32U4, atmel-dfu bootloader,
one rotary encoder for volume).

It is cloned inside my
[qmk-userspace](https://github.com/ned-si/qmk-userspace) checkout, at
`keyboards/handwired/pteron44/keymaps/nedsi` (git-ignored there). The shared code
(layer enum, row macros, custom keycodes, tap dances) lives in qmk-userspace, in
`users/nedsi`.

## Target

Upstream QMK has no Atreus 44 definition, and an External Userspace can only
hold keymaps. This keymap therefore builds on `handwired/pteron44`, which has the
same 4x12 matrix, MCU, bootloader and diode direction. The differences are
carried here:

- `config.h`: matrix pins, encoder pins, USB IDs and names.
- `keymap.c`: `LAYOUT_atreus44`, the physical layout on the 4x12 matrix (no keys
  in the two middle columns of the top two rows).

## Build and flash

From a machine set up as described in the qmk-userspace README:

```sh
qmk compile -kb handwired/pteron44 -km nedsi
qmk flash   -kb handwired/pteron44 -km nedsi
```

Enter the bootloader with `QK_BOOT` (bottom-left key on the NAV layer) or the
reset button, then the CLI flashes it with dfu-programmer.
