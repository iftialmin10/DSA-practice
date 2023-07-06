/*
You are given a set of jobs, each with a specific deadline and associated profit. 
The goal is to schedule the jobs in such a way that the total profit is maximized.

Each job has an ID, a deadline (the latest time by which the job needs to be completed), 
and a profit value. It is important to note that each job takes only one unit of time to complete.

The objective is to find the sequence of jobs that maximizes the total profit while ensuring that 
no job misses its deadline. In other words, you need to assign a time slot to each job, 
making sure that the job is completed before or on its deadline, and the total profit is maximized.

The task is to implement a program that takes the set of jobs as input and outputs the sequence 
of jobs that results in the maximum profit.

Example:
Suppose we have the following jobs with their respective deadlines and profits:
Job A: Deadline = 2, Profit = 100
Job B: Deadline = 1, Profit = 19
Job C: Deadline = 2, Profit = 27
Job D: Deadline = 1, Profit = 25
Job E: Deadline = 3, Profit = 15

The program should output the maximum profit sequence of jobs, considering their deadlines. 
In this case, the optimal sequence would be Job A, Job C, and Job E, resulting in a total profit of 142.

Note: It is assumed that jobs cannot be executed simultaneously, and each job can be completed 
within one unit of time.

*/
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
