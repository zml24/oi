int n, m;
int h[N], e[N << 1], ne[N << 1], idx;
int d[N], fa[N][M];
int q[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void bfs(int root) {
    memset(d, INF, sizeof d);
    d[0] = 0, d[root] = 1;
    int hh = 0, tt = -1;
    q[++tt] = root;
    while (hh <= tt) {
        int t = q[hh++];
        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];
            if (d[j] > d[t] + 1) {
                d[j] = d[t] + 1;
                q[++tt] = j;
                fa[j][0] = t;
                for (int k = 1; k < M; k++) fa[j][k] = fa[fa[j][k - 1]][k - 1];
            }
        }
    }
}

int lca(int a, int b) {
    if (d[a] < d[b]) swap(a, b);
    for (int k = M - 1; ~k; k--)
        if (d[fa[a][k]] >= d[b]) a = fa[a][k];
    if (a == b) return a;
    for (int k = M - 1; ~k; k--)
        if (fa[a][k] != fa[b][k]) {
            a = fa[a][k];
            b = fa[b][k];
        }
    return fa[a][0];
}
