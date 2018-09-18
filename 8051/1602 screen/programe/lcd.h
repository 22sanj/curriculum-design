#include "reg52.h"
//#include "stdio.h"

#define u16 unsigned int
#define u8 unsigned char
//typedef unsigned int u16;	  //对数据类型进行声明定义
//typedef unsigned char u8;

 sbit E = P2^7;
 sbit RW = P2^5;
 sbit RS = P2^6;
 sfr LCDData=0x80;

 void Init();
 void Delay(u16 x);
 void Write_Instruction(u8 x);
 void Write_Data(u8 x);
 void Write_String(u8 x,u8 *p);
 void Cls(); 

 

