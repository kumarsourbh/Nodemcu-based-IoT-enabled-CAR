# Nodemcu-based-IoT-enabled-CAR
The Wifi/IoT Controlled Car project demonstrates a wireless, IoT-enabled vehicle that can be operated remotely via an app interface. 
Wifi/IoT Controlled Car
Author: Sourbh Kumar
License: GNU General Public License v3.0
Usage: Open-source, shareable, and reproducible for educational purposes

Project Overview
The Wifi/IoT Controlled Car project demonstrates a wireless, IoT-enabled vehicle that can be operated remotely via an app interface. Using a NodeMCU microcontroller and MIT App Inventor, this project provides a hands-on learning experience in IoT, embedded systems, and mobile app control. This README covers all the technical specifications, component list, setup instructions, and additional resources to help users build and customize their own IoT-controlled car.

Key Features
Real-time Control: Remotely control the car's movements (forward, backward, left, right) through a WiFi connection.
IoT Integration with NodeMCU: Utilizing NodeMCU for efficient and low-power IoT connectivity.
App-Based Interface: A mobile app developed on MIT App Inventor for seamless interaction.
Expandability: Open for modifications, allowing users to add sensors or additional functionality.
Components Required
Component	Quantity	Description
NodeMCU	1	ESP8266-based microcontroller with WiFi capabilities.
L298N Motor Driver	1	Dual H-Bridge motor driver to control DC motors.
DC Motors	2	Motors for driving the wheels, compatible with L298N.
Wheels	4	Wheels compatible with DC motors.
Chassis	1	Chassis to mount all components (metallic or plastic).
Battery Pack	1	Power source for NodeMCU and motors (e.g., 18650 Li-ion cells).
Jumper Wires	1 set	For connecting components on the breadboard.
Slide Switch	1	On/off control for the car’s power source.
LEDs	2 (optional)	Optional for indicators or headlights.
System Architecture
The project is based on a modular architecture, with each module handling a specific functionality of the car.

NodeMCU acts as the main control unit, receiving commands from the mobile app and driving the motors via the L298N Motor Driver.
L298N Motor Driver allows bi-directional control of the DC motors, enabling forward, backward, and turning maneuvers.
Power Management distributes power from the battery pack to the NodeMCU and motors, with options for charging and protection.
Mobile App (MIT App Inventor) serves as the user interface, providing buttons for navigation and LED control (optional).
Circuit Connections
Power Supply

Connect the battery pack to the power input of the L298N motor driver and NodeMCU.
Use a slide switch to control power to the car.
Motor Connections


Connect the DC motors to the L298N motor driver’s output terminals (OUT1, OUT2 for the left motor, OUT3, OUT4 for the right motor).
Ensure proper alignment for forward and backward movements.
NodeMCU to Motor Driver
![wifi car_bb (1)](https://github.com/user-attachments/assets/3e3a1286-ca61-4f9f-9c51-c14508da92c8)


Connect NodeMCU’s GPIO pins to the L298N’s IN1, IN2, IN3, and IN4 for motor direction control.
For PWM speed control, connect NodeMCU’s PWM-capable GPIO pins to ENA and ENB on the L298N.
Optional LED Indicators

Connect LEDs to available GPIO pins for additional control (e.g., headlights, indicators).
Software Development
Mobile App (MIT App Inventor)
The app interface is designed with intuitive controls for each movement direction. Users can adjust the app layout or add more features (e.g., speed control, obstacle detection) in the MIT App Inventor environment.

Features:
Directional Controls: Buttons for forward, backward, left, and right.
Connection Status: Indicator showing WiFi connectivity with NodeMCU.
Speed Adjustment (Optional): Slider to control PWM values for motor speed.
NodeMCU Firmware
The NodeMCU firmware is written in Arduino IDE with the following core functionalities:

WiFi Setup: Connect to a predefined WiFi network or work as a hotspot.
Command Parsing: Interpret commands received over WiFi from the app to control the motors.
GPIO Control: Handle motor direction and speed via the L298N driver.
Installation Instructions
Step 1: Prepare Hardware
Assemble the chassis and mount the components.
Connect all wiring according to the circuit connections section above.
Step 2: Install Arduino IDE Libraries
Install necessary libraries for NodeMCU, such as ESP8266WiFi.h and WiFiClient.h.
Download and configure the L298N motor driver library if needed.
Step 3: Flash NodeMCU
Connect the NodeMCU to your computer via USB.
Upload the firmware (provided in the repository) using Arduino IDE.
Set up WiFi credentials in the code if using a router connection.
Step 4: Test App and Connectivity
Open the MIT App Inventor app on your mobile device.
Ensure the app successfully connects to NodeMCU and controls the car as expected.
Usage
Power On the Car: Toggle the slide switch to power the car.
Connect to WiFi: Ensure the NodeMCU is connected to the WiFi network or mobile hotspot.
Launch App: Open the MIT App Inventor app on your mobile device and connect to the car.
Control Movements: Use the app buttons to navigate the car. Test each direction and speed adjustments (if enabled).
Troubleshooting
Connectivity Issues: Verify WiFi credentials in the NodeMCU code and check for correct IP address.
Motor Issues: Check the L298N connections and ensure adequate power supply.
Battery Life: Use fully charged batteries and avoid over-draining Li-ion cells.
License Information
This project is licensed under the GNU General Public License v3.0. You are free to share, modify, and distribute this project for educational purposes. Please see the LICENSE file for more details.

Contributing
Contributions are welcome! Fork the repository, make improvements, and submit pull requests. Let's enhance this IoT-controlled car project together.

Connect with the Author
For more projects and updates from Sourbh Kumar, follow @Sourbh_Kumar on GitHub.

Enjoy building your Wifi/IoT Controlled Car and dive into the world of connected robotics!
