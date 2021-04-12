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

const int N = 20;

int n, m;
int w[N];

void solve() {
    n = 0;
    scanf("%d", &m);
    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        for (int i = n; i < n + b; i++) w[i] = a;
        n += b;
    }
    LL res = 0;
    for (int i = 0; i < 1 << n; i++) {
        if (__builtin_popcount(i) == 0 || __builtin_popcount(i) == n) continue;
        LL a = 0, b = 1;
        for (int j = 0; j < n; j++) {
            if (i >> j & 1) a += w[j];
            else b *= w[j];
        }
        if (a == b) res = max(res, a);
    }
    printf("%lld\n", res);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int TT;
    scanf("%d", &TT);
    for (int ca = 1; ca <= TT; ca++) {
        printf("Case #%d: ", ca);
        solve();
    }
    return 0;
}