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


// ---------- Unique Elements (Maintain Order) ----------
template <typename T>
vector<T> uniqueElements(const vector<T>& arr) {
    vector<T> result;
    unordered_set<T> seen;
    for (const T &x : arr) {
        if (seen.find(x) == seen.end()) {
            result.pb(x);
            seen.insert(x);
        }
    }
    return result;
}
 // unique find using stl  a.resize(unique(a.begin(), a.end()) - a.begin());


// ---------- Solve Function ----------
void solve() {

    int n;
    cin >> n;
    string t;
    cin >> t;

    int ans = 0;
    string marked(n,1);

    for(int i = 0; i<n; i++) {
        if(t[i] == '0') {
            int idx = i + 1;
            for(int j = idx; j <=n; j+= idx) {
                if(t[j-1] == '1') {
                    break;
                }
                if(marked[j-1] == '0') {
                    continue;
                }
                marked[j-1] = '0';
                ans+= idx;
            }
        }
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