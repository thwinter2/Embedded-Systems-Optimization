#ifndef DEBUG_H
#define DEBUG_H
#include <MKL25Z4.h>

#define MASK(x) (1UL << (x))

// Debug Signals on port B
#define DBG_1 1 	// SPI_RW
#define DBG_2 2	  // SD_Read
#define DBG_3 3		// SD_Write
#define DBG_4 8		// pf_read
#define DBG_5 9		// SD_Init
#define DBG_6 10	// unused
#define DBG_7 11	// unused

#define DEBUG_START(channel) {FPTB->PSOR = MASK(channel);} 
#define DEBUG_STOP(channel) { FPTB->PCOR = MASK(channel); }
#define DEBUG_TOGGLE(channel) { FPTB->PTOR = MASK(channel); }

void Init_Debug_Signals(void);

#endif // DEBUG_H
