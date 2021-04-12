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
const double PI = acos(-1);
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

void quick_read() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

const int N = 100010;

int n;
int h[N], w[N], e[N << 1], ne[N << 1], idx;
bool st[N];
map<int, int> mp;
vector<int> res;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u) {
    st[u] = true;
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (st[j]) continue;
        if (!mp.count(w[j]) || !mp[w[j]]) res.push_back(j);
        mp[w[j]]++;
        dfs(j);
        mp[w[j]]--;
    }
}

void solve() {
    memset(h, -1, sizeof h);
    memset(st, 0, sizeof st);
    idx = 0;
    mp.clear();
    res.clear();
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
    for (int i = 1; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }
    st[1] = true;
    res.push_back(1);
    mp[w[1]]++;
    dfs(1);
    sort(res.begin(), res.end());
    for (int i : res) printf("%d\n", i);
}

int main() {
    quick_read();
    solve();
    return 0;
}