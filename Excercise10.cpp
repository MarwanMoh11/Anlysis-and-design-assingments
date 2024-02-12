#include <iostream>
using namespace std;

void sum1(int nums[], int n){
    int  sum = 0;
    int counter  = 0;
    int start = 0;
    int end = 0;
    int max = -999999999;

    for (int i = 0; i < n; i++){
        sum = 0;
        for (int j = i; j < n; j++){
            sum = sum + nums[j];
            counter++;
            if (sum > max){
                max = sum;
                start = i+1;
                end = j+1;
            }


        }
    }



    cout << "Max: "<<max << endl << "S: "<<start << endl << "E: "<< end << endl << "Number of arthimetic operations: " << counter;

}

void sum2(int nums[],int n){
    int sum = 0;
    int max = -9999999;
    int localstart = 0;
    int counter = 0;
    int start;
    int end;

    for (int i = 0; i < n; i++){
        sum = sum + nums[i];
        counter++;

        if (sum>max){
            max = sum;
            start = localstart;
            end = i;
        }

        if (sum<0){
            sum = 0;
            localstart = i + 1;
        }

    }

    cout << endl <<"Max: "<<max << endl << "S: "<<start + 1 << endl << "E: "<< end + 1 << endl << "Number of arthimetic operations: " << counter;
}



int main() {
    int nums[] = {-1,-11,-4,-13,-5,-2};
    int n = 6;

    sum1(nums,n); // θ(n^2) complexity
    sum2(nums,n); // θ(n) complexity

    }



