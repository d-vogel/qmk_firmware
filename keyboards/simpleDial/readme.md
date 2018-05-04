# simpleDial

This is a very simple volume/play-pause dial using a rotary encoder with push-button.
The encoder is integrated in the regular matrix by connecting it in an unusual way.

The encoder used is a generic one from Amazon. The pins on the PCB are identified as follows:
- `VCC`
- `GND`
- `CLK` : quadrature encoder clock signal, pulled-up.
- `DT` : quadrature encoder direction signal, pulled-up.
- `SW` : push switch, unpopulated pull-up footprint.

The wiring of those is well documented. However, they do not integrate well in QMK without implementing custom matrix scanning code.
Using the `GND` pin as column, `CLK`, `DT`, and `SW` as rows, removing the pull-up resistors allows using the regular matrix scanning code.
In this configuration:
- `DT`: associated to a layer switch keyboard.
- `CLK`: sends `KC_VOLD` or `KC_VOLU` depending on the active layer.
- `SW`: sends `KC_MPLY`.

Connection to the arduino pro micro:

| Encoder pin | Arduino pin   | ATmega32u8 pin  |
|:-----------:|:-------------:|:---------------:|
| SW          | 9             | PB5             |
| CLK         | 16            | PB2             |
| DT          | 10            | PB6             |
| VCC         | not connected | not connected   |
| GND         | 8             | PB4             |

Debouncing was disabled, because it interferes with detection.

## Build
The important part is to remove the pull-ups (R1, R2, R3) from the rotary encoder.
![Disassembled view](https://imgur.com/hqzz4dI)

Assembled final prototype, rubber sheet to isolate the two boards.
![Assembled view](https://imgur.com/sfKE3uT)
