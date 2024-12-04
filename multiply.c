#include <stdio.h>
#include <stdlib.h>
void multiply(int** a, int** b,int** c, int m,int n,int x,int y) {
    for(int i = 0;i < m;i++) {
        for(int j = 0;j<y;j++) {
            c[i][j] = 0;
            for(int k = 0; k < n;k++)
                c[i][j] += a[i][k] * b[k][j];
        }
    }
}
int main() {
    int m,n,x,y;
    printf("Enter the order of the first matrix");
    scanf("%d%d",&m,&n);
    printf("Enter the order of the second matrix");
    scanf("%d%d",&x,&y);
    if(n != x) {
        printf("Multiplication not possible");
        exit(0);
    }
    int **a, **b,**c;
    a = (int**)malloc(m*sizeof(int*));
    for (int i = 0;i < m;i++)
        a[i] = (int*)malloc(n*sizeof(int));
    b = (int**)malloc(m*sizeof(int*));
    for (int i = 0;i < x;i++)
        b[i] = (int*)malloc(y*sizeof(int));
    c = (int**)malloc(m*sizeof(int*));
    for (int i = 0;i < m;i++)
        c[i] = (int*)malloc(y*sizeof(int));
    printf("Enter the elements of the first matrix");
    for(int i = 0;i < m;i++) {
        for (int j = 0;j < n;j++) {
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter the elements of the second matrix");
    for(int i = 0;i < x;i++) {
        for (int j = 0;j < y;j++) {
            scanf("%d",&b[i][j]);
        }
    }
    multiply(a,b,c,m,n,x,y);
    for(int i = 0;i < m;i++) {
        for (int j = 0;j < y;j++) {
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
    free(a);
    free(b);
    free(c);
}