#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool areAnagrams(string s1, string s2) {
    if (s1.length() != s2.length()) return false;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
}

int main() {
    string s1, s2;
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;

    if (areAnagrams(s1, s2))
        cout << "Strings are Anagrams." << endl;
    else
        cout << "Strings are NOT Anagrams." << endl;
}
