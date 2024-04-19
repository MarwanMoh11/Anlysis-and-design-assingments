#include <iostream>
#include <vector>
using namespace std;




// Function to check if the move (x, y) is valid on the board of size N
// utilituy function to be used by the solveKnightTour function
bool isSafe(int x, int y, vector<vector<int>>& sol)
{
    int N = sol.size();
    // Check if (x, y) is valid chess board coordinates
    bool iswithin = (x >= 0 && x < N && y >= 0 && y < N);
    // Check if the current cell is not already visited
    bool notvisited = iswithin ? (sol[x][y] == -1) : false;
    return iswithin && notvisited;
}

// Function to solve Knight's Tour problem using backtracking
bool solveKnightTour(int N,int x, int y, int move_i, vector<vector<int>>& sol, int xMove[], int yMove[]) {
    if (move_i == N * N) // All squares have been visited
        return true;
    for (int i = 0; i < 8; i++) {
        int next_x = x + xMove[i];
        int next_y = y + yMove[i];
        if (isSafe(next_x, next_y, sol)) {
            sol[next_x][next_y] = move_i;
            if (solveKnightTour(N, next_x, next_y, move_i + 1, sol, xMove, yMove))
                return true;
            else
                sol[next_x][next_y] = -1; // backtracking
        }
    }
    return false; // No valid moves found
}


// Main function
int main() {
    // Size of the chessboard
    int N = 8;
    vector<vector<int>> sol(N, vector<int>(N, -1)); // Initialize the solution matrix
    int xMove[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int yMove[] = {1, 2, 2, 1, -1, -2, -2, -1};

    // Start from position (0,0) and mark it as the first move
    // note: you may start from any position on the board
    sol[0][0] = 0;

    // Start the recursive backtracking
    if (!solveKnightTour(N, 0, 0, 1, sol, xMove, yMove)) {
        cout << "Solution does not exist";
        return 0;
    }

    // Print the solution
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << sol[i][j] << "\t";
        cout << endl;
    }
    return 0;
}
