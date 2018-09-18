#include "lcd.h"

void Init() //初始化
 {
   Write_Instruction(0x38);
   Delay(200);

   Write_Instruction(0x0e);
   Delay(200);

   Write_Instruction(0x06);
   Delay(200);
 }

 void Delay(u16 x)	//延时函数
 {
 	while(x--);
 }
 
 void Write_Instruction(u8 x)	//命令写入函数
 {
 	Delay(1000);
	E = 0;
	RW = 0;
	RS = 0; 

	LCDData=x;//命令符
	E = 1;
	Delay(20);
	E = 0;
 
 }

 void Write_Data(u8 x)  //数据写入操作，单个数据
{
	Delay(1000);
	E = 0;
	RW = 0;
	RS = 1;
	
	E = 1;
	LCDData = x;
	E = 0;
                                                                                                                                                                                                                                                                      
}

void Write_String(u8 x,u8 *p)  //写入字符串
{
	Write_Instruction(x);
	while(*p !=0x00)
	{
		Write_Data(*p);
		p++;
		if(x++ == 0x8f)
		{
			Write_Instruction(0xc0);		
		}
	}




}


void Cls(void)	//清屏
{
	Write_Instruction(0x01);

}
