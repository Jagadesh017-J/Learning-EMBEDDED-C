// WRITEN A EMBEDDED PROGRAM FOR 2-LED BLINKING..
#include<LPC21XX.H>
void delay(unsigned int);
#define LED1 1<<17
#define LED2 1<<3
int main()
{
IODIR0=LED1|LED2;
while(1)
{
IOSET0= LED1|LED2;
delay(1);
IOCLR0=LED1|LED2;
delay(1);
}
}

void delay(unsigned int sec)
{
T0PR=1500000-1;
T0TCR=0X1;
while(T0TC<sec);
T0TCR=0X3;
T0TCR=0X0;
}
