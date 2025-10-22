#include <stdio.h>
#include <stdlib.h>
//--------------------------------------------------------------------------------------------
//прототипы ф-ий
Node* middleNode(Node* head);
void printList(Node* head);
Node* createNode(int data);
void appendNode(Node** head, int data);
//--------------------------------------------------------------------------------------------
typedef struct Node {
    int data;
    struct Node* next;
} Node;
//--------------------------------------------------------------------------------------------
int main() {
    Node* head = NULL;
    int n, value;

    printf("Введите количество элементов в списке: ");
    scanf("%d", &n);

    printf("Введите %d элементов:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        appendNode(&head, value);
    }

    printf("Исходный список: ");
    printList(head);

    // Находим середину списка
    Node* middle = middleNode(head);

    printf("Середина списка: %d\n", middle->data);

    return 0;
}
//--------------------------------------------------------------------------------------------
Node* middleNode(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
//--------------------------------------------------------------------------------------------
// Функция для печати списка
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
//--------------------------------------------------------------------------------------------
// Функция для создания нового узла
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
//--------------------------------------------------------------------------------------------
// Функция для добавления элемента в конец списка
void appendNode(Node** head, int data) {
    Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

