ЗАГОЛОВОК func.h
#ifndef FUNC_H
#define FUNC_H
double** calculate(double** A, double** B, int n, char op);

#endif

ФУНКЦИЯ func.c
#include <stdlib.h>
#include "func.h"


double** calculate(double** A, double** B, int n, char op) {
    int i, j, k;
    double** Res = (double**)malloc(n * sizeof(double*));
    for (i = 0; i < n; i++) {
        Res[i] = (double*)malloc(n * sizeof(double));
    }

    if (op == '+') {
        for ( i = 0; i < n; i++) {
            for ( j = 0; j < n; j++) {
                Res[i][j] = A[i][j] + B[i][j];
            }
        }
    } 
    else if (op == '-') {
        for ( i = 0; i < n; i++) {
            for ( j = 0; j < n; j++) {
                Res[i][j] = A[i][j] - B[i][j];
            }
        }
    } 
    else if (op == '*') {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                Res[i][j] = 0; 
                for (k = 0; k < n; k++) {
                    Res[i][j] += A[i][k] * B[k][j];
                }
            }
        }
    }

    return Res;
}

ОСНОВНОЙ ФАЙЛ main.c
#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int main() {

    int n,i,j,k;
    char op;

    printf("Vvedite razmer matricy n: ");
    scanf("%d", &n);

    double** A = (double**)malloc(n * sizeof(double*));
    for (i = 0; i < n; i++) {
        A[i] = (double*)malloc(n * sizeof(double));
    }

    double** B = (double**)malloc(n * sizeof(double*));
    for (i = 0; i < n; i++) {
        B[i] = (double*)malloc(n * sizeof(double));
    }

    printf("Vvedite elementy matricy A:\n");
    for (i = 0; i < n; i++) {
        for ( j = 0; j < n; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    printf("Vvedite elementy matricy B:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%lf", &B[i][j]);
        }
    }

    printf("Vvedite operaciyu (+, -, *): ");
    scanf(" %c", &op); 

    double** Result = calculate(A, B, n, op);

    printf("Result:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%.2lf ", Result[i][j]);
        }
        printf("\n");
    }

    for( i=0; i<n; i++) {
        free(A[i]);
        free(B[i]);
        free(Result[i]);
    }
    free(A);
    free(B);
    free(Result);

    system("pause"); 
    return 0;
}
