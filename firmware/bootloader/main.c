/*********************************************************************
 *
 *   Microchip USB HID Bootloader for PIC18 (Non-J Family) USB Microcontrollers
 *
 *********************************************************************
 * FileName:        main.c
 * Dependencies:    See INCLUDES section below
 * Processor:       PIC18
 * Compiler:        C18 3.42+
 * Company:         Microchip Technology, Inc.
 *
 * Software License Agreement
 *
 * The software supplied herewith by Microchip Technology Incorporated
 * (the "Company") for its PIC® Microcontroller is intended and
 * supplied to you, the Company's customer, for use solely and
 * exclusively on Microchip PICmicro Microcontroller products. The
 * software is owned by the Company and/or its supplier, and is
 * protected under applicable copyright laws. All rights are reserved.
 * Any use in violation of the foregoing restrictions may subject the
 * user to criminal sanctions under applicable laws, as well as to
 * civil liability for the breach of the terms and conditions of this
 * license.
 *
 * THIS SOFTWARE IS PROVIDED IN AN "AS IS"” CONDITION. NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED
 * TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE COMPANY SHALL NOT,
 * IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 * File Version  Date		Comment
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * 1.0			 06/19/2008	Original Version.  Adapted from 
 *							MCHPFSUSB v2.1 HID Bootloader
 *							for PIC18F87J50 Family devices.
 * 2.9f          06/26/2012 Added PIC18F45K50 Family support.
 ********************************************************************/

/*********************************************************************
IMPORTANT NOTES: This code is currently configured to work with the
PIC18F4550 using the PICDEM FS USB Demo Board.  However, this code
can be readily adapted for use with the both the F and LF versions of
the following devices:

PIC18F4553/4458/2553/2458
PIC18F4550/4455/2550/2455
PIC18F4450/2450
PIC18F14K50/13K50
PIC18F45K50/25K50/24K50


To do so, replace the linker script with an appropriate version, and
click "Configure --> Select Device" and select the proper
microcontroller.  Also double check to verify that the io_cfg.h and
usbcfg.h are properly configured to match your desired application
platform.

Verify that the coniguration bits are set correctly for the intended
target application, and fix any build errors that result from either
the #error directives, or due to I/O pin count mismatch issues (such
as when using a 28-pin device, but without making sufficient changes
to the io_cfg.h file)

This project needs to be built with the C18 compiler optimizations
enabled, or the total code size will be too large to fit within the
program memory range 0x000-0xFFF.  The default linker script included
in the project has this range reserved for the use by the bootloader,
but marks the rest of program memory as "PROTECTED".  If you try to
build this project with the compiler optimizations turned off, or
you try to modify some of this code, but add too much code to fit
within the 0x000-0xFFF region, a linker error like that below may occur:

Error - section '.code_main.o' can not fit the section. Section '.code_main.o' length=0x00000082
To fix this error, either optimize the program to fit within 0x000-0xFFF
(such as by turning on compiler optimizations), or modify the linker
and vector remapping (as well as the application projects) to allow this
bootloader to use more program memory.
 *********************************************************************/

/** I N C L U D E S **********************************************************/
#include <xc.h>
#include "typedefs.h"                   
#include "usb.h"                         
#include "io_cfg.h"                     
#include "BootPIC18NonJ.h"

/** C O N F I G U R A T I O N ************************************************/
// Note: For a complete list of the available config pragmas and their values, 
// see the compiler documentation, and/or click "Help --> Topics..." and then 
// select "PIC18 Config Settings" in the Language Tools section.

#if defined(CDRBOT)
#pragma config PLLSEL	= PLL3X		// 3X PLL multiplier selected
#pragma config CFGPLLEN	= OFF		// PLL turned on during execution
#pragma config CPUDIV	= NOCLKDIV	// 1:1 mode (for 48MHz CPU)
#pragma config LS48MHZ	= SYS48X8	// Clock div / 8 in Low Speed USB mode
#pragma config FOSC	= INTOSCIO	// HFINTOSC selected at powerup, no clock out
#pragma config PCLKEN	= OFF		// Primary oscillator driver
#pragma config FCMEN	= OFF		// Fail safe clock monitor
#pragma config IESO	= OFF		// Internal/external switchover (two speed startup)
#pragma config nPWRTEN	= OFF		// Power up timer
#pragma config BOREN	= SBORDIS	// BOR enabled
#pragma config BORV	= 2V5		// BOR set to 2.5V nominal
#pragma config nLPBOR	= ON		// Low Power BOR
#pragma config WDTEN	= SWON		// Watchdog Timer controlled by SWDTEN
#pragma config WDTPS	= 32768		// WDT postscalar
#pragma config CCP2MX	= RC1		// CCP2 input/output is multiplexed with RC1
#pragma config PBADEN	= OFF		// Port B Digital/Analog Powerup Behavior
#pragma config T3CMX	= RB5		// T3CKI function is on RB5
#pragma config SDOMX	= RC7		// SDO function location
#pragma config MCLRE	= ON		// MCLR function enabled (RE3 disabled)
#pragma config STVREN	= ON		// Stack overflow reset
#pragma config LVP	= OFF		// Low voltage programming
#pragma config ICPRT	= OFF		// Dedicated ICPORT program/debug pins enable
#pragma config XINST	= OFF		// Extended instruction set
#pragma config CP0	= OFF		// Block 0 is not code-protected
#pragma config CP1	= OFF		// Block 1 is not code-protected
#pragma config CP2	= OFF		// Block 2 is not code-protected
#pragma config CP3	= OFF		// Block 3 is not code-protected
#pragma config CPB	= OFF		// Boot block is not code-protected
#pragma config CPD	= OFF		// Data EEPROM is not code-protected
#pragma config WRT0	= OFF		// Block 0 (0800-1FFFh) is not write-protected
#pragma config WRT1	= OFF		// Block 1 (2000-3FFFh) is not write-protected
#pragma config WRT2	= OFF		// Block 2 (04000-5FFFh) is not write-protected
#pragma config WRT3	= OFF		// Block 3 (06000-7FFFh) is not write-protected
#pragma config WRTC	= OFF		// Configuration registers (300000-3000FFh) are not write-protected
#pragma config WRTB	= OFF		// Boot block (0000-7FFh) is not write-protected
#pragma config WRTD	= OFF		// Data EEPROM is not write-protected
#pragma config EBTR0	= OFF		// Block 0 is not protected from table reads executed in other blocks
#pragma config EBTR1	= OFF		// Block 1 is not protected from table reads executed in other blocks
#pragma config EBTR2	= OFF		// Block 2 is not protected from table reads executed in other blocks
#pragma config EBTR3	= OFF		// Block 3 is not protected from table reads executed in other blocks
#pragma config EBTRB	= OFF		// Boot block is not protected from table reads executed in other blocks
#else
#error Not a supported board (yet), make sure the proper board is selected in usbcfg.h, and if so, set configuration bits in __FILE__, line __LINE__
#endif

