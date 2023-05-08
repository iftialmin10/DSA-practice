/*
Write a C++ program to implement the Insertion Sort algorithm and demonstrate
its best, worst, and average cases. Your program should generate random arrays
of integers and sort them using Insertion Sort. You should measure the time
taken to sort each array and print the results for each case.

Explanation:

The code generates an array of 10000 random integers between 1 and
1000000 using the C++ random library. It then measures the time taken to sort
the array using the Insertion Sort algorithm in the best case, worst case, and average case.

In the best case, the array is already sorted, so the Insertion Sort algorithm
takes the shortest time to sort the array. In the worst case, the array is
sorted in reverse order, so the Insertion Sort algorithm takes the longest
time to sort the array. In the average case, the array is randomly generated,
so the Insertion Sort algorithm takes an average time to sort the array.

The code uses the high_resolution_clock from the <chrono> library to measure the
time taken to sort the arrays in microseconds. It then prints the time taken for
each case to the console.

Note: You can modify the SIZE constant to generate larger or smaller arrays and
adjust the distribution of the random integers by modifying the parameters of
the uniform_int_distribution<> function.
*/
#include <iostream>
#include <chrono>
#include <random>

using namespace std;
using namespace chrono;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    const int SIZE = 10000;
    int arr[SIZE];

    // Generate random arrays
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 1000000);
    for (int i = 0; i < SIZE; i++) {
        arr[i] = dis(gen);
    }

    // Best case
    auto start = high_resolution_clock::now();
    //ALAMIN TASK: WRITE ONE LINE OF CODE HERE TO MAKE THE CODE WORK
    ///////////line1

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Best case: " << duration.count() << " microseconds" << endl;

    // Worst case
    for (int i = 0; i < SIZE; i++) {
        arr[i] = SIZE - i;
    }
    start = high_resolution_clock::now();
    //ALAMIN TASK: WRITE ONE LINE OF CODE HERE TO MAKE THE CODE WORK
    ///////////line2

    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);
    cout << "Worst case: " << duration.count() << " microseconds" << endl;

    // Average case
    for (int i = 0; i < SIZE; i++) {
        arr[i] = dis(gen);
    }
    start = high_resolution_clock::now();
    //ALAMIN TASK: WRITE ONE LINE OF CODE HERE TO MAKE THE CODE WORK
    ///////////line3

    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);
    cout << "Average case: " << duration.count() << " microseconds" << endl;

    return 0;
}
