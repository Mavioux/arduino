#define in1 6
#define in2 5
#define in3 9
#define in4 3


//in1 high  in2 low mprosta (de3ia)
//in4 high  in3 low mprosta (aristera)

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  char c;
  
  if(Serial.available()) {
    
    c = Serial.read();
    
    if(c == '\n') {
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in4, LOW);
      digitalWrite(in3, LOW);   
    }
    else {    
      if(c == 'w') {
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in4, HIGH);
        digitalWrite(in3, LOW);
      }
      else if(c == 'a') {
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        digitalWrite(in4, HIGH);
        digitalWrite(in3, LOW);
      }
      else if (c == 's') {
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in4, LOW);
        digitalWrite(in3, HIGH);
      }
      else if (c == 'd') {
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in4, LOW);
        digitalWrite(in3, LOW);  
      }
      else if(c == 'z') {
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in4, HIGH);
        digitalWrite(in3, LOW); 
      }
      else if(c == 'x') {
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in4, LOW);
        digitalWrite(in3, HIGH); 
      }
    
      delay(1000);  
    }
    
    
  }
  

}
