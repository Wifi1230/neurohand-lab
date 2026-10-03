# NeuroHand Lab

An educational and research prototype of a neurotechnology interface for controlling a virtual and, eventually, robotic hand.

## Project goal

Build a system that:

1. records muscle activity using EMG;
2. sends data to a computer over USB and later BLE;
3. recognizes simple gestures or muscle activation levels;
4. controls a virtual hand;
5. eventually controls a simple robotic hand mechanism;
6. may later be extended with EEG/BCI.

This is an educational prototype, not a medical device.

## Current hardware

| Component | Purpose | Status |
|---|---|---|
| DFRobot Gravity SEN0240 | EMG signal measurement | Wired |
| Waveshare ESP32-S3-DEV-KIT-N8R8 | ADC reading, processing and BLE | Wired, USB checked |
| 830-point breadboard | Temporary prototyping | In use |
| Dupont wires | Connections between the ESP32, sensor and LED | In use |
| USB-A to USB-C cable | Programming and computer tests | In use |
| 5 mm LEDs | Muscle-activity indicator | GPIO4 blink confirmed |
| 330 ohm resistors | LED current limiting | In the LED circuit |

Servos and hand mechanics will be added only after the EMG part works reliably.

## Roadmap

### Stage 1 — electronics

- [x] Program the ESP32-S3.
- [x] Confirm USB communication.
- [x] Connect an LED through a 330 ohm resistor.
- [x] Confirm LED control.
- [x] Connect the SEN0240.
- [x] Read the analog signal.

### Stage 2 — EMG analysis

- [ ] Record samples to a file.
- [ ] Plot the signal.
- [ ] Measure noise and value range.
- [ ] Add calibration and filtering.
- [ ] Document electrode placement and safety.

### Stage 3 — virtual hand

- [ ] Send EMG data to a computer application.
- [ ] Control hand opening and closing.
- [ ] Add user calibration.
- [ ] Measure latency and stability.

### Stage 4 — wireless communication and classification

- [ ] Send data over BLE.
- [ ] Collect a repeatable labeled dataset.
- [ ] Recognize at least two gestures.
- [ ] Measure accuracy and classification errors.

### Stage 5 — robotic hand

- [ ] Choose a mechanism and actuator.
- [ ] Add a servo or simple gripper.
- [ ] Limit movement range and force.
- [ ] Test safely without wearing the mechanism.

### Stage 6 — possible EEG extension

EEG must use a separate specialized measurement front-end. EEG electrodes must not be connected directly to ESP32 GPIO pins. The ESP32 may later receive and process data from such a module.

## Initial wiring

Confirmed on the bench on 2026-10-03. The Gravity cable colors on this unit are red `+`, black `-`, and blue `A`. The round electrode plug goes only into the SEN0240, never into an ESP32 pin.

```text
SEN0240 +  (red)  -> ESP32-S3 3V3
SEN0240 -  (black) -> ESP32-S3 GND
SEN0240 A  (blue)  -> GPIO1
```

LED, on the left half of the breadboard:

```text
GPIO4 -> row a10 -> 330 ohm from b10 to b15 -> LED long leg in c15
LED short leg in c20 -> row a20 -> blue minus rail
ESP32-S3 GND -> the same lower section of that minus rail
```

The breadboard power rails are split in the middle, so both ground wires have to sit on the same half. `IO4` is the silkscreen name of GPIO4. With the sensor powered and the electrodes off the skin, GPIO1 sits near 1.5 V (about 1700–1800 on the 12-bit ADC). A finger across the three metal pads drives the spread up to about 500.

Check the labels on the actual boards before connecting anything. Do not rely only on wire colors.

## Experiment documentation

Each experiment should record:

- date and code version;
- hardware and wiring;
- objective;
- settings;
- data, plots or photos;
- result and problems;
- conclusion and next step.

## Safety

- Use electrodes only on intact skin.
- Do not place electrodes on the chest or neck.
- Perform initial electrode tests using battery power.
- Do not power servos from the ESP32 3.3 V pin.
- This project is not a certified medical device and must not be used for diagnosis or treatment.

## Status

**Current status:** ESP32-S3, activity LED, and SEN0240 are wired and the analog input responds. Firmware and the live view are still local and are not in this repository yet.

**Next goal:** get a repeatable rest-versus-fist difference from the forearm electrodes.
