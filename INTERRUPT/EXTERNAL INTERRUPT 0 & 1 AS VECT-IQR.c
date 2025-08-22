// external interrupt-0 AND 1 as vect-irq
#include<LPC21XX.H>
#define led1 1<<2
#define led2 1<<3
void EXT0_CONF();
void delay_ms(unsigned char );

void EXT0_ISR() __irq
{
EXTINT=0X01;
IOSET0=led1;
IOCLR0=led1;
VICVectAddr=0;
}

void EXT1_ISR() __irq
{
EXTINT=0X02;
IOSET0=led1;
IOCLR0=led1;
VICVectAddr=0;
}

void EXT0_CONF()
{
 VICIntSelect=0;
 VICVectCntl0=0x20|14;
 VICVectAddr0=(int)EXT0_ISR;

 VICVectCntl1=0x20|15;
 VICVectAddr1=(int)EXT1_ISR;
}

 unsigned int count=0;

 int main()
 {
 PINSEL1=0X01;
 PINSEL0=0X20000000;
 IODIR0=led1|led2;
 EXT0_CONF();
 EXTMODE=0X03;
 EXTPOLAR=0X00;

 VICIntEnable=1<<14|1<<15;
 while(1)
 count++;
 }

 void delay_ms(unsigned char sec )
 {
 T0PR=15000-1;
 T0TCR=0X01;
 while(T0TC<sec);
 T0TCR=0X03;
 T0TCR=0X00;
 }
