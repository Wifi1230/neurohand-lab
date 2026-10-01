\# Initial EMG Prototype Wiring

\*\*Status:\*\* Preliminary. Verify the labels on the physical boards before

powering the circuit.

\## Components

\- Waveshare ESP32-S3-DEV-KIT-N8R8

\- DFRobot Gravity SEN0240

\- 5 mm LED

\- 330 ohm resistor

\- 830-point breadboard

\- Dupont wires

\## Electrical connections

```text

SEN0240 VCC  -> ESP32-S3 3V3

SEN0240 GND  -> ESP32-S3 GND

SEN0240 SIG  -> ESP32-S3 GPIO1 (ADC input)

ESP32-S3 GPIO4 -> 330 ohm resistor -> LED long leg

ESP32-S3 GND  -> LED short leg

Signal flow



electrodes

&#x20;   |

&#x20;   v

SEN0240 amplifier and filter

&#x20;   |

&#x20;   v

ESP32-S3 ADC

&#x20;   |

&#x20;   v

sampling, calibration and filtering

&#x20;   |

&#x20;   v

USB or BLE

&#x20;   |

&#x20;   v

computer and virtual hand

Breadboard notes

Put the ESP32-S3 across the breadboard center gap.

Put LED legs in separate rows.

The resistor must be in series with the LED.

Never connect 3V3 and GND to the same row.

Verify the VCC, GND and SIG labels on the SEN0240.

Do not rely only on wire colors.

Test order

Upload a basic LED blink program.

Confirm USB communication.

Connect SEN0240 VCC, GND and SIG.

Read ADC values over Serial.

Measure the resting signal.

Measure the signal during muscle activation.

Add software-based LED activation.

Initial electrode tests should use battery power. The SEN0240 signal must not be connected to a 5 V ESP32 input.

