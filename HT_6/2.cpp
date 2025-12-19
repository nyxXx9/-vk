int maxProfit(int* prices, int n) {
    int profit = 0, min = prices[0];
    for (int i = 1; i < n; i++) {
        if (prices[i] - min > profit) profit = prices[i] - min;
        if (prices[i] < min) min = prices[i];
    }
    return profit;
}
