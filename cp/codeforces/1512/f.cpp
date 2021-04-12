#include<bits/stdc++.h>

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

const int N = 200010;

int n, m;
LL a[N], b[N];

void quick_read() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i < n; i++) scanf("%d", &b[i]);
    LL res = INF, cur = 0, sum = 0;
    for (int i = 1; i <= n; i++) {
        res = min(res, cur + (m - sum + a[i] - 1) / a[i]);
        if (i == n) break;
        LL t = (b[i] - sum + a[i] - 1) / a[i];
        cur += t + 1;
        sum += a[i] * t - b[i];
        // printf("%lld %lld\n", cur, sum);
    }
    printf("%lld\n", res);
}

int main() {
    quick_read();
    int TT;
    scanf("%d", &TT);
    while (TT--) {
        solve();
    }
    return 0;
}