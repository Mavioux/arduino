

void setup() {
  // put your setup code here, to run once:
  pinMode(3, INPUT);
  pinMode(5, OUTPUT);
  pinMode(A0, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int buttonInput = digitalRead(3);
 
  if(buttonInput == HIGH) {
    int analogPotential = analogRead(A0);
    analogWrite(5, analogPotential/4);  
  }
  
  
  
}
