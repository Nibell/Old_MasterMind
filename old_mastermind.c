/*
    mastermind.c
    Game functions for Mastermind

    Authors:    Christoffer Lindahl <christoffer@kekos.se>
                Markus Thorsberg <markus.thorsberg@student.hv.se>
                Linus Nibell <linus.nibell@student.hv.se>
    Date:       2011-02-14, last edit 2011-03-01
    Version:    0.3
*/
#include "mastermind.h"

/*
    fillWithRandom()
    Fills a secret key with size numbers of randomized numbers between 0 and 9
    @dependencies - <stdlib.h>
    @params Secret key - A secret variable that will store the numbers
    @params int size - Size of key
    @return void
*/
void fillWithRandom(Secret key, int size)
    {
    int i;

    for (i = 0; i < size; i++)
        {
        key[i] = (rand() % SECRET_MAX);
        }
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
    int is_same,
        i, j;

    /* Seed random generator */
    srand(time(NULL));

    /* As long as the 4 numbers are the same */
    do
        {
        is_same = 0;

        /* Randomize */
        fillWithRandom(key, SECRET_SIZE);

        /* Check numbers, for every number */
        for (i = 0; i < SECRET_SIZE; i++)
            {
            /* No need to keep checking if we already found duplicates */
            if (is_same)
                break;

            /* For all remaining numbers */
            for (j = i + 1; j < SECRET_SIZE; j++)
                {
                /* Check if numbers are the same */
                if (key[i] == key[j])
                    {
                    is_same = 1;
                    break;
                    }

                }
            }
        }
    while (is_same);
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
    int i, j;

    /* Check if the guess contained correct numbers */
    /* Loop through all numbers in guess */
    for (i = 0; i < SECRET_SIZE; i++)
        {
        /* Loop through all numbers in key */
        for (j = 0; j < SECRET_SIZE; j++)
            {
            /* If number in guess equals number in key then save a S in feedback */
            if (guess[i] == key[j])
                {
                feedback[i] = 'S';
                break;
                }
            /* ...or else save an underscore (that may be overwritten in next block) */
            else
                {
                feedback[i] = '_';
                }
            }
        }

    /* Check if the guess contained correct numbers at correct positions */
    /* Loop through all numbers in guess */
    for (i = 0; i < SECRET_SIZE; i++)
        {
        /* If number in guess equals number at same position in key */
        if (guess[i] == key[i])
            {
            feedback[i] = 'R';
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
