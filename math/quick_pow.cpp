int qmi(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = (LL)res * a % MOD;
        a = (LL)a * a % MOD;
        b >>= 1;
    }
    return res;
}
