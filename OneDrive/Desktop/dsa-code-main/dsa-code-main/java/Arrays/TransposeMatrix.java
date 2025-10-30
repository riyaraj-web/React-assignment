package Arrays;

import java.util.Scanner;

public class TransposeMatrix {


    public static void main(String[] args) {
        Scanner scanner=new Scanner(System.in);


        System.out.println("Enter the row size:");
        int row=scanner.nextInt();
        System.out.println("Enter the column size:");
        int col=scanner.nextInt();

        if(row==col) {




            int arr[][]=new int[row][col];

            int trans[][]=new int[row][col];

            System.out.println("Enter elements matrix:");
            for (int i = 0; i < row; i++) {

                for (int j = 0; j < col; j++) {

                    arr[i][j]=scanner.nextInt();

                }
            }

            System.out.println("elements :");
            for (int i = 0; i < row; i++) {

                for (int j = 0; j < col; j++) {

                    System.out.print(arr[i][j]+" ");

                }
                System.out.println();
            }
            System.out.println("Transpose :");
            for (int i = 0; i < row; i++) {

                for (int j = 0; j < col; j++) {

                    trans[i][j]=arr[j][i];

                }
                System.out.println();
            }

            for (int i = 0; i < row; i++) {

                for (int j = 0; j < col; j++) {

                    System.out.print(trans[i][j]+" ");

                }
                System.out.println();
            }

        }
        else {
            System.out.println("row and column size must be same....");
        }

    }



}