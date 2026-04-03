#include <stdio.h>

// Структура для даты
struct Date {
    int day;
    int month;
    int year;
};

// Структура для человека (вложенная структура Date)
struct Person {
    char name[50];
    struct Date birthDate;
};

int main() {
    // 1. Заполняем структуры (создаём несколько людей)
    struct Person people[4] = {
        {"Анна", {15, 5, 1998}},      // родилась в 1998
        {"Иван", {22, 11, 2005}},     // родился в 2005
        {"Мария", {3, 8, 2001}},      // родилась в 2001
        {"Петр", {19, 2, 1995}}       // родился в 1995
    };

    int count = 4; // количество людей

    // 2. Выводим данные всех людей
    printf("=== Все люди ===\n");
    for (int i = 0; i < count; i++) {
        printf("Имя: %s, Дата рождения: %02d.%02d.%d\n",
               people[i].name,
               people[i].birthDate.day,
               people[i].birthDate.month,
               people[i].birthDate.year);
    }

    // 3. Выводим только тех, кто родился после 2000 года
    printf("\n=== Родившиеся после 2000 года ===\n");
    for (int i = 0; i < count; i++) {
        if (people[i].birthDate.year > 2000) {
            printf("Имя: %s, Дата рождения: %02d.%02d.%d\n",
                   people[i].name,
                   people[i].birthDate.day,
                   people[i].birthDate.month,
                   people[i].birthDate.year);
        }
    }

    return 0;
}