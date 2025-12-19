#include <stdlib.h>

int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

long long copyTime(int n, int x, int y) {
    if (n == 1) return min(x, y);

    long long l = 0;
    long long r = (long long)(n - 1) * max(x, y);

    while (l + 1 < r) {
        long long mid = l + (r - l) / 2;
        if (mid / x + mid / y < n - 1) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return r + min(x, y);
}
