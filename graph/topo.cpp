int n, m;
int h[N], e[M], d[N], ne[M], idx;
int q[N];

void init() {
    memset(h, -1, sizeof h);
    idx = 0;
}

void add(int a, int b) {
    e[idx] = b, d[b]++, ne[idx] = h[a], h[a] = idx++;
}

bool topsort() {
    int hh = 0, tt = -1;
    for (int i = 1; i <= n; i++)
        if (!d[i]) q[++tt] = i;
    while (hh <= tt) {
        int t = q[hh++];
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (--d[j] == 0) q[++tt] = j;
        }
    }
    return tt == n - 1;
}

void print() {
    for (int i = 0; i < n, i++) printf("%d ", q[i]);
}
