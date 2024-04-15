#include <stdio.h>
#include "Tasks.h"

void fcTask2(void)
{
    printf("Perform task 2\n");

    int n, m;

    printf("Enter number of rows for array:\n");
    scanf("%d", &n);
    printf("Enter number of columns for array:\n");
    scanf("%d", &m);

    int numbers[n*m];
    for (int row = 0; row < n; row++){
        for (int column = 0; column < m; column++){
            printf("Enter number for [%d][%d]:\n", row, column);
            scanf("%d", &numbers[row*m + column]);
        }
    }

    int maxSum = 0;
    int maxSumNumber = 0;

    for (int row = 0; row < n; row++) {
        for (int column = 0; column < m; column++) {
            int currentSum = 0;
            for (int x = row - 1; x <= row + 1; x++) {
                for (int y = column - 1; y <= column + 1; y++) {
                    if (x >= 0 && x < n && y >= 0 && y < m && (x != row || y != column)) {
                        currentSum += numbers[x * m + y];
                    }
                }
            }
            if (currentSum > maxSum){
                maxSum = currentSum;
                maxSumNumber = numbers[row * m + column];
            }
        }
    }

    printf("The number with the maximum sum of neighboring elements is: %d\n", maxSumNumber);
}

