import java.util.Scanner;

public class BubbleSort_ascending
{
    public static void main(String args[])
    {
        
        Scanner sc = new Scanner(System.in);   // Create Scanner object for user input
        int i = 0, j = 0, temp = 0;            // Declare loop variables and temporary variable for swapping
        int a[] = new int[5];                  // Declare an integer array of size 5

        // Take input from the user
        System.out.println("Enter 5 numbers: ");
        for(i = 0; i < 5; i++)
        {
            a[i] = sc.nextInt();               // Read each number and store in array
        }

        // Display array before sorting
        System.out.println("Array before sorting: ");
        for(i = 0; i < 5; i++)
        {
            System.out.print(a[i] + ",");      // Print each element separated by a comma
        }
