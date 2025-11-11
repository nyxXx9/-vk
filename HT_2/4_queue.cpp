#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 3

typedef struct {
    char items[MAX_SIZE];
    int rear;
    int front;
} Queue;

// Функция инициализации очереди
void initQueue(Queue* q) {
    q->front = -1;
    q->rear = 0;
}

char A[3] = {'a', 'b', 'c'};
char B[5] = {'g', 'a', 'j', 'b', 'm'};


char pop(Queue* q){ //удаляем поэлементно
    return q->items[q->front++];
}

void append(Queue* q, char A){ //добавляем А в очередь
    q->front = 0;
    q->items[q->rear++] = A;
}

int isEmpty(Queue* q) { //пуст или не пуст?
    return (q->front == -1 || q->front >= q->rear);
}

int main(){
    Queue q;
    initQueue(&q); //не вручную инициализируем

    // Добавляем массив A в очередь
    for(int i = 0; i < 3; i++) {
        append(&q, A[i]);
    }

    // Проверяем, содержится ли A в B
    for(int i = 0; i < 5 && !isEmpty(&q); i++) {
        if(B[i] == q.items[q.front]) {
            pop(&q);  // удаляем совпавший элемент
        }
    }

    if (isEmpty(&q)){
        printf("A исходна для строки B");
    }
    else{
        printf("A НЕ исходна для строки B");
    }
    return 0;
}

