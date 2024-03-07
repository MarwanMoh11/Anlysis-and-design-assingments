//
// Created by Marwan on 3/3/2024.
//
#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <string>
#include <queue>
using namespace std;

void writeVectorToFile(const vector<int>& vec, const string& filename) {
    ofstream outputFile(filename);
    if (!outputFile) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    for (int num : vec) {
        outputFile << num << endl;
    }
    // output path and filename
    cout << "Output stored in the path D:\\C++\\Assignment1" << " file name: " << filename << ".txt" << endl;



    outputFile.close();
}

vector<int> mergeSortedVectors(const vector<vector<int>>& sortedVectors) {
    // Create a priority queue to store iterators of each vector along with their current values
    auto cmp = [](const auto& a, const auto& b) { return *a.first > *b.first; }; // custom comparator used to compare pairs
    priority_queue<pair<vector<int>::const_iterator, vector<int>::const_iterator>, vector<pair<vector<int>::const_iterator, vector<int>::const_iterator>>, decltype(cmp)> pq(cmp); // a priority queue is created of type pair of vector iterators as the elements stored and the container is a vector of pair of vector iterators and the third parameter is the comparison being made using decltype because the type is too complex to use a normal declaration

    // Initialize the priority queue with iterators to the first element of each vector
    for (const auto& vec : sortedVectors) {
        if (!vec.empty()) {
            pq.push({vec.begin(), vec.end()});
        }
    }

    // Merge the vectors
    vector<int> mergedResult;
    while (!pq.empty()) {
        auto [it, end] = pq.top();
        pq.pop();
        mergedResult.push_back(*it);
        if (next(it) != end) {
            pq.push({next(it), end});
        }
    }

    return mergedResult;
}

void optimerge(string path){
    vector<vector<int>> output;
    for (const auto& entry : std::filesystem::directory_iterator(path)) { //iterate through the files stored in the folder
        if(entry.is_regular_file()){
            ifstream inputFile(entry.path());
            if(!inputFile){
                cerr << "Error opening file: " << entry.path() << endl;
                continue; // Skip to the next file
            }
            cout << "Reading from file Name: "<< entry.path().filename() <<" Path: " << entry.path() << endl;
            string line;
            vector<int> minioutput;
            while (getline(inputFile, line)) {
                if(!line.empty()){
                    int num = stoi(line);
                    minioutput.push_back(num); // this is for each file read
                }

            }
            output.push_back(minioutput); // for the bigger vector of vectors
            inputFile.close();
        }

    }

    vector<int> sorted = mergeSortedVectors(output); // apply the mergesorted function to the output and this is stored in a sorted vector


    writeVectorToFile(sorted,"output"); // this function is used to write the output on a file very simple


            }


int main(){
    optimerge("D:\\numbers");
    return 0;

}