//Lab 10 Priority Queue
// Erfan Sadri

#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
private:
    vector<pair<int, string>> elem;

public:
    PriorityQueue() {}

    bool empty() const {
        return elem.empty();
    }

    size_t size() const {
        return elem.size();
    }

    void push(int priority, const string& description) {
        elem.emplace_back(priority, description);
    }

    pair<int, string> top() const {
        if (empty()) {
            throw out_of_range("Priority queue is empty");
        }
        int maxPriority = elem[0].first;
        int maxIndex = 0;
        for (size_t i = 1; i < elem.size(); ++i) {
            if (elem[i].first > maxPriority) {
                maxPriority = elem[i].first;
                maxIndex = static_cast<int>(i);
            }
        }
        return elem[maxIndex];
    }

    void pop() {
        if (empty()) {
            throw out_of_range("Priority queue is empty");
        }
        int maxPriority = elem[0].first;
        int maxIndex = 0;
        for (size_t i = 1; i < elem.size(); ++i) {
            if (elem[i].first > maxPriority) {
                maxPriority = elem[i].first;
                maxIndex = static_cast<int>(i);
            }
        }
        elem.erase(elem.begin() + maxIndex);
    }
};

class TaskScheduler {
private:
    PriorityQueue taskQueue;

public:
    void addTask(int priority, const string& description) {
        taskQueue.push(priority, description);
    }

    void removeTask() {
        if (!taskQueue.empty()) {
            taskQueue.pop();
        } else {
            cout << "No tasks in the scheduler." << endl;
        }
    }

    void displayTasks() const {
        PriorityQueue tempQueue = taskQueue;
        cout << "Tasks in priority order: ";
        while (!tempQueue.empty()) {
            pair<int, string> task = tempQueue.top();
            cout << "Priority " << task.first << ": " << task.second << " ";
            tempQueue.pop();
        }
        cout << endl;
    }
};

int main() {
    TaskScheduler scheduler;
    int choice;
    int priority;
    string description;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add a task\n";
        cout << "2. Remove the highest priority task\n";
        cout << "3. Display all tasks\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter priority: ";
                cin >> priority;
                cout << "Enter description: ";
                cin.ignore();
                getline(cin, description);
                scheduler.addTask(priority, description);
                break;
            case 2:
                scheduler.removeTask();
                break;
            case 3:
                scheduler.displayTasks();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        }
    } while (choice != 4);

    return 0;
}