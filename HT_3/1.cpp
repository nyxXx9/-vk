#include <stdio.h>
#include <stdlib.h>

struct hashNode {
    int key;
    int value;
    struct hashNode* next;
};

struct hashMap {
    struct hashNode** table;
    int size;
};

struct hashMap* createHashMap(int size) {
    struct hashMap* map = malloc(sizeof(struct hashMap));
    map->size = size;
    map->table = calloc(size, sizeof(struct hashNode*));
    return map;
}

int hash(int key, int size) {
    return abs(key) % size;
}

void insert(struct hashMap* map, int key, int value) {
    int index = hash(key, map->size);
    struct hashNode* newNode = malloc(sizeof(struct hashNode));
    newNode->key = key;
    newNode->value = value;
    newNode->next = map->table[index];
    map->table[index] = newNode;
}

int find(struct hashMap* map, int key) {
    int index = hash(key, map->size);
    struct hashNode* current = map->table[index];
    while (current != NULL) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }
    return -1;
}

int* twoSum(int* data, int dataSize, int target, int* returnSize) {
    *returnSize = 2;
    int* result = malloc(2 * sizeof(int));
    struct hashMap* map = createHashMap(dataSize * 2);

    for (int i = 0; i < dataSize; i++) {
        insert(map, data[i], i);
    }

    for (int i = 0; i < dataSize; i++) {
        int diff = target - data[i];
        int j = find(map, diff);
        if (j != -1 && j != i) {
            result[0] = i;
            result[1] = j;
            free(map->table);
            free(map);
            return result;
        }
    }

    *returnSize = 0;
    free(map->table);
    free(map);
    free(result);
    return NULL;
}
