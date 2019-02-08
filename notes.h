/*
 * notes.h
 *
 *  Created on: Jan 30, 2019
 *      Author: Nathaniel Bajakian
 */

#ifndef NOTES_H_
#define NOTES_H_

typedef struct {
    char pitch;         //Note pitch.
    char duration;      //Note duration.
} Note; //1 byte per note.



//Note Lengths
#define TS 1
#define SI 2
#define EI 4
#define FO 8
#define HA 16
#define FU 32

//Note Pitches: These are indices to a master notelist.
#define REST 0
#define E1  1
#define F1  2
#define G1  3
#define Gs1 4
#define Ab1 4
#define A1  5
#define Bb1 89
#define B1  6
#define Cb1 6
#define C2  7
#define Db2 88
#define D2  8
#define Eb2 87
#define E2  9
#define Fb2 9
#define F2  10
#define Fs2 11
#define Gb2 11
#define G2  12
#define Gs2 13
#define Ab2 13
#define A2  14
#define As2 15
#define Bb2 15
#define B2  16
#define Bs2 17
#define Cb2 16
#define C3  17
#define Cs3 18
#define Db3 18
#define D3  19
#define Ds3 20
#define Eb3 21
#define E3  22
#define Fb3 22
#define F3  23
#define Fs3 24
#define Gb3 24
#define G3  25
#define Gs3 26
#define Ab3 26
#define A3  27
#define As3 28
#define Bb3 28
#define B3  29
#define Bs3 30
#define Cb3 30
#define C4  31
#define Cs4 32
#define Db4 33
#define D4  34
#define Ds4 35
#define Eb4 35
#define E4  36
#define F4  37
#define Fs4 38
#define Gb4 38
#define G4  39
#define Gs4 40
#define Ab4 40
#define A4  41
#define Bb4 42
#define B4  43
#define Cb4 43
#define C5  44
#define Cs5 45
#define Db5 45
#define D5  46
#define Ds5 47
#define Eb5 48
#define E5  49
#define F5  50
#define Fs5 51
#define G5  52
#define Gs5 53
#define Ab5 54
#define A5  55
#define As5 56
#define Bb5 56
#define B5  58
#define Cb5 58
#define C6  59
#define Cs6 60
#define Db6 60
#define D6  61
#define Ds6 62
#define Eb6 62
#define E6  63
#define Fb6 63
#define F6  64
#define Fs6 65
#define Gb6 65
#define G6  66
#define Gs6 67
#define Ab6 67
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
