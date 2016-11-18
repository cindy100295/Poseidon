#include <FastLED.h>
#include <stdlib.h>
#define NUM_LEDS 25
#define DATA_PIN 11
#define DATA_PIN1 10
int mode;
CRGB leds[NUM_LEDS];
CRGB leds1[NUM_LEDS];
int r, g, b;
int count;
uint8_t var = 1;       //串口1接收状态标志位
uint8_t buf_length = 0; //串口1接收数组长度
char buf[100] = {0};   //串口1接收数据存放数组
uint8_t flag = 0;      //处理数据标志位
int ledpin = 9; //声明LED的数字接口编号
int val;//接受主机发来的LED灯状态标志

/************************************************

 *************************************************/
void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  FastLED.addLeds<NEOPIXEL, DATA_PIN1>(leds1, NUM_LEDS);
  r = 150;
  g = 110;
  b = 255;
  count = 0;
  mode = 1;


  Serial.begin(9600);
  Serial1.begin(9600);
}
void loop() {
  // read from port 0, send to port 1:
  if (Serial.available()) {
    char inByte = Serial.read();
    Serial1.write(inByte);
  }
  // read from port 1, send to port 0:
  if (Serial1.available()) {
    char inByte = Serial1.read();
    Serial.println(inByte);
    switch (inByte) {
      case '0':
        sunny();
        break;
      case '1':
        cloudy();
        break;
      case '2':
        lightning();
        break;
      case '3':
        cloudy();//foggy
        break;

    }
  }
  count += 1;
  //Serial.println(count % 200);
  FastLED.clear();
  FastLED.show();
}// end loop
/*************************************************************
                       end
 * **************************************************************/

