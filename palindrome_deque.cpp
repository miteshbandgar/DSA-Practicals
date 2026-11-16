#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
    string str;
    deque<char> dq;

    cout << "Enter a string: ";
    cin >> str;

    for (int i = 0; i < str.length(); i++) {
        dq.push_back(str[i]);
    }

    bool palindrome = true;

    while (dq.size() > 1) {
        if (dq.front() != dq.back()) {
            palindrome = false;
            break;
        }
        dq.pop_front();
        dq.pop_back();
    }

    if (palindrome) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}
