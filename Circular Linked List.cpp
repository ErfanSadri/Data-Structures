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
class CLinkedList {
private:
    Node<T>* head;
public:
    CLinkedList() : head(nullptr) {}

    void setNext(CLinkedList& setList) {


        Node<T>* set = setList;

        head = set;
    }//end of setnext


    void insertAtStart(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
        }
        else {
            Node<T>* last = head;
            while (last->next != head) {
                last = last->next;
            }
            newNode->next = head;
            head = newNode;
            last->next = head;
        }
    }

    void insertAtEnd(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
        }
        else {
            Node<T>* last = head;
            while (last->next != head) {
                last = last->next;
            }
            newNode->next = head;
            last->next = newNode;
        }
    }

    void deleteByValue(T val) {
        if (head != nullptr) {
            Node<T>* current = head;
            Node<T>* prev = nullptr;
            while (current->data != val && current->next != head) {
                prev = current;
                current = current->next;
            }
            if (current->data == val) {
                if (current == head) {
                    Node<T>* last = head;
                    while (last->next != head) {
                        last = last->next;
                    }
                    head = head->next;
                    last->next = head;
                }
                else
                    prev->next = current->next;

                delete current;
            }
        }
    }

    void print() {
        if (head != nullptr) {
            Node<T>* current = head;
            do {
                cout << current->data << " ";
                current = current->next;
            } while (current != head);

            cout << endl;
        }
    }

    /*
    write a function to split the circular linked list at the given position into 
    2 circular linked list and test program to print

    void splitCLinkedList(CLinkedList& list, int position, CLinkedList& newList)
    */

    void splitCLinkedList(CLinkedList& list, int val, CLinkedList& newList) {

        if (head != nullptr) {
            Node<T>* current = head;
            Node<T>* last1 = current;
            Node<T>* prev = nullptr;

            if (current->data != val && current->next != head) {
                for (int i = 1; i <= val; i++) {
                    prev = current;
                    last1 = current;
                    current = current->next;
                }//end of for loop

            }//end of if

            //if (current->data == val) {
                Node<T>* head2 = current;
                Node<T>* last2 = current;
                newList.head = head2;

                while (last2->next != head) {//traversing the second list
                    last2 = last2->next;
                }//end of while loop

                last2->next = head2;

                //completing list 1
                last1->next = head;

            //}//end of if 2

        }//end of if 1
    }//end of splitCLinkedList

};//end of CLinkedList

/*
    void splitCLinkedList(CLinkedList& list, int val, CLinkedList& newList) {

        if (head != nullptr) {
            Node<T>* current = head;
            Node<T>* last1 = current;
            Node<T>* prev = nullptr;
            while (current->data != val && current->next != head) {
                prev = current;
                last1 = current;
                current = current->next;

            }

            if (current->data == val) {
                Node<T>* head2 = current;
                Node<T>* last2 = current;
                newList.head = head2;

                while (last2->next != head) {//traversing the second list
                    last2 = last2->next;
                }//end of while loop

                last2->next = head2;

                //completing list 1
                last1->next = head;

            }//end of if 2

        }//end of if 1
    }//end of splitCLinkedList

};//end of CLinkedList
*/

int main() {
    CLinkedList<int> list;

    list.insertAtStart(20);
    list.insertAtStart(30);
    list.insertAtStart(10);
    list.insertAtStart(40);

    cout << "Circular Linked List: ";
    list.print();

    int d = 30;
    list.deleteByValue(d);
    cout << "Deleted " << d << endl;
    list.print();

    CLinkedList<int> list2;
    CLinkedList<int> list3;

    list2.insertAtStart(20);
    list2.insertAtEnd(30);
    list2.insertAtStart(10);
    list2.insertAtStart(5);
    list2.insertAtEnd(40);
    list2.insertAtEnd(45);

    int val = 4;

    list2.splitCLinkedList(list2, val, list3);


    cout << "\n\nPrinting list2: ";
    list2.print();

    cout << "\n\nPrinting list3: ";
    list3.print();

    return 0;
}
