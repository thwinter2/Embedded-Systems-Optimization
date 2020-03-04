/*----------------------------------------------------------------------------
 *----------------------------------------------------------------------------*/
#include <MKL25Z4.H>
#include <stdio.h>
#include "gpio_defs.h"

#include "LCD.h"
#include "font.h"

#include "LEDs.h"
#include "timers.h"
#include "UART.h"
#include "debug.h"

#include "pff.h"

#include "I2C.h"
#include "mma8451.h"
#include "delay.h"
#include "profile.h"
#include "math.h"

extern int LCD_JPEG(void);

uint32_t DMA_Destination_Buffer[512];
uint32_t * DMA_Destination = 0;
uint32_t DMA_Count;

void die(												/* Stop with dying message */
					FRESULT rc						/* FatFs return value */
		) {
//  printf("Failed with rc=%u.\n", rc);
	Control_RGB_LEDs(1, 0, 0);
	for (;;);
}


#if 0
void PFF_Test(void) {
	FATFS fatfs;									/* File system object */
	DIR dir;											/* Directory object */
	FILINFO fno;									/* File information object */
	UINT br, i;
	BYTE buff[64];
	FRESULT rc;
	PT_T p;
	uint32_t row = 0;
	char tbuff[64];

	LCD_Text_PrintStr_RC(row++, 0, "Mounting file system");
	rc = pf_mount(&fatfs);
	if (rc)
		die(rc);

#if PF_USE_DIR
	LCD_Text_PrintStr_RC(row++, 0, "Opening root directory");

	rc = pf_opendir(&dir, "");
	if (rc)
		die(rc);

	for (;;) {
		rc = pf_readdir(&dir, &fno);	/* Read a directory item */
		if (rc || !fno.fname[0])
			break;										/* Error or end of dir */
		if (fno.fattrib & AM_DIR)
			sprintf(tbuff, "   <dir>  %s", fno.fname);
		else
			sprintf(tbuff, "%8u  %s", fno.fsize, fno.fname);
		LCD_Text_PrintStr_RC(row++, 0, tbuff);
	}
	if (rc)
		die(rc);
#endif


	while (1);

#if 0
	rc = pf_open("PFF.c");
	if (rc)
		die(rc);

//  printf("\nType the file content.\n");
	for (;;) {
		rc = pf_read(buff, sizeof(buff), &br);	/* Read a chunk of file */
		if (rc || !br)
			break;										/* Error or end of file */
//    for (i = 0; i < br; i++)    /* Type the data */
//      putchar(buff[i]);
	}
	if (rc)
		die(rc);
#endif

#if PF_USE_WRITE
	printf("\nOpen a file to write (write.txt).\n");
	rc = pf_open("WRITE.TXT");
	if (rc)
		die(rc);

	printf("\nWrite a text data. (Hello world!)\n");
	for (;;) {
		rc = pf_write("Hello world!\r\n", 14, &bw);
		if (rc || !bw)
			break;
	}
	if (rc)
		die(rc);

	printf("\nTerminate the file write process.\n");
	rc = pf_write(0, 0, &bw);
	if (rc)
		die(rc);
#endif

	Control_RGB_LEDs(0, 1, 0);
//  printf("\nTest completed.\n");
	for (;;);
}
#endif

void Init_DMA(uint32_t * destination, uint32_t count){
	DMA_Destination = destination;
	DMA_Count = count;
	
	SIM->SCGC7 |= SIM_SCGC7_DMA_MASK;
	SIM->SCGC6 |= SIM_SCGC6_DMAMUX_MASK;
	
	DMAMUX0->CHCFG[0] = 0;
	
	DMA0->DMA[0].DCR = DMA_DCR_EINT_MASK | DMA_DCR_SINC_MASK | DMA_DCR_SSIZE(1) | DMA_DCR_DSIZE(1) | 
	DMA_DCR_ERQ_MASK | DMA_DCR_CS_MASK;
	
	// Configure DMA ISR
	NVIC_SetPriority(DMA0_IRQn, 2);
	NVIC_ClearPendingIRQ(DMA0_IRQn);
	NVIC_EnableIRQ(DMA0_IRQn);
	
	// Set DMA MUX channel to use SPI1 Transmit Complete as Trigger
	DMAMUX0->CHCFG[0] = DMAMUX_CHCFG_SOURCE(18);
	
}

void Start_DMA(void){
	// Initialize Source/Dest Pointers
	DMA0->DMA[0].SAR = DMA_SAR_SAR((uint32_t) (SPI1_D));
	DMA0->DMA[0].DAR = DMA_DAR_DAR((uint32_t) DMA_Destination);
	// byte count
	DMA0->DMA[0].DSR_BCR = DMA_DSR_BCR_BCR(DMA_Count);
	// clear done flag
	DMA0->DMA[0].DSR_BCR &= ~DMA_DSR_BCR_DONE_MASK;
	// set enable flag
	DMAMUX0->CHCFG[0] |= DMAMUX_CHCFG_ENBL_MASK;
}

void DMA_IRQHandler(void){
	DMA0->DMA[0].DSR_BCR |= DMA_DSR_BCR_DONE_MASK;
	Start_DMA();
}

/*----------------------------------------------------------------------------
  MAIN function
 *----------------------------------------------------------------------------*/
int main(void) {
	FATFS fatfs;
	FRESULT rc;
	int error;
	PT_T p;
	char buf[16];
	
	Init_RGB_LEDs();
	Init_DMA(DMA_Destination_Buffer,512);

#ifdef PROFILER_SERIAL_SUPPORT
	Init_UART0(115200);
	printf("Hello 2019!\n\r");
#endif
	Init_Debug_Signals();

#ifdef PROFILER_LCD_SUPPORT
	LCD_Init();
	LCD_Text_Init(1);
	LCD_Erase();

	LCD_Text_PrintStr_RC(0, 0, "Initializing");
#endif

	LCD_Text_PrintStr_RC(1, 0, "Looking for uSD card");
	rc = pf_mount(&fatfs);
	if (rc) {
		LCD_Text_PrintStr_RC(2, 0, "pf_mount failed");
		Control_RGB_LEDs(1, 0, 0);
		while (1);
	}
	LCD_Text_PrintStr_RC(2, 0, "Mounted uSD card");


	while (1) {
		Init_Profiling();
		LCD_Erase();
		Control_RGB_LEDs(1, 0, 1);	// Magenta: running
		Enable_Profiling();
		error = LCD_JPEG();
		Disable_Profiling();
		Control_RGB_LEDs(error, 1-error, 0);	// Green: ok. Red: bad.
		if (error != 0) {
			sprintf(buf, "LCD_JPEG failure %d", error);
			LCD_Text_PrintStr_RC(0, 0, buf); 
			while (1)
				;
		}
		Sort_Profile_Regions();
		LCD_TS_Blocking_Read(&p);		// Wait for user to press screen
		LCD_Erase();
		Display_Profile();
	}
}
