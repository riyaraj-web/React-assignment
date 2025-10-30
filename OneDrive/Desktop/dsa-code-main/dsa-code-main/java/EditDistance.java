public class EditDistance {
    public static void main(String[] args) {
        String str1 = "intention";
        String str2 = "execution";

        int ans = editDistance(str1, str2);
        System.out.println("Min operations to convert str1 into str2 is: " + ans);
    }

    public static int editDistance(String str1, String str2) {
        int n1 = str1.length();
        int n2 = str2.length();

        int[][] dp = new int[n1+1][n2+1];

        for(int i=0;i<=n1;i++) dp[i][0] = i;
        for(int i=0;i<=n2;i++) dp[0][i] = i;

        for(int i=1;i<=n1;i++) {
            for(int j=1;j<=n2;j++) {
                int ch1 = str1.charAt(i-1);
                int ch2 = str2.charAt(j-1);

                if(ch1 == ch2) 
                    dp[i][j] = dp[i-1][j-1];
                else 
                    dp[i][j] = 1 + Math.min(dp[i-1][j-1], Math.min(dp[i-1][j], dp[i][j-1]));
                
            }
        }

        return dp[n1][n2];
    }
}
