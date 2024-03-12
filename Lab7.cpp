#include <iostream>
#include <algorithm>
using namespace std;

struct bucket{
    int id;
    bool full;

};

// requires the array to be sorted
int storage(bucket arr[],int start, int end){
    if(arr[end].full == 0){
        return 0;
    }
    if(arr[start].full == 1){
        return (end+1-start);

    } else if (arr[start].full == 0){
            return storage(arr, start, start+(end-start)/2) + storage(arr, (start+(end-start)/2)+1, end);} else {



    }



}


int main(){
    bucket arr[] = {{11,1},
                    {12,0},
                    {13,0},
                    {14,0},
                    {15,0},
                    {16,1}
    };

    sort(begin(arr),end(arr),[](const bucket &s, const bucket &e){return s.full < e.full;});

    cout << storage(arr,0,5);
}

