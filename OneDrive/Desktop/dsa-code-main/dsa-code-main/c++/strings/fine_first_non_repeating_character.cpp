#include <iostream>
#include <string>
using namespace std;

char firstNonRepeatingChar(string s) {
    int freq[256] = {0};

    for (char c : s)
        freq[(unsigned char)c]++;

    for (char c : s)
        if (freq[(unsigned char)c] == 1)
            return c;

    return '\0';
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    char result = firstNonRepeatingChar(s);
    if (result)
        cout << "First non-repeating character: " << result << endl;
    else
        cout << "No unique character found." << endl;
}
