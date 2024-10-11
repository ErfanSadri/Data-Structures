#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T val) : data(val), next(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;

public:
    LinkedList() : head(nullptr) {}

    void insertAtStart(T val) {
        Node<T>* newNode = new Node<T>(val);
        newNode->next = head;
        head = newNode;
    }

    void print() {
        Node<T>* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Function to merge two sorted linked lists
    LinkedList<T> mergeSortedLists(const LinkedList<T>& list1, const LinkedList<T>& list2) {
        LinkedList<T> mergedList;

        Node<T>* current1 = list1.head;
        Node<T>* current2 = list2.head;

        while (current1 != nullptr && current2 != nullptr) {
            if (current1->data < current2->data) {
                mergedList.insertAtStart(current1->data);
                current1 = current1->next;
            } else {
                mergedList.insertAtStart(current2->data);
                current2 = current2->next;
            }
        }

        while (current1 != nullptr) {
            mergedList.insertAtStart(current1->data);
            current1 = current1->next;
        }

        while (current2 != nullptr) {
            mergedList.insertAtStart(current2->data);
            current2 = current2->next;
        }

        return mergedList;
    }

    // Function to split the list into two halves
    pair<LinkedList<T>, LinkedList<T>> splitIntoHalves() {
        LinkedList<T> firstHalf;
        LinkedList<T> secondHalf;

        // Counting the number of nodes
        int count = 0;
        Node<T>* current = head;
        while (current != nullptr) {
            ++count;
            current = current->next;
        }

        // Splitting
        current = head;
        for (int i = 0; i < count / 2; ++i) {
            firstHalf.insertAtStart(current->data);
            current = current->next;
        }

        while (current != nullptr) {
            secondHalf.insertAtStart(current->data);
            current = current->next;
        }

        return make_pair(firstHalf, secondHalf);
    }
};

int main() {
    LinkedList<int> list1;
    list1.insertAtStart(600);
    list1.insertAtStart(400);
    list1.insertAtStart(200);
    cout << "List 1: ";
    list1.print();

    LinkedList<int> list2;
    list2.insertAtStart(500);
    list2.insertAtStart(300);
    list2.insertAtStart(100);
    cout << "List 2: ";
    list2.print();

    LinkedList<int> mergedList = list1.mergeSortedLists(list1, list2);
    cout << "Merged List: ";
    mergedList.print();

    pair<LinkedList<int>, LinkedList<int>> halves = mergedList.splitIntoHalves();
    cout << "First Half: ";
    halves.first.print();
    cout << "Second Half: ";
    halves.second.print();

    return 0;
}
