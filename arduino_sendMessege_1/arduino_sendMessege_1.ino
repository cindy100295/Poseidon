#include <VSync.h>
ValueReceiver<2> receiver;
int index, mouseY;
uint8_t var = 1;       //串口1接收状态标志位
uint8_t buf_length = 0; //串口1接收数组长度
char buf[100] = {0};   //串口1接收数据存放数组
uint8_t flag = 0;      //处理数据标志位
char inByte = 'a';
int button_open = 4; //开灯按钮连在数字端口4
int button_close = 5; //关灯按钮连在数字端口5
/************************************************

 *************************************************/
void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  pinMode(button_open, INPUT);
  pinMode(button_close, INPUT);
  receiver.observe(index);
  receiver.observe(mouseY);
}
void loop() {

  Serial1.write(inByte);
  if (Serial1.available()) {
    char inByte = Serial1.read();
    Serial.println(inByte);
  }
//------------------------------------------
  if ( index ==1)
    inByte = 'a';
  else
    inByte = 'b';
//inByte = index;
  receiver.sync();

  // -------------------------------------
}

void APC220() {

}
/*************************************************************
                       end
 * **************************************************************/

