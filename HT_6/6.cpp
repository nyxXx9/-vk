int countNoThree(int n) {
    if (n == 0) return 1;
    if (n == 1) return 2;
    if (n == 2) return 4;

    int a=1, b=2, c=4, d;
    for (int i = 3; i <= n; i++) {
        d = a + b + c;
        a = b; b = c; c = d;
    }
    return c;
}
