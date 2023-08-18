/*
Given a knapsack with a maximum weight capacity and a set of items, each with a weight and a value, determine the maximum value that can be obtained by selecting a subset of items to put into the knapsack. The knapsack has a constraint that only one copy of each item can be selected (0/1 property), and the total weight of the selected items cannot exceed the knapsack's weight capacity.

The goal is to maximize the total value of the selected items while ensuring that the total weight does not exceed the knapsack's capacity.

In this implementation, we define a knapsack function that takes the capacity, weights, values, and the number of items as parameters. It uses a 2D table (dp) to store the maximum values that can be obtained for different capacities and items.

We iterate through the items and capacities using nested loops. For each item and capacity, we check if the current item's weight is less than or equal to the current capacity. If it is, we calculate the maximum value that can be obtained by including or excluding the current item. If the weight is greater, we exclude the item and get the value from the previous row.

Finally, we return the maximum value that can be obtained from the last row of the table.

In the main function, we define the capacity, weights, values, and the number of items. We call the knapsack function with these parameters and print the result.
*/

#include <iostream>
#include <vector>

using namespace std;

// Function to solve the 0/1 Knapsack problem
int knapsack(int capacity, const vector<int>& weights, const vector<int>& values, int n) {
    // Create a 2D table to store the maximum values for different capacities and items
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // Fill the table in bottom-up manner
    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= capacity; ++w) {
            // If the current item's weight is less than or equal to the current capacity
            if (weights[i - 1] <= w) {
                // Calculate the maximum value that can be obtained by including or excluding the current item
                //ALAMIN TASK: WRITE ONE LINE OF CODE HERE TO MAKE THE CODE WORK
                dp[i][w] = max(values[i-1] + dp[i-1][w-weights[i - 1]], dp[i-1][w]); // LINE 1
            }
            else {
                // If the current item's weight is greater than the current capacity,
                // exclude the item and get the value from the previous row
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Return the maximum value that can be obtained
    return dp[n][capacity];
}

int main() {
    int capacity = 10;
    vector<int> weights = {2, 3, 4, 5};
    vector<int> values = {3, 4, 5, 6};
    int n = weights.size();

    int max_value = knapsack(capacity, weights, values, n);
    cout << "Test Case 1: Maximum value that can be obtained: " << max_value << endl;

    capacity = 7;
    weights = {1, 3, 4, 5};
    values = {1, 4, 5, 7};
    n = weights.size();

    max_value = knapsack(capacity, weights, values, n);
    cout << "Test Case 2: Maximum value that can be obtained: " << max_value << endl;

    capacity = 6;
    weights = {1, 2, 3, 4, 5};
    values = {2, 4, 4, 7, 8};
    n = weights.size();

    max_value = knapsack(capacity, weights, values, n);
    cout << "Test Case 3: Maximum value that can be obtained: " << max_value << endl;

    capacity = 8;
    weights = {1, 3, 4, 6};
    values = {2, 4, 5, 7};
    n = weights.size();

    max_value = knapsack(capacity, weights, values, n);
    cout << "Test Case 4: Maximum value that can be obtained: " << max_value << endl;

    capacity = 5;
    weights = {2, 3, 4};
    values = {3, 4, 5};
    n = weights.size();

    max_value = knapsack(capacity, weights, values, n);
    cout << "Test Case 5: Maximum value that can be obtained: " << max_value << endl;

    return 0;
}

