#include <stdio.h>
#include <stdlib.h>

// Структура узла списка
typedef struct Node {
    int data;
    struct Node* next;
} Node;
// Структура списка
typedef struct {
    Node* head = NULL;
} LinkedList;

void append(LinkedList* list, int data);
void display(LinkedList* list);
Node* reverse(LinkedList* list);

int main(){
    LinkedList list;
    append(&list, 1);
    append(&list, 2);
    append(&list, 3);
    append(&list, 4);
    display(&list);
    reverse(&list);
    display(&list);


    return 0;
}

//добавление в начало
void append(LinkedList* list, int data) {
    Node* new_node = (Node*)calloc(1,sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;


    if (list->head == NULL) {
        new_node->next = NULL;
        list->head = new_node;
    }

    else {
        new_node->next = list->head;
        list->head = new_node;
    }
}
//------------------------------------------------------------------------------------------------
//разворот
Node* reverse(LinkedList* list){
    Node* current = list-> head;
    Node* prev = NULL;

    while (current != NULL){
    Node* next = current->next;
    current->next = prev;

    prev = current;
    current = next;
    }

    list->head = prev;
    return list->head;

}
//------------------------------------------------------------------------------------------------
// Вывод списка
void display(LinkedList* list) {
    Node* current = list->head;
    printf("Список: ");
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf(" -> NULL\n");
}
