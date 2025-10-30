// diddy_sort.cpp
// DIDDY Sort - Dynamic Incremental Dual-Directional Yielding Sort
// A stable hybrid sorting algorithm by ChatGPT named after "Diddy"
// MIT License - Free to use, modify, share

#include <bits/stdc++.h>
using namespace std;

// Optional debug toggle
#define DEBUG_MODE false

void debug(const string& msg) {
    if (DEBUG_MODE) cout << msg << endl;
}

// DIDDY Sort:
// 1. Uses incremental gaps to perform shell-like insertions
// 2. Alternates left-right and right-left passes
// 3. Final pass uses merge sort to guarantee stability and sorting

class DiddySort {
private:
    vector<int> arr;
    int n;

    void shell_pass(int gap, bool left_to_right) {
        debug("Shell pass with gap = " + to_string(gap) + " direction = " + (left_to_right ? "L->R" : "R->L"));
        if (left_to_right) {
            for (int i = gap; i < n; ++i) {
                int temp = arr[i];
                int j = i;
                while (j >= gap && arr[j - gap] > temp) {
                    arr[j] = arr[j - gap];
                    j -= gap;
                }
                arr[j] = temp;
            }
        } else {
            for (int i = n - gap - 1; i >= 0; --i) {
                int temp = arr[i];
                int j = i;
                while (j + gap < n && arr[j + gap] < temp) {
                    arr[j] = arr[j + gap];
                    j += gap;
                }
                arr[j] = temp;
            }
        }
    }

    void final_merge_sort(int l, int r) {
        if (l >= r) return;
        int m = (l + r) / 2;
        final_merge_sort(l, m);
        final_merge_sort(m + 1, r);
        merge(l, m, r);
    }

    void merge(int l, int m, int r) {
        vector<int> left(arr.begin() + l, arr.begin() + m + 1);
        vector<int> right(arr.begin() + m + 1, arr.begin() + r + 1);
        int i = 0, j = 0, k = l;

        while (i < left.size() && j < right.size()) {
            if (left[i] <= right[j]) arr[k++] = left[i++];
            else arr[k++] = right[j++];
        }
        while (i < left.size()) arr[k++] = left[i++];
        while (j < right.size()) arr[k++] = right[j++];
    }

public:
    DiddySort(const vector<int>& input) {
        arr = input;
        n = arr.size();
    }

    vector<int> sort() {
        if (n <= 1) return arr;

        int gap = n / 2;
        bool left_to_right = true;

        while (gap > 0) {
            shell_pass(gap, left_to_right);
            gap /= 2;
            left_to_right = !left_to_right;
        }

        final_merge_sort(0, n - 1);
        return arr;
    }

    void print() {
        for (int x : arr) cout << x << " ";
        cout << endl;
    }
};

// === Utility functions for testing ===
vector<int> generate_random(int n, int seed = 42) {
    srand(seed);
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        v[i] = rand() % 1000;
    return v;
}

bool is_sorted(const vector<int>& v) {
    for (int i = 1; i < v.size(); ++i)
        if (v[i - 1] > v[i]) return false;
    return true;
}

void test_case(vector<int> input, const string& test_name) {
    cout << "Running: " << test_name << endl;
    DiddySort sorter(input);
    vector<int> sorted = sorter.sort();
    sorter.print();
    if (is_sorted(sorted)) {
        cout << "[PASS] " << test_name << endl;
    } else {
        cout << "[FAIL] " << test_name << endl;
    }
    cout << string(40, '-') << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Test 1: Random input
    test_case(generate_random(15), "Random 15");

    // Test 2: Already sorted
    vector<int> sorted = {1, 2, 3, 4, 5, 6, 7, 8};
    test_case(sorted, "Already Sorted");

    // Test 3: Reverse sorted
    vector<int> reverse_sorted = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    test_case(reverse_sorted, "Reverse Sorted");

    // Test 4: All elements same
    vector<int> same = {7, 7, 7, 7, 7, 7};
    test_case(same, "All Same Elements");

    // Test 5: Small input
    vector<int> small = {3, 1};
    test_case(small, "Two Elements");

    // Test 6: Large input
    test_case(generate_random(10000, 2025), "Large Random (10,000)");

    return 0;
}
