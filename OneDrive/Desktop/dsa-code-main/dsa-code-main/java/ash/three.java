public class AddStringsBuilder {
    public static void main(String[] args) {
        String str1 = "Java";
        String str2 = "Programming";

        StringBuilder sb = new StringBuilder();
        sb.append(str1);
        sb.append(" ");
        sb.append(str2);

        String result = sb.toString();
        System.out.println("Result: " + result);
    }
}
