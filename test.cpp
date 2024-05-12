//
// Created by Marwan on 5/10/2024.
//

#include <iostream>
#include <vector>
using namespace std;

int longest(int index=0,int previndex=-1,vector<vector<int>> dp,int arr[], int size){

    if(dp[index][previndex+1]==0){
        return 0;
    }

    if(dp[index][previndex+1]!=-1){
        return dp[index][previndex+1];
    }

    if(arr[index]>arr[previndex]){
        return 1 + longest(index+1,previndex+1,dp,arr,size);
    } else if (arr[index]>arr[previndex]) {
        return 0 + longest(index + 1, previndex + 1, dp, arr, size);
    }
}

int main(
        vector<vector<int>>(-1,vector<int>(-1));
        )