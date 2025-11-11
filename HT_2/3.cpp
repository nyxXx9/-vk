#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

typedef struct{
    Node* head = NULL;
} LinkedList;

void display(LinkedList* list);
void append(LinkedList* list, int data);
Node* pop(LinkedList* list, int data);

int main(){

    LinkedList list;
    append(&list, 1);
    append(&list, 2);
    append(&list, 3);
    append(&list, 4);
    display(&list);
    pop(&list, 4);
    display(&list);
    pop(&list, 1);
    display(&list);
    pop(&list, 34);
    display(&list);



    return 0;
}


void display(LinkedList* list){
    Node* current = list->head;

    printf("Список: ");

    while (current != NULL){
        printf("%d", current->data);
        if (current->next != NULL){
            printf(" -> ");
        }
        current = current->next;
    }
    printf("-> NULL\n");
}

void append(LinkedList* list, int data){
    Node* new_node = (Node*)calloc(1, sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (list->head == NULL){
        new_node->next = NULL;
        list->head = new_node;

    }

    else{
        new_node->next = list->head;
        list->head = new_node;
    }
}
//-----------------------------------------------------------------------
Node* pop(LinkedList* list, int data){
    int val = data;

    Node* dummy = (Node*)calloc(1, sizeof(Node));
    dummy->next = list->head;
    Node* prev = dummy;
    Node* current = list->head;


    while (current != NULL){
        if (current->data == val){
            prev->next = current->next;
            list->head = dummy->next;
        }
        else{
            prev = current;
        }
        current = current->next;
    }

    return list->head;
}
//-----------------------------------------------------------------------
