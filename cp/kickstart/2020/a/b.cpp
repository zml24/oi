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

const int N = 60, M = 40;

int n, m, k;
int w[N][M];
int s[N][M];
int f[N][N * M]; // f[i][j] = min(f[i - 1][j], ..., f[i - 1][j - m])

void solve() {
    memset(f, 0, sizeof f);
    memset(s, 0, sizeof s);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) scanf("%d", &w[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) s[i][j] = s[i][j - 1] + w[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= i * m; j++) {
            f[i][j] = f[i - 1][j];
            for (int l = 1; l <= m; l++)
                if (j - l >= 0) f[i][j] = max(f[i][j], f[i - 1][j - l] + s[i][l]);
        }
    printf("%d\n", f[n][k]);
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