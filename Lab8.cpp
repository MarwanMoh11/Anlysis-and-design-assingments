//
// Created by Marwan on 3/19/2024.
//
#include <iostream>
using namespace std;
#include <vector>


int comb(int target, vector<int> arr){
    int DP[arr.size()+1][target+1];
    // Filling in the base case
    for(int i = 0; i < arr.size()+1; i++){
        DP[i][0] = 1;
    }
    // Filling in the base case
    for (int i = 1; i < target+1; i++){
        DP[0][i] = 0;
    }

    // Calculating remaining cells 
    for (int i = 1; i < arr.size()+1; i++){
        for (int j = 1; j <= target; j++){
            if(arr[i-1] > j){
                DP[i][j] = DP[i-1][j] ;
            } else if (arr[i-1] == j){
                DP[i][j] = DP[i-1][j] + 1;
            }else {
                DP[i][j] = DP[i-1][j] + DP[i][j-arr[i-1]];
            }
        }
    }



    return DP[arr.size()][target];
}

int main(){
    cout << comb(10 ,{2,3,5});
}
