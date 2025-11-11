#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

char pol[] = {"abcba"};
char NOTpol[] = {"Kitten"};


typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

// Инициализация стека
void initStack(Stack* s) {
    s->top = -1;
}

void append(Stack* s, char value){
    s->data[++(s->top)] = value;
}

char pop(Stack* s) {
    return s->data[(s->top)--];
}

void printStack(Stack* s) {
    printf("Содержимое стека: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%c ", s->data[i]);
    }
    printf("\n");
}

int check(char str[]){
    Stack stack;
    initStack(&stack);
    int len = strlen(str);
     // Добавляем все символы в стек
    for (int i = 0; i < len; i++) {
        append(&stack, str[i]);
    }

    // Проверяем палиндром
    for (int i = 0; i < len; i++) {
        if (str[i] != pop(&stack)) {
            printf("%s - НЕ палиндром\n", str);
            return 0;//exit(1);
        }
    }
    printf("%s - палиндром\n", str);
    return 0;
}

int main(){
    Stack s;
    initStack(&s);

    // Добавляем строку посимвольно
    for (int i = 0; i < strlen(pol); i++) {
        append(&s, pol[i]);  // Передаем отдельные символы
    }

    printStack(&s);

    check(pol);
    check(NOTpol);

    return 0;
}
