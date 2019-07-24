#include <Servo.h>

#include <NewPing.h>

NewPing sonar(4, 5, 180);
Servo servo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo.attach(6);

}

void loop() {
  // put your main code here, to run repeatedly:
  int angle = sonar.ping_cm();
  Serial.println(angle);
  servo.write(angle);
  delay(500);

  

}
