//
// Created by Marwan on 4/2/2024.
//
#include <iostream>
#include <vector>
using namespace std;

void CodeCracker(int n, string &code, int range, int& counter,vector<bool>& used){
    if(n == 0){
        cout << code << endl;
        counter++;
        return;
    }
    for(int i = 1; i <= range; i++){
        if(used[i]) continue;
            code.push_back(i + '0');
            used[i] = true;
            CodeCracker(n-1, code, range,counter,used);
            used[i] = false;
            code.pop_back();

    }

}

void CodeCrackerCaller(int n, int range, int& counter){
    string code = "";
    vector<bool> used(10, false);
    CodeCracker(n, code, range,counter,used);


}

void ID(vector<int> IDs, int x, int teamsize, vector<int> result, int junior, int senior, vector<bool>& used, int& counter, int start) {
    if (teamsize == 3 && senior > 0) {
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
        cout << endl;
        counter++;
        return;
    }

    for (int i = start; i < IDs.size(); i++) {
        if (used[i]) continue; // Skip if this ID has already been used
        result.push_back(IDs[i]);
        used[i] = true; // Mark this ID as used
        if (IDs[i] > x) {
            junior++;
        } else {
            senior++;
        }
        ID(IDs, x, teamsize + 1, result, junior, senior, used, counter, i + 1);
        used[i] = false; // Unmark this ID as used
        result.pop_back();
        if (IDs[i] > x) {
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
    // Team size
    int teamSize = 0;
    // Junior and senior counts
    int junior = 0, senior = 0;
    // Vector to hold the current team
    vector<int> result;
    // Vector to keep track of which IDs have been used
    vector<bool> used(IDs.size(), false);

    int counter1 = 0;

    // Call the ID function to generate the teams
    ID(IDs, X, teamSize, result, junior, senior, used,counter1,0);

    cout << "Total number of teams: " << counter1 << endl << endl;

    int counter2 = 0;
    CodeCrackerCaller(4, 6, counter2);
    cout << "Total number of codes: " << counter2 << endl;


    return 0;
}