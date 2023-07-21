/*
The Quick Sort algorithm is a widely used sorting algorithm that follows the divide-and-conquer approach.
 Here's a summary of the procedure:

1. The `swap` function is defined to swap two elements in an array.

2. The `partition` function is defined to select a pivot element and rearrange the elements in the array
such that all elements smaller than the pivot are on the left, and all elements greater than the pivot
are on the right. The pivot element is placed in its final sorted position. This function returns the
index of the pivot element.

3. The `quickSort` function is defined to recursively sort the sub-arrays. It takes the input array, the
starting index (low), and the ending index (high) as parameters. Inside this function:
   - Check if the low index is less than the high index. If not, return.
   - Call the `partition` function to obtain the pivot index.
   - Recursively call `quickSort` for the sub-array on the left of the pivot (from low to pivot-1).
   - Recursively call `quickSort` for the sub-array on the right of the pivot (from pivot+1 to high).

4. The `printArray` function is defined to print the elements of an array.

5. In the `main` function:
   - Various test cases are defined, each with its own array and size.
   - The original arrays are printed.
   - The `quickSort` function is called on each array to sort it.
   - The sorted arrays are printed.

The Quick Sort algorithm has an average time complexity of O(n log n) and a worst-case time complexity of
O(n^2) when the input is already sorted or nearly sorted. However, it is an efficient and widely used sorting algorithm in practice.
*/

#include <iostream>
using namespace std;

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function to divide the array into two sub-arrays
int partition(int arr[], int low, int high) {
    // Choose the rightmost element as the pivot
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        // If the current element is smaller than or equal to the pivot,
        // swap it with the element at the next position
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    // Swap the pivot element with the element at the next position
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array
        int pivot = partition(arr, low, high);
        // Recursively sort the two sub-arrays using two lines of code
        // They are responsible for sorting the sub-arrays on the left and right sides of the pivot element.
        // 1. The first line
        // - This line recursively calls the `quickSort` function to sort the sub-array on the left side of the pivot element.
        // - The `low` index remains the same, as it represents the starting index of the current sub-array.
        // - The `pivot - 1` index is passed as the new `high` index, indicating that the sub-array should end just before the pivot element.

        // 2. The second line
        // - This line recursively calls the `quickSort` function to sort the sub-array on the right side of the pivot element.
        // - The `pivot + 1` index is passed as the new `low` index, indicating that the sub-array should start just after the pivot element.
        // - The `high` index remains the same, as it represents the ending index of the current sub-array.

        // By making these recursive calls, the Quick Sort algorithm ensures that the sub-arrays are sorted individually. The process continues until the sub-arrays become empty or contain only one element, at which point the recursion stops. The algorithm then combines the sorted sub-arrays to obtain the final sorted array.

        //ALAMIN TASK: WRITE TWO LINES OF CODE HERE TO MAKE THE CODE WORK
        quickSort(arr ,low, pivot-1); //LINE1
        quickSort(arr , pivot+1, high);//LINE2
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Test cases
    int arr1[] = { 64, 25, 12, 22, 11 };
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Original array: ";
    printArray(arr1, n1);
    quickSort(arr1, 0, n1 - 1);
    cout << "Sorted array: ";
    printArray(arr1, n1);

    int arr2[] = { -4, 10, 3, 7, 1 };
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "Original array: ";
    printArray(arr2, n2);
    quickSort(arr2, 0, n2 - 1);
    cout << "Sorted array: ";
    printArray(arr2, n2);

    int arr3[] = { 5, 5, 5, 5, 5 };
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    cout << "Original array: ";
    printArray(arr3, n3);
    quickSort(arr3, 0, n3 - 1);
    cout << "Sorted array: ";
    printArray(arr3, n3);

    int arr4[] = { 1, 2, 3, 4, 5 };
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    cout << "Original array: ";
    printArray(arr4, n4);
    quickSort(arr4, 0, n4 - 1);
    cout << "Sorted array: ";
    printArray(arr4, n4);

    int arr5[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    int n5 = sizeof(arr5) / sizeof(arr5[0]);
    cout << "Original array: ";
    printArray(arr5, n5);
    quickSort(arr5, 0, n5 - 1);
    cout << "Sorted array: ";
    printArray(arr5, n5);

    int arr6[] = { 100, 4, 200, 1, 3, 2, 9, 8, 7, 6, 5 };
    int n6 = sizeof(arr6) / sizeof(arr6[0]);
    cout << "Original array: ";
    printArray(arr6, n6);
    quickSort(arr6, 0, n6 - 1);
    cout << "Sorted array: ";
    printArray(arr6, n6);

    return 0;
}

