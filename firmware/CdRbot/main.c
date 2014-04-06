/* 
 * File:   mian.c
 * Author: gary
 *
 * Created on April 15, 2013, 9:59 PM
 */

/** I N C L U D E S **********************************************************/
#include "cdrbot.h"

/** P R I V A T E  P R O T O T Y P E S ***************************************/

/** D E C L A R A T I O N S **************************************************/
void main(void) {
    InitRobot();

    for (;;) {
        UINT32_VAL sensors;
        sensors.Val = 0;
        //        char command;
        //
        //        sensors = processSensor();
        //        if (sensors) {
        //            switch (sensors) {
        //            case 24:
        //                command = FORWARD;
        //                break;
        //            case 82:
        //                command = REVERSE;
        //                break;
        //            case 90:
        //                command = RIGHT;
        //                break;
        //            case 8:
        //                command = LEFT;
        //                break;
        //            case 28:
        //                command = HALT;
        //                break;
        //            default:
        //                command = HALT;
        //                break;
        //            }
        //            putch(command);
        //            moveRobot(command);
        //        }


        sendIR(0xE718FF00);
        sensors = processSensor();
        printf("0x%X\r\n",sensors.word.HW);
        Delay10KTCYx(200);
        //__delay_ms(5);

        //        mLED_1_Toggle();
        //        Delay10KTCYx(200);
        //        Delay10KTCYx(200);
        //        Delay10KTCYx(200);
    }
}

void interrupt ISR(void) {
    micros_interrupt();
    tsopInterrupt();
    //	serialInterrupt();
    servoInterrupt();
}
