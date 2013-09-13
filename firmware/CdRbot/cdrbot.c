#include <xc.h>
#include "cdrbot.h"
#include "serial.h"

/** P R I V A T E  P R O T O T Y P E S ***************************************/
void initClockCDRBot ( void );

/** D E C L A R A T I O N S **************************************************/

/******************************************************************************
 * Function:        initClockCDRBot()
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        This function configures clock source for 48 MHz with the 3X PLL
 *
 * Note:            None
 *****************************************************************************/
void initClockCDRBot ( void )
{
	OSCTUNE = 0x80; //3X PLL ratio mode selected
	OSCCON = 0x70; //Switch to 16MHz HFINTOSC
	OSCCON2 = 0x10; //Enable PLL, SOSC, PRI OSC drivers turned off
	while ( OSCCON2bits.PLLRDY != 1 ); //Wait for PLL lock
}

/******************************************************************************
 * Function:        initRobot()
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        This function initializes all the modules for the robots
 *
 * Note:            None
 *****************************************************************************/
void InitRobot ( void )
{
	initClockCDRBot();
	mInitLED();
	mInitSwitchPrg();
	mInitMotors();
	mInitTsop();
	mInitSerialPort();

	RCONbits.IPEN = 0; // Interruption Priority Disabled
	INTCONbits.PEIE = 1; // Peripherial Interrupt Enabled
	INTCONbits.GIE = 1; // Global Interrupt Enable
}

void moveRobotSpeed ( unsigned int direction, unsigned int speed )
{
	int speedLeftServo = 0;
	int speedRightServo = 0;

	switch ( direction )
	{
		case FORWARD:
			speedLeftServo = speed;
			speedRightServo = -speed;
			break;
		case REVERSE:
			speedLeftServo = -speed;
			speedRightServo = speed;
			break;
		case LEFT:
			speedLeftServo = -speed;
			speedRightServo = -speed;
			break;
		case RIGHT:
			speedLeftServo = speed;
			speedRightServo = speed;
			break;
		case HALT:
			speedLeftServo = 0;
			speedRightServo = 0;
			break;

	}

	setServoSpeed(0, speedLeftServo);
	setServoSpeed(1, speedRightServo);
}

void moveRobot ( unsigned int direction )
{
	moveRobotSpeed(direction, 255);
}