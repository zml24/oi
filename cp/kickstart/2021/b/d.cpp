#include <bits/stdc++.h>

#define x first
#define y second
#define endl '\n'

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;

const int INF = 0x3f3f3f3f;
// const double INF = 1e20;
// const LL INF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);
    cout.tie(nullptr);
    return 0;
}();

const int N = 50010, M = 100010, MX = 200010;

int n, m, mx;
int h[N], e[N << 1], w1[N << 1], ne[N << 1], idx;
LL w2[N << 1];
map<int, vector<PII>> mp;
LL ans[M];

struct Node {
    int l, r;
    LL gcd;
}tr[MX << 2];

LL _gcd(LL a, LL b) {
    return b ? _gcd(b, a % b) : a;
}

void add(int a, int b, int c, LL d) {
    e[idx] = b, w1[idx] = c, w2[idx] = d, ne[idx] = h[a], h[a] = idx++;
}

void pushup(Node &u, Node &l, Node &r) {
    u.gcd = _gcd(l.gcd, r.gcd);
}

void pushup(int u) {
    pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

void build(int u, int l, int r) {
    if (l == r) tr[u] = {l, r};
    else {
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int x, LL v) {
    if (tr[u].l == x && tr[u].r == x) tr[u] = {x, x, v};
    else {
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

void dfs(int u, int father) {
    for (auto it : mp[u]) {
        Node t = query(1, 1, it.x);
        ans[it.y] = t.gcd;
    }
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (j == father) continue;
        modify(1, w1[i], w2[i]);
        dfs(j, u);
        modify(1, w1[i], 0);
    }
}

void solve() {
    memset(h, -1, sizeof h);
    idx = 0;
    cin >> n >> m;
    mx = 0;
    for (int i = 1; i < n; i++) {
        int a, b, c;
        LL d;
        cin >> a >> b >> c >> d;
        add(a, b, c, d);
        add(b, a, c, d);
        mx = max(mx, c);
    }
    build(1, 1, mx);
    mp.clear();
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        mp[a].push_back({b, i});
    }
    dfs(1, -1);
    for (int i = 0; i < m; i++) cout << ans[i] << " ";
    cout << endl;
}

int main() {
    int TT;
    cin >> TT;
    for (int ca = 1; ca <= TT; ca++) {
        cout << "Case #" << ca << ": ";
        solve();
    }
    return 0;
}