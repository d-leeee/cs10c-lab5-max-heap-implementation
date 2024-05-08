#include "PrintJob.h"
#include <iostream>

using namespace std;

int PrintJob::getPriority() const{
    return priority;
}

int PrintJob::getJobNumber() const{
    return jobNumber;
}

int PrintJob::getPages() const{
    return numPages;
}

void PrintJob::getJobDescription() const{
    cout << "Priority: " << priority << ", Job Number: " << jobNumber
    << ", Number of Pages: " << numPages << endl;
}