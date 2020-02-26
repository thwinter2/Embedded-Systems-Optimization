// Automatically generated file. Do not edit if you plan to regenerate it.
#include "region.h"
const REGION_T RegionTable[] = {
	{0x000003cd, 0x000003e8, "LCD_24S_Write_Command"}, // 0
	{0x00000475, 0x0000048a, "LCD_24S_Write_Data"}, // 1
	{0x00001a8d, 0x00001aaa, "addAndClamp"}, // 2
	{0x00001b01, 0x00001b1a, "clamp"}, // 3
	{0x00001b3d, 0x00001b86, "convertCb"}, // 4
	{0x00001b91, 0x00001bdc, "convertCr"}, // 5
	{0x00001be1, 0x00001c12, "copyY"}, // 6
	{0x00001c91, 0x00001e66, "decodeNextMCU"}, // 7
	{0x00002065, 0x00002094, "getBit"}, // 8
	{0x00002099, 0x0000210e, "getBits"}, // 9
	{0x00002115, 0x0000211e, "getBits1"}, // 10
	{0x0000211f, 0x00002128, "getBits2"}, // 11
	{0x00002129, 0x00002178, "getChar"}, // 12
	{0x00002181, 0x000021ea, "getExtendOffset"}, // 13
	{0x00002209, 0x00002270, "getExtendTest"}, // 14
	{0x00002271, 0x00002298, "getOctet"}, // 15
	{0x00002365, 0x000023b6, "huffDecode"}, // 16
	{0x000023c1, 0x000023de, "huffExtend"}, // 17
	{0x000023e1, 0x00002584, "idctCols"}, // 18
	{0x00002589, 0x00002674, "idctRows"}, // 19
	{0x00002679, 0x00002686, "imul_b1_b3"}, // 20
	{0x00002689, 0x00002694, "imul_b2"}, // 21
	{0x00002699, 0x000026a6, "imul_b4"}, // 22
	{0x000026a7, 0x000026b2, "imul_b5"}, // 23
	{0x000026b5, 0x000026e4, "init"}, // 24
	{0x000026e9, 0x000027e6, "initFrame"}, // 25
	{0x000027ed, 0x000028d8, "initScan"}, // 26
	{0x00002901, 0x0000297e, "locateSOFMarker"}, // 27
	{0x000031b9, 0x00003286, "processMarkers"}, // 28
	{0x0000328d, 0x000032f8, "processRestart"}, // 29
	{0x000032fd, 0x0000343e, "readDHTMarker"}, // 30
	{0x00003451, 0x0000350e, "readDQTMarker"}, // 31
	{0x0000351d, 0x000035ce, "readSOFMarker"}, // 32
	{0x000035d5, 0x0000368c, "readSOSMarker"}, // 33
	{0x00003691, 0x000036a6, "stuffChar"}, // 34
	{0x000036b1, 0x000036ce, "subAndClamp"}, // 35
	{0x000036d1, 0x000037dc, "transformBlock"}, // 36
	{0x000037e1, 0x00003b12, "transformBlockReduce"}, // 37
	{0x00003b25, 0x00003bca, "upsampleCb"}, // 38
	{0x00003bd5, 0x00003c4e, "upsampleCbH"}, // 39
	{0x00003c59, 0x00003cd4, "upsampleCbV"}, // 40
	{0x00003cdd, 0x00003d84, "upsampleCr"}, // 41
	{0x00003d89, 0x00003e04, "upsampleCrH"}, // 42
	{0x00003e09, 0x00003e86, "upsampleCrV"}, // 43
	{0x00001aad, 0x00001af8, "check_fs"}, // 44
	{0x00001b1d, 0x00001b38, "clust2sect"}, // 45
	{0x00001c19, 0x00001c8c, "create_name"}, // 46
	{0x00001e81, 0x00001ee2, "dir_find"}, // 47
	{0x00001ee5, 0x00001f40, "dir_next"}, // 48
	{0x00001f45, 0x00001f72, "dir_rewind"}, // 49
	{0x00001fa9, 0x00002010, "follow_path"}, // 50
	{0x00002299, 0x000022b0, "get_clust"}, // 51
	{0x000022b1, 0x000022ec, "get_fat"}, // 52
	{0x000022f1, 0x00002362, "get_fileinfo"}, // 53
	{0x000028dd, 0x000028f2, "ld_dword"}, // 54
	{0x000028f3, 0x000028fe, "ld_word"}, // 55
	{0x000000d5, 0x000000e0, "Reset_Handler"}, // 56
	{0x000000e1, 0x000000e2, "NMI_Handler"}, // 57
	{0x000000e3, 0x000000e4, "HardFault_Handler"}, // 58
	{0x000000e5, 0x000000e6, "SVC_Handler"}, // 59
	{0x000000e7, 0x000000e8, "PendSV_Handler"}, // 60
	{0x000000e9, 0x000000ea, "SysTick_Handler"}, // 61
	{0x0000014d, 0x0000017e, "Control_RGB_LEDs"}, // 62
	{0x00000185, 0x00000196, "Delay"}, // 63
	{0x0000019d, 0x000001a4, "Disable_Profiling"}, // 64
	{0x000001a9, 0x0000026a, "Display_Profile"}, // 65
	{0x000002bd, 0x000002c4, "Enable_Profiling"}, // 66
	{0x000002c9, 0x000002e0, "Init_ADC"}, // 67
	{0x000002e9, 0x0000035c, "Init_Debug_Signals"}, // 68
	{0x0000036d, 0x000003ba, "Init_Profiling"}, // 69
	{0x000003ed, 0x000003f6, "LCD_Erase"}, // 70
	{0x00000411, 0x00000464, "Init_RGB_LEDs"}, // 71
	{0x00000491, 0x000004f6, "LCD_Controller_Init"}, // 72
	{0x000004fd, 0x0000057e, "LCD_Fill_Buffer"}, // 73
	{0x00000581, 0x0000062c, "LCD_GPIO_Init"}, // 74
	{0x00000639, 0x00000686, "LCD_Init"}, // 75
	{0x000006a1, 0x00000736, "LCD_JPEG"}, // 76
	{0x00000791, 0x00000802, "LCD_Plot_Pixel"}, // 77
	{0x00000803, 0x00000898, "LCD_Start_Rectangle"}, // 78
	{0x00000899, 0x000008bc, "LCD_TS_Blocking_Read"}, // 79
	{0x000008bd, 0x000008c4, "LCD_TS_Init"}, // 80
	{0x000008c5, 0x00000a52, "LCD_TS_Read"}, // 81
	{0x00000a69, 0x00000a7a, "LCD_Text_GetGlyphWidth"}, // 82
	{0x00000a81, 0x00000aac, "LCD_Text_Init"}, // 83
	{0x00000ab5, 0x00000c14, "LCD_Text_PrintChar"}, // 84
	{0x00000c19, 0x00000c4a, "LCD_Text_PrintStr"}, // 85
	{0x00000c51, 0x00000c8c, "LCD_Text_PrintStr_RC"}, // 86
	{0x00000c91, 0x00000cb0, "LCD_Text_Set_Colors"}, // 87
	{0x00000cb5, 0x00000d12, "LCD_Write_Rectangle_N_Qu"}, // 88
	{0x00000d1d, 0x00000d4c, "LCD_Write_Rectangle_Pixe"}, // 89
	{0x00000df9, 0x00000e54, "PWM_Init"}, // 90
	{0x00000e65, 0x00000ec2, "Process_Profile_Sample"}, // 91
	{0x00000f65, 0x0000113c, "SD_Init"}, // 92
	{0x00001141, 0x000011ee, "SD_Read"}, // 93
	{0x000011f9, 0x00001204, "SPI_CS_High"}, // 94
	{0x00001209, 0x00001214, "SPI_CS_Low"}, // 95
	{0x00001219, 0x00001220, "SPI_Freq_High"}, // 96
	{0x00001225, 0x0000122c, "SPI_Freq_Low"}, // 97
	{0x00001231, 0x00001270, "SPI_Init"}, // 98
	{0x00001285, 0x000012ac, "SPI_RW"}, // 99
	{0x000012b5, 0x000012d0, "SPI_Release"}, // 100
	{0x000012d1, 0x000012d8, "SPI_Timer_Off"}, // 101
	{0x000012dd, 0x000012f6, "SPI_Timer_On"}, // 102
	{0x00001301, 0x0000130c, "SPI_Timer_Status"}, // 103
	{0x00001311, 0x000013a8, "Sort_Profile_Regions"}, // 104
	{0x000013b9, 0x00001472, "SystemInit"}, // 105
	{0x000014a1, 0x000014ac, "TPM0_IRQHandler"}, // 106
	{0x000014b1, 0x00001508, "UART0_IRQHandler"}, // 107
	{0x00001f79, 0x00001f88, "disk_initialize"}, // 108
	{0x00001f8d, 0x00001fa4, "disk_readp"}, // 109
	{0x00002011, 0x00002060, "free"}, // 110
	{0x00002985, 0x00002a34, "main"}, // 111
	{0x00002a95, 0x00002af0, "malloc"}, // 112
	{0x00002b01, 0x00002c00, "pf_mount"}, // 113
	{0x00002c09, 0x00002c5e, "pf_open"}, // 114
	{0x00002c65, 0x00002cae, "pf_opendir"}, // 115
	{0x00002cb5, 0x00002d76, "pf_read"}, // 116
	{0x00002d81, 0x00002e1a, "pf_readdir"}, // 117
	{0x00002e21, 0x00002eb2, "pjpeg_decode_init"}, // 118
	{0x00002ebd, 0x00002eee, "pjpeg_decode_mcu"}, // 119
	{0x00002ef5, 0x00003184, "pjpeg_load_from_file"}, // 120
	{0x0000318d, 0x000031b2, "pjpeg_need_bytes_callbac"}, // 121
}; 
const unsigned NumProfileRegions=122;
volatile unsigned RegionCount[122];
unsigned SortedRegions[122];
