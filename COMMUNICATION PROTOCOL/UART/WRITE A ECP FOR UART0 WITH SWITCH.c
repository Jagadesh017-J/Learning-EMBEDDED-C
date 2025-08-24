#include<LPC21XX.H>

void UART0_CONF(void);
void UART0_TX(unsigned char);
unsigned char UART0_RX(void);
void UART0_STR(unsigned char* );
void delay_ms(unsigned char);

#define SW1 14
#define SW2 15
int main()
{
	unsigned char count=0;
	UART0_CONF();
	
	while(1)
	{
		if(((IOPIN0>>SW1)&1)==0)
		{ 
			delay_ms(200);
			count=1;
		}
		else if(((IOPIN0>>SW2)&1)==0)
		{
			delay_ms(200);
			count=2;
		}
		if(count==1)
		{
			UART0_STR("SWITCH 1 IS PRESSED ");
			count=0;
		}
		else if(count==2)
		{
			UART0_STR("SWITCH 2 IS PRESSED ");
			count=0;
		}
		
	}
	
}

void UART0_CONF(void)
{
	PINSEL0=0X05;
	U0LCR=0x83;
	U0DLL=97;
	U0DLM=0;
	U0LCR=0X03;
}

void UART0_TX(unsigned char data)
{
	while(((U0LSR>>5)&1)==0);
	U0THR=data;
}

unsigned char UART0_RX()
{
	while((U0LSR&1)==0);
	return U0RBR;
}

void UART0_STR(unsigned char *str)
{
	while(*str)
		UART0_TX(*str++);
}

void delay_ms(unsigned char sec)
{
	T0PR=15000-1;
	T0TCR=0X1;
	while(T0TC<sec);
	T0TCR=0X3;
	T0TCR=0X0;
	
}




