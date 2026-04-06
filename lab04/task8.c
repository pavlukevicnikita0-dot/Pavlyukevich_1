#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    char имя[50];
    int возраст;
};

int main() {
    FILE *файл;
    struct Person *люди;
    struct Person *прочитанные;
    int количество;
    
    // Спрашиваем размер
    printf("Сколько человек будем вводить? ");
    scanf("%d", &количество);
    getchar();  // чистим буфер
    
    // Выделяем память под массив структур
    люди = (struct Person*)malloc(количество * sizeof(struct Person));
    if (люди == NULL) {
        printf("Ошибка выделения памяти!\n");
        return 1;
    }
    
    // Заполняем массив
    printf("\n=== ВВОД ДАННЫХ ===\n");
    for (int i = 0; i < количество; i++) {
        printf("\nЧеловек %d:\n", i + 1);
        printf("  Имя: ");
        fgets(люди[i].имя, sizeof(люди[i].имя), stdin);
        люди[i].имя[strcspn(люди[i].имя, "\n")] = 0;
        
        printf("  Возраст: ");
        scanf("%d", &люди[i].возраст);
        getchar();
    }
    
    // Записываем в файл
    printf("\n=== ЗАПИСЬ В ФАЙЛ ===\n");
    
    файл = fopen("people.bin", "wb");
    if (файл == NULL) {
        printf("Ошибка: не могу создать файл!\n");
        free(люди);
        return 1;
    }
    
    fwrite(люди, sizeof(struct Person), количество, файл);
    fclose(файл);
    
    printf("✓ Записано %d человек в файл 'people.bin'\n", количество);
    printf("  Размер файла: %d байт\n", количество * (int)sizeof(struct Person));
    
    // Читаем из файла
    printf("\n=== ЧТЕНИЕ ИЗ ФАЙЛА ===\n");
    
    файл = fopen("people.bin", "rb");
    if (файл == NULL) {
        printf("Ошибка: не могу открыть файл!\n");
        free(люди);
        return 1;
    }
    
    // Узнаём размер файла, чтобы понять, сколько там структур
    fseek(файл, 0, SEEK_END);
    long размер_файла = ftell(файл);
    rewind(файл);
    
    int количество_в_файле = размер_файла / sizeof(struct Person);
    printf("В файле найдено %d записей\n", количество_в_файле);
    
    // Выделяем память под прочитанные данные
    прочитанные = (struct Person*)malloc(размер_файла);
    if (прочитанные == NULL) {
        printf("Ошибка выделения памяти!\n");
        fclose(файл);
        free(люди);
        return 1;
    }
    
    fread(прочитанные, sizeof(struct Person), количество_в_файле, файл);
    fclose(файл);
    
    // Выводим всех
    printf("\n=== СПИСОК ЛЮДЕЙ ===\n");
    for (int i = 0; i < количество_в_файле; i++) {
        printf("%d. %s, %d лет\n", 
               i + 1, 
               прочитанные[i].имя, 
               прочитанные[i].возраст);
    }
    
    // Чистим память
    free(люди);
    free(прочитанные);
    
    return 0;
}