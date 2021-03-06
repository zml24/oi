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

const int N = 100010;

int n, m;
int w[N];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> w[i];
    sort(w, w + n);
    int sum = 0, res;
    for (int i = 0; i < m; i++) sum += w[m - 1] - w[i];
    res = sum;
    for (int i = 1; i + m <= n; i++) {
        int r = i + m - 1;
        sum += (w[r] - w[r - 1]) * (m - 1);
        sum -= w[r - 1] - w[i - 1];
        res = min(res, sum);
    }
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