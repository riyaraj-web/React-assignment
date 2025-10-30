#include<iostream>
#include<vector>
using namespace std;

int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low, j = high;
    while(i < j){
        while(arr[i] <= pivot && i <= high - 1){
            i++;
        }
        while(arr[j] > pivot && j >= low + 1){
            j--;
        }
        if(i < j){
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high){
    if(low < high){
        int pIdx = partition(arr, low, high);
        quickSort(arr, low, pIdx-1);
        quickSort(arr, pIdx+1, high);
    }
}

int main(){
    int arr[] = {3,2,6,1,4,8,2,6,7,9};
    quickSort(arr, 0, 9);
    for(int i = 0; i < 10; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
