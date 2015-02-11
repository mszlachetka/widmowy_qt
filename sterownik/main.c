/*
 * main.c
 *
 *  Created on: Oct 28, 2014
 *      Author: Michal
 */
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "own_timer.h"
#include "led_driver.h"



char dane[2][360];
volatile int usart_flag=0;
char usart_bufor=0;


void USARTInit(uint16_t ubrr_value)
{
   //Set Baud rate

   UBRRL = ubrr_value;
   UBRRH = (ubrr_value>>8);

   /*Set Frame Format
   >> Asynchronous mode
   >> No Parity
   >> 1 StopBit
   >> char size 8*/

   UCSRC=(1<<URSEL)|(3<<UCSZ0);
   //Enable The receiver and transmitter


 //  UCSRB |= (1 << RXCIE);

   UCSRB=(1<<RXEN)|(1<<TXEN);
}

char USARTReadChar()
{

   //Wait untill a data is available
   while(!(UCSRA & (1<<RXC)))
   {

      //Do nothing
   }

   //Now USART has got data from host
   //and is available is buffer
   return UDR;
}

void USARTWriteChar(char data)
{
   //Wait untill the transmitter is ready

   while(!(UCSRA & (1<<UDRE)))
   {
      //Do nothing
   }


   //Now write the data to USART buffer

   UDR=data;
}

/*ISR(USART_RXC_vect)
{
usart_bufor=USARTReadChar;
USARTWriteChar(usart_bufor);
usart_flag=1;
}*/

int main(void)
{
	sei();
	char data=0;
USARTInit(51);
DDRB = 0xff;
timer0_init();
 int actual_row=0;
 int actual_angle=0;

int i;
for(i=0;i<360;i++)
{
	dane[0][i]=255;
	dane[1][i]=255;
}

PORTB|=(1<<OE);

/*while (1)
{

	/*if(usart_flag==1)
	{
		cli();
		dane[actual_row][actual_angle]=usart_bufor;
		USARTWriteChar(dane[actual_row][actual_angle]);
		usart_flag=0;
		if(actual_row==0) actual_row++;
		if(actual_row==1)
		{
			actual_row=0;
			actual_angle++;
		}
		if(actual_angle==359 && actual_row==1)
		{
			actual_angle=0;
			actual_row=0;
		}
		sei();
	}

int i;*/
	/*for(i=0;i<360;i++)
	{
		send_LED_char(dane[0][i],SDI_1,LE_1);
		send_LED_char(dane[1][i],SDI_2,LE_2);
		PORTB&=~(1<<OE);
		czas_ms(1);
		//PORTB|=(1<<OE);
		//czas_ms(1);
	}




}*/

while(1)
{

 data=USARTReadChar;
send_LED_char(data,SDI_1,LE_1);
send_LED_char(data,SDI_2,LE_2);

PORTB&=~(1<<OE);

   czas_ms(1000);
   PORTB|=(1<<OE);
   czas_ms(1000);

}
    return 0;
}


