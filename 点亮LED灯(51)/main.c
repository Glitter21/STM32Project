#include <REGX52.H>
#include <INTRINS.H>
void Delay1ms(unsigned int ms)		//@12.000MHz
{
	unsigned char i, j;
	while(ms)
	{
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
		ms--;
	}
}

void main()
{
	P2=0xFE;//1111 1110
	Delay1ms(100);
	P2=0xFD;
	Delay1ms(100);
	P2=0xFB;
	Delay1ms(100);
	P2=0xF7;
	Delay1ms(100);
	P2=0xEF;
	Delay1ms(100);
	P2=0xDF;
	Delay1ms(100);
	P2=0xBF;
	Delay1ms(100);
	P2=0x7F;
	Delay1ms(100);
}
