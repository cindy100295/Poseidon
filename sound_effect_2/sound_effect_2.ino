#define DATA 13
//#define BUSY 0
#define PLAYnPAUSE 8
#define NEXT 9
#define BUSY 12
#define LED 13
int db = 0xFFE7;
int stateFlag = 0;
int songnum = 1;
int busy;
//FFFEH  停止  停止语音播放
void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  pinMode(DATA, OUTPUT);
  pinMode(LED, OUTPUT);
  for (int i = 8; i < 12; i++)
  {
    pinMode(i, INPUT);
  }
  //delay(1000);
  //write_command(0x0001);
  write_command(db);
  write_command(0xfff3);
  stateFlag = 1;
  write_command(0xFFF0);
}

void loop() {
  busy = digitalRead(12);
  if (Serial.available()) {
    char inByte = Serial.read();
    Serial1.write(inByte);
  }
  if (Serial1.available()) {
    char inByte = Serial1.read();
    //Serial.println(inByte);
    //write_command(0xFFF0);//FFF0H  播放  播放/恢复当前的地址语音。
    /*if (digitalRead(PLAYnPAUSE))
      {
      delay(10);
      if (digitalRead(PLAYnPAUSE))
      {
        if (stateFlag)
        {
          write_command(0xFFF1);  //FFF1H  暂停  暂停当前的地址播放
          stateFlag = 0;
        }
        else
        {
          write_command(0xFFF0);//FFF0H  播放  播放/恢复当前的地址语音。
          stateFlag = 1;
        }
      }
      while (digitalRead(PLAYnPAUSE));

      } else*/ if (stateFlag == 1) {
      delay(10);

      if (inByte == '0' && (songnum != 0 || busy == 0)) {
        write_command(0x0000);
        songnum = 0;
      }
      else if (inByte == '1' && (songnum != 1 || busy == 0) )
      {
        write_command(0x0005);
        songnum = 1;
      }
      else if (inByte == '2' && (songnum != 2 || busy == 0) )
      {
        write_command(0x0006);
        songnum = 2;
      }
      else if (inByte == '3' && (songnum != 3 || busy == 0))
      {
        write_command(0x0000);
        songnum = 3;
      }

      while (digitalRead(NEXT));
    }
    Serial.print(inByte);
  }

  Serial.print(' ');
  Serial.print(digitalRead(9));
  Serial.print(' ');
  Serial.println(digitalRead(12));

}


