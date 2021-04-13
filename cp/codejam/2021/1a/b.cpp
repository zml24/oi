#include <bits/stdc++.h>

#define x first
#define y second
#define endl '\n'

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

void quick_read() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

const int N = 100, M = 60;

int n;
PIL w[N];
LL res = 0;

void check(LL x) {
    if (x < 2) return;
    LL mul = x, sum = 0;
    for (int i = 0; i < n; i++) {
        if (mul % w[i].x == 0) {
            LL s = w[i].y;
            while (mul % w[i].x == 0 && s) {
                mul /= w[i].x;
                s--;
            }
            if (s) sum += w[i].x * s;
        } else sum += w[i].x * w[i].y;
    }
    if (mul != 1) return;
    if (x == sum) res = max(res, sum);
}

void solve() {
    scanf("%d", &n);
    LL sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d%lld", &w[i].x, &w[i].y);
        sum += w[i].x * w[i].y;
    }
    res = 0;
    for (LL i = sum - 499 * M; i <= sum; i++) check(i);
    printf("%lld\n", res);
}

int main() {
    quick_read();
    int TT;
    scanf("%d", &TT);
    for (int ca = 1; ca <= TT; ca++) {
        printf("Case #%d: ", ca);
        solve();
    }
    return 0;
}