#include <stdio.h>

int main() {

int number;

printf("Введите число: ");
scanf("%d", &number);

int LastDigit = number % 10;

printf ("Вывод: %d\n ", LastDigit);

return 0;
}
