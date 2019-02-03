 /*
 * takeMeHome.h
 *
 *  Created on: Feb 1, 2019
 *      Author: Administrator
 */

#ifndef TETRIS_H_
#define TETRIS_H_
//Treble: 311
//Bass: 352
Note tetrisTreble[] = {

                     {NOTE_E5,4},
                     {NOTE_B4,2},
                     {NOTE_C5,2},
                     {NOTE_D5,2},
                     {NOTE_E5,2},
                     {NOTE_C5,2},
                     {NOTE_B4,2},

                     {NOTE_A4,4},
                     {NOTE_A4,2},
                     {NOTE_C5,2},
                     {NOTE_E5,4},
                     {NOTE_D5,2},
                     {NOTE_C5,2},

                     {NOTE_B4,4},
                     {NOTE_B4,2},
                     {NOTE_C5,2},
                     {NOTE_D5,4},
                     {NOTE_E5,4},

                     {NOTE_C5,4},
                     {NOTE_A4,4},
                     {NOTE_A4,8},

                     {REST, 2},   //******************** Line 05 ********************//
                     {NOTE_D5,4},
                     {NOTE_F5,2},
                     {NOTE_A5,4},
                     {NOTE_G5,2},
                     {NOTE_F5,2},

                     {REST, 2},
                     {NOTE_E5,4},
                     {NOTE_C5,2},
                     {NOTE_E5,4},
                     {NOTE_D5,2},
                     {NOTE_C5,2},

                     {NOTE_B4,4},
                     {NOTE_B4,2},
                     {NOTE_C5,2},
                     {NOTE_D5,4},
                     {NOTE_E5,4},

                     {NOTE_C5,4},
                     {NOTE_A4,3},
                     {REST, 1},
                     {NOTE_A4,8},   //End of first repeat



                     {NOTE_E5,4},   //Start of second repeat
                     {NOTE_B4,2},
                     {NOTE_C5,2},
                     {NOTE_D5,2},
                     {NOTE_E5,2},
                     {NOTE_C5,2},
                     {NOTE_B4,2},

                     {NOTE_A4,4},
                     {NOTE_A4,2},
                     {NOTE_C5,2},
                     {NOTE_E5,4},
                     {NOTE_D5,2},
                     {NOTE_C5,2},

                     {NOTE_B4,4},
                     {NOTE_B4,2},
                     {NOTE_C5,2},
                     {NOTE_D5,4},
                     {NOTE_E5,4},

                     {NOTE_C5,4},
                     {NOTE_A4,4},
                     {NOTE_A4,8},

                     {REST, 2},   //******************** Line 05 ********************//
                     {NOTE_D5,4},
                     {NOTE_F5,2},
                     {NOTE_A5,4},
                     {NOTE_G5,2},
                     {NOTE_F5,2},

                     {REST, 2},
                     {NOTE_E5,4},
                     {NOTE_C5,2},
                     {NOTE_E5,4},
                     {NOTE_D5,2},
                     {NOTE_C5,2},

                     {NOTE_B4,4},
                     {NOTE_B4,2},
                     {NOTE_C5,2},
                     {NOTE_D5,4},
                     {NOTE_E5,4},

                     {NOTE_C5,4},
                     {NOTE_A4,3},
                     {REST, 1},
                     {NOTE_A4,8},   //End of second repeat

                     {NOTE_E5,4},
                     {NOTE_B4,2},
                     {NOTE_C5,2},
                     {NOTE_D5,4},
                     {NOTE_E5,4},

                     {NOTE_C5 ,4},      //******************** Line 10 ********************//
                     {NOTE_A4 ,2},
                     {NOTE_C5 ,2},
                     {NOTE_E5 ,4},
                     {NOTE_A5 ,4},

                     {NOTE_Gs5,4},
                     {NOTE_F5 ,2},
                     {NOTE_E5 ,2},
                     {NOTE_D5 ,4},
                     {NOTE_C5 ,4},

                     {NOTE_E5 ,4},
                     {NOTE_Ds5,4},
                     {NOTE_D5 ,4},
                     {NOTE_Cs5,4},

                     {NOTE_C5 ,4},
                     {NOTE_A4 ,2},
                     {NOTE_B4 ,2},
                     {NOTE_C5 ,4},
                     {NOTE_A4 ,4},

                     {NOTE_B4 ,4},
                     {NOTE_E4 ,2},
                     {NOTE_Gs4,2},
                     {NOTE_B4 ,4},
                     {NOTE_G4 ,4},

                     {NOTE_A4 ,4},
                     {NOTE_G4 ,4},
                     {NOTE_F4 ,4},
                     {NOTE_D4 ,4},

                     {NOTE_A4 ,4},   //******************** Line 16 ********************//
                     {NOTE_G4 ,4},
                     {NOTE_F4 ,4},
                     {NOTE_D4 ,4},

                     {NOTE_E4 ,2},
                     {NOTE_Ds4,2},
                     {NOTE_E4 ,2},
                     {NOTE_F4 ,2},//
                     {NOTE_Gs4,2},
                     {NOTE_A4 ,2},
                     {NOTE_B4 ,2},
                     {NOTE_C5 ,2},

                     {NOTE_D5 ,2},
                     {NOTE_C5 ,2},
                     {NOTE_D5 ,2},
                     {NOTE_C5 ,2},//
                     {NOTE_B4 ,2},
                     {NOTE_A4 ,2},
                     {NOTE_Gs4,2},
                     {NOTE_E5 ,2},

                     {NOTE_Gs4,2},
                     {NOTE_A4 ,2},
                     {NOTE_B4 ,2},
                     {NOTE_C4 ,2},//
                     {NOTE_D5 ,2},
                     {NOTE_D5 ,2},
                     {NOTE_E5 ,2},
                     {NOTE_Gs5,2},

                     {NOTE_E6, 8},

                     {NOTE_E5,4},        //******************** Line 21 ********************//
                     {NOTE_B4,2},
                     {NOTE_C5,2},
                     {NOTE_D5,2},
                     {NOTE_E5,2},
                     {NOTE_C5,2},
                     {NOTE_B4,2},

                     {NOTE_A4,4},
                     {NOTE_A4,2},
                     {NOTE_C5,2},
                     {NOTE_E5,4},
                     {NOTE_D5,2},
                     {NOTE_C5,2},

                     {NOTE_B4,4},
                     {NOTE_B4,2},
                     {NOTE_C5,2},
                     {NOTE_D5,4},
                     {NOTE_E5,4},

                     {NOTE_C5,4},
                     {NOTE_A4,4},
                     {NOTE_A4,8},

                     {REST,2},
                     {NOTE_D5,4},
                     {NOTE_F5,2},
                     {NOTE_A5,4},
                     {NOTE_G5,2},
                     {NOTE_F5,2},

                     {REST,2},       //******************** Line 26 ********************//
                     {NOTE_E5,4},
                     {NOTE_C5,2},
                     {NOTE_E5,4},
                     {NOTE_D5,2},
                     {NOTE_C5,2},

                     {NOTE_B4,4},
                     {NOTE_B4,2},
                     {NOTE_C5,2},
                     {NOTE_D5,4},
                     {NOTE_E5,4},

                     {NOTE_C5,4},
                     {NOTE_A4,4},
                     {NOTE_A4,8},

                     {REST,2},
                     {NOTE_B4,4},
                     {NOTE_C5,2},
                     {NOTE_D5,4},
                     {NOTE_E5,4},

                     {REST,2},
                     {NOTE_B4,4},
                     {NOTE_C5,2},
                     {NOTE_D5,4},
                     {NOTE_E5,4},

                     {REST,2},       //******************** Line 31 ********************//
                     {NOTE_B4,4},
                     {NOTE_C5,2},
                     {NOTE_D5,4},
                     {NOTE_Ds5,4},

                     {NOTE_E6,2},
                     {NOTE_Ds6,2},
                     {NOTE_D6,2},
                     {NOTE_Cs6,2},//
                     {NOTE_C6,2},
                     {NOTE_B5,2},
                     {NOTE_As5,2},
                     {NOTE_A5,2},

                     {NOTE_Gs5,2},
                     {NOTE_G5,2},
                     {NOTE_Fs5,2},
                     {NOTE_F5,2},
                     {NOTE_E5,4},
                     {REST, 4},

                     {NOTE_E6,2},
                     {NOTE_F6,2},
                     {NOTE_E6,2},
                     {NOTE_C6,2},//
                     {NOTE_D6,2},
                     {NOTE_E6,2},
                     {NOTE_D6,2},
                     {NOTE_B5,2},

                     {NOTE_C6,2},       //******************** Line 35 ********************//
                     {NOTE_D6,2},
                     {NOTE_C5,2},
                     {NOTE_A5,2},
                     {NOTE_B5,2},
                     {NOTE_C6,2},
                     {NOTE_B5,2},
                     {NOTE_Gs5,2},

                     {NOTE_A5,2},
                     {NOTE_Gs5,2},
                     {NOTE_A5,2},
                     {NOTE_B5,1},
                         {NOTE_C6,1},
                         {NOTE_D6,1},
                         {NOTE_C6,1},
                     {NOTE_B5,2},
                     {NOTE_C6,2},
                     {NOTE_D6,2},

                     {NOTE_E6,2},
                     {NOTE_F6,2},
                     {NOTE_E6,2},
                     {NOTE_C6,2},//
                     {NOTE_D6,2},
                     {NOTE_E6,2},
                     {NOTE_D6,2},
                     {NOTE_B5,2},

                     {NOTE_C6,2},       //******************** Line 38 ********************//
                     {NOTE_D6,2},
                     {NOTE_C6,2},
                     {NOTE_A5,2},//
                     {NOTE_B5,2},
                     {NOTE_C6,2},
                     {NOTE_B5,2},
                     {NOTE_Gs5,2},

                     {NOTE_A5,2},
                     {NOTE_B5,2},
                     {NOTE_C6,2},
                     {NOTE_B5,2},//
                     {NOTE_A5,4},
                     {NOTE_E4,4},

                     {NOTE_E5,2},
                     {NOTE_F5,2},
                     {NOTE_E5,2},
                     {NOTE_C5,2},//
                     {NOTE_D5,2},
                     {NOTE_E5,2},
                     {NOTE_D5,2},
                     {NOTE_B4,2},

                     {NOTE_C5,2},
                     {NOTE_D5,2},
                     {NOTE_C5,2},
                     {NOTE_A4,2},//
                     {NOTE_B4,2},
                     {NOTE_C5,2},
                     {NOTE_B4,2},
                     {NOTE_Gs4,2},

                     {NOTE_A4,2},           //******************** Line 42 ********************//
                     {NOTE_Gs4,2},
                     {NOTE_A4,2},
                     {NOTE_B4,1},
                         {NOTE_C5,1},
                         {NOTE_D5,1},
                         {NOTE_C5,1},
                     {NOTE_B4,2},
                     {NOTE_C5,2},
                     {NOTE_D5,2},

                     {NOTE_E5,2},
                     {NOTE_D5,2},
                     {NOTE_E5,2},
                     {NOTE_C5,2},//
                     {NOTE_D5,2},
                     {NOTE_E5,2},
                     {NOTE_D5,2},
                     {NOTE_B4,2},

                     {NOTE_C5,2},
                     {NOTE_D5,2},
                     {NOTE_C5,2},
                     {NOTE_A4,2},//
                     {NOTE_B4,2},
                     {NOTE_C5,2},
                     {NOTE_B4,2},
                     {NOTE_Gs4,2},

                     {NOTE_A4,2},
                     {NOTE_B4,2},
                     {NOTE_C5,2},
                     {NOTE_E5,2},
                     {NOTE_A5, 8},
};

