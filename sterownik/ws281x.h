/*
 * ws281x.h
 *
 *  Created on: 17 lip 2015
 *      Author: Michal
 */

#ifndef WS281X_H_
#define WS281X_H_

#define WS_PIN_NR PB0
#define WS_PIN (1<<WS_PIN_NR)
#define WS_PIN_NR2 PB1
#define WS_PIN2 (1<<WS_PIN_NR2)

#define WS_PORT PORTB
#define WS_DIR DDRB

#define WS_LED_CNT 30
typedef struct
{
   uint8_t g;
    uint8_t r;
    uint8_t b;
} rgb;


void ws281x_asm_send( void *data, uint16_t datlen, uint8_t pin )
{

	uint8_t databyte=0, cnt, pinLO=~pin;
	WS_DIR |= pin;
	datlen *= 3;


	asm volatile(
	"		lds		%[cnt],%[ws_port]	\n\t"
	"		or		%[pinHI],%[cnt]		\n\t"
	"		and		%[pinLO],%[cnt]		\n\t"
	"mPTL%=:subi	%A6,1				\n\t"
	"		sbci	%B6,0				\n\t"
	"		brcs	exit%=				\n\t"
	"		ld		%[databyte],X+		\n\t"
	"		ldi		%[cnt],8			\n\t"

	"oPTL%=:sts		%[ws_port],	%[pinHI]	\n\t"
			"		rjmp .+0				\n\t"

	"		lsl		%[databyte]			\n\t"
	"		brcs	.+2					\n\t"
	"		sts		%[ws_port],	%[pinLO]\n\t"
			"		rjmp .+0					\n\t"
			"		rjmp .+0				\n\t"

	"		dec		%[cnt]					\n\t"
	"		sts		%[ws_port],	%[pinLO]\n\t"
	"		breq	mPTL%=				\n\t"
			"		rjmp .+0					\n\t"

	"		rjmp	oPTL%=				\n\t"
	"exit%=:							\n\t"
	:	[cnt]"=&d" (cnt)
	:	[databyte]"r" (databyte), [ws_port]"M" (_SFR_MEM_ADDR(WS_PORT)),
	 	[pinHI]"r" (pin), [pinLO]"r" (pinLO), [data]"x" (data), [datlen]"r" (datlen)
	);
}


#endif /* WS281X_H_ */
