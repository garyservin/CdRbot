/* 
 * File:   mian.c
 * Author: gary
 *
 * Created on April 15, 2013, 9:59 PM
 */

/** I N C L U D E S **********************************************************/
#include "cdrbot.h"

/** P R I V A T E  P R O T O T Y P E S ***************************************/

/** D E C L A R A T I O N S **************************************************/

void main ( void )
{
	char i = 4;
	int prueba[5] = { FORWARD, REVERSE, LEFT, RIGHT, HALT };

	InitRobot();

	for (;; )
	{
		if ( !swPrg )
		{
			if ( ++i > 4 )
				i = 0;

		}
		moveRobot(prueba[i]);
		mLED_1_Toggle();
		Delay10KTCYx(200);
		Delay10KTCYx(200);
		Delay10KTCYx(200);
	}
}

void interrupt ISR ( void )
{
	servoInterrupt();
}
