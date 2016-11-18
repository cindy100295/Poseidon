int lastS1;
int space, step1, s1;
uint8_t var = 1;
uint8_t buf_length = 0;
char buf[100] = {0};
uint8_t flag = 0;
int motorPin =  13;         //LED 接到数字 13
int motorPin1 =  4;
int motorPin0 =  12;
int val;
#include <Servo.h>
int angle = 0;
int angle1 = 0;
int count;
boolean positive;
Servo myservo;
Servo myservo1;

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  count = 0;
    pinMode(motorPin0, OUTPUT);
  pinMode(motorPin, OUTPUT);
  // Serial.begin(9600);    //用于调试
  pinMode(motorPin1, OUTPUT);
  myservo.attach(9);
  s1 = 0;
  step1 = 0;
  space = 0;
  flag = true;
}

void loop() {
  if (Serial.available()) {
    char inByte = Serial.read();
    Serial1.write(inByte);
  }
  if (Serial1.available()) {
    char inByte = Serial1.read();
    Serial.print(s1);
    Serial.println(inByte);
    switch (inByte) {
      case '0':
        digitalWrite(motorPin, LOW);
        digitalWrite(motorPin0, LOW);
        // delay(100);
        //  myservo.write(0);
        break;
      case '1':
        digitalWrite(motorPin, HIGH);
        digitalWrite(motorPin0, HIGH);
        /* if (s1>lastS1&&s1 == 180)
           positive = true;
          else if (s1<lastS1 && s1==0 )
           positive = false;*/
        s1 += space;
        if (s1 == 0)space = 1;
        if (s1 == 180)space = -1;


        break;
      case '2':
        digitalWrite(motorPin, LOW);
        digitalWrite(motorPin0, LOW);
        break;
      case '3':
        digitalWrite(motorPin, LOW);
        digitalWrite(motorPin0, LOW);
        break;
    }
  }
  myservo.write(s1);
  delay(3);
  //moving();
  count += 1;
  lastS1 = s1;

}

/*  int soundState1 = analogRead(soundPin1);  //读取传感器的值
   Serial.println(soundState1);    //串口打印声音传感器的值

   //如果声音值大于 10，亮灯，并持续 10s，否则关灯
  if (soundState1 > 1000) {
       digitalWrite(motorPin1, HIGH);
       myservo1.write(180);
       //myservo1.write(0);
       }else{
       digitalWrite(motorPin1, LOW);
       myservo1.write(0);
  }
       }      */

