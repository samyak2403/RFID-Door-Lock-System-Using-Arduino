/*
 * Copyright (c) 2025 Samyak Kamble
 * GitHub: https://github.com/samyak2403
 * Date: 2025-02-19
 */
#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
#define buzzer 2
#define servoPin 3

String UID = "93 1C CF A9"; // Enter your card or keychain ID
byte lock = 0;

Servo servo;
LiquidCrystal_I2C lcd(0x27, 16, 2);
MFRC522 rfid(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);
  servo.attach(servoPin);
  servo.write(45); // Initial position
  lcd.init();
  lcd.backlight();
  SPI.begin();
  rfid.PCD_Init();
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW); // Ensure buzzer is off initially
}

void loop() {
  lcd.setCursor(4, 0);
  lcd.print("Welcome!");
  lcd.setCursor(1, 1);
  lcd.print("Put your card");

  // Check for a new card
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) {
    return; // If no new card, return to the start of the loop
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Scanning");
  Serial.print("NUID tag is: ");
  String ID = "";
  for (byte i = 0; i < rfid.uid.size; i++) {
    lcd.print(".");
    ID.concat(String(rfid.uid.uidByte[i] < 0x10 ? " 0" : " "));
    ID.concat(String(rfid.uid.uidByte[i], HEX));
    delay(300);
  }
  ID.toUpperCase();

  lcd.clear();
  if (ID.substring(1) == UID) {
    if (lock == 0) {
      // Locking mechanism
      digitalWrite(buzzer, HIGH);
      delay(300);
      digitalWrite(buzzer, LOW);
      servo.write(120); // Move servo to locked position
      lcd.setCursor(0, 0);
      lcd.print("Locked");
      lock = 1;
    } else {
      // Unlocking mechanism
      digitalWrite(buzzer, HIGH);
      delay(300);
      digitalWrite(buzzer, LOW);
      servo.write(45); // Move servo to unlocked position
      lcd.setCursor(0, 0);
      lcd.print("Unlocked");
      lock = 0;
    }
  } else {
    // Wrong card
    lcd.setCursor(0, 0);
    lcd.print("Wrong card!");
    for (int i = 0; i < 4; i++) {
      digitalWrite(buzzer, HIGH);
      delay(200);
      digitalWrite(buzzer, LOW);
      delay(200);
    }
  }
  delay(1500); // Delay to read the message
  lcd.clear();
}