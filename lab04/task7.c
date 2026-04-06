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
    int количество;
    
    // Вводим данные
    printf("Сколько человек ввести? ");
    scanf("%d", &количество);
    getchar();  // чистим буфер
    
    // Выделяем память под массив структур
    люди = (struct Person*)malloc(количество * sizeof(struct Person));
    if (люди == NULL) {
        printf("Ошибка памяти!\n");
        return 1;
    }
    
    // Заполняем
    printf("\n=== ВВОД ДАННЫХ ===\n");
    for (int i = 0; i < количество; i++) {
        printf("\nЧеловек %d:\n", i + 1);
        printf("  Имя: ");
        fgets(люди[i].имя, sizeof(люди[i].имя), stdin);
        люди[i].имя[strcspn(люди[i].имя, "\n")] = 0;
        
        printf("  Возраст: ");
        scanf("%d", &люди[i].возраст);
        getchar();  // чистим буфер
    }
    
    // Записываем весь массив в файл
    файл = fopen("people.bin", "wb");
    if (файл == NULL) {
        printf("Ошибка создания файла!\n");
        free(люди);
        return 1;
    }
    
    fwrite(люди, sizeof(struct Person), количество, файл);
    fclose(файл);
    
    printf("\n✓ Записано %d человек в people.bin\n", количество);
    
    // Читаем обратно
    файл = fopen("people.bin", "rb");
    if (файл == NULL) {
        printf("Ошибка открытия файла!\n");
        free(люди);
        return 1;
    }
    
    // Узнаём, сколько записей в файле
    fseek(файл, 0, SEEK_END);
    long размер_файла = ftell(файл);
    rewind(файл);
    
    int количество_в_файле = размер_файла / sizeof(struct Person);
    
    // Выделяем память и читаем
    struct Person *прочитанные = (struct Person*)malloc(размер_файла);
    fread(прочитанные, sizeof(struct Person), количество_в_файле, файл);
    fclose(файл);
    
    // Выводим
    printf("\n=== ПРОЧИТАННЫЕ ДАННЫЕ ===\n");
    for (int i = 0; i < количество_в_файле; i++) {
        printf("%d. %s, %d лет\n", 
               i + 1, 
               прочитанные[i].имя, 
               прочитанные[i].возраст);
    }
    
    free(люди);
    free(прочитанные);
    
    return 0;
}