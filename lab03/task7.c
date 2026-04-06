#include <stdio.h>
#include <stdlib.h>

struct Student {
    char имя[50];
    int возраст;
};

// Функция ввода студентов
void ввести_студентов(struct Student *студенты, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nСтудент %d:\n", i + 1);
        printf("  Имя: ");
        scanf("%s", студенты[i].имя);
        printf("  Возраст: ");
        scanf("%d", &студенты[i].возраст);
    }
}

// Функция вывода
void вывести_студентов(struct Student *студенты, int n) {
    printf("\nСписок студентов:\n");
    for (int i = 0; i < n; i++) {
        printf("  %d. %s - %d лет\n", i + 1, студенты[i].имя, студенты[i].возраст);
    }
}

// Функция поиска самого старшего
int найти_старшего(struct Student *студенты, int n) {
    int индекс = 0;
    for (int i = 1; i < n; i++) {
        if (студенты[i].возраст > студенты[индекс].возраст) {
            индекс = i;
        }
    }
    return индекс;
}

int main() {
    struct Student *студенты;
    int n;
    
    printf("Сколько студентов? ");
    scanf("%d", &n);
    
    студенты = (struct Student*)malloc(n * sizeof(struct Student));
    
    ввести_студентов(студенты, n);
    вывести_студентов(студенты, n);
    
    int старший = найти_старшего(студенты, n);
    printf("\nСамый старший студент: %s (%d лет)\n", 
           студенты[старший].имя, 
           студенты[старший].возраст);
    
    free(студенты);
    return 0;
}