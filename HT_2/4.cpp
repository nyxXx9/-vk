#include <stdio.h>
#include <stdlib.h>
//----------------------------------------------------------------------------------------------
//прототипы ф-ий
ListNode* removeElements(ListNode* head, int val);
void printList(ListNode* head);
ListNode* createNode(int val);
void appendNode(ListNode** head, int val);
//----------------------------------------------------------------------------------------------
typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;
//----------------------------------------------------------------------------------------------
int main() {
    ListNode* head = NULL;
    int n, value, valToRemove;

    printf("Введите количество элементов в списке: ");
    scanf("%d", &n);

    printf("Введите %d элементов:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        appendNode(&head, value);
    }

    printf("Исходный список: ");
    printList(head);

    printf("Введите значение для удаления: ");
    scanf("%d", &valToRemove);

    // Удаляем элементы
    head = removeElements(head, valToRemove);

    printf("Список после удаления: ");
    printList(head);

    return 0;
}
//----------------------------------------------------------------------------------------------
ListNode* removeElements(ListNode* head, int val) {
    ListNode* dummy = (ListNode*)malloc(sizeof(ListNode));
    dummy->next = head;
    ListNode* prev = dummy;
    ListNode* cur = head;

    while (cur != NULL) {
        if (cur->val == val) {
            prev->next = cur->next;
        } else {
            prev = cur;
        }
        cur = cur->next;
    }
    return dummy->next;
}
//----------------------------------------------------------------------------------------------
// Функция для печати списка
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}
//----------------------------------------------------------------------------------------------
// Функция для создания нового узла
ListNode* createNode(int val) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}
//----------------------------------------------------------------------------------------------
// Функция для добавления элемента в конец списка
void appendNode(ListNode** head, int val) {
    ListNode* newNode = createNode(val);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    ListNode* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

