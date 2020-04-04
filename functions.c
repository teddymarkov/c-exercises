/*
 * FUNCTIONS
 *
 * Requirements:
 * Write three functions
 *  - Function called gcd to find the greatest common divisor of two
 *  non-negative integer values and return the result;
 *  - Calculate the absolute value of a number. Takes a float. Return a float;
 *  - Compute the square root of a number. If a negative argument is passed,
 *  then a message is displayed and -1.0 is returned. Use the absoluteValue
 *  function above???;
 */

#include <stdio.h>

int gcd(int x, int y);
float absoluteValue(float x);
float squareRoot(float x);


int gcd(int u, int v) {
    int temp;
    while (v != 0) {
        temp = u % v;
        u = v;
        v = temp;

    }
    return u;
}

float absoluteValue(float x) {
    if (x < 0) {
        x = -x;
    }
    return x;
}

float squareRoot(float x) {

    const float epsilon = .00001;
    float guess = 1.0;
    if (x < 0) {
        printf("Negative value provided\n");
        return -1;
    }
    while (absoluteValue(guess * guess - x) >= epsilon) {
        guess = (x / guess + guess) / 2.0;
    }
    return guess;
}

int main() {
    // GCD
    int number1 = 5;
    int number2 = 15;
    float number3 = (float)-40.45;
    float number4 = -9;
    printf("The GCD of %d and %d is %d.\n", number1, number2, gcd(number1, number2));
    // Absolute value
    printf("The absolute value of %f is %f\n", number3, absoluteValue(number3));
    // Square root
    printf("The square root of %f is %f\n", number4, squareRoot(number4));

    return 0;
}
