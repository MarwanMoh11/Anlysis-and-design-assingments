//
// Created by Marwan on 2/27/2024.
//
#include <iostream>
#include <string>
#include <algorithm>
#include "vector"
using namespace std;

struct package{

    float value;
    float weight;

    bool operator<(const package& other) const{ // overloading the comparison operator for the sort
        return value/weight > other.value/other.weight;
    }


};




struct chores{

    string name;
    int minutes;
    int urgency;

    bool operator<(const chores& other) const{ // overloading the comparison operator for the sort
        return urgency > other.urgency;
    }

    bool compare(const chores& other) const{ // overloading the comparison operator for the sort
        return minutes> other.minutes;
    }

};

bool FindNum(int arr[], int n, int target,int size){

    if(n==size){
        return false;
    }
    if(arr[n] == target){
        return true;
    } else {
        return FindNum(arr,n+1,target,size);

    }


}

bool Pal(int i, int j,string x){

    if(i>j){

        return true;

    }
    if(x.at(i) == x.at(j)){
        return Pal(++i,--j,x);

    }else{
        return false;
    }

}

void delivery(vector<package> arr[],int weight){
    int total = 0;

    sort(arr->begin(),arr->end());

    for(const auto& package: *arr){
        if(total+package.weight < weight){
            cout << package.value << endl;
        }
    }


}


void chores1(vector<chores> arr,int size, int time){
    sort(arr.begin(),arr.end());
    int time_elapsed = 0;

    for(const auto& chore: arr){
        if(time_elapsed+ chore.minutes < time){
            cout << chore.name << endl;
        }

    }

}

void chores2(vector<chores> arr,int size, int time){
    sort(arr.begin(),arr.end());
    int time_elapsed = 0;

    for(const auto& chore: arr){
        if(time_elapsed+ chore.minutes < time){
            cout << chore.name << endl;
        }

    }
}


int main(){
    int arr[5] = {1,2,3,4,5};



    vector<package> x = {{1,2},
                         {3,1},
                         {1,4}};
    delivery(&x,7);
}