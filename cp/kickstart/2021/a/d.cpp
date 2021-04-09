#include <bits/stdc++.h>

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

const int N = 510, M = 250010;

int n, m;
int a[N][N], b[N][N];
int r[N], c[N];
int p[2 * N], sz[2 * N];

struct Edge {
    int a, b, w;
    bool operator< (const Edge& e) const {
        return w < e.w;
    }
}edges[M];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

bool merge(int a, int b) {
    int pa = find(a), pb = find(b);
    if (pa != pb) {
        if (sz[pa] < sz[pb]) swap(pa, pb);
        p[pb] = pa;
        sz[pa] += sz[pb];
        return true;
    }
    return false;
}

void solve() {
    m = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) scanf("%d", &a[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) scanf("%d", &b[i][j]);
    for (int i = 1; i <= n; i++) scanf("%d", &r[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
    LL res = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (a[i][j] < 0) {
                res += b[i][j];
                edges[m++] = {i, n + j, b[i][j]};
            }
    sort(edges, edges + m);
    for (int i = 1; i <= 2 * n; i++) p[i] = i, sz[i] = 1;
    for (int i = m - 1; ~i; i--)
        if (merge(edges[i].a, edges[i].b)) res -= edges[i].w;
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