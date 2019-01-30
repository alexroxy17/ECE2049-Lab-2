/*************        ECE2049      *****************/
/*************         LAB 1       *****************/
/***************************************************/
/************** Nathaniel Bajakian *****************/
/**************    Rosana Pochat   *****************/
/***************************************************/

#include <msp430.h>
#include <stdlib.h>
#include "peripherals.h"


typedef struct {
    unsigned int pitch;         //Note pitch
    unsigned int duration;      //Note duration
    char LED;                   //LEDs to light for each note
} Note; //40 bits per note, 2.5 bytes


//typedef enum {S_MENU, S_COUNTDOWN, S_PLAY, S_LOSE, S_WIN} state;
typedef enum {WELCOME, PRECOUNT, COUNTDOWN, PLAY, LOSE, WIN} eState;


// Function Prototypes
void swDelay(char numLoops);
void swDelay2(char numLoops);
void runTimer(void);



/*****************************GLOBALS******************************/


volatile unsigned int i,j,k,row,col;    //Global, temporary vars

/******************************MAIN FUNCTION*******************************/
void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;    // Stop watchdog timer. Always need to stop this!!
                                 // You can then configure it properly, if desired

    //Initialization
    initLeds();       //Initialize LEDs
    configDisplay();  //Configure 96x96 display
    configKeypad();   //Configure keypad
    initButtons();    //Configure buttons
    eState state = WELCOME; //Set initial state to welcome



    /******************************MAIN LOOP*******************************/
    while (1)    // Forever loop
    {
        switch(state)
        {
        case WELCOME: //Dislay welcome screen
        {

            Graphics_clearDisplay(&g_sContext); // Clear the display
            Graphics_Rectangle box = {.xMin = 2, .xMax = 94, .yMin = 2, .yMax = 94 };     // Draw a box around everything because it looks nice
            Graphics_drawRectangle(&g_sContext, &box);
            Graphics_drawStringCentered(&g_sContext, "MSP Hero", AUTO_STRING_LENGTH, 48, 15, TRANSPARENT_TEXT);
            Graphics_drawStringCentered(&g_sContext, "by", AUTO_STRING_LENGTH, 48, 25, TRANSPARENT_TEXT);              //Writing text
            Graphics_drawStringCentered(&g_sContext, "Nate & Rosana", AUTO_STRING_LENGTH, 48, 35, TRANSPARENT_TEXT);
            Graphics_drawStringCentered(&g_sContext, "Press * to", AUTO_STRING_LENGTH, 48, 75, TRANSPARENT_TEXT);
            Graphics_drawStringCentered(&g_sContext, "start", AUTO_STRING_LENGTH, 48, 85, TRANSPARENT_TEXT);
            Graphics_flushBuffer(&g_sContext);                                                                         //Refreshing screen
            state = PRECOUNT; //Wait for input
            break;
        }

        case PRECOUNT: //Resets a whole lotta variables while the player is prompted to press a button.
        {
            volatile unsigned int moveOn = 0;
            char currKey;
            while(moveOn == 0)
            {
                currKey = getKey();
                if(currKey == '*')  //Query for star key
                    moveOn = 1;
            }
            state = COUNTDOWN;
        }

        case COUNTDOWN: //Countdown from 3 to 1, with ~1 second interval
        {
            uint8_t* readyText = "Get ready!";         //Using this to avoid CCS complaining at me
            uint8_t* countdown[3] = {"3", "2", "1"};   //Using this to have a loop instead of three seperate write blocks
            runTimer();
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
            /*
            BuzzerOnFreq(440);
            updateScreen();
            swDelay(12);
            BuzzerOff();
            */

            state = MAINSTATE;
            break;
        }
        case MAINSTATE: //Draw Aliens
        {
            break;
        }//End of maincase

        case NEXTLEVEL:
        {

            state = MAINSTATE;
            break;
        }

        case GAMEOVER:
        {
            Graphics_clearDisplay(&g_sContext); // Clear the display

            /*/-----------Resetting globals-----------//
            isDead      = 0;
            level       = 0;
            clearLevel  = 0;                         */
            setLeds(0);

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
