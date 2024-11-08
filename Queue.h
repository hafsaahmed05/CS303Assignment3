#include <iostream>
#include <queue>
using namespace std;

// Node structure for the linked list
template <typename T>
struct Node {
  T data;      // value to keep track of the data in the node
  Node* next;  // pointer to the next node

  // constructor defintion for the Node struct
  Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class Queue {
private:
  Node<T>* head;       // Pointer to the front node
  Node<T>* tail;       // Pointer to the rear node
  int currentSize;     // Size of the queue

  int last_occurrence(Node<T>* node, T target, int index, int& lastIndex) {
    // Base Case: if the node is nullptr, return the lastIndex found
    if (node == nullptr)
      return lastIndex;
    
    // If the current node's data matches the target
    if (node->data == target) {
      // Update the lastIndex value to the current index
      lastIndex = index; 
    }
    
    // Recursive call to check the next node and increment the index
    return last_occurrence(node->next, target, index + 1, lastIndex);
  }

public:
  // Constructor
  Queue() : head(nullptr), tail(nullptr), currentSize(0) {}

  // Destructor
  ~Queue() {
    while (!empty()) {
      pop();
    }
  }

  // Check if the queue is empty
  bool empty() const {
    return (currentSize == 0);
  }

  // Push a new element at the rear of the queue
  void push(T value) {
    // Create a new node with the value provided
    Node<T>* newNode = new Node<T>(value);

    // If the queue is empty
    if (empty()) {
       // Set the front and the back of the queue equal to the new node
      tail = newNode;
      head = tail;
    } 

    else {
      // Set the current tail's next node equal to the new node
      tail->next = newNode;
      
      // Change the tail's pointer to the newNode
      tail = newNode;
    }
      
    // Increment the size of the queue
    currentSize++;
  }

  // Pop the front element of the queue
  void pop() {
    // If the queue is empty, then print error message and exit function
    if (empty()) {
      cout << "Queue is empty, cannot pop." << endl;
      return;
    }

    // Create a temporary variable to store the current front of the queue
    Node<T>* oldFront = head;
    
    // Change the front of the queue pointer to the next node
    head = head->next;
    
    // Delete the current front of the queue
    delete oldFront;
    
    // Decrement the current size of the queue
    currentSize--;

    // If the queue if empty after removing the front
    if (head == nullptr) {
        // Set the tail's pointer equal to null as well
        tail = nullptr;
    }
  }

  // Return the front element of the queue
  T front() {
    // If the Queue is empty
    if (empty()) {
      // Print message saying queue is empty
      cout << "Queue is empty\n";
      
      // Return the default constructor value of T
      return T();
    }
    // Return the value at the head
    return head->data;
  }

  // Return the size of the queue
  int size() const {
    return currentSize;
  }

  // Move the front element to the rear of the queue
  void move_to_rear() {
     // If the queue has more than one element
    if (currentSize > 1) {

      // Store the value of the front element
      T frontElem = front();

      // Remove it from the front
      pop();

      // Push it to the front of the queue
      push(frontElem);
    }
  }

  void printQueue(){
     Node<T>* curr = head;
     while (curr != nullptr) {
         cout << " " << curr->data;
         curr = curr->next;
     }
     cout << endl;
  }

  // function to find the last occurrence of a target element
  int last_occurrence(T target) {
       // Initialize lastIndex as -1 for no occurrence
       int lastIndex = -1;
       return last_occurrence(head, target, 0, lastIndex);
  }

  void insertion_sort() {
    // If the queue is empty or has only one element, exit the function
    if (empty() || size() <= 1) 
      return; 
    
    // Initialize the sorted list by creating a pointer node that will point to the sorted part of the list
    Node<T>* sorted = nullptr; 

    // Create a pointer used to keep track of the current node in the unsorted part of the list and set it equal to the first element of the unsorted list
    Node<T>* current = head;
    
    // Traverse the list - while the end of the list is not reached
    while (current != nullptr) {
      // Store the nextNode in the unsorted part of the list in a variable
      Node<T>* nextNode = current->next;

      // if the sorted part of the list is empty or if the current value's data is less than or equal to the first node of the sorted part of the list
      if (sorted == nullptr || current->data <= sorted->data) {
        // link the current node to the sorted part of the list
        current->next = sorted;

        // make the sorted pointer point to the new node at the front of the list
        sorted = current;
      }
    
      else {
        // Find the node before the point of insertion in the sorted part of the list and store it in a temporary variable
        Node<T>* temp = sorted;   

        // Traverse the linked list until you find out the correct position of the value at the temp variable
        while (temp->next != nullptr && temp->next->data < current->data) {
          temp = temp->next;
        }

        // set the current node equal to the next node in the sorted part of the list
        current->next = temp->next;
        temp->next = current;
      }

      // Move to the next node in the unsorted part of the queue
      current = nextNode;
    
      // Update the head to the head of the sorted queue
      head = sorted;

      // Update the tail to the tail of the sorted queue
      while (tail->next != nullptr) {
        tail = tail->next;
      }
    }
  }
};
