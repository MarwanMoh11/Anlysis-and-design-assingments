//
// Created by Marwan on 5/8/2024.
//
#include <iostream>
#include <vector>
using namespace std;

int PorT(vector<char> street,int steps){
    vector<int> thief;
    vector<int> police;
    int counttheif = 0;
    int countpolice = 0;
    int catches = 0;

    for(int i = 0; i < street.size(); i++){
        if(street[i] =='P'){
            police.push_back(i);
        } else if(street[i] =='T'){
            thief.push_back(i);
        } else{
            continue;
        }
    }

    while(counttheif < thief.size() && countpolice < police.size()){
        if(abs(police[countpolice]-thief[counttheif]) < steps){
            catches++;
            countpolice++;
            counttheif++;
        } else if()
    }


}


int main() {
    cout << "Hello, World!" << endl;
    return 0;
}