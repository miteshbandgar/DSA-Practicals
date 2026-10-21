#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Friend
{
    string name;
    string mobile;
};

int sentinelSearch(vector<Friend>& phoneBook, string key)
{
    int n = phoneBook.size();
    if (n == 0)
        return -1;

    phoneBook.push_back({key, ""});

    int i = 0;
    while (phoneBook[i].name != key)
    {
        i++;
    }

    phoneBook.pop_back();

    if (i < n)
        return i;
    return -1;
}

void insertFriend(vector<Friend>& phoneBook, Friend f)
{
    int pos = 0;
    while (pos < phoneBook.size() &&
           phoneBook[pos].name < f.name)
    {
        pos++;
    }
    phoneBook.insert(phoneBook.begin() + pos, f);
}

void sortPhoneBook(vector<Friend>& phoneBook)
{
    int n = phoneBook.size();

    for (int i = 1; i < n; i++)
    {
        Friend key = phoneBook[i];
        int j = i - 1;

        while (j >= 0 && phoneBook[j].name > key.name)
        {
            phoneBook[j + 1] = phoneBook[j];
            j--;
        }

        phoneBook[j + 1] = key;
    }

    cout << "\nPhone book sorted alphabetically!\n";
}

void deleteFriend(vector<Friend>& phoneBook)
{
    if (phoneBook.empty())
    {
        cout << "\nPhone book is empty. Nothing to delete.\n";
        return;
    }

    string name;
    cout << "\nEnter friend name to delete: ";
    cin >> name;

    int index = sentinelSearch(phoneBook, name);

    if (index == -1)
    {
        cout << "Friend not found. Nothing deleted.\n";
        return;
    }

    phoneBook.erase(phoneBook.begin() + index);
    cout << "Friend deleted successfully!\n";
}

void addFriend(vector<Friend>& phoneBook)
{
    Friend f;
    cout << "\nEnter friend name: ";
    cin >> f.name;

    int index = sentinelSearch(phoneBook, f.name);
    if (index != -1)
    {
        cout << "Friend already exists in the phone book!\n";
        return;
    }

    cout << "Enter mobile number: ";
    cin >> f.mobile;

    insertFriend(phoneBook, f);
    cout << "Friend added successfully!\n";
}

int main()
{
    vector<Friend> phoneBook;
    int choice;

    do
    {
        cout << "\n**PHONE BOOK MENU**\n";
        cout << "1. Add Friend\n";
        cout << "2. Search Friend\n";
        cout << "3. Display Phone Book\n";
        cout << "4. Sort Phone Book (A-Z)\n";
        cout << "5. Delete Friend\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            addFriend(phoneBook);
        }
        else if (choice == 2)
        {
            string name;
            cout << "\nEnter friend name to search: ";
            cin >> name;

            int index = sentinelSearch(phoneBook, name);

            if (index != -1)
            {
                cout << "\nFriend found!\n";
                cout << "Name : " << phoneBook[index].name << endl;
                cout << "Mobile : " << phoneBook[index].mobile << endl;
            }
            else
            {
                cout << "\nFriend not found.\n";
                char ch;
                cout << "Do you want to add this friend? (y/n): ";
                cin >> ch;

                if (ch == 'y' || ch == 'Y')
                {
                    Friend f;
                    f.name = name;
                    cout << "Enter mobile number: ";
                    cin >> f.mobile;
                    insertFriend(phoneBook, f);
                    cout << "Friend added successfully!\n";
                }
            }
        }
        else if (choice == 3)
        {
            if (phoneBook.empty())
            {
                cout << "\nPhone book is empty.\n";
            }
            else
            {
                cout << "\n===== PHONE BOOK =====\n";
                for (const Friend& f : phoneBook)
                {
                    cout << "Name : " << f.name << endl;
                    cout << "Mobile : " << f.mobile << endl;
                    cout << "----------------------\n";
                }
            }
        }
        else if (choice == 4)
        {
            sortPhoneBook(phoneBook);
        }
        else if (choice == 5)
        {
            deleteFriend(phoneBook);
        }
        else if (choice == 6)
        {
            cout << "\nExiting Phone Book. Goodbye!\n";
        }
        else
        {
            cout << "\nInvalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}
