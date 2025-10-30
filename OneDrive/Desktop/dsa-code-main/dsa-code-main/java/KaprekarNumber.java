import java.util.*;
class KaprekarNumber
{
     void calc()
     {
         Scanner sc=new Scanner(System.in);
         int n1,n2;
         do
         {
             System.out.println("Enter the lower range----");
             n1=sc.nextInt();//taking input
             System.out.println("Enter the upper range----");
             n2=sc.nextInt();//taking input
         }while(n1<=0||n2<=0||n2<=n1);//end of do-while loop
         System.out.println("The Kaprekar numbers are----");
         for(int i=n1;i<=n2;i++)
         {
             int x=i;
             int c=(int)(Math.log10(i)+1);
             int a=(x*x)/(int)Math.pow(10,c);
             int b=(x*x)%(int)Math.pow(10,c);
             if(a+b==i)
                System.out.println(i);
         }//end of for loop
     }//end of calc
 public static void main(String args[])
    {
         KaprekarNumber ob=new KaprekarNumber();//object creation
         ob.calc();//method calling
    }//end of main
}//end of class
     
          