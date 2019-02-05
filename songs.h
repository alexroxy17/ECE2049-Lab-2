/*
 * songs.h
 *
 *  Created on: Feb 1, 2019
 *      Author: Administrator
 */

#ifndef SONGS_H_
#define SONGS_H_


#include "notes.h"
#include "songofstorms.h"
#include "gameofthrones.h"
#include "gravityfalls.h"
#include "takemehome.h"
#include "tetris.h"
#include "interstellar.h"
#include "despacito.h"

typedef struct {
    Note* bigSpeaker;                   //What notepattern to play on the large speaker
    Note* smlSpeaker;                   //What notepattern to play on the small speaker
    char tempo;                         //Tempo to play at. 18=165 bpm, 30 = 100bpm
    char power:1;                       //What power the large speaker should play at. Only need 1 bit: 0 or 1.
    unsigned int bigSpeakerCount;     //Number of notes for the large speaker. Only need 9 bits.
    unsigned int smlSpeakerCount;    //Number of notes for the small speaker. Only need 9 bits.
} Song;

Song tetris = {
               tetrisBass,
               tetrisTreble,
               18,
               1,
               352,
               311
};

Song gravityFalls = {
                     gravityFallsBass,
                     gravityFallsTreble,
                     18,
                     0,
                     184,
                     75
};
Song songOfStorms = {
                     SONGOFSTORMS,
                     SONGOFSTORMS,  //Repeat, since there is no bass line (yet)
                     18,
                     0,
                     230,
                     230      //Disable playback for small speaker
};

Song interstellar = {
                     interstellarBass,
                     interstellarTreble,
                     30,
                     0,
                     214,
                     546
};

Song despacito = {
                     despacitoTreble,
                     despacitoBass,
                     17,
                     0,
                     438,
                     353
};


#endif /* SONGS_H_ */
