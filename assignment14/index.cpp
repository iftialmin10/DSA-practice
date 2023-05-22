/*

The code implements Prim's algorithm for finding the minimum spanning tree (MST) of a graph represented
using an adjacency matrix. It starts by defining the number of vertices in the graph. The `minKey`
function finds the vertex with the minimum key value from the set of vertices not yet included in the
MST. The `printMST` function prints the constructed MST. The `primMST` function performs the main
Prim's algorithm logic. It initializes arrays for storing the MST, key values, and MST set. It then
iteratively selects the vertex with the minimum key value, adds it to the MST set, and updates the
key values and parent indices of its adjacent vertices. Finally, the constructed MST is printed. The
main function initializes the graph using an adjacency matrix and calls the `primMST` function to
find and print the MST.

*/

#include <bits/stdc++.h>
using namespace std;

#define V 5 // Number of vertices in the graph

int minKey(int key[], bool mstSet[])
{
    int min = INT_MAX, min_index; // Initialize min value with maximum integer value

    // Find the vertex with the minimum key value from the set of vertices not yet included in MST
    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index; // Return the index of the vertex with the minimum key value
}

void printMST(int parent[], int graph[V][V])
{
    cout << "Edge \tWeight\n";

    // Print the constructed MST stored in parent[]
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
}

void primMST(int graph[V][V])
{
    int parent[V]; // Array to store constructed MST
    int key[V]; // Key values used to pick minimum weight edge in cut
    bool mstSet[V]; // To represent set of vertices included in MST

    // Initialize all keys as INFINITE and MST set as false
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0; // Always include the first vertex in MST
    parent[0] = -1; // First node is always the root of MST

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet); // Pick the minimum key vertex from the set of vertices not yet included in MST
        mstSet[u] = true; // Add the picked vertex to the MST set

        // Update key values and parent indices of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]){
                //ALAMIN TASK: WRITE TWO LINES OF CODE TO MAKE THE CODE WORK
                //LINE
                //LINE
            }
    }

    // Print the constructed MST
    printMST(parent, graph);
}

int main()
{
    int graph[V][V] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };

    primMST(graph); // Find and print the MST

    return 0;
}

