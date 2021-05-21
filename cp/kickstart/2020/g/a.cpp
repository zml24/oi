#include <bits/stdc++.h>

#define x first
#define y second
#define endl '\n'

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
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

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

void solve() {
    string str;
    cin >> str;
    vector<int> st, ed;
    auto idx = str.find("KICK");
    while (idx != string::npos) {
        st.push_back(idx);
        idx = str.find("KICK", idx + 1);
    }
    idx = str.find("START");
    while (idx != string::npos) {
        ed.push_back(idx);
        idx = str.find("START", idx + 1);
    }
    int res = 0;
    int n = st.size(), m = ed.size();
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (st[i] < ed[j]) res += m - j, i++;
        else j++;
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