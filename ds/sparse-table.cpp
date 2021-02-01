void init() {
    for (int j = 0; j < M; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            if (!j) f[i][j] = w[i];
            else f[i][j] = max(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
}

int query(int l, int r) {
    int len = r - l + 1;
    int k = log(len) / log(2);
    return max(f[l][k], f[r - (1 << k) + 1][k]);
}
