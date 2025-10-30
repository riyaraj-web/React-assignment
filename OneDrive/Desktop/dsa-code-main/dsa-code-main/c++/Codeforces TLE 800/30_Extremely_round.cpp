#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    int t;
    cin >> t;

    while(t--) {
        string s;
        cin >> s;

        int n = s.size();

        int first = s[0] - '0';

        int ans = (n-1) * 9 + first;

        cout << ans << endl;
    }

    return 0;
}