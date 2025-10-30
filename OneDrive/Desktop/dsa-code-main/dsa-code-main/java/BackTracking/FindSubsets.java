// if the lenght of a str is n
// then the number of subsets it will have is 2^n (exponential)

public class FindSubsets{
    public static void main(String args[]){
        String str = "abc";
        int i=0;
        String ans = "";
        findSubsets(str, i, ans);

    }

    public static void findSubsets(String str, int i, String ans){
        // base case
        if(i == str.length()){
            if(ans.length() == 0){
                System.out.println("null");
            }else{
                System.out.println(ans);
            }
            return;
        }

        // recursion
        // YES Choice ->  a new str char is added to the ans str
        findSubsets(str, i+1, ans+str.charAt(i));

        // NO choice ->  a new str char is not added to the ans str
        findSubsets(str, i+1, ans);

    }
}