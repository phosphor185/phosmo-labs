#include "triangle.h"
#include <math.h>

// Проверка неравенства треугольника
int is_valid_triangle(double a, double b, double c) {
    return (a + b > c) && (a + c > b) && (b + c > a);
}

// Вычисление периметра
double calculate_perimeter(double a, double b, double c) {
    return a + b + c;
}

// Вычисление площади по формуле Герона
double calculate_area(double a, double b, double c) {
    double p = calculate_perimeter(a, b, c) / 2.0; // полупериметр
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
