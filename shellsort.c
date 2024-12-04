//
// Created by ananmay on 19/11/24.
//
#include "stdio.h"
#include "stdlib.h"
void shellSort(int* arr, int n) {
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}
int main() {
    int n;
    printf("Enter the size of array:");
    scanf("%d",&n);
    int* arr = calloc(n,sizeof(int));
    printf("Emter the elements\n");
    for (int i = 0; i < n; ++i)
        scanf("%d",&arr[i]);
    shellSort(arr,n);
    printf("Sorted Array: ");
    for (int i = 0; i < n; ++i)
        printf("%d ",arr[i]);
}