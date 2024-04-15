#include <stdio.h>
#include <stdlib.h>
#include "Tasks.h"

//Task Function prototype
typedef void (*TaskFc)(void);

// Subscribed Task function list
TaskFc TaskFctions[]=
{
    fcTask1,
    fcTask2,
    fcTask3,
    fcTask4,
    fcTask5
};

int main()
{

//Call all task that was subscribe
    for(int i=0;i<sizeof(TaskFctions)/sizeof(TaskFctions[0]);i++)
    {
        printf("=============================\n"
               "Start Task:%d\n"
               "-----------------------------\n",i+1);
        TaskFctions[i]();// Execute task function
        printf("-----------------------------\n"
               "End Task:%d\n"
               "=============================\n",i+1);
    }
    return 0;
}
