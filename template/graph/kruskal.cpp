struct Edge {
    int a, b, w;

    bool operator< (const Edge &e) const {
        return w < e.w;
    }
}edges[M];

int n, m;
int p[N];

void init() {
    for (int i = 1; i <= n; i++) p[i] = i, sz[i] = 1;
}

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

bool merge(int a, int b) {
    int pa = find(a), pb = find(b);
    if (pa != pb) {
        if (sz[a] < sz[b]) swap(a, b);
        p[pb] = pa;
        sz[pa] += pb;
        return true;
    }
    return false;
}

int kruskal() {
    sort(edges, edges + m, cmp);
    int res = 0, cnt = 0;
    for (int i = 0; i < m; i++) {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        if (merge(a, b)) res += w, cnt++;
    }
    if (cnt < n - 1) return INF;
    return res;
}
