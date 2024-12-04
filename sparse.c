#include <stdio.h>
struct ele {
    int row;
    int col;
    int value;
};
void createSparse(int m,int n, struct ele sparse[]) {
        int k = 1;
        sparse[0].row = m;
        sparse[0].col = n;
        for(int i = 0;i<m;i++) {
                for(int j = 0;j<n;j++) {
                        int l;
                        scanf("%d",&l);
                        if (l != 0) {
                                sparse[k].row = i;
                                sparse[k].col = j;
                                sparse[k++].value = l;
                        }
                }
        }
        sparse[0].value = k-1;
}
void display(struct ele sparse[]) {
        int k = 1,i,j;
        for(i=0;i<sparse[0].row;i++) {
            for(j=0;j<sparse[0].col;j++) {
                if(sparse[k].row == i && sparse[k].col==j) {
                    printf("%d ",sparse[k].value);
                    k++;
                }
                else {
                    printf("0 ");
                }
            }
            printf("\n");
        }
}
void transpose(struct ele sparse[],struct ele trans[]) {
    int k = 1,i,j;
    trans[0].row = sparse[0].col;
    trans[0].col = sparse[0].row;
    trans[0].value = sparse[0].value;
    for(i = 1;i<=sparse[0].value;i++) {
        trans[k].row = sparse[i].col;
        trans[k].col = sparse[i].row;
        trans[k++].value = sparse[i].value;
    }
    for(i=1;i<=sparse[0].value;i++) {
        for(j=1;j<=sparse[0].value-i;j++) {
            if(trans[j].row > trans[j+1].row) {
                struct ele temp = trans[j];
                trans[j] = trans[j+1];
                trans[j+1] = temp;
            }
        }
    }
}
void add(struct ele sparse1[], struct ele sparse2[],struct ele result[]) {
    if(sparse1[0].row != sparse2[0].row || sparse1[0].col != sparse2[0].col) {
        printf("Addition not possible");
        return;
    }
    int k = 1,i,j;
    result[0].row = sparse1[0].row;
    result[0].col = sparse2[0].col;
    for(i=1;i<=sparse1[0].value;i++) {
        if(sparse1[i].row == sparse2[i].row && sparse1[i].col == sparse2[i].col) {
            result[k].row = sparse1[i].row;
            result[k].col = sparse2[i].col;
            result[k].value = sparse1[i].value + sparse2[i].value;
            k++;
        }
    }
    printf("%d\n",k);
    int f = i;
    for(i=f-1;i<=sparse2[0].value;i++,k++) {
        result[k].row = sparse2[i].row;
        result[k].col = sparse2[i].col;
        result[k].value = sparse2[i].value;
    }
    printf("%d\n",k);
    for(i=f-1;i<=sparse1[0].value;i++,k++) {
        result[k].row = sparse1[i].row;
        result[k].col = sparse1[i].col;
        result[k].value = sparse1[i].value;
    }
    printf("%d\n",k);
    result[0].value = k-1;
}
int main() {
    int m,n;
    struct ele sparse[1000],trans[1000];
    printf("Enter the dimensions of the matrix");
    scanf("%d%d",&m,&n);
    printf("Enter the elements of the matrix \n");
    createSparse(m,n,sparse);
    printf("Original Matrix \n");
    display(sparse);
    printf("Transposed Matrix\n");
    transpose(sparse,trans);
    display(trans);
}