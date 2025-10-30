//Program02
import java.util.*;
class PellNumber
{
    void calc()
    {
         Scanner sc=new Scanner(System.in);
         int N;
         do
         {
             System.out.println("Enter the value of N----");
             N=sc.nextInt();//taking input
         }while(N<=0);//end of do-while loop
         System.out.println("Pell series----");
         if(N==1)
         System.out.println("0");
         else if(N==2)
         System.out.println("0,1");
         else
         {
             System.out.print("0,1,");
             int m=0,n=1;int p;
             for(int i=3;i<=N;i++)
             {
                 p=2*n+m;
                 m=n;
                 n=p;
                 System.out.print(p+",");
             }//end of for loop
         }//end of else
         System.out.println();
    }//end of calc
public static void main(String args[])
    {
        PellNumber ob=new PellNumber();//creating object
        ob.calc();//method calling
    }//end of main
}//end of class   