#include <stdio.h>

int main() {
    int num1, num2;

printf("Введите число один: ");
scanf("%d", &num1);

printf("Введите число два: ");
scanf("%d", &num2);

int summa = num1 + num2;

int raznost = num1 - num2;

int umnoj = num1 * num2;

printf("%d\n", summa);
    printf("%d\n", raznost);
    printf("%d\n", umnoj);

    return 0;
}
