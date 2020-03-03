#include <MKL25Z4.H>
#include <stdio.h>
#include "DMA.h"

void Init_DMA_Transmit(void){
	
	SIM->SCGC7 |= SIM_SCGC7_DMA_MASK;
	SIM->SCGC6 |= SIM_SCGC6_DMAMUX_MASK;
	
	DMAMUX0->CHCFG[0] = 0;
	
	DMA0->DMA[0].DCR = DMA_DCR_EINT_MASK | DMA_DCR_SINC_MASK | DMA_DCR_SSIZE(1) | DMA_DCR_DSIZE(1) | 
	DMA_DCR_ERQ_MASK | DMA_DCR_CS_MASK;
	
	// Configure DMA ISR
	NVIC_SetPriority(DMA0_IRQn, 2);
	NVIC_ClearPendingIRQ(DMA0_IRQn);
	NVIC_EnableIRQ(DMA0_IRQn);
	
	// Set DMA MUX channel to use SPI1 Transmit as Trigger
	DMAMUX0->CHCFG[0] = DMAMUX_CHCFG_SOURCE(19);
	
}

void Start_DMA(uint32_t * source, uint32_t * destination, uint32_t count){
	// Initialize Source/Dest Pointers
	DMA0->DMA[0].SAR = DMA_SAR_SAR((uint32_t) source);
	DMA0->DMA[0].DAR = DMA_DAR_DAR((uint32_t) destination);
	// byte count
	DMA0->DMA[0].DSR_BCR = DMA_DSR_BCR_BCR(count);
	// clear done flag
	DMA0->DMA[0].DSR_BCR &= ~DMA_DSR_BCR_DONE_MASK;
	// set enable flag
	DMAMUX0->CHCFG[0] |= DMAMUX_CHCFG_ENBL_MASK;
	
}
