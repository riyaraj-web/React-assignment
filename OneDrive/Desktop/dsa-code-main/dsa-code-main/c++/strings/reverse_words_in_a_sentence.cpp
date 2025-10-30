#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);

    stringstream ss(sentence);
    string word;
    vector<string> words;

    while (ss >> word)
        words.push_back(word);

    reverse(words.begin(), words.end());

    cout << "Reversed sentence: ";
    for (size_t i = 0; i < words.size(); ++i) {
        cout << words[i];
        if (i != words.size() - 1) cout << " ";
    }
    cout << endl;
}
