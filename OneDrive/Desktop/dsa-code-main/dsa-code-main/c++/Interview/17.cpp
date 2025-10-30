#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

/*
Problem: Best Time to Buy and Sell Stock
Technique: Greedy (Tracking Minimum Price)
Time Complexity: O(N)
Space Complexity: O(1)

Description:
Given an array prices where prices[i] is the price of a given stock on the i-th day. 
You want to maximize your profit by choosing a single day to buy one stock and 
choosing a different day in the future to sell that stock. 
Return the maximum profit you can achieve from this transaction. 
If you cannot achieve any profit, return 0.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        // 'minPrice' tracks the lowest stock price encountered so far up to the current day.
        // Initialize it to a very large value (or the first price).
        int minPrice = INT_MAX; 
        
        // 'maxProfit' tracks the maximum profit achieved so far.
        int maxProfit = 0;
        
        // Iterate through all the stock prices (days).
        for (int price : prices) {
            
            // 1. Update the minimum price (The BUY action):
            // The minimum price is the cheapest point we could have bought the stock
            // before or on the current day.
            minPrice = min(minPrice, price);
            
            // 2. Calculate potential profit and update the maximum (The SELL action):
            // The potential profit on the current day is the current price minus 
            // the minimum price recorded so far.
            int currentProfit = price - minPrice;
            
            // Update the overall maximum profit.
            maxProfit = max(maxProfit, currentProfit);
        }

        return maxProfit;
    }
};

// Test cases
int main() {
    Solution solution;
    
    // Test 1: Max profit possible
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    int result1 = solution.maxProfit(prices1); // Expected: 5 (Buy at 1, Sell at 6)
    cout << "Test 1: Max Profit = " << result1 << " (Expected: 5)" << endl;

    // Test 2: No profit possible (prices are decreasing)
    vector<int> prices2 = {7, 6, 4, 3, 1};
    int result2 = solution.maxProfit(prices2); // Expected: 0
    cout << "Test 2: Max Profit = " << result2 << " (Expected: 0)" << endl;
    
    // Test 3: Upward trend
    vector<int> prices3 = {1, 2, 3, 4, 5};
    int result3 = solution.maxProfit(prices3); // Expected: 4 (Buy at 1, Sell at 5)
    cout << "Test 3: Max Profit = " << result3 << " (Expected: 4)" << endl;

    return 0;
}