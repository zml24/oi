#include <bits/stdc++.h>

#define x first
#define y second
#define endl '\n'

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, pair<int, int>> PLII;
typedef pair<double, double> PDD;

// const int INF = 0x3f3f3f3f;
// const double INF = 1e20;
// const LL INF = 0x3f3f3f3f3f3f3f3f;
const LL INF = 1e12;
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

const int N = 310, M = 1010;

int n, m, s, r;
int g[N][N];
int h[N], e[M], ne[M], idx;
bool st[N][N];
LL dist[N][N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void solve() {
    cin >> n >> m >> s >> r;
    memset(h, -1, sizeof h);
    idx = 0;
    while (m--) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    memset(dist, 0x3f, sizeof dist);
    priority_queue<PLII, vector<PLII>, greater<PLII>> pq;
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        while (k--) {
            int a;
            cin >> a;
            dist[i][a] = 0;
            pq.push({0, {i, a}});
        }
    }
    vector<vector<int>> ra(r);
    vector<int> rb(r);
    for (int i = 0; i < r; i++) {
        int k;
        cin >> k;
        ra[i].resize(k);
        for (int j = 0; j < k; j++) cin >> ra[i][j];
        cin >> rb[i];
    }
    memset(st, 0, sizeof st);
    while (pq.size()) {
        auto u = pq.top();
        PII t = u.y;
        pq.pop();
        if (st[t.x][t.y]) continue;
        st[t.x][t.y] = true;
        for (int i = h[t.x]; ~i; i = ne[i]) {
            int j = e[i];
            if (dist[j][t.y] > dist[t.x][t.y] + 1) {
                dist[j][t.y] = dist[t.x][t.y] + 1;
                pq.push({dist[j][t.y], {j, t.y}});
            }
        }
        for (int i = 0; i < r; i++) {
            if (find(ra[i].begin(), ra[i].end(), t.y) == ra[i].end()) continue;
            LL sum = 0;
            for (int j : ra[i]) sum += dist[t.x][j];
            sum = min(sum, INF);
            if (dist[t.x][rb[i]] > sum) {
                dist[t.x][rb[i]] = sum;
                pq.push({sum, {t.x, rb[i]}});
            }
        }
    }
    LL res = INF;
    for (int i = 1; i <= n; i++) res = min(res, dist[i][1]);
    if (res == INF) cout << "-1" << endl;
    else cout << res << endl;
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