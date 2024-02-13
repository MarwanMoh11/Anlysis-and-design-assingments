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
    int arr1[] = {2,-4,14,34};
    int size1  = 4;
    cout <<"=============================="<<endl;
    cout << "Naive(x=1): " << poly1(arr1,1,size1,counter1) << endl << "Counter: " << counter1 <<endl<< "Honer(x=1): " << poly2(arr1,1,size1,counter2) <<endl << "Counter: " << counter2 << endl;
    counter1 = 0; counter2 = 0;
    int arr2[] = {2,-4,14,34,-4,23,-11,23,11};
    int size2  = 8;
    cout <<"=============================="<<endl;
    cout << "Naive(x=1): " << poly1(arr2,1,size2,counter1) << endl << "Counter: " << counter1 <<endl<< "Honer(x=1): " << poly2(arr2,1,size2,counter2) <<endl << "Counter: " << counter2 << endl;
    counter1 = 0; counter2 = 0;
    int arr3[] = {2,-4,14,34,22,21,32,232,44,44,2,-23};
    int size3  = 10;
    cout <<"=============================="<<endl;
    cout << "Naive(x=1): " << poly1(arr3,1,size3,counter1) << endl << "Counter: " << counter1 <<endl<< "Honer(x=1): " << poly2(arr3,1,size3,counter2) <<endl << "Counter: " << counter2 << endl;
    counter1 = 0; counter2 = 0;
    cout <<"=============================="<<endl;




    return 0;
}