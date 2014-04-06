/* 
 * File:   io_cfg.h
 * Author: gary
 *
 * Created on June 16, 2013, 12:29 AM
 */

#ifndef IO_CFG_H
#define	IO_CFG_H

/** I N C L U D E S **********************************************************/
#include <xc.h>

/** T R I S ******************************************************************/
#define INPUT_PIN           1
#define OUTPUT_PIN          0

/** L E D ********************************************************************/
#define mInitLED()		LATC &= 0xFE; TRISC &= 0xFE;

#define mLED_1			LATCbits.LATC0
#define mLED_1_On()		mLED_1 = 1;
#define mLED_1_Off()		mLED_1 = 0;
#define mLED_1_Toggle()		mLED_1 ^= 1;

/** S W I T C H **************************************************************/
#define mInitSwitchPrg()	TRISBbits.TRISB4 = 1; ANSELBbits.ANSB4 = 0;

#define swPrg			PORTBbits.RB4

/** S E R V O S **************************************************************/
#define mInitServos()		LATB &= 0x3F; TRISB &= 0x3F;

#define mServo_L		LATBbits.LATB6		// Left Servo
#define mServo_R		LATBbits.LATB7		// Right Servo

/** L I N E  S E N S O R S ***************************************************/
#define mInitLineSensors()	TRISAbits.TRISA0=TRISAbits.TRISA1=1;ADCON0=0x01;ADCON2=0x3C;

#define mLineSensor_L		PORTAbits.RA0		// Left Sensor
#define mLineSensor_R		PORTAbits.RA1		// Right Sensor

/** O P O N E N T  S E N S O R ***********************************************/
#define mInitOponentSensor()	TRISBbits.TRISB0 = 1; ANSELBbits.ANSB0 = 0; TRISBbits.RB3 = 0; ANSELBbits.ANSB3 = 0;
#define mOponentSenor		PORTBbits.RB0

#endif	/* IO_CFG_H */

