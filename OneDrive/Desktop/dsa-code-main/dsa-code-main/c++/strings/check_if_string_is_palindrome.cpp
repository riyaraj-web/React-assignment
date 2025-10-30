#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s) {
    int left = 0, right = s.length() - 1;
    while (left < right) {
        if (s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    if (isPalindrome(s))
        cout << "Palindrome" << endl;
    else
        cout << "Not a Palindrome" << endl;
}
