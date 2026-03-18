#include <stdio.h>

int main() {

int number;

scanf("%d", &number);

printf("%d\n", number / 100);
printf("%d\n", (number / 10) % 10);
printf("%d\n", number % 10);

return 0;
}
