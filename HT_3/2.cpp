#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int feedAnimals(int* animals, int animalsSize, int* food, int foodSize) {
    if (animalsSize == 0 || foodSize == 0) return 0;

    qsort(animals, animalsSize, sizeof(int), compare);
    qsort(food, foodSize, sizeof(int), compare);

    int count = 0;
    for (int i = 0; i < foodSize; i++) {
        if (food[i] >= animals[count]) {
            count++;
            if (count == animalsSize) break;
        }
    }
    return count;
}
