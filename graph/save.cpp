// adjacency matrix
int g[N][N];

// adjacency list
int h[N], e[M], w[M], ne[M], idx;

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void init() {
    idx = 0;
    memset(h, -1, sizeof h);
}

// edges only
struct Edge {
    int a, b, w;
}edges[M];
