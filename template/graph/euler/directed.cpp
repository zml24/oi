int n, m;
int h[N], e[M], ne[M], idx;
bool used[M];
int ans[M], cnt;
int din[N], dout[N];

void init() {
    memset(h, -1, sizeof h);
    memset(used, 0, sizeof used);
    memset(din, 0, sizeof din);
    memset(dout, 0, sizeof dout);
    idx = cnt = 0;
}

void add(int a, int b) {
    e[idx] = b, din[b]++, dout[a]++, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u) {
    for (int &i = h[u]; ~i;) {
        if (used[i]) {
            i = ne[i];
            continue;
        }
        used[i] = true;
        int t = i + 1;
        int j = e[i];
        i = ne[i];
        dfs(j);
        ans[++cnt] = t;
    }
}

bool print() {
    for (int i = 1; i <= n; i++)
        if (din[i] != dout[i]) return false;
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

