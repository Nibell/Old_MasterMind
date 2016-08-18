/*
    unix.c
    UNIX specific implementations of some functions

    Authors:    Christoffer Lindahl <christoffer@kekos.se>
                Markus Thorsberg <markus.thorsberg@student.hv.se>
                Linus Nibell <linus.nibell@student.hv.se>
    Date:       2011-03-01, last edit 2011-03-01
    Version:    0.1
*/
#include <stdlib.h>   /* For system() */

/*
    clearScreen()
    Clears the screen
    @dependencies -
    @return void
*/
void clearScreen(void)
    {
    system("clear");
    }
