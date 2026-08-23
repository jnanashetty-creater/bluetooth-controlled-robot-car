# Bluetooth-Controlled Robot Car

A 4-wheeled robotic car controlled wirelessly via a Bluetooth-connected mobile app, built as part of a two-week internship (June 2023 – Dec 2023) at NMAM Institute of Technology, Nitte.

## Overview

The car uses an Arduino UNO as its main controller, receiving directional commands (forward, backward, left, right, stop) from a mobile app over a Bluetooth serial link. Motor speed and direction are controlled via an L298N dual H-bridge motor driver, with PWM used for speed regulation.

## Hardware Used

- Arduino UNO (ATmega328P)
- HC-05 Bluetooth module (up to ~10m range, master/slave modes)
- L298N motor driver (dual H-bridge, controls 4 DC motors in a skid-steer configuration)
- Lithium-ion battery
- 4-wheeled chassis with DC motors

## How It Works

- The HC-05 module is wired to the Arduino's RX/TX pins for serial communication.
- The mobile app sends single-character commands (`A` = forward, `B` = backward, `C` = right, `D` = left, `S` = stop) over Bluetooth.
- The Arduino reads incoming characters and triggers the corresponding motor direction via `digitalWrite` on the L298N's input pins.
- Motor speed is set using `analogWrite` (PWM) at a duty cycle of ~27% (value 70/255), adjustable in code.
- The same command logic also works over the USB serial connection for debugging.

## Code

See [`bluetooth_robot_car.ino`](./bluetooth_robot_car.ino) for the full Arduino sketch.

## Future Improvements

- Add a GPS module for location tracking
- Add ultrasonic/LiDAR sensors for basic obstacle detection
- Add a robotic arm attachment for task automation
- Integrate a Raspberry Pi for onboard ML-based control

## Reference

Umar, A. et al. *Development of an Android-Based, Voice-Controlled Autonomous Robotic Vehicle.* Eng. Proc. 2023, 58, 48.
