//
// Created by Marwan on 3/22/2024
//


#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<vector<int>> get_optimal_split(const vector<int>& dims) {
    int n = dims.size() - 1; // Number of matrices
    vector<vector<int>> dp(n, vector<int>(n, 0)); // Dynamic programming table for memoization
    vector<vector<int>> split(n, vector<int>(n, 0)); // Table to store the optimal split

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX; // Initialize to maximum value

            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + dims[i] * dims[k + 1] * dims[j + 1];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                    split[i][j] = k;
                }
            }
        }
    }
    return split;
}

void print_parenthesis(const vector<vector<int>>& split, int i, int j) {
    if (i == j) {
        cout << "A" << i + 1;
    } else {
        cout << "(";
        print_parenthesis(split, i, split[i][j]);
        print_parenthesis(split, split[i][j] + 1, j);
        cout << ")";
    }
}

void print_optimal(const vector<int>& dims) {
    vector<vector<int>> split = get_optimal_split(dims);
    int n = dims.size() - 1;

    cout << "Optimal Parenthesization: ";
    print_parenthesis(split, 0, n - 1);
    cout << endl;
}






int main(){
    vector<int> dims = {3, 2, 4, 2, 5}; // Test case mentioned
    cout << "Test case: ";
    for (int dim : dims) {
        cout << dim << " ";
    }
    cout << endl;

    print_optimal(dims);

    vector<int> dims2 = {4, 4, 6, 12, 7}; // Additional test case
    cout << "Additional test case: ";
    for (int dim : dims2) {
        cout << dim << " ";
    }
    cout << endl;

    print_optimal(dims2);
    return 0;
}