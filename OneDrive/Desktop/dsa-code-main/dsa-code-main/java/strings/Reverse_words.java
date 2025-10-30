package strings;

public class Reverse_words {
    public static void wordReverse(String str) {


        String word[] = str.split(" ");

        for (int i = word.length - 1; i >= 0; i--) {

//			int a= word[i].length();
//			System.out.println(a);
            System.out.print(word[i] + " ");
        }

    }


    public static void main(String[] args) {


        String str = "i am somnath dhere";

        wordReverse(str);
    }
}


