#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal.h>
#include <Servo.h>

#define RST_PIN 9
#define SS_PIN 10
#define RED_LED A0
#define GREEN_LED A1

byte readCard[4];
char* myTags[100] = {};
int tagsCount = 0;
String tagID = "";
boolean successRead = false;
boolean correctTag = false;
boolean doorOpened = false;

//Create instances
MFRC522 mfrc522(SS_PIN, RST_PIN);
LiquidCrystal lcd(2, 3, 4, 5, 6, 7); //Parameters (rs, enable, d4, d5, d6, d7)
Servo myServo; //Servo Motor


//Define the custom functions
uint8_t getID() {
  //Getting ready for reading PICCs
  if ( !mfrc522.PICC_IsNewCardPresent()) {
    return 0; //else go on with the rest of the code
  }

  if (!mfrc522.PICC_ReadCardSerial()) {
    return 0; //Get Serial and continue
  }

  tagID = "";
  for (uint8_t i = 0; i < 4; i++) {
    readCard[i] = mfrc522.uid.uidByte[i];
    tagID.concat(String(mfrc522.uid.uidByte[i], HEX)); //Add the 4 bytes in a single String variable
  }
  tagID.toUpperCase();
  mfrc522.PICC_HaltA();
  return 1;
}

void printNormalModeMessage() {
  delay(1500);
  lcd.clear();
  lcd.print("Access Control");
  lcd.setCursor(0, 1);
  lcd.print("Scan Your Tag!");
}


void setup() {
  SPI.begin();
  mfrc522.PCD_Init();
  lcd.begin(16, 2);
  myServo. attach(8); //Set the d8 as servo input

  myServo.write(50); //Initial Position 50 degrees for servo motor

  //Setup Lights
  analogWrite(GREEN_LED, 0);
  analogWrite(RED_LED, 0);

  //Print the inital message
  lcd.print("No Master Tag!");
  lcd.setCursor(0, 1);
  lcd.print("   Scan Now!");
  //wait until master tag is scanned
  while (!successRead) {
    successRead = getID();
    if (successRead == true) {
      myTags[tagsCount] = strdup(tagID.c_str()); //Sets the master tag into position 0 in myTags Array
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Master Tag Set!");
      tagsCount++;
    }
  }
  successRead = false;
  printNormalModeMessage();
}

void loop() {

  if (!doorOpened) {
    //Check for a tag
    if ( ! mfrc522.PICC_IsNewCardPresent()) { //If a new PICC placed to RFID reader continue
      return;
    }
    if ( ! mfrc522.PICC_ReadCardSerial()) {   //Since a PICC placed get Serial and continue
      return;
    }

    tagID = "";

    for (uint8_t i = 0; i < 4; i++) {
      readCard[i] = mfrc522.uid.uidByte[i];
      tagID.concat(String(readCard[i], HEX));
    }
    tagID.toUpperCase();
    mfrc522.PICC_HaltA(); //Stop Reading

    correctTag = false;

    //Check whether the tag entered is the master Tag
    if (tagID == myTags[0]) {
      lcd.clear();
      lcd.print("Developer Mode");
      lcd.setCursor(0, 1);
      lcd.print("Add or Remove Tag");

      while (successRead == false) {
        successRead = getID();
        if (successRead) {
          if (tagID == myTags[0]) {
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Can't Remove");
            lcd.setCursor(0, 1);
            lcd.print("Master Tag!");
            delay(500);
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Access Granted!");
            analogWrite(GREEN_LED, 400);
            myServo.write(180); //Unlocks the door
            printNormalModeMessage();
            doorOpened = true;
            successRead = false;
            printNormalModeMessage();
            return;
          }

          for (uint8_t i = 1; i < 100; i++) {
            if (tagID == myTags[i]) {
              myTags[i] = "";
              lcd.clear();
              lcd.setCursor(0, 0);
              lcd.print("Tag Removed!");
              delay(500);
              printNormalModeMessage();
              return;
            }
          }
          myTags[tagsCount] = strdup(tagID.c_str());
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Tag Added!");
          delay(500);
          printNormalModeMessage();
          tagsCount++;
          return;
        }
      }
    }

    successRead = false;
    for (int i = 0; i < 100; i++) {
      if (tagID == myTags[i]) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Access Granted!");
        analogWrite(GREEN_LED, 400);
        myServo.write(180); //Unlocks the door
        printNormalModeMessage();
        correctTag = true;
        doorOpened = true;
        lcd.clear();
        lcd.setCursor(0, 0);
      }
    }

    if (!correctTag) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Access Denied!");
      analogWrite(RED_LED, 400);
      delay(1500);
      analogWrite(RED_LED, 0);
      printNormalModeMessage();
    }
  }

  else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Door open!");
    lcd.setCursor(0, 1);
    lcd.print("Closing...,");
    myServo.write(50);
    analogWrite(GREEN_LED, 0);
    analogWrite(RED_LED, 0);
    doorOpened = false;
    printNormalModeMessage();
  }


}
