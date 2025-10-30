#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

void solve (int n) {

    if(n % 3 == 0) {
        cout << "Second" <<endl;
    }
    else {
        cout << "First" <<endl;

    }

}


int main() {

    int t;
    cin >> t;

    while(t--) {

        int n;
        cin >> n;

        solve(n);
    }

    return 0;
}