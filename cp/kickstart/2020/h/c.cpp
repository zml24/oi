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

const int N = 100010;

int n;
int a[N], b[N];

void solve() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d%d", &a[i], &b[i]);
    LL res = 0;
    sort(a, a + n);
    for (int i = 0; i < n; i++) a[i] -= i;
    sort(a, a + n);
    for (int i = 0; i < n; i++) res += abs(a[i] - a[n / 2]);
    sort(b, b + n);
    for (int i = 0; i < n; i++) res += abs(b[i] - b[n / 2]);
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