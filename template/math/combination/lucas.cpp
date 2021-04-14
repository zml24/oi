int qmi(int a, int k) {
    int res = 1;
    while (k) {
        if (k & 1) res = (LL)res * a % mod;
        a = (LL)a * a % mod;
        k >>= 1;
    }
    return res;
}

int c(int a, int b) {
    if (b > a) return 0;
    int res = 1;
    for (int i = 1, j = a; i <= b; i++, j--) {
        res = (LL)res * j % mod;
        res = (LL)res * qmi(i, mod - 2) % mod;
    }
    return res;
}

int lucas(LL a, LL b) {
    if (a < mod && b < mod) return c(a, b);
    return (LL)c(a % mod, b % mod) * lucas(a / mod, b / mod) % mod;
}
