
#include "debug.h"
#include<MKL25Z4.h>

void Init_Debug_Signals(void) {
	// Enable clock to port B
	SIM->SCGC5 |= SIM_SCGC5_PORTB_MASK;
	SIM->SCGC5 |= SIM_SCGC5_PORTC_MASK;
	SIM->SCGC5 |= SIM_SCGC5_PORTD_MASK;
	SIM->SCGC5 |= SIM_SCGC5_PORTE_MASK;
	// Make pins GPIO
	PORTB->PCR[DBG_0] &= ~PORT_PCR_MUX_MASK;          
	PORTB->PCR[DBG_0] |= PORT_PCR_MUX(1);   
	PORTB->PCR[DBG_1] &= ~PORT_PCR_MUX_MASK;          
	PORTB->PCR[DBG_1] |= PORT_PCR_MUX(1);          
	PORTB->PCR[DBG_2] &= ~PORT_PCR_MUX_MASK;          
	PORTB->PCR[DBG_2] |= PORT_PCR_MUX(1);          
	PORTB->PCR[DBG_3] &= ~PORT_PCR_MUX_MASK;          
	PORTB->PCR[DBG_3] |= PORT_PCR_MUX(1);          
	PORTB->PCR[DBG_4] &= ~PORT_PCR_MUX_MASK;          
	PORTB->PCR[DBG_4] |= PORT_PCR_MUX(1);          
	PORTB->PCR[DBG_5] &= ~PORT_PCR_MUX_MASK;          
	PORTB->PCR[DBG_5] |= PORT_PCR_MUX(1);          
	PORTB->PCR[DBG_6] &= ~PORT_PCR_MUX_MASK;          
	PORTB->PCR[DBG_6] |= PORT_PCR_MUX(1);          
	PORTB->PCR[DBG_7] &= ~PORT_PCR_MUX_MASK;          
	PORTB->PCR[DBG_7] |= PORT_PCR_MUX(1);    
	
	// Uncomment if using Port C
/* 
	//Port C

	PORTC->PCR[DBG_0] &= ~PORT_PCR_MUX_MASK;          
	PORTC->PCR[DBG_0] |= PORT_PCR_MUX(1);  
	PORTC->PCR[DBG_1] &= ~PORT_PCR_MUX_MASK;          
	PORTC->PCR[DBG_1] |= PORT_PCR_MUX(1);          
	PORTC->PCR[DBG_2] &= ~PORT_PCR_MUX_MASK;          
	PORTC->PCR[DBG_2] |= PORT_PCR_MUX(1);          
	PORTC->PCR[DBG_3] &= ~PORT_PCR_MUX_MASK;          
	PORTC->PCR[DBG_3] |= PORT_PCR_MUX(1);          
	PORTC->PCR[DBG_4] &= ~PORT_PCR_MUX_MASK;          
	PORTC->PCR[DBG_4] |= PORT_PCR_MUX(1);          
	PORTC->PCR[DBG_5] &= ~PORT_PCR_MUX_MASK;          
	PORTC->PCR[DBG_5] |= PORT_PCR_MUX(1);          
	PORTC->PCR[DBG_6] &= ~PORT_PCR_MUX_MASK;          
	PORTC->PCR[DBG_6] |= PORT_PCR_MUX(1);          
	PORTC->PCR[DBG_7] &= ~PORT_PCR_MUX_MASK;          
	PORTC->PCR[DBG_7] |= PORT_PCR_MUX(1); 
	PORTC->PCR[DBG_CD_4] &= ~PORT_PCR_MUX_MASK;          
	PORTC->PCR[DBG_CD_4] |= PORT_PCR_MUX(1);
	PORTC->PCR[DBG_CD_5] &= ~PORT_PCR_MUX_MASK;          
	PORTC->PCR[DBG_CD_5] |= PORT_PCR_MUX(1);
	PORTC->PCR[DBG_CD_6] &= ~PORT_PCR_MUX_MASK;          
	PORTC->PCR[DBG_CD_6] |= PORT_PCR_MUX(1);
	PORTC->PCR[DBG_CD_7] &= ~PORT_PCR_MUX_MASK;          
	PORTC->PCR[DBG_CD_7] |= PORT_PCR_MUX(1);
	PORTC->PCR[DBG_C_12] &= ~PORT_PCR_MUX_MASK;          
	PORTC->PCR[DBG_C_12] |= PORT_PCR_MUX(1);
*/		
	
	
	// Uncomment if using Port D
/*
	//Port D

	PORTD->PCR[DBG_0] &= ~PORT_PCR_MUX_MASK;          
	PORTD->PCR[DBG_0] |= PORT_PCR_MUX(1); 
	PORTD->PCR[DBG_1] &= ~PORT_PCR_MUX_MASK;          
	PORTD->PCR[DBG_1] |= PORT_PCR_MUX(1);          
	PORTD->PCR[DBG_2] &= ~PORT_PCR_MUX_MASK;          
	PORTD->PCR[DBG_2] |= PORT_PCR_MUX(1);          
	PORTD->PCR[DBG_3] &= ~PORT_PCR_MUX_MASK;          
	PORTD->PCR[DBG_3] |= PORT_PCR_MUX(1);          
	PORTD->PCR[DBG_4] &= ~PORT_PCR_MUX_MASK;          
	PORTD->PCR[DBG_4] |= PORT_PCR_MUX(1);          
	PORTD->PCR[DBG_5] &= ~PORT_PCR_MUX_MASK;          
	PORTD->PCR[DBG_5] |= PORT_PCR_MUX(1);          
	PORTD->PCR[DBG_6] &= ~PORT_PCR_MUX_MASK;          
	PORTD->PCR[DBG_6] |= PORT_PCR_MUX(1);          
	PORTD->PCR[DBG_7] &= ~PORT_PCR_MUX_MASK;          
	PORTD->PCR[DBG_7] |= PORT_PCR_MUX(1);
	PORTD->PCR[DBG_CD_4] &= ~PORT_PCR_MUX_MASK;          
	PORTD->PCR[DBG_CD_4] |= PORT_PCR_MUX(1);
	PORTD->PCR[DBG_CD_5] &= ~PORT_PCR_MUX_MASK;          
	PORTD->PCR[DBG_CD_5] |= PORT_PCR_MUX(1);
	PORTD->PCR[DBG_CD_6] &= ~PORT_PCR_MUX_MASK;          
	PORTD->PCR[DBG_CD_6] |= PORT_PCR_MUX(1);
	PORTD->PCR[DBG_CD_7] &= ~PORT_PCR_MUX_MASK;          
	PORTD->PCR[DBG_CD_7] |= PORT_PCR_MUX(1);
*/

// Uncomment if using Port A
	/*
//Port A
	PORTA->PCR[DBG_0] &= ~PORT_PCR_MUX_MASK;          
	PORTA->PCR[DBG_0] |= PORT_PCR_MUX(1);
	PORTA->PCR[DBG_1] &= ~PORT_PCR_MUX_MASK;          
	PORTA->PCR[DBG_1] |= PORT_PCR_MUX(1);          
	PORTA->PCR[DBG_2] &= ~PORT_PCR_MUX_MASK;          
	PORTA->PCR[DBG_2] |= PORT_PCR_MUX(1);          
	PORTA->PCR[DBG_3] &= ~PORT_PCR_MUX_MASK;          
	PORTA->PCR[DBG_3] |= PORT_PCR_MUX(1);          
	PORTA->PCR[DBG_4] &= ~PORT_PCR_MUX_MASK;          
	PORTA->PCR[DBG_4] |= PORT_PCR_MUX(1);          
	PORTA->PCR[DBG_5] &= ~PORT_PCR_MUX_MASK;          
	PORTA->PCR[DBG_5] |= PORT_PCR_MUX(1);          
	PORTA->PCR[DBG_6] &= ~PORT_PCR_MUX_MASK;          
	PORTA->PCR[DBG_6] |= PORT_PCR_MUX(1);          
	PORTA->PCR[DBG_7] &= ~PORT_PCR_MUX_MASK;          
	PORTA->PCR[DBG_7] |= PORT_PCR_MUX(1);
	*/

	//Port E
	PORTE->PCR[DBG_0] &= ~PORT_PCR_MUX_MASK;          
	PORTE->PCR[DBG_0] |= PORT_PCR_MUX(1); 
	PORTE->PCR[DBG_1] &= ~PORT_PCR_MUX_MASK;          
	PORTE->PCR[DBG_1] |= PORT_PCR_MUX(1);          
	PORTE->PCR[DBG_2] &= ~PORT_PCR_MUX_MASK;          
	PORTE->PCR[DBG_2] |= PORT_PCR_MUX(1);          
	PORTE->PCR[DBG_3] &= ~PORT_PCR_MUX_MASK;          
	PORTE->PCR[DBG_3] |= PORT_PCR_MUX(1);          
	PORTE->PCR[DBG_4] &= ~PORT_PCR_MUX_MASK;          
	PORTE->PCR[DBG_4] |= PORT_PCR_MUX(1);          
	PORTE->PCR[DBG_5] &= ~PORT_PCR_MUX_MASK;          
	PORTE->PCR[DBG_5] |= PORT_PCR_MUX(1);          
	PORTE->PCR[DBG_6] &= ~PORT_PCR_MUX_MASK;          
	PORTE->PCR[DBG_6] |= PORT_PCR_MUX(1);          
	PORTE->PCR[DBG_7] &= ~PORT_PCR_MUX_MASK;          
	PORTE->PCR[DBG_7] |= PORT_PCR_MUX(1);
	
	// Set ports to outputs
	PTB->PDDR |= MASK(DBG_0) | MASK(DBG_1) | MASK(DBG_2) | MASK(DBG_3) | MASK(DBG_4) | MASK(DBG_5) | MASK(DBG_6) | MASK(DBG_7);
	PTC->PDDR |= MASK(DBG_0) | MASK(DBG_1) | MASK(DBG_2) | MASK(DBG_3) | MASK(DBG_4) | MASK(DBG_5) | MASK(DBG_6) | MASK(DBG_7);//| MASK(DBG_CD_4) | MASK(DBG_CD_5) | MASK(DBG_CD_6) | MASK(DBG_CD_7) | MASK(DBG_C_12);
	PTA->PDDR |= MASK(DBG_0) | MASK(DBG_1) | MASK(DBG_2) | MASK(DBG_3) | MASK(DBG_4) | MASK(DBG_5) | MASK(DBG_6) | MASK(DBG_7);
	PTD->PDDR |= MASK(DBG_0) | MASK(DBG_1) | MASK(DBG_2) | MASK(DBG_3) | MASK(DBG_4) | MASK(DBG_5) | MASK(DBG_6) | MASK(DBG_7)| MASK(DBG_CD_4) | MASK(DBG_CD_5) | MASK(DBG_CD_6) | MASK(DBG_CD_7);
	PTE->PDDR |= MASK(DBG_0) | MASK(DBG_1) | MASK(DBG_2) | MASK(DBG_3) | MASK(DBG_4) | MASK(DBG_5) | MASK(DBG_6) | MASK(DBG_7);
	// Initial values are 0
	PTB->PCOR = MASK(DBG_0) | MASK(DBG_1) | MASK(DBG_2) | MASK(DBG_3) | MASK(DBG_4) | MASK(DBG_5) | MASK(DBG_6) | MASK(DBG_7);
	PTC->PCOR = MASK(DBG_0) | MASK(DBG_1) | MASK(DBG_2) | MASK(DBG_3) | MASK(DBG_4) | MASK(DBG_5) | MASK(DBG_6) | MASK(DBG_7);//| MASK(DBG_CD_4) | MASK(DBG_CD_5) | MASK(DBG_CD_6) | MASK(DBG_CD_7) | MASK(DBG_C_12);
	PTA->PCOR = MASK(DBG_0) | MASK(DBG_1) | MASK(DBG_2) | MASK(DBG_3) | MASK(DBG_4) | MASK(DBG_5) | MASK(DBG_6) | MASK(DBG_7);
	PTD->PCOR = MASK(DBG_0) | MASK(DBG_1) | MASK(DBG_2) | MASK(DBG_3) | MASK(DBG_4) | MASK(DBG_5) | MASK(DBG_6) | MASK(DBG_7)| MASK(DBG_CD_4) | MASK(DBG_CD_5) | MASK(DBG_CD_6) | MASK(DBG_CD_7);
	PTE->PCOR = MASK(DBG_0) | MASK(DBG_1) | MASK(DBG_2) | MASK(DBG_3) | MASK(DBG_4) | MASK(DBG_5) | MASK(DBG_6) | MASK(DBG_7);
}	