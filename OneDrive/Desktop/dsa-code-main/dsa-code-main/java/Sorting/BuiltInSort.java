import java.util.Arrays;

public class BuiltInSort {
    public static void main(String[] args) {
        int[] data = {5, 2, 8, 1, 3};
        Arrays.sort(data);
        for (int num : data)
            System.out.print(num + " ");
    }
}
