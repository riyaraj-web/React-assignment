import java.util.Scanner;

public class SunnyNumberChecker {

    // Method to check if a number is a perfect square
    public static boolean isPerfectSquare(double num) {
        double sqrt = Math.sqrt(num);
        // Check if the square root is an integer (i.e., no fractional part)
        return (sqrt == (int) sqrt);
    }

    // Method to check if a number is a Sunny Number
    public static boolean isSunnyNumber(int num) {
        // A number is sunny if (num + 1) is a perfect square
        return isPerfectSquare(num + 1);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter a number to check if it's a Sunny Number: ");
        int number = scanner.nextInt();

        if (isSunnyNumber(number)) {
            System.out.println(number + " is a Sunny Number.");
        } else {
            System.out.println(number + " is not a Sunny Number.");
        }

        scanner.close();
    }
}