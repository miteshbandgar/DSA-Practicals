#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
    int choice;
    deque<string> tasks;
    string task;

    do {
        cout << "\n--- Task Scheduler ---";
        cout << "\n1. Add Task at Front";
        cout << "\n2. Add Task at Rear";
        cout << "\n3. Add High-Priority Task";
        cout << "\n4. Process Task";
        cout << "\n5. Display Tasks";
        cout << "\n6. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter task: ";
                cin >> task;
                tasks.push_front(task);
                cout << "Task added at front." << endl;
                break;

            case 2:
                cout << "Enter task: ";
                cin >> task;
                tasks.push_back(task);
                cout << "Task added at rear." << endl;
                break;

            case 3:
                cout << "Enter high-priority task: ";
                cin >> task;
                tasks.push_front(task);
                cout << "High-priority task added." << endl;
                break;

            case 4:
                if (tasks.empty()) {
                    cout << "No tasks available!" << endl;
                } else {
                    cout << "Processing task: " << tasks.front() << endl;
                    tasks.pop_front();
                }
                break;

            case 5:
                cout << "Tasks: ";
                if (tasks.empty()) {
                    cout << "No tasks available!" << endl;
                } else {
                    for (int i = 0; i < tasks.size(); i++) {
                        cout << tasks[i] << " ";
                    }
                    cout << endl;
                }
                break;

            case 6:
                cout << "Program ended." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 6);

    return 0;
}