/** P R I V A T E  P R O T O T Y P E S ***************************************/
static void InitializeSystem ( void );
void USBTasks ( void );
void BlinkUSBStatus ( void );

/** V E C T O R  R E M A P P I N G *******************************************/
void interrupt interrupt_at_high_vector ( void )
{
	asm("goto 0x4008");
}

void interrupt low_priority interrupt_at_low_vector ( void )
{
	asm(" goto 0x4018");
}

/** D E C L A R A T I O N S **************************************************/

/******************************************************************************
 * Function:        void main(void)
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        Main program entry point.
 *
 * Note:            None
 *****************************************************************************/
void main ( void )
{
	// Para el CdRbot usamos con el PIC18F25K50 usamos el pin RA7
	// Check Bootload Mode Entry Condition
	if ( programSwitch == 1 ) //This example uses the sw2 I/O pin to determine if the device should enter the bootloader, or the main application code
	{
		asm ("goto 0x4000");
		//If the user is not trying to enter the bootloader, go straight to the main application remapped "reset" vector.
	}

	//We have decided to stay in this bootloader firwmare project.  Initialize
	//this firmware and the USB module.
	InitializeSystem();

	//Execute main loop
	while ( 1 )
	{
		ClrWdt();
		USBTasks(); // Need to call USBTasks() periodically
		// it handles SETUP packets needed for enumeration

		BlinkUSBStatus();

		if ( (usb_device_state == CONFIGURED_STATE) && (UCONbits.SUSPND != 1) )
		{
			ProcessIO(); // This is where all the actual bootloader related data transfer/self programming takes place
		} // see ProcessIO() function in the Boot87J50Family.c file.
	}//end while

}//end main

/******************************************************************************
 * Function:        static void InitializeSystem(void)
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        InitializeSystem is a centralize initialization routine.
 *                  All required USB initialization routines are called from
 *                  here.
 *
 *                  User application initialization routine should also be
 *                  called from here.                  
 *
 * Note:            None
 *****************************************************************************/
static void InitializeSystem ( void )
{
	//Initialize oscillator settings compatible with USB operation.  Note,
	//these may be application specific!
	#if defined(CDRBOT)
	OSCTUNE = 0x80; //3X PLL ratio mode selected
	OSCCON = 0x70; //Switch to 16MHz HFINTOSC
	OSCCON2 = 0x10; //Enable PLL, SOSC, PRI OSC drivers turned off
	while ( OSCCON2bits.PLLRDY != 1 ); //Wait for PLL lock
	*((unsigned char*) 0xFB5) = 0x90; //Enable active clock tuning for USB operation
	#endif

	mInitializeUSBDriver(); // See usbdrv.h

	UserInit(); // See user.c & .h

}//end InitializeSystem

/******************************************************************************
 * Function:        void USBTasks(void)
 *
 * PreCondition:    InitializeSystem has been called.
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        Service loop for USB tasks.
 *
 * Note:            None
 *****************************************************************************/
void USBTasks ( void )
{
	/*
	 * Servicing Hardware
	 */
	USBCheckBusStatus(); // Must use polling method
	USBDriverService(); // Interrupt or polling method

}// end USBTasks

/******************************************************************************
 * Function:        void BlinkUSBStatus(void)
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        BlinkUSBStatus turns on and off LEDs corresponding to
 *                  the USB device state.
 *
 * Note:            mLED macros can be found in io_cfg.h
 *                  usb_device_state is declared in usbmmap.c and is modified
 *                  in usbdrv.c, usbctrltrf.c, and usb9.c
 *****************************************************************************/
void BlinkUSBStatus ( void )
{
	static word led_count = 0;

	if ( led_count == 0 )led_count = 10000U;
	led_count--;

	if ( usb_device_state < CONFIGURED_STATE )
	{
		mLED_1_On();
	}
	else
	{
		if ( led_count == 0 )
		{
			mLED_1_Toggle();
		}//end if
	}//end if(...)
}//end BlinkUSBStatus

/** EOF main.c ***************************************************************/
