#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "AD.h"

uint16_t ADValue;
float Voltage;

int main(void)
{
	OLED_Init();
	AD_Init();
	
	//OLED_ShowString(1, 1, "ADValue:");
	OLED_ShowCHinese0(1,1,0);//原始数据
	OLED_ShowCHinese0(1,2,1);
	OLED_ShowCHinese0(1,3,2);
	OLED_ShowCHinese0(1,4,3);
	OLED_ShowString(1,9,":");
	
	OLED_ShowCHinese(2,1,0);//电压
	OLED_ShowCHinese(2,4,1);
	OLED_ShowString(2,9,":0.");
	OLED_ShowString(2,14,"V");
	//OLED_ShowString(3, 1, "Volatge:0.00V");
	 
	while (1)
	{
		ADValue = AD_GetValue();
		Voltage = (float)ADValue / 4095 * 3.3;
		
		OLED_ShowNum(1, 10, ADValue, 4);
		OLED_ShowNum(2, 10, Voltage, 1);
		OLED_ShowNum(2, 12, (uint16_t)(Voltage * 100) % 100, 2);
		
		Delay_ms(100);
	}
}
