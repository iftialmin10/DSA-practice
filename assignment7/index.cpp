/*
Summary:

The Divide and Conquer Sort algorithm is a recursive sorting algorithm that
breaks down an array into smaller sub-arrays, sorts each sub-array, and
then merges the sub-arrays back together to form a sorted array. The algorithm
works by dividing the input array into two halves, recursively sorting the
two halves, and then merging the sorted halves back together. The merge
operation is the key part of the algorithm and involves comparing the elements
of the two sub-arrays and inserting them into a new array in sorted order.

Explanation:

The merge function takes in the array to be sorted, the left index, the middle
index, and the right index. It first calculates the sizes of the two sub-arrays
by subtracting the middle index from the left index and the right index from
the middle index. It then creates two temporary sub-arrays L and R of the
corresponding sizes. The elements of the left sub-array are copied into L, and
the elements of the right sub-array are copied into R. The function then uses
three counters i, j, and k to merge the two sub-arrays back into the original
array. The counters i and j are used to iterate over the elements of the left
and right sub-arrays, respectively. The counter k is used to keep track of the
position in the original array where the next element should be placed. The
function compares the current elements of the left and right sub-arrays and
inserts the smallest element into the original array, and then increments the
corresponding counter to move to the next element in that sub-array.

*/

#include <iostream>
using namespace std;

// The merge function takes in the array to be sorted, the left index, the middle index, and the right index
void merge(int arr[], int l, int m, int r) {

    // Calculate the sizes of the two sub-arrays
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create two temporary sub-arrays of the corresponding sizes
    int L[n1], R[n2];

    // Copy the elements of the left sub-array into L
    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }

    // Copy the elements of the right sub-array into R
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    // Use three counters i, j, and k to merge the two sub-arrays back into the original array
    int i = 0, j = 0, k = l;

    // Compare the current elements of the left and right sub-arrays and insert them into the original array in sorted order
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

    // Copy any remaining elements of the left sub-array into the original array
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy any remaining elements of the right sub-array into the original array
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// The mergeSort function takes in the array to be sorted, the left index, and the right index
void mergeSort(int arr[], int l, int r) {

    // Base case: if there is only one element or less in the sub-array, return
    if (l < r) {

        // Calculate the middle index
        int m = l + (r - l) / 2;

        // Recursively sort the left sub-array
        //ALAMIN TASK: WRITE ONE LINE OF CODE HERE TO MAKE THE CODE WORK
        mergeSort(arr, l, m) ;////////LINE1

        // Recursively sort the right sub-array
        //ALAMIN TASK: WRITE ONE LINE OF CODE HERE TO MAKE THE CODE WORK
        mergeSort(arr, m+1, r); ////////LINE2

        // Merge the sorted left and right sub-arrays
        merge(arr, l, m, r);
    }
}

int main() {

    // Declare the array to be sorted
    int arr[] = { 5, 2, 8, 1, 3 };

    // Calculate the size of the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Print the unsorted array
    cout << "Unsorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    // Sort the array using merge sort
    mergeSort(arr, 0, n - 1);

    // Print the sorted array
    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
