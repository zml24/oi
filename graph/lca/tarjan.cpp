#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 500010, INF = 0x3f3f3f3f;

int n, m, root;
int h[N], e[N << 1], w[N << 1], ne[N << 1], idx;
int p[N];
int q[N], depth[N], st[N];
vector<PII> query[N];
int res[N];

void init() {
    memset(h, -1, sizeof h);
    memset(depth, 0, sizeof depth);
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
        depth[j] = depth[u] + w[i];
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
        if (st[v] == 2) res[id] = find(v);
    }
    st[u] = 2;
}

int main() {
    scanf("%d%d%d", &n, &m, &root);
    init();
    for (int i = 1; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b, 1), add(b, a, 1);
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a != b) {
            query[a].push_back({b, i});
            query[b].push_back({a, i});
        } else res[i] = a;
    }
    dfs(root, -1);
    tarjan(root);
    for (int i = 0; i < m; i++) printf("%d\n", res[i]);
    return 0;
}