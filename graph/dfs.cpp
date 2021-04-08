int h[N], e[M], ne[M], idx;
bool st[N];

void init() {
    memset(h, -1, sizeof h);
    memset(st, 0, sizeof st);
    idx = 0;
}

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u) {
    st[u] = true;
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!st[j]) dfs(j);
    }
}
