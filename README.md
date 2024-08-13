# IR Remote Control for Home Appliances

This project allows you to control various home appliances like a fan, lights, and a bulb using an infrared (IR) remote. The project is implemented using an Arduino and the `IRremote` library.

## Table of Contents

- [Hardware Requirements](#hardware-requirements)
- [Software Requirements](#software-requirements)
- [Circuit Diagram](#circuit-diagram)
- [How It Works](#how-it-works)
- [Code Explanation](#code-explanation)
- [Usage](#usage)
- [Troubleshooting](#troubleshooting)
- [License](#license)

## Hardware Requirements

- Arduino (Uno, Nano, etc.)
- IR Receiver (e.g., TSOP1738)
- IR Remote
- Relay Module (optional, for high-power appliances)
- Jumper wires
- Breadboard
- 4 LEDs (or actual appliances connected via relays)
- 4 Resistors (220Ω) for LEDs
- Power supply for the Arduino

## Software Requirements

- Arduino IDE
- IRremote Library for Arduino

## Circuit Diagram

Connect the components as follows:

- **IR Receiver**:  
  - Signal pin -> Pin 11 of Arduino  
  - VCC pin -> 5V of Arduino  
  - GND pin -> GND of Arduino
- **Appliances (LEDs)**:  
  - Fan -> Pin 9 (purple wire)  
  - Light 1 -> Pin 10 (green wire)  
  - Light 2 -> Pin 8 (blue wire)  
  - Bulb -> Pin 12 (yellow wire)  
  - The other terminal of each appliance should be connected to the GND.

## How It Works

The IR receiver captures signals from the IR remote and sends them to the Arduino. The Arduino then decodes the received signal and controls the connected appliances based on the decoded values.

### Button Mappings:

- **Fan**: Toggles ON/OFF with `fanButton` (`0xBB44FB04`).
- **Light 1**: Toggles ON/OFF with `lightButton1` (`0xEE11FB04`).
- **Light 2**: Toggles ON/OFF with `lightButton2` (`0xED12FB04`).
- **Light 3**: Toggles both Light 1 and Light 2 simultaneously with `lightButton3` (`0xEC13FB04`).
- **Bulb**: Toggles ON/OFF with `bulbButton` (`0xF00FFB04`).
- **Power**: Toggles all appliances ON/OFF with `power` (`0xF708FB04`).

## Code Explanation

- **Component State Management**:  
  An array `componentState[]` stores the state (ON/OFF) of each appliance.
  
- **Button Codes**:  
  Each button on the IR remote is assigned a specific hexadecimal code (e.g., `fanButton`, `lightButton1`).

- **Main Logic**:  
  The `loop()` function continuously checks for signals from the IR remote. When a valid signal is detected, the corresponding appliance is toggled between ON and OFF states.

## Usage

1. **Setup**: Connect the components as per the circuit diagram and upload the provided code to your Arduino board.
2. **Control**: Use the designated buttons on your IR remote to control the fan, lights, and bulb.
3. **Monitor**: You can uncomment the `Serial.print` statements in the code for debugging and to monitor the state of the appliances.

## Troubleshooting

- **No Response**: Ensure that the IR receiver is properly connected to the Arduino. Check the signal pin connection.
- **Wrong Appliance Controlled**: Verify the hex codes for your remote buttons using a serial monitor or IR decoder tool.
- **Appliance Not Turning Off/On**: Double-check the wiring and ensure the correct digital pins are used in the code.

## License

This project is open-source under the MIT License.