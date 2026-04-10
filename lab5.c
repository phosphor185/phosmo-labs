ЗАГОЛОВОК func.h
#ifndef FUNC_H
#define FUNC_H
double** calculate(double** A, double** B, int n, char op);

#endif

ФУНКЦИЯ func.c
  #include <stdlib.h>
#include "func.h"

double** calculate(double** A, double** B, int n, char op) {
    // Создаем матрицу для результата
    double** Res = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        Res[i] = (double*)malloc(n * sizeof(double));
    }

    if (op == '+') {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                Res[i][j] = A[i][j] + B[i][j];
            }
        }
    } 
    else if (op == '-') {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                Res[i][j] = A[i][j] - B[i][j];
            }
        }
    } 
    else if (op == '*') {
        // Умножение матриц - это три цикла, самое сложное для новичка
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                Res[i][j] = 0; // Сначала обнуляем
                for (int k = 0; k < n; k++) {
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
    setlocale(LC_ALL, "Russian"); // Чтобы русский текст работал
    int n;
    char op;

    printf("Vvedite razmer matricy n: ");
    scanf("%d", &n);

    // Выделяем память для матрицы А (массив указателей)
    double** A = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        A[i] = (double*)malloc(n * sizeof(double));
    }

    // Выделяем память для матрицы B
    double** B = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        B[i] = (double*)malloc(n * sizeof(double));
    }

    // Вводим первую матрицу
    printf("Vvedite elementy matricy A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    // Вводим вторую матрицу
    printf("Vvedite elementy matricy B:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &B[i][j]);
        }
    }

    // Вводим знак
    printf("Vvedite operaciyu (+, -, *): ");
    // Пробел перед %c нужен, чтобы съесть лишний Enter после ввода чисел
    scanf(" %c", &op); 

    // Вызываем функцию из другого файла
    double** Result = calculate(A, B, n, op);

    // Выводим результат
    printf("Result:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2lf ", Result[i][j]);
        }
        printf("\n");
    }

    // Освобождаем память (новички часто забывают, но тут я написал)
    for(int i=0; i<n; i++) {
        free(A[i]);
        free(B[i]);
        free(Result[i]);
    }
    free(A);
    free(B);
    free(Result);

    system("pause"); // Чтобы окно не закрылось сразу в Visual Studio
    return 0;
}
