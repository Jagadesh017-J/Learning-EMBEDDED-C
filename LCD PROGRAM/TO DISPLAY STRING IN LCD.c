/W.A.ECP.TO DISPLAY STR IN LCD
  
#include<LPC21XX.H>
#include"delay.h"
#define LCD 0XFF
#define RS 1<<8
#define E 1<<9
void CMD(unsigned int);
void DATA(unsigned int);
void STR(unsigned char* str);
void INIT();
int main()
{
INIT();
CMD(0X80); 
STR("JAGADSEH");

}
void INIT()
{
IODIR0=LCD|RS|E;
CMD(0X01);
CMD(0X02);
CMD(0X0C);
CMD(0X38);
CMD(0X80);
}
void DATA(unsigned int DATA)
{
IOCLR0=LCD;
IOSET0=DATA;
IOSET0=RS;
IOSET0=E;
delay_milli_sec(2);
IOCLR0=E;
}

void CMD(unsigned int CMD)
{
IOCLR0=LCD;
IOSET0=CMD;
IOCLR0=RS;
IOSET0=E;
delay_milli_sec(2);
IOCLR0=E;
}

void STR(unsigned char* str)
{
int i;
for(i=0;str[i];i++)
DATA(str[i]);
}
