#include <stdio.h>

int main () {

int N;
int i;

printf("Введите число: ");
scanf("%d", &N);

printf("Все четные числа от 0 до %d:\n", N); 
for (i = 0; i <=N; i += 2) {
printf("%d", i);
}
printf("\n");
return 0;
}

