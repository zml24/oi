#include <bits/stdc++.h>

#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define endl '\n'

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
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
    cout.precision(20);
    cout.tie(nullptr);
    return 0;
}();

const int N = 110;

int n, m, c, d, e1, e2, f;

int x[N], y[N], w[N];

int qmi(int a, int k) {
    int res = 1;
    while (k) {
        if (k & 1) res = (LL)res * a % mod;
        a = (LL)a * a % mod;
        k >>= 1;
    }
    return res;
}

void solve() {
    cin >> n >> m >> x[0] >> y[0] >> c >> d >> e1 >> e2 >> f;
    w[0] = (x[0] + y[0]) % f;
    for (int i = 1; i < n; i++) {
        x[i] = ((LL)c * x[i - 1] + (LL)d * y[i - 1] + e1) % f;
        y[i] = ((LL)d * x[i - 1] + (LL)c * y[i - 1] + e2) % f;
        w[i] = ((LL)x[i] + y[i]) % f;
    }
    int res = 0;
    for (int i = 1; i <= m; i++)
        for (int l = 1; l <= n; l++)
            for (int r = l; r <= n; r++)
                for (int j = l; j <= r; j++) res = (res + (LL)w[j - 1] * qmi(j - l + 1, i)) % mod;
    cout << res << endl;
}

int main() {
    int TT;
    cin >> TT;
    for (int ca = 1; ca <= TT; ca++) {
        cout << "Case #" << ca << ": ";
        solve();
    }
    return 0;
}