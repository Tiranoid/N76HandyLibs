#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_define.h"
#include "Common.h"
#include "delay.h"
#include "i2c_handler.h"
#include "TSSD1306.h"
#include "TDS1307.h"
#include "OneLineSymbols.h"
void main()
{
	// Set I2C address, width and height. call it before OLED_Init
	OLED_Settings(0x78,128, 64);
	// initialize OLED
	OLED_Init();
	// Set contrast (1~255)
	OLED_SetContrast(255);
	// obviously clears OLED
	OLED_Clear();
	// switch between two fonts.
	OLED_SetFont(0);
	OLED_Write("Hello Nuvoton !");
	// Sets cursor to (line (which is from 0 to OLED_hight/8) and column from 0 to OLED_width)
	// in this case (128*64) we have 64/8=8 lines and 128 columns
	OLED_SetCursor(1,0);
	OLED_SetFont(1);
	// Writes to the screen
	OLED_Write("Here We Are !");
	// draw some icons (line,column,value)
	OLED_DrawMessage(2,114);
	OLED_DrawBattery(1,114,2);
	OLED_DrawAntenna(0,114,3);
	OLED_SetCursor(2,0);
	while(1)
	{
		OLED_ClearField(2,0,68);
		OLED_WriteINT(RTC_GetData(2));
		OLED_Write(":");
		OLED_WriteINT(RTC_GetData(1));
		OLED_Write(":");
		OLED_WriteINT(RTC_GetData(0));
		OLED_DrawSpacer(OLED_currLine,OLED_currCol,5);
		OLED_WriteINT(RTC_GetData(4));
		OLED_Write("/");
		OLED_WriteINT(RTC_GetData(5));
		OLED_Write("/20");
		OLED_WriteINT(RTC_GetData(6));
		Timer3_Delay100ms(8);
	}
}
