#include <Servo.h>
Servo servida;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servida.attach(3);

}

void loop() {
  // put your main code here, to run repeatedly:
  //int counter = 0;
  int number = 0;

  while (true) {
     
     

    if(Serial.available()) {
      char c = Serial.read();
      if(c == '\n') {
        break;  //otan teleiwsei to noumero vgainoyme apo to loop
      }
      else {
        number = number * 10;
        number += (c - '0');
      }
    }
  }
  
  Serial.println(number);
  servida.write(number);

}
