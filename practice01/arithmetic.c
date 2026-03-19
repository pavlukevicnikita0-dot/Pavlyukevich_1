#include <stdio.h>

int main () {

int a,b,c;
printf("Введите три числа: ");
scanf("%d %d %d", &a, &b, &c);
float j = (a + b + c) / 3.00;
printf("Среднее арифметическое: %f\n", j);
return 0;
}
