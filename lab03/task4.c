#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int n, m;
    
    // Начальный размер
    printf("Сколько элементов будет изначально? ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Размер должен быть положительным!\n");
        return 1;
    }
    
    // Создаём начальный массив
    arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Память не выделилась(\n");
        return 1;
    }
    
    // Заполняем начальный массив
    printf("\nВведи %d чисел:\n", n);
    for (int i = 0; i < n; i++) {
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    
    printf("\nИзначальный массив: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // ===== УВЕЛИЧИВАЕМ РАЗМЕР =====
    printf("\nДо скольки элементов увеличить массив? ");
    scanf("%d", &m);
    
    if (m > n) {
        // Расширяем массив через realloc
        arr = (int*)realloc(arr, m * sizeof(int));
        if (arr == NULL) {
            printf("Не удалось расширить память!\n");
            return 1;
        }
        
        // Вводим новые элементы
        printf("Введи %d новых элементов (индексы от %d до %d):\n", m - n, n, m - 1);
        for (int i = n; i < m; i++) {
            printf("arr[%d]: ", i);
            scanf("%d", &arr[i]);
        }
        
        printf("\nМассив после расширения: ");
        for (int i = 0; i < m; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        printf("Новый размер должен быть больше старого!\n");
    }
    
    // ===== УМЕНЬШАЕМ РАЗМЕР =====
    int k;
    printf("\nДо скольки элементов уменьшить массив? ");
    scanf("%d", &k);
    
    if (k > 0 && k < m) {
        // Уменьшаем массив через realloc
        arr = (int*)realloc(arr, k * sizeof(int));
        if (arr == NULL && k > 0) {
            printf("Не удалось уменьшить память!\n");
            return 1;
        }
        
        printf("\nМассив после уменьшения (осталось %d элементов):\n", k);
        for (int i = 0; i < k; i++) {
            printf("arr[%d] = %d\n", i, arr[i]);
        }
        
        printf("\nВ одну строку: ");
        for (int i = 0; i < k; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        printf("Некорректный размер для уменьшения!\n");
    }
    
    // Чистим память
    free(arr);
    
    return 0;
}