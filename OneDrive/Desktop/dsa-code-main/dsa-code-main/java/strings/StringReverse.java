package strings;

public class StringReverse {


    //built in method
    public static void name(String str) {


        StringBuilder builder=new StringBuilder(str);


        String string = builder.reverse().toString();
        System.out.println(string);
    }


    //Using logic
    public static void reverse(String str1) {

        String s="";

        for (int i =str1.length()-1;i>=0; i--) {

            s=s+str1.charAt(i);
        }

        System.out.println(s);

    }


    //Recursion
    public static String rucursion(String s ,String r,int i) {



        if(i<0) {
            return r;
        }

        return  rucursion(s, r+s.charAt(i),i-1);

    }
    public static void main(String[] args) {

        reverse("Somnath");
        String str="somnathdhere";
        String r="";
        int i=str.length()-1;

        System.out.println(rucursion(str, r, i));

    }

}
