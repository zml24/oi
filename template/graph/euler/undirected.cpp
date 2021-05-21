int n, m;
int h[N], e[M], ne[M], idx;
bool used[M];
int ans[M], cnt;
int d[N];

void init() {
    memset(h, -1, sizeof h);
    memset(used, 0, sizeof used);
    memset(d, 0, sizeof d);
    idx = cnt = 0;
}

void add(int a, int b) {
    e[idx] = b, d[a]++, d[b]++, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u) {
    for (int &i = h[u]; ~i;) {
        if (used[i]) {
            i = ne[i];
            continue;
        }
        used[i] = used[i ^ 1] = true;
        int t = i / 2 + 1;
        if (i & 1) t = -t;
        int j = e[i];
        i = ne[i];
        dfs(j);
        ans[++cnt] = t;
    }
}

bool print() {
    for (int i = 1; i <= n; i++)
        if (d[i] & 1) return false;
    for (int i = 1; i <= n; i++)
        if (~h[i]) {
            dfs(i);
            break;
        }
    if (cnt < m) return false;
    for (int i = cnt; i; i--) cout << ans[i] << " ";
    cout << endl;
    return true;
}

