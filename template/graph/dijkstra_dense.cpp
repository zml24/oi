int n, S, T;
int g[N][N];
int dist[N];
bool st[N];

void init() {
    memset(g, INF, sizeof g);
    for (int i = 1; i <= n; i++) g[i][i] = 0;
}

void add(int a, int b, int c) {
    g[a][b] = min(g[a][b], c);
}

int dijkstra() {
    memset(dist, INF, sizeof dist);
    memset(st, 0, sizeof st);
    dist[S] = 0;
    for (int i = 0; i < n; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++)
            if (!st[j] && (t == -1 || dist[t] > dist[j])) t = j;
        st[t] = true;
        for (int j = 1; j <= n; j++) dist[j] = min(dist[j], dist[t] + g[t][j]);
    }
    if (dist[n] > INF / 2) return -1;
    else return dist[T];
}
