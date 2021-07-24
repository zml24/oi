int n;
int g[N][N];
int dist[N];
bool st[N];

void init() {
    memset(g, 0x3f, sizeof g);
    for (int i = 1; i <= n; i++) g[i][i] = 0;
}

void add(int a, int b, int c) {
    g[a][b] = min(g[a][b], c);
}

int prim() {
    memset(dist, 0x3f, sizeof dist);
    int res = 0;
    for (int i = 0; i < n; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++)
            if (!st[j] && (t == -1 || dist[t] > dist[j])) t = j;
        if (i && dist[t] == INF) return -1;
        st[t] = true;
        if (i) res += dist[t];
        for (int j = 1; j <= n; j++) dist[j] = min(dist[j], g[t][j]);
    }
    return res;
}
