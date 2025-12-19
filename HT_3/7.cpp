#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET 26

typedef struct {
    char** arr;
    int size;
} Group;

int compare(const void* a, const void* b) {
    return *(char*)a - *(char*)b;
}

int main() {
    char* input[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    int n = 6;

    char sorted[6][4];
    for (int i = 0; i < n; i++) {
        strcpy(sorted[i], input[i]);
        qsort(sorted[i], strlen(sorted[i]), sizeof(char), compare);
    }

    Group groups[6];
    int groupCount = 0;
    int used[6] = {0};

    for (int i = 0; i < n; i++) {
        if (used[i]) continue;

        groups[groupCount].arr = malloc(6 * sizeof(char*));
        groups[groupCount].size = 0;

        groups[groupCount].arr[groups[groupCount].size++] = input[i];
        used[i] = 1;

        for (int j = i + 1; j < n; j++) {
            if (!used[j] && strcmp(sorted[i], sorted[j]) == 0) {
                groups[groupCount].arr[groups[groupCount].size++] = input[j];
                used[j] = 1;
            }
        }
        groupCount++;
    }

    for (int i = 0; i < groupCount; i++) {
        printf("[");
        for (int j = 0; j < groups[i].size; j++) {
            printf("\"%s\"", groups[i].arr[j]);
            if (j < groups[i].size - 1) printf(",");
        }
        printf("]\n");
        free(groups[i].arr);
    }

    return 0;
}
