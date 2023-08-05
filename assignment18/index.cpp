/*
You are given a sequence of matrices, and your task is to find the most efficient way to multiply
these matrices together. Each matrix has dimensions A1, A2, A3, ..., An-1, An, where the i-th matrix
has dimensions Ai x Ai+1. The cost of multiplying two matrices with dimensions p x q and q x r is
p x q x r.

Your goal is to minimize the total cost of multiplying all the matrices together.


In this implementation, we use a 2D table dp to store the minimum number of multiplications needed for
multiplying matrices from i to j. The dp table is initialized with 0s.

We calculate the minimum number of multiplications using the bottom-up approach. The outer loop len
represents the length of the chain, starting from 2 (since the minimum chain length is 2) up to n-1
(where n is the number of matrices). The inner loop i iterates over the range of possible starting
positions, and j is calculated as i + len - 1 to determine the ending position.

Within the inner loop, we initialize dp[i][j] with a large value (LONG_MAX) to ensure that any valid
cost will be smaller. We then try all possible combinations of splitting the chain at position k
(where k ranges from i to j-1). We calculate the cost of multiplying the two resulting subchains and
add the cost of multiplying the matrices at position i-1, k, and j.

Finally, we return dp[1][n-1], which represents the minimum number of multiplications needed for the
entire chain.
*/
#include <iostream>
#include <climits>
using namespace std;

// Function to calculate the minimum number of multiplications needed for matrix chain multiplication
long matrixChainMultiplication(int dimensions[], int n) {
    // Create a 2D table to store the minimum number of multiplications
    // needed for multiplying matrices from i to j
    long dp[n][n];

    // Initialize the table with 0s
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = 0;
        }
    }

    // Calculate the minimum number of multiplications
    // using the bottom-up approach
    for (int len = 2; len < n; len++) {
        for (int i = 1; i < n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = LONG_MAX; // Initialize with a large value

            // Try all possible combinations to find the minimum
            for (int k = i; k <= j - 1; k++) {
                //ALAMIN TASK: WRITE ONE LINE OF CODE HERE TO MAKE THE CODE WORK
                int cost = dp[i][k] + dp[k+1] [j] + dimensions[i-1] * dimensions[k] * dimensions[j];//LINE 1

                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    // Return the minimum number of multiplications for the entire chain
    return dp[1][n - 1];
}

int main() {
    int dimensions1[] = {10, 30, 5, 60};
    int n1 = sizeof(dimensions1) / sizeof(dimensions1[0]);
    long minimumMultiplications1 = matrixChainMultiplication(dimensions1, n1);
    cout << "Test Case 1 - Minimum number of multiplications needed: " << minimumMultiplications1 << endl;

    int dimensions2[] = {3, 4, 2, 5, 1};
    int n2 = sizeof(dimensions2) / sizeof(dimensions2[0]);
    long minimumMultiplications2 = matrixChainMultiplication(dimensions2, n2);
    cout << "Test Case 2 - Minimum number of multiplications needed: " << minimumMultiplications2 << endl;

    int dimensions3[] = {1, 2, 3, 4, 5};
    int n3 = sizeof(dimensions3) / sizeof(dimensions3[0]);
    long minimumMultiplications3 = matrixChainMultiplication(dimensions3, n3);
    cout << "Test Case 3 - Minimum number of multiplications needed: " << minimumMultiplications3 << endl;

    int dimensions4[] = {4, 2, 3, 1, 5};
    int n4 = sizeof(dimensions4) / sizeof(dimensions4[0]);
    long minimumMultiplications4 = matrixChainMultiplication(dimensions4, n4);
    cout << "Test Case 4 - Minimum number of multiplications needed: " << minimumMultiplications4 << endl;

    int dimensions5[] = {6, 2, 8, 4};
    int n5 = sizeof(dimensions5) / sizeof(dimensions5[0]);
    long minimumMultiplications5 = matrixChainMultiplication(dimensions5, n5);
    cout << "Test Case 5 - Minimum number of multiplications needed: " << minimumMultiplications5 << endl;

    return 0;
}

