int p[N];

void init() {
    for (int i = 1; i <= n; i++) p[i] = i;
}

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void merge(int a, int b) {
    p[find(a)] = find(b);
}

// with size
int p[N], cnt[N];

void init() {
    for (int i = 1; i <= n; i++) p[i] = i, cnt[i] = 1;
}

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void merge(int a, int b) {
    cnt[find(b)] += cnt[find(a)];
    p[find(a)] = find(b);
}

// with distance
int p[N], d[N];

void init() {
    for (int i = 1; i <= n; i++) p[i] = i, d[i] = 0;
}

int find(int x) {
    if (p[x] != x) {
        int u = find(p[x]);
        d[x] += d[p[x]];
        p[x] = u;
    }
    return p[x];
}

void merge(int a, int b) {
    p[find(a)] = find(b);
    d[find(a)] = dis;
}

// union by rank
int p[N], rank[N];

void init() {
    for (int i = 1; i <= n; i++) p[i] = i, rank[i] = 0;
}

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void merge(int a, int b) {
    int pa = find(a), pb = find(b);
    if (pa != pb) {
        if (rank[pa] < rank[pb]) swap(pa, pb);
        p[pb] = pa;
        if (rank[pa] == rank[pb]) rank[pa]++;
    }
}
