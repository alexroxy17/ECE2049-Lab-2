/*************        ECE2049      *****************/
/*************         LAB 1       *****************/
/***************************************************/
/************** Nathaniel Bajakian *****************/
/**************    Rosana Pochat   *****************/
/***************************************************/

#include <msp430.h>
#include "peripherals.h"
#include "songs.h"


typedef enum {WELCOME,MENU,MENUPAGE2,MENUPAGE3,GOTSELECT,DIFFICULTYSELECT,COUNTDOWN, PLAY, LOSE, WIN, QUIT, POST} eState;


// Function Prototypes
void swDelay(char waitTime);
void playNote(const Note* note, char ledToggle);
void playNoteTwo(const Note* note);
void resetGlobals(void);
void pressButtons(void);

volatile unsigned int totalDifficulty = 1;
volatile unsigned int count=0, sixteenths=0,noteOne=0,noteTwo=0,durationOne,durationTwo,sixteenthsPassed=0, sixteenthsPassedTwo=0, wrongNotes = 0, totalWrongNotes=0, difficulty = 1, demo = 0;
char tempo = 18, foo=4, soundEffect = 0;    //init tempo to 165 bpm, foo to 4
char correctButtonPress = 0;
char wrongButtonBress = 0;
char firstWrap = 0;

#pragma vector=TIMER2_A0_VECTOR
__interrupt void TimerA2_ISR(void)
{
    count++;
    if (count % totalDifficulty == 0) //18=165 bpm, 30 = 100bpm
        sixteenths++;
}

