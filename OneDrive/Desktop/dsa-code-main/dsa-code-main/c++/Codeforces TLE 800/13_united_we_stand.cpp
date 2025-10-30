#include <iostream>
#include <vector>
#include <map>
using namespace std;

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

        map<int, int> mp;
        for (auto x : arr) {
            mp[x]++;
        }

        if (mp.size() == 1) {
            cout << -1 << endl;
        } else {
            auto it = mp.begin();  // First element
            int ele = it->first;
            int fre = it->second;

            cout << fre << " " << (n - fre) << endl;

            for (int i = 0; i < fre; i++) {
                cout << ele << " ";
            }
            cout << endl;

            for (auto it = next(mp.begin()); it != mp.end(); ++it) {
                for (int i = 0; i < it->second; i++) {
                    cout << it->first << " ";
                }
            }
            cout << endl;
        }
    }

    return 0;
}
