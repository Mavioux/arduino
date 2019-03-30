#define blue 3
#define green 5
#define red 6

char currentColor = 'r';
char nextColor = 'g';

void setup() {
  // put your setup code here, to run once:
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);

  digitalWrite(blue, HIGH);
  digitalWrite(green, HIGH);
  digitalWrite(red, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  //eixame led anodiko ara 8elame thn antistash sthn tash kai anavame ka8e xrwma kanontas to LOW
  

  if(currentColor == 'r') {
    digitalWrite(green, LOW);
    digitalWrite(red, HIGH);
    currentColor = 'g';
  }
  else if(currentColor == 'g') {
    digitalWrite(blue, LOW);
    digitalWrite(green, HIGH);
    currentColor = 'b';
  }
  else {
    digitalWrite(red, LOW);
    digitalWrite(blue, HIGH);
    currentColor = 'r';
  } 

  delay(1000);

  

}
