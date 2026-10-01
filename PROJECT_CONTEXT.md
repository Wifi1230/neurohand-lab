# NeuroHand Lab — context for another AI

## Project state

Repository: `https://github.com/Wifi1230/neurohand-lab.git`

Main branch: `main`

Current files:

```text
README.md
PROJECT_CONTEXT.md
```

There is no firmware, desktop application or schematic file yet. Hardware has been ordered, but wiring should begin only after delivery and after checking the pin labels on the actual boards.

The last local commits are:

```text
8aed406 Add project handoff context
d88763e Add NeuroHand project documentation
```

Push from the cloud environment to GitHub failed because HTTPS authentication is not configured. Do not claim that GitHub contains these commits until `git push` succeeds.

## Vision

The project is an evolving neurotechnology prototype:

```text
EMG -> ESP32-S3 -> USB/BLE -> computer -> virtual hand
                                           |
                                           +-> later: servos/gripper
```

EEG/BCI may be added later. EEG requires a separate specialized measurement front-end; EEG electrodes must never be connected directly to ESP32 GPIO pins.

## Ordered hardware

- DFRobot Gravity SEN0240: single-channel analog EMG module with electrodes, amplifier and filtering.
- Waveshare ESP32-S3-DEV-KIT-N8R8: ESP32-S3-WROOM-1-N8R8, USB-C, soldered headers, Wi-Fi, BLE, 8 MB Flash and 8 MB PSRAM.
- 830-point breadboard.
- Dupont wire set: male-male, female-female and male-female.
- USB-A to USB-C data cable.
- 5 mm LEDs.
- 330 ohm resistors.

Servos, a battery, a power bank and hand mechanics have not been ordered. They are not needed for the first stage.

## First bring-up plan

1. Install Arduino IDE or PlatformIO.
2. Add Espressif board support.
3. Select `ESP32S3 Dev Module` or the matching Waveshare board definition.
4. Connect the ESP32-S3 over USB-C.
5. Upload a simple LED test.
6. Connect the SEN0240:

```text
SEN0240 VCC -> ESP32-S3 3V3
SEN0240 GND -> ESP32-S3 GND
SEN0240 SIG -> ADC input, for example GPIO1
```

7. Read ADC values and send them over Serial.
8. Measure the resting level and response to muscle activation.
9. Build the virtual-hand application only after the signal is stable.

Check the labels on the actual module before wiring. Do not trust wire colors alone.

## LED test

```text
ESP32-S3 GPIO4 -> 330 ohm resistor -> LED long leg
LED short leg -> GND
```

The LED should be controlled in software from the EMG reading. Do not connect it directly to the sensor SIG output.

## Technical constraints

- One SEN0240 does not provide enough spatial information for many reliable gestures. The initial goal is rest/activation or one simple movement.
- AI cannot recover information that was not measured. More gestures will require additional EMG channels and new training data.
- ESP32-S3 ADC pin mapping differs from the classic ESP32-WROOM-32. GPIO34 belongs to the classic ESP32 examples and must not be reused blindly on the S3.
- BLE is sufficient for EMG samples. USB is simpler for the first programming and debugging stage.
- Servos require a separate power supply. Never power servos from the ESP32 3.3 V pin.

## Suggested future directories

```text
src/firmware/
src/desktop/
data/raw/
data/processed/
docs/experiments/
docs/schematics/
media/
```

Do not commit passwords, tokens or private personal data.

## Experiment records

Every experiment should include:

- date;
- code version or commit hash;
- hardware and wiring;
- objective;
- data and plots;
- result;
- problems;
- decision about the next step.

## Safety

- Use electrodes only on intact skin.
- Do not place electrodes on the chest or neck.
- Perform initial measurements using battery power.
- This is not a medical device and must not be used for diagnosis.
- Test physical mechanisms without wearing them first.
