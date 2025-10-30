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
// void solve() {

//     int n , s;
//     cin >> n >> s;

//     vector<int> a(n);

//     for(int i = 0; i<n; i++) {
//         cin >> a[i];
//     }

//     deque<int> ones;

//     int sum = 0;

//     for(int i = 0; i<n; i++) {
//         if(a[i] == 1) {
//             sum ++;
//             ones.pb(i);
//         }
//     }

//     if(sum < s) {
//         cout << -1 << endl;
//         return;
//     }
//     if(sum == s ) {
//         cout << 0 << endl;
//         return;    
//     }

//     int ops = 0;

//     int i = 0, j= n-1;

//     while(i<j && sum > s && !ones.empty()) {
//         if(a[i] == 1){
//             i++;
//             sum--;
//             ones.pop_front();
//             ops++;
//         }
//         else if(a[j] == 1) {
//             j--;
//             sum--;
//             ones.pop_back();
//             ops++;
//         }
//         else  {
//             int frontdiff = abs(ones.front() - i);
//             int backdiff = abs(ones.back() - j);
//             if(frontdiff < backdiff) {
//                 i++;
//                 ops++;
//                 // ones.pop_front();
//             }
//             else {
//                 j--;
//                 ops++;
//                 // ones.pop_back();
//             }
//         }
//     }

//     cout << ops << endl;

// }


void solve() {
    int n , s;
    cin >> n >> s;

    vector<int> a(n);
    int ones = 0;
    for(int i = 0; i<n; i++) {
        cin >> a[i];
        if(a[i] == 1) {
            ones++;
        }
    }

    if(ones < s) {
        cout << -1 << endl;
        return;
    }
    if(ones == s) {
        cout << 0 << endl;
        return;
    }

    int currOne = 0;
    int maxi = 0,  l = 0;

    for(int i = 0 ; i<n; i++) {
        if(a[i] == 1) {
            currOne++;
        }

        while( currOne > s) {
            if(a[l] == 1) {
                currOne--;
            }
            l++;
        }

        if(currOne == s) {
            maxi = max(maxi, i - l + 1);
        } 

    }

    cout << n - maxi << endl;

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