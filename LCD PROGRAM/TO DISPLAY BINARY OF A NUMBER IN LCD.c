//W.A.ECP.TO DISPLAY BINARY OF A NUMBER IN LCD
#include<LPC21XX.H>
#include"delay.h"
void INTI();
void CMD(unsigned char );
void DATA(unsigned char );
void BINARY(unsigned char);
void STR(unsigned char*);
#define led 0Xff
#define E 1<<9
#define RS 1<<8
int main()
{
char COUNT=0;
INTI();
CMD(0X80);
STR("BINARY = ");
CMD(0XC0);
BINARY(3);
}

void INTI()
{
IODIR0=led|RS|E;
CMD(0X01);
CMD(0X02);
CMD(0X0C);
CMD(0X38);

}

void CMD(unsigned char cmd)
{
IOCLR0=led;
IOSET0=cmd;
IOCLR0=RS;
IOSET0=E;
delay_milli_sec(2);
IOCLR0=E;

}

void DATA(unsigned char data)
{
IOCLR0=led;
IOSET0=data;
IOSET0=RS;
IOSET0=E;
delay_milli_sec(2);
IOCLR0=E;
}

void BINARY(unsigned char NUM)
{
char i,count=0;
for(i=7;i>=0;i--)
{
DATA(((NUM>>i)&1)+48);
}

}

void STR(unsigned char* str)
{
int i;
for(i=0;str[i];i++)
DATA(str[i]);
}
