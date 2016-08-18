/*
    mastermind.c
    Game functions for Mastermind

    Authors:    Christoffer Lindahl <christoffer@kekos.se>
                Markus Thorsberg <markus.thorsberg@student.hv.se>
                Linus Nibell <linus.nibell@student.hv.se>
    Date:       2011-02-14, last edit 2011-03-07
    Version:    0.4
*/
#include "mastermind.h"

/*
    existInSecret()
    Checks if the number compare already exists in Secret key
    @dependencies -
    @params int compare - Number to compare
    @params Secret key - A secret variable that will store the numbers
    @return int Returns 0 if number didn't exist and 1 if it dit exist
*/
int existInSecret(int compare, Secret key)
    {
    int i;

    for (i = 0; i < SECRET_SIZE; i++)
        {
        if (key[i] == compare)
            return 1;
        }

    return 0;
    }

/*
    getSecretKey()
    Creates 4 randomized numbers and stores it in an array
    @dependencies - <stdlib.h> <time.h>
    @params Secret key - A secret variable that will store the key
    @return void
*/
void getSecretKey(Secret key)
    {
    int number, i;

    /* Seed random generator */
    srand(time(NULL));

    /* Iterate through all positions in Secret */
    for (i = 0; i < SECRET_SIZE; i++)
        {
        number = (rand() % SECRET_MAX);

        /* Check if the new number already exists */
        if (!existInSecret(number, key))
            key[i] = number;
        else
            --i; /* Step back one iteration and try randomize again */
        }
    }

/*
    controlGuess()
    Compares the players guess against the key and generates feedback
    @dependencies -
    @params Secret key - A secret variable that stores the key
    @params Secret key - A secret variable that stores the players guess
    @params char feedback[] - String that will contain feedback
    @return void
*/
void controlGuess(Secret key, Secret guess, char feedback[])
    {
    int i;

    /* Check if the guess contained correct numbers */
    /* Loop through all numbers in guess */
    for (i = 0; i < SECRET_SIZE; i++)
        {
        /* If number in guess equals number at same position in key */
        if (guess[i] == key[i])
            {
            feedback[i] = 'R';
            }
        /* Or if the number exist somewhere in the key */
        else if (existInSecret(guess[i], key))
            {
            feedback[i] = 'S';
            }
        /* Or the number didn't exist anywhere */
        else
            {
            feedback[i] = '_';
            }
        }
    }

/*
    playGame()
    Makes up the Mastermind game
    @dependencies - <stdio.h> <string.h>
    @return int Number of guesses
*/
int playGame(void)
    {
    Secret key,
        guess;
    char feedback[SECRET_SIZE + 1] = "____";
    int incorrect = 1,
        scaned_nums,
        num_guesses;

    /* Randomize 4 numbers */
    getSecretKey(key);
    printf("Facit: %d%d%d%d\n", key[0], key[1], key[2], key[3]);

    /* Guess and correct */
    do
        {
        printf("Ange din gissning:  ");
        scaned_nums = scanf("%1d%1d%1d%1d", &guess[0], &guess[1], &guess[2], &guess[3]);
        /* Did the user enter 4 numbers? */
        if (scaned_nums == SECRET_SIZE)
            {
            ++num_guesses;
            /*printf("Du gissade p\x86: %d%d%d%d\n", guess[0], guess[1], guess[2], guess[3]);*/
            controlGuess(key, guess, feedback);
            /* Did the user figure out all numbers? */
            if (!strcmp(feedback, "RRRR"))
                {
                incorrect = 0;
                }
            else
                {
                printf("Det var fel. Hj\x84lp: %s\n", feedback);
                }
            }
        else
            {
            printf("\nDu angav felaktig gissning. Skriv in 4 siffror!\n");
            }

        /* Clear stdin buffer if the user entered to long guess */
        fflush(stdin);
        }
    while (incorrect);

    return num_guesses;
    }
