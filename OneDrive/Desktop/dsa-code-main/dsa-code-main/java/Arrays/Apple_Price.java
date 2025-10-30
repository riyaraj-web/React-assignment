package Arrays;

import java.util.Arrays;

public class Apple_Price {

    public static void name() {
        int prices[] = {3, 5, 8, 10};
        int demands[] = {1, 6, 10};

        int m=prices.length;
        int n=demands.length;



        Arrays.sort(prices);

        boolean used[]=new boolean[m];
        int result[]=new int[n];

        for (int i = 0; i < n; i++) {
            int demand=demands[i];

            int choosen=-1;

            for (int j = m-1;j>=0; j--) {

                if (!used[j] && prices[j]<=demand) {

                    choosen=prices[j];
                    used[j]=true;
                    break;

                }
            }
            result[i]=choosen;

        }


        for (int i = 0; i < result.length; i++) {

            System.out.print(result[i]+" ");
        }


    }




    public static void main(String[] args) {


        int prices[] = {3, 5, 8, 10};
        int demands[] = {1, 6, 10};

        int m = prices.length;
        int n = demands.length;


        Arrays.sort(prices);

        boolean used[] = new boolean[m]; // Track whether apple at index j is sold
        int results[] = new int[n];      // Output results for each customer

        for (int i = 0; i < n; i++) {
            int demand = demands[i];
            int chosen = -1;

            // Loop through prices from high to low (right to left)
            for (int j = m - 1; j >= 0; j--) {
                if (!used[j] && prices[j] <= demand) {
                    chosen = prices[j];
                    used[j] = true; // Mark this apple as sold
                    break;
                }
            }
            results[i] = chosen;
        }

        // Print the result
        for (int i = 0; i < n; i++) {
            System.out.print(results[i] + " ");
        }
    }


}
