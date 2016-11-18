void write_command(int COM_data) 
{      
    byte high_data; //高八位
    byte low_data;   //低八位
    low_data  = COM_data & 0x00ff; 
    high_data = (COM_data>>8) & 0x00ff; 
    digitalWrite(DATA,LOW); 
    delay(5);                         //拉低数据线 5 毫秒
    for(int i = 0;i < 8;i++)                        //发送高八位
    { 
         if(high_data & 0x80)                            //数据位为 1 
         { 
             digitalWrite(DATA,HIGH); 
             delayMicroseconds(600);                     //延时 600us 
             digitalWrite(DATA,LOW); 
             delayMicroseconds(200);                    //延时 200us 
         }else{ 
             digitalWrite(DATA,HIGH);                          
             delayMicroseconds(200);                   //延时 200us  
             digitalWrite(DATA,LOW); 
             delayMicroseconds(600);                   //延时 600us 
         } 
         high_data = _crol_(high_data,1);     //循环左移一位
    } 
    for(int i = 0;i < 8;i++)                         // 发送低八位
    { 
        if(low_data & 0x80)             //数据位为 1 
        { 
            digitalWrite(DATA,HIGH); 
            delayMicroseconds(600);      //延时 600us 
            digitalWrite(DATA,LOW); 
            delayMicroseconds(200);               //延时 200us  
        }else{ 
            digitalWrite(DATA,HIGH); 
            delayMicroseconds(200);                  //延时 200us  
            digitalWrite(DATA,LOW); 
            delayMicroseconds(600);                  //延时 600us 
        } 
        low_data = _crol_(low_data,1);  
    } 
    digitalWrite(DATA,HIGH); 
    delay(1);
} 

byte _crol_(byte data,int num)
{
    byte d;
    d = (data << num) | (data >> (8 - num));
    return d;
}
