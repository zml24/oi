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

const int N = 310;

int n, m, k;
set<vector<int>, double> mp;
set<vector<int>, int> st;
vector<int> target;

double dfs(vector<int> ans) {
    if (st.count(ans)) return mp[ans];
    duoble res = 0, pos = 0;
    for (int i = 0; i < m; i++) {
        int j = i + 1;
        while (j < m && ans[j - 1] == ans[j]) j++;
        
        i = j;
    }
    res = res / pos + 
}

void solve() {
    scanf("%d%d%d", &n, &m, &k);
    mp.clear();
    st.clear();
    target.clear();
    for (int i = 0; i < m - k; i++) target.push_back(0);
    for (int i = 0; i < k; i++) {
        int x;
        scanf("%d", &x);
        target.push_back(x);
    }
    mp[target] = 0;
    st[target] = 0;
    vector<int> res(m);
    printf("%d\n", dfs(res));
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