#include <stdlib.h>

int subarraySum(int* nums, int n, int k) {
    int count = 0, sum = 0;
    int* map = calloc(20000, sizeof(int));

    map[10000] = 1;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
        int target = sum - k;
        if (map[target + 10000] > 0)
            count += map[target + 10000];
        map[sum + 10000]++;
    }
    free(map);
    return count;
}
