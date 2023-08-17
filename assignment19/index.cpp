/*
The Bellman-Ford algorithm is used to find the shortest paths from a given source vertex to all other vertices in a weighted directed graph. The graph can have both positive and negative edge weights, but it should not contain any negative-weight cycles reachable from the source vertex.

The algorithm works by iteratively relaxing the edges V-1 times, where V is the number of vertices in the graph. In each iteration, it considers all the edges in the graph and updates the distance of the destination vertex if a shorter path is found. By repeating this process V-1 times, the algorithm guarantees that the shortest paths are calculated.

After V-1 iterations, the algorithm performs one additional iteration to check for the presence of negative-weight cycles. If a shorter path is found during this iteration, it implies the existence of a negative-weight cycle in the graph, and the algorithm reports it as an error.

The Bellman-Ford algorithm is a dynamic programming-based approach that optimally solves the single-source shortest path problem in a weighted directed graph.
*/


#include <iostream>
#include <climits>
#include <vector>

// Data structure to represent a weighted edge
struct Edge {
    int source, destination, weight;
};

// Function to compute the shortest paths from source to all other vertices
void bellmanFord(std::vector<Edge>& graph, int V, int source) {
    // Initialize distances to all vertices as infinity except the source
    std::vector<long long> distance(V, INT_MAX);
    distance[source] = 0;

    // Relax all edges V-1 times
    for (int i = 0; i < V - 1; ++i) {
        // Iterate over all edges
        for (const auto& edge : graph) {
            int u = edge.source;
            int v = edge.destination;
            int weight = edge.weight;

            // Relax the edge if a shorter path is found
            if (distance[u] != INT_MAX && distance[u] + weight < distance[v])
                //ALAMIN TASK: WRITE ONE LINE OF CODE HERE TO MAKE THE CODE WORK
                 distance[v] = distance[u] + weight;//LINE 1
        }
    }

    // Check for negative-weight cycles
    for (const auto& edge : graph) {
        int u = edge.source;
        int v = edge.destination;
        int weight = edge.weight;

        // If a shorter path is found, a negative-weight cycle exists
        if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
            std::cout << "Negative-weight cycle detected!\n";
            return;
        }
    }

    // Print the shortest distances
    std::cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < V; ++i) {
        std::cout << i << "\t" << distance[i] << "\n";
    }
}

int main() {
    int V = 5; // Number of vertices
    int E = 6; // Number of edges

    std::vector<Edge> graph(E);

    // Test Case 1
    graph[0] = {0, 1, 5};
    graph[1] = {0, 2, 2};
    graph[2] = {1, 3, 4};
    graph[3] = {2, 1, -3};
    graph[4] = {2, 3, 3};
    graph[5] = {3, 4, 1};

    int source = 0;
    bellmanFord(graph, V, source);

    // Test Case 2
    graph[0] = {0, 1, 2};
    graph[1] = {0, 2, 4};
    graph[2] = {1, 2, 1};
    graph[3] = {1, 3, 5};
    graph[4] = {2, 3, 2};
    graph[5] = {2, 4, 3};
    graph[6] = {3, 4, 1};

    source = 0;
    bellmanFord(graph, V, source);

    // Test Case 3
    graph[0] = {0, 1, 1};
    graph[1] = {1, 2, -1};
    graph[2] = {2, 3, -2};
    graph[3] = {3, 0, -4};

    source = 0;
    bellmanFord(graph, V, source);

    // Test Case 4
    graph[0] = {0, 1, 1};
    graph[1] = {1, 2, 2};
    graph[2] = {2, 3, 3};
    graph[3] = {3, 0, -10};

    source = 0;
    bellmanFord(graph, V, source);

    // Test Case 5
    graph[0] = {0, 1, 1};
    graph[1] = {1, 2, 2};
    graph[2] = {2, 3, 3};
    graph[3] = {3, 0, 10};

    source = 0;
    bellmanFord(graph, V, source);

    return 0;
}

