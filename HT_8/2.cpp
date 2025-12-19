int maxSubarraySum(int* arr, int n, int k) {
    if (n < k) return -1;

    int sum = 0;
    for (int i = 0; i < k; i++)
        sum += arr[i];

    int max = sum;
    for (int i = k; i < n; i++) {
        sum = sum - arr[i-k] + arr[i];
        if (sum > max) max = sum;
    }
    return max;
}
