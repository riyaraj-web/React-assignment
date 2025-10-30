#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;

        if (c % 2 == 0) {
            if (a > b) {
                cout << "First" << endl;
            } else {
                cout << "Second" << endl;
            }
        } else {
            if (a + 1 > b) {
                cout << "First" << endl;
            } else {
                cout << "Second" << endl;
            }
        }
    }
    return 0;
}