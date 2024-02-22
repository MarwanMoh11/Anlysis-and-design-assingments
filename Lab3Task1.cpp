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

    bool operator<(const Jobs& other) const{ // overloading the comparison operator for the sort
        return profit > other.profit;
    }
};




void maxprofit(int maxdeadline, vector<Jobs> arr[]){
    sort(arr->begin(), arr->end()); // sorting the vector based on the profit value (Pre sorting)
    int day = 1;

    for(const auto& Jobs: *arr){ // going over the whole vector
        if (day <= maxdeadline& day <= Jobs.deadline){ // if the deadline of specific job fits criteria pick it based on value
            cout << "The job " << Jobs.id  << " is done before day " << day << " for a profit of " << Jobs.profit << endl;
            day++;


        }


    }


}


int main(){

    vector<Jobs> arr = {{'a',2,20},
                        {'b',2,15},
                        {'c',1,21},
                        {'d',3,5},
                        {'e',3,1}};

    maxprofit(3,&arr);

    return 0;
}