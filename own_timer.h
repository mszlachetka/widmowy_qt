/*
 * own_timer.h
 *
 *  Created on: Nov 25, 2014
 *      Author: Michal
 */

#ifndef OWN_TIMER_H_
#define OWN_TIMER_H_

volatile int pomiarczasu=0;

void czas_ms(int czas)
{
   pomiarczasu=0;
   while(4*czas>pomiarczasu)
   {

   }
   pomiarczasu=0;
}

void czas_us(int czas)
{
    pomiarczasu=0;
    TCNT0=0;
   while(czas>256*pomiarczasu+TCNT0)
   {

   }
   pomiarczasu=0;
   TCNT0=0;
}

ISR(TIMER0_OVF_vect)
{
     pomiarczasu++;
}

void timer0_init()
{
	 TIMSK |= (1<<TOIE0);
	    TCCR0 |= (0<<CS02)|(0<<CS01)|(1<<CS00);//timer0 mierzy czas
}

#endif /* OWN_TIMER_H_ */
