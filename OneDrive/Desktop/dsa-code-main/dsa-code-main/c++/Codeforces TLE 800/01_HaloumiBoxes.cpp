// There is a road, which can be represented as a number line. You are located
// in the point 0
//  of the number line, and you want to travel from the point 0
//  to the point x
// , and back to the point 0
// .

// You travel by car, which spends 1
//  liter of gasoline per 1
//  unit of distance travelled. When you start at the point 0
// , your car is fully fueled (its gas tank contains the maximum possible amount
// of fuel).

// There are n gas stations, located in points a1,a2,…,an
// When you arrive at a gas station, you fully refuel your car. Note that you
// can refuel only at gas stations, and there are no gas stations in points 0
//  and

// You have to calculate the minimum possible volume of the gas tank in your car
// (in liters) that will allow you to travel from the point 0
//  to the point x
//  and back to the point 0
// .

#include <iostream>
#include <vector>

using namespace std;

bool isSorted(vector<int> &arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            return false;  // If any element is smaller than the previous, not
                           // sorted
        }
    }
    return true;  // If no issues found, return true
}

void solve(vector<int> &arr, int k) {
    if (k == 1 && isSorted(arr)) {
        cout << "YES" << endl;
    } else if (k > 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    int cases;
    cin >> cases;

    while (cases--) {
        int n, k;
        cin >> n >> k;

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        solve(arr, k);
    }

    return 0;
}
