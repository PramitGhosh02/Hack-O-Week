# Forklift Ultrasonic Pedestrian Safety System

This repository contains the firmware and simulation configuration for an Arduino-based safety system designed specifically for forklifts. 

## Features
- **Proximity Detection:** Uses an HC-SR04 ultrasonic sensor to detect objects or pedestrians in the forklift's path.
- **Automatic Cutoff:** Immediately stops the primary motor if an object comes within 2 meters (200 cm).
- **Audio Warning:** Activates a piezo buzzer alarm when an object is dangerously close to warn the pedestrian.

## Repository Contents
1. `forklift_safety.ino`: The main Arduino sketch containing the hardware control and safety logic.
2. `diagram.json`: The hardware connection layout mapped out for the Wokwi simulator. 

## How to Simulate
This project is configured and ready to be test-driven using the [Wokwi Simulator](https://wokwi.com). 
If you use VS Code, simply install the `Wokwi Simulator` extension, open this folder, and start the simulation to see it in action! 

## Hardware Wiring Guide
- **Sensor TRIG:** Pin 9
- **Sensor ECHO:** Pin 10
- **Piezo Buzzer:** Pin 11
- **Motor Control/Relay:** Pin 12
