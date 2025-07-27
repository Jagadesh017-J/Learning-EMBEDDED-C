#include<LPC21XX.H>
int main()
{
  IODIR0=1>>17;
  IOSET=1>>17;
  IOCLR=1>>17;
  while(1);
}
