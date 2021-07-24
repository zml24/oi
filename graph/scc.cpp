int n, m;
int h[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
int stk[N], tt;
bool st[N];
int id[N], scc_cnt;

void init() {
    memset(h, -1, sizeof h);
    memset(dfn, 0, sizeof dfn);
    memset(st, 0, sizeof st);
    memset(id, 0, sizeof id);
    idx = timestamp = tt = scc_cnt = 0;
}

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void tarjan(int u) {
    dfn[u] = low[u] = ++timestamp;
    stk[++tt] = u, st[u] = true;
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (!dfn[j]) {
            tarjan(j);
            low[u] = min(low[u], low[j]);
        } else if (st[j]) low[u] = min(low[u], dfn[j]);
    }
    if (dfn[u] == low[u]) {
        ++scc_cnt;
        int t;
        do {
            t = stk[tt--];
            st[t] = false;
            id[t] = scc_cnt;
        } while (t != u);
    }
}
