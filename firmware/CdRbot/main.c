/* 
 * File:   mian.c
 * Author: gary
 *
 * Created on April 15, 2013, 9:59 PM
 */

//#include "cdrbot.h"

#include <xc.h>
#include <delays.h>

void main ( void )
{
	OSCTUNE = 0x80; //3X PLL ratio mode selected
	OSCCON = 0x70; //Switch to 16MHz HFINTOSC
	OSCCON2 = 0x10; //Enable PLL, SOSC, PRI OSC drivers turned off
	while ( OSCCON2bits.PLLRDY != 1 ); //Wait for PLL lock

	TRISCbits.RC0 = 0;
	LATCbits.LATC0 = 0;
	for (;; )
	{
		LATCbits.LATC0 = !LATCbits.LATC0;
		Delay10KTCYx(200);
		Delay10KTCYx(200);
		Delay10KTCYx(200);
	}
}
