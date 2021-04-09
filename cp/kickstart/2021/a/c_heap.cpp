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

const int N = 310;

int n, m;
int a[N][N];
bool st[N][N];

void solve() {
    memset(st, 0, sizeof st);
    scanf("%d%d", &n, &m);
    priority_queue<PII> heap;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
            heap.push({a[i][j], i * m + j});
        }
    LL res = 0;
    while (heap.size()) {
        auto t = heap.top();
        heap.pop();
        int x = t.y / m, y = t.y % m;
        if (st[x][y]) continue;
        st[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i], yy = y + dy[i];
            if (~xx && xx < n && ~yy && yy < m && !st[xx][yy] && a[xx][yy] < a[x][y]) {
                res += a[x][y] - a[xx][yy] - 1;
                a[xx][yy] = a[x][y] - 1;
                heap.push({a[xx][yy], xx * m + yy});
            }
        }
    }
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