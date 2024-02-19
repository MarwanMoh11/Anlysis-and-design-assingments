//
// Created by Marwan on 2/19/2024.
//

#include <iostream>
using namespace std;

const int friends = 3;


void Friendship(int arr[friends][friends]){
    int counter = 0, fullyconnected = 0, ringtopology = 0;

    for (int i = 0; i < friends; i++){
        for(int j = 0; j < friends; j++){

            if(arr[i][j] == 1){
                counter++;

            }
        }
        if(counter == friends-1){
           fullyconnected++;
        } if(counter == 2){
            ringtopology++;

        }
        counter = 0;
    }
    if(fullyconnected == friends) {
        cout << "Fully connected" << endl;
    }
    if (fullyconnected == 1){
        cout << "Star Topology" << endl;
    } if (ringtopology == friends){
        cout << "Ring Topology" << endl;
    }


}


int main(){

    int myArray[friends][friends] = {
            {0, 1, 1},
            {1, 0, 0},
            {1, 0, 0}
    };


    Friendship(myArray);





    return 0;
}