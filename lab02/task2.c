#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int age;
    float ball;
    char group[20];
};

int main() {
    struct Student students[5];
    int i, max;
    float maxBall;
    
    // Заполняем данными
    strcpy(students[0].name, "Иванов Иван");
    students[0].age = 19;
    students[0].ball = 4.7;
    strcpy(students[0].group, "ИВТ-21");
    
    strcpy(students[1].name, "Петрова Анна");
    students[1].age = 20;
    students[1].ball = 4.9;
    strcpy(students[1].group, "ИВТ-21");
    
    strcpy(students[2].name, "Сидоров Алексей");
    students[2].age = 18;
    students[2].ball = 4.2;
    strcpy(students[2].group, "ПИ-11");
    
    strcpy(students[3].name, "Козлова Екатерина");
    students[3].age = 19;
    students[3].ball = 5.0;
    strcpy(students[3].group, "ИВТ-21");
    
    strcpy(students[4].name, "Михайлов Дмитрий");
    students[4].age = 21;
    students[4].ball = 4.5;
    strcpy(students[4].group, "ПИ-11");
    
    // Выводим всех студентов
    printf("\n========== СПИСОК СТУДЕНТОВ ==========\n\n");
    
    for(i = 0; i < 5; i++) {
        printf("%d. %s\n", i+1, students[i].name);
        printf("   Возраст: %d\n", students[i].age);
        printf("   Группа: %s\n", students[i].group);
        printf("   Средний балл: %.1f\n", students[i].ball);
        printf("   -------------------------\n");
    }
    
    // Ищем студента с максимальным баллом
    max = 0;
    maxBall = students[0].ball;
    
    for(i = 1; i < 5; i++) {
        if(students[i].ball > maxBall) {
            maxBall = students[i].ball;
            max = i;
        }
    }
    
    // Выводим результат
    printf("\n====== СТУДЕНТ С ЛУЧШИМ БАЛЛОМ ======\n\n");
    printf("ФИО: %s\n", students[max].name);
    printf("Возраст: %d\n", students[max].age);
    printf("Группа: %s\n", students[max].group);
    printf("Средний балл: %.1f\n", students[max].ball);
    printf("======================================\n");
    
    return 0;
}
