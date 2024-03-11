#include <iostream>
#include <vector>
#include <utility>

using namespace std;

pair<int, int> findMaxMin(const vector<int>& arr, int low, int high) {
    if (low == high) {
        // Base case: only one element in the array
        return make_pair(arr[low], arr[low]);
    } else if (high - low == 1) {
        // Base case: only two elements in the array
        pair<int, int> result;
        if (arr[low] < arr[high]) {
            result.first = arr[low];
            result.second = arr[high];
        } else {
            result.first = arr[high];
            result.second = arr[low];
        }
        return result;

    } else {
        // Divide the array into two halves
        int mid = (low + high) / 2;
        pair<int, int> leftPair = findMaxMin(arr, low, mid);
        pair<int, int> rightPair = findMaxMin(arr, mid + 1, high);

        // Combine the results from the two halves
        int minVal = min(leftPair.first, rightPair.first);
        int maxVal = max(leftPair.second, rightPair.second);

        return make_pair(minVal, maxVal);
    }
}

int calculateDrainDay(int L, int max) {
    int pool = 0;
    int totaladded = 0;
    int day = 1;
    int totalremoved = 0;

    // Initialization: O(1)

    while(pool >= 0){
        // Loop runs until pool becomes negative

        pool -= day;  // Constant time: O(1)
        pool += L;    // Constant time: O(1)
        day++;        // Constant time: O(1)

        if(pool > max){
            pool = max;  // Constant time: O(1)
        }
    }

    // Loop complexity: O(sqrt(L))

    return day;  // Constant time: O(1)
}





int main() {

    int L = 10;
    int max = 10000;
    int drain_day = calculateDrainDay(L,max);
    cout << "The pool will drain completely on day " << drain_day << endl;


    vector<int> arr = {3, 1, 8, 4, 1000, 6, 9};
    int n = arr.size();

    pair<int, int> result = findMaxMin(arr, 0, n - 1);

    cout << "Minimum element: " << result.first << endl;
    cout << "Maximum element: " << result.second << endl;

    return 0;
}
