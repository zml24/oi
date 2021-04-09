#include<bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<int, LL> PIL;
typedef pair<double, double> PDD;

const int INF = 0x3f3f3f3f;
// const double INF = 1e20;
const double PI = acos(-1);
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

const int N = 200010;

struct Node {
    int l, r;
    LL sum1, sum2;
}tr[N << 2];

int n, m;
int w[N];

void pushup(Node &u, Node &l, Node &r) {
    u.sum1 = l.sum1 + r.sum1;
    u.sum2 = l.sum2 + r.sum2;
}

void pushup(int u) {
    pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

void build(int u, int l, int r) {
    if (l == r) {
        if (r & 1) tr[u] = {l, r, w[r], w[r] * r};
        else tr[u] = {l, r, -w[r], -w[r] * r};
    } else {
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int x, int v) {
    if (tr[u].l == x && tr[u].r == x) {
        if (x & 1) tr[u] = {x, x, v, v * x};
        else tr[u] = {x, x, -v, -v * x};
    } else {
        int mid = tr[u].l + tr[u].r >> 1;
        if (x <= mid) modify(u << 1, x, v);
        else modify(u << 1 | 1, x, v);
        pushup(u);
    }

}

Node query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) return tr[u];
    int mid = tr[u].l + tr[u].r >> 1;
    if (r <= mid) return query(u << 1, l, r);
    if (l > mid) return query(u << 1 | 1, l, r);
    auto lc = query(u << 1, l, r), rc = query(u << 1 | 1, l, r);
    Node res;
    pushup(res, lc, rc);
    return res;
}

void solve() {
    memset(tr, 0, sizeof tr);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
    build(1, 1, n);
    LL res = 0;
    while (m--) {
        char op[5];
        int a, b;
        scanf("%s%d%d", op, &a, &b);
        if (op[0] == 'U') modify(1, a, b);
        else {
            LL t = query(1, a, b).sum2 - (a - 1) * query(1, a, b).sum1;
            if (a & 1) res += t;
            else res -= t;
        }
    }
    printf("%lld\n", res);
}

int main() {
    int TT;
    scanf("%d", &TT);
    for (int ca = 1; ca <= TT; ca++) {
        printf("Case #%d: ", ca);
        solve();
    }
    return 0;
}