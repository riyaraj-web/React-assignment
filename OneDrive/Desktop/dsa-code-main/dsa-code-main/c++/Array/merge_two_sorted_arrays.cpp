#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    vector<int> v3;
    int left = 0, right = 0;

    while (left < m && right < n) {
        if (nums1[left] < nums2[right]) {
            v3.push_back(nums1[left]);
            left++;
        } else {
            v3.push_back(nums2[right]);
            right++;
        }
    }

    while (left < m) {
        v3.push_back(nums1[left]);
        left++;
    }

    while (right < n) {
        v3.push_back(nums2[right]);
        right++;
    }

    nums1 = v3;

    for (int x : nums1) cout << x << " ";
}

int main()
{
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {2, 5, 6};
    merge(nums1, nums1.size(), nums2, nums2.size());
    return 0;
}
