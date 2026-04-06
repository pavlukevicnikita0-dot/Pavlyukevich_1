#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *файл;
    int n;
    char имя[50];
    int возраст;
    float зарплата;
    
    // Записываем данные, введенные пользователем
    printf("=== ВВОД ДАННЫХ ===\n");
    printf("Сколько человек ввести? ");
    scanf("%d", &n);
    getchar();  // чистим буфер
    
    файл = fopen("people.txt", "w");
    if (файл == NULL) {
        printf("Ошибка!\n");
        return 1;
    }
    
    fprintf(файл, "%-20s %-10s %-10s\n", "Имя", "Возраст", "Зарплата");
    fprintf(файл, "----------------------------------------\n");
    
    for (int i = 0; i < n; i++) {
        printf("\nЧеловек %d:\n", i + 1);
        printf("  Имя: ");
        scanf("%s", имя);
        printf("  Возраст: ");
        scanf("%d", &возраст);
        printf("  Зарплата: ");
        scanf("%f", &зарплата);
        
        fprintf(файл, "%-20s %-10d %-10.2f\n", имя, возраст, зарплата);
    }
    
    fclose(файл);
    printf("\n✓ Данные сохранены!\n");
    
    // Читаем и показываем
    printf("\n=== ДАННЫЕ ИЗ ФАЙЛА ===\n");
    файл = fopen("people.txt", "r");
    if (файл == NULL) {
        printf("Ошибка!\n");
        return 1;
    }
    
    char строка[200];
    while (fgets(строка, sizeof(строка), файл) != NULL) {
        printf("%s", строка);
    }
    
    fclose(файл);
    
    return 0;
}