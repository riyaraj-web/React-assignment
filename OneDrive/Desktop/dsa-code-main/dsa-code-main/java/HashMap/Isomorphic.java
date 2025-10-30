import java.util.HashMap;

public class Isomorphic {
    public static void main(String[] args) {
        String s= "abcdca";
        String t= "xywswz";

        HashMap <Character, Character> mp= new HashMap<>();

        if(s.length() != t.length())
        {
            System.out.println("Not Isomorphic");
        }
        else
        {
            for(int i=0; i<s.length(); i++)
            {
                char chS= s.charAt(i);
                char chT= t.charAt(i);

                if (mp.containsKey(chS)) {
                    if(mp.get(chS) != chT)
                    {
                        System.out.println("Not Isomorphic");
                    }
                }
                else if (mp.containsValue(chT)) {
                    System.out.println("Not Isomorphic");
                }
                else
                {
                    mp.put(chS, chT);
                }
            }
            System.out.println(mp);
             
        }
    }
}
