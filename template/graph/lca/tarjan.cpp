int n, m;
int h[N], e[N << 1], w[N << 1], ne[N << 1], idx;
int d[N];
int p[N];
int st[N];
vector<PII> query[N];
int res[M];

void init() {
    memset(h, -1, sizeof h);
    memset(d, 0, sizeof d);
    memset(st, 0, sizeof st);
    memset(res, 0, sizeof res);
    idx = 0;
    for (int i = 1; i <= n; i++) p[i] = i;
    for (int i = 1; i <= n; i++) query[i].clear();
}

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void dfs(int u, int fa) {
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (j == fa) continue;
        d[j] = d[u] + w[i];
        dfs(j, u);
    }
}

void tarjan(int u) {
    st[u] = 1;
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (!st[j]) {
            tarjan(j);
            p[j] = u;
        }
    }
    for (auto item : query[u]) {
        int v = item.x, id = item.y;
        if (st[v] == 2) {
            int anc = find(v);
            res[id] = d[u] + d[v] - d[anc] * 2;
        }
    }
    st[u] = 2;
}
