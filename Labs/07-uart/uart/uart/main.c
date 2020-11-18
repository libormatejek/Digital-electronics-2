/***********************************************************************
 * 
 * Analog-to-digital conversion with displaying result on LCD and 
 * transmitting via UART.
 * ATmega328P (Arduino Uno), 16 MHz, AVR 8-bit Toolchain 3.6.2
 *
 * Copyright (c) 2018-2020 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 **********************************************************************/

/* Includes ----------------------------------------------------------*/

#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC
#include "timer.h"          // Timer library for AVR-GCC
#include "lcd.h"            // Peter Fleury's LCD library
#include <stdlib.h>         // C library. Needed for conversion function
#include "uart.h"           // Peter Fleury's UART library

#ifndef F_CPU
#define F_CPU 16000000
#endif

/* Function definitions ----------------------------------------------*/
/**
 * Main function where the program execution begins. Use Timer/Counter1
 * and start ADC conversion four times per second. Send value to LCD
 * and UART.
 */
int main(void)
{
    // Initialize LCD display
    lcd_init(LCD_DISP_ON);
    lcd_gotoxy(1, 0); lcd_puts("value:");
    lcd_gotoxy(1, 1); lcd_puts("key:");
    
    // Configure ADC to convert PC0[A0] analog value
	
    // Set ADC reference to AVcc
	ADMUX |= (1<<REFS0);
	ADMUX &= ~(1<<REFS1);
    // Set input channel to ADC0
	ADMUX &= ~((1<<MUX0)|(1<<MUX1)|(1<<MUX2)|(1<<MUX3));
	
    // Enable ADC module
	ADCSRA |= (1<<ADEN);
    // Enable conversion complete interrupt
	ADCSRA |= (1<<ADIE);
    // Set clock prescaler to 128
	ADCSRA |= ((1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2));
	

    // Configure 16-bit Timer/Counter1 to start ADC conversion
	
	
    // Enable interrupt and set the overflow prescaler to 262 ms
	TIM1_overflow_interrupt_enable();
	TIM1_overflow_262ms();

    // Initialize UART to asynchronous, 8N1, 9600
	uart_init(UART_BAUD_SELECT(9600,F_CPU));

    // Enables interrupts by setting the global interrupt mask
    sei();

    // Infinite loop
    while (1)
    {
        /* Empty loop. All subsequent operations are performed exclusively 
         * inside interrupt service routines ISRs */
    }

    // Will never reach this
    return 0;
}

/* Interrupt service routines ----------------------------------------*/
/**
 * ISR starts when Timer/Counter1 overflows. Use single conversion mode
 * and start conversion four times per second.
 */
ISR(TIMER1_OVF_vect)
{
    // Start ADC conversion
	ADCSRA |= (1<<ADSC);

}

/* -------------------------------------------------------------------*/
/**
 * ISR starts when ADC completes the conversion. Display value on LCD
 * and send it to UART.
 */
ISR(ADC_vect)
{
	int16_t value = ADC;
	char lcd_string[8] ="        ";
	

	 itoa(value, lcd_string, 10); // value to dacimal
     lcd_gotoxy(8, 0);
	 lcd_puts("    "); //clear area
	 lcd_gotoxy(8, 0);
	 lcd_puts(lcd_string); // show decimal
	 
	 if (value < 700) // reduce amount of sent uart data
	 {
	 uart_puts("ADC value in decimal:");
	 uart_puts(lcd_string); // send uart value in decimal
	 uart_puts("\n");
	 }
	 
	 
	 lcd_gotoxy(13, 0);
	 lcd_puts("   ");
	 itoa(value, lcd_string, 16); // value to hexa
	 lcd_gotoxy(13, 0);
	 lcd_puts(lcd_string); // show value in hexa
	 
	 lcd_gotoxy(13, 1);
	 lcd_puts("p:");
	 
	 if(value %2 == 0) // get parity 
	 {
		lcd_gotoxy(15,1);
		lcd_puts("1");
	}
	else
	{
		lcd_gotoxy(15,1);
		lcd_puts("0");
	}
	 
	 lcd_gotoxy(6, 1);
	 lcd_puts("      "); // clear key type area
	 lcd_gotoxy(6, 1);
	 
	 //Print key - type of key conditions
	 
	 if(value == 0)
	 {
		 lcd_puts("Right");
		 lcd_gotoxy(6, 1);
		
	 }
	 
	 if(90<value && value<150)
	 {
		 lcd_puts("Up");
		 lcd_gotoxy(6, 1);
	
	 }
	 if(240<value && value<280)
	 {
		 lcd_puts("Down");
		 lcd_gotoxy(6, 1);
		 
	 }
	 if(395<value && value<450)
	 {
		 lcd_puts("Left");
		 lcd_gotoxy(6, 1);
		 
	 }
	 if(640<value && value<700)
	 {
		 lcd_puts("Select");
		 lcd_gotoxy(6, 1);
		 
	 }
	 if(value > 1016)
	 {
		 
		 lcd_puts("None");
		 lcd_gotoxy(6, 1);
		 }
	 
	 

}