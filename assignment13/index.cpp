/*
Summary:
The code implements Huffman coding, a compression algorithm that assigns variable-length codes to characters
based on their frequencies. It builds a Huffman tree using a priority queue (min heap) and generates Huffman
codes for each character. The codes are printed to the console.

The program starts by defining a HuffmanNode struct to represent nodes in the Huffman tree. Each node contains
a character, its frequency, and pointers to its left and right children.

The printHuffmanCodes function recursively traverses the Huffman tree and prints the Huffman codes for each
character. It starts from the root node and appends '0' for the left child and '1' for the right child while traversing.

The HuffmanCoding function builds the Huffman tree. It creates a priority queue (min heap) and inserts each
character with its frequency as a HuffmanNode into the queue. The function then extracts the two nodes with
the minimum frequencies, creates a new internal node with the sum of their frequencies, and sets the extracted
nodes as its children. This process continues until only one node is left in the queue, which becomes the
 root of the Huffman tree.

In the main function, an example input array (characters) and corresponding frequencies (frequencies)
are provided. The HuffmanCoding function is called with this input to generate and print the Huffman
codes for each character.
*/
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

// A Huffman tree node
struct HuffmanNode {
    char data;             // One of the input characters
    unsigned frequency;    // Frequency of the character
    HuffmanNode* left;     // Left child
    HuffmanNode* right;    // Right child

    HuffmanNode(char data, unsigned frequency) {
        left = right = nullptr;
        this->data = data;
        this->frequency = frequency;
    }
};

// Comparison function for the priority queue
struct Compare {
    bool operator()(HuffmanNode* lhs, HuffmanNode* rhs) {
        return lhs->frequency > rhs->frequency;
    }
};

// Prints Huffman codes from the root of the Huffman Tree
void printHuffmanCodes(HuffmanNode* root, string code) {
    if (root == nullptr)
        return;

    if (root->data != '$')
        cout << root->data << ": " << code << endl;

    printHuffmanCodes(root->left, code + "0");
    printHuffmanCodes(root->right, code + "1");
}

// Builds Huffman Tree and prints Huffman codes
void HuffmanCoding(char characters[], int frequencies[], int size) {
    // Create a min heap and insert all characters with frequencies
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> minHeap;

    for (int i = 0; i < size; ++i)
        minHeap.push(new HuffmanNode(characters[i], frequencies[i]));

    // Iterate until there is only one node left in the min heap
    while (minHeap.size() != 1) {
        // Extract the two minimum frequency nodes from the min heap
        HuffmanNode* left = minHeap.top();
        minHeap.pop();

        HuffmanNode* right = minHeap.top();
        minHeap.pop();

        // Create a new internal node with the sum of frequencies
        // and set the extracted nodes as its children
        HuffmanNode* newNode = new HuffmanNode('$', left->frequency + right->frequency);

        //ALAMIN TASK: WRITE TWO LINES OF CODE TO MAKE THE CODE WORK
        newNode-> left = left ; //LINE
        newNode-> right = right; //LINE

        // Add the new node back to the min heap
        //ALAMIN TASK: WRITE ONE LINE OF CODE TO MAKE THE CODE WORK
        minHeap.push(newNode); //LINE
    }

    // Print Huffman codes using the Huffman tree built above
    printHuffmanCodes(minHeap.top(), "");
}

int main() {
    char characters[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int frequencies[] = { 5, 9, 12, 13, 16, 45 };

    int size = sizeof(characters) / sizeof(characters[0]);

    HuffmanCoding(characters, frequencies, size);

    return 0;
}
