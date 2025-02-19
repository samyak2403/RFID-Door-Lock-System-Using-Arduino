/*
 * Copyright (c) 2025 Samyak Kamble
 * GitHub: https://github.com/samyak2403
 * Date: 2025-02-19
 */
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN 9
#define SS_PIN  10

byte readCard[4];
byte a = 0;

LiquidCrystal_I2C lcd(0x27, 16, 2); // Set the LCD address to 0x27 for a 16 chars and 2 line display
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance

void setup() {
  Serial.begin(9600);
  lcd.init();                      // Initialize the LCD
  lcd.backlight();                 // Turn on the backlight
  while (!Serial);                 // Wait for serial connection (for debugging)
  SPI.begin();                     // Init SPI bus
  mfrc522.PCD_Init();              // Init MFRC522
  delay(4);                        // Optional delay for stability
  mfrc522.PCD_DumpVersionToSerial(); // Show details of PCD - MFRC522 Card Reader details
  lcd.setCursor(2, 0);
  lcd.print("Put your card");
}

void loop() {
  // Check if a new card is present
  if (!mfrc522.PICC_IsNewCardPresent()) {
    return; // No card present, exit the loop
  }

  // Try to read the card's UID
  if (!mfrc522.PICC_ReadCardSerial()) {
    return; // Failed to read the card, exit the loop
  }

  // Card read successfully, display the UID
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Scanned UID:");
  a = 0;

  Serial.println(F("Scanned PICC's UID:"));
  for (uint8_t i = 0; i < 4; i++) {
    readCard[i] = mfrc522.uid.uidByte[i];
    Serial.print(readCard[i], HEX);
    Serial.print(" ");

    lcd.setCursor(a, 1);
    lcd.print(readCard[i], HEX);
    lcd.print(" ");
    a += 3; // Move cursor for next byte
  }
  Serial.println("");

  // Halt PICC (stop communication with the card)
  mfrc522.PICC_HaltA();
} this code 100% working yes or no anser only??