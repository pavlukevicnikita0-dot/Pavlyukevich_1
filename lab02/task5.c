#include <stdio.h>

// 1. Создаём перечисление Day (дни недели)
enum Day {
    MONDAY,     // 0
    TUESDAY,    // 1
    WEDNESDAY,  // 2
    THURSDAY,   // 3
    FRIDAY,     // 4
    SATURDAY,   // 5
    SUNDAY      // 6
};

// 3. Используем enum внутри структуры
struct Event {
    char name[50];
    enum Day eventDay;  // день недели, когда происходит событие
};

// Функция для получения названия дня по enum (чтобы красиво выводить)
const char* getDayName(enum Day d) {
    switch (d) {
        case MONDAY:    return "Понедельник";
        case TUESDAY:   return "Вторник";
        case WEDNESDAY: return "Среда";
        case THURSDAY:  return "Четверг";
        case FRIDAY:    return "Пятница";
        case SATURDAY:  return "Суббота";
        case SUNDAY:    return "Воскресенье";
        default:        return "Неизвестно";
    }
}

int main() {
    // 1. Создаём переменную типа enum Day
    enum Day today;
    today = WEDNESDAY;  // ставим среду
    
    // 2. Выводим значение с помощью конструкции switch
    printf("=== Задание 2: switch ===\n");
    printf("Сегодня: ");
    
    switch (today) {
        case MONDAY:
            printf("Понедельник\n");
            break;
        case TUESDAY:
            printf("Вторник\n");
            break;
        case WEDNESDAY:
            printf("Среда\n");
            break;
        case THURSDAY:
            printf("Четверг\n");
            break;
        case FRIDAY:
            printf("Пятница\n");
            break;
        case SATURDAY:
            printf("Суббота\n");
            break;
        case SUNDAY:
            printf("Воскресенье\n");
            break;
        default:
            printf("Ошибка\n");
    }
    
    // 3. Используем enum внутри структуры
    printf("\n=== Задание 3: enum внутри структуры ===\n");
    
    // Создаём несколько событий
    struct Event events[3] = {
        {"Зарядка",      MONDAY},
        {"Встреча с другом", FRIDAY},
        {"Поездка на рыбалку", SATURDAY}
    };
    
    // Выводим все события
    for (int i = 0; i < 3; i++) {
        printf("Событие: %s, День: %s\n", 
               events[i].name, 
               getDayName(events[i].eventDay));
    }
    
    // Дополнительно: показываем, что enum - это просто числа
    printf("\n=== А можно и так (enum = числа) ===\n");
    printf("MONDAY = %d\n", MONDAY);
    printf("TUESDAY = %d\n", TUESDAY);
    printf("SUNDAY = %d\n", SUNDAY);
    
    return 0;
}