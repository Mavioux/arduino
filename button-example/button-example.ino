void setup() {
  // put your setup code here, to run once:
  pinMode(3, INPUT);
  pinMode(5, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int buttonInput = digitalRead(3);

  digitalWrite(5, buttonInput);

}
