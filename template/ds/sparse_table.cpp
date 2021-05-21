int n;
int w[N];
int f[N][M];

void init(int l, int r) {
    for (int j = 0; j < M; j++)
        for (int i = l; i + (1 << j) - 1 <= r; i++)
            if (!j) f[i][j] = w[i];
            else f[i][j] = max(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
}

int query(int l, int r) {
    int len = r - l + 1;
    int k = log2(len);
    return max(f[l][k], f[r - (1 << k) + 1][k]);
}
