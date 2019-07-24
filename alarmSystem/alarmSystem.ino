#define TRIG 11
#define ECHO 12
#define BUZZER 13
#define RESET_BUTTON 10
#define ALARM_LED 9
#define SWITCH 8
#define SWITCH_LED 7


long duration, distance;
boolean alarmOn = false;
unsigned int counter = 0;
unsigned int maxCounter = 0;
boolean on = false;
boolean buttonState = false;

void setup() {
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(RESET_BUTTON, INPUT);
  pinMode(ALARM_LED, OUTPUT);
  pinMode(SWITCH, INPUT);
  pinMode(SWITCH_LED, OUTPUT);
}

void loop() {

  delay(150);

  buttonState = digitalRead(SWITCH);

  if (buttonState) {
    on = !on;
    if (on) {
      digitalWrite(SWITCH_LED, HIGH);
    }
    else {
      digitalWrite(SWITCH_LED, LOW);
      alarmOn = false;
      noTone(BUZZER);
      digitalWrite(ALARM_LED, LOW);
    }
  }

  if (on) {
    digitalWrite(TRIG, LOW);
    delayMicroseconds(5);
    digitalWrite(TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG, LOW);

    //Read the signal from the sensor
    duration = pulseIn(ECHO, HIGH);

    //Convert time into distance
    distance = duration / 2 / 29.1;

    Serial.print(distance);
    Serial.println(" cm.");

    if (distance < 30) {
      counter++;
      maxCounter = 0;
    }

    if (distance > 50) {
      maxCounter++;
    }

    if (maxCounter > 5) {
      counter = 0;
    }

    if (counter > 5) {
      alarmOn = true;
      counter = 0;
    }

    if (alarmOn) {
      tone(BUZZER, 500);
      digitalWrite(ALARM_LED, HIGH);
      delay(100);
      digitalWrite(ALARM_LED, LOW);
      counter = 0;
      maxCounter = 0;
    }

    if (digitalRead(RESET_BUTTON)) {
      counter = 0;
      maxCounter = 0;
      alarmOn = false;
      noTone(BUZZER);
      digitalWrite(ALARM_LED, LOW);
    }
  }




}
