#include <stdio.h>
#include <stdlib.h>
void merge(int *arr,int low,int mid,int high){
    int i = low, j = mid+1, k=0;
    int temp[high-low+1];
    while (i <= mid && j <=high){
        if(arr[i] <= arr [j])     temp[k++] = arr[i++];
        else        temp[k++] = arr[j++];
    }
    while(i <= mid)     temp[k++] = arr[i++];
    while(j <= high)     temp[k++] = arr[j++];
    for(i=low, k=0; i<=high; i++,k++)
        arr[i] = temp[k];
}
void mergeSort(int *arr,int low, int high){
    if(low < high){
        int mid = low +(high - low)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}
int* quicksort(int* arr,int low,int n) {
    int isSorted = 1;
    int pivot = low;
    for(int i = low;i<n;i++)
        if(arr[i] < arr[pivot]) {
            int temp = arr[i];
            arr[i] = arr[pivot];
            arr[pivot] = temp;
            pivot = i;
            isSorted = 0;
            break;
        }
    if(isSorted && low+1 == n)
        return arr;
    if (isSorted)
        return quicksort(arr,low+1,n);
    return quicksort(arr,low,n);
}
int getMax(int *arr, int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}
void countingSort(int *arr, int n, int exp) {
    int output[n];
    int count[10] = {0};
    for (int i = 0; i < n; i++)
        count[arr[i] / exp % 10]++;
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i] / exp % 10] - 1] = arr[i];
        count[arr[i] / exp % 10]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}
void radixSort(int *arr, int n) {
    int max = getMax(arr, n);
    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}
void printArray(int *arr,int n){
    printf("Sorted array\n");
    for(int i = 0; i < n; i++)
        printf("%d ",arr[i]);
    printf("\n");
}
int main() {
    int n, *arr, ch;
    do{
        printf("Enter the size of array : ");
        scanf("%d",&n);
        arr = (int *)calloc(n,sizeof(int));
        printf("Enter the elements of array\n");
        for(int i = 0; i < n; i++)
            scanf("%d",&arr[i]);
        printf("1 to Merge Sort\n2 to Quick Sort\n3 to Radix Sort\n4 to Exit:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                mergeSort(arr, 0, n-1);
                printArray(arr, n);
                break;
            case 2:
                arr = quicksort(arr, 0, n);
                printArray(arr, n);
                break;
            case 3:
                radixSort(arr, n);
                printArray(arr, n);
                break;
            case 4: break;
        }
    }while(ch!=4);
}