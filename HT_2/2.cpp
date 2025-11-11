#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

typedef struct{
    Node* head = 0;
} LinkedList;

void append(LinkedList* list, int data);
void display(LinkedList* list);
Node* middle(LinkedList* list);


int main(){
    LinkedList list;
    append(&list, 1);
    append(&list, 2);
    append(&list, 3);
    append(&list, 4);
    append(&list, 5);
    display(&list);

    middle(&list);

}


//----------------------------------------------------------------------
//added
void append(LinkedList* list, int data){
    Node* new_node = (Node*)calloc(1, sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (list->head == NULL){
        list->head = new_node;
    }

    else{
        new_node->next = list->head;
        list->head = new_node;

    }
}
//----------------------------------------------------------------
//printer
void display(LinkedList* list){
    Node* current = list->head;
    printf("Список:");
    while (current != NULL){
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf(" -> NULL\n");
}
//------------------------------------------
//середина
Node* middle(LinkedList* list){
    //проверка на пустоту
    if (list->head == NULL){
        return NULL;
    }

    Node* slow = list->head;
    Node* fast = list->head;

    while (fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    printf("%d", slow->data);
    return slow;

}
