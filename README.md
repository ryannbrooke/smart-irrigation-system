# smart-irrigation-system

## Overview
An embedded electro-mechanical irrigation system that automatically waters plants based on real-time soil moisture measurements. Built using an ESP32 microcontroller, capacitive soil moisture sensors, and a relay-controlled water pump.

## Features
- Automatic irrigation based on soil moisture
- ESP32 microcontroller
- Capacitive soil moisture sensing
- Relay-controlled 12V pump
- Modular firmware for future expansion
- Designed for future Wi-Fi/IoT integration

## Hardware
- ESP32 Development Board
- Capacitive Soil Moisture Sensor
- 12V Water Pump
- Relay Module
- 12V Power Supply
- 12V to 5V DC-DC Converter
- Tubing and Reservoir
- Component Housing

## Software
- Arduino Framework (ESP32)
- C++

## How it Works
1. Read soil moisture.
2. Compare against a moisture threshold.
3. Activate the pump if the soil is too dry.
4. Water for a short time.
5. Measure again to prevent overwatering.

## Design Decisions
- Capacitive sensors were chosen over resistive sensors to eliminate corrosion.
- Relay switching isolates the low-voltage controller from the pump.
- Time-based watering approximates variable flow control.

## Future Improvements
- Wi-Fi monitoring
- Mobile dashboard
- Multiple irrigation zones
- Weather-based watering
- Data logging

## Author
Ryan Brooke
Simon Fraser University
Mechatronics Systems Engineering
