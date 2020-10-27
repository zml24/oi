const int INF = 0x3f3f3f3f;

int p[N];

struct Edge {
    int a, b, w;
}edges[M];

bool cmp(Edge x, Edge y) {return x.w < y.w;}

int kruskal() {
    sort(edges, edges + m);
    for (int i = 1; i <= n; i++) p[i] = i;
    int res = 0, cnt = 0;
    for (int i = 0; i < m; i++) {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        a = find(a), b = find(b);
        if (a != b) {
            p[a] = b;
            res += w;
            cnt++;
        }
    }
    if (cnt < n - 1) return INF;
    return res;
}