#define GFALLS 0
#define TETRIS 1
#define GOTBAS 2
#define INTERS 3
#define DESPAC 4
#define MHYSAS 5
#define AQUAVI 6
#define CANOND 7

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
    Graphics_Rectangle box = {.xMin = 2, .xMax = 94, .yMin = 2, .yMax = 94 };     // Draw a box around everything because it looks nice
    unsigned char song = 0;
    const Song songList[8] = {gravityFalls, tetris, gameOfThrones, interstellar, despacito, mhysa, aquaVitae, canonInD};
    const Song effectList[2] = {lossTone, winTone};

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
            setLeds(0);
            volatile unsigned int moveOn = 0;   //Wait flag
            char currKey;                       //Holds current key
            while(moveOn == 0)
            {
                currKey = getKey();
                if(currKey == '*')  //Query for star key, WAIT FOR INPUT
                    moveOn = 1;
                //pressButtons();
            }
            state = MENU;

            break;
        }
        case MENU:
        {
            resetGlobals();
            Graphics_clearDisplay(&g_sContext); // Clear the display
            Graphics_drawRectangle(&g_sContext, &box);
            Graphics_drawStringCentered(&g_sContext, "MENUU: Choose a", AUTO_STRING_LENGTH, 48, 10, TRANSPARENT_TEXT);
            Graphics_drawStringCentered(&g_sContext, "song with 1-3", AUTO_STRING_LENGTH, 48, 20, TRANSPARENT_TEXT);

            Graphics_drawStringCentered(&g_sContext, "1:Grav. Falls", AUTO_STRING_LENGTH, 48, 40, TRANSPARENT_TEXT);
            Graphics_drawStringCentered(&g_sContext, "2:Tetris", AUTO_STRING_LENGTH, 48, 50, TRANSPARENT_TEXT);
            Graphics_drawStringCentered(&g_sContext, "3:Game of Thrns", AUTO_STRING_LENGTH, 48, 60, TRANSPARENT_TEXT);
            Graphics_drawStringCentered(&g_sContext, "Press # for", AUTO_STRING_LENGTH, 48, 75, TRANSPARENT_TEXT);
            Graphics_drawStringCentered(&g_sContext, "next page", AUTO_STRING_LENGTH, 48, 85, TRANSPARENT_TEXT);
            Graphics_flushBuffer(&g_sContext);  //Draw to display

            volatile unsigned int moveOn = 0;   //Wait flag
            char currKey;                       //Holds current key
            while(moveOn == 0)
            {
                currKey = getKey();
                if(currKey == '1')  //Query for 1 key, WAIT FOR INPUT
                {
                    song = GFALLS,state = DIFFICULTYSELECT,moveOn = 1;
                    break;
                }
                if(currKey == '2')  //Query for 2 key, WAIT FOR INPUT
                {
                    song = TETRIS,state = DIFFICULTYSELECT,moveOn = 1;
                    break;
                }
                if(currKey == '3')  //Query for 3 key, WAIT FOR INPUT
                {
                    state = GOTSELECT,moveOn = 1;
                    break;
                }
                if(currKey == '#')  //Query for pound key, WAIT FOR INPUT
                {
                    state = MENUPAGE2,moveOn = 1;
                    break;
                }
            }
            break;
        }

        case MENUPAGE2:
        {
            resetGlobals();
            Graphics_clearDisplay(&g_sContext); // Clear the display
            Graphics_drawRectangle(&g_sContext, &box);
            Graphics_drawStringCentered(&g_sContext, "MENU: Choose a", AUTO_STRING_LENGTH, 48, 10, TRANSPARENT_TEXT);
            Graphics_drawStringCentered(&g_sContext, "song with 1-3", AUTO_STRING_LENGTH, 48, 20, TRANSPARENT_TEXT);

            Graphics_drawStringCentered(&g_sContext, "1:Interstellar", AUTO_STRING_LENGTH, 48, 40, TRANSPARENT_TEXT);
            Graphics_drawStringCentered(&g_sContext, "2:Despacito", AUTO_STRING_LENGTH, 48, 50, TRANSPARENT_TEXT);
            Graphics_drawStringCentered(&g_sContext, "3:Aqua Vitae", AUTO_STRING_LENGTH, 48, 60, TRANSPARENT_TEXT);
            Graphics_drawStringCentered(&g_sContext, "* for pre. pg.", AUTO_STRING_LENGTH, 48, 75, TRANSPARENT_TEXT);
            Graphics_drawStringCentered(&g_sContext, "# for next pg.", AUTO_STRING_LENGTH, 48, 85, TRANSPARENT_TEXT);
            Graphics_flushBuffer(&g_sContext);  //Draw to display

            volatile unsigned int moveOn = 0;   //Wait flag
            char currKey;                       //Holds current key
            while(moveOn == 0)
            {
                currKey = getKey();
                if(currKey == '1')  //Query for 1 key, WAIT FOR INPUT
                    song = INTERS,state = DIFFICULTYSELECT,moveOn = 1;
                if(currKey == '2')  //Query for 2 key, WAIT FOR INPUT
                    song = DESPAC,state = DIFFICULTYSELECT,moveOn = 1;
                if(currKey == '3')  //Query for 3 key, WAIT FOR INPUT
                    song = AQUAVI,state = DIFFICULTYSELECT,moveOn = 1;
                if(currKey == '*')  //Query for star key, WAIT FOR INPUT
                    state = MENU,moveOn = 1;
                if(currKey == '#')  //Query for star key, WAIT FOR INPUT
                    state = MENUPAGE3,moveOn = 1;
            }
            break;
        }

        case MENUPAGE3:
        {
            resetGlobals();
            Graphics_clearDisplay(&g_sContext); // Clear the display
            Graphics_drawRectangle(&g_sContext, &box);
            Graphics_drawStringCentered(&g_sContext, "MENU: Choose a", AUTO_STRING_LENGTH, 48, 10, TRANSPARENT_TEXT);
            Graphics_drawStringCentered(&g_sContext, "song with 1-3", AUTO_STRING_LENGTH, 48, 20, TRANSPARENT_TEXT);

            Graphics_drawStringCentered(&g_sContext, "1:Canon in D", AUTO_STRING_LENGTH, 48, 40, TRANSPARENT_TEXT);
            Graphics_drawStringCentered(&g_sContext, "Press * for", AUTO_STRING_LENGTH, 48, 75, TRANSPARENT_TEXT);
            Graphics_drawStringCentered(&g_sContext, "next page", AUTO_STRING_LENGTH, 48, 85, TRANSPARENT_TEXT);
            Graphics_flushBuffer(&g_sContext);  //Draw to display

            volatile unsigned int moveOn = 0;   //Wait flag
            char currKey;                       //Holds current key
            while(moveOn == 0)
            {
                currKey = getKey();
                if(currKey == '1')  //Query for 1 key, WAIT FOR INPUT
                    song = CANOND,state = DIFFICULTYSELECT,moveOn = 1;
                if(currKey == '*')  //Query for star key, WAIT FOR INPUT
                    state = MENUPAGE2,moveOn = 1;
            }
            break;
        }

        case GOTSELECT:
        {
            Graphics_clearDisplay(&g_sContext); // Clear the display
            Graphics_drawRectangle(&g_sContext, &box);
            Graphics_drawStringCentered(&g_sContext, "Choose your", AUTO_STRING_LENGTH, 48, 10, TRANSPARENT_TEXT);
            Graphics_drawStringCentered(&g_sContext, "GoT Variant:", AUTO_STRING_LENGTH, 48, 20, TRANSPARENT_TEXT);

            Graphics_drawStringCentered(&g_sContext, "1:Main Theme", AUTO_STRING_LENGTH, 48, 40, TRANSPARENT_TEXT);
            Graphics_drawStringCentered(&g_sContext, "2:Mhysa", AUTO_STRING_LENGTH, 48, 50, TRANSPARENT_TEXT);
            Graphics_drawStringCentered(&g_sContext, "Press * for", AUTO_STRING_LENGTH, 48, 75, TRANSPARENT_TEXT);
            Graphics_drawStringCentered(&g_sContext, "previous page", AUTO_STRING_LENGTH, 48, 85, TRANSPARENT_TEXT);
            Graphics_flushBuffer(&g_sContext);  //Draw to display

            volatile unsigned int moveOn = 0;   //Wait flag
            char currKey;                       //Holds current key
            while(moveOn == 0)
            {
                currKey = getKey();
                if(currKey == '1')  //Query for 1 key, WAIT FOR INPUT
                    song = GOTBAS,state = DIFFICULTYSELECT,moveOn = 1;
                if(currKey == '2')  //Query for 2 key, WAIT FOR INPUT
                    song = MHYSAS,state = DIFFICULTYSELECT,moveOn = 1;
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
                if(currKey == '1')  //Query for 1 key, WAIT FOR INPUT
                {
                    difficulty = 4,state = COUNTDOWN,moveOn = 1;
                    break;
                }
                if(currKey == '2')  //Query for 2 key, WAIT FOR INPUT
                {
                    difficulty = 3,state = COUNTDOWN,moveOn = 1;
                    break;
                }
                if(currKey == '3')  //Query for 3 key, WAIT FOR INPUT
                {
                    difficulty = 1,state = COUNTDOWN,moveOn = 1;
                    break;
                }
                if(currKey == '0')  //Query for 0 key, WAIT FOR INPUT
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
                BuzzerOnFreq(C5);
                userLEDs(3-i);
                swDelay(1);
                BuzzerOff();
                swDelay(1);
            }
            Graphics_clearDisplay(&g_sContext);
            userLEDs(3);
            Graphics_drawStringCentered(&g_sContext, "GO!", AUTO_STRING_LENGTH, 48, 15, TRANSPARENT_TEXT);
            Graphics_drawStringCentered(&g_sContext, "Press # to", AUTO_STRING_LENGTH, 48, 75, TRANSPARENT_TEXT);
            Graphics_drawStringCentered(&g_sContext, "quit", AUTO_STRING_LENGTH, 48, 85, TRANSPARENT_TEXT);
            Graphics_flushBuffer(&g_sContext);


            //resetGlobals();
            if(songList[song].power)
                P1DS |=  BIT2;              //High drive strength
            else
                P1DS &= ~BIT2;              //Low drive strength

            tempo = songList[song].tempo;   //Set correct song tempo
            totalDifficulty = (tempo*difficulty);
            state = PLAY;
            userLEDs(0);
            stopTimer();
            runTimer();
            count = 0;
            sixteenths = 0;
            break;
        }

        case PLAY:
        {


            volatile unsigned int loc_sixteenths = sixteenths, loc_sixteenths_two = sixteenths; //sixteenths arises from the global interrupts


            //If rest, don't play any music
            if((&songList[song].bigSpeaker[noteOne].pitch == REST) | (noteOne >= songList[song].bigSpeakerCount)) //If note is a rest or song is done
                BuzzerOffTwo();
            else
                playNoteTwo(&songList[song].bigSpeaker[noteOne]); //Else, play appropriate note with appropriate power

            if((&songList[song].smlSpeaker[noteTwo] == REST) | (noteTwo >= songList[song].smlSpeakerCount)) //If note is a rest or song is done
                BuzzerOff();
            else
                playNote   (&songList[song].smlSpeaker[noteTwo],1);

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

                if(!demo && correctButtonPress != 1)
                {
                    totalWrongNotes++;
                    userLEDs(1);//Red LED
                }
                else
                    userLEDs(2);//Correct
                correctButtonPress = 0;

                //buttonPress = getButtons();
/*
                if(!demo)   //Only count mispresses if the game is not in a demo.
                {
                    if(buttonPress != correctLED)
                        totalWrongNotes++;
                }
*/
            }

            if((noteOne >= songList[song].bigSpeakerCount) | (noteTwo >= songList[song].smlSpeakerCount))   //If song is over
                state = WIN;            //If song is over, player wins

            if(getKey() == '#')         //Quit game if necessary
                state = QUIT;

            //**********Button/Game Logic**********//

            char correctLED  = ((songList[song].smlSpeaker[noteTwo].pitch % 4)+1);  //(Note index%4)+1 is the value of what button the player should press
            switch(correctLED) //Determine what the correct LED for the current playing note is
            {
            case 1:
                correctLED = BIT0;
                break;
            case 2:
                correctLED = BIT1;
                break;
            case 3:
                correctLED = BIT2;
                break;
            case 4:
                correctLED = BIT3;
                break;
            }
            if(songList[song].smlSpeaker[noteTwo].pitch == REST) //If rest, the correct note to play is nothing
                correctLED = 0;
            char currButton = getButtons(); //Get the button the player is currently pressing
            if(correctLED & currButton)
                correctButtonPress = 1;     //If player presses correct button in the duration of the note, this will toggle on.
            if((demo != 1) && (totalWrongNotes >= 15))   //End game if player loses
                state = LOSE;
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
            soundEffect = 0;    //Losing sound effect
            state = POST;
            break;
        }

        case WIN:
        {
            Graphics_clearDisplay(&g_sContext); // Clear the display
            BuzzerOff();    //Reset buzzers
            BuzzerOffTwo(); //Reset buzzers
            setLeds(REST);     //Reset LEDs
            resetGlobals(); //Reset globals
            Graphics_drawStringCentered(&g_sContext, "YOU", AUTO_STRING_LENGTH, 48, 15, TRANSPARENT_TEXT);
            Graphics_drawStringCentered(&g_sContext, "WIN!", AUTO_STRING_LENGTH, 48, 25, TRANSPARENT_TEXT);
            Graphics_drawStringCentered(&g_sContext, "To return:", AUTO_STRING_LENGTH, 48, 75, TRANSPARENT_TEXT);
            Graphics_drawStringCentered(&g_sContext, "Press *", AUTO_STRING_LENGTH, 48, 85, TRANSPARENT_TEXT);
            Graphics_flushBuffer(&g_sContext);

            soundEffect = 1;    //Winning sound effect
            state = POST;
            break;
        }

        case QUIT:
        {
            Graphics_clearDisplay(&g_sContext); // Clear the display
            BuzzerOff();    //Reset buzzers
            BuzzerOffTwo(); //Reset buzzers
            setLeds(REST);     //Reset LEDs
            resetGlobals(); //Reset globals
            Graphics_drawStringCentered(&g_sContext, "GAME", AUTO_STRING_LENGTH, 48, 15, TRANSPARENT_TEXT);
            Graphics_drawStringCentered(&g_sContext, "OVER:", AUTO_STRING_LENGTH, 48, 25, TRANSPARENT_TEXT);
            Graphics_drawStringCentered(&g_sContext, "You quit!", AUTO_STRING_LENGTH, 48, 50, TRANSPARENT_TEXT);
            Graphics_drawStringCentered(&g_sContext, "To return:", AUTO_STRING_LENGTH, 48, 75, TRANSPARENT_TEXT);
            Graphics_drawStringCentered(&g_sContext, "Press *", AUTO_STRING_LENGTH, 48, 85, TRANSPARENT_TEXT);
            Graphics_flushBuffer(&g_sContext);
            soundEffect = 0;
            state = POST;
        }
        case POST:
        {

            totalDifficulty = 18;
            /*
            volatile unsigned int loc_sixteenths = sixteenths, loc_sixteenths_two = sixteenths; //sixteenths arises from the global interrupts

            //If rest, don't play any music
            if((&effectList[soundEffect].bigSpeaker[noteOne] == REST) | (noteOne >= effectList[soundEffect].bigSpeakerCount)) //If note is a rest or song is done
                BuzzerOffTwo();
            else
                playNoteTwo(&effectList[soundEffect].bigSpeaker[noteOne]); //Else, play appropriate note with appropriate power

            if((&effectList[soundEffect].smlSpeaker[noteTwo] == REST) | (noteTwo >= effectList[soundEffect].smlSpeakerCount)) //If note is a rest or song is done
                BuzzerOff();
            else
                playNote   (&effectList[soundEffect].smlSpeaker[noteTwo],0);

            durationOne = effectList[soundEffect].bigSpeaker[noteOne].duration;
            durationTwo = effectList[soundEffect].smlSpeaker[noteTwo].duration;

            if(loc_sixteenths - sixteenthsPassed == durationOne)
            {
                noteOne++;
                sixteenthsPassed = loc_sixteenths;
                BuzzerOffTwo();
                setLeds(foo);
                if(soundEffect)
                {
                    foo++;  //Ascending lights
                    if(foo >= 4)
                        foo = 1;
                }
                else
                {
                    foo--;  //Descending lights
                    if(foo <= 0)
                        foo = 4;
                }
            }
            if(loc_sixteenths_two - sixteenthsPassedTwo == durationTwo)
            {
                noteTwo++;
                sixteenthsPassedTwo = loc_sixteenths_two;
                BuzzerOff();
            }
            */
            //if(noteOne >= effectList[soundEffect].bigSpeakerCount)   //If song is over
           // {
                volatile unsigned int moveOn = 0;
                while(moveOn == 0)
                {
                    char currKey = getKey();
                    if(currKey == '*')    //Wait for user to press * key
                        moveOn = 1;
                }
                resetGlobals();
                state = WELCOME;
                stopTimer();    //Stop  timer
                break;
            //}
            //break;

        }//End post

        }//End switch
    }  // end while (1)
}//End main


void playNote(const Note* note, char toggle)
{
    BuzzerOnFreq(note->pitch);
    if((note->pitch)!=REST)
        setLeds(((note->pitch)%4)+1);
}

void playNoteTwo(const Note* note)
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
    //demo = 0;
    foo = 4;
    soundEffect = 0;
}

void pressButtons(void)
{
    char foo = getButtons();
    setLeds(foo);
}



void swDelay(char waitTime)
{
    // This function is a software delay. It performs
    // useless loops and looks at the counter to determine
    // if a required amount of time has passed.
    //
    // Input: waitTime = number of half seconds to wait
    // Output: none
    //
    // nsb, ECE2049, 06 Feb 2019

    volatile unsigned int loc_sixteenths = sixteenths;      //sixteenths arises from the global interrupts. Use this to ensure that goalTime doesn't change.
    unsigned int goalTime = loc_sixteenths + (waitTime*4);  //Goal time to reach
    unsigned char flag = 1; //Flag for loop

    totalDifficulty = 30;//Set timer to 100bpm

    while(flag)
        if(goalTime == sixteenths)
            flag = 0; //Wait for time to pass, then exit loop.

    resetGlobals();
}
