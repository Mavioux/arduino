#define in1 6
#define in2 5
#define in3 9
#define in4 3

bool flag = true;

//in1 high  in2 low mprosta (de3ia)
//in4 high  in3 low mprosta (aristera)

void setup() {
  // put your setup code here, to run once:
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (flag) {
    analogWrite(in1, 255);
    analogWrite(in2, 0);
    analogWrite(in3, 0);
    analogWrite(in4, 255);  
  }

  delay(4000);


  analogWrite(in1, 0);
  analogWrite(in2, 0);
  analogWrite(in3, 0);
  analogWrite(in4, 0);

  flag = false;

  

}
