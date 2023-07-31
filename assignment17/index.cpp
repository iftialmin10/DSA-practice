/*
In this implementation, the floydWarshall function takes a graph represented by an adjacency matrix
and the number of vertices V. It initializes the distance matrix dist with the input graph and
performs the Floyd-Warshall algorithm to find the shortest distances between all pairs of vertices.
Finally, it prints the shortest distances.

The algorithm iteratively considers all vertices as intermediate vertices and checks if using the
current intermediate vertex leads to a shorter path between two vertices. If it does, the shortest
distance is updated. The algorithm guarantees that after V iterations, the shortest distances are
calculated.

Please note that this implementation assumes that the graph is represented by an adjacency matrix,
where INF represents infinity or an unreachable edge. You can modify the code as per your input
format if needed.
*/

#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9; // Represents infinity

// Function to perform the Floyd-Warshall algorithm
void floydWarshall(vector<vector<int>>& graph, int V) {
    vector<vector<int>> dist(V, vector<int>(V)); // Stores the shortest distances

    // Initialize the distance matrix with the input graph
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Evaluate all pairs of vertices
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                // If vertex k is on the shortest path from i to j,
                // then update the value of dist[i][j]
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    //ALAMIN TASK: WRITE ONE LINE OF CODE HERE TO MAKE THE CODE WORK
                    dist[i][j] = dist[i][k] + dist[k][j];//LINE 1
                }
            }
        }
    }

    // Print the shortest distances
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    // Test Case 1
    int V1 = 4;
    vector<vector<int>> graph1 = {
        {0, 5, INF, 10},
        {INF, 0, 3, INF},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}
    };
    cout << "Test Case 1:" << endl;
    floydWarshall(graph1, V1);
    cout << endl;

    // Test Case 2
    int V2 = 3;
    vector<vector<int>> graph2 = {
        {0, 2, INF},
        {INF, 0, 7},
        {1, INF, 0}
    };
    cout << "Test Case 2:" << endl;
    floydWarshall(graph2, V2);
    cout << endl;

    // Test Case 3
    int V3 = 5;
    vector<vector<int>> graph3 = {
        {0, INF, -2, INF, INF},
        {4, 0, 3, INF, 9},
        {INF, INF, 0, 2, INF},
        {INF, -5, INF, 0, INF},
        {INF, INF, INF, 1, 0}
    };
    cout << "Test Case 3:" << endl;
    floydWarshall(graph3, V3);
    cout << endl;

    // Test Case 4
    int V4 = 3;
    vector<vector<int>> graph4 = {
        {0, 1, 5},
        {INF, 0, INF},
        {INF, INF, 0}
    };
    cout << "Test Case 4:" << endl;
    floydWarshall(graph4, V4);
    cout << endl;

    // Test Case 5
    int V5 = 4;
    vector<vector<int>> graph5 = {
        {0, INF, INF, 10},
        {INF, 0, INF, INF},
        {INF, 3, 0, INF},
        {INF, INF, -2, 0}
    };
    cout << "Test Case 5:" << endl;
    floydWarshall(graph5, V5);
    cout << endl;

    return 0;
}
