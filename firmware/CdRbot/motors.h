/* 
 * File:   motors.h
 * Author: gary
 *
 * Created on June 16, 2013, 4:24 PM
 */

#ifndef MOTORS_H
#define	MOTORS_H

/** I N C L U D E S **********************************************************/
#include <xc.h>
#include "cdrbot.h"
#include "io_cfg.h"

/** D E F I N I T I O N S ****************************************************/
#define Ticks4Window	5000UL * (F_OSC/4000000UL)	// PWM Window for servo = 5 ms x 4 = 20 ms
#define Ticks4CCW	700UL * (F_OSC/4000000UL)	// PWM High for Counter-Clockwise Rotation = 0.7 ms
#define Ticks4Center	1500UL * (F_OSC/4000000UL)	// PWM High for Center  Position = 1.5 ms
#define Ticks4CW	2300UL * (F_OSC/4000000UL)	// PWM High for Clockwise Rotation = 2.3 ms

#define CW		0
#define CCW		1

/** P U B L I C  P R O T O T Y P E S *****************************************/
void mInitMotors ( void );
void servoInterrupt ( void );
void setServoSpeed ( unsigned int servoID, int speed );

#endif	/* MOTORS_H */

