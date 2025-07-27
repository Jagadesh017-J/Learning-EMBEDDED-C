// WRITEN A EMBEDDED PROGRAM FOR 1-LED BLINKING..
#include<LPC21XX.H>
void delay(unsigned int);
#define LED 1<<17;
int main()
{
IODIR0=LED;
while(1)
{
IOSET0= LED;
delay(1);
IOCLR0=LED;
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
