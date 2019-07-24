#include <stdio.h>


bool ledState = LOW;
bool currentButtonState = LOW;
bool nextButtonState = HIGH;

void setup() {
  // put your setup code here, to run once:
  pinMode(3, INPUT);
  pinMode(5, OUTPUT);
  digitalRead(5, nextButtonState);

}

void loop() {
  // put your main code here, to run repeatedly:
  /*int buttonInput = digitalRead(3);

  if(buttonInput) {
      flag = !flag;
      printf("I was pressed");
      delay(500);
  }

  //delay(100);

  if (flag) {
    digitalWrite(5, HIGH);  
  }
  else {
     digitalWrite(5, LOW); 
  }

  //delay(500);*/

  nextButtonState = digitalRead(3);

  if(currentButtonState == LOW && nextButtonState == HIGH) {
    ledState = !ledState;
    digitalWrite(5, ledState);      
  }

  currentButtonState = nextButtonState;  

  
  
}
