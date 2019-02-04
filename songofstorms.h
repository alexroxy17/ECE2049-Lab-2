/*
 * songofstorms.h
 *
 *  Created on: Feb 1, 2019
 *      Author: Nathaniel Bajakian
 */


#ifndef SONGOFSTORMS_H_
#define SONGOFSTORMS_H_
#include "notes.h"

Note SONGOFSTORMS [] = {
    /*  SIXTEEN = 1; EIGHT = 2; FOURTH = 4; HALF = 8; FULL = 16*/
    {NOTE_D4,  2},
    {NOTE_F4,  2},
    {NOTE_D5,  8},

    {NOTE_D4,  2},
    {NOTE_F4,  2},
    {NOTE_D5,  8},

    {NOTE_E5,  6},
    {NOTE_F5,  2},
    {NOTE_E5,  2},
    {NOTE_F5,  2}, //10
    {NOTE_E5,  2},
    {NOTE_C5,  2}, //Corrected from D5
    {NOTE_A4,  7},
    {REST, 1},

    {NOTE_A4,  4},
    {NOTE_D4,  4},
    {NOTE_F4,  2},
    {NOTE_G4,  2},

    {NOTE_A4,  9},
    {REST, 1},    //20

    {NOTE_A4,  4},
    {NOTE_D4,  4},
    {NOTE_F4,  2},
    {NOTE_G4,  2},

    {NOTE_F4,  10},//25     //Midpoint, start over

    {NOTE_D4,  2},
    {NOTE_F4,  2},
    {NOTE_D5,  8},

    {NOTE_D4,  2},
    {NOTE_F4,  2},
    {NOTE_D5,  8},

    {NOTE_E5,  6},
    {NOTE_F5,  2},
    {NOTE_E5,  2},
    {NOTE_F5,  2}, //35

    {NOTE_E5,  2},
    {NOTE_C5,  2},
    {NOTE_A4,  7},
    {REST, 1},

    {NOTE_A4,  4},
    {NOTE_D4,  4},
    {NOTE_F4,  2},
    {NOTE_G4,  2},

    {NOTE_A4,  7},
    {REST, 1},     //45

    {NOTE_A4,  4},
    {NOTE_D3,  4},
    {NOTE_D4,  3},
    {REST, 1},
    {NOTE_D4,  4},

    {REST, 2},
    {NOTE_E3, 2},
    {NOTE_E4, 4},

    {REST, 4},
    {NOTE_F4, 4},
    {NOTE_F4, 4},

    {REST, 2},
    {NOTE_E3, 2},
    {NOTE_E4, 4},

    {REST, 4},
    {NOTE_D4, 4},
    {NOTE_D4, 4},

    {REST, 2},
    {NOTE_E4, 2},
    {NOTE_E5, 8},

    {REST, 4},
    {NOTE_F5, 3},
    {REST, 1},
    {NOTE_F5, 4},

    {REST, 2},
    {NOTE_E4, 2},
    {NOTE_E5, 8},

    {NOTE_D5, 2},
    {NOTE_F5, 2},
    {NOTE_D6, 8},

    {NOTE_D5, 2},
    {NOTE_F5, 2},
    {NOTE_D6, 8},

    {NOTE_E6, 6},
    {NOTE_F6, 2},
    {NOTE_E6, 2},
    {NOTE_F6, 2},

    {NOTE_E6, 2},
    {NOTE_C6, 2},
    {NOTE_A5, 8},

    {NOTE_A5, 4},
    {NOTE_D5, 4},
    {NOTE_F5, 2},
    {NOTE_G5, 2},

    {NOTE_A5, 11},
    {REST, 1},

    {NOTE_A5, 4},
    {NOTE_D5, 4},
    {NOTE_F5, 1},
    {REST, 1},
    {NOTE_F5, 2},

    {NOTE_E5, 12},

    {NOTE_D5, 2},
    {NOTE_F5, 2},
    {NOTE_D6, 8},

    {NOTE_D5, 2},
    {NOTE_F5, 2},
    {NOTE_D6, 8},

    {NOTE_E6, 6},
    {NOTE_F6, 2},
    {NOTE_E6, 2},
    {NOTE_F6, 2},

    {NOTE_E6, 2},
    {NOTE_C6, 2},
    {NOTE_A5, 8},

    {NOTE_A5, 4},
    {NOTE_D5, 4},
    {NOTE_F5, 2},
    {NOTE_G5, 2},

    {NOTE_A5, 3},
    {REST, 1},
    {NOTE_A5, 3},
    {REST, 1},
    {NOTE_A4, 10}, //119
    {NOTE_E5, 12},

    ///////////////////////////////////

    {NOTE_G4, 4}, //Patt1   Game of thrones
    {NOTE_C4, 4},
    {NOTE_Ds4, 2},
    {NOTE_F4, 2},

    {NOTE_G4, 4}, //Patt1
    {NOTE_C4, 4},
    {NOTE_Ds4, 2},
    {NOTE_F4, 2},

    {NOTE_G4, 4}, //Patt 1
    {NOTE_C4, 4},
    {NOTE_Ds4, 2},
    {NOTE_F4, 2},

    {NOTE_G4, 4}, //Patt 1
    {NOTE_C4, 4},
    {NOTE_Ds4, 2},
    {NOTE_F4, 2},

    {NOTE_G4, 4}, //Patt 2
    {NOTE_C4, 4},
    {NOTE_E4, 2},
    {NOTE_F4, 2},

    {NOTE_G4, 4}, //Patt 2
    {NOTE_C4, 4},
    {NOTE_E4, 2},
    {NOTE_F4, 2},

    {NOTE_G4, 4}, //Patt 2
    {NOTE_C4, 4},
    {NOTE_E4, 2},
    {NOTE_F4, 2},

    {NOTE_G4, 4}, //Patt 2
    {NOTE_C4, 4},
    {NOTE_E4, 2},
    {NOTE_F4, 2},

    {NOTE_G4, 12},   //******************** Line 09 ********************//

    {NOTE_C4, 12},

    {NOTE_C4, 1},
    {NOTE_E4, 1},
    {NOTE_F4, 2},
    {NOTE_G4, 8},

    {NOTE_C4, 8},
    {NOTE_E4, 2},
    {NOTE_F4, 2},

    {NOTE_D4, 4},
    {NOTE_E3, 4},
    {NOTE_G3, 2},
    {NOTE_C4, 2},

    {NOTE_D4, 4},
    {NOTE_E3, 4},
    {NOTE_G3, 2},
    {NOTE_C4, 2},

    {NOTE_D4, 4},
    {NOTE_E3, 4},
    {NOTE_G3, 2},
    {NOTE_C4, 2},

    {NOTE_D4, 4},
    {NOTE_E3, 4},
    {NOTE_G3, 2},

    {NOTE_G4, 12},  //******************** Line 25 ********************//

    {NOTE_C4, 12},

    {NOTE_E4, 2},
    {NOTE_F4, 2},
    {NOTE_G4, 8},

    {NOTE_C4, 8},
    {NOTE_E4, 2},
    {NOTE_F4, 2},

    {NOTE_D4, 4},
    {NOTE_G3, 4},
    {NOTE_B3, 2},
    {NOTE_C4, 2},

    {NOTE_D4, 4},
    {NOTE_G3, 4},
    {NOTE_B3, 2},
    {NOTE_C4, 2},

    {NOTE_D4, 4},
    {NOTE_G3, 4},
    {NOTE_B3, 2},
    {NOTE_C4, 2},

    {NOTE_D4, 4},
    {NOTE_G3, 4},
    {NOTE_B3, 4},

    {NOTE_F4, 12},   //******************** Line 33 ********************//

    {NOTE_B3, 12},

    {NOTE_E4, 2},
    {NOTE_D4, 2},
    {NOTE_F4, 8},

    {NOTE_B3, 8},
    {NOTE_E4, 2},
    {NOTE_D4, 2},

    {NOTE_C4, 4},
    {NOTE_G3, 4},
    {NOTE_A3, 2},
    {NOTE_B3, 2},

    {NOTE_C4, 4},
    {NOTE_G3, 4},
    {NOTE_A3, 2},
    {NOTE_B3, 2},

    {NOTE_C4, 4},
    {NOTE_G3, 4},
    {NOTE_A3, 2},
    {NOTE_B3, 2},

    {NOTE_C4, 4},
    {NOTE_G3, 4},
    {NOTE_C4, 4},

    {NOTE_G4, 12}, //******************** Line 41 ********************//

    {NOTE_C4, 12},

    {NOTE_E4, 2},
    {NOTE_F4, 2},
    {NOTE_G4, 8},

    {NOTE_C4, 8},
    {NOTE_E4, 2},
    {NOTE_F4, 2},

    {NOTE_B4, 8},
    {NOTE_G3, 2},
    {NOTE_C4, 2},

    {NOTE_B4, 8},
    {NOTE_G3, 2},
    {NOTE_C4, 2}
    };



#endif /* SONGOFSTORMS_H_ */
