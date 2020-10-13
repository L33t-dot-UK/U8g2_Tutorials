# FOR USE WITH SB-001, SB-001A OR SB-002 

REFERENCE: https://www.l33t.uk/arduino_projects/mipr/sdk/

# New Features in Version 0.7

- Support for SDK version 1.0.0
- Mode 5 re-factored
- Memory usage optimised freeing up some RAM
- SB001A getDist() function changed to include sensor.dataReady() clause when aquiring readings from the VL53L1X
- Example Python scripts in the Python Examples folder; to get these working install V0.7 on your Arduino and run the scripts. You might need to change the COMM port in the python script

For a list of commands that can be used with the SDK open SDK_Manual.pdf.

# Op Modes

To change the Op Mode open serial monitor and connect to MIPR type a capital O for Oscar and then select the desired Op Mode.
Op Modes are as follows;

- 0; Remote controlled
- 1; Light Seeker
- 2; Light Avoider
- 3; Obstacle avoider
- 4; Follow Mode
- 5; Execute command
- 6; Line Follower Mode; Simple
- 7; Line Follower Mode; Intermediate
- 8; Line Follower Mode; Advanced
- 9; SDK Mode

Modes 1 to 4 work with this code version once SB-001 or SB-001A have been inserted.

# File Breakdown;

- Version_0_6.ino - Main Arduino IDE file, contains setup and loop funcitons for MIPR
- _01_Motor_Functions.ino - Contains functions to access MIPR's motor driver
- _02_Communications.ino - Allows access to MIPR's bluetooth functions
- _03_Odometry_Module.ino - Carries out basic odometry calculaitons
- _04_Sensor_Board_001.ino - Provides functions for light seeking sensor board
- _05_Sensor_Board_001A.ino - Provides functions for obstacle avoidance sensor board
- _06_Line_Follower.ino
- _07_SDK.ino
- _99_TelPacket.ino - Builds the telemetry packet for broadcast via the Bluetooth module and monitors battery voltage
- SDK_Manual.pdf

