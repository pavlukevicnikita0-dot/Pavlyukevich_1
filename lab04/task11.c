#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *файл;
    char символ;
    
    // Создаём тестовый файл
    файл = fopen("test.txt", "w");
    if (файл) {
        fprintf(файл, "Hello, World!\n");
        fprintf(файл, "This is line 2\n");
        fprintf(файл, "And line 3\n");
        fclose(файл);
    }
    
    // Открываем для чтения
    файл = fopen("test.txt", "r");
    if (файл == NULL) {
        printf("Ошибка открытия файла!\n");
        return 1;
    }
    
    printf("Читаем файл с проверкой конца и ошибок:\n");
    printf("----------------------------------------\n");
    
    // Читаем посимвольно
    while (1) {
        символ = fgetc(файл);
        
        if (символ == EOF) {
            // Дошли до конца или ошибка?
            if (feof(файл)) {
                printf("\n[Достигнут конец файла]");
                break;
            } else if (ferror(файл)) {
                printf("\n[Ошибка при чтении файла!]");
                break;
            }
        } else {
            putchar(символ);
        }
    }
    
    printf("\n----------------------------------------\n");
    
    // Проверяем статус после чтения
    if (feof(файл)) {
        printf("✓ Чтение завершено: достигнут конец файла\n");
    }
    if (ferror(файл)) {
        printf("✗ Была ошибка при чтении!\n");
    }
    
    fclose(файл);
    
    return 0;
}