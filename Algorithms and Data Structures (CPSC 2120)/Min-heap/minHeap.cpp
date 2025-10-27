#include "minHeap.h"

void minHeap::siftUp(int pos){
    //Break out of recursion
    if(pos == 0){
        return;
    }

    int parent = (pos - 1) / 2;
    //If the child is smaller than the parent then swap them and try again with the new pos
    if(heap[pos] < heap[parent]){
        swap(heap[pos], heap[parent]);
        pos = parent;
        siftUp(parent);
    }
}

void minHeap::siftDown(int pos){
    int leftIndex = 2 * pos + 1;
    int rightIndex = 2 * pos + 2;
    int small = pos;

    //Pick the smaller of the two children
    if(leftIndex < heap.size() && heap[leftIndex] < heap[small]){
        small = leftIndex;
    }

    if(rightIndex < heap.size() && heap[rightIndex] < heap[small]){
        small = rightIndex;
    }

    //If the child is bigger than the parent, swap them
    if(small != pos){
        swap(heap[pos], heap[small]);
        siftDown(small);
    }
}


minHeap::minHeap(vector<int> data){
    heap = data;

    for(int i = heap.size() - 1; i >= 0; --i){
        siftDown(i);
    }
}

void minHeap::insert(int value){
    heap.push_back(value);
    siftUp(heap.size() - 1);
}

int minHeap::removeMin(){
    if(heap.empty()){
        return -1;
    }
    int temp = heap[0];
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    siftDown(0);

    return temp;
}