# Temperature-Controlled Fan System

**Course:** Introduction to Electronics Projects  
**University:** University of Nevada, Las Vegas  
**Project Type:** Team Electronics / Arduino Project  
**Date:** April 2026  

## Overview

This project is a temperature-controlled fan system built with an Arduino Uno. The goal was to automatically change fan speed based on the surrounding temperature instead of using a manual switch.

A DHT11 temperature sensor measures the room temperature and sends the reading to the Arduino. The Arduino converts the temperature into a PWM value and uses that PWM signal to control the speed of a DC motor. As the temperature rises, the fan speed increases.

## How It Works

1. The DHT11 sensor reads the surrounding air temperature.
2. The Arduino processes the temperature reading.
3. The temperature is mapped to a PWM value from 0 to 255.
4. The Arduino sends the PWM signal through pin 9 to the motor-control circuit.
5. The transistor controls the motor current.
6. The fan spins faster as the temperature rises and slower as the temperature drops.
7. The system updates every two seconds.

### Temperature Control Logic

The project used this temperature range:

| Temperature | PWM / Fan Response |
|---|---|
| Around 23°C | Fan off or slow |
| Between 23°C and 26°C | Fan runs at a moderate speed |
| Around 26°C or higher | Fan runs faster |

The Arduino code maps the 23°C to 26°C range to PWM values from 0 to 255.

## Hardware

- Arduino Uno
- DHT11 temperature sensor
- DC motor with fan
- Transistor / motor driver
- Protection diode
- Resistor
- Breadboard
- Jumper wires
- USB cable for Arduino power and programming

## Circuit Design

The Arduino controls the circuit, but the DC motor is not powered directly from an Arduino output pin because the motor requires more current than the pin can safely provide.

The transistor is used to control the motor current, while the Arduino provides the PWM control signal.

A diode is connected across the motor to help protect the Arduino and the rest of the circuit from voltage spikes caused by back EMF when the motor turns off.

## Software

- Arduino IDE
- DHT sensor library
- Serial Monitor

The DHT11 temperature sensor was connected to digital pin 2.

The motor-control signal was connected to PWM pin 9.

The program reads the temperature, checks that the sensor reading is valid, converts the temperature into a fan-speed value, and sends that value to the motor using `analogWrite()`.

## Testing

The project was tested by monitoring both temperature and fan-speed values in the Arduino Serial Monitor.

The team checked that:

- Temperature readings appeared correctly
- Fan speed values changed between 0 and 255
- The motor responded to changing PWM values
- The fan spun faster when the sensor detected a higher temperature
- The transistor and diode were connected correctly to protect the Arduino

During the demonstration, the DHT11 first detected room temperature and the fan ran at a moderate speed. Hot air was then applied to the sensor, the measured temperature increased, and the fan speed increased.

## Results

The system successfully demonstrated automatic fan-speed control using temperature input.

At lower temperatures, the PWM value was lower and the fan rotated more slowly or stayed off. As the temperature increased, the PWM value increased and the fan spun faster.

## Challenges and Limitations

The DHT11 is a basic temperature sensor and is not as accurate or fast as more advanced sensors.

The selected control range was narrow, from 23°C to 26°C. Temperatures outside this range can make the fan run close to minimum speed or maximum speed.

## Possible Improvements

Future improvements could include:

- Add an LCD screen to display temperature
- Use a smoother or adjustable fan-speed curve
- Use a stronger motor driver
- Add a separate power supply for the fan
- Allow the user to choose the desired temperature range
- Build the final circuit on a cleaner and more permanent board

## Skills Demonstrated

- Arduino programming
- Temperature sensor integration
- PWM motor control
- Breadboard circuit building
- Transistor-based motor control
- Back-EMF protection
- Serial Monitor testing
- Hardware/software troubleshooting
- Engineering documentation
- Teamwork and project presentation

## Team

- Tsukasa Takahashi
- Zihan Chen
- Jeremiah Dacanay
- Mason Cucuru
