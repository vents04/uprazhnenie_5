#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void add(int **numbers, int *size, int x) {
    (*size)++;
    *numbers = realloc(*numbers, (*size) * sizeof(int));
    if (*numbers == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    (*numbers)[*size - 1] = x;
}

void delete(int **numbers, int *size, int x) {
    int toBeKept = 0;
    for (int index = 0; index < *size; index++) {
        if ((*numbers)[index] != x) {
            (*numbers)[toBeKept++] = (*numbers)[index];
        }
    }
    *size = toBeKept;
    *numbers = realloc(*numbers, (*size) * sizeof(int));
    if (*size > 0 && *numbers == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
}

void smallest(int **numbers, int *size, int x) {
    if (x <= 0 || x > *size) {
        printf("Invalid value of X!\n");
        return;
    }
    for (int current = 0; current < x; current++) {
        int minIndex = current;
        for (int search = current + 1; search < *size; search++) {
            if ((*numbers)[search] < (*numbers)[minIndex]) {
                minIndex = search;
            }
        }
        int temporary = (*numbers)[current];
        (*numbers)[current] = (*numbers)[minIndex];
        (*numbers)[minIndex] = temporary;
    }
    printf("%d-th smallest element removed.\n", x);
    delete(numbers, size, (*numbers)[x - 1]);
}


void printArray(int *numbers, int size) {
    printf("Current array: ");
    for (int index = 0; index < size; index++) {
        printf("%d ", numbers[index]);
    }
    printf("\n");
}

void fcTask5() {
    int *numbers = NULL;
    int size = 0;

    int command, x;
    while (1) {
        printf("Enter command (1: add, 2: delete, 3: smallest), 0 to exit: ");
        scanf("%d", &command);

        if (command == 0) {
            break;
        }

        switch (command) {
            case 1:
                printf("Enter number to add: ");
                scanf("%d", &x);
                add(&numbers, &size, x);
                printArray(numbers, size);
                break;
            case 2:
                printf("Enter number to delete: ");
                scanf("%d", &x);
                delete(&numbers, &size, x);
                printArray(numbers, size);
                break;
            case 3:
                printf("Enter X for X-th smallest: ");
                scanf("%d", &x);
                smallest(&numbers, &size, x);
                printArray(numbers, size);
                break;
            default:
                printf("Invalid command!\n");
                break;
        }
    }

    free(numbers);
}
