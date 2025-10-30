// You are given an array prices where prices[i] is the price of a given stock on the ith day.
//
// Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:
//
// After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
//
// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
// Example 1:
// Input: prices = [1,2,3,0,2]
// Output: 3
// Explanation: transactions = [buy, sell, cooldown, buy, sell]
//
// Example 2:
// Input: prices = [1]
// Output: 0

package BuyAndSellStock2Onwards;
import java.util.Arrays;

public class BestTimeToBuyAndSellStockWithCooldown {
    public static void main(String[] args) {
        BestTimeToBuyAndSellStockWithCooldown bss = new BestTimeToBuyAndSellStockWithCooldown();
        int[] a = {1,2,3,0,2};
        System.out.println(bss.maxProfit(a)); // Example usage
    }

    /**
     * Recursive helper function to calculate max profit with cooldown.
     * @param i   Current day index
     * @param buy 1 if we can buy, 0 if we must sell
     * @param a   Prices array
     * @param dp  Memoization table
     * @return    Maximum profit from day i with given state
     */
    private int f(int i, int buy, int[] a, int[][] dp) {
        // Base case: If we've reached the end, no more profit can be made
        if(i >= a.length){
            return 0;
        }
        // Return cached result if already computed
        if(dp[i][buy] != -1){
            return dp[i][buy];
        }
        int profit = 0;
        if(buy == 1){
            // Option 1: Buy at current day, move to next day with buy=0 (must sell next)
            // Option 2: Skip buying, move to next day with buy=1 (still can buy)
            profit = Math.max(f(i+1,0,a,dp)-a[i], f(i+1,1,a,dp));
        }
        else{
            // Option 1: Sell at current day, move to day after next (cooldown), can buy again
            // Option 2: Skip selling, move to next day with buy=0 (still holding)
            profit = Math.max(f(i+2, 1, a, dp) + a[i], f(i+1,0,a,dp));
        }
        // Store result in dp table and return
        return dp[i][buy] = profit;
    }

    /**
     * Calculates the maximum profit with cooldown after selling.
     * @param a Prices array
     * @return  Maximum profit
     */
    public int maxProfit(int[] a) {
        int n = a.length;
        // dp[i][buy]: Max profit at day i, buy/sell state
        int[][] dp = new int[n+1][3];

        // Initialize dp table with -1 (uncomputed)
        for(int[] r: dp) {
            Arrays.fill(r,-1);
        }

        // Start from day 0, can buy
        return f(0,1,a,dp);
    }
}
