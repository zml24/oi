#include <bits/stdc++.h>

using namespace std;

const int N = 100010, M = 200010;

struct Edge {
    int a, b, w;
    bool operator< (const Edge &e) const {
        return w < e.w;
    }
}edges[M];

int n, m;
int p[N];

void init() {
    for (int i = 1; i <= n; i++) p[i] = i;
}

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void kruskal() {
    sort(edges, edges + m);
    int res = 0, cnt = 0;
    for (int i = 0; i < m; i++) {
        int a = edges[i].a, b = edges[i].b;
        if (find(a) != find(b)) {
            p[find(a)] = find(b);
            res += edges[i].w, cnt++;
        }
    }
    if (cnt < n - 1) puts("impossible");
    else printf("%d\n", res);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) scanf("%d%d%d", &edges[i].a, &edges[i].b, &edges[i].w);
    init();
    kruskal(); 
    return 0;
}