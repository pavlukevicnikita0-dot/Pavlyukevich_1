#include <windows.h>
#include <stdio.h>
struct Student
{
    char name[50];
    int age;
    float avarage;
};
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    struct Student student;
    printf("Введите имя: ");
    scanf("%s", student.name);
    printf("Введите ваш возраст: ");
    scanf("%d", &student.age);
    printf("Введите средний балл: ");
    scanf("%f", &student.avarage);

    // Вывод текст
    printf("\n  ;)  Данные студента   ;)   \n");
    printf("Имя студента:%s\n", student.name);
    printf("Возвраст студента:%d\n", student.age);
    printf("Средний балл студента:%.2f\n", student.avarage);
    return 0;
}
