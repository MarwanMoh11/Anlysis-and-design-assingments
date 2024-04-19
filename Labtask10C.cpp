//
// Created by Marwan on 4/19/2024.
//

#include <iostream>
#define N 5
using namespace std;

bool R_solve_maze(int maze[N][N], int x, int y, int sol[N][N]) {
    // If (x, y) is the destination, return true
    if(x == N-1 && y == N-1) {
        sol[x][y] = 1;
        return true;
    }

    // Check if maze[x][y] is valid
    if(x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1) {
        // Mark x, y
        sol[x][y] = 1;

        // Move right
        if (R_solve_maze(maze, x+1, y, sol))
            return true;

        // Move down
        if (R_solve_maze(maze, x, y+1, sol))
            return true;

        // If none of the above movements work, then BACKTRACK: unmark x, y
        sol[x][y] = 0;
        return false;
    }

    return false;
}

void printSolution(int sol[N][N]) {
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++)
            cout << sol[x][y] << " ";
        cout << endl;
    }
}

int main() {
    int maze[N][N] = {
            {1, 0, 0, 0, 0},
            {1, 1, 0, 1, 0},
            {0, 1, 1, 1, 0},
            {0, 0, 0, 1, 0},
            {1, 1, 1, 1, 1}
    };

    int sol[N][N] = {{0}};

    if(!R_solve_maze(maze, 0, 0, sol))
        cout << "No solution exists";
    else
        printSolution(sol);

    return 0;
}