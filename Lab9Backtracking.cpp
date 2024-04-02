//
// Created by Marwan on 4/2/2024.
//
#include <iostream>
#include <vector>
using namespace std;

void CodeCracker(int n, string &code, int range, int& counter,vector<bool>& used){
    if(n == 0){
        cout << code << endl;
        counter++;
        return;
    }
    for(int i = 1; i <= range; i++){
        if(used[i]) continue;
            code.push_back(i + '0');
            used[i] = true;
            CodeCracker(n-1, code, range,counter,used);
            used[i] = false;
            code.pop_back();

    }

}

void CodeCrackerCaller(int n, int range, int& counter){
    string code = "";
    vector<bool> used(10, false);
    CodeCracker(n, code, range,counter,used);


}


int main(){
    int counter = 0;
    CodeCrackerCaller(4, 6, counter);
    cout << "Total number of codes: " << counter << endl;
    return 0;
}