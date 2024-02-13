#include <iostream>
using namespace std;

int exp(int a, int n,int &counter){
    int long_a = a;
    int result = 1;

    while (n!=0){
        if(n%2==1){
            result *= long_a;
            counter++;
            n -=1;
        } else {
            long_a *= long_a;
            counter++;
            n /= 2;}


    }
    return result;


}


int poly1(int arr[], int x, int size,int &counter){
    int p = arr[0];

    for (int i = 1; i <size;i++){
        counter++;
        p = p + arr[i] * exp(x,i,counter);
    }
    return p;
}

int poly2(int arr[], int x, int size,int &counter){
    int p = arr[size-1];
    for (int i = 1; i <size;i++){
        counter++;
        p = p*x + arr[size-1-i];

    }
    return p;
}

int main(){
    int counter1 = 0;
    int counter2 = 0;
    int arr[] = {2,-4,14,34};
    int size  = 4;
    cout << poly1(arr,4,size,counter1) << endl << poly2(arr,4,size,counter2) << endl << counter1 << endl << counter2;
    return 0;
}