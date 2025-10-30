#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        int one = 0, two = 0;

        for(int i = 0; i<n; i++) {
            cin >> arr[i];

            if(arr[i] == 2) {
                two ++;
            }

        }

        if(two % 2 == 1) {
            cout << -1 << endl;
            continue;
        }

        int currcount = 0;
        int index = -1;

        for(int i = 0; i<n; i++) {
            if(arr[i] ==2) {
                currcount++;
            }
            if(currcount == two / 2) {
                index = i;
                break;
            }

        }

        cout << index + 1 << endl;



        // bool f = false;

        // int r_cnt = count(arr.begin(), arr.end(), 2);
        // int l_cnt = 0;

        // for(int k = 0; k<n; k++) {
        //     if(arr[k] == 2) {
        //         l_cnt++;
        //         r_cnt--;
        //     }

        //     if(l_cnt == r_cnt) {
        //         cout << k << endl;
        //         f = true;
        //         break;
        //     }
        // }

        // if(!f) cout << -1 << endl;
    }

    return 0;
}