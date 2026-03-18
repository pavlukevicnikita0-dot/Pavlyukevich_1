#include <stdio.h>

int main () {

int N;
int i;
printf("Введите число: ");
scanf("%d", &N);
printf("Все нечетные числа от 0 до %d:\n", N);
for (i = 1; i <= N; i += 2) {
  printf("%d", i);
}
return 0;
}


