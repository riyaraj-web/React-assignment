import java.util.HashMap;
import java.util.Map;

public class Frequency {
    public static void main(String[] args) {
        Map<Integer,Integer> mp = new HashMap<>();

        int[] arr={1,3,5,3,4,3,1,4,5,7,8,5,3,2,4,6,7,8,8,6,5,4,3,2,2,5};
        int n= arr.length;

        for (int i : arr) {
            if(!mp.containsKey(i))
            {
                mp.put(i, 1);
            }
            else
            {
                mp.put(i, mp.get(i)+1);
            }

        }
        System.out.println("Frequency Map");
        System.out.println(mp.entrySet());


        // check for max freq
        int maxFreq= -1;
        int ansKey= -1;

        for (var dic : mp.entrySet()) {
            if(dic.getValue() > maxFreq)
            {
                maxFreq= dic.getValue();
                ansKey= dic.getKey();
            }
        }

        System.out.println("Key: "+ ansKey +" \nMax Frequency: "+maxFreq);
    }
}
