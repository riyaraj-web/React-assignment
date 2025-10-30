 #include <bits/stdc++.h>
#define ll long long int
using namespace std;

int maxArea(vector<int>& height) {
    int n = height.size();
    int l = 0, r = n - 1;
    int maxarea = 0;

    while (l < r) {
        int dis = r - l;
        int h = min(height[l], height[r]);
        maxarea = max(maxarea, dis * h);

        if (height[l] < height[r]) {
            l++;
        } else {
            r--;
        }
    }
    return maxarea;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> height(n);
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    cout << maxArea(height) << "\n";

    return 0;
}
