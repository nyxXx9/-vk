void pascalIterative(int n) {
    int dp[n][n];
    for (int i = 0; i < n; i++) {
        dp[i][0] = dp[i][i] = 1;
        for (int j = 1; j < i; j++)
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
    }
}
