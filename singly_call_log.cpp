// Call Log Management - Singly Linked List

#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string name;
    string number;
    string time;
    Node* next;
};

void insertBeginning(Node*& head, string name, string number, string time)
{
    Node* newNode = new Node();

    newNode->name = name;
    newNode->number = number;
    newNode->time = time;
    newNode->next = head;

    head = newNode;

    cout << "Call record inserted at beginning.\n";
}

void insertEnd(Node*& head, string name, string number, string time)
{
    Node* newNode = new Node();

    newNode->name = name;
    newNode->number = number;
    newNode->time = time;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    cout << "Call record inserted at end.\n";
}

void deleteCall(Node*& head, string number)
{
    if (head == NULL)
    {
        cout << "Call log is empty.\n";
        return;
    }

    Node* temp = head;
    Node* previous = NULL;

    while (temp != NULL && temp->number != number)
    {
        previous = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Call record not found.\n";
        return;
    }

    if (previous == NULL)
    {
        head = temp->next;
    }
    else
    {
        previous->next = temp->next;
    }

    delete temp;

    cout << "Call record deleted successfully.\n";
}

void displayCalls(Node* head)
{
    if (head == NULL)
    {
        cout << "Call log is empty.\n";
        return;
    }

    Node* temp = head;

    cout << "\n========== CALL LOG ==========\n";

    while (temp != NULL)
    {
        cout << "Name   : " << temp->name << endl;
        cout << "Number : " << temp->number << endl;
        cout << "Time   : " << temp->time << endl;
        cout << "------------------------------\n";

        temp = temp->next;
    }
}

void searchCall(Node* head, string number)
{
    Node* temp = head;
    int position = 1;

    while (temp != NULL)
    {
        if (temp->number == number)
        {
            cout << "\nCall record found.\n";
            cout << "Name   : " << temp->name << endl;
            cout << "Number : " << temp->number << endl;
            cout << "Time   : " << temp->time << endl;
            cout << "Position: " << position << endl;
            return;
        }

        temp = temp->next;
        position++;
    }

    cout << "Call record not found.\n";
}

int countCalls(Node* head)
{
    int count = 0;
    Node* temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

void deleteList(Node*& head)
{
    Node* temp = head;

    while (temp != NULL)
    {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }

    head = NULL;
}

int main()
{
    Node* head = NULL;

    int choice;
    string name, number, time;

    do
    {
        cout << "\n========== CALL LOG MANAGEMENT ==========\n";
        cout << "1. Insert Call at Beginning\n";
        cout << "2. Insert Call at End\n";
        cout << "3. Delete Call\n";
        cout << "4. Display Call Log\n";
        cout << "5. Search Call\n";
        cout << "6. Count Calls\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Name: ";
            cin >> name;

            cout << "Enter Phone Number: ";
            cin >> number;

            cout << "Enter Call Time: ";
            cin >> time;

            insertBeginning(head, name, number, time);
            break;

        case 2:
            cout << "Enter Name: ";
            cin >> name;

            cout << "Enter Phone Number: ";
            cin >> number;

            cout << "Enter Call Time: ";
            cin >> time;

            insertEnd(head, name, number, time);
            break;

        case 3:
            cout << "Enter phone number to delete: ";
            cin >> number;

            deleteCall(head, number);
            break;

        case 4:
            displayCalls(head);
            break;

        case 5:
            cout << "Enter phone number to search: ";
            cin >> number;

            searchCall(head, number);
            break;

        case 6:
            cout << "Total number of calls = "
                 << countCalls(head) << endl;
            break;

        case 7:
            deleteList(head);
            cout << "Program terminated.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 7);

    return 0;
}
