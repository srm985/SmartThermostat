/*
 * Numerical Conversion Functions
 *
 * Created: 9.7.14
 * Author: Sean McQuay
 *
 */

#include <avr/io.h>
#include <util/delay.h>

#include "Conversions.h"


unsigned char BCD2Hex_Byte(unsigned char BCD)
{
	unsigned char data;
	
	data = (BCD & 0x0F) + (((BCD & 0xF0) >> 4) * 10);
	
	return data;
}


unsigned char Hex2BCD_Byte(unsigned char Hex)
{
	unsigned char data = 0;
	
	data += (Hex / 10) << 4;
	data += Hex - ((Hex / 10) * 10);
	
	return data;
}
