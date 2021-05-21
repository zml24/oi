#include <bits/stdc++.h>

#define x first
#define y second
#define endl '\n'

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;

// const int INF = 0x3f3f3f3f;
// const double INF = 1e20;
const LL INF = 0x3f3f3f3f3f3f3f3f;
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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> w(n);
    for (int i = 0; i < n; i++) cin >> w[i];
    sort(w.begin(), w.end());
    w.resize(2 * n);
    for (int i = 0; i < n; i++) w[i + n] = w[i] + m;
    LL res = INF, pre = 0, cur = 0;
    for (int l = 0; l <= n; l++) {
        int r = l + n - 1;
        int mid = l + r >> 1;
        if (l == 0) for (int i = l; i <= r; i++) cur += abs(w[i] - w[mid]);
        else {
            cur = pre - (w[mid - 1] - w[l - 1]) + (w[r] - w[mid]);
            if (n % 2 == 0) cur -= w[mid] - w[mid - 1];
        }
        res = min(res, cur);
        pre = cur;
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