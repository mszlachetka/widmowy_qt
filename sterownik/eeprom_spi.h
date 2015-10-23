#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define SET_CS PORTB|=(1<<PB2)
#define CLR_CS PORTB&=~(1<<PB2)

#define EEPROM_WRITE_ENABLE 6
#define EEPROM_WRITE_DISABLE 4
#define EEPROM_READ 3
#define EEPROM_WRITE 2


void SPI_MasterInit(void)
{
DDRB |=(1<<PB2);
DDRB |= (1<<PB3)|(1<<PB5);
SPCR = (1<<SPE)|(1<<MSTR);
}

inline uint8_t SPI_MasterTransmit(uint8_t cData)
{
SPDR = cData;
while
(!(SPSR & (1<<SPIF)));
return SPDR;
}
