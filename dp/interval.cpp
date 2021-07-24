int w[N][N];
int f[N][N];

for (int len = 2; len <= n; len++)
    for (int l = 1; l + len - 1 <= n; l++) {
        int r = l + len - 1;
        f[l][r] = INF;
        for (int k = l; k < r; k++)
            f[l][r] = mln(f[l][r], f[l][k] + f[k + 1][r] + w[i][r]);
    }
}
