package BuyAndSellStock2Onwards;

// You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.
// Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.
//
// Note:
// You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
// The transaction fee is only charged once for each stock purchase and sale.
//
// Example 1:
// Input: prices = [1,3,2,8,4,9], fee = 2
// Output: 8
// Explanation: The maximum profit can be achieved by:
// - Buying at prices[0] = 1
// - Selling at prices[3] = 8
// - Buying at prices[4] = 4
// - Selling at prices[5] = 9
// The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
//
// Example 2:
// Input: prices = [1,3,7,5,10,3], fee = 3
// Output: 6

import java.util.Arrays;

public class BestTimeToBuyAndSellStockWithTransactionFee {
    public static void main(String[] args) {
        BestTimeToBuyAndSellStockWithTransactionFee bss = new BestTimeToBuyAndSellStockWithTransactionFee();
        int[] a = {1,3,2,8,4,9};
        int fee = 2;
        System.out.println(bss.maxProfit(a,fee));
    }

    /**
     * Recursive helper function to calculate max profit with transaction fee.
     * @param i   Current day index
     * @param buy 1 if we can buy, 0 if we must sell
     * @param fee Transaction fee per transaction
     * @param a   Prices array
     * @param dp  Memoization table
     * @return    Maximum profit from day i with given state
     */
    private int f(int i, int buy, int fee, int[] a, int[][] dp) {
        // Base case: If we've reached the end, no more profit can be made
        if(i>=a.length){
            return 0;
        }
        // Return cached result if already computed
        if(dp[i][buy] != -1){
            return dp[i][buy];
        }

        int profit = 0;
        if(buy == 1) {
            // Option 1: Buy at current day, move to next day with buy=0 (must sell next)
            // Option 2: Skip buying, move to next day with buy=1 (still can buy)
            profit = Math.max(f(i+1,0,fee,a,dp)-a[i] , f(i+1,1,fee,a,dp));
        }
        else {
            // Option 1: Sell at current day, pay fee, move to next day with buy=1 (can buy again)
            // Option 2: Skip selling, move to next day with buy=0 (still holding)
            profit = Math.max(f(i+1,1,fee,a,dp)+a[i]-fee , f(i+1,0,fee,a,dp));
        }
        // Store result in dp table and return
        return dp[i][buy] = profit;
    }

    /**
     * Calculates the maximum profit with unlimited transactions and a transaction fee.
     * @param a   Prices array
     * @param fee Transaction fee per transaction
     * @return    Maximum profit
     */
    public int maxProfit(int[] a, int fee) {
        int n = a.length;
        // dp[i][buy]: Max profit at day i, buy/sell state
        int[][] dp = new int[n+1][3];
        // Initialize dp table with -1 (uncomputed)
        for(int[] r : dp){
            Arrays.fill(r,-1);
        }
        // Start from day 0, can buy
        return f(0,1,fee,a,dp);
    }
}

