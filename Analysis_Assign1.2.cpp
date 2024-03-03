//
// Created by Marwan on 3/3/2024.
//
#include <iostream>
#include <queue>
#include <sstream>
#include <fstream>
using namespace std;

#define MAX_SIZE 100 // Maximum Height of Huffman Tree.
class HuffmanTreeNode {
public:

    char data; // Stores character
    int freq; // Stores frequency of the character
    HuffmanTreeNode* left; // Left child of the current node
    HuffmanTreeNode* right; // Right child of the current node

    HuffmanTreeNode(char character, int frequency) // Initializing the current node
    {
        data = character;
        freq = frequency;
        left = right = NULL;
    }
};

// Custom comparator class
class Compare {
public:
    bool operator()(HuffmanTreeNode* a, HuffmanTreeNode* b)
    {   // Defining priority on the basis of frequency
        return a->freq > b->freq;
    }
};

// Function to generate Huffman Encoding Tree
HuffmanTreeNode* generateTree(priority_queue<HuffmanTreeNode*, vector<HuffmanTreeNode*>, Compare> pq)
{
    // We keep on looping till only one node remains in the Priority Queue
    while (pq.size() != 1) {


        // Remove nodes ni, nj with lowest frequencies pi, pj from the Priority Queue
        HuffmanTreeNode* ni = pq.top();
        pq.pop();
        HuffmanTreeNode* nj = pq.top();
        pq.pop();

        // Create a new symbol (could be a anything, it won't be used)
        // with the new frequency = pi+pj (we are only concerned with the frequency)
        char newSymbol = '$'; // Placeholder symbol
        int newFrequency = ni->freq + nj->freq;

        // A new node is formed with the new symbol and frequency
        HuffmanTreeNode* newNode = new HuffmanTreeNode(newSymbol, newFrequency);

        // set the left and right children of the newely formed node to be ni and nj
        newNode->left = ni;
        newNode->right = nj;

        // Push back node created to the Priority Queue
        pq.push(newNode);
    }
    // The Priority Queue should have one element: the entire Tree
    return pq.top();
}

// Function to print the huffman code for each character.
// It uses arr to store the codes
void printCodes(HuffmanTreeNode* root, int arr[], int top)
{
    // Assign 0 to the left node and recur
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    // Assign 1 to the right node and recur
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    // If this is a leaf node, then we print root->data
    // We also print the code for this character from arr
    if (!root->left && !root->right) {
        cout << root->data << " ";
        for (int i = 0; i < top; i++) {
            cout << arr[i];
        }
        cout << endl;
    }
}

void HuffmanCodes(char data[], int freq[], int size)
{
    // Declaring priority queue using custom comparator
    priority_queue<HuffmanTreeNode*, vector<HuffmanTreeNode*>, Compare> pq;

    // Populating the priority queue
    for (int i = 0; i < size; i++) {
        HuffmanTreeNode* newNode = new HuffmanTreeNode(data[i], freq[i]);
        pq.push(newNode);
    }

    // Generate Huffman Encoding Tree and get the root node
    HuffmanTreeNode* root = generateTree(pq);

    // Print Huffman Codes
    int arr[MAX_SIZE], top = 0;
    printCodes(root, arr, top);
}

void HuffmanCodestxt(string path)
{
    vector<char> data;
    vector<int> freq;
    int size = 0;

    ifstream inputFile(path);
    if (!inputFile) {
        cerr << "Error opening file: " << path << endl;
        return;
    }

    string line;
    while (getline(inputFile, line)) {
        size++;
        char d;
        int f;
        char comma;
        istringstream iss(line);
        if (iss >> d >> f) {
            data.push_back(d);
            freq.push_back(f);
        } else {
            cerr << "Error parsing line: " << line << endl;
        }
    }

    inputFile.close();

    // Declaring priority queue using custom comparator
    priority_queue<HuffmanTreeNode*, vector<HuffmanTreeNode*>, Compare> pq;

    for (int i = 0; i < size; i++) {
        HuffmanTreeNode* newNode = new HuffmanTreeNode(data[i], freq[i]);
        pq.push(newNode);
    }

    // Generate Huffman Encoding Tree and get the root node
    HuffmanTreeNode* root = generateTree(pq);

    // Print Huffman Codes
    int arr[MAX_SIZE], top = 0;
    printCodes(root, arr, top);
}











