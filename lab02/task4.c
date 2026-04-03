#include <stdio.h>

// Структура Rectangle (прямоугольник)
struct Rectangle {
    float width;   // ширина
    float height;  // высота
};

// 1. Функция вычисления площади (передача по значению)
float areaByValue(struct Rectangle r) {
    return r.width * r.height;
}

// 2. Функция вычисления периметра (передача по значению)
float perimeterByValue(struct Rectangle r) {
    return 2 * (r.width + r.height);
}

// 3. Функция вычисления площади (передача по указателю)
float areaByPointer(struct Rectangle *r) {
    return r->width * r->height;
}

// 4. Функция вычисления периметра (передача по указателю)
float perimeterByPointer(struct Rectangle *r) {
    return 2 * (r->width + r->height);
}

int main() {
    // Создаём прямоугольник
    struct Rectangle rect;
    
    // Вводим данные с клавиатуры
    printf("Введите ширину прямоугольника: ");
    scanf("%f", &rect.width);
    
    printf("Введите высоту прямоугольника: ");
    scanf("%f", &rect.height);
    
    printf("\n=== Результаты ===\n");
    
    // Вызываем функции с передачей ПО ЗНАЧЕНИЮ
    printf("1. Передача по значению:\n");
    printf("   Площадь: %.2f\n", areaByValue(rect));
    printf("   Периметр: %.2f\n", perimeterByValue(rect));
    
    // Вызываем функции с передачей ПО УКАЗАТЕЛЮ
    printf("\n2. Передача по указателю:\n");
    printf("   Площадь: %.2f\n", areaByPointer(&rect));
    printf("   Периметр: %.2f\n", perimeterByPointer(&rect));
    
    return 0;
}