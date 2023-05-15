/*
Implement a C++ program that takes an integer n as input and generates an array of n random integers.
Implement the selection sort algorithm to sort the array.
Measure the execution time of the sorting algorithm using the std::chrono library in C++.
Repeat steps 1-3 for different values of n, such as 10, 100, 1000, and 10000.
Print out the execution time for each value of n.
*/

/*
we generate arrays of sizes 10, 100, 1000, and 10000 and measure the execution time of the selection sort
algorithm on each of these arrays. The execution time is measured using the std::chrono library in C++.
The output of the program will be the execution time for each value of n.

Note: The execution time of the program may vary depending on the machine used to run it.
*/

#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;

void selectionSort(int arr[], int n) {
   for (int i = 0; i < n-1; i++) {
      int minIndex = i;
      for (int j = i+1; j < n; j++) {
         if (arr[j] < arr[minIndex]) {
            minIndex = j;
         }
      }
      swap(arr[i], arr[minIndex]);
   }
}

int main() {
   srand(time(0));
   int nValues[] = {10, 100, 1000, 10000};
   for (int i = 0; i < 4; i++) {
       int n = nValues[i];
      int arr[n];
      for (int j = 0; j < n; j++) {
         arr[j] = rand() % 100;
      }
      auto start = chrono::steady_clock::now();

      selectionSort(arr , n); //ALAMIN TASK: WRITE ONE LINE OF CODE HERE TO MAKE THE CODE WORK


      auto end = chrono::steady_clock::now();
      auto diff = end - start;
      cout << "Time taken for n = " << n << ": " << chrono::duration <double, milli> (diff).count() << " ms" << endl;
   }
   return 0;
}
