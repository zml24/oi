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

const int N = 200010;

int n, m, u, d, l, r;
double fac[N], fx[N], fy[N];

double cal(int n, int k) {
    return exp2(fac[n] - fac[n - k] - fac[k] - n);
}

void solve() {
    scanf("%d%d%d%d%d%d", &n, &m, &u, &l, &d, &r);
    fx[1] = cal(n - 1, 0);
    for (int i = 2; i <= m; i++) fx[i] = fx[i - 1] + cal(n - 2 + i - 1, i - 1) / 2;
    fy[1] = cal(m - 1, 0);
    for (int i = 2; i <= n; i++) fy[i] = fy[i - 1] + cal(m - 2 + i - 1, i - 1) / 2;
    double res = 0;
    int x = d + 1, y = l - 1;
    while (x < n && y > 0) {
        res += cal(x + y - 2, x - 1);
        x++, y--;
    }
    if (x == n && y > 0) res += fx[y];
    x = u - 1, y = r + 1;
    while (x > 0 && y < m) {
        res += cal(x + y - 2, x - 1);
        x--, y++;
    }
    if (x > 0 && y == m) res += fy[x];
    printf("%lf\n", res);
}

int main() {
    for (int i = 1; i < N; i++)
        fac[i] = fac[i - 1] + log2(i);
    int TT;
    scanf("%d", &TT);
    for (int ca = 1; ca <= TT; ca++) {
        printf("Case #%d: ", ca);
        solve();
    }
    return 0;
}