/*
	i2c Handler for Nuvoton N76E003 microcontrollers
	Written by Tirdad Sadri Nejad

	keeping my name written here on this header motivates me for such efforts.
	
	tirdad_ms@hotmail.com
*/


#include "N76E003.h"
#include "Common.h"
#include "SFR_Macro.h"
#include "Function_define.h"
#include "i2c_handler.h"

void i2c_init()
{
	P13_OpenDrain_Mode;
	P14_OpenDrain_Mode;
	I2CLK = I2C_PRSC;
	set_I2CEN; 
}

bit i2c_write(uint8_t iData)
{
	I2DAT = iData;
	clr_SI;
	while (!SI);
	if (I2STAT != 0x28)		return 0;
	else return 1;
}

bit i2c_restart(uint8_t iAdd)
{
	set_STA;
	clr_SI; 
	while (!SI);
	if (I2STAT != 0x10)		return 0;
	clr_STA;
	I2DAT	= iAdd;
	clr_SI;
	while (!SI);
	if (I2STAT != 0x18 && I2STAT != 0x40)		return 0;
	else return 1;
}
bit i2c_start(uint8_t iAdd)
{
	set_STA;
	clr_SI;
	while (!SI);
	if (I2STAT != 0x08)		return 0;
	I2DAT	= iAdd;
	clr_STA;
	clr_SI;
	while (!SI);
	if (I2STAT != 0x18 && I2STAT != 0x40)		return 0;
	else return 1;
}

void i2c_stop()
{
	clr_SI;
  set_STO;
}

uint8_t i2c_read(uint8_t ack)
{
	if(ack !=0) set_AA;
	else clr_AA;
	clr_SI;
	while(!SI);
	return I2DAT;
}