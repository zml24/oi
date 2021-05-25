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
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.precision(20);
    // cout.tie(nullptr);
    return 0;
}();

int l, r, n;

void solve() {
    cin >> l >> r >> n;
    while (true) {
        int mid = l + r >> 1;
        cout << mid << endl;
        string str;
        cin >> str;
        if (str == "CORRECT") break;
        else if (str == "TOO_SMALL") l = mid + 1;
        else r = mid - 1;
    }
}

int main() {
    int TT;
    cin >> TT;
    while (TT--) {
        solve();
    }
    return 0;
}