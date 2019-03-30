void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  for(int value = 0; value < 256; value++) {
    analogWrite(3, value);
    analogWrite(5, 255 - value);
    delay(1);
  }

  for(int value = 0; value < 256; value++) {
    analogWrite(3, 255 - value); 
    analogWrite(5, value);
    delay(1);
  }

}
