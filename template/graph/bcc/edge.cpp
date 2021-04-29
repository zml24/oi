int n, m;
int h[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
int stk[N], tt;
int id[N], bcc_cnt;
bool is_bridge[M];

void init() {
    memset(h, -1, sizeof h);
    memset(dfn, 0, sizeof dfn);
    memset(id, 0, sizeof id);
    memset(is_bridge, 0, sizeof is_bridge);
    idx = timestamp = tt = bcc_cnt = 0;
}

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void tarjan(int u, int from) {
    dfn[u] = low[u] = ++timestamp;
    stk[++tt] = u;
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (!dfn[j]) {
            tarjan(j, i);
            low[u] = min(low[u], low[j]);
            if (dfn[u] < low[j]) is_bridge[i] = is_bridge[i ^ 1] = true;
        } else if (i != (from ^ 1)) low[u] = min(low[u], dfn[j]);
    }
    if (dfn[u] == low[u]) {
        ++bcc_cnt;
        int t;
        do {
            t = stk[tt--];
            id[t] = bcc_cnt;
        } while (t != u);
    }
}
