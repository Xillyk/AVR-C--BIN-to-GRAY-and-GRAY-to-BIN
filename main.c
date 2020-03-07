/*
 * ch6-2.c
 *
 * Created: 7/3/2563 13:07:43
 * Author : Pitchapong Charmtong
 */ 

#include <avr/io.h>

int main(void)
{
	DDRB = 0X00;
	DDRC = 0XFE;
	DDRD = 0XFF;
    
	uint8_t sw1, sw2, value = 0, tmp, i;

    while (1) 
    {
		sw1 = PINB;
		sw2 = PINC;
		sw2 &= 0X01;
		
		value = sw1;
		
		if(sw2 == 1)
		{
			tmp = value >> 1;
			value ^= tmp;
		}
		else
		{
			tmp = value;

 			for(i = 0; i < 7; i++)
 			{
				tmp = tmp >> 1;
				tmp ^= value;
			}
			value = tmp;
		}
		PORTD = value;
    }
}

