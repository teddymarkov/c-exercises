/*
 * WEATHER
 *
 * Requirements:
 * Calculate:
 *  - Total rainfall for each year
 *  - Average yearly rainfall
 *  - Average rainfall for each month
 */

#include <stdio.h>

int main() {
    const int AVAILABLE_YEARS[5] = {2010, 2011, 2012, 2013, 2014};
    const char *MONTHS[12] = {
            "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep",
            "Oct", "Nov", "Dec"
    };
    const double RAINFALL_DATA[5][12] = {
            {2.3, 4.5, 3.34, 1.4, 1.10, 2.23, 9.9, 3.3, 3.4, 4.6, 1.5, 5.7},
            {2.3, 4.5, 3.34, 1.4, 1.10, 2.23, 9.9, 3.3, 3.4, 4.6, 1.5, 5.7},
            {2.3, 4.5, 3.34, 1.4, 1.10, 2.23, 9.9, 3.3, 3.4, 4.6, 1.5, 5.7},
            {2.3, 4.5, 3.34, 1.4, 1.10, 2.23, 9.9, 3.3, 3.4, 4.6, 1.5, 5.7},
            {2.3, 4.5, 3.34, 1.4, 1.10, 2.23, 9.9, 3.3, 3.4, 4.6, 1.5, 5.7},
    };  // 5 years; 12 months;

    float totalYear[5] = {0};
    float monthlyAvg[12];
    int yCount, mCount;
    float sumPerMonth;
    float sumPerYear;
    float sumAll;

    // Calculation on year
    for (yCount = 0; yCount < 5; ++yCount) {
        sumPerYear = 0.0;
        for (mCount = 0; mCount < 12; ++mCount) {
            sumPerYear = sumPerYear + RAINFALL_DATA[yCount][mCount];
        }
        totalYear[yCount] = sumPerYear;
        sumAll = sumAll + sumPerYear;
    }

    // Calculation for month
    for (mCount = 0; mCount < 12; ++mCount) {
        sumPerMonth = 0.0;
        for (yCount = 0; yCount < 5; ++yCount) {
            sumPerMonth = sumPerMonth + RAINFALL_DATA[yCount][mCount];
        }
        monthlyAvg[mCount] = sumPerMonth / 5.0;
    }

    // Output total per year
    printf("YEAR\t\tRAINFALL (inches)\n");
    for (yCount = 0; yCount < 5; ++yCount) {
        sumPerYear = sumPerYear + totalYear[yCount];
        printf("%.d\t\t%.1f\n", AVAILABLE_YEARS[yCount], totalYear[yCount]);
    }
    // Output yearly average
    printf("\nThe yearly average is %f inches.\n", sumAll / 5);
    // Output monthly averages
    printf("\nMONTHLY AVERAGES:\n\n");
    for (mCount = 0; mCount < 12; ++mCount) {
        printf("%s\t\t", MONTHS[mCount]);
    }
    printf("\n");
    for (mCount = 0; mCount < 12; ++mCount) {
        printf("%.1f\t\t", monthlyAvg[mCount]);
    }

    return 0;
}
