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

// const int INF = 0x3f3f3f3f;
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

const LL INF = 2e18;

LL n;

LL get(LL x) {
    LL res = 1;
    while (x) {
        x /= 10, res *= 10;
    }
    return res;
}

LL cal(LL mid, int u) {
    LL res = 0;
    for (int i = 1; i <= u; i++) {
        int t = get(mid);
        if (res > INF / t) return INF;
        res = res * t + mid;
        res = min(res, INF);
        ++mid;
    }
    return res;
}

LL cal(int u) {
    LL l = 1, r = 1e9;
    while (l < r) {
        LL mid = l + r >> 1;
        if (cal(mid, u) > n) r = mid;
        else l = mid + 1;
    }
    return cal(l, u);
}

void solve() {
    scanf("%lld", &n);
    LL res = 2e18;
    for (int i = 2; i <= 18; i++) res = min(res, cal(i));
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