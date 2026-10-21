// Train Reservation System - Doubly Linked List

#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int seatNo;
    string passengerName;
    string trainName;

    Node* prev;
    Node* next;
};

void insertBeginning(Node*& head, Node*& tail,
                     int seat, string name, string train)
{
    Node* newNode = new Node();

    newNode->seatNo = seat;
    newNode->passengerName = name;
    newNode->trainName = train;

    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;
    else
        tail = newNode;

    head = newNode;

    cout << "Reservation inserted at beginning.\n";
}

void insertEnd(Node*& head, Node*& tail,
               int seat, string name, string train)
{
    Node* newNode = new Node();

    newNode->seatNo = seat;
    newNode->passengerName = name;
    newNode->trainName = train;

    newNode->next = NULL;
    newNode->prev = tail;

    if (tail == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }

    cout << "Reservation inserted at end.\n";
}

void deleteReservation(Node*& head, Node*& tail, int seat)
{
    if (head == NULL)
    {
        cout << "Reservation list is empty.\n";
        return;
    }

    Node* temp = head;

    while (temp != NULL && temp->seatNo != seat)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Seat number not found.\n";
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    else
        tail = temp->prev;

    delete temp;

    cout << "Reservation cancelled successfully.\n";
}

void displayForward(Node* head)
{
    if (head == NULL)
    {
        cout << "Reservation list is empty.\n";
        return;
    }

    Node* temp = head;

    cout << "\n========== TRAIN RESERVATIONS ==========\n";

    while (temp != NULL)
    {
        cout << "Seat Number     : " << temp->seatNo << endl;
        cout << "Passenger Name  : " << temp->passengerName << endl;
        cout << "Train Name      : " << temp->trainName << endl;
        cout << "----------------------------------------\n";

        temp = temp->next;
    }
}

void displayBackward(Node* tail)
{
    if (tail == NULL)
    {
        cout << "Reservation list is empty.\n";
        return;
    }

    Node* temp = tail;

    cout << "\n====== RESERVATIONS IN REVERSE ORDER ======\n";

    while (temp != NULL)
    {
        cout << "Seat Number     : " << temp->seatNo << endl;
        cout << "Passenger Name  : " << temp->passengerName << endl;
        cout << "Train Name      : " << temp->trainName << endl;
        cout << "-----------------------------------------\n";

        temp = temp->prev;
    }
}

void searchReservation(Node* head, int seat)
{
    Node* temp = head;
    int position = 1;

    while (temp != NULL)
    {
        if (temp->seatNo == seat)
        {
            cout << "\nReservation Found!\n";
            cout << "Seat Number    : " << temp->seatNo << endl;
            cout << "Passenger Name : " << temp->passengerName << endl;
            cout << "Train Name     : " << temp->trainName << endl;
            cout << "Position       : " << position << endl;
            return;
        }

        temp = temp->next;
        position++;
    }

    cout << "Reservation not found.\n";
}

int countReservations(Node* head)
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

void deleteList(Node*& head, Node*& tail)
{
    Node* temp = head;

    while (temp != NULL)
    {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }

    head = NULL;
    tail = NULL;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    int choice;
    int seat;
    string name, train;

    do
    {
        cout << "\n========== TRAIN RESERVATION SYSTEM ==========\n";
        cout << "1. Insert Reservation at Beginning\n";
        cout << "2. Insert Reservation at End\n";
        cout << "3. Cancel Reservation\n";
        cout << "4. Display Reservations Forward\n";
        cout << "5. Display Reservations Backward\n";
        cout << "6. Search Reservation\n";
        cout << "7. Count Reservations\n";
        cout << "8. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Seat Number: ";
            cin >> seat;

            cout << "Enter Passenger Name: ";
            cin >> name;

            cout << "Enter Train Name: ";
            cin >> train;

            insertBeginning(head, tail, seat, name, train);
            break;

        case 2:
            cout << "Enter Seat Number: ";
            cin >> seat;

            cout << "Enter Passenger Name: ";
            cin >> name;

            cout << "Enter Train Name: ";
            cin >> train;

            insertEnd(head, tail, seat, name, train);
            break;

        case 3:
            cout << "Enter Seat Number to cancel: ";
            cin >> seat;

            deleteReservation(head, tail, seat);
            break;

        case 4:
            displayForward(head);
            break;

        case 5:
            displayBackward(tail);
            break;

        case 6:
            cout << "Enter Seat Number to search: ";
            cin >> seat;

            searchReservation(head, seat);
            break;

        case 7:
            cout << "Total Reservations = "
                 << countReservations(head) << endl;
            break;

        case 8:
            deleteList(head, tail);
            cout << "Program terminated.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 8);

    return 0;
}
