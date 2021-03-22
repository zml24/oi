struct Node {
    int l, int r;
    int sum, add;
}tr[N << 2];

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
    if (l == r) tr[u] = {l, r, w[r]}; // init
    else {
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

// point update
void modify(int u, int x, int v) {
    if (tr[u].l == x && tr[u].r == x) tr[u] = {x, x, v};
    else {
        int mid = tr[u].l + tr[u].r >> 1;
        if (x <= mid) modify(u << 1, x, v);
        else modify(u << 1 | 1, x, v);
        pushup(u);
    }
}

// range update
void modify(int u, int l, int r, int d) {
    if (tr[u].l >= l && tr[u].r <= r) eval(tr[u], d);
    else {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) modify(u << 1, l, r, d);
        if (r > mid) modify(u << 1 | 1, l, r, d);
        pushup(u);
    }
}

Node query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) return tr[u];
    pushdown(u); // for range update
    int mid = tr[u].l + tr[u].r >> 1;
    if (r <= mid) return query(u << 1, l, r);
    if (l > mid) return query(u << 1 | 1, l, r);
    auto lc = query(u << 1, l, r), rc = query(u << 1 | 1, l, r);
    Node res;
    pushup(res, lc, rc);
    return res;
}

