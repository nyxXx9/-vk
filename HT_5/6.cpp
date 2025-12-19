#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int value;
    int arrayIdx;
    int elementIdx;
} HeapNode;

typedef struct {
    HeapNode* arr;
    int size;
    int capacity;
} MinHeap;

MinHeap* createHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->arr = (HeapNode*)malloc(capacity * sizeof(HeapNode));
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(MinHeap* heap, int idx) {
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (heap->arr[idx].value < heap->arr[parent].value) {
            swap(&heap->arr[idx], &heap->arr[parent]);
            idx = parent;
        } else break;
    }
}

void heapifyDown(MinHeap* heap, int idx) {
    while (1) {
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;
        int smallest = idx;

        if (left < heap->size && heap->arr[left].value < heap->arr[smallest].value)
            smallest = left;
        if (right < heap->size && heap->arr[right].value < heap->arr[smallest].value)
            smallest = right;

        if (smallest != idx) {
            swap(&heap->arr[idx], &heap->arr[smallest]);
            idx = smallest;
        } else break;
    }
}

void push(MinHeap* heap, HeapNode node) {
    if (heap->size >= heap->capacity) return;
    heap->arr[heap->size] = node;
    heapifyUp(heap, heap->size);
    heap->size++;
}

HeapNode pop(MinHeap* heap) {
    HeapNode node = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    heapifyDown(heap, 0);
    return node;
}

bool isEmpty(MinHeap* heap) {
    return heap->size == 0;
}

int* mergeKSortedArrays(int** arrays, int k, int* sizes, int* totalSize) {
    int total = 0;
    for (int i = 0; i < k; i++) total += sizes[i];
    *totalSize = total;

    int* result = (int*)malloc(total * sizeof(int));
    MinHeap* heap = createHeap(k);

    for (int i = 0; i < k; i++) {
        if (sizes[i] > 0) {
            HeapNode node = {arrays[i][0], i, 0};
            push(heap, node);
        }
    }

    int idx = 0;
    while (!isEmpty(heap)) {
        HeapNode node = pop(heap);
        result[idx++] = node.value;

        if (node.elementIdx + 1 < sizes[node.arrayIdx]) {
            HeapNode nextNode = {
                arrays[node.arrayIdx][node.elementIdx + 1],
                node.arrayIdx,
                node.elementIdx + 1
            };
            push(heap, nextNode);
        }
    }

    free(heap->arr);
    free(heap);
    return result;
}

int main() {
    int arr1[] = {1, 4, 5};
    int arr2[] = {1, 3, 4};
    int arr3[] = {2, 6};

    int* arrays[] = {arr1, arr2, arr3};
    int sizes[] = {3, 3, 2};
    int k = 3;
    int totalSize;

    int* result = mergeKSortedArrays(arrays, k, sizes, &totalSize);

    printf("Merged: ");
    for (int i = 0; i < totalSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}
