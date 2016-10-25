/******************************************
        DHT Temp/Hum Sensor Polling
******************************************/


#include <avr/io.h>
#define __DELAY_BACKWARD_COMPATIBLE__
#include <util/delay.h>
#include <avr/interrupt.h>

#include "LCD_Disp.h"

volatile unsigned char tempCount = 0, tempData = 0;

ISR(INT0_vect)
{
	cli();
	tempData = 0;
	if(TCNT0 > 100)
	{
		tempData = 1;
	}
	TCNT0 = 0;
	tempCount --;
	sei();
}

void initDHT(void)
{
	EICRA |= 0x02;
	EIMSK |= 0x01;
	EIFR &= 0x00;
	
	TCCR0A |= (1 << CS00);	//No Prescaler, 1usec Resolution
}

void pollDHT(unsigned char *climateData)
{
	climateData[0] = 0;
	
	//***************Poll DHT***************
	DDRD |= 0x04;
	PORTD &= 0xFB;
	_delay_ms(20);
	PORTD |= 0x04;
	_delay_us(38);		//40usec minus register changes
	DDRD &= 0xFB;
	PORTD |= 0x04;
	//**************************************
	
	_delay_us(150);
	TCNT0 = 0;
	tempCount = 8;
	tempData = 0;
	
	sei();
	while(tempCount >= 0)
	{
		LCD_Shift(Cur_Shift, Right_Cur, 12);
		climateData[0] |= tempData << tempCount; 
		LCD_Write(tempCount + '0', RS);
		LCD_Shift(Cur_Shift, Left_Cur, 13);
	}
	cli();
}