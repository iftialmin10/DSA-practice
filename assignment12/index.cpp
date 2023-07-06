/*
Given a set of files with different sizes, the goal is to merge these files together while minimizing the 
total amount of computation required. Each file has a certain size, and when two files are merged, the 
computation cost is equal to the sum of their sizes. The task is to determine the minimum number of 
computations needed to merge all the files.

The code solves this problem by using a clever approach. It uses a priority queue (min heap) to keep 
track of the file sizes. It repeatedly merges the two smallest files from the priority queue, updates 
the computation count, and adds the merged file size back to the priority queue. This process continues
until there is only one file left. Finally, the code returns the minimum number of computations required to merge all the files.

In simpler terms, the code finds an efficient way to combine the files with the least computation effort, 
ensuring that the total computation cost is minimized.


The given code aims to find the minimum number of computations required to merge a set of files with different sizes.
It utilizes a priority queue (min heap) to efficiently merge the files while minimizing the total computation cost.

Here's a summary of the code:

1. The code defines a function `findMinimumComputation` that takes the number of files (`numberOfFiles`) and an
array of file sizes (`fileSizes`) as parameters.

2. Inside the function, a min heap named `minHeap` is created using a `priority_queue` with a `greater<int>`
comparator.

3. The file sizes are pushed into the min heap using a loop.

4. The function enters a while loop that continues until there is only one element left in the min heap.

5. Inside the loop, the two smallest file sizes are extracted from the min heap, added together to get a combined
size, and the total computations are incremented accordingly.

6. The combined size is then pushed back into the min heap.

7. Once the loop finishes, the minimum number of computations (`totalComputations`) is returned as the result of
the function.

8. In the `main` function, the number of files and their sizes are provided as input.

9. The `findMinimumComputation` function is called with the given inputs, and the result is stored in the variable
`minimumComputations`.

10. The minimum number of computations is printed to the console.

The code efficiently calculates the minimum number of computations required to merge files by utilizing a min heap
data structure. It demonstrates a practical application of priority queues and provides a solution to the file merging problem.

*/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Function to find the minimum computation
int findMinimumComputation(int numberOfFiles, int fileSizes[])
{
    // Create a min heap (priority queue)
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Push all file sizes into the min heap
    for (int i = 0; i < numberOfFiles; i++) {
        minHeap.push(fileSizes[i]);
    }

    // Variable to count the total number of computations
    int totalComputations = 0;

    while (minHeap.size() > 1) {
        // Extract the two smallest sizes from the min heap
        int smallestSize1 = minHeap.top();
        minHeap.pop();
        int smallestSize2 = minHeap.top();
        minHeap.pop();

        // Compute the new combined file size
        //ALAMIN TASK: WRITE ONE LINE OF CODE HERE TO MAKE THE CODE WORK
        //LINE1


        // Add the current computations with the previous ones
        //ALAMIN TASK: WRITE ONE LINE OF CODE HERE TO MAKE THE CODE WORK
        //LINE1


        // Push the new combined file size back into the min heap
        //ALAMIN TASK: WRITE ONE LINE OF CODE HERE TO MAKE THE CODE WORK
        //LINE1

    }

    // Return the minimum number of computations required
    return totalComputations;
}

// Driver code
int main()
{
    // Number of files
    int numberOfFiles = 6;

    // Sizes of the files
    int fileSizes[] = {2, 3, 4, 5, 6, 7};

    // Compute the minimum number of computations
    int minimumComputations = findMinimumComputation(numberOfFiles, fileSizes);

    // Print the result
    cout << "Minimum Computations = " << minimumComputations << endl;

    return 0;
}
