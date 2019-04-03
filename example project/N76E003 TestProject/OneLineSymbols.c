#include "Common.h"
#include "i2c_handler.h"
#include "TSSD1306.h"
#include "OneLineSymbols.h"

#define CMDS	0x00
#define CMD		0x80
#define DATS	0x40
#define DAT		0xC0

#define BAT_WIDHT	15
const uint8_t code Battery[]  =
{
	0x00,0x7E,0x42,0x42,0x66,0x3C,0x00
};

const uint8_t code BatteryL0[]  =
{
	0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42
};
const uint8_t code BatteryL1[]  =
{
	0x5A,0x5A,0x42,0x42,0x42,0x42,0x42,0x42
};
const uint8_t code BatteryL2[]  =
{
	0x5A,0x5A,0x42,0x5A,0x5A,0x42,0x42,0x42
};
const uint8_t code BatteryL3[]  =
{
	0x5A,0x5A,0x42,0x5A,0x5A,0x42,0x5A,0x5A
};
void OLED_DrawBattery(uint8_t line,uint8_t col,uint8_t level)
{
	uint8_t i;
	OLED_SetCursor(line,col);
	i2c_start(OLED_ADD);
	i2c_write(DATS);
	for (i=0; i<3;i++)
	{
		i2c_write(Battery[i]);
	}
	switch(level)
	
	{
		case 0:
		for ( i=0; i<8;i++)
		{
			i2c_write(BatteryL0[i]);
		}
		break;
		case 1:
		for ( i=0; i<8;i++)
		{
			i2c_write(BatteryL1[i]);
		}
		break;
		case 2:
		for ( i=0; i<8;i++)
		{
			i2c_write(BatteryL2[i]);
		}
		break;
		case 3:
		for ( i=0; i<8;i++)
		{
			i2c_write(BatteryL3[i]);
		}
		break;
	}
	for ( i=3; i<7;i++)
	{
		i2c_write(Battery[i]);
	}
	i2c_stop();
}

#define ANT_WIDHT	15
const uint8_t code Antenna[]  =
{
	//0x00,0x18,0x3C,0x3C,0x18,0x00,0x18,0x00,0x00,0x24,0x18,0x00,0x42,0x3C,0x00
	0x00,0x00,0x40,0x40,0x00,0x60,0x60,0x00,0x78,0x78,0x00,0x7E,0x7E,0x00,0x00
};

void OLED_DrawAntenna(uint8_t line,uint8_t col, uint8_t level)
{
	uint8_t i;
	OLED_SetCursor(line,col);
	i2c_start(OLED_ADD);
	i2c_write(DATS);
	for ( i=0;i<5;i++)
	{
		i2c_write(Antenna[i]);
	}
	for ( i=5;i<5+(level*3);i++)
	{
		i2c_write(Antenna[i]);
	}
	i2c_write(0x00);
	i2c_stop();
}



#define MSG_WIDHT	15
const uint8_t code Message[]  =
{
	//0x00,0x5E,0x00,0x00,0x7E,0x7A,0x76,0x6E,0x6E,0x6E,0x6E,0x76,0x7A,0x7E,0x00
	  0x00,0x5E,0x00,0x00,0x7E,0x46,0x4A,0x52,0x52,0x52,0x52,0x4A,0x46,0x7E,0x00
};
void OLED_DrawMessage(uint8_t line,uint8_t col)
{
	uint8_t i;
	OLED_SetCursor(line,col);
	i2c_start(OLED_ADD);
	i2c_write(DATS);
	for ( i=0;i<MSG_WIDHT;i++)
	{
		i2c_write(Message[i]);
	}
	i2c_stop();
}

#define TRI_WIDHT	5
const uint8_t code Triangle[]  =
{
	0x00,0x7E,0x33,0x11,0x00
};
void OLED_DrawTriangle(uint8_t line,uint8_t col)
{
	uint8_t i;
	OLED_SetCursor(line,col);
	i2c_start(OLED_ADD);
	i2c_write(DATS);
	for ( i=0;i<TRI_WIDHT;i++)
	{
		i2c_write(Triangle[i]);
	}
	i2c_stop();
}

void OLED_DrawSpacer(uint8_t line,uint8_t col,uint8_t offset)
{
	uint8_t i;
	OLED_SetCursor(line,col);
	i2c_start(OLED_ADD);
	i2c_write(DATS);
	for ( i=0;i<offset;i++)	i2c_write(0);
	i2c_write(0x7E);
	for ( i=0;i<offset+1;i++)	i2c_write(0);
	i2c_stop();
}