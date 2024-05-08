#include "Heap.h"
#include <iostream>

using namespace std;

/*Inserts a PrintJob to the heap without
violating max-heap properties.*/
void Heap::enqueue(PrintJob* newJob){
    if (numItems == MAX_HEAP_SIZE){
        return;
    }
    arr[numItems] = newJob;
    trickleUp(numItems);
    numItems++;
}

void Heap::trickleUp(int newJobIndex){
    while (newJobIndex > 0){
        int parentIndex = (newJobIndex - 1) / 2;
        if (arr[newJobIndex] <= arr[parentIndex]){
            return;
        }
        else {
            PrintJob* copyJob = arr[newJobIndex];
            arr[newJobIndex] = arr[parentIndex];
            arr[parentIndex] = copyJob;
            newJobIndex = parentIndex;
        }
    }
}

/*Removes the node with highest priority from the heap. 
Follow the algorithm on priority-queue slides. */
void Heap::dequeue(){
    trickleDown(0);
}

void Heap::trickleDown(int rootIndex){
    int childIndex = 2 * rootIndex + 1;
    PrintJob* value = arr[rootIndex];

    while (childIndex < MAX_HEAP_SIZE){
        PrintJob* maxValue = value;
        int maxIndex = -1;
        for (int i = 0; i < 2 && i + childIndex < MAX_HEAP_SIZE; i++){
            if (arr[i + childIndex] > maxValue){
                maxValue = arr[i + childIndex];
                maxIndex = i + childIndex;
            }
        }
        if (maxValue == value){
            return;
        }
        else {
            PrintJob* copyJob = arr[rootIndex];
            arr[rootIndex] = arr[maxIndex];
            arr[maxIndex] = copyJob;
            rootIndex = maxIndex;
            childIndex = 2 * rootIndex + 1;
        }
    }
}
/*Returns the node with highest priority.*/
PrintJob* Heap::highest() const{
    return arr[0];
}

/*Prints the PrintJob with highest priority in the following format:
Priority: priority, Job Number: jobNum, Number of Pages: numPages
(Add a new line at the end.)*/
void Heap::print() const{
    arr[0]->getJobDescription();
}
