/*
 * notes.h
 *
 *  Created on: Jan 30, 2019
 *      Author: Nathaniel Bajakian
 */

#ifndef NOTES_H_
#define NOTES_H_

typedef struct {
    char pitch:7;         //Note pitch. Only need 7 bits: 0-127
    char duration:6;      //Note duration. Only need 6 bits: 0-65
} Note; //13 bits per note. Down from 16 bits per note, 1 byte. Down from 40 bits per note



//Note Lengths
#define THSCND 1
#define SXTNTH 2
#define EIGHTH 4
#define FOURTH 8
#define HALF   16
#define FULL   32

//Note Pitches: These are indices to a master notelist.
#define REST     0
#define NOTE_E1  1
#define NOTE_F1  2
#define NOTE_G1  3
#define NOTE_Gs1 4
#define NOTE_A1  5
#define NOTE_B1  6
#define NOTE_C2  7
#define NOTE_D2  8
#define NOTE_E2  9
#define NOTE_F2  10
#define NOTE_Fs2 11
#define NOTE_G2  12
#define NOTE_Gs2 13
#define NOTE_A2  14
#define NOTE_As2 15
#define NOTE_B2  16
#define NOTE_C3  17
#define NOTE_Cs3 18
#define NOTE_D3  19
#define NOTE_Ds3 20
#define NOTE_Eb3 21
#define NOTE_E3  22
#define NOTE_F3  23
#define NOTE_Fs3 24
#define NOTE_G3  25
#define NOTE_Gs3 26
#define NOTE_A3  27
#define NOTE_As3 28
#define NOTE_B3  29
#define NOTE_Bs3 30
#define NOTE_C4  31
#define NOTE_Cs4 32
#define NOTE_Db4 33
#define NOTE_D4  34
#define NOTE_Ds4 35
#define NOTE_E4  36
#define NOTE_F4  37
#define NOTE_Fs4 38
#define NOTE_G4  39
#define NOTE_Gs4 40
#define NOTE_A4  41
#define NOTE_Bb4 42
#define NOTE_B4  43
#define NOTE_C5  44
#define NOTE_Cs5 45
#define NOTE_D5  46
#define NOTE_Ds5 47
#define NOTE_Eb5 48
#define NOTE_E5  49
#define NOTE_F5  50
#define NOTE_Fs5 51
#define NOTE_G5  52
#define NOTE_Gs5 53
#define NOTE_Ab  54
#define NOTE_A5  55
#define NOTE_As5 56
#define NOTE_Bb5 57
#define NOTE_B5  58
#define NOTE_C6  59
#define NOTE_Cs6 60
#define NOTE_D6  61
#define NOTE_Ds6 62
#define NOTE_E6  63
#define NOTE_F6  64
#define NOTE_Fs6 65
#define NOTE_G6  66
#define NOTE_Gs6 67
#define NOTE_A6  68
#define NOTE_As6 69
#define NOTE_B6  70
#define NOTE_C7  71
#define NOTE_Cs7 72
#define NOTE_D7  73
#define NOTE_Ds7 74
#define NOTE_E7  75
#define NOTE_F7  76
#define NOTE_Fs7 77
#define NOTE_G7  78
#define NOTE_Gs7 79
#define NOTE_A7  80
#define NOTE_As7 81
#define NOTE_B7  82
#define NOTE_C8  83
#define NOTE_Cs8 84
#define NOTE_D8  85
#define NOTE_Ds8 86

#define E1  1
#define F1  2
#define G1  3
#define Gs1 4
#define A1  5
#define B1  6
#define C2  7
#define D2  8
#define E2  9
#define F2  10
#define Fs2 11
#define G2  12
#define Gs2 13
#define A2  14
#define As2 15
#define B2  16
#define C3  17
#define Cs3 18
#define D3  19
#define Ds3 20
#define Eb3 21
#define E3  22
#define F3  23
#define Fs3 24
#define G3  25
#define Gs3 26
#define A3  27
#define As3 28
#define B3  29
#define Bs3 30
#define C4  31
#define Cs4 32
#define Db4 33
#define D4  34
#define Ds4 35
#define E4  36
#define F4  37
#define Fs4 38
#define G4  39
#define Gs4 40
#define A4  41
#define Bb4 42
#define B4  43
#define C5  44
#define Cs5 45
#define D5  46
#define Ds5 47
#define Eb5 48
#define E5  49
#define F5  50
#define Fs5 51
#define G5  52
#define Gs5 53
#define Ab  54
#define A5  55
#define As5 56
#define Bb5 57
#define B5  58
#define C6  59
#define Cs6 60
#define D6  61
#define Ds6 62
#define E6  63
#define F6  64
#define Fs6 65
#define G6  66
#define Gs6 67
#define A6  68
#define As6 69
#define B6  70
#define C7  71
#define Cs7 72
#define D7  73
#define Ds7 74
#define E7  75
#define F7  76
#define Fs7 77
#define G7  78
#define Gs7 79
#define A7  80
#define As7 81
#define B7  82
#define C8  83
#define Cs8 84
#define D8  85
#define Ds8 86


#endif /* NOTES_H_ */
