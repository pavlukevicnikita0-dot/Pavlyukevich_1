#include <stdio.h>

int main () {
int x;
printf("Введите свое число: ");
scanf("%d", &x);

if(x % 2 == 0) {
  printf("%d делится на 2\n", x);
} else {
  printf("%d ошибка, число не делится на 2\n", x);
}
if(x % 3 == 0) {
  printf("%d делится на 3\n", x);
} else {
printf("%d ошибка,число не делится на 3\n", x);
}
return 0;
}
