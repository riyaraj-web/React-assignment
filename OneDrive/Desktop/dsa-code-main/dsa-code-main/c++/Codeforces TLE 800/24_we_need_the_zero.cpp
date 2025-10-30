#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int x = 0;

        if (n % 2 != 0) {
            for (int i = 0; i < n; i++) {
                x ^= arr[i];
            }
            cout << x << endl;
        } else {
            int temp = 0;
            for (int i = 0; i < n; i++) {
                temp ^= arr[i];
            }
            if (temp == 0) {
                cout << 3 << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }

    return 0;
}