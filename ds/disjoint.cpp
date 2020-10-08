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
