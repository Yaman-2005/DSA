#include "stdbool.h"
void multiply(int** a, int** b,int** c, int m,int n,int x,int y) {
    for(int i = 0;i < m;i++) {
        for(int j = 0;j<y;j++) {
            c[i][j] = 0;
            for(int k = 0; k < n;k++)
                c[i][j] += a[i][k] * b[k][j];
        }
    }
}
bool isIden(int** a,int m) {
    int i,j;
    for (i=0;i<m;i++) {
        for (j=0;j<m;j++) {
            if((i==j && a[i][j] != 1) || (i!=j && a[i][j]!=0))
                return false;
        }
    }
    return true;
}
bool isdiag(int** a,int m) {
    int i,j;
    for (i=0;i<m;i++) {
        for (j=0;j<m;j++) {
            if(i!=j && a[i][j]!=0)
                return false;
        }
    }
    return true;
}