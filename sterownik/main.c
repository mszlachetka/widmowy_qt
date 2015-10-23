#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "ws281x.h"
#include "eeprom_spi.h"

#define ROWS_CNT 120
#define FINAL_ADDRESS ROWS_CNT*128
#define START_ADDRESS 0
#define SNAKE_SIZE 3
#define SNAKE_INTERVAL 3
#define DELAY_WATCH_US 3

#define SWITCH_INTERVAL_MIN  180 //w us  //180 IDEALNIE PRZY KODZIE Z 27.08.15

volatile unsigned int read_status=0;
#define READ_WAIT 0 //sprawdzenie
#define READ_READY 1 //w gotowosci

volatile unsigned int address=0; //adres wyswietlany
volatile unsigned int address2=128*60;
volatile unsigned int write_address=0; //adres wczytywyany USART
volatile unsigned char temp_read_data=0; //wartosc wczytana USART
volatile unsigned int temp_data_counter=0;

volatile unsigned int us_interval_time=SWITCH_INTERVAL_MIN; //czas pomiedzy ledami ,
										// niweluje wplyw zmiany predkosci
rgb tled[WS_LED_CNT];
rgb tled2[WS_LED_CNT];
uint8_t* wsk_tled= (uint8_t*)tled;

void rainbow(int led_cnt,int interval, int snake_size, int start_address);
void save_eeprom(int address, uint8_t led_cnt, rgb *tled);
void load_eeprom(int address, uint8_t led_cnt, rgb *tled);

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


   UCSRB |= (1 << RXCIE);

   UCSRB |=(1<<RXEN)|(1<<TXEN);
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

void ext_interrupt_init()
{
		MCUCR|=(1<<ISC01);
		GICR |= (1 << INT0);

		DDRD &= ~(1<<PD2);
		PORTD |= (1 << PORTD2);
}

ISR (INT0_vect)
{
	//zwieksz lub zmniejsz przerwy jesli zle kolko wyszlo
	if(address<FINAL_ADDRESS && us_interval_time>5)
		{
		if(ROWS_CNT*128-address<5*128+1) us_interval_time-=5;
		else if(us_interval_time>30) us_interval_time-=30;
		//us_interval_time*=(float)(address/FINAL_ADDRESS);
		}
	else if(address>FINAL_ADDRESS)
		{
		if(address-ROWS_CNT*128<5*128+1) us_interval_time+=10; //tu bardziej
		else us_interval_time+=30;
		//us_interval_time*=(float)(address/FINAL_ADDRESS);

		}

    address=START_ADDRESS;
    address2=START_ADDRESS+FINAL_ADDRESS/2;
    PORTC^=255;
}

ISR(USART_RXC_vect)
{
	temp_read_data=USARTReadChar();



	if(read_status==READ_WAIT)//znak poczatku
	{
		if(temp_read_data==255)
		{
			read_status=READ_READY;
			write_address=0;
			wsk_tled= (uint8_t*)tled;
			temp_data_counter=0;

		}
	}
		else if(read_status==READ_READY) //wczytaj wszystko
	{

			PORTC^=255;
		*wsk_tled=temp_read_data;
		wsk_tled++;
		temp_data_counter++;


		if(temp_data_counter==WS_LED_CNT*3) //wczytano caly rzad
		{
		save_eeprom(write_address,WS_LED_CNT, tled);

		wsk_tled= (uint8_t*)tled;
		temp_data_counter=0;
		write_address+=128; // zapisane 2 strony = 2*64
		USARTWriteChar(255); //zwrotne

		if(write_address==FINAL_ADDRESS)//wczytano ostatni rzad
		{

			int i=0;

			/*for(i=0;i<WS_LED_CNT;i++)
			{
				tled[i].g=0;
				tled[i].r=0;
				tled[i].b=0;
			}*/
			for(i=0;i<30;i++)
			{
			save_eeprom(write_address,WS_LED_CNT,tled);
			write_address+=128;//30  razy ostatni pusty rzad dla bezpieczenstwa
			//w sumie 30 rzedow
			}

			read_status=READ_WAIT;

		}

	}

	}

}

