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
void printArray(const vector<T> &arr) {
    for (auto &x : arr) cout << x << ' ';
    cout << endl;
}

// ---------- Unique Elements (Maintain Order) ----------
template <typename T>
vector<T> uniqueElements(const vector<T> &arr) {
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

    vector<vector<char>> vec(n, vector<char>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> vec[i][j];
        }
    }

    vector<vector<bool>> marked(n, vector<bool>(n, false));
    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int cnt0 = 0, cnt1 = 0;

            // i,j
            if (vec[i][j] == '0') {
                cnt0++;
                marked[i][j] = true;
            } else {
                cnt1++;
                marked[i][j] = true;
            }
            // j,n-1-i
            if (vec[j][n - 1 - i] == '0') {
                cnt0++;
                marked[j][n - 1 - i] = true;
            } else {
                cnt1++;
                marked[j][n - 1 - i] = true;
            }
            // n-1-i,n-1-j
            if (vec[n - 1 - i][n - 1 - j] == '0') {
                cnt0++;
                marked[n - 1 - i][n - 1 - j] = true;
            } else {
                cnt1++;
                marked[n - 1 - i][n - 1 - j] = true;
            }
            // n-1-j,i
            if (vec[n - 1 - j][i] == '0') {
                cnt0++;
                marked[n - 1 - j][i] = true;
            } else {
                cnt1++;
                marked[n - 1 - j][i] = true;
            }
            if (cnt0 >= cnt1) {
                ans += cnt1;
                vec[i][j] = '0';
                vec[j][n - i - 1] = '0';
                vec[n - i - 1][n - j - 1] = '0';
                vec[n - j - 1][i] = '0';
            } else {
                ans += cnt0;
                vec[i][j] = '1';
                vec[j][n - i - 1] = '1';
                vec[n - i - 1][n - j - 1] = '1';
                vec[n - j - 1][i] = '1';
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