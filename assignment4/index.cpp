/*
Assignment:
Implement the following three sorting algorithms in C++ and compare their time complexities:

Bubble Sort (O(n^2))
Merge Sort (O(n log n))
Quick Sort (O(n log n) in average case and O(n^2) in worst case)


The program generates an array of 100000 random integers using a uniform distribution.
It then sorts the array using Bubble Sort, Merge Sort, and Quick Sort, and prints the
time taken by each algorithm. The chrono library is used to measure the execution
time of each sorting algorithm.
*/

/*
The bubbleSort is used to sort the entire array arr using the bubble sort algorithm.
In the bubble sort algorithm, we repeatedly swap adjacent elements if they are in the wrong order
until the entire array is sorted. In each iteration, the largest element "bubbles up"
to its correct position at the end of the array.

The bubbleSort function takes two arguments - the array to be sorted arr and the size of the array n.

By passing n as the size of the array, we are instructing the bubbleSort function to sort the entire
array, starting from the first element (arr[0]) and ending at the last element (arr[n-1]).
*/

/*
The mergeSort is used to sort the entire array arr using the merge sort algorithm.
In the merge sort algorithm, we start by dividing the array into two halves and recursively sorting each half.
Once the two halves are sorted, we merge them to produce the final sorted array.

The mergeSort function takes three arguments - the array to be sorted arr, the starting index of the array 0,
and the ending index of the array n-1. The ending index of the array is n-1 because the array
indices start from 0 and end at n-1.

By passing 0 as the starting index and n-1 as the ending index, we are instructing the mergeSort function
to sort the entire array starting from the first element (arr[0]) and ending at the last element (arr[n-1]).
*/

/*
The quickSort is used to sort the entire array arr using the quicksort algorithm.
In the quicksort algorithm, we first choose a pivot element from the array. We then partition
the array around the pivot element such that all the elements smaller than the pivot are on its
left and all the elements greater than the pivot are on its right. We then recursively apply the
same procedure on the left and right subarrays until the entire array is sorted.

The quickSort function takes three arguments - the array to be sorted arr, the starting index of
the array 0, and the ending index of the array n-1. The ending index of the array is n-1 because
the array indices start from 0 and end at n-1.

By passing 0 as the starting index and n-1 as the ending index, we are instructing the quickSort
function to sort the entire array starting from the first element (arr[0]) and ending at the last element (arr[n-1]).
*/

#include <iostream>
#include <chrono>
#include <random>

using namespace std;

// Bubble Sort implementation
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Merge Sort implementation
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l+(r-l)/2;

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

// Quick Sort implementation
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    // Generate random array
    const int n = 10000;
    int arr[n];
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> uni(-100000,100000);
    for(int i=0; i<n; i++) {
        arr[i] = uni(rng);
    }

    // Sort using Bubble Sort
    auto start1 = chrono::high_resolution_clock::now();
    //ALAMIN TASK: Write one line of code here to make the code work
    //////////line1
    auto end1 = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed_seconds1 = end1 - start1;
    cout << "Time taken by Bubble Sort: " << elapsed_seconds1.count() << "s" << endl;

    // Sort using Merge Sort
    auto start2 = chrono::high_resolution_clock::now();
    //ALAMIN TASK: Write one line of code here to make the code work
    //////////line2
    auto end2 = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed_seconds2 = end2 - start2;
    cout << "Time taken by Merge Sort: " << elapsed_seconds2.count() << "s" << endl;

    // Sort using Quick Sort
    auto start3 = chrono::high_resolution_clock::now();
    //ALAMIN TASK: Write one line of code here to make the code work
    //////////line3
    auto end3 = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed_seconds3 = end3 - start3;
    cout << "Time taken by Quick Sort: " << elapsed_seconds3.count() << "s" << endl;

    return 0;
}
