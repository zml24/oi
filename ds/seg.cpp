#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 100010;

int n, m;
int w[N];

struct Node {
    int l, r;
    LL add, sum;
}tr[N << 2];

void pushup(Node &u, Node &l, Node &r) {
    u.sum = l.sum + r.sum;
}

void pushup(int u) {
    pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

void eval(Node &u, LL add) {
    u.add += add;
    u.sum += (u.r - u.l + 1) * add;
}

void pushdown(int u) {
    if (tr[u].add) {
        eval(tr[u << 1], tr[u].add);
        eval(tr[u << 1 | 1], tr[u].add);
        tr[u].add = 0;
    }
}

void build(int u, int l, int r) {
    if (l == r) tr[u] = {l, r, 0, w[l]};
    else {
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

// 单点修改
void modify(int u, int x, int v) {
    if (tr[u].l == x && tr[u].r == x) tr[u].sum += v;
    else {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (x <= mid) modify(u << 1, x, v);
        else modify(u << 1 | 1, x, v);
        pushup(u);
    }
}

// 区间修改
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
    else {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (r <= mid) return query(u << 1, l, r);
        if (l > mid) return query(u << 1 | 1, l, r);
        auto lc = query(u << 1, l, r), rc = query(u << 1 | 1, l, r);
        Node res;
        pushup(res, lc, rc);
        return res;
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
    build(1, 1, n);
    while (m--) {
        char op[2];
        int l, r;
        scanf("%s%d%d", op, &l, &r);
        if (*op == 'C') {
            int d;
            scanf("%d", &d);
            modify(1, l, r, d);
        } else printf("%lld\n", query(1, l, r).sum);
    }
    return 0;
}