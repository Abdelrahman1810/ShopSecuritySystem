#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#define SS_PIN 10
#define RST_PIN 9
#define PIR 8
#define MagneticDoor 7

int i, j;
const int buzzer[] = { 2, 3 };
int status = 4;
bool isSafe = 0;
bool isPIRDetect = 0;
bool isDoorOpend = 0;

void lcdStatus();
void C522Sensor();
void alarmSystem();

MFRC522 rfid(SS_PIN, RST_PIN);
LiquidCrystal_I2C lcd(0x27,20,4);

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();

  pinMode(buzzer[0], OUTPUT);
  pinMode(buzzer[1], OUTPUT);
  pinMode(status, OUTPUT);

  pinMode(PIR, INPUT);
  pinMode(MagneticDoor, INPUT_PULLUP);

  lcd.begin(16, 2);
  lcd.backlight();
}

void loop() {

  C522Sensor();
  isPIRDetect = digitalRead(PIR);
  isDoorOpend = digitalRead(MagneticDoor);
  lcdStatus();
  digitalWrite(status, isSafe);

  if(isSafe)
  {
    alarmSystem(false);
  }
  else if(isPIRDetect || isDoorOpend)
  {
    while (!isSafe)
    {
      alarmSystem(true);
    }
  }
}

void C522Sensor() 
{
  if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial())
  {
    lcd.clear();
    lcd.setCursor(0,0);
    String UID = "";  // user ID
    for (byte i = 0; i < 4; i++) {
      UID.concat(String(rfid.uid.uidByte[i] < 0x10 ? " 0" : " "));
      UID.concat(String(rfid.uid.uidByte[i], HEX));
    }
    UID.toUpperCase();
    
    if (UID.substring(1) == "33 86 21 90") // you can change and add ids depending on how many Serisl you hsve
    {

      if(isDoorOpend && isSafe)
      {
        lcd.print("Close the door");
        delay(1500);
        lcd.clear();
      }
      else
      {
        Serial.println("Authorized Access");
        isSafe = !isSafe;
      }
    }
    else
    {
      lcd.clear();
      lcd.print("Access denied");
      delay(1500);
      lcd.clear();
    }
          

    rfid.PICC_HaltA();
    rfid.PCD_StopCrypto1();
  }
}

void alarmSystem(bool on) 
{
  C522Sensor();
  lcdStatus();
  if(on)
  {
    for (i = 0; i < 2; i++) {
      for (j = 0; j < 2; j++) {
        digitalWrite(buzzer[j], LOW);
      }
      delay(200);
      digitalWrite(buzzer[i], HIGH);
      delay(200);
    }
  }
  else
  {
    for (j = 0; j < 2; j++)
    {
      digitalWrite(buzzer[j], LOW);
    }
  }
}

void lcdStatus()
{
  
  if(isSafe)
  {
    lcd.setCursor(1,0);
    lcd.print("status: OPEN");
  }
  else
  {
    if(isPIRDetect || isDoorOpend)
    {
      lcd.clear();
      lcd.setCursor(4,0);
      lcd.print("NOT ALLOWED");
      lcd.setCursor(4,1);
      lcd.print("INTRUDER");
    }
    else
    {
      lcd.setCursor(1,0);
      lcd.print("status: CLOSED");
      lcd.setCursor(1,1);
      lcd.print("Scan ID");
    }
  }
}
