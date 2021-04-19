#include <bits/stdc++.h>

#define x first
#define y second
#define endl '\n'

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<int, LL> PIL;
typedef pair<double, double> PDD;

const int INF = 0x3f3f3f3f;
// const double INF = 1e20;
// const LL INF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

void quick_read() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

const int N = 10010, M = 10010;

int n, m;
int h[N], e[M], w[M], ne[M], idx;
LL f[M];

void add(int a, int b, int c, LL d) {
    e[idx] = b, w[idx] = c, f[idx] = d, ne[idx] = h[a], h[a] = idx++;
}

LL gcd(LL a, LL b) {
    return b ? gcd(b, a % b) : a;
}

void dfs(int u, int father) {
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (j != father) w[i] = 0;
        if (j == father) continue;
        dfs(j, u);
    }
}

void solve() {
    memset(h, -1, sizeof h);
    idx = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; i++) {
        int a, b, c;
        LL d;
        scanf("%d%d%d%lld", &a, &b, &c, &d);
        add(a, b, c, d);
        add(b, a, c, d);
    }
    dfs(1, -1);
    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        LL res;
        int cnt = 0;
        while (a != 1) {
            for (int i = h[a]; ~i; i = ne[i]) {
                if (!w[i]) continue;
                if (b >= w[i]) {
                    if (!cnt) res = f[i];
                    else res = gcd(res, f[i]);
                    cnt++;
                }
                int j = e[i];
                a = j;
                break;
            }
        }
        if (!cnt) printf("%d ", 0);
        else printf("%lld ", res);
    }
    puts("");
}

int main() {
    quick_read();
    int TT;
    scanf("%d", &TT);
    for (int ca = 1; ca <= TT; ca++) {
        printf("Case #%d: ", ca);
        solve();
    }
    return 0;
}