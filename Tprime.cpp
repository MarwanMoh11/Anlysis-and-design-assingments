//
// Created by Marwan on 4/1/2024.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(int i){
    if(i == 1){
        return false;
    }
    for(int j = 2; j*j<=i; j++){
        if(i % j == 0){
            return false;
        }
    }
    return true;
}

vector<bool> isTPrime( const vector<int>& nums){
    vector<bool> results;
    for(int i = 0; i < nums.size(); i++){
        int root  = sqrt(nums[i]);
        if(root*root == nums[i] && isPrime(root)){
            results.push_back(true);
        } else {
            results.push_back(false);
        }
    }

    return results;
}

int main(){
    vector<int> nums = {4, 5, 6, 9};
    vector<bool> results = isTPrime(nums);
    for(int i = 0; i < results.size(); i++){
        cout << results[i] << " ";
    }
    return 0;
}
