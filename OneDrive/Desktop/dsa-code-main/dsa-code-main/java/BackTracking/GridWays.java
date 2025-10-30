public class GridWays{
    public static void main(String args[]){
        int n=10, m=10;
        int i=0, j=0;

        System.out.println(gridways(m, n, i, j));
    }

    public static int gridways(int m, int n, int i, int j){

        // base case
        if(i == n-1 && j==m-1){     // last case condition (cell at the boundary / last cell )
            return 1;
        } else if( i == n || j == m){           // if cell exceeds boundary    
            return 0;
        }

        // 2 cases only exists

        // 1. go right
        int w1_right = gridways(m,n,i+1, j);
        int w2_down = gridways(m, n, i, j+1);
        return w1_right + w2_down;
    }
}