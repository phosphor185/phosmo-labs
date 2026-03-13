#include <stdio.h>
#include <math.h>
int main() {
 double a;
    printf("vvedite a: ");
    scanf ("%lf", &a);
    double b;
    printf("vvedite b");
    scanf ("%lf", &b);
    double c;
    printf("vvedite c");
    scanf ("%lf", &c);
    double d = pow (b, 2) - 4 * a * c;
    
    if (d < 0){
     printf ("d < 0");
    }
    if (d == 0){
  double x1 = (-b / 2 * a);
  printf ("x1 = %lf \n", x1);
  printf ("D = %lf \n", d);
 }
 if (d > 0){
     double x1 = (-b + pow(d, 0.5))/(2*a);
     double x2 = (-b - pow(d, 0.5))/(2*a);
     printf ("x1 = %lf \n", x1);
     printf ("x2 = %lf \n", x2);
     printf ("D = %lf \n", d);
    }
 return 0;
}
