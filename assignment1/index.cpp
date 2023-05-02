#include <iostream>
#include <cassert>

using namespace std;

int max_value(int arr[], int size) {
    int max_val = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max_val) {
            //ALAMIN TASK: WRITE ONE LINE OF CODE HERE TO MAKE THE CODE WORK
        }
    }
    return max_val;
}

int main() {
    int arr[] = {5, 3, 8, 1, 6};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    // A Priori analysis: check if the function will return the expected result for the given input array
    assert(max_value(arr, arr_size) == 8);

    // Call the max_value function and store the result in a variable
    int max_val = max_value(arr, arr_size);

    // Print the maximum value in the array
    cout << "The maximum value in the array is " << max_val << endl;

    return 0;
}
