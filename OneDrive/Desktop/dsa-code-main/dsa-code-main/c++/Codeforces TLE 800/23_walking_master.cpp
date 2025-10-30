#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll t;
    cin >> t;

    while (t--) {
        ll a,b,c,d;

        cin >> a >> b >> c >> d;
        ll ans = 0;

        if( b > d) {
            cout << -1 << endl;
        }
        else {
            if((a + d - b) < c) {
                cout << -1 << endl;
            }
            else {
                cout << (2 * (d-b) + a - c) << endl;
            }
        }
    } 

    return 0;
}