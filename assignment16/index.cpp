/*
Given a weighted graph, the problem is to find the shortest distances from a source node to all other nodes in the graph.

Dijkstra's algorithm is a popular algorithm used to solve the single-source shortest path problem in a graph with non-negative
edge weights. It starts from a source node and iteratively expands the frontier by choosing the node with the minimum distance.
It gradually explores all nodes and updates the shortest distances until it reaches all the nodes in the graph.

The algorithm maintains a priority queue of nodes, sorted based on their current distance from the source node. It begins by
initializing the distance of the source node to 0 and all other nodes to infinity. Then, it repeatedly selects the node with
the minimum distance from the priority queue, updates the distances of its neighbors if a shorter path is found, and adds them
to the queue. This process continues until the priority queue becomes empty.

By the end of the algorithm, the shortest distances from the source node to all other nodes in the graph will be determined.

In summary, Dijkstra's algorithm starts from a source node and progressively explores the graph by choosing the node with the
minimum distance. It efficiently updates the shortest distances until it reaches all nodes, providing the shortest path from
the source node to every other node in the graph with non-negative edge weights.
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Structure to represent a node in the graph
struct Node {
    int id;
    int distance;

    Node(int _id, int _distance) : id(_id), distance(_distance) {}

    // Overloading comparison operator for priority queue
    bool operator<(const Node& other) const {
        return distance > other.distance;
    }
};

// Dijkstra's algorithm implementation
vector<int> dijkstra(vector<vector<pair<int, int>>>& graph, int start) {
    int n = graph.size();

    // Initializing the distances with infinity
    vector<int> distance(n, INT_MAX);

    // Priority queue to store nodes based on their distance
    priority_queue<Node> pq;

    // Set the distance of the start node to 0 and push it to the priority queue
    distance[start] = 0;
    pq.push(Node(start, 0));

    while (!pq.empty()) {
        // Get the node with the minimum distance from the priority queue
        Node curr = pq.top();
        pq.pop();

        int currNode = curr.id;
        int currDistance = curr.distance;

        // If the current distance is greater than the stored distance, ignore it
        if (currDistance > distance[currNode])
            continue;

        // Iterate through the neighbors of the current node
        for (auto& neighbor : graph[currNode]) {
            int neighborNode = neighbor.first;
            int neighborDistance = neighbor.second;

            // Calculate the new distance to the neighbor node
            int newDistance = currDistance + neighborDistance;

            // If the new distance is smaller, update the distance and push the neighbor to the priority queue
            if (newDistance < distance[neighborNode]) {
                //ALAMIN TASK: WRITE TWO LINES OF CODE HERE TO MAKE THE CODE WORK
                //LINE ONE
                //LINE TWO
            }
        }
    }

    return distance;
}

int main() {
    // Problem statement: Given a weighted graph, find the shortest distances from a source node to all other nodes.

    // Example graph: A simple directed graph with 4 nodes and 5 edges
    // Node 0 is connected to Node 1 with weight 2
    // Node 0 is connected to Node 2 with weight 5
    // Node 1 is connected to Node 2 with weight 1
    // Node 1 is connected to Node 3 with weight 6
    // Node 2 is connected to Node 3 with weight 3
    vector<vector<pair<int, int>>> graph = {
        {{1, 2}, {2, 5}},     // Node 0
        {{2, 1}, {3, 6}},     // Node 1
        {{3, 3}},             // Node 2
        {}                    // Node 3
    };

    // Test Case 1: Source node = 0
    vector<int> distances = dijkstra(graph, 0);
    cout << "Shortest distances from Node 0 to all other nodes:" << endl;
    for (int i = 0; i < distances.size(); ++i) {
        cout << "Node " << i << ": " << distances[i] << endl;
    }
    cout << endl;

    // Test Case 2: Source node = 1
    distances = dijkstra(graph, 1);
    cout << "Shortest distances from Node 1 to all other nodes:";
    for (int i = 0; i < distances.size(); ++i) {
        cout << "Node " << i << ": " << distances[i] << endl;
    }
    cout << endl;

    // Test Case 3: Source node = 2
    distances = dijkstra(graph, 2);
    cout << "Shortest distances from Node 2 to all other nodes:" << endl;
    for (int i = 0; i < distances.size(); ++i) {
        cout << "Node " << i << ": " << distances[i] << endl;
    }
    cout << endl;

    // Test Case 4: Source node = 3
    distances = dijkstra(graph, 3);
    cout << "Shortest distances from Node 3 to all other nodes:" << endl;
    for (int i = 0; i < distances.size(); ++i) {
        cout << "Node " << i << ": " << distances[i] << endl;
    }
    cout << endl;

    // Test Case 5: Source node = 4 (Invalid node)
    distances = dijkstra(graph, 4);
    cout << "Shortest distances from Node 4 to all other nodes:" << endl;
    for (int i = 0; i < distances.size(); ++i) {
        cout << "Node " << i << ": " << distances[i] << endl;
    }
    cout << endl;

    return 0;
}
