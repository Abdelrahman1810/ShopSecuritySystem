# Shop Security System

This is an Arduino project that uses the MFRC522 RFID reader module, PIR motion sensor, magnetic door sensor, 2 buzzers and an LCD screen to create a shop security system. When the system detects an unauthorized access, it triggers the alarm system, sounds two buzzers, and displays a warning message on the LCD screen. The alarm will continue to sound until an authorized RFID card is presented to the RFID reader module.

## Requirements

- Arduino Uno or any compatible board
- MFRC522 RFID reader module
- PIR motion sensor
- Magnetic door sensor
- 2 buzzers
- 16x2 LCD screen (I2C e.g.)
- green LEDC
- Breadboard
- Jumper wires

## Connection

Here's how you can connect the components:

- RFID reader module:
  - SDA pin to Arduino digital pin 10
  - SCK pin to Arduino digital pin 13
  - MOSI pin to Arduino digital pin 11
  - MISO pin to Arduino digital pin 12
  - IRQ not connected
  - GND pin to Arduino GND
  - RST pin to Arduino digital pin 9
  - 3.3V pin to Arduino 3.3V
  - **<a href="https://drive.google.com/file/d/1OyuJ8RzonVSR99zM1e_ZwtWLNcS6UJgV/view">See How</a>**
    > **Note** this image belong to other people I use it to make connection more clear, many thanks to them
   

- PIR motion sensor:
  - OUT pin to Arduino digital pin 8
  - VCC pin to Arduino 5V
  - GND pin to Arduino GND
  - **<a href="https://www.circuits-diy.com/wp-content/uploads/2021/09/Interfacing-HC-SR501-PIR-Motion-Sensor-with-Arduino-UNO.jpg">See How</a>**
    > **Note** this image belong to other people I use it to make connection more clear, many thanks to them

- Magnetic door sensor:
  - One leg to Arduino digital pin 7
  - Other leg to Arduino GND
  - A pull-up resistor (~10k ohm) between the digital pin 7 and 5V is required.
  - **<a href="https://johnny-five.readthedocs.io/en/latest/breadboard/switch-magnetic-door.png">See How</a>**
    > **Note** this image belong to other people I use it to make connection more clear, many thanks to them

- Buzzers:
  - Positive leg to Arduino digital pins 2 and 3
  - Negative leg to Arduino GND

- LED:
    - Short leg to GND
    - other leg to Arduino digital pin 4

- LCD screen:
  - SDA pin to Arduino analog pin A4
  - SCL pin to Arduino analog pin A5
  - VCC pin to Arduino 5V
  - GND pin to Arduino GND
  - **<a href="https://www.makerguides.com/wp-content/uploads/2019/02/I2C-LCD-with-Arduino-Wiring-Diagram-Schematic-Pinout.jpg">See How</a>**
    > **Note** this image belong to other people I use it to make connection more clear, many thanks to them

## Libraries

This project uses the following libraries:
- <a href="https://github.com/miguelbalboa/rfid">MFRC522</a> library GithubCommunity
- <a href="https://github.com/johnrickman/LiquidCrystal_I2C">LiquidCrystal_12C</a> library by Frank de Brabander


## Usage

1. Upload the code to your Arduino board.
2. Connect the components according to the connection diagram.
3. Power up your Arduino board.
4. Present an authorized RFID card to the RFID reader module to arm the system.
5. Test the system by triggering the PIR motion sensor or opening the magnetic door sensor.
6. Present an authorized RFID card to the RFID reader module to disarm the system.

## Customization

You can customize the code to add or remove authorized RFID card IDs. You can also customize the warning messages displayed on the LCD screen and the duration and pattern of the buzzer alarm.

**Note**: When modifying the code, make sure to test the system thoroughly to ensure its reliability and security.

## Contact

If you have any questions or comments about this project, please feel free to contact me at 

<a href="http://wa.me/201061075354" target="_blank"><img alt="LinkedIn" src="https://img.shields.io/badge/whatsapp-128C7E.svg?style=for-the-badge&logo=whatsapp&logoColor=white" /></a> 

<a href="https://www.linkedin.com/in/abdelrahman-mohammed-814a9022a/" target="_blank"><img alt="LinkedIn" src="https://img.shields.io/badge/linkedin-0077b5.svg?style=for-the-badge&logo=linkedin&logoColor=white" /></a>

Gmail : abdelrahmansalby23@gmail.com 📫