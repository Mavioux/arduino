int value = 0;
//int flag = true;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  if(value < 256){
    analogWrite(3, value++);
    delay(20);
  }
  else if(value >= 256 && value <= 510){
    analogWrite(3, 511 - value++);
    delay(20);
  }

  

}