Note tetrisBass[] = {

                     {NOTE_B3,2},
                     {NOTE_E4,2},
                     {NOTE_D4,2},
                     {NOTE_E4,2},//
                     {NOTE_E3,2},
                     {NOTE_E4,2},
                     {NOTE_B3,2},
                     {NOTE_E4,2},

                     {NOTE_A3,2},
                     {NOTE_E4,2},
                     {NOTE_C4,2},
                     {NOTE_E4,2},//
                     {NOTE_E3,2},
                     {NOTE_E4,2},
                     {NOTE_C4,2},
                     {NOTE_E4,2},

                     {NOTE_B3,2},
                     {NOTE_E4,2},
                     {NOTE_D4,2},
                     {NOTE_E4,2},//
                     {NOTE_E3,2},
                     {NOTE_E4,2},
                     {NOTE_B3,2},
                     {NOTE_E4,2},

                     {NOTE_A3,2},
                     {NOTE_E4,2},
                     {NOTE_C4,2},
                     {NOTE_E4,2},//
                     {NOTE_A3,2},
                     {NOTE_E4,2},
                     {NOTE_C4,2},
                     {NOTE_E4,2},

                     {NOTE_D3,2},     //******************** Line 05 ********************//
                     {NOTE_F4,2},
                     {NOTE_D4,2},
                     {NOTE_F4,2},//
                     {NOTE_A3,2},
                     {NOTE_F4,2},
                     {NOTE_D4,2},
                     {NOTE_F4,2},

                     {NOTE_A3,2},
                     {NOTE_E4,2},
                     {NOTE_C4,2},
                     {NOTE_E4,2},//
                     {NOTE_E3,2},
                     {NOTE_E4,2},
                     {NOTE_C4,2},
                     {NOTE_E4,2},

                     {NOTE_B3,2},
                     {NOTE_E4,2},
                     {NOTE_D4,2},
                     {NOTE_E4,2},//
                     {NOTE_E3,2},
                     {NOTE_E4,2},
                     {NOTE_B3,2},
                     {NOTE_E4,2},

                     {NOTE_A3,2},
                     {NOTE_E4,2},
                     {NOTE_C4,2},
                     {NOTE_E4,2},//
                     {NOTE_A3,2},
                     {NOTE_E4,2},
                     {NOTE_C4,2},
                     {NOTE_E4,2},     //End of first repeat



                     {NOTE_B3,2},     //Start of second repeat
                     {NOTE_E4,2},
                     {NOTE_D4,2},
                     {NOTE_E4,2},//
                     {NOTE_E3,2},
                     {NOTE_E4,2},
                     {NOTE_B3,2},
                     {NOTE_E4,2},

                     {NOTE_A3,2},
                     {NOTE_E4,2},
                     {NOTE_C4,2},
                     {NOTE_E4,2},//
                     {NOTE_E3,2},
                     {NOTE_E4,2},
                     {NOTE_C4,2},
                     {NOTE_E4,2},

                     {NOTE_B3,2},
                     {NOTE_E4,2},
                     {NOTE_D4,2},
                     {NOTE_E4,2},//
                     {NOTE_E3,2},
                     {NOTE_E4,2},
                     {NOTE_B3,2},
                     {NOTE_E4,2},

                     {NOTE_A3,2},
                     {NOTE_E4,2},
                     {NOTE_C4,2},
                     {NOTE_E4,2},//
                     {NOTE_A3,2},
                     {NOTE_E4,2},
                     {NOTE_C4,2},
                     {NOTE_E4,2},

                     {NOTE_D3,2},     //******************** Line 05 ********************//
                     {NOTE_F4,2},
                     {NOTE_D4,2},
                     {NOTE_F4,2},//
                     {NOTE_A3,2},
                     {NOTE_F4,2},
                     {NOTE_D4,2},
                     {NOTE_F4,2},

                     {NOTE_A3,2},
                     {NOTE_E4,2},
                     {NOTE_C4,2},
                     {NOTE_E4,2},//
                     {NOTE_E3,2},
                     {NOTE_E4,2},
                     {NOTE_C4,2},
                     {NOTE_E4,2},

                     {NOTE_B3,2},
                     {NOTE_E4,2},
                     {NOTE_D4,2},
                     {NOTE_E4,2},//
                     {NOTE_E3,2},
                     {NOTE_E4,2},
                     {NOTE_B3,2},
                     {NOTE_E4,2},

                     {NOTE_A3,2},
                     {NOTE_E4,2},
                     {NOTE_C4,2},
                     {NOTE_E4,2},//
                     {NOTE_A3,2},
                     {NOTE_E4,2},
                     {NOTE_C4,2},
                     {NOTE_E4,2},     //End of second repeat

                     {NOTE_E3 ,2},
                     {NOTE_B3 ,4},
                     {NOTE_B3 ,2},
                     {NOTE_E3 ,2},
                     {NOTE_B3 ,4},
                     {NOTE_B3 ,2},

                     {NOTE_A3 ,2},        //******************** Line 10 ********************//
                     {NOTE_C4 ,4},
                     {NOTE_C4 ,2},
                     {NOTE_A3 ,2},
                     {NOTE_C4 ,4},
                     {NOTE_C4 ,2},

                     {NOTE_E3 ,2},
                     {NOTE_Gs3,4},
                     {NOTE_G3 ,2},
                     {NOTE_E3 ,2},
                     {NOTE_G3 ,4},
                     {NOTE_G3 ,2},

                     {NOTE_C4 ,2},
                     {NOTE_E4 ,2},
                     {NOTE_B3 ,2},
                     {NOTE_E4 ,2},
                     {NOTE_As3,2},
                     {NOTE_E4 ,2},
                     {NOTE_A3 ,2},
                     {NOTE_E4 ,2},

                     {NOTE_F3 ,2},
                     {NOTE_A3 ,4},
                     {NOTE_A3 ,2},
                     {NOTE_F3 ,2},
                     {NOTE_A3 ,4},
                     {NOTE_A3 ,2},

                     {NOTE_E3 ,2},
                     {NOTE_Gs3,4},
                     {NOTE_G3 ,2},
                     {NOTE_E3 ,2},
                     {NOTE_G3 ,4},
                     {NOTE_G3 ,2},

                     {NOTE_D3 ,2},
                     {NOTE_F3 ,4},
                     {NOTE_F3 ,2},
                     {NOTE_D3 ,2},
                     {NOTE_F3 ,4},
                     {NOTE_F3 ,2},

                     {NOTE_B2 ,2},        //******************** Line 16 ********************//
                     {NOTE_D3 ,4},
                     {NOTE_D3 ,2},
                     {NOTE_B2 ,2},
                     {NOTE_D3 ,4},
                     {NOTE_D3 ,2},

                     {NOTE_E2 ,15},
                     {REST, 1},

                     {NOTE_E2 ,15},
                     {REST, 1},

                     {NOTE_E3 ,2},
                     {NOTE_F3 ,2},
                     {NOTE_G3 ,2},
                     {NOTE_Gs3,2},
                     {NOTE_B3 ,2},
                     {NOTE_C4 ,2},
                     {NOTE_E4 ,2},
                     {NOTE_Gs4,2},

                     {NOTE_E5, 8},

                     {NOTE_E2,2},            //******************** Line 21 ********************//
                     {NOTE_E3,2},
                     {NOTE_Gs2,2},
                     {NOTE_E3,2},//
                     {NOTE_B2,2},
                     {NOTE_E3,2},
                     {NOTE_G2,2},
                     {NOTE_E3,2},

                     {NOTE_A2,2},
                     {NOTE_A3,2},
                     {NOTE_C3,2},
                     {NOTE_A3,2},//
                     {NOTE_E3,2},
                     {NOTE_A3,2},
                     {NOTE_C3,2},
                     {NOTE_A3,2},

                     {NOTE_Gs3,2},
                     {NOTE_E4,2},
                     {NOTE_G3,2},
                     {NOTE_E4,2},//
                     {NOTE_B3,2},
                     {NOTE_E4,2},
                     {NOTE_G3,2},
                     {NOTE_E4,2},

                     {NOTE_A3,2},
                     {NOTE_E4,2},
                     {NOTE_E3,2},
                     {NOTE_C4,2},//
                     {NOTE_C3,2},
                     {NOTE_A3,2},
                     {NOTE_A2,2},
                     {NOTE_A3,2},

                     {NOTE_D2,2},
                     {NOTE_F3,2},
                     {NOTE_D2,2},
                     {NOTE_F3,2},//
                     {NOTE_D3,2},
                     {NOTE_F3,2},
                     {NOTE_A2,2},
                     {NOTE_F3,2},

                     {NOTE_A2,2},           //******************** Line 26 ********************//
                     {NOTE_A3,2},
                     {NOTE_C3,2},
                     {NOTE_A3,2},//
                     {NOTE_E3,2},
                     {NOTE_A3,2},
                     {NOTE_C3,2},
                     {NOTE_A3,2},

                     {NOTE_E2,2},
                     {NOTE_E3,2},
                     {NOTE_Gs2,2},
                     {NOTE_E3,2},//
                     {NOTE_B2,2},
                     {NOTE_E3,2},
                     {NOTE_G2,2},
                     {NOTE_E3,2},

                     {NOTE_A2,2},
                     {NOTE_A3,2},
                     {NOTE_C3,2},
                     {NOTE_A3,2},//
                     {NOTE_E3,2},
                     {NOTE_A3,2},
                     {NOTE_C3,2},
                     {NOTE_A3,2},

                     {NOTE_B3,2},
                     {NOTE_F4,2},
                     {NOTE_D4,2},
                     {NOTE_F4,2},//
                     {NOTE_B3,2},
                     {NOTE_F4,2},
                     {NOTE_D4,2},
                     {NOTE_F4,2},

                     {NOTE_Gs3,2},
                     {NOTE_F4,2},
                     {NOTE_B3,2},
                     {NOTE_D4,2},//
                     {NOTE_G3,2},
                     {NOTE_F4,2},
                     {NOTE_B3,2},
                     {NOTE_D4,2},

                     {NOTE_F3,2},           //******************** Line 31 ********************//
                     {NOTE_D4,2},
                     {NOTE_B3,2},
                     {NOTE_D4,2},//
                     {NOTE_F3,2},
                     {NOTE_D4,2},
                     {NOTE_Ds3,2},
                     {NOTE_Ds4,2},

                     {NOTE_E3,2},
                     {NOTE_Ds3,2},
                     {NOTE_D3,2},
                     {NOTE_Cs3,2},//
                     {NOTE_C3,2},
                     {NOTE_B2,2},
                     {NOTE_As2,2},
                     {NOTE_A2,2},


                     {NOTE_Gs2,2},
                     {NOTE_G2,2},
                     {NOTE_Fs2,2},
                     {NOTE_F2,2},//
                     {NOTE_E2,4},
                     {NOTE_E1,4},

                     {NOTE_A2,4},
                     {NOTE_A3,4},
                     {NOTE_E2,4},
                     {NOTE_Gs3,4},

                     {NOTE_A2,4},         //******************** Line 35 ********************//
                     {NOTE_A3,4},
                     {NOTE_E2,4},
                     {NOTE_Gs3,4},

                     {NOTE_A2,2},
                     {NOTE_A3,2},
                     {NOTE_E2,2},
                     {NOTE_E3,2},//
                     {NOTE_A2,2},
                     {NOTE_A3,2},
                     {NOTE_E2,2},
                     {NOTE_E3,2},

                     {NOTE_A2,4},
                     {NOTE_A3,4},
                     {NOTE_E2,4},
                     {NOTE_Gs3,4},

                     {NOTE_A2,4},         //******************** Line 38 ********************//
                     {NOTE_A3,4},
                     {NOTE_F2,4},
                     {NOTE_F3,4},

                     {NOTE_E1,2},
                     {NOTE_F1,2},
                     {NOTE_G1,2},
                     {NOTE_Gs1,2},
                     {NOTE_A1,4},
                     {NOTE_E1,4},

                     {NOTE_A2,4},
                     {NOTE_A3,4},
                     {NOTE_E2,4},
                     {NOTE_Gs3,4},

                     {NOTE_A2,4},
                     {NOTE_A3,4},
                     {NOTE_E2,4},
                     {NOTE_Gs3,4},

                     {NOTE_A2,2},         //******************** Line 42 ********************//
                     {NOTE_A3,2},
                     {NOTE_E2,2},
                     {NOTE_E3,2},//
                     {NOTE_A2,2},
                     {NOTE_A3,2},
                     {NOTE_E2,2},
                     {NOTE_E3,2},

                     {NOTE_A2,4},
                     {NOTE_A3,4},
                     {NOTE_E2,4},
                     {NOTE_Gs3,4},

                     {NOTE_A2,4},
                     {NOTE_A3,4},
                     {NOTE_F2,4},
                     {NOTE_F3,4},

                     {NOTE_E2,2},
                     {NOTE_D2,2},
                     {NOTE_C2,2},
                     {NOTE_B1,2},//
                     {NOTE_A1,8},

};



#endif /* TAKEMEHOME_H_ */
