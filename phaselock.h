#include <lpc214x.h>

void initClocks(void)
{
	PLL0CON = 0x01;   //Enable PLL
	PLL0CFG = 0x24;   //Multiplier and divider setup
	PLL0FEED = 0xAA;  //Feed sequence
	PLL0FEED = 0x55;
	
	while(!(PLL0STAT & 0x00000400)); //is locked?
		
	PLL0CON = 0x03;   //Connect PLL after PLL is locked
	PLL0FEED = 0xAA;  //Feed sequence
	PLL0FEED = 0x55;
	VPBDIV = 0x01;    // PCLK is same as CCLK i.e.60 MHz
}
