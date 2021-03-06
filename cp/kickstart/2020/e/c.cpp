#include <bits/stdc++.h>

#define x first
#define y second
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

int a[N], b[N];

void solve() {
    int n;
    cin >> n;
    LL sum = 0;
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i], sum += a[i];
    int cnt = 0, cur = 0;
    LL ans = sum, res = sum;
    priority_queue<PII> pq;
    for (int i = 0; i < n; i++) {
        ans += a[i];
        pq.push({a[i] + b[i], a[i]});
        while (pq.size()) {
            PII t = pq.top();
            if (t.x <= sum) break;
            ans -= 2 * t.y;
            sum -= t.y;
            cur++;
            pq.pop();
        }
        if (ans > res) res = ans, cnt = cur;
        if (ans == res) cnt = min(cnt, cur);
    }
    if (pq.size()) cout << cur << " INDEFINITELY" << endl;
    else cout << cnt << " " << res << endl;
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