int n, m;
int h[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
int stk[N], tt;
int bcc_cnt;
vector<int> bcc[N];
bool cut[N];
int root;

void init() {
    memset(h, -1, sizeof h);
    memset(dfn, 0, sizeof dfn);
    memset(cut, 0, sizeof cut);
    idx = timestamp = tt = bcc_cnt = 0;
    for (int i = 1; i <= n; i++) bcc[i].clear();
}

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void tarjan(int u) {
    dfn[u] = low[u] = ++timestamp;
    stk[++tt] = u;
    if (u == root && h[u] == -1) {
        bcc[++bcc_cnt].push_back(u);
        return;
    }
    int cnt = 0;
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (!dfn[j]) {
            tarjan(j);
            low[u] = min(low[u], low[j]);
            if (dfn[u] <= low[j]) {
                cnt++;
                if (u != root || cnt > 1) cut[u] = true;
                ++bcc_cnt;
                int t;
                do {
                    t = stk[tt--];
                    bcc[bcc_cnt].push_back(u);
                } while (t != j);
                bcc[bcc_cnt].push_back(u);
            }
        } else low[u] = min(low[u], dfn[j]);
    }
}
