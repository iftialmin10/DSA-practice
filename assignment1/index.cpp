/*
Assignment:

Write a C++ program that demonstrates A Priori analysis. Your program should have a function that takes in an array of integers 
and returns the maximum value in the array. Before calling the function, perform A Priori analysis to ensure that the function 
will return the expected result for a given input array.

Explanation:

The program defines a max_value function that takes in an array of integers and returns the maximum value in the array. 
In the main function, we create an array of integers arr and its size arr_size.

Before calling the max_value function, we perform A Priori analysis by asserting that the function will return the expected 
result for the given input array. We assert that the maximum value in the array is 8, which is the correct value.

Next, we call the max_value function with the arr array and store the result in a variable max_val. We then print the maximum 
value in the array using cout.

Overall, this program demonstrates A Priori analysis in C++ using assert statements to ensure that a function will return the 
expected result for a given input.
*/
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
