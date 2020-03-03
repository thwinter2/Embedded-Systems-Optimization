#include <MKL25Z4.H>
#include "LEDs.h"
#include "gpio_defs.h"

void Init_RGB_LEDs(void) {
	// Enable clock to ports B and D
	SIM->SCGC5 |= SIM_SCGC5_PORTB_MASK | SIM_SCGC5_PORTD_MASK;;
	
	// Make 3 pins GPIO
	PORTB->PCR[RED_LED_POS] &= ~PORT_PCR_MUX_MASK;          
	PORTB->PCR[RED_LED_POS] |= PORT_PCR_MUX(1);          
	PORTB->PCR[GREEN_LED_POS] &= ~PORT_PCR_MUX_MASK;          
	PORTB->PCR[GREEN_LED_POS] |= PORT_PCR_MUX(1);          
	PORTD->PCR[BLUE_LED_POS] &= ~PORT_PCR_MUX_MASK;          
	PORTD->PCR[BLUE_LED_POS] |= PORT_PCR_MUX(1);          
	
	// Set ports to outputs
	FPTB->PDDR |= MASK(RED_LED_POS) | MASK(GREEN_LED_POS);
	FPTD->PDDR |= MASK(BLUE_LED_POS);
}

void Control_RGB_LEDs(unsigned int red_on, unsigned int green_on, unsigned int blue_on) {
	if (red_on) {
			FPTB->PCOR = MASK(RED_LED_POS);
	} else {
			FPTB->PSOR = MASK(RED_LED_POS); 
	}
	if (green_on) {
			FPTB->PCOR = MASK(GREEN_LED_POS);
	}	else {
			FPTB->PSOR = MASK(GREEN_LED_POS); 
	} 
	if (blue_on) {
			FPTD->PCOR = MASK(BLUE_LED_POS);
	}	else {
			FPTD->PSOR = MASK(BLUE_LED_POS); 
	}
}	
