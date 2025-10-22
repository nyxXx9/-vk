#include <stdio.h>
#include <stdlib.h>
//----------------------------------------------------------------------------------------------
//прототипы ф-ий
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);
ListNode* createNode(int val);
void printList(ListNode* head);
void appendNode(ListNode** head, int val);
//---------------------------------------------------------------------------------------------
typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;
//---------------------------------------------------------------------------------------------
int main() {
    ListNode* list1 = NULL;
    ListNode* list2 = NULL;
    int n1, n2, value;

    // Ввод первого списка
    printf("Введите количество элементов в первом списке: ");
    scanf("%d", &n1);
    printf("Введите %d отсортированных элементов:\n", n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &value);
        appendNode(&list1, value);
    }

    // Ввод второго списка
    printf("Введите количество элементов во втором списке: ");
    scanf("%d", &n2);
    printf("Введите %d отсортированных элементов:\n", n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &value);
        appendNode(&list2, value);
    }

    printf("Первый список: ");
    printList(list1);
    printf("Второй список: ");
    printList(list2);

    // Объединение списков
    ListNode* merged = mergeTwoLists(list1, list2);

    printf("Объединенный список: ");
    printList(merged);

    return 0;
}
//---------------------------------------------------------------------------------------------
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    // Создаем фиктивный узел (упрощаю логику)
    ListNode dummy;
    ListNode* tail = &dummy;
    dummy.next = NULL;

    while (list1 != NULL && list2 != NULL) {
        if (list1->val <= list2->val) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    // Присоединяем оставшиеся узлы
    if (list1 != NULL) {
        tail->next = list1;
    } else {
        tail->next = list2;
    }

    return dummy.next;
}
//---------------------------------------------------------------------------------------------
// Функция для создания нового узла
ListNode* createNode(int val) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}
//---------------------------------------------------------------------------------------------
// Функция для печати списка
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}
//---------------------------------------------------------------------------------------------
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

