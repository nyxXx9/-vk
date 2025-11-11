#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

typedef struct {
    char items[MAX_SIZE];
    int rear;
    int front;
} Deque;

// Функция инициализации очереди
void initDeque(Deque* dq) {
    dq->front = -1;
    dq->rear = -1;
}
// Проверка на пустоту
int isEmpty(Deque *dq) {
    return dq->front == -1;
}
// Добавление в конец
void append(Deque *dq, char value) {
    if (isEmpty(dq)) {
        dq->front = 0;
        dq->rear = 0;
    } else {
        dq->rear = (dq->rear + 1) % MAX_SIZE; //кольцевая логика
    }
    dq->items[dq->rear] = value;
}

char pol[] = {"abcba"};
char NOTpol[] = {"Kitten"};
// Удаление из конца
char removeRear(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Дек пуст!\n");
        return '\0';
    }
    char value = dq->items[dq->rear];
    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = -1;
    } else {
        dq->rear = (dq->rear - 1 + MAX_SIZE) % MAX_SIZE;
    }
    return value;
}
// Удаление из начала
char removeFront(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Дек пуст!\n");
        return '\0';
    }
    char value = dq->items[dq->front];
    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = -1;
    } else {
        dq->front = (dq->front + 1) % MAX_SIZE;
    }
    return value;
}

// Проверка палиндрома с помощью дека
int check(char* str) {
    Deque dq;
    initDeque(&dq);
    int len = strlen(str);

    // Добавляем все символы в конец дека
    for (int i = 0; i < len; i++) {
        append(&dq, str[i]);
    }

    // Проверяем палиндром, сравнивая начало и конец
    while (!isEmpty(&dq) && dq.front != dq.rear) {
        char first = removeFront(&dq);
        char last = removeRear(&dq);
        if (first != last) {
            printf("'%s' - НЕ палиндром\n", str);
            return 0;
        }
    }
    printf("'%s' - палиндром\n", str);
    return 0;
}

int main(){
    check(pol);
    check(NOTpol);

    return 0;
}
