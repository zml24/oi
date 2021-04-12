#include <bits/stdc++.h>

#define x first
#define y second

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

const int N = 310, NN = 90010, MM = 450010;

int n, m, S = 0;
int g[N][N];
int h[NN], e[MM], w[MM], ne[MM], idx;
LL dist[NN];
bool st[NN];

int get(int a, int b) {
    return (a - 1) * m + b;
}

void add(int a, int b, LL c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void spfa() {
    memset(st, 0, sizeof st);
    deque<int> q;
    dist[S] = 0;
    q.push_back(S);
    st[S] = true;
    while (q.size()) {
        int t = q.front();
        q.pop_front();
        st[t] = false;
        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];
            if (dist[j] < dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                if (!st[j]) {
                    if (q.empty() || dist[q.front()] > dist[j]) q.push_back(j);
                    else q.push_front(j);
                    st[j] = true;
                }
            }
        }
    }
}

void solve() {
    memset(h, -1, sizeof h);
    idx = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            scanf("%d", &g[i][j]);
            add(S, get(i, j), 0);
            dist[get(i, j)] = -INF;
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int k = 0; k < 4; k++) {
                int x = i + dx[k], y = j + dy[k];
                if (x && x <= n && y && y <= m) add(get(i, j), get(x, y), g[i][j] - g[x][y] - 1);
            }
    spfa();
    LL res = 0;
    for (int i = 1; i <= n * m; i++) res += dist[i];
    printf("%lld\n", res);
}

int main() {
    int TT;
    scanf("%d", &TT);
    for (int ca = 1; ca <= TT; ca++) {
        printf("Case #%d: ", ca);
        solve();
    }
    return 0;
}