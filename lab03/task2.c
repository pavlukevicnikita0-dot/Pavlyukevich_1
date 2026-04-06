#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int *arr;
    int n;
    
    // Спрашиваем размер массива
    printf("Сколько элементов будет в массиве? ");
    scanf("%d", &n);
    
    // Выделяем память через calloc (сам обнуляет всё)
    arr = (int*)calloc(n, sizeof(int));
    
    // Проверка: вдруг памяти нет
    if (arr == NULL) {
        printf("Ошибка: память не выделилась\n");
        return 1;
    }
    
    // Выводим значения элементов (будут нули, даже если ничего не клали)
    printf("\nМассив после calloc (все значения обнулены):\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    
    // Для наглядности выведем в строчку
    printf("\nВ одну строку: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Освобождаем память
    free(arr);
    
    return 0;
}