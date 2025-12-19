int binarySearchSqrt(int target) {
    if (target <= 1) return target;

    long long l = 0, r = target;
    while (l <= r) {
        long long mid = l + (r - l) / 2;
        long long square = mid * mid;

        if (square > target) {
            r = mid - 1;
        } else if (square < target) {
            l = mid + 1;
        } else {
            return (int)mid;
        }
    }
    return (int)r;
}
