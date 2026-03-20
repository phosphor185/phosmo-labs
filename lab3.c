#include <stdio.h>

int main() {
    char str[80];
    int i = 0;
    char ch;
    printf("vvedite stroku: ");
    fgets(str, sizeof(str), stdin);
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == 'a') {
            str[i] = 'A';
        } else if (str[i] == 'b') {
            str[i] = 'B';
        }
    }
    printf("res: %s", str);
    
    return 0;
}
