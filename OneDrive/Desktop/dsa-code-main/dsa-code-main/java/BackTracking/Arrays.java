public class Arrays{
    public static void main(String args[]){
        // only initialize an array
        // we will fill this arr using recursion

        int arr[] = new int[5];

        // idx on each element
        int i=0;

        // element's value
        int val = 1;

        changeArrays(arr, i, val);
        printArr(arr);
    }

    public static void printArr(int arr[]){
        for(int i=0; i<arr.length; i++){
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    public static void changeArrays(int arr[], int i, int val){
        // base case
        if(i==arr.length){
            printArr(arr);
            return;
        }

        // when the call stack goes up
        arr[i] = val;

        changeArrays(arr, i+1, val+1);

        // when call stack unwinds
        // when the call comes back to changeArrays, next this recursion will be executed
        arr[i] = arr[i] - 2;        // backtracking step
    }
}