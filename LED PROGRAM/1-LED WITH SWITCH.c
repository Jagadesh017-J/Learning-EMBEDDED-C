// W.A.ECP FOR 1-LED WITH SWITCH..
#include<LPC21XX.H>
#define led  1<<1
#define sw 1<<2
int main()
{
IODIR0=led;
while(1)
{
if((IOPIN0&(sw))==0)
IOCLR0=led;
else
IOSET0=led;
} 

}
