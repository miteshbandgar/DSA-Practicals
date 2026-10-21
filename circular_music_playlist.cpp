// Music Playlist Management - Circular Linked List

#include <iostream>
#include <string>
using namespace std;

struct Song
{
    int songID;
    string songName;
    string artist;
    string duration;

    Song* next;
};

Song* head = NULL;
Song* current = NULL;

void addSong()
{
    Song* newSong = new Song;

    cout << "Enter Song ID: ";
    cin >> newSong->songID;

    cout << "Enter Song Name: ";
    cin >> newSong->songName;

    cout << "Enter Artist: ";
    cin >> newSong->artist;

    cout << "Enter Duration: ";
    cin >> newSong->duration;

    if (head == NULL)
    {
        head = newSong;
        newSong->next = head;
    }
    else
    {
        Song* temp = head;

        while (temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = newSong;
        newSong->next = head;
    }

    cout << "Song Added Successfully!\n";
}

void displayPlaylist()
{
    if (head == NULL)
    {
        cout << "Playlist is Empty.\n";
        return;
    }

    Song* temp = head;

    cout << "\n===== MUSIC PLAYLIST =====\n";

    do
    {
        cout << "Song ID   : " << temp->songID << endl;
        cout << "Song Name : " << temp->songName << endl;
        cout << "Artist    : " << temp->artist << endl;
        cout << "Duration  : " << temp->duration << endl;
        cout << "-------------------------\n";

        temp = temp->next;

    } while (temp != head);
}

void playNext()
{
    if (head == NULL)
    {
        cout << "Playlist is Empty.\n";
        return;
    }

    if (current == NULL)
    {
        current = head;
    }
    else
    {
        current = current->next;
    }

    cout << "\nNow Playing:\n";
    cout << "Song ID   : " << current->songID << endl;
    cout << "Song Name : " << current->songName << endl;
    cout << "Artist    : " << current->artist << endl;
    cout << "Duration  : " << current->duration << endl;
}

void searchSong()
{
    if (head == NULL)
    {
        cout << "Playlist is Empty.\n";
        return;
    }

    int searchID;

    cout << "Enter Song ID to search: ";
    cin >> searchID;

    Song* temp = head;

    do
    {
        if (temp->songID == searchID)
        {
            cout << "\nSong Found!\n";
            cout << "Song ID   : " << temp->songID << endl;
            cout << "Song Name : " << temp->songName << endl;
            cout << "Artist    : " << temp->artist << endl;
            cout << "Duration  : " << temp->duration << endl;

            return;
        }

        temp = temp->next;

    } while (temp != head);

    cout << "Song Not Found.\n";
}

void deleteSong()
{
    if (head == NULL)
    {
        cout << "Playlist is Empty.\n";
        return;
    }

    int deleteID;

    cout << "Enter Song ID to delete: ";
    cin >> deleteID;

    Song* currentNode = head;
    Song* previous = NULL;

    if (head->next == head)
    {
        if (head->songID == deleteID)
        {
            delete head;
            head = NULL;
            current = NULL;

            cout << "Song Deleted Successfully!\n";
        }
        else
        {
            cout << "Song Not Found.\n";
        }

        return;
    }

    if (head->songID == deleteID)
    {
        Song* last = head;

        while (last->next != head)
        {
            last = last->next;
        }

        head = head->next;
        last->next = head;

        if (current == currentNode)
            current = head;

        delete currentNode;

        cout << "Song Deleted Successfully!\n";
        return;
    }

    previous = head;
    currentNode = head->next;

    while (currentNode != head)
    {
        if (currentNode->songID == deleteID)
        {
            previous->next = currentNode->next;

            if (current == currentNode)
                current = currentNode->next;

            delete currentNode;

            cout << "Song Deleted Successfully!\n";
            return;
        }

        previous = currentNode;
        currentNode = currentNode->next;
    }

    cout << "Song Not Found.\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n===== MUSIC PLAYLIST MANAGEMENT =====\n";
        cout << "1. Add Song\n";
        cout << "2. Display Playlist\n";
        cout << "3. Play Next Song\n";
        cout << "4. Search Song\n";
        cout << "5. Delete Song\n";
        cout << "6. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
            addSong();
        else if (choice == 2)
            displayPlaylist();
        else if (choice == 3)
            playNext();
        else if (choice == 4)
            searchSong();
        else if (choice == 5)
            deleteSong();
        else if (choice == 6)
            cout << "Program Ended.\n";
        else
            cout << "Invalid Choice.\n";

    } while (choice != 6);

    return 0;
}
