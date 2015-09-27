/*
 * led_driver.h
 *
 *  Created on: Nov 25, 2014
 *      Author: Michal
 */

#ifndef LED_DRIVER_H_
#define LED_DRIVER_H_

#include "own_timer.h"

#define CLK 2
#define OE 5

#define SDI_2 0
#define LE_2 1

#define LE_1 4
#define SDI_1 3

void send_LED_char(char data , int sdi, int le)
{
	int i=0;

	PORTB|=(1<<le);
	for(i=0;i<8;i++)
	{
		if(data&(1<<i))
		{
			PORTB|=(1<<sdi);
			czas_us(1);
			PORTB|=(1<<CLK);
			czas_us(1);
			PORTB&=~(1<<sdi);
			czas_us(1);
			PORTB&=~(1<<CLK);
			czas_us(1);
		}
		else
			{
			PORTB|=(1<<CLK);
			czas_us(2);
			PORTB&=~(1<<CLK);
			czas_us(2);
			}
	}

czas_us(200);
	PORTB&=~(1<<le);


}



#endif /* LED_DRIVER_H_ */
