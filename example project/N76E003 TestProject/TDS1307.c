/*
 * TDS1307.cpp
 *
 * Created: 8/22/2018 1:11:19 AM
 *  Author: BlackHand
 */ 

#define RTC_ADD_W	0xD0
#define RTC_ADD_R	0xD1
#include "Common.h"
#include "i2c_handler.h"


uint8_t BCD_toINT(uint8_t hex)
{
	return(((hex & 0xF0) >> 4) * 10 + (hex & 0x0F));
}


void RTC_SetData(uint8_t item,uint8_t t_val)
{
	i2c_start(RTC_ADD_W);
	i2c_write(item);
	i2c_write(t_val);
	i2c_stop();
}

void RTC_Set(uint8_t secs, uint8_t mins, uint8_t hours, uint8_t DayOfWeek, uint8_t Date, uint8_t month, uint8_t year)
{
	i2c_start(RTC_ADD_W);
	i2c_write(0x00);
	i2c_write(secs);
	i2c_write(mins);
	i2c_write(hours);
	i2c_write(DayOfWeek);
	i2c_write(Date);
	i2c_write(month);
	i2c_write(year);
	i2c_stop();
}

void RTC_Settings(uint8_t sqw_GPIO_Output, uint8_t sqw_enable, uint8_t sqw_frq_1_4_8_32)
{
	uint8_t DS1307_Settings = (sqw_GPIO_Output<<7) | (sqw_enable<<4) | (sqw_frq_1_4_8_32);
	i2c_init();
	i2c_start(RTC_ADD_W);
	i2c_write(7);
	i2c_write(DS1307_Settings);
	i2c_stop();
}

void RTC_Write_GPRAM(uint8_t ramAdd, uint8_t iData)
{
	i2c_start(RTC_ADD_W);
	i2c_write(8+ramAdd);
	i2c_write(iData);
	i2c_stop();
}

uint8_t RTC_Read_GPRAM(uint8_t ramAdd)
{
	uint8_t  ret;
	i2c_start(RTC_ADD_W);
	i2c_write(8+ramAdd);
	i2c_restart(RTC_ADD_R);
	ret = i2c_read(0);
	i2c_stop();
	return ret;
}

uint8_t RTC_GetData(uint8_t item)
{
	uint8_t ret;
	i2c_start(RTC_ADD_W);
	i2c_write(item);
	i2c_restart(RTC_ADD_R);
	ret = i2c_read(0);
	i2c_stop();
	return BCD_toINT(ret);
}