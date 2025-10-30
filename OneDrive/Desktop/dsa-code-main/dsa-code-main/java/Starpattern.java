public class Starpattern{
    public static void main(String[] args) {
        int row=10;
        int col=10;
        int i=0;
        int j=0;
        for (i = 0; i <=col; i++) {
            for (j = i; j >=0; j--) {
                System.out.print(" *");
            }
                 System.out.print("      ***    ");
            for (j =i; j <=col; j++) {
                System.out.print(" *");
            }
             System.out.println();
        }
        
    }
}