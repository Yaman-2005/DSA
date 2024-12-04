//
// Created by ananmay on 10/11/24.
//
#include "stdio.h"
int* quicksort(int* arr,int size,int low) {
    int isSorted = 1;
    int pivot = arr[low];
    int pivotPos = low;
    for(int i = low;i<size;i++) {
        if(arr[i] < arr[pivotPos]) {
            int temp = arr[i];
            arr[i] = pivot;
            arr[pivotPos] = temp;
            pivotPos = i;
            isSorted = 0;
        }
    }
    printf("\n");
    if(isSorted && low+1 == size) {
        return arr;
    }
    else if(isSorted) {
        return quicksort(arr,size,low+1);
    }
    else {
        return quicksort(arr,size,low);
    }
}
int main() {
    printf("Enter the number of elements");
    int n;
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0;i<n;i++)
        scanf("%d",&arr[i]);
    int s = sizeof(arr)/sizeof(arr[0]);
    int* res = quicksort(arr,s,0);
    printf("Answer");
    for (int i = 0;i<n;i++) {
        printf("%d ",res[i]);
    }
}