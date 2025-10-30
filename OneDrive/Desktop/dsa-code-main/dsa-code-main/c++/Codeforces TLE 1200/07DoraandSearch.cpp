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

    vector<int> a(n);

    for(int i = 0; i<n; i++) {
        cin >> a[i];
    }

    int mini = 1, maxi = n;
    int i = 0, j = n-1;
    bool found = false;

    while( i < j) {
        if((a[i] == mini && a[j] == maxi) || (a[i] == maxi && a[j] == mini)) {
            i++;
            j--;
            mini++;
            maxi--;
        }
        else if(a[i] == mini || a[i] == maxi) {
            if(a[i] == maxi) {
                maxi--;
            }
            else {
                mini++;
            }
            i++;
        }
        else if(a[j] == maxi || a[j] == mini) {
            if(a[j] == maxi) {
                maxi--;
            }
            else {
                mini++;
            }
            j--;
        }
        else {
            // cout << i+1 << " " << j+1 << endl;
            found = true;
            break;
        }
    }
    if(found) {
        cout << i+1 << " " << j+1 << endl;
    }
    else {
        cout << -1 << endl;
    }
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