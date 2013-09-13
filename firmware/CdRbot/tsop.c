/** I N C L U D E S **********************************************************/
#include "tsop.h"

volatile struct
{
	UINT32_VAL Buffer;
	unsigned char pos;
	unsigned char timer;
	unsigned Ready : 1;
	unsigned NewData : 1;
} tsop = { 0, 0, 0, 0, 1 };

/** P R I V A T E  P R O T O T Y P E S ***************************************/

/** D E C L A R A T I O N S **************************************************/
void mInitTsop ( void )
{
	OpenTimer1(T1_SOURCE_FOSC_4 & // Set Timer to measure pulse time
		T1_PS_1_1 &
		T1_OSC1EN_OFF &
		T1_SYNC_EXT_OFF &
		T1_8BIT_RW &
		TIMER_INT_OFF,
		0x00);

	T1CONbits.TMR1ON = 0;

	mInitOponentSensor();

	/*TRISCbits.TRISC2 = 1; // Disable the CCPx pin output driver by setting the associated TRIS bit.
	PR2 = PWM_PERIOD; // Load the PR2 register for Timer2 with the PWM period value.
	CCP1CONbits.CCP1M = 0x0C; // Configure the CCP module for the PWM mode by loading the CCPxCON register with the appropriate values.

	CCPR1L = 0x28; // Load the CCPRxL register
	CCP1CONbits.DC1B = 00; // and the DCxB<1:0> bits of the CCPxCON register, with the PWM duty cycle value.

	// Configure and start the 8 - bit Timer2 :
	PIR1bits.TMR2IF = 0; // Clear the TMR2IF interrupt flag bit of the PIR1 register.
	T2CONbits.T2CKPS = 0x01; // Configure the T2CKPS bits of the T2CON register with the Timer prescale value.
	T2CONbits.TMR2ON = 1; // Enable the Timer by setting the TMR2ON bit of the T2CON register.

	// Enable PWM output pin :
	while ( !PIR1bits.TMR2IF ) continue; // Wait until the Timer overflows and the TMR2IF bit of the PIR1 register is set.
	TRISCbits.TRISC2 = 0; // Enable the CCPx pin output driver by clearing the associated TRIS bit.*/

	TRISCbits.TRISC1 = 1; // Disable the CCPx pin output driver by setting the associated TRIS bit.
	OpenPWM2(PWM_PERIOD, CCP_2_SEL_TMR32);
	SetDCPWM2(0xA0);
	OpenTimer2(T2_POST_1_1 &
		T2_PS_1_4 &
		TIMER_INT_OFF);
	// Enable PWM output pin :
	while ( !PIR1bits.TMR2IF ) continue; // Wait until the Timer overflows and the TMR2IF bit of the PIR1 register is set.
	TRISCbits.TRISC1 = 0; // Enable the CCPx pin output driver by clearing the associated TRIS bit.

	INTCON2bits.INTEDG0 = 0; // Interrupt on falling edge of INT pin
	INTCONbits.INT0IF = 0; // Clear Interrupt Flag for INT
	INTCONbits.INT0IE = 1; // Enable Interrupt for INT
}

char processSensor ( void )
{
	char value = 0;
	if ( tsop.Ready )
	{
		tsop.Ready = 0;

//		printf("0x%02X\r\n", tsop.Buffer.byte.UB);
		//		printf("0x%X", tsop.Buffer.word.HW);
		//		printf("%X\r\n", tsop.Buffer.word.LW);
		value = tsop.Buffer.byte.UB;
	}
	return (char) value;
}

void tsopInterrupt ( void )
{
	if ( INTCONbits.INT0IE && INTCONbits.INT0IF )
	{
		mLED_1_Toggle()
		if ( tsop.NewData )
		{
			tsop.NewData = 0;
			T1CONbits.TMR1ON = 1;
			WriteTimer1(0);
			tsop.pos = 0;
			tsop.Buffer.Val = 0;
		}
		else
		{
			tsop.timer = ReadTimer1();
			WriteTimer1(0);
			//						printf("%u|", tsop.timer);
			//			printf("%u\r\n", tsop.timer);

			if ( tsop.timer >= 10 && tsop.timer < 80 )
				tsop.Buffer.Val &= (((unsigned long) 1 << tsop.pos++) ^ 0xFFFFFFFF);
			else if ( tsop.timer >= 80 && tsop.timer < 140 )
				tsop.Buffer.Val |= ((unsigned long) 1 << tsop.pos++);
			else if ( tsop.timer >= 140 )
				tsop.pos = 0;

			if ( tsop.pos >= 32 )
			{
				tsop.NewData = 1;
				tsop.Ready = 1;
				T1CONbits.TMR1ON = 0;
				//				putch('\r');
				//				putch('\n');
				//				printf("0x%X\r\n", tsop.Buffer.byte.UB);
			}
		}
		INTCONbits.INT0IF = 0; // Clear Timer 0 interrupt flag
	}
}