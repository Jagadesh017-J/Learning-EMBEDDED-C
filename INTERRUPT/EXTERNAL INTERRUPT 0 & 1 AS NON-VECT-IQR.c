#include<LPC21XX.H>
#define led1 1<<2
#define led2 1<<3
void delay_ms(unsigned char );
void NON_VECT_ISR()__irq
{
if((VICIRQStatus>>14)&1)
{
EXTINT=0X01;
IOSET0=led1;
IOCLR0=led1;
VICVectAddr=0;
}
if((VICIRQStatus>>15)&1)
{
EXTINT=0X02;
IOSET0=led2;
IOCLR0=led2;
VICVectAddr=0;
}

}
unsigned int count =0;
int main()
{
 PINSEL1=0X01;
 PINSEL0=0X20000000;
 IODIR0=led1|led2;
 VICIntSelect=0;
 VICDefVectAddr=(int)NON_VECT_ISR;
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
