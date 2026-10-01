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
| DFRobot Gravity SEN0240 | EMG signal measurement | Ordered |
| Waveshare ESP32-S3-DEV-KIT-N8R8 | ADC reading, processing and BLE | Ordered |
| 830-point breadboard | Temporary prototyping | Ordered |
| Dupont wires | Connections between the ESP32, sensor and LED | Ordered |
| USB-A to USB-C cable | Programming and computer tests | Ordered |
| 5 mm LEDs | Muscle-activity indicator | Ordered |
| 330 ohm resistors | LED current limiting | Ordered |

Servos and hand mechanics will be added only after the EMG part works reliably.

## Roadmap

### Stage 1 — electronics

- [ ] Program the ESP32-S3.
- [ ] Confirm USB communication.
- [ ] Connect an LED through a 330 ohm resistor.
- [ ] Confirm LED control.
- [ ] Connect the SEN0240.
- [ ] Read the analog signal.

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

```text
SEN0240 VCC  -> ESP32-S3 3V3
SEN0240 GND  -> ESP32-S3 GND
SEN0240 SIG  -> ADC input, for example GPIO1
```

LED:

```text
GPIO4 -> 330 ohm resistor -> LED long leg
LED short leg -> GND
```

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

**Current status:** preparing the first EMG prototype.

**Next goal:** bring up the ESP32-S3, LED and SEN0240 signal reading.
