#include <stdio.h>
#include <string.h>

// Перечисление для курса
enum Course {
    FIRST = 1,    // 1 курс
    SECOND,       // 2 курс
    THIRD,        // 3 курс
    FOURTH        // 4 курс
};

// Структура Student
struct Student {
    char name[50];
    int age;
    enum Course course;
    float averageGrade;   // средний балл
};

// Функция получения названия курса
const char* getCourseName(enum Course c) {
    switch (c) {
        case FIRST:  return "1 курс";
        case SECOND: return "2 курс";
        case THIRD:  return "3 курс";
        case FOURTH: return "4 курс";
        default:     return "Неизвестно";
    }
}

// 1. Функция добавления студента (по указателю)
void addStudent(struct Student *s, const char *name, int age, enum Course course, float grade) {
    strcpy(s->name, name);
    s->age = age;
    s->course = course;
    s->averageGrade = grade;
}

// 2. Функция вывода одного студента
void printStudent(struct Student *s) {
    printf("Имя: %s, Возраст: %d, Курс: %s, Средний балл: %.2f\n",
           s->name, s->age, getCourseName(s->course), s->averageGrade);
}

// 3. Функция вывода всех студентов
void printAllStudents(struct Student *students, int count) {
    if (count == 0) {
        printf("Список студентов пуст.\n");
        return;
    }
    
    printf("\n=== Список студентов ===\n");
    for (int i = 0; i < count; i++) {
        printf("%d. ", i + 1);
        printStudent(&students[i]);
    }
}

// 4. Функция поиска студента по имени (возвращает индекс, -1 если не найден)
int findByName(struct Student *students, int count, const char *name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

// 5. Функция сортировки по среднему баллу (пузырьком, по убыванию)
void sortByAverage(struct Student *students, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (students[j].averageGrade < students[j + 1].averageGrade) {
                // Меняем местами
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    printf("\nСортировка по среднему баллу выполнена.\n");
}

// Дополнительно: функция удаления студента по индексу
void deleteStudent(struct Student *students, int *count, int index) {
    if (index < 0 || index >= *count) {
        printf("Ошибка: неверный индекс\n");
        return;
    }
    
    for (int i = index; i < *count - 1; i++) {
        students[i] = students[i + 1];
    }
    (*count)--;
    printf("Студент удалён.\n");
}

int main() {
    struct Student students[100];  // максимум 100 студентов
    int studentCount = 0;          // текущее количество студентов
    
    int choice;
    char searchName[50];
    int index;
    char name[50];
    int age;
    int courseNum;
    float grade;
    
    do {
        printf("\n=== МЕНЮ ===\n");
        printf("1. Добавить студента\n");
        printf("2. Вывести всех студентов\n");
        printf("3. Поиск по имени\n");
        printf("4. Сортировка по среднему баллу\n");
        printf("5. Удалить студента\n");
        printf("0. Выход\n");
        printf("Выберите действие: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:  // Добавление студента
                if (studentCount >= 100) {
                    printf("Достигнут максимум студентов (100)\n");
                    break;
                }
                
                printf("Введите имя: ");
                scanf("%s", name);
                
                printf("Введите возраст: ");
                scanf("%d", &age);
                
                printf("Введите курс (1-4): ");
                scanf("%d", &courseNum);
                while (courseNum < 1 || courseNum > 4) {
                    printf("Курс должен быть от 1 до 4. Повторите: ");
                    scanf("%d", &courseNum);
                }
                
                printf("Введите средний балл: ");
                scanf("%f", &grade);
                
                addStudent(&students[studentCount], name, age, (enum Course)courseNum, grade);
                studentCount++;
                printf("Студент добавлен!\n");
                break;
                
            case 2:  // Вывод всех студентов
                printAllStudents(students, studentCount);
                break;
                
            case 3:  // Поиск по имени
                if (studentCount == 0) {
                    printf("Список студентов пуст.\n");
                    break;
                }
                
                printf("Введите имя для поиска: ");
                scanf("%s", searchName);
                index = findByName(students, studentCount, searchName);
                
                if (index != -1) {
                    printf("\nСтудент найден:\n");
                    printStudent(&students[index]);
                } else {
                    printf("Студент с именем '%s' не найден.\n", searchName);
                }
                break;
                
            case 4:  // Сортировка по среднему баллу
                if (studentCount == 0) {
                    printf("Нет студентов для сортировки.\n");
                    break;
                }
                sortByAverage(students, studentCount);
                printAllStudents(students, studentCount);
                break;
                
            case 5:  // Удаление студента
                if (studentCount == 0) {
                    printf("Список студентов пуст.\n");
                    break;
                }
                
                printf("Введите имя студента для удаления: ");
                scanf("%s", searchName);
                index = findByName(students, studentCount, searchName);
                
                if (index != -1) {
                    deleteStudent(students, &studentCount, index);
                } else {
                    printf("Студент с именем '%s' не найден.\n", searchName);
                }
                break;
                
            case 0:
                printf("Выход из программы.\n");
                break;
                
            default:
                printf("Неверный выбор. Попробуйте снова.\n");
        }
    } while (choice != 0);
    
    return 0;
}