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
		// ����ADת��ֵ��Ӧ�ĵ�ѹ
		Voltage[0]	= (float)AD_Value[0] / 4095 * 3.3;
		Voltage[1]	= (float)AD_Value[1] / 4095 * 3.3;
		Voltage[2]	= (float)AD_Value[2] / 4095 * 3.3;
		
		
		// �����������Ĳ���
		float R_light = 10;  // ���������µĵ���ֵ����λ��ŷķ��
		float R_dark = 1000; // �ڰ������µĵ���ֵ����λ��ŷķ��
	
		
		// ���ݹ����������Լ������ֵ
		float R_sensing	= (Voltage[1] * R_dark) / (3.3 - Voltage[1]);
		float light_intensity = (R_sensing - R_dark) / (R_light - R_dark);
		
		char display_str1[10];
    sprintf(display_str1, "%d%%", (uint16_t)(light_intensity * 100)); // �����ֵ��ʽ��Ϊ�ַ���
		
		// �¶ȴ�������ز���
		float V25 = 1.54;// ��25���϶��µĵ�ѹֵ����λ�����أ�
		float Avg_Slope = 4.3e-3; // ��ѹ���¶�֮���ƽ��б�ʣ���λ������/���϶ȣ�
		float temperature = (float)(Voltage[2] - V25) / Avg_Slope + 25.5; // �����¶�ֵ
		char temperatureStr[10];
    sprintf(temperatureStr, "%.1f", temperature); // ��ʽ���¶��ַ���
		
		//��ѹ
		OLED_ShowNum(1, 6, Voltage[0], 1);
		OLED_ShowNum(1, 8, (uint16_t)(Voltage[0] * 100) % 100, 2);
		
		//����ֵ
		//OLED_ShowNum (2,8,(uint16_t)(light_intensity * 100),4);
		OLED_ShowString(2, 8, display_str1);
		
		//�¶�
		//OLED_ShowNum (3,6,temperature,4);
		OLED_ShowString(3, 6, temperatureStr);
		OLED_ShowCHinese(3, 6, 9);
		
		OLED_ShowNum (4,6,AD_Value[3],4);
		Delay_ms(100);
		//OLED_Clear();
	}
}
