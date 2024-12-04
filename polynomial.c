#include <stdio.h>
#include <stdlib.h>


void printPolynomial(int poly[], int n) {
    int first = 1;
    for (int i = n - 1; i >= 0; i--) {
        if (poly[i] != 0) {
            if (!first) printf(" + ");
            printf("%dx^%d", poly[i], i);
            first = 0;
        }
    }
    printf("\n");
}


void addPolynomials(int poly1[], int poly2[], int res[], int n,int n1,int n2) {
    for (int i = 0; i < n; i++) {
        if(i<n1)
            res[i]+=poly1[i];
        if(i<n2)
            res[i]+=poly2[i];
    }
}


void multiplyPolynomials(int poly1[], int poly2[], int res[], int n1, int n2) {
    int m = n1 + n2 - 1;
    for (int i = 0; i < m; i++) {
        res[i] = 0;
    }

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            res[i + j] += poly1[i] * poly2[j];
        }
    }
}

int main() {
    int n1, n2;

    printf("Enter the degree of the first polynomial: ");
    scanf("%d", &n1);
    n1++;

    int *poly1 = (int *)calloc(n1, sizeof(int));

    printf("Enter the coefficients of the first polynomial:\n");
    for (int i = 0; i < n1; i++) {
        printf("Coefficient of x^%d: ", i);
        scanf("%d", &poly1[i]);
    }

    printf("Enter the degree of the second polynomial: ");
    scanf("%d", &n2);
    n2++;

    int *poly2 = (int *)calloc(n2, sizeof(int));

    printf("Enter the coefficients of the second polynomial:\n");
    for (int i = 0; i < n2; i++) {
        printf("Coefficient of x^%d: ", i);
        scanf("%d", &poly2[i]);
    }

    int n = (n1 > n2) ? n1 : n2;
    int *resultAdd = (int *)calloc(n, sizeof(int));
    int *resultMul = (int *)calloc(n1 + n2 - 1, sizeof(int));

    addPolynomials(poly1, poly2, resultAdd, n,n1,n2);
    multiplyPolynomials(poly1, poly2, resultMul, n1, n2);

    printf("First polynomial: ");
    printPolynomial(poly1, n1);

    printf("Second polynomial: ");
    printPolynomial(poly2, n2);

    printf("Sum of polynomials: ");
    printPolynomial(resultAdd, n);

    printf("Product of polynomials: ");
    printPolynomial(resultMul, n1 + n2 - 1);

    free(poly1);
    free(poly2);
    free(resultAdd);
    free(resultMul);

    return 0;
}