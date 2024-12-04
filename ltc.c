//
// Created by ananmay on 18/8/24.
//
#include <stdio.h>
#include "stdbool.h"
bool isPrime(int n) {
    for(int i = 2;i<=n/2;i++) {
        if(n%i==0)
            return false;
    }
    return true;
}
bool isUgly(int n) {
    for(int i = 2; i <= n;i++) {
        if(n%i==0 && isPrime(i) && i!=2 && i!=3 && i!=5)
            return false;
    }
    return true;
}

int nthUglyNumber(int n) {
    int i = 1,count=1;
    while(true) {
        if(isUgly(i) && count != n) {
            i++;
            count++;
            printf("%d count != n\n",i);
        }
        else if(isUgly(i) == false) {
            i++;
            printf("Not Ugly\n");
        }
        if(isUgly(i) && count == n) {
            printf("count==n\n");
            return i;
        }
    }
}
int main() {
    int n;
    printf("Enter the number:");
    scanf("%d",&n);
    printf("Result:%d", nthUglyNumber(n));
}