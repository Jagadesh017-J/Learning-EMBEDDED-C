// W.A.ECP FOR 8-LED DE-CONVERENGE BLINKING ..
#include<LPC21XX.H>
void delay(unsigned int);
#define LED1 1<<i
#define LED2 1<<j

int main()
{
unsigned int i,j;
while(1)
{
for(i=4,j=3;j>0;i++,j--)
{
IODIR0=LED1|LED2;
IOCLR0= LED1|LED2;
delay(500);
IOSET0=LED1|LED2;
delay(500);
}

}

}

void delay(unsigned int sec)
{
T0PR=15000-1;                                                                                   00-1;
T0TCR=0X1;
while(T0TC<sec);
T0TCR=0X3;
T0TCR=0X0;
}
