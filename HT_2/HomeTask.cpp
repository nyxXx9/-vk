#include <stdio.h>
#include <stdlib.h>
//играемся с указателями, перевязкой

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
void dano(LinkedList* list1, LinkedList* list2);
LinkedList* H(LinkedList* list1, LinkedList* list2);

int main(){
    LinkedList list1 = {NULL};
    LinkedList list2 = {NULL};
    dano(&list1, &list2);
    // Сливаем списки - list1 будет содержать результат
    LinkedList* mergedList = H(&list1, &list2);
    printf("Объединенный список:\n");
    display(mergedList);

    return 0;
}
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

void dano(LinkedList* list1, LinkedList* list2){

    append(list1, 8);
    append(list1, 6);
    append(list1, 3);

    append(list2, 20);
    append(list2, 11);
    append(list2, 9);
    append(list2, 7);
    append(list2, 4);


    display(list1);
    display(list2);
}

LinkedList* H(LinkedList* list1, LinkedList* list2){
    Node dummy = {0, NULL};
    Node* tail = &dummy;
    Node* l1 = list1->head;
    Node* l2 = list2->head;

  while (l1 != NULL && l2 != NULL) {
        if (l1->data < l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

// Добавляем оставшиеся элементы
    if (l1 != NULL) {
        tail->next = l1;
    } else {
        tail->next = l2;
    }

    list1->head = dummy.next;
    list2->head = NULL; //очищаем второй список
    return list1;
}
