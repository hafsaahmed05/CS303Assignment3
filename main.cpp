#include <iostream>
#include "Question1.h"
using namespace std;

int main() {
     Queue<int> myQueue;

     // Using the push function
     myQueue.push(8);
     myQueue.push(9);
     myQueue.push(12);
     myQueue.push(3);
     myQueue.push(6);
     myQueue.push(4);
     myQueue.push(3);
     myQueue.push(1);
     myQueue.push(14);
     myQueue.push(8);

     cout << "Queue: ";
     myQueue.printQueue();

     // Using the front function to print the first element
     cout << "\nFront element: " << myQueue.front() << endl;
     
     // Using the size element
     cout << "\nQueue size: " << myQueue.size() << endl;

     // Move front to rear
     myQueue.move_to_rear();
     cout << "\nUpdated Queue (after moving front to rear): ";
     myQueue.printQueue();

     // Using the pop function
     myQueue.pop();
     
     cout << "\nUpdated Queue (after popping an element): ";
     myQueue.printQueue();

     // Finding the last occurence of an element
     cout << "The last occurence of element 3 is at index: " << myQueue.last_occurrence(3) << endl;

     // Using Insertion Sort
     cout << "\nCURRENT QUEUE: ";
     myQueue.printQueue();

     myQueue.insertion_sort();

     cout << "\nQUEUE (AFTER SORT): ";
     myQueue.printQueue();
     
     
}