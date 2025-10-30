#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

void solve(vector<int> &arr, int n) {

    int mini = 100000000;

    for(int i = 0; i<n; i++) {
        mini = min(abs(arr[i]), mini);
    }

    cout << mini << endl;
}

int main() {

    int n; 
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i<n; i++) {
        cin >> arr[i];
    }

    solve(arr, n);


    return 0;
}