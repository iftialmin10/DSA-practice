/*
Assignment:

Write a C++ program that takes an integer as input from the user and checks whether
it is a prime number or not. Use a while loop and ensure that the algorithm has a
time complexity of O(n^0.5).

The program first takes an integer as input from the user and checks if it is less than 2.
If so, it outputs "Not a prime number" and exits. Otherwise, it sets a flag isPrime to true,
and checks if the input number is divisible by any number from 2 to sqrt(n) using a while loop.
If it is, the flag is set to false and the loop is terminated. Finally, the program outputs
whether the input number is prime or not based on the value of the isPrime flag.
The while loop ensures that the algorithm has a time complexity of O(n^0.5).
*/
#include <iostream>
using namespace std;

int main() {
    int n, i = 2;
    bool isPrime = true;

    cout << "Enter a positive integer: ";
    cin >> n;

    // Check if the input number is less than 2
    if (n < 2) {
        cout << "Not a prime number\n";
        return 0;
    }

    // Check if the input number is divisible by any number from 2 to sqrt(n)
    while (i * i <= n) {
        if (n % i == 0) {
            // ALAMIN TASK: write exactly two lines of code here to make this code work as the output image
            isPrime = false; //////line1
            //////line2
            
        }
        i++;
    }

    // Output the result
    if (isPrime) {
        cout << n << " is a prime number\n";
    } else {
        cout << n << " is not a prime number\n";
    }

    return 0;
}
