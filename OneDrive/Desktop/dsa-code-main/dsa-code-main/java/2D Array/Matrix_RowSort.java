import java.util.*;
public class Matrix_RowSort 
{
    void calc()
    {
        Scanner sc=new Scanner(System.in);
        int R;int C;
        do
        {
            System.out.println("Enter the row size of the matrix----");
            R=sc.nextInt();
            System.out.println("Enter the column size of the matrix----");
            C=sc.nextInt();
        }while(R<=0 || C<=0);
        int a[][]=new int[R][C];
        System.out.println("Enter the array elements of the array----");
        for(int i=0;i<R;i++)
        {
            for(int j=0;j<C;j++)
            {
                a[i][j]=sc.nextInt();
            }            
        }
        System.out.println("Original array----");
        for(int i=0;i<R;i++)
        {
            for(int j=0;j<C;j++)
            {
                System.out.print(a[i][j]+" ");
            }
            System.out.println();
        }
        System.out.println("Sorted array----");      
        for(int i=0;i<R;i++)//selection sort
        {
            for(int p=0;p<R-1;p++)
            {
                int min=p;
                for(int j=p+1;j<C;j++)
                {
                    if(a[i][j]<a[i][min])
                    {
                        min=j;
                    }
                }
                int t=a[i][p];
                a[i][p]=a[i][min];
                a[i][min]=t;
            }
        }
        for(int i=0;i<R;i++)
        {
            for(int j=0;j<C;j++)
            {
                System.out.print(a[i][j]+" ");
            }
            System.out.println();
        }
    }//end of calc
    public static void main(String args[])
    {
        new Matrix_RowSort().calc();
    }//end of main
}//end of class
