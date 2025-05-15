#ifndef HEAP_H
#define HEAP_H

class MinHeap {
public:
    MinHeap(int capacity) {
        this->capacity = capacity;
        size = capacity;
        heapArray = new int[size];
        position = new int[capacity];
        for (int i = 0; i <= size; i++) {
            heapArray[i] = i;
            position[i] = i;
        }
        keyArray = new int[capacity];
        keyArray[0] = 0;
        for (int i = 1; i <= size; i++) {
            keyArray[i] = 999;
        }
    }

    ~MinHeap() {
        std::cout<<"Destroying heap"<<std::endl;
    }

    void insert(int vertex, int key) {
        keyArray[vertex] = key;
    }

    int extractMin() {
        int minIndex = keyArray[heapArray[0]];
        minHeapify(size);
        return minIndex;
    }

    void decreaseKey(int vertex, int newKey) {
        if (keyArray[vertex] > newKey) {
            insert(vertex, newKey);
        }
    }

    bool isInMinHeap(int vertex) {
        for (int i = 0; i < size ; i++) {
            if (heapArray[i] == vertex) {
                return true;
            }
        }
        return false;
    }

    bool isEmpty() {
        if (size == 0) {
            return true;
        }
        return false;
    }

private:
    int* heapArray;        // Heap of vertex indices
    int* keyArray;         // Corresponding key values
    int* position;         // Maps vertex to its position in heap
    int capacity;
    int size;

    void minHeapify(int idx) {
        size = idx-1;
        int arr[size];
        for (int i = 0; i < capacity; i++) {
            arr[i] = heapArray[i + 1];
        }
        delete heapArray;
        heapArray = new int[size];
        for (int i = 0; i < size; i++) {
            heapArray[i] = arr[i];
        }
    }
};

#endif