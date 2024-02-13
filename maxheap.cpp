#include <iostream>
using namespace std;

// A class for Max Heap
class MaxHeap{
    int *heap_array; // pointer to array of elements in heap
    int capacity; // maximum possible size of max heap
    int heap_size; // Current number of elements in max heap

public:
    // Constructor: Initialise a capacity and heap_array;
    MaxHeap(int capacity){
        this->heap_size = 0;
        this->capacity = capacity;
        this->heap_array = new int[capacity];
    }

    // method to heapify a subtree with the root at given index i
    void MaxHeapify(int i){
        /* A recursive method to heapify 'heap_array' */
        int l = left(i);
        int r = right(i);

        int largest = i;
        if (l < heap_size && heap_array[l] > heap_array[i])
            largest = l;
        if (r < heap_size && heap_array[r] > heap_array[largest])
            largest = r;

        if (largest != i){
            swap(heap_array[i], heap_array[largest]);
            MaxHeapify(largest);
        }
    }

    // method to get index of parent of node at index i
    int parent(int i){ return (i-1)/2; }

    // method to get index of left child of node at index i
    int left(int i){ return (2*i + 1); }

    // method to get index of right child of node at index i
    int right(int i){ return (2*i + 2); }

    // method to remove maximum element (or root) from max heap
    int extractMax(){
        if (heap_size <= 0)
            return INT_MIN;
        if (heap_size == 1){
            heap_size--;
            return heap_array[0];
        }

        // remove the maximum value from the heap.
        int root = heap_array[0];
        heap_array[0] = heap_array[heap_size-1];
        heap_size--;
        MaxHeapify(0);

        return root;
    }

    // method to increase key value of key at index i to new_val
    void increaseKey(int i, int new_val){
        heap_array[i] = new_val;
        while (i != 0 && heap_array[parent(i)] < heap_array[i]){
            swap(heap_array[i], heap_array[parent(i)]);
            i = parent(i);
        }
    }

    // Returns the maximum key (key at root) from max heap
    int getMax(){ return heap_array[0]; }

    // method deletes key at index i
    // (It first increases value to plus infinite, then calls extractMax() )
    void deleteKey(int i){
        increaseKey(i, INT_MAX);
        extractMax();
    }

    // method to inserts a new key 'k'
    void insertKey(int k){
        if (heap_size == capacity){
            cout << "\nOverflow: Could not insertKey\n";
            return;
        }

        // Inserting the new key at the end
        int i = heap_size;
        heap_array[heap_size++] = k;

        while (i != 0 && heap_array[parent(i)] < heap_array[i]){
            swap(heap_array[i], heap_array[parent(i)]);
            i = parent(i);
        }
    }

    // method to build a max heap from array
    void BuildMaxHeap(int* A, int n) {
        // Copy the given array to the heap array
        for (int i = 0; i < n; ++i) {
            heap_array[i] = A[i];
        }

        // Update the size of the heap
        heap_size = n;

        // Heapify each node in reverse order
        for (int i = n / 2 - 1; i >= 0; --i) {
            MaxHeapify(i);
        }
    }

    // Function to perform heap sort
    int* HeapSort(int* arr, int size) {
        // Build max heap
        BuildMaxHeap(arr, size);

        // Create a new array to store the sorted elements
        int* sortedArray = new int[size];

        // Extract elements from max heap one by one
        for (int i = 0; i < size; i++) {
            // Move the maximum element from the heap to sortedArray
            sortedArray[i] = extractMax();
        }

        // Return the sorted array
        return sortedArray;
    }

    //utility function to preview heap_array
    void heap_array_preview()
    {
        for(int i = 0; i < heap_size; ++i) {
            std::cout << heap_array[i] << ' ';
        }
        std::cout << endl;
    }

    void pop(){
        if (heap_size < 1) {
            cout << "Heap is already empty." << endl;
            return;
        }
        // Swap the root (maximum element) with the last element
        heap_array[0] = heap_array[heap_size - 1];
        // Decrease the size of the heap
        heap_size--;
        // Heapify the root to maintain heap property
        MaxHeapify(0);
    }

    void push(int k){
        if (heap_size >= capacity) {
            cout << "Overflow: Could not push " << k << " into heap." << endl;
            return;
        }
        // Insert the new key at the end
        int i = heap_size;
        heap_array[heap_size++] = k;

        // Fix the heap property if violated
        while (i != 0 && heap_array[parent(i)] < heap_array[i]){
            swap(heap_array[i], heap_array[parent(i)]);
            i = parent(i);
        }
    }

};
