/*
 * peripherals.c
 *
 *  Created on: Jan 29, 2014
 *      Author: deemer
 *  Updated on Jan 3, 2016
 *  	smj
 *  Updated on Jan 14, 2018
 *      smj
 *  Updated on Aug 22, 2018
 *      smj
  *  Updated on Jan 9, 2019
 *      smj
 *
 */

#include "peripherals.h"


// Globals
tContext g_sContext;    // user defined type used by graphics library
unsigned int allFrequencies[] = {1,41,44,49,52,55,62,65,73,84,87,92,98,104,110,117, 123,131,139,147,156,156,165,175,185,196,208,220,233,247,262,262,277,277,294,311,330,349,370,392,415,440,466,494,523,554,587,622,622,659,698,740,784,831,831,880,932,932,988,1047, 1109, 1175, 1245, 1319, 1397, 1480, 1568, 1661, 1760, 1865, 1976, 2093, 2217, 2349, 2489, 2637, 2794, 2960, 3136, 3322, 3520, 3729, 3951, 4186, 4435, 4699, 4978};



void initLeds(void)
{
    // Configure LEDs as outputs, initialize to logic low (off)
    // Note the assigned port pins are out of order test board
    // Red     P6.2 D1
    // Green   P6.1 D2
    // Blue    P6.3 D3
    // Yellow  P6.4 D4
    // smj -- 27 Dec 2016

    P6SEL &= ~(BIT4|BIT3|BIT2|BIT1);
    P6DIR |=  (BIT4|BIT3|BIT2|BIT1);
    P6OUT &= ~(BIT4|BIT3|BIT2|BIT1);
}

void initButtons(void)
{
    P7SEL &= ~(BIT0|BIT4);
    P2SEL &= ~(BIT2);
    P3SEL &= ~(BIT6);       //Selecting buttons for I/O

    P7DIR &= ~(BIT0|BIT4);
    P2DIR &= ~(BIT2);
    P3DIR &= ~(BIT6);       //Selecting buttons for INPUT (0)

    P7REN |=  (BIT0|BIT4);
    P2REN |=  (BIT2);
    P3REN |=  (BIT6);       //Enabling pull resistors

    P7OUT |=  (BIT0|BIT4);
    P2OUT |=  (BIT2);
    P3OUT |=  (BIT6);       //Setting pull resistors to pull UP

}

char getButtons(void)
{
    //  S1   S2   S3   S4
    //  7.0  3.6  2.2  7.4
    char s1=0,s2=0,s3=0,s4=0,ret=0x00;

    s1 = (~P7IN & BIT0);    //s1 is 1 if P7.0 is 0
    s2 = (~P3IN & BIT6);    //button is pressed if value is zero!
    s3 = (~P2IN & BIT2);
    s4 = (~P7IN & BIT4);


    if(s1)
        ret |= BIT0;
    if(s2)
        ret |= BIT1;
    if(s3)
        ret |= BIT2;
    if(s4)
        ret |= BIT3;

    return ret;

}

void userLEDs(char inbits)
{
    P1SEL &= ~(BIT0); //Select LED1 for I/O
    P4SEL &= ~(BIT7); //Select LED2 for I/O

    P1DIR |=  (BIT0); //Select LED1 for output
    P4DIR |=  (BIT7); //Select LED2 for output
    //inbits--;
    //inbits &= (BIT0|BIT1); //Mask inbits to only two LSB

    switch(inbits)
    {
        case 0:
        {
            P1OUT &= ~(BIT0);   //LED1 Output = 0
            P4OUT &= ~(BIT7);   //LED2 Output = 0
            break;
        }
        case 1:
        {
            P1OUT |=  (BIT0);   //LED1 Output = 1
            P4OUT &= ~(BIT7);   //LED2 Output = 0
            break;
        }
        case 2:
        {
            P1OUT &= ~(BIT0);   //LED1 Output = 0
            P4OUT |=  (BIT7);   //LED2 Output = 1
            break;
        }
        case 3:
        {
            P1OUT |=  (BIT0);   //LED1 Output = 1
            P4OUT |=  (BIT7);   //LED2 Output = 1
            break;
        }
        default: //Iferror, 1
        {
            P1OUT |=  (BIT0);   //LED1 Output = 1
            P4OUT |=  (BIT7);   //LED2 Output = 1
            break;
        }
    }
}



