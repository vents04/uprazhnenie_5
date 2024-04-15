#include <stdio.h>
#include <stdlib.h>

void addFriend(int **friends, int person1, int person2, int *numFriends) {
    friends[person1][numFriends[person1]] = person2;
    friends[person2][numFriends[person2]] = person1;
    numFriends[person1]++;
    numFriends[person2]++;
}

void printFriends(int **friends, int person, int *numFriends) {
    printf("Friends of person %d are: ", person + 1);
    for (int friendIndex = 0; friendIndex < numFriends[person]; friendIndex++) {
        printf("%d ", friends[person][friendIndex] + 1);
    }
    printf("\n");
}

void fcTask4() {
    int n;
    printf("Enter the number of people: ");
    scanf("%d", &n);

    int **friends = malloc(n * sizeof(int *));
    int *numFriends = calloc(n, sizeof(int));
    if (friends == NULL || numFriends == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    for (int person = 0; person < n; person++) {
        friends[person] = malloc(n * sizeof(int));
        if (friends[person] == NULL) {
            printf("Memory allocation failed!\n");
            return;
        }
    }

    printf("Enter the friendships:\n");
    for (int person = 0; person < n; person++) {
        int m;
        printf("Enter the number of friends for person %d: ", person + 1);
        scanf("%d", &m);

        printf("Enter the friends of person %d: ", person + 1);
        for (int friendIndex = 0; friendIndex < m; friendIndex++) {
            int friend;
            scanf("%d", &friend);
            if (friend < 1 || friend > n) {
                printf("Invalid friend number!\n");
                return;
            }
            addFriend(friends, person, friend - 1, numFriends);
        }
    }

    int personToCheck;
    printf("Enter the person whose friends you want to check: ");
    scanf("%d", &personToCheck);

    if (personToCheck >= 1 && personToCheck <= n) {
        printFriends(friends, personToCheck - 1, numFriends);
    } else {
        printf("Invalid person number!\n");
    }

    for (int person = 0; person < n; person++) {
        free(friends[person]);
    }

    free(friends);
    free(numFriends);
}
