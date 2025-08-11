//W.A.ECP.TO DISPLAY 'A' IN LCD
#include<LPC21XX.H>
#include"delay.h"
void INTI();
void CMD(unsigned char );
void DATA(unsigned char );
#define led 0Xff
#define E 1<<9
#define RS 1<<8
int main()
{
INTI();
CMD(0X80);
DATA('6512');
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


void DATA(unsigned char cmd)
{
IOCLR0=led;
IOSET0=cmd;
IOSET0=RS;
IOSET0=E;
delay_milli_sec(2);
IOCLR0=E;

}
