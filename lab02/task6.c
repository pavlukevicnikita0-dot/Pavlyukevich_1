#include <stdio.h>

// 1. Создаём объединение Data
union Data {
    int i;
    float f;
    char c;
};

// 3. Создаём структуру, содержащую union и поле-индикатор типа
struct Container {
    union Data data;      // само объединение
    int type;             // 0 - int, 1 - float, 2 - char
};

// Функция для вывода содержимого структуры (чтобы удобно было)
void printContainer(struct Container cont) {
    switch (cont.type) {
        case 0:
            printf("Тип: int, Значение: %d\n", cont.data.i);
            break;
        case 1:
            printf("Тип: float, Значение: %.2f\n", cont.data.f);
            break;
        case 2:
            printf("Тип: char, Значение: '%c'\n", cont.data.c);
            break;
        default:
            printf("Неизвестный тип\n");
    }
}

int main() {
    printf("=== Задание 1 и 2: присваивание и демонстрация ===\n\n");
    
    // Создаём переменную объединения
    union Data myData;
    
    // Присваиваем int
    myData.i = 42;
    printf("1. Присвоили myData.i = 42\n");
    printf("   myData.i = %d\n", myData.i);
    printf("   myData.f = %f (мусор)\n", myData.f);
    printf("   myData.c = '%c' (мусор)\n\n", myData.c);
    
    // Присваиваем float (затирает int)
    myData.f = 3.14;
    printf("2. Присвоили myData.f = 3.14\n");
    printf("   myData.i = %d (мусор)\n", myData.i);
    printf("   myData.f = %f\n", myData.f);
    printf("   myData.c = '%c' (мусор)\n\n", myData.c);
    
    // Присваиваем char (затирает float)
    myData.c = 'A';
    printf("3. Присвоили myData.c = 'A'\n");
    printf("   myData.i = %d (мусор)\n", myData.i);
    printf("   myData.f = %f (мусор)\n", myData.f);
    printf("   myData.c = '%c'\n\n", myData.c);
    
    printf("=== Задание 3: структура с union и полем типа ===\n\n");
    
    // Создаём несколько контейнеров с разными типами данных
    struct Container c1, c2, c3;
    
    // Контейнер с int
    c1.data.i = 100;
    c1.type = 0;   // int
    
    // Контейнер с float
    c2.data.f = 99.99;
    c2.type = 1;   // float
    
    // Контейнер с char
    c3.data.c = 'Z';
    c3.type = 2;   // char
    
    // Выводим все контейнеры
    printf("Контейнер 1: ");
    printContainer(c1);
    
    printf("Контейнер 2: ");
    printContainer(c2);
    
    printf("Контейнер 3: ");
    printContainer(c3);
    
    // Дополнительно: показываем размер объединения и структуры
    printf("\n=== Размеры в памяти ===\n");
    printf("Размер union Data: %zu байт\n", sizeof(union Data));
    printf("Размер int: %zu байт\n", sizeof(int));
    printf("Размер float: %zu байт\n", sizeof(float));
    printf("Размер char: %zu байт\n", sizeof(char));
    printf("Размер struct Container: %zu байт\n", sizeof(struct Container));
    
    return 0;
}