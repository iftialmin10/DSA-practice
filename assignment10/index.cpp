#include <bits/stdc++.h>
using namespace std;

struct Item {
    int profit, weight;

    Item(int profit, int weight)
    {
        this->profit = profit;
        this->weight = weight;
    }
};

static bool compareByRatio(struct Item a, struct Item b)
{
    double ratio1 = (double)a.profit / (double)a.weight;
    double ratio2 = (double)b.profit / (double)b.weight;
    return ratio1 > ratio2;
}

double fractionalKnapsack(int knapsackCapacity, struct Item items[], int numItems)
{
    sort(items, items + numItems, compareByRatio);

    double totalProfit = 0.0;

    for (int i = 0; i < numItems; i++) {
        if (items[i].weight <= knapsackCapacity) {
            //ALAMIN TASK: WRITE TWO LINES OF CODE HERE TO MAKE THE CODE WORK
            //LINE1

            //LINE2

        }
        else {
            //ALAMIN TASK: WRITE ONE LINE OF CODE HERE TO MAKE THE CODE WORK
            //LINE1

            break;
        }
    }

    return totalProfit;
}

int main()
{
    int knapsackCapacity = 50;
    Item items[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };
    int numItems = sizeof(items) / sizeof(items[0]);

    double maxProfit = fractionalKnapsack(knapsackCapacity, items, numItems);
    cout << "Maximum achievable profit: " << maxProfit << endl;

    return 0;
}
