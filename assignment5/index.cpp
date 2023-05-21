/*
To demonstrate the run time of O(n^3), O(n^4), and O(n^5) using C++,
we can create three separate functions that perform nested loops with different exponents of n.

In this code, we define three functions cubicRuntime(), quarticRuntime(), and quinticRuntime()
which have runtimes of O(n^3), O(n^4), and O(n^5) respectively. Each function takes an integer
n as input, which determines the size of the loops.

Inside each function, we use nested loops to perform some O(1) operation, and we measure the time
it takes to complete the loops using the chrono library. We output the duration in microseconds
to the console.

In the main() function, we call each of the three runtime functions with an input of n = 100.
This value can be adjusted to test the runtimes for different input sizes.
*/

#include <iostream>
#include <chrono>

using namespace std;

void cubicRuntime(int n) {
    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                // some O(1) operation
            }
        }
    }

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();

    cout << "Cubic Runtime: " << duration << " microseconds" << endl;
}

void quarticRuntime(int n) {
    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                for (int l = 0; l < n; l++) {
                    // some O(1) operation
                }
            }
        }
    }

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();

    cout << "Quartic Runtime: " << duration << " microseconds" << endl;
}

void quinticRuntime(int n) {
    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                for (int l = 0; l < n; l++) {
                    for (int m = 0; m < n; m++) {
                        // some O(1) operation
                    }
                }
            }
        }
    }

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();

    cout << "Quintic Runtime: " << duration << " microseconds" << endl;
}

int main() {
    int n = 100;
    //ALAMIN TASK: write three line of code here to make the code work
    cubicRuntime(n); ////////line1

    quarticRuntime(n); ////////line2

    quinticRuntime(n); ////////line3

    return 0;
}

