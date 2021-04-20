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
// const LL INF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

void quick_read() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

const int N = 300010;

int n;
int w[N];
int b[N], l[N], r[N];

void solve() {
    memset(b, 0, sizeof b);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
    if (n <= 3) {
        printf("%d\n", n);
        return;
    }
    for (int i = 1; i < n; i++) b[i] = w[i + 1] - w[i];
    l[1] = 1, r[n - 1] = 1;
    for (int i = 2; i < n; i++) {
        if (b[i] == b[i - 1]) l[i] = l[i - 1] + 1;
        else l[i] = 1;
    }
    for (int i = n - 2; i; i--) {
        if (b[i] == b[i + 1]) r[i] = r[i + 1] + 1;
        else r[i] = 1;
    }
    int res = max(l[n - 1], r[1]);
    for (int i = 2; i < n - 1; i++) {
        res = max({res, l[i] + 1, r[i] + 1});
        if (i + 2 < n && b[i + 1] + b[i + 2] == 2 * b[i]) res = max(res, l[i] + 2);
        if (i - 2 > 0 && b[i - 1] + b[i - 2] == 2 * b[i]) res = max(res, r[i] + 2);
        if (i - 2 > 0 && i + 1 < n && b[i - 1] + b[i] == 2 * b[i - 2] && b[i - 2] == b[i + 1])
            res = max(res, l[i - 2] + r[i + 1] + 2);
        if (i - 1 > 0 && i + 2 < n && b[i + 1] + b[i] == 2 * b[i - 1] && b[i - 1] == b[i + 2])
            res = max(res, l[i - 1] + r[i + 2] + 2);
    }
    printf("%d\n", res + 1);
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