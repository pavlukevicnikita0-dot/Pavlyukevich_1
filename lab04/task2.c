#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *файл;
    char символ;
    
    // Запись: пользователь вводит текст
    printf("Введи текст (чтобы закончить, нажми Enter, потом Ctrl+D/Z):\n");
    
    файл = fopen("test.txt", "w");
    if (файл == NULL) {
        printf("Ошибка!\n");
        return 1;
    }
    
    // Читаем символы с клавиатуры и пишем в файл
    while ((символ = getchar()) != EOF) {
        putc(символ, файл);
    }
    
    fclose(файл);
    
    // Чтение и вывод на экран
    printf("\n\nСодержимое файла:\n");
    
    файл = fopen("test.txt", "r");
    if (файл == NULL) {
        printf("Ошибка!\n");
        return 1;
    }
    
    while ((символ = getc(файл)) != EOF) {
        putchar(символ);
    }
    
    fclose(файл);
    
    return 0;
}