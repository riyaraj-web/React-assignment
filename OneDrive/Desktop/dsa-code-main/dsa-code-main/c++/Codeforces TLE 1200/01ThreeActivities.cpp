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

vector<int> findMax3(vector<int> &arr) {
    vector<pair<int, int>> tmp(arr.size());

    for(int i = 0; i < tmp.size(); i++) { //? (val, ind)
        tmp[i].first = arr[i];
        tmp[i].second = i;
    }

    sort(tmp.rbegin(), tmp.rend()); //* O(N log N)

    vector<int> ans(3);

    for(int i = 0; i < 3; i++) ans[i] = tmp[i].second;

    return ans;
}

void solve() {

    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    // unordered_map<int,int>

    

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    vector<int> maxa = findMax3(a); //* O(N log N)
    vector<int> maxb = findMax3(b);
    vector<int> maxc = findMax3(c);

    int ans = 0;

    for(int i = 0; i<3; i++) {
        for(int j = 0; j<3; j++) {
            for(int k = 0; k < 3; k++) {
                int x = maxa[i];
                int y = maxb[j];
                int z = maxc[k];

                if((x == y) || (y == z) || (z == x)) continue;

                ans = max(ans, a[x] + b[y] + c[z]);
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


// (1,0) (3,7) (8,5) (10,3) (12,9) (13,8) (15,4) (17,1) (17,6) (18,2)
