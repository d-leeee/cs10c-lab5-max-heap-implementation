#include "PrintJob.h"

const int MAX_HEAP_SIZE = 10;

class Heap {
    private:
        PrintJob* arr[MAX_HEAP_SIZE]; //heap of MAX_HEAP_SIZE
        int numItems;  //current number of items in heap
        void trickleDown(int rootIndex); //percolate down
        void trickleUp(int newJobIndex); //percolate up
        bool empty() const { return numItems == 0; }
        bool full() const { return numItems == MAX_HEAP_SIZE; }
    public:
        //Constructor & Rule of 3
        Heap(){
            numItems = 0;
        }
        ~Heap(){
            //delete each PrintJob object inside the heap
            for (int i = 0; i < MAX_HEAP_SIZE; i++){
                delete arr[i];
            }
            numItems = 0;
        }
        Heap(const Heap&) = delete;
        Heap& operator=(const Heap&) = delete;

        /*Inserts a PrintJob to the heap without
        violating max-heap properties.*/
        void enqueue(PrintJob* newJob);

        /*Removes the node with highest priority from the heap. 
        Follow the algorithm on priority-queue slides. */
        void dequeue();

        /*Returns the node with highest priority.*/
        PrintJob* highest() const;

        /*Prints the PrintJob with highest priority in the following format:
        Priority: priority, Job Number: jobNum, Number of Pages: numPages
        (Add a new line at the end.)*/
        void print() const;
};