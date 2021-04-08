int n;
int p[N], sz[N];

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
        if (sz[pa] < sz[pb]) swap(pa, pb);
        p[pb] = pa;
        sz[pa] += sz[pb];
        return true;
    }
    return false;
}
