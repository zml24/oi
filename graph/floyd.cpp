void floyd(int x, int y) {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

    if (g[x][y] > 0x3f3f3f3f / 2) return -1;
    else return g[x][y];
}
