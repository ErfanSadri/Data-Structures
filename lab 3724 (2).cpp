#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

struct Sport {
    string name;
    int players;
};

template <class T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
    };

    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void enqueue(T value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (!isEmpty()) {
            Node* temp = front;
            front = front->next;
            delete temp;
            if (front == nullptr) {
                rear = nullptr;
            }
        } else {
            cout << "Queue is empty. Cannot dequeue." << endl;
        }
    }

    T getFront() {
        if (!isEmpty()) {
            return front->data;
        } else {
            cout << "Queue is empty. Cannot get front element." << endl;
            return T();
        }
    }

    bool isEmpty() {
        return front == nullptr;
    }
};

int main() {
    Queue<int> intQueue;
    intQueue.enqueue(10);
    intQueue.enqueue(20);
    intQueue.enqueue(30);

    cout << "Front element of intQueue: " << intQueue.getFront() << endl;
    intQueue.dequeue();
    cout << "Front element of intQueue after dequeue: " << intQueue.getFront() << endl;

    Queue<char> charQueue;
    charQueue.enqueue('A');
    charQueue.enqueue('B');
    charQueue.enqueue('C');

    cout << "Front element of charQueue: " << charQueue.getFront() << endl;
    charQueue.dequeue();
    cout << "Front element of charQueue after dequeue: " << charQueue.getFront() << endl;

    Queue<Sport> sportQueue;
    Sport football = {"Football", 11};
    Sport basketball = {"Basketball", 5};
    Sport volleyball = {"volleyball", 11};

    sportQueue.enqueue(football);
    sportQueue.enqueue(basketball);
    sportQueue.enqueue(volleyball);

    cout << "Front element of sportQueue: " << sportQueue.getFront().name << " with " << sportQueue.getFront().players << " players." << endl;

    return 0;
}