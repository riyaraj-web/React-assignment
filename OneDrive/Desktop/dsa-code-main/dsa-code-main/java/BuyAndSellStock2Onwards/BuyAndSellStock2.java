package BuyAndSellStock2Onwards;

// You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
//
// On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time.
// However, you can sell and buy the stock multiple times on the same day, ensuring you never hold more than one share of the stock.
//
// Find and return the maximum profit you can achieve.
//
// Example 1:
// Input: prices = [7,1,5,3,6,4]
// Output: 7
// Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
// Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
// Total profit is 4 + 3 = 7.

import java.util.Arrays;

class BuyAndSellStock2 {
    public static void main(String[] args) {
        BuyAndSellStock2 bss = new BuyAndSellStock2();
        int[] a = {7,1,5,3,6,4};
        System.out.println(bss.maxProfit(a)); // Example usage
    }

    /**
     * Recursive helper function to calculate max profit.
     * @param i   Current day index
     * @param buy 1 if we can sell (currently holding), 0 if we can buy (not holding)
     * @param a   Prices array
     * @param dp  Memoization table
     * @return    Maximum profit from day i with given state
     */
    private int f(int i, int buy, int[] a, int[][] dp) {
        // Base case: If we've reached the end, no more profit can be made
        if(i == a.length){
            return 0;
        }
        // Return cached result if already computed
        if(dp[i][buy] != -1){
            return dp[i][buy];
        }

        int profit = 0;
        if(buy == 1) {
            // Option 1: Sell at current day, move to next day with buy=0 (can buy again)
            // Option 2: Skip selling, move to next day with buy=1 (still holding)
            profit = Math.max(f(i+1,0,a,dp)+a[i], f(i+1,1,a,dp));
        }
        else{
            // Option 1: Buy at current day, move to next day with buy=1 (must sell next)
            // Option 2: Skip buying, move to next day with buy=0 (still not holding)
            profit = Math.max(f(i+1,1,a,dp)-a[i], f(i+1,0,a,dp));
        }
        // Store result in dp table and return
        return dp[i][buy] = profit;
    }

    /**
     * Calculates the maximum profit with unlimited transactions.
     * @param a Prices array
     * @return  Maximum profit
     */
    public int maxProfit(int[] a) {
        int n = a.length;
        // dp[i][buy]: Max profit at day i, buy/sell state
        int[][] dp = new int[n][3];

        // Initialize dp table with -1 (uncomputed)
        for(int[] r:dp){
            Arrays.fill(r,-1);
        }

        // Start from day 0, not holding any stock (can buy)
        return f(0,0,a,dp);
    }
}
