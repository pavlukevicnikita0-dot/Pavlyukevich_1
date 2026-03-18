#include <stdio.h>

int main () {

int seconds;

scanf("%d", &seconds);

int hours = (seconds / 3600) % 24;
int minutes = (seconds / 3600) / 60;
int sec = (seconds % 60);

printf("%02d:%02d:%02d\n", hours, minutes, sec);

return 0;
}