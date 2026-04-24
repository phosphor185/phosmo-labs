#include <stdio.h>
#include <windows.h>

struct humen {
    char surname[50];
    char name[50];
    int year;
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    struct humen arr1[4], arr2[4];
    struct humen temp;

    printf("Vvedi 4 cheloveka (Familiya Imya God):\n");
    int i;
    int j;
    for (i = 0; i < 4; i++) {
        printf("Chelovek %d: ", i + 1);
        scanf("%s %s %d", arr1[i].surname, arr1[i].name, &arr1[i].year);
    }

    for (i = 0; i < 4; i++) {
        arr2[i] = arr1[i];
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3 - i; j++) {
            if (arr2[j].year > arr2[j+1].year) {
                temp = arr2[j];
                arr2[j] = arr2[j+1];
                arr2[j+1] = temp;
            }
        }
    }

    printf("\nOtsortirovano po godu rozhdeniya:\n");
    for (i = 0; i < 4; i++) {
        printf("%s %s %d\n", arr2[i].surname, arr2[i].name, arr2[i].year);
    }

    return 0;
}
