#include<LPC21XX.H>
void INTI();
void CMD(unsigned char);
void DATA(unsigned char);
void delay_ms(unsigned int);
void STR(unsigned char*);
#define DP 0xff
#define RS 1<<8
#define E 1<<9
int main()
{
INTI();
CMD(0X80);


}

void INTI()
{
CMD(0X01);
CMD(0X02);
CMD(0X0C);
CMD(0X38);
}

void CMD(unsigned char cmd)
{
IOCLR0=DP|RS|E;
IOSET0=cmd;
IOCLR0=RS;
IOSET0=E;
delay_ms(2);
IOCLR0=E;
}

void DATA(unsigned char data)
{
IOCLR0=DP|RS|E;
IOSET0=data;
IOSET0=RS;
IOSET0=E;
delay_ms(2);
IOCLR0=E;
}


void STR(unsigned char*s)
{
while(*s)
{
DATA(*s++);
}
}

void LCD_ROTATE(unsigned char*s,unsigned char data )
{
unsigned char i,n,j;
for(n=0;s[n];n++);
j=n;
for(i=0;i<16;i++)
{
 CMD(0X01);
 CMD(data+i);
 STR(s);
 if((16-j)<i)
 {
 CMD(0X01);
 STR(s+(--n));
 }
 delay_ms(500);

}

}
void delay_ms(unsigned int sec)
{
T0PR=15000-1;
T0TCR=0X01;
while(T0TC<sec);
T0TCR=0X03;
T0TCR=0X00;
}
