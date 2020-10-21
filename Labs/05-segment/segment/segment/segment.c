/***********************************************************************
 * 
 * Seven-segment display library for AVR-GCC.
 * ATmega328P (Arduino Uno), 16 MHz, AVR 8-bit Toolchain 3.6.2
 *
 * Copyright (c) 2019-2020 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 *
 **********************************************************************/

/* Includes ----------------------------------------------------------*/
#include <util/delay.h>
#include "gpio.h"
#include "segment.h"

/* Function definitions ----------------------------------------------*/
void SEG_init(void)
{
    /* Configuration of SSD signals */
    GPIO_config_output(&DDRD, SEGMENT_LATCH);
    GPIO_config_output(&DDRD, SEGMENT_CLK);
    GPIO_config_output(&DDRB, SEGMENT_DATA);
}

/*--------------------------------------------------------------------*/
void SEG_update_shift_regs(uint8_t segments, uint8_t position)
{
    uint8_t bit_number;

    // Pull LATCH, CLK, and DATA low
GPIO_write_low(&PORTD,SEGMENT_LATCH);
GPIO_write_low(&PORTD,SEGMENT_CLK);
GPIO_write_low(&PORTB,SEGMENT_DATA);
    // Wait 1 us
_delay_ms(1000);
    // Loop through the 1st byte (segments)
    // a b c d e f g DP (active low values)
    for (bit_number = 0; bit_number < 8; bit_number++)
    {
        // Output DATA value (bit 0 of "segments")
			if(segments[bit_number] == 1){
					// Wait 1 us
			_delay_ms(1000);
					// Pull CLK high
			GPIO_write_high(&PORTD,SEGMENT_CLK);
					// Wait 1 us
			_delay_ms(1000);
					// Pull CLK low
			GPIO_write_low(&PORTD,SEGMENT_CLK);
					// Shift "segments"
					segments = segments >> 1;
	}
				}

    // Loop through the 2nd byte (position)
    // p3 p2 p1 p0 . . . . (active high values)
    for (bit_number = 0; bit_number < 8; bit_number++)
    {
        // Output DATA value (bit 0 of "position")
			if(position[bit_number]=1){
			_delay_ms(1000);
			// Pull CLK high
			GPIO_write_high(&PORTD,SEGMENT_CLK);
			// Wait 1 us
			_delay_ms(1000);
			// Pull CLK low
			GPIO_write_low(&PORTD,SEGMENT_CLK);
			// Shift "segments"
			segments = segments >> 1;
	}
       // Shift "position"
		     position = position >> 1;
    }

    // Pull LATCH high
			GPIO_write_high(&PORTD,SEGMENT_LATCH);

    // Wait 1 us

}

/*--------------------------------------------------------------------*/
/* SEG_clear */
SEG_clear();
/*--------------------------------------------------------------------*/
/* SEG_clk_2us */
SEG_clk_2us();