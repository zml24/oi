// adjacency matrix
int g[N][N];

// adjacency list
int h[N], e[M], w[M], ne[M], idx;

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

// max flow
void add(int a, int b, int c) {
    e[idx] = a, f[idx] = c, ne[idx] = h[a], h[a] = idx++;
    e[idx] = b, f[idx] = 0, ne[idx] = h[b], h[b] = idx++;
}

// min cost max flow
void add(int a, int b, int c, int d) {
    e[idx] = a, f[idx] = c, w[idx] = d, ne[idx] = h[a], h[a] = idx++;
    e[idx] = b, f[idx] = 0, w[idx] = -d, ne[idx] = h[b], h[b] = idx++;
}

void init() {
    idx = 0;
    memset(h, -1, sizeof h);
}

// edges only
struct Edge {
    int a, b, w;
}edges[M];
