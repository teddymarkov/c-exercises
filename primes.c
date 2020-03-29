/*
 * PRIME NUMBERS GENERATOR
 *
 * Requirements:
 * Find the prime numbers up to 100
 */

#include <stdio.h>
#include <stdbool.h>

int main()
{
    int primes[50] = {0};
    int i, p;
    int length = 2;  // Store count of the length of the primes array;
    bool isPrime;

    primes[0] = 2;
    primes[1] = 3;

    for (p = 5; p <= 100; p = p + 2) {
        isPrime = true;
        for (i = 1; isPrime && p / primes[i] >= primes[i]; ++i) {
            if (p % primes[i] == 0) {
                isPrime = false;
            }
        }

        if (isPrime == true) {
            primes[length] = p;
            ++length;
        }
    }

    for (i = 0; i < length; ++i) {
        printf("%d ", primes[i]);
    }

    return 0;
}
