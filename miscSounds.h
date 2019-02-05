/*
 * miscSounds.h
 *
 *  Created on: Feb 5, 2019
 *      Author: Administrator
 */

#ifndef MISCSOUNDS_H_
#define MISCSOUNDS_H_
#include "notes.h"

Note lossTreble[] = {
             {REST,12},
             {Ds4,2},
             {D4,2},
             {Db4,2},
             {C4,2},
             {D4,2},
             {Db4,2},
             {C4,2},
             {B3,2},
             {D4,2},
             {C4,2},
             {B3,2},
             {As3,2},
             {C4,2},
             {B3,2},
             {As3,2},
             {A3,2},
             {B3,1},
             {As3,1},
             {A3,1},
             {Gs3,1},
             {Fs3,2},
             {F3,2},
             {E2,12},
};

Note lossBass[] = {
                   {REST,12},
                   {Cs4,2},
                   {B3,2},
                   {As3,2},
                   {A3,2},//
                   {B3,2},
                   {As3,2},
                   {A3,2},
                   {G3,2},//
                   {B3,2},
                   {As3,2},
                   {G3,2},
                   {Fs3,2},//
                   {A3,2},
                   {Gs3,2},
                   {G3,2},
                   {F3,2},//
                   {G3,1},
                   {Gs3,1},
                   {F3,1},
                   {E3,1},
                   {Ds3,1},
                   {Cs3,2},
                   {B2,4},
                   {F1,8},
};

Note winTreble[] = {
                    {REST,12},
                    {E3,1},     //With bass
                    {C4,1},     //With treb
                    {E4,2},
                    {G4,1},
                    {C5,1},
                    {E5,2},
                    {G5,4},
                    {E5,2},
                    {REST,2},

                    {REST,1},
                    {C4,1},
                    {Ds4,2},
                    {Gs4,1},
                    {C5,1},
                    {Eb5,2},
                    {Gs5,4},
                    {Eb5,2},
                    {REST,2},

                    {REST,1},
                    {D4,1},
                    {F4,2},
                    {Bb4,2},
                    {D5,2},
                    {F5,2},
                    {Bb5,3},
                    {REST,1},
                    {Bb5,1},
                    {Bb5,1},
                    {Bb5,2},

                    {C6,16}
};

Note winBass[] = {
                  {REST,12},
                  {G3,1},
                  {E3,1},
                  {G3,2},
                  {E3,1},
                  {G3,1},
                  {C4,2},
                  {E4,4},
                  {C4,2},
                  {REST,2},

                  {Gs3,1},
                  {Ds3,1},
                  {Gs3,2},
                  {Ds3,1},
                  {Gs3,1},
                  {C4,2},
                  {Ds4,4},
                  {C4,2},
                  {REST,2},

                  {As3,1},
                  {F3,1},
                  {As3,2},
                  {F3,1},
                  {As3,1},
                  {D4,2},
                  {F4,4},
                  {D4,1},
                  {D4,1},
                  {D4,2},
                  {C4,16}
};


#endif /* MISCSOUNDS_H_ */
