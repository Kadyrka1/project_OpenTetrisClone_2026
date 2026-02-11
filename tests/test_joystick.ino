//--------------------------------
//-----------LIBRARIES------------
//--------------------------------
#include <EEPROM.h>
#define EEPROM_SIZE 512  // Define EEPROM size for ESP32
#include <Adafruit_NeoPixel.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>


// Define pin numbers for joystick directions
const int UP_PIN = 14;
const int DOWN_PIN = 27;
const int LEFT_PIN = 16;
const int RIGHT_PIN = 17;

const int debounce_delay = 250;

LiquidCrystal_I2C lcd(0x27, 20, 4); //4x20

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Configure pins as INPUT_PULLUP
  pinMode(UP_PIN, INPUT_PULLUP);
  pinMode(DOWN_PIN, INPUT_PULLUP);
  pinMode(LEFT_PIN, INPUT_PULLUP);
  pinMode(RIGHT_PIN, INPUT_PULLUP);
  
  Serial.println("4-Direction Joystick Ready!");

  //----LCD-------
  //LCD initialize
  lcd.init();
  lcd.backlight();

  lcd.setCursor(3,0);
  lcd.print("Hello, world!");

}

void loop() {
  // Read joystick directions (LOW = pressed, HIGH = not pressed)
  bool upPressed = (digitalRead(UP_PIN) == LOW);
  bool downPressed = (digitalRead(DOWN_PIN) == LOW);
  bool leftPressed = (digitalRead(LEFT_PIN) == LOW);
  bool rightPressed = (digitalRead(RIGHT_PIN) == LOW);
  
  // Print direction when pressed
  if (upPressed) {
    Serial.println("UP");
  }
  if (downPressed) {
    Serial.println("DOWN");
  }
  if (leftPressed) {
    Serial.println("LEFT");
  }
  if (rightPressed) {
    Serial.println("RIGHT");
  }
  
  // Small delay to debounce and reduce serial output
  delay(debounce_delay);

  //LCD
  lcd.setCursor(2,1);
  lcd.print("Ywrobot Arduino!");
  lcd.setCursor(0,2);
  lcd.print("Arduino LCM IIC 2004");
  lcd.setCursor(2,3);
  lcd.print("Power By Ec-yuan!");
  
}
