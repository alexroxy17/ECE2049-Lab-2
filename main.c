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
void playNoteTwo(Note* note);
void resetGlobals(void);


volatile unsigned int count=0, sixteenths=0,noteOne=0,noteTwo=0,durationOne,durationTwo,sixteenthsPassed=0, sixteenthsPassedTwo=0;
#pragma vector=TIMER2_A0_VECTOR
__interrupt void TimerA2_ISR(void)
{
    count++;
    if (count % 18 == 0) //165 bpm
        sixteenths++;
}


/******************************MAIN FUNCTION*******************************/
void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;    // Stop watchdog timer. Always need to stop this!!
                                 // You can then configure it properly, if desired
    Note GAMEOFTHRONES[] = {

                            {NOTE_G4, 4, 0}, //Patt1
                            {NOTE_C4, 4, 0},
                            {NOTE_Ds4, 2, 0},
                            {NOTE_F4, 2, 0},

                            {NOTE_G4, 4, 0}, //Patt1
                            {NOTE_C4, 4, 0},
                            {NOTE_Ds4, 2, 0},
                            {NOTE_F4, 2, 0},

                            {NOTE_G4, 4, 0}, //Patt 1
                            {NOTE_C4, 4, 0},
                            {NOTE_Ds4, 2, 0},
                            {NOTE_F4, 2, 0},

                            {NOTE_G4, 4, 0}, //Patt 1
                            {NOTE_C4, 4, 0},
                            {NOTE_Ds4, 2, 0},
                            {NOTE_F4, 2, 0},

                            {NOTE_G4, 4, 0}, //Patt 2
                            {NOTE_C4, 4, 0},
                            {NOTE_E4, 2, 0},
                            {NOTE_F4, 2, 0},

                            {NOTE_G4, 4, 0}, //Patt 2
                            {NOTE_C4, 4, 0},
                            {NOTE_E4, 2, 0},
                            {NOTE_F4, 2, 0},

                            {NOTE_G4, 4, 0}, //Patt 2
                            {NOTE_C4, 4, 0},
                            {NOTE_E4, 2, 0},
                            {NOTE_F4, 2, 0},

                            {NOTE_G4, 4, 0}, //Patt 2
                            {NOTE_C4, 4, 0},
                            {NOTE_E4, 2, 0},
                            {NOTE_F4, 2, 0},

                            {NOTE_G4, 12, 0},
                            {NOTE_C4, 12, 0},

                            {NOTE_C4, 1, 0},
                            {NOTE_E4, 2, 0},
                            {NOTE_F4, 2, 0},
                            {NOTE_G4, 8, 0},

                            {NOTE_C4, 8, 0},
                            {NOTE_E4, 2, 0},
                            {NOTE_F4, 2, 0},

                            {NOTE_B3, 4, 0},
                            {NOTE_D4, 4, 0},
                            {NOTE_G3, 4, 0},
                            {NOTE_B3, 2, 0},
                            {NOTE_C4, 2, 0},
    };

    Note SONGOFSTORMS [] = {
                              /*  SIXTEEN = 1; EIGHT = 2; FOURTH = 4; HALF = 8; FULL = 16*/
                              {NOTE_D4,  2, 0},
                              {NOTE_F4,  2, 0},
                              {NOTE_D5,  8, 0},

                              {NOTE_D4,  2, 0},
                              {NOTE_F4,  2, 0},
                              {NOTE_D5,  8, 0},

                              {NOTE_E5,  6, 0},
                              {NOTE_F5,  2, 0},
                              {NOTE_E5,  2, 0},
                              {NOTE_F5,  2, 0}, //10
                              //E4 D4 A4
                              {NOTE_E5,  2, 0},
                              {NOTE_C5,  2, 0}, //Corrected from D5
                              {NOTE_A4,  7, 0},
                              {REST, 1, 0},

                              {NOTE_A4,  4, 0},
                              {NOTE_D4,  4, 0},
                              {NOTE_F4,  2, 0},
                              {NOTE_G4,  2, 0},

                              {NOTE_A4,  9, 0},
                              {REST, 1, 0},    //20

                              {NOTE_A4,  4, 0},
                              {NOTE_D4,  4, 0},
                              {NOTE_F4,  2, 0},
                              {NOTE_G4,  2, 0},

                              {NOTE_F4,  10, 0},//25
                              //Midpoint, start over
                              {NOTE_D4,  2, 0},
                              {NOTE_F4,  2, 0},
                              {NOTE_D5,  8, 0},

                              {NOTE_D4,  2, 0},
                              {NOTE_F4,  2, 0},
                              {NOTE_D5,  8, 0},

                              {NOTE_E5,  6, 0},
                              {NOTE_F5,  2, 0},
                              {NOTE_E5,  2, 0},
                              {NOTE_F5,  2, 0}, //35
                              //E4 D4 A4
                              {NOTE_E5,  2, 0},
                              {NOTE_C5,  2, 0},
                              {NOTE_A4,  7, 0},
                              {REST, 1, 0},

                              {NOTE_A4,  4, 0},
                              {NOTE_D4,  4, 0},
                              {NOTE_F4,  2, 0},
                              {NOTE_G4,  2, 0},

                              {NOTE_A4,  7, 0},
                              {REST, 1, 0},     //45

                              {NOTE_A4,  4, 0},
                              {NOTE_D3,  4, 0},
                              {NOTE_D4,  3, 0},
                              {REST, 1, 0},
                              {NOTE_D4,  4, 0},

                              {REST, 2, 0},
                              {NOTE_E3, 2, 0},
                              {NOTE_E4, 4, 0},

                              {REST, 4, 0},
                              {NOTE_F4, 4, 0},
                              {NOTE_F4, 4, 0},

                              {REST, 2, 0},
                              {NOTE_E3, 2, 0},
                              {NOTE_E4, 4, 0},

                              {REST, 4, 0},
                              {NOTE_D4, 4, 0},
                              {NOTE_D4, 4, 0},

                              {REST, 2, 0},
                              {NOTE_E4, 2, 0},
                              {NOTE_E5, 8, 0},

                              {REST, 4, 0},
                              {NOTE_F5, 3, 0},
                              {REST, 1, 0},
                              {NOTE_F5, 4, 0},

                              {REST, 2, 0},
                              {NOTE_E4, 2, 0},
                              {NOTE_E5, 8, 0},

                              {NOTE_D5, 2, 0},
                              {NOTE_F5, 2, 0},
                              {NOTE_D6, 8, 0},

                              {NOTE_D5, 2, 0},
                              {NOTE_F5, 2, 0},
                              {NOTE_D6, 8, 0},

                              {NOTE_E6, 6, 0},
                              {NOTE_F6, 2, 0},
                              {NOTE_E6, 2, 0},
                              {NOTE_F6, 2, 0},

                              {NOTE_E6, 2, 0},
                              {NOTE_C6, 2, 0},
                              {NOTE_A5, 8, 0},

                              {NOTE_A5, 4, 0},
                              {NOTE_D5, 4, 0},
                              {NOTE_F5, 2, 0},
                              {NOTE_G5, 2, 0},

                              {NOTE_A5, 11, 0},
                              {REST, 1, 0},

                              {NOTE_A5, 4, 0},
                              {NOTE_D5, 4, 0},
                              {NOTE_F5, 1, 0},
                              {REST, 1, 0},
                              {NOTE_F5, 2, 0},

                              {NOTE_E5, 12, 0},

                              {NOTE_D5, 2, 0},
                              {NOTE_F5, 2, 0},
                              {NOTE_D6, 8, 0},

                              {NOTE_D5, 2, 0},
                              {NOTE_F5, 2, 0},
                              {NOTE_D6, 8, 0},

                              {NOTE_E6, 6, 0},
                              {NOTE_F6, 2, 0},
                              {NOTE_E6, 2, 0},
                              {NOTE_F6, 2, 0},

                              {NOTE_E6, 2, 0},
                              {NOTE_C6, 2, 0},
                              {NOTE_A5, 8, 0},

                              {NOTE_A5, 4, 0},
                              {NOTE_D5, 4, 0},
                              {NOTE_F5, 2, 0},
                              {NOTE_G5, 2, 0},

                              {NOTE_A5, 3, 0},
                              {REST, 1, 0},
                              {NOTE_A5, 3, 0},
                              {REST, 1, 0},
                              {NOTE_A4, 10, 0}, //119
                              {NOTE_E5, 12, 0}
    };

    //Initialization
    initLeds();       //Initialize LEDs
    configDisplay();  //Configure 96x96 display
    configKeypad();   //Configure keypad
    //initButtons();    //Configure buttons
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
            BuzzerOffTwo();
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
            playNoteTwo(&SONGOFSTORMS[noteOne]);
            //playNoteTwo(&GAMEOFTHRONES[noteTwo]);

            volatile unsigned int loc_sixteenths = sixteenths, loc_sixteenths_two = sixteenths; //sixteenths arises from the global interrupts
            durationOne = SONGOFSTORMS[noteOne].duration;
            durationTwo = GAMEOFTHRONES[noteTwo].duration;

            if(loc_sixteenths - sixteenthsPassed == durationOne)
            {
                noteOne++;
                sixteenthsPassed = loc_sixteenths;
                BuzzerOffTwo();
            }

            if(loc_sixteenths_two - sixteenthsPassedTwo == durationTwo)
            {
                noteTwo++;
                sixteenthsPassedTwo = loc_sixteenths_two;
                BuzzerOffTwo();
            }
                          //GOT: 46 SOS: 119
            if(noteOne >= 165) //Replace with Song.noteCount later
            {
                state = LOSE;
            }
            break;
        }


        case LOSE:
        {
            Graphics_clearDisplay(&g_sContext); // Clear the display
            BuzzerOffTwo();    //Reset buzzer
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

void playNoteTwo(Note* note)
{
    BuzzerOnFreqTwo(note->pitch);
}

void resetGlobals(void)
{
    noteOne = 0;
    sixteenthsPassed = 0;
    sixteenths = 0;
    count = 0;
    durationOne = 0;
    durationTwo = 0;
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
