// W.A.ECP FOR 8-LED BLINKING FROM RIGHT TO LEFT..
int main()
{
int i;
while(1)
{
for(i=7;i>=0;i--)
{
IODIR0=1<<i;
IOCLR0= 1<<i;
delay(500);
IOSET0=1<<i;
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
