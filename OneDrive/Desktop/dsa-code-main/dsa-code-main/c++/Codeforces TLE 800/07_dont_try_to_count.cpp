#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;

void solve(string x, string s) {
    
    bool found = false;
    for(int ops = 0; ops<= 5; ops ++) {
        //0,1,2,3,4,5

        if(x.find(s) != string::npos) {
            cout << ops << endl;
            found = true;
            break;
        }
        x.append(x);
    }

    if(!found) {
        cout << -1 << endl;
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        string x, s;

        cin >> x >> s;

        solve(x, s);
    }
    return 0;
}