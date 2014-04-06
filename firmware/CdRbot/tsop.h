/* 
 * File:   motors.h
 * Author: gary
 *
 * Created on June 16, 2013, 4:24 PM
 */

#ifndef TSOP_H
#define	TSOP_H

/** I N C L U D E S **********************************************************/
#include <xc.h>
#include <delays.h>
#include "cdrbot.h"
#include "io_cfg.h"

/** D E F I N I T I O N S ****************************************************/
#define PRES_TMR2	4
#define IR_FREQ	38000UL
#define IR_PERIOD	1 / IR_FREQ

#define PWM_PERIOD	( F_OSC / (4 * PRES_TMR2 * IR_FREQ) ) - 1

#define LOW_TIME 5000
#define HIGH_TIME 10000

/** P U B L I C  P R O T O T Y P E S *****************************************/
void mInitTsop ( void );
void tsopInterrupt ( void );
UINT32_VAL processSensor ( void );
void sendCarrier ( unsigned int time );
void sendIR ( unsigned long data );
char is_tsop_receiving ( void );
void micros_interrupt(void);

#endif	/* TSOP_H */

