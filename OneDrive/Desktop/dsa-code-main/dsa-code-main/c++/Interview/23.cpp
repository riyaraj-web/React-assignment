#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> // For std::max

using namespace std;

/*
Problem: Merge Intervals
Technique: Sorting + Iteration (Greedy approach)
Time Complexity: O(N log N) dominated by the initial sort
Space Complexity: O(N) (for the output list)

Description:
Given an array of intervals where intervals[i] = [start_i, end_i], merge all 
overlapping intervals, and return an array of the non-overlapping intervals that 
cover all the intervals in the input.
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return {};
        }

        // =======================================================
        // Step 1: Sort the intervals based on their start time.
        // This is the crucial step that makes the linear merge possible.
        // O(N log N)
        // =======================================================
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        // Initialize the result list with the first interval.
        vector<vector<int>> merged;
        merged.push_back(intervals[0]);

        // =======================================================
        // Step 2: Iterate and Merge
        // O(N)
        // =======================================================
        for (int i = 1; i < intervals.size(); ++i) {
            // Get the last merged interval in the result list.
            vector<int>& lastMerged = merged.back();
            
            // Get the current interval being examined.
            const vector<int>& current = intervals[i];

            // Check for Overlap:
            // An overlap exists if the current interval's start time is less than or 
            // equal to the end time of the last merged interval.
            if (current[0] <= lastMerged[1]) {
                // Merge operation:
                // Update the end time of the last merged interval to be the maximum
                // of its current end time and the current interval's end time.
                lastMerged[1] = max(lastMerged[1], current[1]);
            } else {
                // No overlap:
                // The current interval does not overlap with the previous merged one,
                // so we start a new merged interval.
                merged.push_back(current);
            }
        }

        return merged;
    }
};

// Test cases
void printIntervals(const vector<vector<int>>& intervals) {
    cout << "[";
    for (size_t i = 0; i < intervals.size(); ++i) {
        cout << "[" << intervals[i][0] << ", " << intervals[i][1] << "]" 
             << (i == intervals.size() - 1 ? "" : ", ");
    }
    cout << "]";
}

int main() {
    Solution solution;
    
    // Test 1: Merging multiple
    vector<vector<int>> intervals1 = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> result1 = solution.merge(intervals1); // Expected: [[1, 6], [8, 10], [15, 18]]
    cout << "Test 1: ";
    printIntervals(result1);
    cout << " (Expected: [[1, 6], [8, 10], [15, 18]])" << endl;

    // Test 2: Complete overlap
    vector<vector<int>> intervals2 = {{1, 4}, {4, 5}};
    vector<vector<int>> result2 = solution.merge(intervals2); // Expected: [[1, 5]]
    cout << "Test 2: ";
    printIntervals(result2);
    cout << " (Expected: [[1, 5]])" << endl;
    
    // Test 3: Unsorted intervals
    vector<vector<int>> intervals3 = {{1, 4}, {0, 0}};
    vector<vector<int>> result3 = solution.merge(intervals3); // Expected: [[0, 0], [1, 4]]
    cout << "Test 3: ";
    printIntervals(result3);
    cout << " (Expected: [[0, 0], [1, 4]])" << endl;

    return 0;
}