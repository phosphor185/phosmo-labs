#include <stdio.h>

int main() {
    char str[81];
    int i = 0;
    
    // Ввод строки с консоли
    printf("Введите строку (до 80 символов): ");
    fgets(str, sizeof(str), stdin);
    
    // Замена 'a' на 'A' и 'b' на 'B'
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == 'a') {
            str[i] = 'A';
        } else if (str[i] == 'b') {
            str[i] = 'B';
        }
    }
    
    // Вывод результата
    printf("Результат: %s\n", str);
    
    return 0;
}
