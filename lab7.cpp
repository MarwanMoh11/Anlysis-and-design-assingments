#include <iostream>
#include <vector>
#include <climits>
using namespace std;


// The function is calculating the optimal way to split a sequence of matrices for multiplication.
// It takes vector of integers as input where the first and second element makes up one matrix dimensions
//  we keep shifting it by one. each cell (i,j) represents the minimum cost of multiplying matrices from i to j in the sequence. The function returns this 2D table.
vector<vector<int>> get_optimal_split(const vector<int>& matrix_dims) {
    int n = matrix_dims.size() - 1; // Number of matrices
    vector<vector<int>> DP(n, vector<int>(n, 0)); // Dynamic programming table for memoization
    vector<vector<int>> optimalsplit(n, vector<int>(n, 0)); // Table to store the optimal split

    for (int j = 2; j <= n; j++) {
        for (int i = 0; i < n - j + 1; i++) {
            int j = i + j - 1; // end index of subsequence
            DP[i][j] = INT_MAX; // Initialize to maximum value

            for (int k = i; k < j; k++) {
                int cost = DP[i][k] + DP[k + 1][j] + matrix_dims[i] * matrix_dims[k + 1] * matrix_dims[j + 1]; // cost of multiplying matrices from i to k and k + 1 to j
                if (cost < DP[i][j]) { // Update DP table and optimal split if cost is less than current minimum
                    DP[i][j] = cost;
                    optimalsplit[i][j] = k;
                }
            }
        }
    }
    return optimalsplit;
}

// The function prints out the optimal way to parenthesis the matrices to be multiplied
void print_parenthesis(const vector<vector<int>>& split, int i, int j) {
    if (i == j) {
        cout << "A" << i + 1; // Base case if we only have one matrix
    } else {
        cout << "(";
        print_parenthesis(split, i, split[i][j]); // Recursion on the left side
        print_parenthesis(split, split[i][j] + 1, j); // Recursion on the right side
        cout << ")";
    }
}

// This function is used as nothing but an interface to call the get_optimal_split and print_parenthesis functions.
void print_optimal(const vector<int>& dims) {
    vector<vector<int>> split = get_optimal_split(dims);
    int n = dims.size() - 1;

    cout << "Optimal Parenthesization: ";
    print_parenthesis(split, 0, n - 1);
    cout << endl;
}


int main(){
    vector<int> dims = {3, 2, 4, 2, 5}; // Test case discussed in slides
    // Output should be ((A1A2)A3)
    cout << "Test case: ";
    for (int dim : dims) {
        cout << dim << " ";
    }
    cout << endl;

    print_optimal(dims);

    vector<int> dims2 = {4, 4, 6, 12, 7}; // Additional test case
    // Output should be (A1(A2(A3A4)))
    cout << "Additional test case: ";
    for (int dim : dims2) {
        cout << dim << " ";
    }
    cout << endl;

    print_optimal(dims2);
    return 0;
}