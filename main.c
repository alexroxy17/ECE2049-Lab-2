/*************        ECE2049      *****************/
/*************         LAB 1       *****************/
/***************************************************/
/************** Nathaniel Bajakian *****************/
/**************    Rosana Pochat   *****************/
/***************************************************/

#include <msp430.h>
#include "peripherals.h"

typedef enum {WELCOME,COUNTDOWN, PLAY, LOSE, WIN} eState;


// Function Prototypes
void swDelay(char numLoops);
void swDelay2(char numLoops);
void playNote(Note* note);
void resetGlobals(void);


volatile unsigned int count=0, sixteenths=0,note=0,duration,sixteenthsPassed=0;
#pragma vector=TIMER2_A0_VECTOR
__interrupt void TimerA2_ISR(void)
{
    count++;
    if (count % 16 == 0)
        sixteenths++;
}


/******************************MAIN FUNCTION*******************************/
void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;    // Stop watchdog timer. Always need to stop this!!
                                 // You can then configure it properly, if desired

    Note SONGOFSTORMS [] = {
                                /*  SIXTEEN = 1; EIGHT = 2; FOURTH = 4; HALF = 8; FULL = 16*/
                                /* THIRTYSECOND = 1 SIXTEEN = 2; EIGHT = 4; FOURTH = 8; HALF = 16; FULL = 32*/
                              {NOTE_D4,  EIGHTH, 0},
                              {NOTE_F4,  EIGHTH, 0},
                              {NOTE_D5,  FOURTH, 0},

                              {NOTE_D4,  EIGHTH, 0},
                              {NOTE_F4,  EIGHTH, 0},
                              {NOTE_D5,  FOURTH, 0},

                              {NOTE_E5,  FOURTH + EIGHTH, 0},
                              {NOTE_F5,  EIGHTH, 0},
                              {NOTE_E5,  EIGHTH, 0},
                              {NOTE_F5,  EIGHTH, 0}, //10
                              //E4 D4 A4
                              {NOTE_E5,  EIGHTH, 0},
                              {NOTE_D5,  EIGHTH, 0},
                              {NOTE_A4,  HALF - 1, 0},
                              {REST, 1, 0},

                              {NOTE_A4,  FOURTH, 0},
                              {NOTE_D4,  FOURTH, 0},
                              {NOTE_F4,  EIGHTH, 0},
                              {NOTE_G4,  EIGHTH, 0},

                              {NOTE_A4,  HALF + EIGHTH - 1, 0},
                              {REST, 1, 0},    //20

                              {NOTE_A4,  FOURTH, 0},
                              {NOTE_D4,  FOURTH, 0},
                              {NOTE_F4,  EIGHTH, 0},
                              {NOTE_G4,  EIGHTH, 0},

                              {NOTE_F4,  HALF + EIGHTH, 0},//25
                              //Midpoint, start over
                              {NOTE_D4,  EIGHTH, 0},
                              {NOTE_F4,  EIGHTH, 0},
                              {NOTE_D5,  HALF 0},

                              {NOTE_D4,  EIGHTH, 0},
                              {NOTE_F4,  EIGHTH, 0},
                              {NOTE_D5,  HALF 0},

                              {NOTE_E5,  FOURTH + EIGHTH, 0},
                              {NOTE_F5,  EIGHTH, 0},
                              {NOTE_E5,  EIGHTH, 0},
                              {NOTE_F5,  EIGHTH, 0}, //35
                              //E4 D4 A4
                              {NOTE_E5,  EIGHTH, 0},
                              {NOTE_D5,  EIGHTH, 0},
                              {NOTE_A4,  HALF - 1, 0},
                              {REST, 1, 0},

                              {NOTE_A4,  FOURTH, 0},
                              {NOTE_D4,  FOURTH, 0},
                              {NOTE_F4,  EIGHTH, 0},
                              {NOTE_G4,  EIGHTH, 0},

                              {NOTE_A4,  HALF + EIGHTH - 1, 0},
                              {REST, 1, 0},     //45

                              {NOTE_A4,  FOURTH 0},
                              {NOTE_D4,  FOURTH 0},
                              {NOTE_F4,  EIGHTH, 0},
                              {NOTE_G4,  EIGHTH, 0},

                              {NOTE_F4,  10, 0} //50
    };

    //Initialization
    initLeds();       //Initialize LEDs
    configDisplay();  //Configure 96x96 display
    configKeypad();   //Configure keypad
    initButtons();    //Configure buttons
    eState state = WELCOME; //Set initial state to welcome

    // Using msp430.h definitions
     _BIS_SR(GIE); // Global Interrupt enable VERY IMPORTANT

    /******************************MAIN LOOP*******************************/
    while (1)    // Forever loop
    {
        switch(state)
        {
        case WELCOME: //Dislay welcome screen
        {
            BuzzerOff();
            Graphics_clearDisplay(&g_sContext); // Clear the display
            Graphics_Rectangle box = {.xMin = 2, .xMax = 94, .yMin = 2, .yMax = 94 };     // Draw a box around everything because it looks nice
            Graphics_drawRectangle(&g_sContext, &box);
            Graphics_drawStringCentered(&g_sContext, "MSP Hero", AUTO_STRING_LENGTH, 48, 15, TRANSPARENT_TEXT);
            Graphics_drawStringCentered(&g_sContext, "by", AUTO_STRING_LENGTH, 48, 25, TRANSPARENT_TEXT);              //Writing text
            Graphics_drawStringCentered(&g_sContext, "Nate & Rosana", AUTO_STRING_LENGTH, 48, 35, TRANSPARENT_TEXT);
            Graphics_drawStringCentered(&g_sContext, "Press * to", AUTO_STRING_LENGTH, 48, 75, TRANSPARENT_TEXT);
            Graphics_drawStringCentered(&g_sContext, "start", AUTO_STRING_LENGTH, 48, 85, TRANSPARENT_TEXT);
            Graphics_flushBuffer(&g_sContext);                                                                         //Refreshing screen

            volatile unsigned int moveOn = 0;   //Wait flag
            char currKey;                       //Holds current key
            while(moveOn == 0)
            {
                currKey = getKey();
                if(currKey == '*')  //Query for star key, WAIT FOR INPUT
                    moveOn = 1;
            }
            state = COUNTDOWN;

            break;
        }

        case COUNTDOWN: //Countdown from 3 to 1, with ~1 second interval
        {
            uint8_t* readyText = "Get ready!";         //Using this to avoid CCS complaining at me
            uint8_t* countdown[3] = {"3", "2", "1"};   //Using this to have a loop instead of three seperate write blocks
            runTimer();
            volatile unsigned int i;
            for(i=0;i<3;i++)
            {
                Graphics_clearDisplay(&g_sContext); // Clear the display
                Graphics_drawStringCentered(&g_sContext, readyText, AUTO_STRING_LENGTH, 48, 15, TRANSPARENT_TEXT);
                Graphics_drawStringCentered(&g_sContext, countdown[i], AUTO_STRING_LENGTH, 48, 25, TRANSPARENT_TEXT);
                Graphics_flushBuffer(&g_sContext);
                BuzzerOnFreq(3520);
                swDelay(1);
                BuzzerOff();
                swDelay(7);
            }
            Graphics_clearDisplay(&g_sContext);
            sixteenths = 0;
            state = PLAY;
            break;
        }

        case PLAY:
        {
            playNote(&SONGOFSTORMS[note]);
            volatile unsigned int loc_sixteenths = sixteenths; //sixteenths arises from the global interrupts
            duration = SONGOFSTORMS[note].duration;

            if(loc_sixteenths - sixteenthsPassed == duration)
            {
                note++;
                sixteenthsPassed = loc_sixteenths;
                BuzzerOff();
            }
            if(note >= 50)
            {
                state = LOSE;
            }
            break;
        }


        case LOSE:
        {
            Graphics_clearDisplay(&g_sContext); // Clear the display
            BuzzerOff();    //Reset buzzer
            setLeds(0);     //Reset LEDs
            resetGlobals(); //Reset globals

            Graphics_drawStringCentered(&g_sContext, "GAME", AUTO_STRING_LENGTH, 48, 15, TRANSPARENT_TEXT);
            Graphics_drawStringCentered(&g_sContext, "OVER", AUTO_STRING_LENGTH, 48, 25, TRANSPARENT_TEXT);
            Graphics_drawStringCentered(&g_sContext, "To return:", AUTO_STRING_LENGTH, 48, 75, TRANSPARENT_TEXT);
            Graphics_drawStringCentered(&g_sContext, "Press *", AUTO_STRING_LENGTH, 48, 85, TRANSPARENT_TEXT);
            Graphics_flushBuffer(&g_sContext);

            volatile unsigned int moveOn = 0;
            while(moveOn == 0)
            {
                char currKey = getKey();
                if(currKey == '*')    //Wait for user to press * key
                    moveOn = 1;
            }
            state = WELCOME;
        }
        }//End switch
    }  // end while (1)
}//End main




void playNote(Note* note)
{
    BuzzerOnFreq(note->pitch);
}

void resetGlobals(void)
{
    note = 0;
    sixteenthsPassed = 0;
    sixteenths = 0;
    count = 0;
    duration = 0;
}




void swDelay(char numLoops)
{
    // This function is a software delay. It performs
    // useless loops to waste a bit of time
    //
    // Input: numLoops = number of delay loops to execute
    // Output: none
    //
    // smj, ECE2049, 25 Aug 2013

    volatile unsigned int i,j;  // volatile to prevent removal in optimization
                                // by compiler. Functionally this is useless code
    for (j=0; j<numLoops; j++)
    {
        i = 10000 ;     // SW Delay
        while (i > 0)   // could also have used while (i)
           i--;
    }
}
void swDelay2(char numLoops)
{
    // This function is a software delay. It performs
    // useless loops to waste a bit of time. Less time than
    // swDelay.
    //
    // Input: numLoops = number of delay loops to execute
    // Output: none
    //
    // nsb, ECE2049, 22 Jan 2019

    volatile unsigned int i,j;

    for (j=0; j<numLoops; j++)
    {
        i = 100 ;                   // SW Delay
        while (i > 0)               // could also have used while (i)
           i--;
    }
}
