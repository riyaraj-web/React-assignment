import java.util.*;
class Matrix_FullSort
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
        display(a);
        System.out.println("fully sorted array----");
        fsort(a);
    }
    void fsort(int x[][])
    {
        int a[]=new int[x.length*x[0].length];
        int c=0;
        for(int i=0;i<x.length;i++)
        {
            for(int j=0;j<x[0].length;j++)
            {
                a[c]=x[i][j];
                c++;
            }            
        }
        for(int i=0;i<a.length-1;i++)
        {
            int min=i;
            for(int j=i+1;j<a.length;j++)
            {
                if(a[j]<a[min])
                {
                    min=j;
                }
            }
            int t=a[i];
            a[i]=a[min];
            a[min]=t;
        }
        c=0;
        for(int i=0;i<x.length;i++)
        {
            for(int j=0;j<x[0].length;j++)
            {
                System.out.print(a[c]+" ");
                c++;
            }
            System.out.println();
        }
    }//end of fsort
    void display(int x[][])
    {
        for(int i=0;i<x.length;i++)
        {
            for(int j=0;j<x[0].length;j++)
            {
                System.out.print(x[i][j]+" ");
            }
            System.out.println();
        }
    }//end of display
    public static void main(String args[])
    {
        new Matrix_FullSort().calc();
    }//end of main
}//end of class