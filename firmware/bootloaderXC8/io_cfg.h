/*********************************************************************
 *
 *                Microchip USB C18 Firmware 
 *
 *********************************************************************
 * FileName:        io_cfg.h
 * Dependencies:    See INCLUDES section below
 * Processor:       PIC18
 * Compiler:        C18 3.11+
 * Company:         Microchip Technology, Inc.
 *
 * Software License Agreement
 *
 * The software supplied herewith by Microchip Technology Incorporated
 * (the “Company”) for its PICmicro® Microcontroller is intended and
 * supplied to you, the Company’s customer, for use solely and
 * exclusively on Microchip PICmicro Microcontroller products. The
 * software is owned by the Company and/or its supplier, and is
 * protected under applicable copyright laws. All rights are reserved.
 * Any use in violation of the foregoing restrictions may subject the
 * user to criminal sanctions under applicable laws, as well as to
 * civil liability for the breach of the terms and conditions of this
 * license.
 *
 * THIS SOFTWARE IS PROVIDED IN AN “AS IS” CONDITION. NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED
 * TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE COMPANY SHALL NOT,
 * IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 * File Version  Date		Comment
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * 1.0			 04/09/2008	Started from MCHPFSUSB v1.3 HID Mouse
 *							demo project.  Commented out items that
 *							are not particularly useful for the
 *							bootloader.
 ********************************************************************/

#ifndef IO_CFG_H
#define IO_CFG_H

/** I N C L U D E S *************************************************/
#include "usbcfg.h"

/** T R I S *********************************************************/
#define INPUT_PIN           1
#define OUTPUT_PIN          0

// CdRbot Board
#if defined(CDRBOT)
/** U S B ***********************************************************/
// Se necesita para que no genere error
#define usb_bus_sense       1
#define self_power          1

/** L E D ***********************************************************/
#define mInitAllLEDs()		LATC &= 0xFE; TRISC &= 0xFE;  //RC0
#define mLED_1			LATCbits.LATC0

#define mLED_1_On()		mLED_1 = 1;
#define mLED_1_Off()		mLED_1 = 0;
#define mLED_1_Toggle()		mLED_1 = !mLED_1;

/** S W I T C H *****************************************************/
#if defined(__PIC18F25K50)
#define programSwitch		PORTBbits.RB4
#elif defined(__PIC18F45K50)
#define programSwitch		PORTBbits.RB4
#endif

#else
#error Not a supported board (yet), add I/O pin mapping in __FILE__, line __LINE__
#endif


//Special register re-definitions, for accessing the USBIF and USBIE interrupt 
//related bits.  These bits are located in PIR3/PIE3 on PIC18F45K50 Family devices,
//but this fimware expects them to be in PIR2/PIE2 instead, like on previous devices.
#if defined(CDRBOT)
#define PIR2bits  PIR3bits
#define PIE2bits  PIE3bits
#endif


#endif //IO_CFG_H
