/* 
 * File:   motors.h
 * Author: gary
 *
 * Created on June 16, 2013, 4:24 PM
 */

#ifndef SERIAL_H
#define	SERIAL_H

/** I N C L U D E S **********************************************************/
#include <xc.h>
#include "cdrbot.h"
#include "io_cfg.h"

/** D E F I N I T I O N S ****************************************************/

/** P U B L I C  P R O T O T Y P E S *****************************************/
void mInitSerialPort ( void );
void serialInterrupt ( void );
void putch ( unsigned char byte );
#endif	/* SERIAL_H */

