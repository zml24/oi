for (int len = 2; len <= n; len++)
    for (int i = 1; i + len - 1 <= n; i++) {
        int j = i + len - 1;
        f[i][j] = INF;
        for (int k = i; k < j; k++)
            f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + g[i][j]);
    }
}
