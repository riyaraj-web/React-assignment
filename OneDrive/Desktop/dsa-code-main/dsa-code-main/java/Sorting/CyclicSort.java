public class CyclicSort {
    public static void main(String[] args) {
        int[] arr = {1,2,5,3,4,6};
        cyclicsort(arr);
        for (int num : arr) {
            System.out.print(num + " ");
        }
    
    }
    public static void cyclicsort(int[] arr){
        int i =0;
        while(i<arr.length){
            int correctind= arr[i]-1;
            if(arr[i]!=arr[correctind]){
                int temp = arr[i];
                arr[i]=arr[correctind];
                arr[correctind]= temp;

            }else{
                i++;
            }
        }
    }
    
}
