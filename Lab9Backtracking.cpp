//
// Created by Marwan on 4/2/2024.
//
#include <iostream>
#include <vector>
using namespace std;

void CodeCracker(int n, string &code, int range, int& counter,vector<bool>& used){
    if(n == 0){ // Base case
        cout << code << endl;
        counter++;
        return;
    }
    for(int i = 1; i <= range; i++){ // Recursive case
        if(used[i]) continue;
            code.push_back(i + '0'); // to make sure string is in ascii
            used[i] = true; // Mark this number as used
            CodeCracker(n-1, code, range,counter,used);// Recursive call
            used[i] = false;// Unmark this number as used
            code.pop_back();// Remove the last character for backtracking

    }

}

void CodeCrackerCaller(int n, int range, int& counter){ // Wrapper function
    string code = "";
    vector<bool> used(10, false); // Vector to keep track of which numbers have been used
    CodeCracker(n, code, range,counter,used); // Call the CodeCracker function


}

void ID(vector<int> IDs, int x, int teamsize, vector<int> result, int junior, int senior, vector<bool>& used, int& counter, int start) {
    if (teamsize == 3 && senior > 0) { // Base case if all the conditions are met we print on the terminal
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
        cout << endl;
        counter++; // keep track of the team combinations
        return;
    }

    for (int i = start; i < IDs.size(); i++) {
        if (used[i]) continue; // Skip if this ID has already been used
        result.push_back(IDs[i]);
        used[i] = true; // Mark this ID as used
        if (IDs[i] > x) { // Check if this ID is a senior or junior by checking how early it was made
            junior++;
        } else {
            senior++;
        }
        ID(IDs, x, teamsize + 1, result, junior, senior, used, counter, i + 1);
        used[i] = false; // Unmark this ID as used
        result.pop_back(); // Remove the last ID for backtracking
        if (IDs[i] > x) { // Update the junior and senior counts after the popback
            junior--;
        } else {
            senior--;
        }
    }
}


int main() {
    // List of employee IDs
    vector<int> IDs = {10, 15, 20, 25, 30};
    // Threshold for seniority
    int X = 25;
    // Vector to hold the current team
    vector<int> result;
    // Vector to keep track of which IDs have been used
    vector<bool> used(IDs.size(), false);

    int counter1 = 0; // Counter to keep track of the number of teams

    // Call the ID function to generate the teams
    ID(IDs, X, 0, result, 0, 0, used,counter1,0);
    // the zero values are sent as parameters to the function to keep track of the team size and the senior and junior members

    cout << "Total number of teams: " << counter1 << endl << endl;

    int counter2 = 0; // Counter to keep track of the number of codes
    CodeCrackerCaller(4, 6, counter2);
    cout << "Total number of codes: " << counter2 << endl;


    return 0;
}