/*----------------------------------------------------------------------------
 *----------------------------------------------------------------------------*/
#include <MKL25Z4.H>
#include <stdio.h>
#include <math.h>

#include "gpio_defs.h"
#include "LEDs.h"
#include "LCD.h"
#include "font.h"
#include "timers.h"
#include "UART.h"
#include "delay.h"
#include "profile.h"
#include "sincos.h"

#define USE_SERIAL_PORT
// #define USE_LCD

#define DELTA (0.01)
#define NUM_TESTS (10000)

float Test_Approx(int num_tests, float (*fp) (float)) {
	float arg = -DELTA*NUM_TESTS/2;
	float ret = 0.0f, retsum = 0.0f;

	while (num_tests--) {
		Enable_Profiling();
		ret = fp(arg);
		Disable_Profiling();
		retsum += ret;
		arg += DELTA;
	}
	return retsum;
}

typedef struct {
	char Name[16];
	float (*Function) (float);
} TEST_FUN;

TEST_FUN test_funs[] = {
	{"cosf", cosf},
	{"cos_52", cos_52},
	{"cos_32", cos_32},
	{"cos_xx", cos_xx},
	{"END", NULL},
};

/*----------------------------------------------------------------------------
  MAIN function
 *----------------------------------------------------------------------------*/
int main(void) {
//  char buffer[32];
//  PT_T pt;
	float sum;
	int i = 0;

	Init_RGB_LEDs();

#ifdef USE_SERIAL_PORT
	Init_UART0(115200);
	printf("n\rTrig Function Approximation Tester\n\r");
#endif

#if 0
	eval_error();
	while (1)
		;
#endif
	
#ifdef USE_LCD
	LCD_Init();
	LCD_Text_Init(1);
	LCD_Erase();
	pt.X = COL_TO_X(0);
	pt.Y = ROW_TO_Y(0);
	LCD_Text_PrintStr(&pt, "Initializing");
#endif

	Control_RGB_LEDs(1, 0, 1);		// Purple: running

	while (test_funs[i].Function != NULL) {
		Init_Profiling();
//		Enable_Profiling();
		sum = Test_Approx(NUM_TESTS, test_funs[i].Function);
// 		Disable_Profiling();
		Control_RGB_LEDs(0, 0, 1);	// Blue: done
		printf("\n\r*** %s ***\n\r", test_funs[i].Name);
		Sort_Profile_Regions();
#ifdef USE_SERIAL_PORT
		Serial_Print_Sorted_Profile();
#endif
#ifdef USE_LCD
		LCD_Erase();
		Display_Profile();
#endif
		i++;
		Delay(100);
	}
	printf("Done!\n\r");
	while (1);
}
