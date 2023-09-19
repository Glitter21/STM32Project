#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
int main(void)
{
	
	OLED_Init();
	//OLED_ShowString(1, 1, "Are you stupid");
	//OLED_ShowNum(2, 1, 12345, 5);
	//OLED_ShowSignedNum(2, 7, -66, 2);
	//OLED_ShowHexNum(3, 1, 0xAA55, 4);
	//OLED_ShowBinNum(4, 1, 0xAA55, 16);
  OLED_ShowCHinese(1,1,0);
	OLED_ShowCHinese(1,2,1);
	OLED_ShowCHinese(1,3,2);
	OLED_ShowCHinese(1,4,3);
	OLED_ShowCHinese(1,5,4);
	while (1)
	{
		
	}
}
