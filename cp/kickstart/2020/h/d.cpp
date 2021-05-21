#include <bits/stdc++.h>

#define x first
#define y second
#define endl '\n'

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
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

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

const int N = 50010, M = 30;

int n, m;
int w[M][M];
char str[N][M];

void solve() {
    scanf("%d%d", &n, &m);
    memset(w, INF, sizeof w);
    for (int i = 0; i < 26; i++) w[i][i] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%s", str[i]);
        for (int j = 0; j < strlen(str[i]); j++)
            for (int k = j + 1; k < strlen(str[i]); k++) {
                if (str[i][j] == str[i][k]) continue;
                w[str[i][j] - 'A'][str[i][k] - 'A'] = w[str[i][k] - 'A'][str[i][j] - 'A'] = 1;
            }
    }
    for (int k = 0; k < 26; k++)
        for (int i = 0; i < 26; i++)
            for (int j = 0; j < 26; j++)
                w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        int res = INF;
        for (int i = 0; i < strlen(str[a]); i++)
            for (int j = 0; j < strlen(str[b]); j++) res = min(res, w[str[a][i] - 'A'][str[b][j] - 'A']);
        printf("%d ", res == INF ? -1 : res + 2);
    }
    puts("");
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