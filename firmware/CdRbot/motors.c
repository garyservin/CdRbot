
/** I N C L U D E S **********************************************************/
#include "motors.h"

volatile unsigned int Ticks4NextInterrupt = 0;
volatile unsigned int Servo_PWM[2] = { Ticks4Center, Ticks4Center };
volatile char Servo_Idx = 0;

volatile struct
{
	unsigned L : 1;
	unsigned R : 1;
	unsigned Phase : 1;
} Servo = { 0, 0, 0 };

unsigned int zeroServo[2] = { 18000, 18000 };
unsigned int enableServo[2] = { 0, 0 };

/** P R I V A T E  P R O T O T Y P E S ***************************************/

/** D E C L A R A T I O N S **************************************************/
void mInitMotors ( void )
{
	mInitServos();
	
	OpenTimer0(TIMER_INT_ON &
		T0_16BIT &
		T0_SOURCE_INT &
		T0_PS_1_1);
}

void servoInterrupt ( void )
{
	if ( INTCONbits.TMR0IF && INTCONbits.TMR0IE )
	{
		INTCONbits.TMR0IF = 0;
		if ( !Servo.Phase )
		{
			if ( Servo_Idx == 0 && enableServo[0] ) mServo_L = 1;
			if ( Servo_Idx == 1 && enableServo[1] ) mServo_R = 1;
			Ticks4NextInterrupt = 65535 - Servo_PWM[Servo_Idx];
			WriteTimer0(Ticks4NextInterrupt);
		}
		else
		{
			if ( Servo_Idx == 0 && enableServo[0] ) mServo_L = 0;
			if ( Servo_Idx == 1 && enableServo[1] ) mServo_R = 0;
			Ticks4NextInterrupt = 65535 - Ticks4Window + Servo_PWM[Servo_Idx];
			WriteTimer0(Ticks4NextInterrupt);
			if ( ++Servo_Idx > 3 ) Servo_Idx = 0;
		}
		Servo.Phase = !Servo.Phase;
	}
}

void setServoSpeed ( unsigned int servoID, int speed )
{
	if ( speed > 255 )
		speed = 255;

	Servo_PWM[servoID] = zeroServo[servoID] + (speed * 38);

	if ( !speed )
		enableServo[servoID] = 0;
	else
		enableServo[servoID] = 1;
}

