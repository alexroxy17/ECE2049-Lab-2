/*************        ECE2049      *****************/
/*************         LAB 1       *****************/
/***************************************************/
/************** Nathaniel Bajakian *****************/
/**************    Rosana Pochat   *****************/
/***************************************************/

#include <msp430.h>
#include "peripherals.h"
#include "songs.h"


typedef enum {WELCOME,MENU,MENUPAGE2,COUNTDOWN, PLAY, LOSE, WIN, QUIT, DIFFICULTYSELECT} eState;


// Function Prototypes
void swDelay(char numLoops);
void swDelay2(char numLoops);
void playNote(Note* note);
void playNoteTwo(Note* note);
void resetGlobals(void);


volatile unsigned int count=0, sixteenths=0,noteOne=0,noteTwo=0,durationOne,durationTwo,sixteenthsPassed=0, sixteenthsPassedTwo=0, wrongNotes = 0, totalWrongNotes=0, difficulty = 1, demo = 0;
char tempo = 18;    //init tempo to 165 bpm


#pragma vector=TIMER2_A0_VECTOR
__interrupt void TimerA2_ISR(void)
{
    count++;
    if (count % (tempo*difficulty) == 0) //18=165 bpm, 30 = 100bpm
        sixteenths++;
}


/******************************MAIN FUNCTION*******************************/
void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;    // Stop watchdog timer. Always need to stop this!!
                                 // You can then configure it properly, if desired

    //Initialization
    initLeds();       //Initialize LEDs
    configDisplay();  //Configure 96x96 display
    configKeypad();   //Configure keypad
    //initButtons();    //Configure buttons
    eState state = WELCOME; //Set initial state to welcome
    Graphics_Rectangle box = {.xMin = 2, .xMax = 94, .yMin = 2, .yMax = 94 };     // Draw a box around everything because it looks nice
    char song = 0;
    Song songList[5] = {gravityFalls, tetris, songOfStorms, interstellar, despacito};

    // Using msp430.h definitions
     _BIS_SR(GIE); // Global Interrupt enable VERY IMPORTANT

    /******************************MAIN LOOP*******************************/
    while (1)    // Forever loop
    {
        switch(state)
        {
        case WELCOME: //Dislay welcome screen
        {
            resetGlobals();
            BuzzerOff();
            BuzzerOffTwo();
            Graphics_clearDisplay(&g_sContext); // Clear the display
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
            state = MENU;

            break;
        }
        case MENU:
        {
            Graphics_clearDisplay(&g_sContext); // Clear the display
            Graphics_drawRectangle(&g_sContext, &box);
            Graphics_drawStringCentered(&g_sContext, "MENU: Choose a", AUTO_STRING_LENGTH, 48, 10, TRANSPARENT_TEXT);
            Graphics_drawStringCentered(&g_sContext, "song with 1-3", AUTO_STRING_LENGTH, 48, 20, TRANSPARENT_TEXT);

            Graphics_drawStringCentered(&g_sContext, "1:Grav. Falls", AUTO_STRING_LENGTH, 48, 40, TRANSPARENT_TEXT);
            Graphics_drawStringCentered(&g_sContext, "2:Tetris", AUTO_STRING_LENGTH, 48, 50, TRANSPARENT_TEXT);
            Graphics_drawStringCentered(&g_sContext, "3:Sng of Thrns", AUTO_STRING_LENGTH, 48, 60, TRANSPARENT_TEXT);
            Graphics_drawStringCentered(&g_sContext, "Press # for", AUTO_STRING_LENGTH, 48, 75, TRANSPARENT_TEXT);
            Graphics_drawStringCentered(&g_sContext, "next page", AUTO_STRING_LENGTH, 48, 85, TRANSPARENT_TEXT);
            Graphics_flushBuffer(&g_sContext);  //Draw to display

            volatile unsigned int moveOn = 0;   //Wait flag
            char currKey;                       //Holds current key
            while(moveOn == 0)
            {
                currKey = getKey();
                if(currKey == '1')  //Query for star key, WAIT FOR INPUT
                {
                    song = 0,state = DIFFICULTYSELECT,moveOn = 1;
                    break;
                }
                if(currKey == '2')  //Query for star key, WAIT FOR INPUT
                {
                    song = 1,state = DIFFICULTYSELECT,moveOn = 1;
                    break;
                }
                if(currKey == '3')  //Query for star key, WAIT FOR INPUT
                {
                    song = 2,state = DIFFICULTYSELECT,moveOn = 1;
                    break;
                }
                if(currKey == '#')  //Query for star key, WAIT FOR INPUT
                {
                    state = MENUPAGE2,moveOn = 1;
                    break;
                }
            }
            break;
        }

        case MENUPAGE2:
        {
            Graphics_clearDisplay(&g_sContext); // Clear the display
            Graphics_drawRectangle(&g_sContext, &box);
            Graphics_drawStringCentered(&g_sContext, "MENU: Choose a", AUTO_STRING_LENGTH, 48, 10, TRANSPARENT_TEXT);
            Graphics_drawStringCentered(&g_sContext, "song with 1-3", AUTO_STRING_LENGTH, 48, 20, TRANSPARENT_TEXT);

            Graphics_drawStringCentered(&g_sContext, "1:Interstellar", AUTO_STRING_LENGTH, 48, 40, TRANSPARENT_TEXT);
            Graphics_drawStringCentered(&g_sContext, "2:Despacito", AUTO_STRING_LENGTH, 48, 50, TRANSPARENT_TEXT);
            Graphics_drawStringCentered(&g_sContext, "Press * for", AUTO_STRING_LENGTH, 48, 75, TRANSPARENT_TEXT);
            Graphics_drawStringCentered(&g_sContext, "previous page", AUTO_STRING_LENGTH, 48, 85, TRANSPARENT_TEXT);
            Graphics_flushBuffer(&g_sContext);  //Draw to display

            volatile unsigned int moveOn = 0;   //Wait flag
            char currKey;                       //Holds current key
            while(moveOn == 0)
            {
                currKey = getKey();
                if(currKey == '1')  //Query for star key, WAIT FOR INPUT
                    song = 3,state = DIFFICULTYSELECT,moveOn = 1;
                if(currKey == '2')  //Query for star key, WAIT FOR INPUT
                    song = 4,state = DIFFICULTYSELECT,moveOn = 1;
                if(currKey == '*')  //Query for star key, WAIT FOR INPUT
                    state = MENU,moveOn = 1;
            }
            break;
        }

        case DIFFICULTYSELECT:
        {
            Graphics_clearDisplay(&g_sContext); // Clear the display
            Graphics_drawRectangle(&g_sContext, &box);
            Graphics_drawStringCentered(&g_sContext, "Choose your", AUTO_STRING_LENGTH, 48, 10, TRANSPARENT_TEXT);
            Graphics_drawStringCentered(&g_sContext, "difficulty", AUTO_STRING_LENGTH, 48, 20, TRANSPARENT_TEXT);
            Graphics_drawStringCentered(&g_sContext, "with 1-3.", AUTO_STRING_LENGTH, 48, 30, TRANSPARENT_TEXT);
            Graphics_drawStringCentered(&g_sContext, "0 for Demo", AUTO_STRING_LENGTH, 48, 40, TRANSPARENT_TEXT);

            Graphics_drawStringCentered(&g_sContext, "1:Childlike", AUTO_STRING_LENGTH, 48, 60, TRANSPARENT_TEXT);
            Graphics_drawStringCentered(&g_sContext, "2:Difficult", AUTO_STRING_LENGTH, 48, 70, TRANSPARENT_TEXT);
            Graphics_drawStringCentered(&g_sContext, "3:Impossible", AUTO_STRING_LENGTH, 48, 80, TRANSPARENT_TEXT);

            Graphics_flushBuffer(&g_sContext);  //Draw to display

            volatile unsigned int moveOn = 0;   //Wait flag
            char currKey;                       //Holds current key
            while(moveOn == 0)
            {
                currKey = getKey();
                if(currKey == '1')  //Query for star key, WAIT FOR INPUT
                {
                    difficulty = 4,state = COUNTDOWN,moveOn = 1;
                    break;
                }
                if(currKey == '2')  //Query for star key, WAIT FOR INPUT
                {
                    difficulty = 3,state = COUNTDOWN,moveOn = 1;
                    break;
                }
                if(currKey == '3')  //Query for star key, WAIT FOR INPUT
                {
                    difficulty = 1,state = COUNTDOWN,moveOn = 1;
                    break;
                }
                if(currKey == '0')  //Query for star key, WAIT FOR INPUT
                {
                    difficulty = 1,state = COUNTDOWN,moveOn = 1, demo = 1;
                    break;
                }
            }
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
                BuzzerOnFreq(NOTE_C5);
                swDelay(1);
                BuzzerOff();
                swDelay(7);
            }
            Graphics_clearDisplay(&g_sContext);

            Graphics_drawStringCentered(&g_sContext, "Press # to", AUTO_STRING_LENGTH, 48, 75, TRANSPARENT_TEXT);
            Graphics_drawStringCentered(&g_sContext, "exit", AUTO_STRING_LENGTH, 48, 85, TRANSPARENT_TEXT);
            Graphics_flushBuffer(&g_sContext);


            resetGlobals();
            if(songList[song].power)
                P1DS |=  BIT2;              //High drive strength
            else
                P1DS &= ~BIT2;              //Low drive strength

            tempo = songList[song].tempo;   //Set correct song tempo
            state = PLAY;
            break;
        }

        case PLAY:
        {
            //Implement demo mode!

            volatile unsigned int loc_sixteenths = sixteenths, loc_sixteenths_two = sixteenths; //sixteenths arises from the global interrupts
            char buttonPress = getButtons();
            char correctLED  = ((songList[song].smlSpeaker[noteTwo].pitch % 4)+1);
            if(songList[song].smlSpeaker[noteTwo].pitch == REST)
                correctLED = 0;

            //If rest, don't play any music
            if((&songList[song].bigSpeaker[noteOne] == REST) | (noteOne >= songList[song].bigSpeakerCount)) //If note is a rest or song is done
                BuzzerOffTwo();
            else
                playNoteTwo(&songList[song].bigSpeaker[noteOne]); //Else, play appropriate note with appropriate power

            if((&songList[song].smlSpeaker[noteTwo] == REST) | (noteTwo >= songList[song].smlSpeakerCount)) //If note is a rest or song is done
                BuzzerOff();
            else
                playNote   (&songList[song].smlSpeaker[noteTwo]);

            durationOne = songList[song].bigSpeaker[noteOne].duration;
            durationTwo = songList[song].smlSpeaker[noteTwo].duration;

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
                BuzzerOff();
                buttonPress = getButtons();
                /*
                if(buttonPress != correctLED)
                    totalWrongNotes++;
*/
            }

            if((noteOne >= songList[song].bigSpeakerCount) | (noteTwo >= songList[song].smlSpeakerCount))   //If song is over
            {
                BuzzerOffTwo();
                state = WIN;
            }

            if(getKey() == '#')
                state = QUIT;





            if(totalWrongNotes >= 15)
            {
                state = LOSE;
                break;
            }


            break;
        }


        case LOSE:
        {
            Graphics_clearDisplay(&g_sContext); // Clear the display
            BuzzerOff();    //Reset buzzers
            BuzzerOffTwo(); //Reset buzzers
            setLeds(REST);     //Reset LEDs
            resetGlobals(); //Reset globals
            stopTimer();    //Stop  timer
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
            break;
        }

        case WIN:
        {
            Graphics_clearDisplay(&g_sContext); // Clear the display
            BuzzerOff();    //Reset buzzers
            BuzzerOffTwo(); //Reset buzzers
            setLeds(REST);     //Reset LEDs
            resetGlobals(); //Reset globals
            stopTimer();    //Stop  timer
            Graphics_drawStringCentered(&g_sContext, "YOU", AUTO_STRING_LENGTH, 48, 15, TRANSPARENT_TEXT);
            Graphics_drawStringCentered(&g_sContext, "WIN!", AUTO_STRING_LENGTH, 48, 25, TRANSPARENT_TEXT);
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
            break;
        }

        case QUIT:
        {
            Graphics_clearDisplay(&g_sContext); // Clear the display
            BuzzerOff();    //Reset buzzers
            BuzzerOffTwo(); //Reset buzzers
            setLeds(REST);     //Reset LEDs
            resetGlobals(); //Reset globals
            stopTimer();    //Stop  timer
            Graphics_drawStringCentered(&g_sContext, "GAME", AUTO_STRING_LENGTH, 48, 15, TRANSPARENT_TEXT);
            Graphics_drawStringCentered(&g_sContext, "OVER:", AUTO_STRING_LENGTH, 48, 25, TRANSPARENT_TEXT);
            Graphics_drawStringCentered(&g_sContext, "You quit!", AUTO_STRING_LENGTH, 48, 50, TRANSPARENT_TEXT);
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
    setLeds(note->pitch);
}

void playNoteTwo(Note* note)
{
    BuzzerOnFreqTwo(note->pitch);
}

void resetGlobals(void)
{
    noteOne = 0;
    noteTwo = 0;
    sixteenthsPassed = 0;
    sixteenthsPassedTwo = 0;
    sixteenths = 0;
    sixteenths = 0;
    count = 0;
    durationOne = 0;
    durationTwo = 0;
    totalWrongNotes = 0;
    demo = 0;
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
