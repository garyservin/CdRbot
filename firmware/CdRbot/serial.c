
/** I N C L U D E S **********************************************************/
#include "serial.h"

/** D E F I N I T I O N S ****************************************************/
volatile struct
{
	unsigned KBhit : 1;
} Serial = { 0 };


/** P R I V A T E  P R O T O T Y P E S ***************************************/

/** D E C L A R A T I O N S **************************************************/

void mInitSerialPort ( void )
{
	unsigned int spbrg = 207;
	unsigned char config = USART_TX_INT_OFF & USART_RX_INT_ON & USART_BRGH_HIGH & USART_EIGHT_BIT & USART_ASYNCH_MODE & USART_ADDEN_OFF;
	unsigned char baudconfig = BAUD_IDLE_RX_PIN_STATE_HIGH & BAUD_IDLE_TX_PIN_STATE_HIGH & BAUD_16_BIT_RATE & BAUD_WAKEUP_OFF & BAUD_AUTO_OFF;

	Open1USART(config, spbrg);
	baud1USART(baudconfig);

	LATC &= 0x3F;
	TRISCbits.TRISC7 = 1;
	TRISCbits.TRISC6 = 1;
	ANSELC &= 0x3F;
}

void putch ( char data )
{
	while ( !PIR1bits.TXIF ) // check buffer
		continue;
	// wait till ready
	TXREG = data;
	// send data
}

void serialInterrupt ( void )
{
	if ( PIR1bits.RCIF && PIE1bits.RCIE )
	{
		PIR1bits.RCIF = 0;
		Write1USART(Read1USART());
	}
}