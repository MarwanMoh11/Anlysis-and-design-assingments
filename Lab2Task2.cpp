#include <iostream>
#include "minheap.cpp"
#include "maxheap.cpp"
using namespace std;



int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = 6;

    MinHeap minHeap(size);
    int* sortedarray = new int[size];
    sortedarray = minHeap.HeapSort(arr, size);

    cout << "Sorted array: ";
    for (int i = 0; i < size; ++i)
        cout << sortedarray[i] << " ";
    cout << endl;

    MaxHeap maxHeap(6);

    maxHeap.push(5);
    maxHeap.push(10);
    maxHeap.push(9);
    maxHeap.push(4);
    maxHeap.push(2);
    maxHeap.push(3);
    maxHeap.push(1000);

    maxHeap.pop();
    maxHeap.heap_array_preview();




    return 0;
}
