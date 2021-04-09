#include <bits/stdc++.h>

#define x first
#define y second
#define sq(x) (x) * (x)

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

int n, m, u, d, l, r;

void solve() {
    scanf("%d%d%d%d%d%d", &n, &m, &u, &l, &d, &r);
    vector<vector<double>> f(n + 1, vector<double>(m + 1));
    f[1][1] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == 1) continue;
            if (i >= u && i <= d && j >= l && j <= r) continue;
            if (i == 1 && j == m) f[i][j] = f[i][j - 1] / 2;
            else if (i == n && j == 1) f[i][j] = f[i - 1][j] / 2;
            else {
                if (i == n) f[i][j] += f[i][j - 1];
                if (j == m) f[i][j] += f[i - 1][j];
                if (i < n) f[i][j] += f[i][j - 1] / 2;
                if (j < m) f[i][j] += f[i - 1][j] / 2;
            }
        }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <+ m; j++) printf("%lf ", f[i][j]);
        puts("");
    }
    printf("%lf\n", f[n][m]);
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