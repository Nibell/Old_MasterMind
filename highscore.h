/*
    highscore.h
    Header file for highscore part of Mastermind

    Authors:    Christoffer Lindahl <christoffer@kekos.se>
                Markus Thorsberg <markus.thorsberg@student.hv.se>
                Linus Nibell <linus.nibell@student.hv.se>
    Date:       2011-02-15, last edit 2011-03-06
    Version:    0.4
*/

#ifndef __HIGHSCORE_H__
#define __HIGHSCORE_H__

#include <stdio.h>
#include <string.h>   /* For strtok() and strcpy() */
#include <stdlib.h>   /* For atoi() */

/* Definitions */

#define PLAYER_NAME_SIZE 50
#define PLAYER_DATE_SIZE 10
#define FILELINE_SIZE 66
#define HIGHSCORE_FILENAME "mm_highscore.txt"

typedef struct
    {
    char name[PLAYER_NAME_SIZE + 1];
    char date[PLAYER_DATE_SIZE + 1]; /* Date format YYYY-MM-DD */
    unsigned int guesses;
    } Player;

/* Function prototypes */
void swap(Player *x, Player *y);
int loadHighscore(Player players[]);
int storeHighscore(Player players[]);
void sortPlayers(Player players[], int size);

#endif
