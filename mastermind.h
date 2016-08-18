/*
    mastermind.h
    Header file for Mastermind

    Authors:    Christoffer Lindahl <christoffer@kekos.se>
                Markus Thorsberg <markus.thorsberg@student.hv.se>
                Linus Nibell <linus.nibell@student.hv.se>
    Date:       2011-02-14, last edit 2011-03-07
    Version:    0.5
*/

#ifndef __MASTERMIND_H__
#define __MASTERMIND_H__

#include <stdio.h>
#include <stdlib.h>   /* For system(), rand() and srand() */
#include <time.h>     /* For time() */
#include <string.h>   /* For strcmp() */

/* Definitions */

#define SECRET_SIZE 4
#define SECRET_MAX 10
#define SIZE_HIGHSCORE 11

typedef int Secret[SECRET_SIZE];

/* Function prototypes */

void clearScreen(void);
int existInSecret(int compare, Secret key);
void getSecretKey(Secret key);
void controlGuess(Secret key, Secret guess, char feedback[]);
int playGame(void);

#endif
