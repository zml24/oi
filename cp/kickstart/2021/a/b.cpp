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

const int N = 1010;

int n, m;
int w[N][N];
int st[N][N][4];

void solve() {
    memset(st, 0, sizeof st);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) scanf("%d", &w[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (w[i][j]) {
                st[i][j][0] = st[i][j - 1][0] + 1;
                st[i][j][1] = st[i - 1][j][1] + 1;
            }
    for (int i = n; i; i--)
        for (int j = m; j; j--)
            if (w[i][j]) {
                st[i][j][2] = st[i][j + 1][2] + 1;
                st[i][j][3] = st[i + 1][j][3] + 1;
            }
    LL res = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int k = 0; k < 4; k++)
                if (st[i][j][(k + 1) % 4] > 1 && st[i][j][k] > 1)
                    res += max(0, min(st[i][j][k] / 2, st[i][j][(k + 1) % 4]) - 1) + max(0, min(st[i][j][(k + 1) % 4] / 2, st[i][j][k]) - 1) + 0LL;
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