// day3HA.c
#include "stdio.h"
void tower(int n, char source, char middle, char dest) {
    if(n==1)
        printf("%c -> %c\n",source,dest);
    else {
        tower(n-1,source,dest,middle);
        printf("%c -> %c\n",source,dest);
        tower(n-1,middle,source,dest);
    }
}
int fibo(int x) {
    if(x==0)
        return 0;
    else if(x==1)
        return 1;
    else
        return (fibo(x-1) + fibo(x-2));
}
int gcd(int a,int b) {
    if(b!=0)
        return gcd(b,a%b);
    else
        return a;
}
int main() {
    int c,n,o;
    do {
        fflush(stdin);
        printf("Press 1 to solve Tower of Hanoi\nPress 2 to print fibonacci series\nPress 3 to get gcd\nPress 4 to exit:");
        scanf("%d",&c);
        switch (c) {
            case 1:
                printf("Enter the number of rings\n");
                scanf("%d",&n);
                printf("Result:\n");
                tower(n,'A','B','C');
                printf("\n");
                break;
            case 2:
                printf("Enter the number of terms\n");
                scanf("%d",&n);
                for (int i = 0; i < 10; ++i) {
                    printf("%d ",fibo(i));
                }
                printf("\n");
                break;
            case 3:
                printf("Enter the two terms:\n");
                scanf("%d%d",&n,&o);
                printf("GCD=%d", gcd(n>o?n,o:o,n));
                printf("\n");
            case 4:
                break;
            default:
                printf("Wrong choice");
        }
    } while (c!=4);
}