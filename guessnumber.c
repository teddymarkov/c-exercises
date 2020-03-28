/*
 * GUESS THE NUMBER
 *
 * Requirements:
 * First generate a random number from 0 to 20
 * Ask the user to guess it
 * Allowed input - numbers from 0 to 20
 * Then indicate if the number was too high or too low
 * User has 5 tries
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRIALS 3
#define MAX 20

int main()
{
    int randNumber;
    int i;
    int usrInput;
    time_t t;

    srand((unsigned) time(&t));
    randNumber = rand() % MAX + 1;

    for (i = TRIALS; i > 0; --i)
    {
        printf("%d attempts left\n", i);
        do {
            printf("Guess the number (allowed 0 - %d): ", MAX);
            scanf("%d", &usrInput);
        }
        while ((usrInput < 0) || (usrInput > MAX));

        if (usrInput > randNumber)
        {
            printf("Your number %d is greater than mine.\n", usrInput);
            continue;
        } else if (usrInput < randNumber)
        {
            printf("Your number %d is smaller than mine.\n", usrInput);
            continue;
        } else if (usrInput == randNumber)
        {
            printf("GOOD JOB! You have guessed the number %d\n", randNumber);
            exit(0);
        } else {
            printf("Unexpected behavior! Quitting...\n");
            exit(1);
        }
    }
    printf("Sorry, You couldn't guess the number.\n");

    return 0;
}
