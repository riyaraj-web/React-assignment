import java.util.Scanner;

public class NeonNumberChecker {

    public static void main(String[] args) {
        Scanner inputScanner = new Scanner(System.in);

        System.out.print("Enter a number to check if it's a Neon number: ");
        int number = inputScanner.nextInt();

        // Calculate the square of the number
        int square = number * number;
        int sumOfDigitsOfSquare = 0;

        // Calculate the sum of the digits of the square
        while (square > 0) {
            int digit = square % 10; // Get the last digit
            sumOfDigitsOfSquare += digit; // Add the digit to the sum
            square /= 10; // Remove the last digit
        }

        // Check if the sum of digits of the square equals the original number
        if (sumOfDigitsOfSquare == number) {
            System.out.println(number + " is a Neon number.");
        } else {
            System.out.println(number + " is not a Neon number.");
        }

        inputScanner.close();
    }
}