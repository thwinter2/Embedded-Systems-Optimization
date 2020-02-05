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
#include "i2c.h"
#include "mma8451.h"
#include "delay.h"
#include "profile.h"
#include "geometry.h"

extern 	void test_atan2_approx(void);

#define PROFILE_DEMO (1)

// Raleigh, NC
#define TEST1_LAT (35.7796)
#define TEST1_LON (-78.6382)

/*----------------------------------------------------------------------------
  MAIN function
 *----------------------------------------------------------------------------*/
int main (void) {
	char buffer[32];
	float dist, bearing, cur_pos_lat, cur_pos_lon;
	char * name;
	PT_T pt;

#if PROFILE_DEMO
	int p;
	float f1=1, f2=0, f3=0;
#endif
	
	cur_pos_lat = TEST1_LAT;
	cur_pos_lon = TEST1_LON;
	
	Init_RGB_LEDs();
	Init_RGB_LEDs();
	LCD_Init();
	LCD_Text_Init(1);
	LCD_Erase();
	
	pt.X = COL_TO_X(0);
	pt.Y = ROW_TO_Y(0);
	LCD_Text_PrintStr(&pt, "Initializing");

	__enable_irq();
	
#if PROFILE_DEMO // ProfileDemo code from slides
	Init_Profiling();
	Control_RGB_LEDs(1,0,0);
	Enable_Profiling();
	
	for (p=0; p<10000; p++) {
		f1 *= 1.02;
		f2 += f1;
		f3 += sin(f1)*cos(f2);
	}
	Disable_Profiling();
	Control_RGB_LEDs(0,1,0);
	Sort_Profile_Regions();
	while (1)
		;
#endif // ProfileDemo code

	while (1) {
		Control_RGB_LEDs(1,0,1); // Purple: running

		Init_Profiling();
		Enable_Profiling();
		Find_Nearest_Waypoint(cur_pos_lat, cur_pos_lon, &dist, &bearing, &name);
		Disable_Profiling();
		Control_RGB_LEDs(0,0,1);	// Blue: done
		LCD_Erase();
		pt.X = COL_TO_X(0);
		pt.Y = ROW_TO_Y(0);
		LCD_Text_PrintStr(&pt, "Closest Point:"); 
		pt.X = COL_TO_X(0);
		pt.Y = ROW_TO_Y(1);
		sprintf(buffer, "%s", name);
		LCD_Text_PrintStr(&pt, buffer); 
		pt.X = COL_TO_X(0);
		pt.Y = ROW_TO_Y(2);
		sprintf(buffer, "%f km", dist);
		LCD_Text_PrintStr(&pt, buffer);
		pt.X = COL_TO_X(0);
		pt.Y = ROW_TO_Y(3);
		sprintf(buffer, "%8.3f deg", bearing);
		LCD_Text_PrintStr(&pt, buffer);
		Delay(1000);
		Sort_Profile_Regions(); 
		LCD_Erase();
		Display_Profile();
	}
}