void setLeds(unsigned char state)
{
    // Turn on 4 colored LEDs on P6.1-6.4 to match the hex value
    // passed in on low nibble state. Unfortunately the LEDs are
    // out of order with 6.2 is the left most (i.e. what we think
    // of as MSB), then 6.1 followed by 6.3 and finally 6.4 is
    // the right most (i.e.  what we think of as LSB) so we have
    // to be a bit clever in implementing our LEDs
    //
    // Input: state = hex values to display (in low nibble)
    // Output: none
    //

    // Turn all LEDs off to start
    //if(state != REST)
      //  state = (state%4)+1;    //If state is not a rest
    //else
      //  state = 0;

    P6OUT &= ~(BIT4|BIT3|BIT2|BIT1);

    if (state == 1)
        P6OUT |= BIT2;  //Leftmost
    else if (state == 2)
        P6OUT |= BIT1;  //Second from left
    else if (state == 3)
        P6OUT |= BIT3;  //Second from right
    else if (state == 4)
        P6OUT |= BIT4;  //Rightmost
    else if (state == 0)
        P6OUT &= ~(BIT2|BIT1|BIT3|BIT4);
    else
        P6OUT &= ~(BIT2|BIT1|BIT3|BIT4);

}


/*
 * Enable a PWM-controlled buzzer on P3.5
 * This function makes use of TimerB0.
 */

void BuzzerOnFreq(int freq)
{
    //freq /= 2;
    // Initialize PWM output on P3.5, which corresponds to TB0.5
    P3SEL |= BIT5; // Select peripheral output mode for P3.5
    P3DIR |= BIT5;

    TB0CTL  = (TBSSEL__ACLK|ID__1|MC__UP);  // Configure Timer B0 to use ACLK, divide by 1, up mode
    TB0CTL  &= ~TBIE;                       // Explicitly Disable timer interrupts for safety

    // Now configure the timer period, which controls the PWM period
    TB0CCR0   = 32768 / allFrequencies[freq];           // Set the PWM period in ACLK ticks
    TB0CCTL0 &= ~CCIE;                  // Disable timer interrupts

    // Configure CC register 5, which is connected to our PWM pin TB0.5
    TB0CCTL5  = OUTMOD_7;                   // Set/reset mode for PWM
    TB0CCTL5 &= ~CCIE;                      // Disable capture/compare interrupts
    TB0CCR5   = TB0CCR0/2;                  // Configure a 50% duty cycle
}

void BuzzerOnFreqTwo(int freq)
{
    // Initialize PWM output on P1.2, which corresponds to TA0.1
    P1SEL |= BIT2; // Select peripheral output mode for P1.2
    P1DIR |= BIT2;

    TA0CTL  = (TASSEL__ACLK|ID__1|MC__UP);  // Configure Timer B0 to use ACLK, divide by 1, up mode
    TA0CTL  &= ~TBIE;                       // Explicitly Disable timer interrupts for safety

    // Now configure the timer period, which controls the PWM period
    TA0CCR0   = 32768 / allFrequencies[freq];           // Set the PWM period in ACLK ticks
    TA0CCTL0 &= ~CCIE;                  // Disable timer interrupts

    // Configure CC register 5, which is connected to our PWM pin TB0.5
    TA0CCTL1  = OUTMOD_7;                   // Set/reset mode for PWM
    TA0CCTL1 &= ~CCIE;                      // Disable capture/compare interrupts
    TA0CCR1   = TA0CCR0/2;                  // Configure a 50% duty cycle
}

/*
 * Disable the buzzer on P3.5
 */
void BuzzerOff(void)
{
    // Disable both capture/compare periods
    TB0CCTL0 = 0;
    TB0CCTL5 = 0;
}

void BuzzerOffTwo(void)
{
    TA0CCTL0 = 0;
    TA0CCTL1 = 0;
}


void configKeypad(void)
{
    // Configure digital IO for keypad
    // smj -- 27 Dec 2015
    // Optimized/reduced:
    // nsb -- 01 Feb 2019

    P1SEL &= ~(BIT5|BIT4); //P1.4, 1.5 for I/O
    P2SEL &= ~(BIT5|BIT4); //P2.5, 2.4 for I/O
    P4SEL &= ~(BIT3);       //P4.3 for I/O

    P1DS  &= ~BIT2; //Reset P1 drive strength

    // Setting up columns
    P2DIR |= (BIT5|BIT4); //P2.5, 2.4 Output
    P1DIR |= BIT5; //P1.5 Output

    P2OUT |= (BIT5|BIT4); //P2.5, 2.4 High
    P1OUT |= BIT5; //P1.5 High

    // Setting up rows
    P1DIR &= ~BIT4; //Row 1.4 input
    P1REN |=  BIT4; //Row 1.4 REN
    P1OUT |=  BIT4; //Row 1.4 Pullup
    P4DIR &= ~BIT3; //Row 4.3 input
    P4REN |=  BIT3; //Row 4.3 REN
    P4OUT |=  BIT3; //Row 4.3 Pullup
}


