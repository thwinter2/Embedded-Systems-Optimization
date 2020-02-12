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

#include "I2C.h"
#include "mma8451.h"
#include "delay.h"
#include "profile.h"
#include "math.h"

#define NUM_TESTS 2500

/*----------------------------------------------------------------------------
  MAIN function
 *----------------------------------------------------------------------------*/
int main(void) {
	uint16_t r;
#ifdef PROFILER_LCD_SUPPORT
	char buffer[32];
	PT_T p;
#endif
	
	Init_RGB_LEDs();

#ifdef PROFILER_SERIAL_SUPPORT
	Init_UART0(115200);
	printf("\n\r\n\rHello 2020!\n\r");
#endif

#ifdef PROFILER_LCD_SUPPORT
	LCD_Init();
	LCD_Text_Init(1);
	LCD_Erase();

	p.X = COL_TO_X(0);
	p.Y = ROW_TO_Y(0);
	LCD_Text_PrintStr(&p, "Initializing");
#endif

	i2c_init();										// init I2C peripheral
	if (!init_mma()) {						// init accelerometer
		Control_RGB_LEDs(1, 0, 0);	// Red light means accelerometer initialization failed
		while (1);
	}

	Delay(70);

#ifdef PROFILER_SERIAL_SUPPORT
	Init_Profiling();
	Control_RGB_LEDs(1, 0, 1);		// Magenta: running
	for (r = 0; r < NUM_TESTS; r++) {
		read_xyz();
		convert_xyz_to_roll_pitch();
	}
	Control_RGB_LEDs(0, 0, 1);		// Blue: done
	Sort_Profile_Regions();
	Serial_Print_Sorted_Profile();
	printf("Done, please reset board when ready.\n\r");
	while (1);
#endif

#ifdef PROFILER_LCD_SUPPORT
	LCD_Erase();
	while (1) {
		p.X = COL_TO_X(0);
		p.Y = ROW_TO_Y(0);
		LCD_Text_PrintStr(&p, "Roll/Pitch");
		p.X = COL_TO_X(0);
		p.Y = ROW_TO_Y(1);
		LCD_Text_PrintStr(&p, "Optimization");
		Init_Profiling();
		Control_RGB_LEDs(1, 0, 1);	// Magenta: running

		for (r = 0; r < NUM_TESTS; r++) {
			read_full_xyz();
			convert_xyz_to_roll_pitch();
			p.X = COL_TO_X(0);
			p.Y = ROW_TO_Y(2);
			sprintf(buffer, "Roll: %5.1f", roll);
			LCD_Text_PrintStr(&p, buffer);
			p.X = COL_TO_X(0);
			p.Y = ROW_TO_Y(3);
			sprintf(buffer, "Pitch: %5.1f", pitch);
			LCD_Text_PrintStr(&p, buffer);
		}
		Control_RGB_LEDs(0, 0, 1);	// Blue: done
		Sort_Profile_Regions();

		LCD_Erase();
		Display_Profile();
	}
#endif

}
