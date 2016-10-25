/*
 * SmartThermo.c
 *
 * Created: 08.07.14 19:47:18
 *  Author: Sean McQuay
 */ 


#include <avr/io.h>
#include <util/delay.h>

#include "I2C.h"
#include "LCD_Disp.h"
#include "Conversions.h"
#include "RTC.h"

int main(void)
{
	DDRB |= 0b00001001;
	PORTB |= 0b00001001;

	unsigned char timeData[7];
	unsigned char climateData[2];

	I2C_init();
	LCD_init();
	initDHT();
	
	
	
    while(1)
    {
		readRTC(timeData);
		LCD_Write(((timeData[2] & 0xF0) >> 4) + '0', RS);
		LCD_Write((timeData[2] & 0x0F) + '0', RS);
		LCD_Write('.', RS);
		LCD_Write(((timeData[1] & 0xF0) >> 4) + '0', RS);
		LCD_Write((timeData[1] & 0x0F) + '0', RS);
		LCD_Write('.', RS);		
		LCD_Write(((timeData[0] & 0xF0) >> 4) + '0', RS);
		LCD_Write((timeData[0] & 0x0F) + '0', RS);
		LCD_Shift(Cur_Shift, Left_Cur, 8);
		
		pollDHT(climateData);
    }
}