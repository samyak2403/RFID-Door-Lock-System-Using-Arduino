# RFID-Door-Lock-System-Using-Arduino
# RFID-Based Locking System

This project implements an RFID-based locking system using an Arduino, an MFRC522 RFID module, a servo motor, and an LCD display. The system locks and unlocks based on the scanned RFID card or tag. If the correct card is scanned, the servo motor changes position to simulate locking or unlocking. If an incorrect card is scanned, the system provides feedback via a buzzer and an LCD message.

## Components Used
- Arduino Uno (or compatible)
- MFRC522 RFID Module
- Servo Motor
- 16x2 I2C LCD Display
- Buzzer
- Jumper Wires
- Breadboard (optional)

## Wiring Diagram
| Arduino Pin | Component Pin |
|-------------|---------------|
| 3           | Servo Signal  |
| 9           | MFRC522 RST   |
| 10          | MFRC522 SS    |
| SDA (A4)    | I2C LCD SDA   |
| SCL (A5)    | I2C LCD SCL   |
| 2           | Buzzer (+)    |
| GND         | Buzzer (-), Servo GND, MFRC522 GND, LCD GND |
| 5V          | Servo VCC, MFRC522 3.3V, LCD VCC |

**Note**: The MFRC522 module operates at 3.3V, so ensure you do not connect it to 5V directly.

## Setup Instructions
1. **Hardware Setup**:
   - Connect the components as per the wiring diagram.
   - Ensure the RFID module is properly connected to the Arduino's SPI pins.
   - Connect the I2C LCD display to the Arduino's I2C pins (SDA and SCL).

2. **Software Setup**:
   - Install the required libraries:
     - `Servo.h` (included with Arduino IDE)
     - `LiquidCrystal_I2C.h` (for I2C LCD)
     - `MFRC522.h` (for RFID module)
   - Upload the provided Arduino code to your board.

3. **Configure RFID UID**:
   - Replace the `UID` variable in the code with the UID of your RFID card or tag.
   - To find the UID of your card, upload the code, open the Serial Monitor, and scan your card. The UID will be displayed in the Serial Monitor.

4. **Test the System**:
   - Power on the Arduino.
   - Place the correct RFID card near the RFID module. The servo should move to the "locked" position, and the LCD should display "Locked".
   - Scan the card again to unlock the system. The servo should return to the "unlocked" position, and the LCD should display "Unlocked".
   - If an incorrect card is scanned, the buzzer will beep, and the LCD will display "Wrong card!".

## Code Overview
The Arduino code performs the following tasks:
- Initializes the servo, LCD, RFID module, and buzzer.
- Continuously checks for an RFID card.
- Compares the scanned card's UID with the predefined UID.
- Locks or unlocks the system based on the card's UID.
- Provides feedback via the LCD and buzzer.

## Libraries Used
- `Servo.h`: For controlling the servo motor.
- `LiquidCrystal_I2C.h`: For interfacing with the I2C LCD display.
- `MFRC522.h`: For communicating with the MFRC522 RFID module.

## Troubleshooting
- **RFID Module Not Detecting Cards**:
  - Ensure the wiring is correct.
  - Check if the RFID module is powered with 3.3V.
  - Move the card closer to the RFID module.
- **LCD Not Displaying Anything**:
  - Verify the I2C address of the LCD (default is `0x27`).
  - Check the wiring for SDA and SCL.
- **Servo Not Moving**:
  - Ensure the servo is connected to the correct pin (Pin 3).
  - Check the power supply to the servo.

## Future Enhancements
- Add multiple authorized RFID cards.
- Implement a keypad for manual unlocking.
- Integrate a Wi-Fi module for remote monitoring and control.

## License
This project is open-source and available under the MIT License. Feel free to modify and distribute it as needed.

## Author
[Your Name]  
[Your GitHub Profile]  
[Your Email]  
