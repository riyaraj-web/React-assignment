package BuyAndSellStock2Onwards;

// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// Find the maximum profit you can achieve. You may complete at most two transactions.
// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

import java.util.Arrays;

public class BuyAndSellStock3 {
    public static void main(String[] args) {
        BuyAndSellStock3 bss = new BuyAndSellStock3();
        int[] a = {3,3,5,0,0,3,1,4};
        System.out.println(bss.maxProfit(a)); // Example usage
    }

    /**
     * Recursive helper function to calculate max profit.
     * @param i   Current day index
     * @param buy 1 if we can buy, 0 if we must sell
     * @param t   Number of completed transactions
     * @param a   Prices array
     * @param dp  Memoization table
     * @return    Maximum profit from day i with given state
     */
    private int f(int i, int buy, int t, int[] a, int[][][] dp) {
        // Base case: If we've reached the end or completed 2 transactions, no more profit can be made
        if(i >= a.length || t >= 2){
            return 0;
        }
        // Return cached result if already computed
        if(dp[i][buy][t] != -1){
            return dp[i][buy][t];
        }

        int profit = 0;
        if(buy == 1) {
            // Option 1: Buy at current day, move to next day with buy=0 (must sell next)
            // Option 2: Skip buying, move to next day with buy=1
            profit = Math.max(f(i+1,0,t,a,dp)-a[i], f(i+1,1,t,a,dp));
        }
        else{
            // Option 1: Sell at current day, increment transaction count, move to next day with buy=1
            // Option 2: Skip selling, move to next day with buy=0
            profit = Math.max(f(i+1,1,t+1,a,dp)+a[i], f(i+1,0,t,a,dp));
        }
        // Store result in dp table and return
        return dp[i][buy][t] = profit;
    }

    /**
     * Calculates the maximum profit with at most two transactions.
     * @param a Prices array
     * @return  Maximum profit
     */
    public int maxProfit(int[] a) {
        int n = a.length;
        // dp[i][buy][t]: Max profit at day i, buy/sell state, t transactions done
        int[][][] dp = new int[n][3][3];

        // Initialize dp table with -1 (uncomputed)
        for(int[][] r:dp){
            for(int[] rr:r){
                Arrays.fill(rr,-1);
            }
        }

        // Start from day 0, can buy, 0 transactions done
        return f(0,1,0,a,dp);
    }
}

