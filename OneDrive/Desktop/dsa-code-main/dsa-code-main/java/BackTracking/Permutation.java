import java.util.*;
public class Permutation{
    public static void main(String args[]){
        String str = "abc";
        findPermutation(str, " ");
    }

    public static void findPermutation(String str, String ans){
        if(str.length() == 0){
            System.out.print(ans);
            return;
        }

        // recursion
        for(int i = 0; i < str.length(); i++){

            // to access the string's curr character
            char curr = str.charAt(i);

            // now i want to delete that curr char from the str bec we cant access that char again
            // "abcde" => "ab" + "de" = "abde"
            String Newstr = str.substring(0, i) + str.substring(i+1);
            findPermutation(Newstr, ans+curr);
        }
        
    }
}