#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int gcd(int a , int b) {
    while(b!= 0) {
        int temp = b; 
        b = a %b;
        a = temp;
    }
    return a;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);

        for(int i = 0; i<n; i++) {
            cin >> arr[i];
        }

        bool yes = false;

        for(int i = 0; i<n; i++) {
            for(int j = i; j<n; j++) {
                if(gcd(arr[i], arr[j]) <= 2) {
                    yes = true;
                    break;
                }
            }
        }

        if(yes) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;

        }
    }

    return 0;
}