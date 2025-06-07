#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize the LCD with I2C address 0x27 and size 16x2
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Define analog pins
const int mq7Pin = A0;
const int mq135Pin = A1;
void setup() {
Serial.begin(9600);
lcd.begin(16, 2); // Specify columns and rows
lcd.backlight(); // Turn on the backlight
lcd.setCursor(0, 0);
lcd.print("MQ-7 & MQ-135");
lcd.setCursor(0, 1);
lcd.print("Initializing...");
delay(2000);
lcd.clear();
}

void loop() {
int mq7Value = analogRead(mq7Pin);
int mq135Value = analogRead(mq135Pin);
// Print to Serial Monitor
Serial.print("MQ-7 Sensor Value: ");
Serial.print(mq7Value);
Serial.print(" | MQ-135 Sensor Value: ");

Serial.println(mq135Value);
// Display on LCD
lcd.setCursor(0, 0);
lcd.print("MQ7: ");
lcd.print(mq7Value);
lcd.print(" "); // Clear leftover chars
lcd.setCursor(0, 1);
lcd.print("MQ135: ");
lcd.print(mq135Value);
lcd.print(" "); // Clear leftover chars
delay(1000);
}

#include <HardwareSerial.h>
#define RXD2 16 // Connect to Uno TX
#define TXD2 17 // Not needed for receiving only
HardwareSerial ArduinoSerial(2); // Using Serial2
void setup() {
Serial.begin(115200);
ArduinoSerial.begin(9600, SERIAL_8N1, RXD2, TXD2); Serial.println("ESP32 ready
to receive data from Arduino...");
}

void loop() {
if (ArduinoSerial.available()) {
String incomingData = ArduinoSerial.readStringUntil('\n');
Serial.print("Received from Arduino: ");
Serial.println(incomingData);
}}
