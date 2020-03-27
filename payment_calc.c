/*
 * Requirements:
 * Calculate weekly pay.
 * Ask the user to enter the number of worked hours for the week.
 * Display:
 *     Gross pay
 *     Taxes
 *     Net pay
 *
 * Assumptions:
 *     Basic pay rate: $12
 *     Overtime coefficient(in excess of 40 hrs): 1.5
 *     Tax rate:
 *         15% of the first $300
 *         20% of the next $150
 *         25% of the rest
 */

#include <stdio.h>

#define PAYRATE 12.00
#define TAXRATE_300 .15
#define TAXRATE_150 .20
#define TAXRATE_REST .25
#define OVERTIME_COEF 1.5

int main()
{
    int hours;
    int overtime;
    double pay;
    double tax;

    printf("Enter worked hours: ");
    scanf("%d", &hours);

    // Calculate gross pay
    pay = ((hours > 40) ? 40 : hours) * PAYRATE;
    // Add overtime pay
    overtime = hours - 40;
    if (overtime > 0)
        pay += (overtime * (PAYRATE * OVERTIME_COEF));
    // Calculate tax
    tax = (pay > 300.0) ? 300.0 * TAXRATE_300 : pay * TAXRATE_300;
    tax += ((pay - 300.0) > 150.0) ? 150.0 * TAXRATE_150 : (pay - 300.0) * TAXRATE_150;
    tax += ((pay - 450.0) > 0.0) ? (pay - 450.0) * TAXRATE_REST : 0.0;

    printf("Gross pay:\t\t$%.2f\n", pay);
    printf("Tax:\t\t\t$%.2f\n", tax);
    printf("Net pay:\t\t$%.2f\n", pay - tax);

    return 0;
}
