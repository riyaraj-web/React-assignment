import java.util.HashMap;
import java.util.Map;

public class Anagram {
    public static void main(String[] args) {
        String s= "aabbbb";
        String t= "aaaabb";

        Map <Character,Integer> ss= new HashMap<>();
        Map <Character,Integer> tt= new HashMap<>();

        if(s.length() != t.length())
        {
            System.out.println("Not Anagram!");
        }
        else{
            // hashmap of 1st string
            // hashmap of 2nd string

            // mapping of string 1
            for(int i=0; i< s.length(); i++)
            {
                if(!ss.containsKey(s.charAt(i)))
                {
                    ss.put(s.charAt(i), 1);
                }
                else{
                    ss.put(s.charAt(i), ss.get(s.charAt(i))+1);
                }
            }
            
            // mapping of string 2
            for(int i=0; i< t.length(); i++)
            {
                if(!tt.containsKey(t.charAt(i)))
                {
                    tt.put(t.charAt(i), 1);
                }
                else{
                    tt.put(t.charAt(i), tt.get(t.charAt(i))+1);
                }
            }
            System.out.println(ss);
            System.out.println(tt);

            // check if ss and tt are equal?
            if(ss.equals(tt))
            {
                System.out.println("Yes! given string is Anagram");
            }
            else
            {
                System.out.println("No! given string is not Anagram");
            }
            
        }
    }



}
