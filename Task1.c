#include <stdio.h>
#include "Tasks.h"

void fcTask1(void)
{
    printf("Perform task 1\n");

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

    for (int row = 0; row < n; row++) {
        for (int column = 0; column < m - 1; column++) {
            if (numbers[row][column] > numbers[row][column+1]) {
                printf("False\n");
                return;
            }
        }
    }

    for (int column = 0; column < m; column++) {
        for (int row = 0; row < n - 1; row++) {
            if (numbers[row][column] < numbers[row+1][column]) {
                printf("False\n");
                return;
            }
        }
    }

    printf("True\n");
}
