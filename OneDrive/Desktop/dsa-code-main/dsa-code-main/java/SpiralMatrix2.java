public class SpiralMatrix2 {
    public static void printspiral(int matrix[][]){
        int startrow=0,startcolumn =0,endrow=matrix.length-1,endcoloumn=matrix[0].length-1;

        while(startrow<= endrow && startcolumn<=endcoloumn){
           for(int j=startcolumn;j<=endcoloumn;j++) {
            System.out.print(matrix[startrow][j]+" ");
           }
           for(int i=startrow+1;i<=endrow;i++){
            System.out.print(matrix[i][endcoloumn]+" ");
           }
           for(int j=endcoloumn-1;j>=startcolumn;j--){
             if(startrow==endrow){
                break;
            }
            System.out.print(matrix[endrow][j]+" ");
           }
           for(int i=endrow-1;i>=startrow+1;i--){
            if(startcolumn==endcoloumn){
                break;
            }
            
            System.out.print(matrix[i][startcolumn]+" ");
           }
           startcolumn++;
           startrow++;
           endcoloumn--;
           endrow--;
        }
        System.out.println();
    }
    public static void main(String[] args) {
        int matrix[][] ={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
        printspiral(matrix);

    }
}
