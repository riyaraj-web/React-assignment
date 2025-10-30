#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;

        if (a + b >= n) {
            if (a == n && b == n) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        } else {
            if (n - a - b == 1) {
                cout << "No" << endl;

            } else {
                cout << "Yes" << endl;
            }
        }
    }

    return 0;
}