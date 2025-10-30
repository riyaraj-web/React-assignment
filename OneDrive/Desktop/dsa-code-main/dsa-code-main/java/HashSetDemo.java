import java.util.*;

public class HashSetDemo {
    public static void main(String[] args) {
        HashSet<String> hashSet = new HashSet<String>();

        hashSet.add("H");
        hashSet.add("M");
        hashSet.add("P");
        hashSet.add("H");

        System.out.println(hashSet);

        System.out.println("List contains M or not? " + hashSet.contains("M"));

        hashSet.remove("P");
        System.out.println("Set after removing P: "+hashSet);

        for (String item : hashSet) {
            System.out.println(item);
        }
    }
}
