//
// Created by Marwan on 3/3/2024.
//
#include <iostream>
#include <queue>
#include <map>
#include <sstream>
#include <fstream>
#include <unordered_map>
using namespace std;

#define MAX_SIZE 100 // Maximum Height of Huffman Tree.
string word;
string temp;
unordered_map<char,string> huffmancodes;
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

void printencoded(const string& input, unordered_map<char, string> huffmancodes){
    cout << "Encoded message:"<<endl;
    for (char ch: input){
        cout << huffmancodes[ch]; //  this is used to print the encoded message
        temp = temp + huffmancodes[ch];
    }
    cout << endl;

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
    string temp = "";
    if (!root->left && !root->right) {
        cout << root->data << " ";
        for (int i = 0; i < top; i++) {
            cout << arr[i];
            temp = temp + to_string(arr[i]);
        }
        huffmancodes[root->data]= temp;
        temp = "";

        cout << endl;
    }


}

string decodeHuffman(const string& encodedMessage, HuffmanTreeNode* root){
    string decodedmessage = "";
    HuffmanTreeNode* currentNode = root;
    for(char bit: encodedMessage){
        if(bit =='0'){
            currentNode = currentNode->left; // go to the left child of the tree if bit is 0
        }else {
            currentNode = currentNode->right; // go to the right child of the tree if bit is 1
        }


        if(currentNode->left == nullptr && currentNode->right  == nullptr){ // when leaf nodes reached add the letter to the decoded message
            decodedmessage += currentNode->data;
            currentNode = root;
        }
    }
    return decodedmessage;
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

void HuffmanCodesFile(string path, bool fileorstring)
{

    map<char,int> input; // used to store characters and frequency
    int size = 0;
    if(fileorstring) { // The user chose to enter a file path
        ifstream inputFile(path);
        if (!inputFile) {
            cerr << "Error opening file: " << path << endl;
            return;
        }

        string line;
        while (getline(inputFile, line)) {
            size++;
            char d;
            char comma;
            istringstream iss(line);
            word = line;
            while (iss >> d) { // go through string word by word

                input[d]++; // add character to maps
            }
        }

        inputFile.close();
    } else { // if the user inputted a string
        char d;
        istringstream iss(path);
        word = path;
        while (iss >> d) {

            input[d]++;
        }
    }

    // Declaring priority queue using custom comparator
    priority_queue<HuffmanTreeNode*, vector<HuffmanTreeNode*>, Compare> pq;

    for (auto it = input.begin(); it !=input.end(); ++it) { // iterate over the map to add the elements to a huffmantree
        cout << it->first << "  " << it->second << endl;
        HuffmanTreeNode* newNode = new HuffmanTreeNode(it->first, it->second);
        pq.push(newNode);
    }

    // Generate Huffman Encoding Tree and get the root node
    HuffmanTreeNode* root = generateTree(pq);

    // Print Huffman Codes
    int arr[MAX_SIZE], top = 0;
    printCodes(root, arr, top);
    printencoded(word,huffmancodes); // call function to encode message
    cout << endl << decodeHuffman(temp,root); // call function to decode

}



int main(){
    int input1;
    string input2; // the word user inputed
    bool tof;
    cout << "Do you want to input a string (press 0) or a file path (press 1):";
    cin >> input1;
// gives option to the user to either input a file or a word
    if(input1==1){ // requires a file path
        tof = true;
        cout <<"Input file path:";
        cin >> input2;
    } else {
        tof = false; // a string
        cout <<"Input string:";
        cin >> input2;
    }


    HuffmanCodesFile(input2, tof); // function instance called to encode and decode



    return 0;
}