int main()
{

	DDRC |=0xff;
	PORTC=15;
	_delay_ms(1000);

sei();
SPI_MasterInit();
ext_interrupt_init();
USARTInit(416);

CLR_CS;
SPI_MasterTransmit(EEPROM_WRITE_ENABLE);
SET_CS;

_delay_ms(1000);

uint8_t row=0;
//int i=0;

address=0;
//int i=0;
/*for(row=0;row<ROWS_CNT;row++)//tymczasowe
{
	if(row<=40)
		{
		for(i=0;i<WS_LED_CNT;i++)
		{
		tled[i].r=125;
		tled[i].g=0;
		tled[i].b=0;

		}
		}
	else if(40<row && row<80)
	{
	for(i=0;i<WS_LED_CNT;i++)
	{
	tled[i].r=0;
	tled[i].g=0;
	tled[i].b=125;
	}
	}
	else
	{
	for(i=0;i<WS_LED_CNT;i++)
		{
		tled[i].r=0;
		tled[i].g=125;
		tled[i].b=0;

		}
	}
	save_eeprom(address,WS_LED_CNT);
	address+=64;
	_delay_ms(20);
}*/

//rainbow(WS_LED_CNT,SNAKE_INTERVAL,SNAKE_SIZE,START_ADDRESS); // tworzy tecze , zapisuje ja od adresu w eeprom
            												// co rzad zmienia strone (64 bytes)
															//rzedow tyle co ledow
															//ledow maks 21
															//interval>size zeby bylo widac ruch


address=START_ADDRESS;
address=START_ADDRESS+FINAL_ADDRESS/2;

int j=0;
	while(1)
	{

	    if(address<(FINAL_ADDRESS+128*30))
			    	{
		//address=START_ADDRESS; //niech przerwanie zeruje
		for(row=0;row<ROWS_CNT/*-ROWS_CNT%SNAKE_INTERVAL*/;row++)
				{
				load_eeprom(address,WS_LED_CNT, tled);//pierwsze ledy

				ws281x_asm_send(tled,WS_LED_CNT,WS_PIN);



				if(address2>FINAL_ADDRESS) address2=address2-FINAL_ADDRESS;
				load_eeprom(address2,WS_LED_CNT, tled);

				ws281x_asm_send(tled,WS_LED_CNT,WS_PIN2);

				address+=128;//ogolny adres odniesienia podstawowy
				address2+=128;
				for(j=0;j<us_interval_time;j++)//zmienny delay_us
				{
				_delay_us(8);
				}

				}
			    	}


		}


	return 0;

}

void rainbow(int led_cnt,int interval, int snake_size, int start_address)
{

int j=0;
int k=0;
int row=0;
int address=start_address;

int coeff=240/led_cnt; //troche mniejszy wspolczynnik

for(row=0;row<led_cnt;row++) // jezdzaca tecza ustalam ile i co ile
{

for(j=0;j<led_cnt+snake_size;j++)
{

	if((j-(row%interval))%interval==0) //row==j narastajaca tecza //liczba oznacza %ile wedrujo
		{
		if(j<led_cnt/2) // tecza
	{
			if(j<led_cnt)
			{
		tled[j].b=0;
		tled[j].g=2*j*coeff;
		tled[j].r=255-j*2*coeff;
			}

			if(j>snake_size)
			{
			for(k=j-snake_size;k<j;k++)
			{
				if(k>=0)
				{
				tled[k].b=0;
				tled[k].g=2*k*coeff;
				tled[k].r=255-k*2*coeff;
				}

			}
			}
			else
			{
				for(k=0;k<j;k++)
						{

							tled[k].b=0;
							tled[k].g=k*2*coeff;
							tled[k].r=255-k*2*coeff;
						}
			}
	}
	else
	{
		if(j<led_cnt)
					{
				tled[j].r=0;
				tled[j].b=coeff*(j-led_cnt/2);
				tled[j].g=255-j*coeff;
					}
							for(k=j-snake_size;k<j;k++)
							{

								if(k>=0 && k<led_cnt/2)
								{
									tled[k].b=0;
									tled[k].g=k*2*coeff;
									tled[k].r=255-k*2*coeff;
								}
								else if (k>=0 && k>=led_cnt/2)
								{

												tled[k].r=0;
												tled[k].b=coeff*(k-led_cnt/2);
												tled[k].g=(coeff*led_cnt)-k*coeff;
								}

							}


	}
		}
	else // dolaczyc do row==j i bedzie jeden element wedrujacy
	{
		if(j<led_cnt)
					{
			tled[j].b=0;
			tled[j].g=0;
			tled[j].r=0;
					}
	}

}

		save_eeprom(address,led_cnt,tled);
		address+=64;
}

}

void save_eeprom(int address, uint8_t led_cnt, rgb *tled)
{
	int i=0;
	CLR_CS;
	SPI_MasterTransmit(EEPROM_WRITE_ENABLE);
	SET_CS;

									CLR_CS;
									SPI_MasterTransmit(EEPROM_WRITE);
									SPI_MasterTransmit((uint8_t)(address>>8));
									SPI_MasterTransmit((uint8_t)address);
									for(i=0;i<led_cnt;i++)
									{
									SPI_MasterTransmit(tled[i].g);
									SPI_MasterTransmit(tled[i].r);
									SPI_MasterTransmit(tled[i].b);
									}
									SET_CS;
									_delay_ms(20);





}

void load_eeprom(int address, uint8_t led_cnt, rgb *tled)
{

	int i=0;

									CLR_CS;
									SPI_MasterTransmit(EEPROM_READ);
									SPI_MasterTransmit((uint8_t)(address>>8));
									SPI_MasterTransmit((uint8_t)address);

									for(i=0;i<led_cnt;i++)
									{
										tled[i].g=SPI_MasterTransmit(0);
										tled[i].r=SPI_MasterTransmit(0);
										tled[i].b=SPI_MasterTransmit(0);
									}

									SET_CS;




}


