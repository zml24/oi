void add(int a, int b, int c) {
    e[idx] = b, f[idx] = c, ne[idx] = h[a], h[a] = idx++;
    e[idx] = a, f[idx] = 0, ne[idx] = h[b], h[b] = idx++;
}

bool bfs() {
    int hh = 0, tt = -1;
    memset(d, -1, sizeof d);
    q[++tt] = S, d[S] = 0, cur[S] = h[S];
    while (hh <= tt) {
        int t = q[hh++];
        for (int i = h[t]; i != -1; i = ne[i]) {
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

int find(int u, int limit) {
    if (u == T) return limit;
    int flow = 0;
    for (int i = cur[u]; i != -1 && flow < limit; i = ne[i]) {
        cur[u] = i;
        int j = e[i];
        if (d[j] == d[u] + 1 && f[i]) {
            int t = find(j, min(f[i], limit - flow));
            if (!t) d[j] = -1;
            f[i] -= t, f[i ^ 1] += t, flow += t;
            // print path in bipartite graph
            // if (t) nxt[u] = j - n;
        }
    }
    return flow;
}

int dinic() {
    int res = 0, flow;
    while (bfs())
        while (flow = find(S, INF)) res += flow;
    return res;
}

void print() {
    for (int i = h[T]; i != -1; i = ne[i])
        if (f[i ^ 1]) {
            int j = e[i] - n;
            while (j) printf("%d ", j), j = nxt[j];
            puts("");
        }
}
