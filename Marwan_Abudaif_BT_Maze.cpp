//
// Created by Marwan on 5/8/2024.
//

// C++ program to find a path from corner cell to
// middle cell in maze containing positive numbers
#include <bits/stdc++.h>
using namespace std;

// Rows and columns in given maze
#define N 9 // 9x9 maze global variable

// check whether given cell is a valid cell or not.
// we pass set of visited cells and the current point we are checking to check the validity of wether we can move to that cell or not
// by seeing if it is in the range of the maze and if it is not visited before
bool isValid(set<pair<int, int> > visited,
             pair<int, int> pt)
{
    // check if cell is not visited yet to
    // avoid cycles (infinite loop) and its
    // row and column number is in range
    return (pt.first >= 0) && (pt.first < N) && // check if the row is in the range of the maze
           (pt.second >= 0) && (pt.second < N) && // check if the column is in the range of the maze
           (visited.find(pt) == visited.end()); // check if the cell is not visited before
}

// Function to print path from source to middle coordinate
void printPath(list<pair<int, int> > path)
{
    // iterate through the path by simply looping over the list with a pointer and printing the coordinates
    for (auto it = path.begin(); it != path.end(); it++)
        cout << "(" << it->first << ", "
             << it->second << ") -> ";

    cout << "MID" << endl << endl; // print the middle cell as MID to indicate that we have reached the middle cell
}

// For searching in all 4 direction
int row[] = {-1, 1, 0, 0};// each index stores the directions so in the row we can move up or down a row
int col[] = { 0, 0, -1, 1};// each index stores the directions so in the column we can move left or right a column

// Coordinates of 4 corners of matrix
int _row[] = { 0, 0, N-1, N-1};// the 4 corners of the maze row coordinates
int _col[] = { 0, N-1, 0, N-1};// the 4 corners of the maze column coordinates

void findPathInMazeUtil(int maze[N][N],
                        list<pair<int, int> > &path, // the path list that stores the path from the corner to the middle cell
                        set<pair<int, int> > &visited, // the visited set is used to keep track of what is visited to avoid cycles
                        pair<int, int> &curr) // the current cell we are using to find the path
{
    // If we have reached the destination cell.
    // print the complete path
    // base case of the recursion when we reach the middle cell
    if (curr.first == N / 2 && curr.second == N / 2)
    {
        printPath(path);
        return;
    }

    // consider each direction
    for (int i = 0; i < 4; ++i) // loop over the 4 directions
    {
        // get value of current cell
        int n = maze[curr.first][curr.second]; // get the value of the current cell that can be traversed

        // We can move N cells in either of 4 directions
        int x = curr.first + row[i]*n; // get the next cell row coordinate
        int y = curr.second + col[i]*n; // get the next cell column coordinate

        // Constructs a pair object with its first element
        // set to x and its second element set to y
        pair<int, int> next = make_pair(x, y);

        // if valid pair
        if (isValid(visited, next)) // check if the next cell is valid to move to
        {
            // mark cell as visited
            visited.insert(next);// we mark the cell as visited to avoid cycles

            // add cell to current path
            path.push_back(next); // we add the cell to the path current path

            // recurse for next cell
            findPathInMazeUtil(maze, path, visited, next); // we recurse for the next cell trying to find the path to the middle cell

            // backtrack
            path.pop_back(); // if it does not work we backtrack and remove the cell from the path

            // remove cell from current path
            visited.erase(next); // we remove the cell from the visited set to avoid cycles
        }
    }
}

// Function to find a path from corner cell to
// middle cell in maze containing positive numbers
void findPathInMaze(int maze[N][N])
{
    // list to store complete path
    // from source to destination
    list<pair<int, int> > path; // initialize the path list that will store the path from the corner to the middle cell

    // to store cells already visited in current path
    set<pair<int, int> > visited; // initialize the visited set to keep track of what is visited to avoid cycles

    // Consider each corners as the starting
    // point and search in maze
    for (int i = 0; i < 4; ++i) // loop over the 4 corners of the maze
    {
        int x = _row[i]; // get the row coordinate of the corner using out already stored corner coordinates array
        int y = _col[i]; // get the column coordinate of the corner using out already stored corner coordinates array

        // Constructs a pair object
        pair<int, int> pt = make_pair(x, y);

        // mark cell as visited
        visited.insert(pt); // mark the cell as visited to avoid cycles

        // add cell to current path
        path.push_back(pt); // add the cell to the current path

        findPathInMazeUtil(maze, path, visited, pt); // call the utility function to find the path to the middle cell

        // backtrack
        path.pop_back(); // backtracking is done on a bigger scale of the corner by removing the cell from the path

        // remove cell from current path
        visited.erase(pt); // remove the cell from the visited set to avoid cycles
    }
}


//this adjusted function is used to find the path from a custom starting point to the middle cell
void findPathInMazeadjusted(int maze[N][N], pair<int, int> start)
{
    // list to store complete path
    // from source to destination
    list<pair<int, int> > path;

    // to store cells already visited in current path
    set<pair<int, int> > visited;

    // mark cell as visited
    visited.insert(start);

    // add cell to current path
    path.push_back(start);

    findPathInMazeUtil(maze, path, visited, start);
}


int main()
{

    // input maze
    int maze[N][N] =
            {
                    { 3, 5, 4, 4, 7, 3, 4, 6, 3 },
                    { 6, 7, 5, 6, 6, 2, 6, 6, 2 },
                    { 3, 3, 4, 3, 2, 5, 4, 7, 2 },
                    { 6, 5, 5, 1, 2, 3, 6, 5, 6 },
                    { 3, 3, 4, 3, 0, 1, 4, 3, 4 },
                    { 3, 5, 4, 3, 2, 2, 3, 3, 5 },
                    { 3, 5, 4, 3, 2, 6, 4, 4, 3 },
                    { 3, 5, 1, 3, 7, 5, 3, 6, 4 },
                    { 6, 2, 4, 3, 4, 5, 4, 5, 1 }
            };
    // Function to find a path from corner cell to middle cell in maze containing positive numbers
    findPathInMaze(maze);

    return 0;
}
