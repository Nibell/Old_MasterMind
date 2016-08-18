/*
    main.c
    The main file for Mastermind

    Authors:    Christoffer Lindahl <christoffer@kekos.se>
                Markus Thorsberg <markus.thorsberg@student.hv.se>
                Linus Nibell <linus.nibell@student.hv.se>
    Date:       2011-02-14, last edit 2011-03-07
    Version:    0.6
*/
#include "mastermind.h"
#include "highscore.h"

/*
å = \x86
ä = \x84
ö = \x94
Å = \x8f
Ä = \x8e
Ö = \x99
*/

int main(void)
{
    Player highscore[SIZE_HIGHSCORE];
    char menu;
    int num_guesses,
    num_highscores;
    int i;

    /* Load highscore file in to program */
    num_highscores = loadHighscore(highscore);
    if (num_highscores < 0)
    {
        printf("Kunde inte \x94ppna/skapa topplistefilen.");
        exit(-1);
    }

    /*for (i = 0; i < num_highscores; i++)
        {
        printf("%d: %s,%d\n", i, highscore[i].name, highscore[i].guesses);
        }

    sortPlayers(highscore, num_highscores);

    printf("\n\n");

    for (i = 0; i < num_highscores; i++)
        {
        printf("%d: %s,%d\n", i, highscore[i].name, highscore[i].guesses);
        }

    return 0;*/

    do
    {
        clearScreen();
        printf("%s\n%s\n%s\n%s\n%s\n\n",
               "Christoffer, Markus   _   och Linus             _           _",
               " _ __ ___   __ _  ___| |_  ___  _ __  _ __ ___ ( )_ __   __| |",
               "| '_ ' _ \\ / _` |/ __|  _|/ _ \\| '__|| '_ ' _ \\| | '_ \\ / _  |",
               "| | | | | | (_| |\\__ \\ |_(  __/| |   | | | | | | | | | ( (_) |",
               "|_| |_| |_|\\__,_||___/___)\\___||_|   |_| |_| |_|_|_| |_|\\____|");
        printf("V\x84lj ett av f\x94ljande:\nS - Spela Mastermind\nT - Visa topplistan\nA - Avsluta\n>");
        scanf("%s", &menu);

        if (menu == 's' || menu == 'S')
        {
            num_guesses = playGame();

            /* Highscores */

            printf("Hittade %d spelare p\x86 topplistan.", num_highscores);

            storeHighscore(num_guesses);

            system("pause");
        }
        else if (menu == 't' || menu == 'T')
        {
            printf("Topplistan\n\n");

            sortPlayers(highscore, num_highscores);

            for (i = 0; i < num_highscores; i++)
            {
                printf("%d: %s,%d\n", i, highscore[i].name, highscore[i].guesses);
            }

            system("pause");
        }
    }
    while (menu != 'a' && menu != 'A');

    return 0;
}
