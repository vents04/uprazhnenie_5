#include <stdio.h>
#include "Tasks.h"

void fcTask3(void)
{
    printf("Perform task 3\n");

    int n, m;

    printf("Enter number of rows for array:\n");
    scanf("%d", &n);
    printf("Enter number of columns for array:\n");
    scanf("%d", &m);

    int numbers[n][m];

    for (int row = 0; row < n; row++){
        for (int column = 0; column < m; column++){
            printf("Enter number for [%d][%d]:\n", row, column);
            scanf("%d", &numbers[row][column]);
        }
    }

    int minRowIndex = 0, maxRowIndex = 0;
    int minValue = numbers[0][0], maxValue = numbers[0][0];
    for (int row = 0; row < n; row++) {
        for (int column = 0; column < m; column++) {
            if (numbers[row][column] < minValue) {
                minValue = numbers[row][column];
                minRowIndex = row;
            }
            if (numbers[row][column] > maxValue) {
                maxValue = numbers[row][column];
                maxRowIndex = row;
            }
        }
    }

    for (int column = 0; column < m; column++) {
        int temporary = numbers[minRowIndex][column];
        numbers[minRowIndex][column] = numbers[maxRowIndex][column];
        numbers[maxRowIndex][column] = temporary;
    }

    for (int row = 0; row < n; row++) {
        for (int column = 0; column < m; column++) {
            printf("%d ", numbers[row][column]);
        }
        printf("\n");
    }
}
