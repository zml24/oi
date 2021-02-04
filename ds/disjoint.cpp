int p[N];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void init() {
    for (int i = 1; i <= n; i++) p[i] = i;
}

void union(int a, int b) {
    p[find(a)] = find(b);
}

// with size
int p[N], cnt[N];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void init() {
    for (int i = 1; i <= n; i++) p[i] = i, cnt[i] = 1;
}

void union(int a, int b) {
    cnt[find(b)] += cnt[find(a)];
    p[find(a)] = find(b);
}

// with distance
int p[N], d[N];

int find(int x) {
    if (p[x] != x) {
        int u = find(p[x]);
        d[x] += d[p[x]];
        p[x] = u;
    }
    return p[x];
}

void init() {
    for (int i = 1; i <= n; i++) p[i] = i, d[i] = 0;
}
void union(int a, int b) {
    p[find(a)] = find(b);
    d[find(a)] = dis;
}
