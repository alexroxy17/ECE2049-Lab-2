/*
 * notes.h
 *
 *  Created on: Jan 30, 2019
 *      Author: Nathaniel Bajakian
 */

#ifndef NOTES_H_
#define NOTES_H_



typedef struct {
    unsigned int pitch;         //Note pitch
    unsigned int duration;      //Note duration
    char LED;                   //LEDs to light for each note
} Note; //40 bits per note, 2.5 bytes

//Note Lengths
#define THSCND 1
#define SXTNTH 2
#define EIGHTH 4
#define FOURTH 8
#define HALF   16
#define FULL   32

//Note Pitches
#define REST     1

#define NOTE_C2  65
#define NOTE_D2  73
#define NOTE_E2  84
#define NOTE_F2  87
#define NOTE_G2  98
#define NOTE_A2  110
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_Cs3 139
#define NOTE_D3  147
#define NOTE_Ds3 156
#define NOTE_Eb3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_Fs3 185
#define NOTE_G3  196
#define NOTE_Gs3 208
#define NOTE_A3  220
#define NOTE_As3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_Cs4 277
#define NOTE_Db4 277
#define NOTE_D4  294
#define NOTE_Ds4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_Fs4 370
#define NOTE_G4  392
#define NOTE_Gs4 415

#define NOTE_A4  440
#define NOTE_Bb4 466 //B flat
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_Cs5 554 //C Sharp
#define NOTE_D5  587
#define NOTE_Eb5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_Fs5 740
#define NOTE_G5  784
#define NOTE_Ab 831
#define NOTE_A5  880

#define NOTE_As5 932
#define NOTE_Bb5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_Cs6 1109
#define NOTE_D6  1175
#define NOTE_Ds6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_Fs6 1480
#define NOTE_G6  1568
#define NOTE_Gs6 1661
#define NOTE_A6  1760
#define NOTE_As6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_Cs7 2217
#define NOTE_D7  2349
#define NOTE_Ds7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_Fs7 2960
#define NOTE_G7  3136
#define NOTE_Gs7 3322
#define NOTE_A7  3520
#define NOTE_As7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_Cs8 4435
#define NOTE_D8  4699
#define NOTE_Ds8 4978


#endif /* NOTES_H_ */
