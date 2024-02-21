//
// Created by Marwan on 2/20/2024.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Jobs{
    char id;
    int deadline;
    int profit;

    bool operator<(const Jobs& other) const{
        return profit > other.profit;
    }
};




void maxprofit(int maxdeadline, vector<Jobs> arr[]){
    sort(arr->begin(), arr->end());
    int day = 1;

    for(const auto& Jobs: *arr){
        while (day<=maxdeadline){
        if (day <= Jobs.deadline && day <= Jobs.deadline){
            cout << "The job " << Jobs.id  << " is done before day " << day << " for a profit of " << Jobs.profit << endl;
            day++;
            break;

        }
        }

    }


}


int main(){

    vector<Jobs> arr = {{'a',3,10},
                        {'b',3,20},
                        {'c',3,12},
                        {'d',3,7}};

    maxprofit(3,&arr);

    return 0;
}