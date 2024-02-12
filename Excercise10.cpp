#include <iostream>
using namespace std;

int main() {
    int  sum = 0;
    int max = -999999999;
    int nums[] = {2,93,-5,-4,6,7};
    int n = 6;
    for (int i = 0; i < n; i++){
        sum = 0;
        for (int j = i+1; j < n; j++){
                sum = sum + nums[j];
                if (sum > max){
                    max = sum;
                }


            }
        }

    cout << max;
    }



