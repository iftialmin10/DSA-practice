/*
The given code implements Kruskal's algorithm to find the Minimum Spanning Tree (MST) of a graph. 
It utilizes a Disjoint Set Union (DSU) data structure with path compression and rank by union 
techniques. The code sorts the edges of the graph based on their weights and then iterates 
through the sorted edges, adding them to the MST if they do not form a cycle. Finally, the code 
outputs the edges in the constructed MST along with their weights and the total weight of the MST.
*/

#include <bits/stdc++.h>
using namespace std;

// Disjoint Set Union (DSU) data structure
// with path compression and rank by union

class DisjointSetUnion {
    int* parent;  // Array to store the parent of each element
    int* rank;    // Array to store the rank of each set

public:
    // Constructor to initialize the data structure
    DisjointSetUnion(int n) {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = -1;   // Initialize each element as a parent
            rank[i] = 1;      // Initialize the rank of each set as 1
        }
    }

    // Find the parent of the set to which element 'i' belongs
    int find(int i) {
        if (parent[i] == -1)
            return i;

        // Path compression - make the parent of i as the root
        return parent[i] = find(parent[i]);
    }

    // Union of two sets based on rank
    void unite(int x, int y) {
        int set1 = find(x);
        int set2 = find(y);

        if (set1 != set2) {
            // Rank by union - attach the smaller rank tree to the larger rank tree
            if (rank[set1] < rank[set2]) {
                parent[set1] = set2;
            }
            else if (rank[set1] > rank[set2]) {
                parent[set2] = set1;
            }
            else {
                parent[set2] = set1;
                rank[set1] += 1;
            }
        }
    }
};

class Graph {
    vector<vector<int>> edgeList;  // Vector to store the edges of the graph
    int numVertices;                // Number of vertices in the graph

public:
    Graph(int V) {
        numVertices = V;
    }

    // Function to add an edge to the graph
    void addEdge(int vertex1, int vertex2, int weight) {
        edgeList.push_back({ weight, vertex1, vertex2 });
    }

    // Function to find the Minimum Spanning Tree using Kruskal's algorithm
    void findMinimumSpanningTree() {
        // Sort the edges in non-decreasing order based on their weights
        sort(edgeList.begin(), edgeList.end());

        // Initialize the Disjoint Set Union data structure
        DisjointSetUnion dsu(numVertices);
        int totalWeight = 0;

        cout << "Following are the edges in the constructed MST" << endl;

        // Iterate through all the edges
        for (auto edge : edgeList) {
            int weight = edge[0];
            int vertex1 = edge[1];
            int vertex2 = edge[2];

            // Check if adding the edge creates a cycle in the MST
            if (dsu.find(vertex1) != dsu.find(vertex2)) {
                /*
                The unite() function in the Disjoint Set Union (DSU) data structure is responsible for merging two sets (or trees)
                together. In this case, vertex1 and vertex2 represent the two vertices connected by the current edge.
                we need to merge the sets to which vertex1 and vertex2 belong. This operation
                ensures that the two vertices are now connected in the MST. It updates the parent pointers and the rank of the
                sets accordingly.
                After uniting the sets, the weight of the current edge is added to the totalWeight variable. This variable keeps
                track of the cumulative weight of all the edges in the MST. By adding the weight of the current edge, we update
                the totalWeight to reflect the weight of the MST constructed so far.
                These two lines play a crucial role in building the MST by connecting vertices and accumulating the total weight
                of the MST.
                */

                //ALAMIN TASK:  WRITE TWO LINES OF CODE TO MAKE THE CODE WORK
                dsu.unite(vertex1 , vertex2);//LINE
                totalWeight = totalWeight + weight; //LINE


                cout << vertex1 << " -- " << vertex2 << " == " << weight << endl;
            }
        }

        cout << "Minimum Cost Spanning Tree: " << totalWeight << endl;
    }
};

int main() {
    Graph graph(4);
    graph.addEdge(0, 1, 10);
    graph.addEdge(1, 3, 15);
    graph.addEdge(2, 3, 4);
    graph.addEdge(2, 0, 6);
    graph.addEdge(0, 3, 5);

    // Find the Minimum Spanning Tree
    graph.findMinimumSpanningTree();

    return 0;
}
