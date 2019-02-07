/*
 * songs.h
 *
 *  Created on: Feb 1, 2019
 *      Author: Administrator
 */

#ifndef SONGS_H_
#define SONGS_H_


#include "mhysa.h"
#include "notes.h"
#include "gravityfalls.h"
#include "tetris.h"
#include "interstellar.h"
#include "despacito.h"
#include "miscSounds.h"
#include "got.h"
#include "aquaVitae.h"
#include "canon.h"

typedef struct {
    const Note* speakerOne;                   //What notepattern to play on the large speaker
    const Note* speakerTwo;                   //What notepattern to play on the small speaker
    char tempo;                         //Tempo to play at. 18=165 bpm, 30 = 100bpm
    char power:1;                       //What power the large speaker should play at. Only need 1 bit: 0 or 1.
    char legacy:1;                      //Future plan: Implement 32nd time keeping. This bit will signify if song was created using 16th timing.
    unsigned int speakerOneCount;       //Number of notes on Speaker One (typically treble clef)
    unsigned int speakerTwoCount;       //Number of notes on Speaker One (typically bass clef)
} Song;

const Song tetris = {
               tetrisBass,
               tetrisTreble,
               18,
               0,
               1,
               352,
               311
};

const Song gravityFalls = {
                     gravityFallsTreble,
                     gravityFallsBass,
                     18,
                     1,
                     1,
                     75,
                     184
};
const Song mhysa = {
                     mhysaTreb,
                     mhysaBass,
                     40,
                     1,
                     1,
                     320,
                     390
};

const Song gameOfThrones = {
                            gotTreb,
                            gotBass,
                            18,
                            1,
                            1,
                            296,
                            224
};

const Song interstellar = {
                     interstellarBass,
                     interstellarTreble,
                     30,
                     1,
                     1,
                     214,
                     546
};

const Song despacito = {
                     despacitoTreble,
                     despacitoBass,
                     17,
                     1,
                     1,
                     438,
                     353
};

const Song lossTone = {
                 lossTreble,
                 lossBass,
                 18,
                 0,
                 1,
                 24,
                 25
};

const Song winTone = {
                winTreble,
                winBass,
                20,//down from 30
                0,
                1,
                31,
                30
};

const Song aquaVitae = {
                        aquaVitaeTreb,
                        aquaVitaeBass,
                        24,//Use 24
                        1,
                        1,
                        926,
                        104
};

const Song canonInD = {
                       canonTreb,
                       canonBass,
                       30,
                       1,
                       1,
                       710,
                       803
};


#endif /* SONGS_H_ */
