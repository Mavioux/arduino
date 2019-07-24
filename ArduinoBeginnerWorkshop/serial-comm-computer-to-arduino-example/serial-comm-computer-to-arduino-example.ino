#define blue 3
#define green 5
#define red 6

char choice = 'r';

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);

  digitalWrite(blue, HIGH);
  digitalWrite(green, HIGH);
  digitalWrite(red, HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
  char c;
  if (Serial.available()) {
    c = Serial.read();  

    if(c == '\n') {
     //Serial.println("Change Line"); 
    }
    else {    
      if(c == 'r') {
        digitalWrite(blue, HIGH);
        digitalWrite(green, HIGH);
        digitalWrite(red, LOW);
      }
      else if(c == 'g') {
        digitalWrite(blue, HIGH);
        digitalWrite(green, LOW);
        digitalWrite(red, HIGH);
      }
      else if (c == 'b') {
        digitalWrite(blue, LOW);
        digitalWrite(green, HIGH);
        digitalWrite(red, HIGH);
      }
      else {
        digitalWrite(blue, HIGH);
        digitalWrite(green, HIGH);
        digitalWrite(red, HIGH);  
      }
    
      delay(10);
    }
    
  }

}
