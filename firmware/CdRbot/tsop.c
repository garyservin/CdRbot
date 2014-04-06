/** I N C L U D E S **********************************************************/
#include "tsop.h"

volatile struct {
    unsigned Ready : 1;
    unsigned NewData : 1;
    unsigned Receiving : 1;
} tsop = {0, 1, 0};

volatile UINT32_VAL Buffer = 0;
volatile unsigned char pos = 0;
volatile unsigned int timer = 0;
volatile long long timestamp = 0;

/** P R I V A T E  P R O T O T Y P E S ***************************************/

void delay_us(unsigned int us);
unsigned long long micros(void);

/** D E C L A R A T I O N S **************************************************/
void mInitTsop(void) {
    // Timer 1 is used for measuring the period of each incoming data
    OpenTimer1(T1_SOURCE_FOSC_4 & // Set Timer to measure pulse time
               T1_PS_1_4 &
               T1_OSC1EN_OFF &
               T1_SYNC_EXT_OFF &
               T1_16BIT_RW &
               TIMER_INT_OFF,
               0x00);
    IPR1bits.TMR1IP = 0;

    // Timer 3 is used for global timing keeping
    OpenTimer3(T3_SOURCE_FOSC_4 & // Set Timer to measure pulse time
               T3_PS_1_4 &
               T3_OSC1EN_OFF &
               T3_SYNC_EXT_OFF &
               T3_16BIT_RW &
               TIMER_INT_ON,
               0x00);

    IPR2bits.TMR3IP = 0; // Low priority for Timer 3

    mInitOponentSensor();

    TRISBbits.TRISB3 = 1; // Disable the CCPx pin output driver by setting the associated TRIS bit.
    OpenPWM2(PWM_PERIOD, CCP_2_SEL_TMR32);
    SetDCPWM2(0x00);
    OpenTimer2(T2_POST_1_1 &
               T2_PS_1_4 &
               TIMER_INT_OFF);
    // Enable PWM output pin :
    while (!PIR1bits.TMR2IF) continue; // Wait until the Timer overflows and the TMR2IF bit of the PIR1 register is set.
    TRISBbits.TRISB3 = 0; // Enable the CCPx pin output driver by clearing the associated TRIS bit.
    IPR1bits.TMR2IP = 0; // Low priority for Timer 2

    INTCON2bits.INTEDG0 = 0; // Interrupt on falling edge of INT pin
    INTCONbits.INT0IF = 0; // Clear Interrupt Flag for INT
    INTCONbits.INT0IE = 1; // Enable Interrupt for INT
}

UINT32_VAL processSensor(void) {
    UINT32_VAL value;
    value.Val = 0;
    if (tsop.Ready) {
        tsop.Ready = 0;
        value = Buffer;
        //        value = Buffer.byte.UB;
        //        printf("%X\r\n", Buffer.word.HW);
        //        printf("%X\r\n", Buffer.word.LW);
    }
    return value;
}

void sendIR(unsigned long data) {
    char i = 0;
    unsigned int bitTime = 600;

    sendCarrier(9000);
    delay_us(5000);

    for (i = 0; i < 32; i++) {
        sendCarrier(bitTime);
        if (data & 0x00000001) {
            delay_us(3 * bitTime);
        } else {
            delay_us(bitTime);
        }
        data >>= 1;
    }
    sendCarrier(bitTime);
}

void sendCarrier(unsigned int time) {
    SetDCPWM2(0xA0);
    delay_us(time);
    SetDCPWM2(0x00);
}

void delay_us(unsigned int us) {
    // TODO: Reimplement te timer-based delay
    unsigned int i, j;
    for (i = 0; i < us; i++) {
        Delay1TCY();
        Delay1TCY();
    }
    //    unsigned long long start = micros();
    //    while ((micros() - start) < us) continue;
}

void tsopInterrupt(void) {
    if (INTCONbits.INT0IE && INTCONbits.INT0IF) {
        if (tsop.Receiving) {
            timer = ReadTimer1();

            if (timer > 0 && timer <= LOW_TIME) {
                putch('0');
                Buffer.Val &= (((unsigned long) 1 << pos++) ^ 0xFFFFFFFF);
            } else if (timer > LOW_TIME && timer <= HIGH_TIME) {
                putch('1');
                Buffer.Val |= ((unsigned long) 1 << pos++);
            } else {
                pos = 0;
            }

            if (pos >= 32) {
                tsop.Ready = 1;
                tsop.Receiving = 0;
            }
        } else {
            tsop.Receiving = 1;
        }

        WriteTimer1(0);

        INTCONbits.INT0IF = 0; // Clear Timer 0 interrupt flag
    }
}

void micros_interrupt(void) {
    if (PIE2bits.TMR3IE && PIR2bits.TMR3IF) {
        timestamp += 21845;
        PIR2bits.TMR3IF = 0;
    }
}

char is_tsop_receiving(void) {
    return tsop.Receiving;
}

unsigned long long micros(void) {
    return timestamp + (ReadTimer3() / 3);
}