#include <iostream>
using namespace std;

int main() {
    int size, key, choice;

    cout << "Enter hash table size: ";
    cin >> size;

    int hashTable[size];
    for (int i = 0; i < size; i++)
        hashTable[i] = -1;

    cout << "\nEnter elements one by one:\n";
    for (int i = 0; i < size; i++) {
        cout << "Enter key " << i + 1 << ": ";
        cin >> key;

        int index = key % size;
        int start = index;

        while (hashTable[index] != -1) {
            index = (index + 1) % size;
            if (index == start) {
                cout << "Hash table is full\n";
                break;
            }
        }

        if (hashTable[index] == -1)
            hashTable[index] = key;
    }

    do {
        cout << "\n1. Search";
        cout << "\n2. Display";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter key to search: ";
            cin >> key;

            int index = key % size;
            int start = index;
            bool found = false;

            while (hashTable[index] != -1) {
                if (hashTable[index] == key) {
                    cout << "Key found at index " << index << "\n";
                    found = true;
                    break;
                }
                index = (index + 1) % size;
                if (index == start)
                    break;
            }

            if (!found)
                cout << "Key not found\n";
        }
        else if (choice == 2) {
            cout << "\nHash Table:\n";
            for (int i = 0; i < size; i++)
                cout << i << " : " << hashTable[i] << "\n";
        }
        else if (choice == 3) {
            cout << "Exit\n";
        }
        else {
            cout << "Invalid choice\n";
        }
    } while (choice != 3);

    return 0;
}
