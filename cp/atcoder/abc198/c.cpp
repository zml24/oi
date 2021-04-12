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

LL n, x, y;

void quick_read() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve() {
    scanf("%lld%lld%lld", &n, &x, &y);
    if (x * x + y * y == n * n) puts("1");
    else if (x * x + y * y <= 4 * n * n) puts("2");
    else {
        LL res = (x * x + y * y + n * n - 1) / (n * n);
        res = ceil(sqrt(res));
        printf("%lld\n", res);
    }
}

int main() {
    quick_read();
    solve();
    return 0;
}