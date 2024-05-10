//
// Created by Marwan on 5/10/2024.
//

#include <iostream>
#include <vector>
using namespace std;

// Function for finding the longest path
// 'ans' is -1 if we can't reach
// 'cur' is the number of steps we have traversed
int findLongestPath(vector<vector<int> >& mat, int i, int j, // i and j are the source coordinates
                    int di, int dj, int n, int m, // di and dj are the destination coordinates and n is the number of rows and m is the number of columns
                    int cur = 0, int ans = -1) // cur is the number of steps we have traversed and ans is the longest path
{
    // If we reach the destination
    if (i == di && j == dj) { // if the current coordinates are the destination coordinates
        // If current path steps are more than previous path
        // steps
        if (cur > ans) // if the current path is longer than the previous path we set the current path as the longest path
            ans = cur;
        return ans;
    }

    //if the source or destination is a hurdle itself
    if(mat[i][j]==0 || mat[di][dj]==0){
        cout << "Error: Source or destination is a hurdle." << endl;
        exit(1);} // exit the program with an error code rather than returning -1 because that would affect the output

    // Mark as visited
    mat[i][j] = 0; // mark the current coordinates as visited using 0 as a flag which is a hurdle in this case

    // Checking if we can reach the destination going right
    if (j != m - 1 && mat[i][j + 1] > 0) // if we are not at the last column and the next column is not a hurdle
        ans = findLongestPath(mat, i, j + 1, di, dj, n, m,
                              cur + 1, ans); // recursively call the function with the next column

    // Checking if we can reach the destination going down
    if (i != n - 1 && mat[i + 1][j] > 0) // if we are not at the last row and the next row is not a hurdle
        ans = findLongestPath(mat, i + 1, j, di, dj, n, m,
                              cur + 1, ans); // recursively call the function with the next row

    // Checking if we can reach the destination going left
    if (j != 0 && mat[i][j - 1] > 0) // if we are not at the first column and the previous column is not a hurdle
        ans = findLongestPath(mat, i, j - 1, di, dj, n, m,
                              cur + 1, ans); // recursively call the function with the previous column

    // Checking if we can reach the destination going up
    if (i != 0 && mat[i - 1][j] > 0)  // if we are not at the first row and the previous row is not a hurdle
        ans = findLongestPath(mat, i - 1, j, di, dj, n, m,
                              cur + 1, ans); // recursively call the function with the previous row

    // Marking visited to backtrack
    mat[i][j] = 1; // we unvisit the current cell by marking it as 1 which is not a hurdle to backtrack

    // Returning the answer we got so far
    return ans;
}

int main()
{
    vector<vector<int> > mat = { { 1, 1, 1, 1 },
                                 { 1, 1, 0, 1 },
                                 { 1, 1, 1, 1 } };

    // Find the longest path with source (0, 0) and
    // destination (2, 3)
    int result = findLongestPath(mat, 0, 0, 2, 3,
                                 mat.size(), mat[0].size());
    cout << result << endl;

    return 0;
}
