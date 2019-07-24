#define SOUND 3
#define LED 2

boolean soundVolume = false;
boolean ledOn = false;

void setup() {
  pinMode(SOUND, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  
  soundVolume = digitalRead(SOUND);

  Serial.println(soundVolume);

  if (soundVolume) {
    ledOn = !ledOn;
  }
  if (ledOn) {
    digitalWrite(LED, HIGH);
  }
  else {
    digitalWrite(LED, LOW);
  }
  if (soundVolume) {
    delay(1000);
  }
}
