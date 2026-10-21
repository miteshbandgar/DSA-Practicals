#include <iostream>
#include <string>
using namespace std;

struct Student {
    int rollNo;
    string name;
    float overallPercentage;
};

int main() {
    Student s;
    int choice, updateChoice;

    cout << "Enter Student Details\n";
    cout << "Roll No: ";
    cin >> s.rollNo;
    cout << "Name: ";
    cin >> s.name;
    cout << "Overall Percentage: ";
    cin >> s.overallPercentage;

    do {
        cout << "\n1. Insertion";
        cout << "\n2. Updation";
        cout << "\n3. Deletion";
        cout << "\n4. Display";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter Roll No: ";
            cin >> s.rollNo;
            cout << "Enter Name: ";
            cin >> s.name;
            cout << "Enter Overall Percentage: ";
            cin >> s.overallPercentage;
            cout << "Student inserted successfully\n";
        }
        else if (choice == 2) {
            cout << "\nWhat do you want to update?";
            cout << "\n1. Roll No";
            cout << "\n2. Name";
            cout << "\n3. Overall Percentage";
            cout << "\nEnter choice: ";
            cin >> updateChoice;

            if (updateChoice == 1) {
                cout << "Enter new Roll No: ";
                cin >> s.rollNo;
            }
            else if (updateChoice == 2) {
                cout << "Enter new Name: ";
                cin >> s.name;
            }
            else if (updateChoice == 3) {
                cout << "Enter new Overall Percentage: ";
                cin >> s.overallPercentage;
            }
            else {
                cout << "Invalid choice\n";
            }

            if (updateChoice >= 1 && updateChoice <= 3)
                cout << "Student updated successfully\n";
        }
        else if (choice == 3) {
            s.rollNo = 0;
            s.name = "";
            s.overallPercentage = 0;
            cout << "Student deleted successfully\n";
        }
        else if (choice == 4) {
            if (s.rollNo == 0) {
                cout << "No student record available\n";
            }
            else {
                cout << "\nStudent Details\n";
                cout << "Roll No: " << s.rollNo << endl;
                cout << "Name: " << s.name << endl;
                cout << "Overall Percentage: " << s.overallPercentage << "%" << endl;
            }
        }
        else if (choice == 5) {
            cout << "Exit\n";
        }
        else {
            cout << "Invalid choice\n";
        }
    } while (choice != 5);

    return 0;
}
