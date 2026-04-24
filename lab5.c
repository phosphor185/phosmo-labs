ЗАГОЛОВОК func.h
Создать функцию выделения памяти под матрицу, функция освобождения памяти для матрицы, создать функцию функции сложения вычитания и деления, умножения
#ifndef FUNC_H
#define FUNC_H

// Память
double** create_matrix(int n);
void free_matrix(double** mat, int n);

// Операции (каждая своя функция)
double** add_matrices(double** A, double** B, int n);
double** sub_matrices(double** A, double** B, int n);
double** mul_matrices(double** A, double** B, int n);
double** div_matrices(double** A, double** B, int n);

#endif

ФУНКЦИЯ func.c
#include <stdlib.h>
#include "func.h"

// 1. Выделение памяти под матрицу n x n
double** create_matrix(int n) {
    double** mat = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        mat[i] = (double*)malloc(n * sizeof(double));
    }
    return mat;
}

// 2. Освобождение памяти
void free_matrix(double** mat, int n) {
    for (int i = 0; i < n; i++) {
        free(mat[i]); // сначала ряды
    }
    free(mat);        // потом сам массив указателей
}

// 3. Сложение
double** add_matrices(double** A, double** B, int n) {
    double** Res = create_matrix(n); // сразу создаем готовую матрицу
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            Res[i][j] = A[i][j] + B[i][j];
        }
    }
    return Res;
}

// 4. Вычитание
double** sub_matrices(double** A, double** B, int n) {
    double** Res = create_matrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            Res[i][j] = A[i][j] - B[i][j];
        }
    }
    return Res;
}

// 5. Умножение (матричное)
double** mul_matrices(double** A, double** B, int n) {
    double** Res = create_matrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            Res[i][j] = 0;
            for (int k = 0; k < n; k++) {
                Res[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return Res;
}

// 6. Деление (поэлементное, как обычно требуют на 1-2 курсе)
double** div_matrices(double** A, double** B, int n) {
    double** Res = create_matrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (B[i][j] != 0) {
                Res[i][j] = A[i][j] / B[i][j];
            } else {
                Res[i][j] = 0; // защита от краша при делении на 0
            }
        }
    }
    return Res;
}

ОСНОВНОЙ ФАЙЛ main.c
#include <stdio.h>
#include <stdlib.h>
#include "func.h"

// Отдельная функция для ввода, чтобы main был чистым
void input_matrix(double** mat, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &mat[i][j]);
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int n;
    char op;

    printf("Vvedite razmer matricy n: ");
    scanf("%d", &n);

    // Выделяем память через нашу функцию
    double** A = create_matrix(n);
    double** B = create_matrix(n);

    printf("Vvedite matricu A:\n");
    input_matrix(A, n);

    printf("Vvedite matricu B:\n");
    input_matrix(B, n);

    printf("Vvedite operaciyu (+, -, *, /): ");
    scanf(" %c", &op); // пробел перед %c съедает лишний Enter

    double** Result = NULL;

    // Препод просил отдельные функции, поэтому делаем выбор тут
    if (op == '+') {
        Result = add_matrices(A, B, n);
    } else if (op == '-') {
        Result = sub_matrices(A, B, n);
    } else if (op == '*') {
        Result = mul_matrices(A, B, n);
    } else if (op == '/') {
        Result = div_matrices(A, B, n);
    } else {
        printf("Neizvestnaya operaciya!\n");
        free_matrix(A, n);
        free_matrix(B, n);
        return 1;
    }

    // Вывод
    printf("Result:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2lf ", Result[i][j]);
        }
        printf("\n");
    }

    // Чистим память ВСЕХ матриц
    free_matrix(A, n);
    free_matrix(B, n);
    free_matrix(Result, n);

    system("pause");
    return 0;
}
