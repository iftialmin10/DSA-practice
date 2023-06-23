#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Job {
    char id;
    int deadline;
    int profit;
} Job;

int compareJobsByProfitDesc(const void* a, const void* b)
{
    Job* job1 = (Job*)a;
    Job* job2 = (Job*)b;
    return (job2->profit - job1->profit);
}

int getMinimum(int num1, int num2)
{
    return (num1 > num2) ? num2 : num1;
}

void printJobScheduling(Job jobs[], int numJobs)
{
    qsort(jobs, numJobs, sizeof(Job), compareJobsByProfitDesc);

    int jobSequence[numJobs];
    bool timeSlotAvailable[numJobs];

    for (int i = 0; i < numJobs; i++)
        timeSlotAvailable[i] = false;

    for (int i = 0; i < numJobs; i++) {
        for (int j = getMinimum(numJobs, jobs[i].deadline) - 1; j >= 0; j--) {
            if (timeSlotAvailable[j] == false) {
                //ALAMIM TASK: WRITE TWO LINES OF CODE TO MAKE THE CODE WORK
                //LINE 1

                //LINE 2

                break;
            }
        }
    }

    printf("The maximum profit sequence of jobs is: \n");

    for (int i = 0; i < numJobs; i++) {
        if (timeSlotAvailable[i])
            printf("%c ", jobs[jobSequence[i]].id);
    }
}

int main()
{
    Job jobs[] = {
        { 'a', 2, 100 },
        { 'b', 1, 19 },
        { 'c', 2, 27 },
        { 'd', 1, 25 },
        { 'e', 3, 15 }
    };
    int numJobs = sizeof(jobs) / sizeof(jobs[0]);

    printf("Following is the maximum profit sequence of jobs:\n");
    printJobScheduling(jobs, numJobs);

    return 0;
}
