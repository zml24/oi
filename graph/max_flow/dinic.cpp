#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 210, M = 10010, INF = 0x3f3f3f3f;

int n, m, S, T;
int h[N], e[M], f[M], ne[M], idx;
int q[N], d[N], cur[N];

void init() {
    memset(h, -1, sizeof h);
    idx = 0;
}

void add(int a, int b, int c) {
    e[idx] = b, f[idx] = c, ne[idx] = h[a], h[a] = idx++;
    e[idx] = a, f[idx] = 0, ne[idx] = h[b], h[b] = idx++;
}

bool bfs() {
    memset(d, -1, sizeof d);
    int hh = 0, tt = -1;
    q[++tt] = S, d[S] = 0, cur[S] = h[S];
    while (hh <= tt) {
        int t = q[hh++];
        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];
            if (d[j] == -1 && f[i]) {
                d[j] = d[t] + 1;
                cur[j] = h[j];
                if (j == T) return true;
                q[++tt] = j;
            }
        }
    }
    return false;
}

LL find(int u, int limit) {
    if (u == T) return limit;
    LL flow = 0;
    for (int i = cur[u]; ~i && flow < limit; i = ne[i]) {
        cur[u] = i;
        int j = e[i];
        if (d[j] == d[u] + 1 && f[i]) {
            int t = find(j, min((LL)f[i], limit - flow));
            if (!t) d[j] = -1;
            f[i] -= t, f[i ^ 1] += t, flow += t;
        }
    }
    return flow;
}

LL dinic() {
    LL res = 0, flow;
    while (bfs())
        while (flow = find(S, INF)) res += flow;
    return res;
}

void print() {
    for (int i = 0; i < idx; i++)
        if (e[i] > m && e[i] <= n && !f[i]) printf("%d %d\n", e[i ^ 1], e[i]);
}

int main() {
    scanf("%d%d%d%d", &n, &m, &S, &T);
    init();
    while (m--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    printf("%lld\n", dinic());
    return 0;
}