unsigned char getKey(void)
{
    // Returns ASCII value of key pressed from keypad or 0.
    // Does not decode or detect when multiple keys pressed.
    // smj -- 27 Dec 2015
    // Updated -- 14 Jan 2018
    // Updated for MSP430 Hero -- nsb -- 01 Feb 2019

    // Set Col1 = ?, Col2 = ? and Col3 = ?
    unsigned char ret_val = 0;

    // Set Col1 = ?, Col2 = ? and Col3 = ?
    P1OUT &= ~BIT5;
    P2OUT |= (BIT5|BIT4);
    // Now check value from each rows
    if ((P4IN & BIT3)==0)
        ret_val = '1';
    if ((P1IN & BIT4)==0)
        ret_val = '*';
    P1OUT |= BIT5;

    // Set Col1 = ?, Col2 = ? and Col3 = ?
    P2OUT &= ~BIT4;
    // Now check value from each rows
    if ((P4IN & BIT3)==0)
        ret_val = '2';
    if ((P1IN & BIT4)==0)
        ret_val = '0';
    P2OUT |= BIT4;

    // Set Col1 = ?, Col2 = ? and Col3 = ?
    P2OUT &= ~BIT5;
    // Now check value from each rows
    if ((P4IN & BIT3)==0)
        ret_val = '3';
    if ((P1IN & BIT4)==0)
        ret_val = '#';
    P2OUT |= BIT5;

    return(ret_val);
}


void configDisplay(void)
{
    // Enable use of external clock crystals
     P5SEL |= (BIT5|BIT4|BIT3|BIT2);

	// Initialize the display peripheral
	Sharp96x96_Init();

    // Configure the graphics library to use this display.
	// The global g_sContext is a data structure containing information the library uses
	// to send commands for our particular display.
	// You must pass this parameter to each graphics library function so it knows how to
	// communicate with our display.
    Graphics_initContext(&g_sContext, &g_sharp96x96LCD);


    Graphics_setForegroundColor(&g_sContext, ClrBlack);
    Graphics_setBackgroundColor(&g_sContext, ClrWhite);
    Graphics_setFont(&g_sContext, &g_sFontFixed6x8);
    Graphics_clearDisplay(&g_sContext);
    Graphics_flushBuffer(&g_sContext);
}

//Start timer
void runTimer(void)
{
    // From Users Guide Ch 17
     // Use ACLK (TASSEL_1), clock divider of 1 (ID_0)
     // and start timer counting in Up mode (MC_1)

    TA2CTL = TASSEL_1 + MC_1 + ID_0;
    TA2CCR0 = 163;      //~1/200 seconds
    TA2CCTL0 = CCIE;    // TA2CCR0 interrupt enabled
}

void stopTimer(void)
{
    TA2CTL = MC_0;      //Stop timer counting
    TA2CCTL0 &= ~CCIE;  //TA2CCR0 interrupt disabled
}


/*
void setupSPI_DAC(void)
{
// ** Set UCSI A0 Reset=1 to configure control registers **
     UCB0CTL1 |= UCSWRST;
     // 3-pin (SCLK, SIMO, SOMI), 8-bit, this MSP430 is SPI master,
     // Clock polarity high, send data MSB first
     UCB0CTL0 = UCMST + UCSYNC + UCCKPH + UCMSB;
     // Use SMCLK as clock source, keep RESET = 1
     UCB0CTL1 = UCSWRST + UCSSEL_2;

     UCB0BR0 = 2;   // SCLK = SMCLK/2 = 524288Hz
     UCB0BR1 = 0;

     //UCB0MCTL = 0;   // write MCTL as 0

     // Enable UCSI A0
     UCB0CTL1 &= ~UCSWRST;
}
*/

//------------------------------------------------------------------------------
// Timer1 A0 Interrupt Service Routine
//------------------------------------------------------------------------------
#pragma vector=TIMER1_A0_VECTOR
__interrupt void TIMER1_A0_ISR (void)
{
	// Display is using Timer A1
	// Not sure where Timer A1 is configured?
	Sharp96x96_SendToggleVCOMCommand();  // display needs this toggle < 1 per sec
}
