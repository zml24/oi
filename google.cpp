#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};

void solve() {
    
}

int main() {
#ifdef LOCAL
    freopen("std.in", "r", stdin);
#endif
    int TT;
    cin >> TT;
    for (int i = 1; i <= TT; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}