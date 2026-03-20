#include <stdio.h>
#include "triangle.h"

int main() {
    double a, b, c;
    
    printf("Введите длины сторон треугольника:\n");
    printf("Сторона a = ");
    scanf("%lf", &a);
    
    printf("Сторона b = ");
    scanf("%lf", &b);
    
    printf("Сторона c = ");
    scanf("%lf", &c);
    
    // Проверка на положительность
    if (a <= 0 || b <= 0 || c <= 0) {
        printf("Ошибка: длины сторон должны быть положительными числами!\n");
        return 1;
    }
    
    // Проверка неравенства треугольника
    if (!is_valid_triangle(a, b, c)) {
        printf("Ошибка: треугольник с такими сторонами не существует!\n");
        printf("Нарушено неравенство треугольника.\n");
        return 1;
    }
    
    // Вычисление и вывод результатов
    double perimeter = calculate_perimeter(a, b, c);
    double area = calculate_area(a, b, c);
    
    printf("\nРезультаты:\n");
    printf("Периметр треугольника: %.2f\n", perimeter);
    printf("Площадь треугольника: %.2f\n", area);
    
    return 0;
}
