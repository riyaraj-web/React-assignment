public class StringPermutations {
   // Recursive function to generate permutations
   private static void permute(String str, String prefix) {
       int n = str.length();
       if (n == 0) {
           System.out.println(prefix); // Base case: print the permutation
       } else {
           for (int i = 0; i < n; i++) {
               // Generate permutations for the remaining characters
               permute(str.substring(0, i) + str.substring(i + 1), prefix + str.charAt(i));
           }
       }
   }
   public static void main(String[] args) {
       String input = "ABC"; // Input string
       System.out.println("Permutations of the string \"" + input + "\":");
       permute(input, ""); // Start the recursion with an empty prefix
   }
}