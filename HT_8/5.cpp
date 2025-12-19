#include <stdlib.h>
#include <string.h>

int findMaxLength(int* nums, int n) {
    int* map = malloc((2*n+1)*sizeof(int));
    memset(map, -1, (2*n+1)*sizeof(int));

    int sum = n, max = 0;
    map[n] = 0;

    for (int i = 0; i < n; i++) {
        sum += (nums[i] == 0) ? -1 : 1;
        if (map[sum] != -1) {
            if (i+1 - map[sum] > max)
                max = i+1 - map[sum];
        } else {
            map[sum] = i+1;
        }
    }
    free(map);
    return max;
}
