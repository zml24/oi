int n;
int g[N][N]

void init() {
    memset(g, 0x3f, sizeof g);
    for (int i = 1; i <= n; i++) g[i][i] = 0;
}

void add(int a, int b, int c) {
    g[a][b] = min(g[a][b], c);
}

void floyd(int S, int T) {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
    if (g[S][T] > INF / 2) return -1;
    else return g[S][T];
}
