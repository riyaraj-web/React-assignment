/*--------------------------------------------------------------------------*\
|    ██████╗  █████╗ ██╗    ██╗ █████╗ ███╗   ██╗██████╗  █████╗ ██████╗    |
|    ██╔══██╗██╔══██╗██║    ██║██╔══██╗████╗  ██║██╔══██╗██╔══██╗██╔══██╗   |
|    ██████╔╝███████║██║ █╗ ██║███████║██╔██╗ ██║██║  ██║███████║██████╔╝   |
|    ██╔══██╗██╔══██║██║███╗██║██╔══██║██║╚██╗██║██║  ██║██╔══██║██╔══██╗   |
|    ██████╔╝██║  ██║╚███╔███╔╝██║  ██║██║ ╚████║██████╔╝██║  ██║██║  ██║   |
|    ╚═════╝ ╚═╝  ╚═╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝  ╚═══╝╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝   |
|                      .....                   .....                        |
|                 . ´           ` ·.::::::.· ´          ` .                 |
|              .´   .:::@:::::)   :::::   (:::::@:::.  `.                   |
|             :   (::´            .:::::::.            `::)  :              |
|           .::`...        .....:::::::::::::....        ...´::.            |
|        .::::::::::::::::::::::::::::::::::::::::::::::::::::::::.         |
|     .:::/::::::::::::::::::::::::::::::::::::::::::::::::::::::\:::.      |
|    ::(--\::::::::::::::::::::::::::::::::::::::::::::::::::::::/--)::     |
|     `.:::::.``··::::::::::::::::::::::::::::::::::::::::··´´.:::::.´      |
|       `·:::::.         ``··::::::::::::::::::::··´´       .:::::·´        |
|          `·:::::.            `.           .´           .:::::·´           |
|              `·:::::.           `  ···· ´           .:::::·´              |
|                  `·:::::.                       .:::::·´                  |
|                  .::::`·:::::..            ..:::::·´::::.                 |
|              .:::::::::::::``·:::::::::::::·´´:::::::::::::.              |
|           .:::::::·´.::::::::::`::::::::´:::::::::::.`·:::::::.           |
|        ·´´´´´    .:::::::::·´`·:::::::::::·´`·::::::::.    `````·         |
|               .::::::·´         `·:::::·´        `·::::::.                |
|            ·´´´´´                  `·´                `````·              |
\*--------------------------------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

// ---------- Shortcuts ----------
#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define endl '\n'

// ---------- Constants ----------
const int MOD = 1e9 + 7;
const int INF = 1e18;

// ---------- Fast I/O ----------
void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

// ---------- Utility Functions ----------
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;  // avoid overflow
}

template <typename T>
void printArray(const vector<T>& arr) {
    for (auto &x : arr) cout << x << ' ';
    cout << endl;
}


// ---------- Solve Function ----------
void solve() {

    int n , k;
    cin >> n >> k;

    vector<int> a(n);
    map<int, vector<int>> mp;

    for(int i = 1; i<=k ;i++) {
        mp[i].pb(0);
    }
    
    for(int i = 0; i<n; i++) {
        cin >> a[i];
        mp[a[i]].pb(i+1);
    }
    for(int i = 1; i<=k ;i++) {
        mp[i].pb(n+1);
    }

    int ans = INT_MAX;

    for(auto &it: mp) {
        int val = it.first;
        vector<int>&arr = it.second;

        priority_queue<int> jumps;

        for(int i = 1; i<arr.size(); i++) {
            jumps.push(arr[i] - arr[i-1] - 1);
        }

        int maxi = jumps.top();
        jumps.pop();

        if(maxi % 2 == 0) {
            jumps.push(maxi/2);
            jumps.push((maxi/2) - 1);
        }
        else {
            jumps.push(maxi/2);
            jumps.push(maxi/2);
        }

        ans = min(ans, jumps.top());

    }

    cout << ans << endl;

}

// ---------- Main ----------
int32_t main() {
    fast_io();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}