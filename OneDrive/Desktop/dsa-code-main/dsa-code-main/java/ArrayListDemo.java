import java.util.ArrayList;

public class ArrayListDemo {

    public static void main(String[] args) {

        ArrayList<Integer> arrayList = new ArrayList<Integer>(5);

        //adding elements
        for(int i = 1; i <= 5; i++) {
            arrayList.add(i);
        }

        //printing elements
        System.out.println(arrayList);

        //removing element using index
        arrayList.remove(3);

        //printing elements
        System.out.println(arrayList);

        //printing element one by one
        for(int i = 0; i < arrayList.size(); i++) {
            System.out.println(arrayList.get(i) + " ");
        }
        //for each
        for(int i : arrayList) {
            System.out.println(i);
        }
    }
}
