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

const int N = 40, M = 1000;

int n, m;
char str[N][N];
int h[N], e[M], ne[M], idx;
bool st[N];
bool g[N][N];
int d[N];
int q[N];

void add(int a, int b) {
    e[idx] = b, d[b]++, ne[idx] = h[a], h[a] = idx++;
}

void topsort() {
    int cnt = 0;
    for (int i = 0; i < 26; i++)
        if (st[i]) cnt++;
    int hh = 0, tt = -1;
    for (int i = 0; i < 26; i++)
        if (st[i] && !d[i]) q[++tt] = i;
    while (hh <= tt) {
        int t = q[hh++];
        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];
            if (--d[j] == 0) q[++tt] = j;
        }
    }
    if (tt != cnt - 1) puts("-1");
    else {
        for (int i = 0; i < cnt; i++) printf("%c", q[i] + 'A');
        puts("");
    }
}

void solve() {
    memset(h, -1, sizeof h);
    memset(st, 0, sizeof st);
    memset(g, 0, sizeof g);
    memset(d, 0, sizeof d);
    idx = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", str[i]);
        for (int j = 0; j < m; j++) st[str[i][j] - 'A'] = true;
        if (i) {
            for (int j = 0; j < m; j++) {
                int a = str[i][j] - 'A', b = str[i - 1][j] - 'A';
                if (a != b && !g[a][b]) {
                    add(a, b);
                    g[a][b] = true;
                }
            }
        }
    }
    topsort();
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