//
// Created by Marwan on 2/19/2024.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sort(vector<int> &arr, float size){
    std::sort(arr.begin(), arr.end());
}

int task1(vector<int> arr, int size){
    // assuming it is sorted
    return arr[size-1] - arr[0];
}

float task2(vector<int> arr, float size){ // linear function that sums and divides by size for average
    float sum = 0;
    for (int i = 0; i < size; i++){
        sum = sum + arr[i];
    }

    return sum / size;
}

int task3(vector<int> arr, int size){
    //assuming it is sorted
    if(size % 2 == 1){
        // If the number of elements is odd, return the middle element
        return arr[size / 2];
    } else {
        // If the number of elements is even return the average of the two middle elements
        return (arr[size / 2 - 1] + arr[size / 2]) / 2.0;
    }
}

bool task4(vector<int> arr, int size){
    //assuming it is sorted

    int *left = &arr[0];
    int *right = &arr[arr.size() - 1];
    int leftIndex = 0;
    int rightIndex = size - 1;

    while (left < right) {
        if (*left + *right == 20) {
            cout << "The pair " << *left << " and " << *right <<" add up to 20." << std::endl;
            return true;
        } else if (*left + *right > 20) {
            right--;
            rightIndex--;
        } else if (*left + *right < 20) {
            left++;
            leftIndex++;
        }
    }

    cout << "No grades add up to 20";
    return false;

}
int main(){

    vector<int> arr = {3,2,1,10,3,0,3,10};
    sort(arr,8);
    cout << task1(arr,8) << endl << task2(arr,8) << endl;
    task4(arr,8);
    return 0;
}