int n, m;
int h[N], w[N], e[N << 1], ne[N << 1], idx;
int id[N], nw[N], cnt;
int dep[N], sz[N], top[N], fa[N], son[N];

struct Node {
    int l, r;
    int add;
    LL sum;
}tr[N << 2];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs1(int u, int father, int depth) {
    dep[u] = depth, fa[u] = father, sz[u] = 1;
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (j == father) continue;
        dfs1(j, u, depth + 1);
        sz[u] += sz[j];
        if (sz[son[u]] < sz[j]) son[u] = j;
    }
}

void dfs2(int u, int t) {
    id[u] = ++cnt, nw[cnt] = w[u], top[u] = t;

}

void pushup(Node &u, Node &l, Node &r) {
    u.sum = l.sum + r.sum;
}

void pushup(int u) {
    pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

void eval(Node &u, int add) {
    u.add += add;
    u.sum += (LL)(u.r - u.l + 1) * add;
}

void pushdown(int u) {
    if (u.add) {
        eval(tr[u << 1], u.add);
        eval(tr[u << 1 | 1], u.add);
        u.add = 0;
    }
}

void build(int u, int l, int r) {
    if (l == r) tr[u] = {l, r, 0, nw[r]};
    else {
        tr[u] = {l, r, 0, nw[r]};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}


