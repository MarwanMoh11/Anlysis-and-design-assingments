//
// Created by Marwan on 5/4/2024.
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:

    string encode(vector<string>& strs) {
        string output= "";
        string temp;
        for(auto x : strs){
            output  = output + x + ' ';
        }

        return output;

    }

    vector<string> decode(string s) {
        vector<string> strs;
        string temp="";

        for (char c : s){
        if(c != ' '){
            temp = temp + c;
        }else {
            strs.push_back(temp);
            temp = "";
        }
        }

        return strs;
    }

};


int main() {
    Solution solution;

    // Test case 1
    vector<string> strs1 = {"we", "say", ":", "yes", "!@#$%^&*()"};
    string encoded1 = solution.encode(strs1);
    cout << "Encoded: " << encoded1 << endl;
    vector<string> decoded1 = solution.decode(encoded1);
    cout << "Decoded: ";
    for (const auto& str : decoded1) {
        cout << str << " ";
    }
    cout << endl;

    // Test case 2
    vector<string> strs2 = {"GitHub", "Copilot", "Test"};
    string encoded2 = solution.encode(strs2);
    cout << "Encoded: " << encoded2 << endl;
    vector<string> decoded2 = solution.decode(encoded2);
    cout << "Decoded: ";
    for (const auto& str : decoded2) {
        cout << str << " ";
    }
    cout << endl;

    return 0;
}