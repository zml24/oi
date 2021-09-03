#include <bits/stdc++.h>

using namespace std;

const int N = 500010, M = log2(N) + 1, INF = 0x3f3f3f3f;

int n, m, root;
int h[N], e[N << 1], ne[N << 1], idx;
int q[N], depth[N], fa[N][M];

void init() {
    memset(h, -1, sizeof h);
    idx = 0;
}

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void bfs(int u) {
    memset(depth, INF, sizeof depth);
    depth[0] = 0, depth[u] = 1;
    int hh = 0, tt = -1;
    q[++tt] = u;
    while (hh <= tt) {
        int t = q[hh++];
        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];
            if (depth[j] > depth[t] + 1) {
                depth[j] = depth[t] + 1;
                q[++tt] = j;
                fa[j][0] = t;
                for (int k = 1; k < M; k++) fa[j][k] = fa[fa[j][k - 1]][k - 1];
            }
        }
    }
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    for (int k = M - 1; ~k; k--)
        if (depth[fa[a][k]] >= depth[b]) a = fa[a][k];
    if (a == b) return a;
    for (int k = M - 1; ~k; k--)
        if (fa[a][k] != fa[b][k]) {
            a = fa[a][k];
            b = fa[b][k];
        }
    return fa[a][0];
}

int main() {
    scanf("%d%d%d", &n, &m, &root);
    init();
    for (int i = 1; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }
    bfs(root);
    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", lca(a, b));
    }
    return 0;
}