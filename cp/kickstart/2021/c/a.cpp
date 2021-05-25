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

int n, m;
string str;
string ans;
int res;

void dfs(int u) {
    if (u == n) {
        for (int i = 0; i < n / 2; i++)
            if (ans[i] != ans[n - i - 1]) return;
        bool flag = false;
        if (ans < str) res++;
        return;
    }
    for (int i = 0; i < m; i++) {
        ans += ('a' + i);
        dfs(u + 1);
        ans.pop_back();
    }
}

void solve() {
    cin >> n >> m >> str;
    ans = "";
    res = 0;
    dfs(0);
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