//
// Created by Marwan on 2/20/2024.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Jobs{
    int id;
    int deadline;
    int profit;

    bool operator<(const Jobs& other) const{
        return profit > other.profit;
    }
};




void maxprofit(int maxdeadline, vector<Jobs> arr[]){
    sort(arr->begin(), arr->end());

    for(const auto& Jobs: *arr){
        cout << Jobs.profit << endl;

    }

}


int main(){

    vector<Jobs> arr = {{2,2,10},
                        {2,2,20},
                        {2,2,12},
                        {2,2,7}};

    maxprofit(2,&arr);

    return 0;
}