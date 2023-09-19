#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "AD.h"
#include <stdio.h>
float Voltage[4];

int main(void)
{
	OLED_Init();
	AD_Init();
	
	
	while (1)
	{
		OLED_Clear();
		AD_GetValue();
		OLED_ShowCHinese(1, 1, 0);
		OLED_ShowCHinese(1, 2, 1);
		OLED_ShowCHinese(2, 1, 2);
		OLED_ShowCHinese(2, 2, 3);
		OLED_ShowCHinese(2, 3, 4);
		OLED_ShowCHinese(3, 1, 5);
		OLED_ShowCHinese(3, 2, 6);
		OLED_ShowCHinese(4, 1, 7);
		OLED_ShowCHinese(4, 2, 8);
		OLED_ShowString(1, 5, ":");
		OLED_ShowString(2, 7, ":");
		OLED_ShowString(3, 5, ":");
		OLED_ShowString(4, 5, ":");
	
	OLED_ShowString(1,5,":0.");
	OLED_ShowString(1,10,"V");
		// 计算AD转换值对应的电压
		Voltage[0]	= (float)AD_Value[0] / 4095 * 3.3;
		Voltage[1]	= (float)AD_Value[1] / 4095 * 3.3;
		Voltage[2]	= (float)AD_Value[2] / 4095 * 3.3;
		
		
		// 定义光敏电阻的参数
		float R_light = 10;  // 光照条件下的电阻值（单位：欧姆）
		float R_dark = 1000; // 黑暗条件下的电阻值（单位：欧姆）
	
		
		// 根据光敏电阻特性计算光敏值
		float R_sensing	= (Voltage[1] * R_dark) / (3.3 - Voltage[1]);
		float light_intensity = (R_sensing - R_dark) / (R_light - R_dark);
		
		char display_str1[10];
    sprintf(display_str1, "%d%%", (uint16_t)(light_intensity * 100)); // 将输出值格式化为字符串
		
		// 温度传感器相关参数
		float V25 = 1.54;// 在25摄氏度下的电压值（单位：伏特）
		float Avg_Slope = 4.3e-3; // 电压与温度之间的平均斜率（单位：伏特/摄氏度）
		float temperature = (float)(Voltage[2] - V25) / Avg_Slope + 25.5; // 计算温度值
		char temperatureStr[10];
    sprintf(temperatureStr, "%.1f", temperature); // 格式化温度字符串
		
		//电压
		OLED_ShowNum(1, 6, Voltage[0], 1);
		OLED_ShowNum(1, 8, (uint16_t)(Voltage[0] * 100) % 100, 2);
		
		//光敏值
		//OLED_ShowNum (2,8,(uint16_t)(light_intensity * 100),4);
		OLED_ShowString(2, 8, display_str1);
		
		//温度
		//OLED_ShowNum (3,6,temperature,4);
		OLED_ShowString(3, 6, temperatureStr);
		OLED_ShowCHinese(3, 6, 9);
		
		OLED_ShowNum (4,6,AD_Value[3],4);
		Delay_ms(100);
		//OLED_Clear();
	}
}
