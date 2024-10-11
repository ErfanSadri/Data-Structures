#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
  T data;
  Node* prev;
  Node* next;

  Node(T val) : data(val), prev(nullptr), next(nullptr) {}
};

template <typename T>
class DLinkedList {
private:
  Node<T>* head;
  Node<T>* tail;
public:
  DLinkedList() : head(nullptr), tail(nullptr) {}

  // Insertion at the beginning of the list
  void insertAtStart(T val) {
    Node<T>* newNode = new Node<T>(val);
    if (head == nullptr) {
      head = tail = newNode;
    }
    else {
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
    }
  }

  // Insertion at the end of the list
  void insertAtEnd(T val) {
    Node<T>* newNode = new Node<T>(val);
    if (tail == nullptr) {
      head = tail = newNode;
    }
    else {
      newNode->prev = tail;
      tail->next = newNode;
      tail = newNode;
    }
  }

  // Deletion by value
  void deleteByValue(T val) {
    Node<T>* current = head;
    while (current != nullptr && current->data != val)
      current = current->next;
    if (current != nullptr) {
      if (current == head) {
        head = current->next;
        if (head != nullptr){
          head->prev = nullptr;
        }
      }
      else if (current == tail) {
        tail = current->prev;
        if (tail != nullptr) {
          tail->next = nullptr;
        }
      }
      else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
      }
      delete current; // Free the memory of the deleted node
    }
  }

  // Print the list forward
  void printForward() {
    Node<T>* current = head;
    while (current != nullptr) {
      cout << current->data << " ";
      current = current->next;
    }
    cout << endl;
  }

  // Print the list backward
  void printBackward() {
    Node<T>* current = tail;
    while (current != nullptr){
      cout << current->data << " ";
      current = current->prev;
    }
    cout << endl;
  }

  // Delete a node from the beginning of the list
  void deleteFromStart() {
    if (head != nullptr) {
      Node<T>* temp = head;
      head = head->next;
      if (head != nullptr) {
        head->prev = nullptr;
      }
      delete temp; // Free the memory of the deleted node
    }
  }

  // Delete a node from the end of the list
  void deleteFromEnd() {
    if (tail != nullptr) {
      Node<T>* temp = tail;
      tail = tail->prev;
      if (tail != nullptr) {
        tail->next = nullptr;
      }
      delete temp; // Free the memory of the deleted node
    }
  }

  // Reverse the list
  void reverse() {
    Node<T>* current = head;
    Node<T>* temp = nullptr;
    while (current != nullptr) {
      temp = current->prev;
      current->prev = current->next;
      current->next = temp;
      current = current->prev;
    }
    if (temp != nullptr) {
      head = temp->prev;
    }
  }
};

int main() {
    DLinkedList<int> intList;
    intList.insertAtStart(20);
    intList.insertAtEnd(30);
    intList.insertAtStart(10);
    intList.insertAtEnd(40);

    cout << "Doubly Linked List (Forward): ";
    intList.printForward();

    cout << "Doubly Linked List (Backward): ";
    intList.printBackward();

    int d = 30;
    intList.deleteByValue(d);
    cout << "Deleted " << d << endl;
    intList.printForward();

    intList.deleteFromStart();
    cout << "Deleted from start: ";
    intList.printForward();

    intList.deleteFromEnd();
    cout << "Deleted from end: ";
    intList.printForward();

    cout << "Reversed list: ";
    intList.reverse();
    intList.printForward();

    return 0;
}