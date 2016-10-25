/******************************************
         Read/Write of DS1307 RTC
******************************************/

#include <avr/io.h>
#define __DELAY_BACKWARD_COMPATIBLE__
#include <util/delay.h>
#include "I2C.h"


void initRTC()
{
	
}


void readRTC(unsigned char *timeData)
{
	I2C_Start(0xD0);
	I2C_Write(0x00);
	I2C_Stop();
	I2C_Start(0xD1);
	for(int i = 0; i <= 6; i++)
	{
		timeData[i] = I2C_ReadAck();
	}
	I2C_ReadNak();
	I2C_Stop();	
}


void writeRTC(unsigned char *timeData)
{
	
}