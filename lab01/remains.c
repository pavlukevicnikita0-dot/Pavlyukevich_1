#include <stdio.h> 

int main() {

int a,b;

int remainder;

printf("Введите первое число:");
scanf("%d",&a); 

printf("Введите второе число:");
scanf("%d",&b);

remainder = a % b;

printf("%d %% %d = %d\n", a, b, remainder);

 return 0;
}