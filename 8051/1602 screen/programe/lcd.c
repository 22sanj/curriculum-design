#include "lcd.h"

void Init() //��ʼ��
 {
   Write_Instruction(0x38);
   Delay(200);

   Write_Instruction(0x0e);
   Delay(200);

   Write_Instruction(0x06);
   Delay(200);
 }

 void Delay(u16 x)	//��ʱ����
 {
 	while(x--);
 }
 
 void Write_Instruction(u8 x)	//����д�뺯��
 {
 	Delay(1000);
	E = 0;
	RW = 0;
	RS = 0; 

	LCDData=x;//�����
	E = 1;
	Delay(20);
	E = 0;
 
 }

 void Write_Data(u8 x)  //����д���������������
{
	Delay(1000);
	E = 0;
	RW = 0;
	RS = 1;
	
	E = 1;
	LCDData = x;
	E = 0;
                                                                                                                                                                                                                                                                      
}

void Write_String(u8 x,u8 *p)  //д���ַ���
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


void Cls(void)	//����
{
	Write_Instruction(0x01);

}
