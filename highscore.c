/*
    highscore.c
    Highscore functions for Mastermind

    Authors:    Christoffer Lindahl <christoffer@kekos.se>
                Markus Thorsberg <markus.thorsberg@student.hv.se>
                Linus Nibell <linus.nibell@student.hv.se>
    Date:       2011-02-15, last edit 2011-03-06
    Version:    0.3
*/
#include "highscore.h"

/*
    swap()
    Swaps to elements in a Player array
    @dependencies -
    @params Player *x - First element
    @params Player *y - Second element
    @return void
*/
void swap(Player *x, Player *y)
    {
    Player temp;
    temp = *x;
    *x = *y;
    *y = temp;
    }

/*
    sortPlayers()
    Sorts an array of Players with bubblesort in ascending
    @dependencies -
    @params Player players[] - The player array that will be sorted
    @return void
*/
void sortPlayers(Player players[], int size)
    {
    int i, j;

    for (i = 0; i < size; i++)
        {
        for (j = 0; j < size - 1; j++)
            {
            if (players[j].guesses > players[j + 1].guesses)
                {
                swap(&players[j], &players[j + 1]);
                }
            }
        }
    }

int storeHighscore(Player players[])
{
    FILE *highscore_file;
    char fileline[FILELINE_SIZE + 1];
    int num_players = 0;

    highscore_file = fopen(HIGHSCORE_FILENAME, "r");

    if (num_guesses < Player.guesses)
        printf("Namn")
    fclose(highscore_file);
}
/*
    loadHighscore()
    Opens the highscore file and parses it contents and stores it in players array
    @dependencies - <stdio.h> <string.h> <stdlib.h>
    @params Player players[] - The player array that will contain the parsed
                               highscores
    @return int Number of players read from highscore file, -1 if file could
                not be created
*/
int loadHighscore(Player players[])
    {
    FILE *highscore_file;
    char fileline[FILELINE_SIZE + 1];
    int num_players = 0;

    /* Open the highscore file in read-mode */
    highscore_file = fopen(HIGHSCORE_FILENAME, "r");

    /* Create the highscore file if it didn't exist */
    if (highscore_file == NULL)
        {
        /* To create a file, it must be opened in write-mode */
        highscore_file = fopen(HIGHSCORE_FILENAME, "w");
        /* Just check if the file could be created */
        if (highscore_file == NULL)
            {
            num_players = -1;
            }
        }
    else
        {
        /* Read the file line by line until reaching end of file (NULL) */
        while ((fgets(fileline, FILELINE_SIZE, highscore_file)) != NULL)
            {
            strcpy(players[num_players].name, strtok(fileline, ","));
            strcpy(players[num_players].date, strtok(NULL, ","));
            players[num_players].guesses = atoi(strtok(NULL, ","));
            ++num_players;
            }
        }

    /* Close highscore file */
    fclose(highscore_file);

    return num_players;
    }
