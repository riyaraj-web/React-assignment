package strings;

import java.util.Arrays;

public class AnagramString {
    public static void main(String[] args) {

        String str1="geeks";
        String str2="skeeg";


        if (str1.length()!=str2.length()) {
            System.out.println("String is not anagram...");
            return;
        }
        char ch1[]=str1.toCharArray();
        char ch2[]=str2.toCharArray();


        Arrays.sort(ch1);
        Arrays.sort(ch2);


        if (Arrays.equals(ch1, ch2)) {

            System.out.println("String is anagrams...");
        }
        else {
            System.out.println("String is not anagrams....");
        }

    }
}
