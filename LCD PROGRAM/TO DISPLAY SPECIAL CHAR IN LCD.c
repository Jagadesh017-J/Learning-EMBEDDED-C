//W.A.ECP.TO DISPLAY SPECIAL CHAR IN LCD
#include<LPC21XX.H>
#include"delay.h"
#define LCD 0XFF
#define RS 1<<8
#define E 1<<9
void CMD(unsigned int);
void DATA(unsigned int);
void STR(unsigned char* str);
void SPL(unsigned int N);
void INIT();
unsigned char spl[]={0X04,0X0E,0X1F,0X0E,0X04,0X04,0X0E,0X15,//80 boy
                     0X04,0X04,0X04,0X0A,0X11,0X11,0X00,0X00,//C0 boy
					 0X00,0X1B,0X15,0X11,0X11,0X0A,0X04,0X00,//81 heart
					 0X00,0X04,0X06,0X1F,0X06,0X04,0X00,0X00,//82 arrow
					 0X00,0X00,0X00,0X04,0X0E,0X1F,0X0E,0X04,//86 girl
					 0X04,0X0E,0X15,0X0E,0X1F,0X0A,0X0A,0X00,//C6 girl
					 
					 };
int main()
{
int i,K=0;
INIT();
while(1)
{
CMD(0X80); 
SPL(64);
CMD(0X80);
DATA(0);
CMD(0XC0);
DATA(1);
CMD(0X82);
DATA(2);
delay_milli_sec(500);
CMD(0X83);
DATA(3);
delay_milli_sec(500);
CMD(0X85);
DATA(4);
CMD(0XC5);
DATA(5);

/*for(i= 0;i>=K;i++)
{
CMD(0X85);
DATA(' ');
delay_milli_sec(500);

DATA(4);
CMD(0XC5);
DATA(5);
K++;
}
  */


void SPL(unsigned int N)
{
unsigned int i;
CMD(0X40);
for(i=0;i<N;i++)
DATA(spl[i]);
}

void INIT()
{
IODIR0=LCD|RS|E;
CMD(0X01);
CMD(0X02);
CMD(0X0C);
CMD(0X38);
}
void DATA(unsigned int data)
{
IOCLR0=LCD;
IOSET0=data;
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
