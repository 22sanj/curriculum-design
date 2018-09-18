#include "reg52.h"	
#include "lcd.h"


unsigned char Disp[]=" Pechin Science ";
void main()
{   
	Init();
	//Delay(1000);
	//Write_Data(2);
	
	Write_String(0x80,"Kuangweijie");
	Write_String(0xc0,"43");
	//Cls();
	//while(1);

}