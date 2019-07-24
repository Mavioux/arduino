#include <NewPing.h>
#define red 8
#define green 9
#define blue 10

NewPing sonar(4,5, 300);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(3, INPUT);
  
  digitalWrite(red, HIGH);
  digitalWrite(green, LOW);
  digitalWrite(blue, HIGH);

  digitalWrite(3, HIGH);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int distance = sonar.ping_cm();

  if( distance <= 10) {
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
    digitalWrite(blue, HIGH); 
    Serial.print("Don't go any further, danger at ");
    Serial.print(distance);
    Serial.println(" cm");
  }
  else if ( distance <= 30 ) {
    digitalWrite(red, HIGH);
    digitalWrite(green, HIGH);
    digitalWrite(blue, LOW);
    Serial.print(distance);
    Serial.println(" cm remaining, stop here or proceed carefully.");      
  }
  else if ( distance <= 50 ) {
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
    digitalWrite(blue, HIGH); 
    //Serial.println("Found obstacle at %d.", distance);    
  }
  else {
    digitalWrite(red, HIGH);
    digitalWrite(green, HIGH);
    digitalWrite(blue, HIGH); 
    Serial.println("Drive safe!");   
  }

  delay (500);
}
