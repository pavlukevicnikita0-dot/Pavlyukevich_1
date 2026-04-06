#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int *arr;
    int n;
    
    // Спрашиваем, сколько чисел будет
    printf("Сколько чисел хотите ввести? ");
    scanf("%d", &n);
    
    // Выделяем память под n целых чисел
    arr = (int*)malloc(n * sizeof(int));
    
    // Если память не выделилась (мало ли)
    if (arr == NULL) {
        printf("Не хватает памяти, сорян(\n");
        return 1;
    }
    
    // Заполняем массив с клавиатуры
    printf("Введите %d чисел:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Число %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    // Выводим результат
    printf("\nТвой массив:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Чистим за собой память (хороший тон)
    free(arr);
    
    return 0;
}