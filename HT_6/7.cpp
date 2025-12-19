int findLIS(int* nums, int n) {
    if (n == 0) return 0;

    int dp[n], max = 1;
    dp[0] = 1;

    for (int i = 1; i < n; i++) {
        dp[i] = 1;
        if (nums[i-1] < nums[i]) dp[i] = dp[i-1] + 1;
        if (dp[i] > max) max = dp[i];
    }
    return max;
}
