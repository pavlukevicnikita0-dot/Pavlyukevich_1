#include <stdio.h>

int main() {

int x;

int result1, result2;

printf("Введите число: ");
scanf("%d", &x);

result1 = x * x + 2 * x + 1;

result2 = (x + 1) * (x + 1) - (x - 1)* (x - 1);

printf("%d\n", result1);
printf("%d\n", result2);

return 0;
}