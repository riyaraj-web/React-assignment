public class MergeSort {

    public static void mergeInPlace(int arr[], int start, int mid, int end) {
        int start2 = mid + 1;
        if (arr[mid] <= arr[start2]) return;

        while (start <= mid && start2 <= end) {
            if (arr[start] <= arr[start2]) {
                start++;
            } else {
                int value = arr[start2];
                int index = start2;

                while (index != start) {
                    arr[index] = arr[index - 1];
                    index--;
                }
                arr[start] = value;

                start++;
                mid++;
                start2++;
            }
        }
    }

    public static void mergeSort(int arr[], int l, int r) {
        if (l >= r) return;

        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        mergeInPlace(arr, l, m, r);
    }

    public static void main(String[] args) {
        int arr[] = {6, 3, 9, 5, 2, 8};
        int n = arr.length;

        mergeSort(arr, 0, n - 1);

        System.out.println("Sorted array:");
        for (int num : arr) {
            System.out.print(num + " ");
        }
        System.out.println();
    }
}
