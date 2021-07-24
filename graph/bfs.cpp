int n, m, S;
int h[N], e[M], ne[M], idx;
int q[N];
bool st[N];

void init() {
    memset(h, -1, sizeof h);
    idx = 0;
}

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void bfs(int S) {
    memset(st, 0, sizeof st);
    int hh = 0, tt = -1;
    q[++tt] = S;
    st[S] = true;
    while (hh <= tt) {
        int t = q[hh++];
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (!st[j]) {
                st[j] = true;
                q[++tt] = j;
            }
        }
    }
}
