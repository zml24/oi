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
// const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
const int dx[4] = {-1, 1, 0, 0}, dy[4] = {-1, 1, -1, 1};

void quick_read() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

const int N = 20;

int n, m;
PII A, B;
int w[N][N];
bool st[N][N];

int dfs(PII a, PII b, int u, int score, int state) {
    // printf("%d %d %d %d\n", a.x, a.y, b.x, b.y);
    if (state == 2) return score;
    int res = INF;
    bool flag = true;
    if (u & 1) { // B move
        res = INF;
        for (int i = 0; i < 4; i++) {
            if ((b.y & 1) && i == 0) continue;
            if (!(b.y & 1) && i == 1) continue;
            int x = b.x + dx[i], y = b.y + dy[i];
            if (x && x <= n && y && y <= 2 * x - 1 && !st[x][y] && !w[x][y]) {
                flag = false;
                st[x][y] = true;
                res = min(res, dfs(a, {x, y}, u + 1, score - 1, 0));
                st[x][y] = false;
            }
        }
        if (flag) res = dfs(a, b, u + 1, score, state + 1);
    } else {     // A move
        res = -INF;
        for (int i = 0; i < 4; i++) {
            if ((a.y & 1) && i == 0) continue;
            if (!(a.y & 1) && i == 1) continue;
            int x = a.x + dx[i], y = a.y + dy[i];
            if (x && x <= n && y && y <= 2 * x - 1 && !st[x][y] && !w[x][y]) {
                flag = false;
                st[x][y] = true;
                res = max(res, dfs({x, y}, b, u + 1, score + 1, 0));
                st[x][y] = false;
            }
        }
        if (flag) res = dfs(a, b, u + 1, score, state + 1);
    }
    return res;
}

void solve() {
    memset(w, 0, sizeof w);
    memset(st, 0, sizeof st);
    scanf("%d%d%d%d%d%d", &n, &A.x, &A.y, &B.x, &B.y, &m);
    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        w[a][b] = 1;
        st[a][b] = true;
    }
    st[A.x][A.y] = st[B.x][B.y] = true;
    printf("%d\n", dfs(A, B, 0, 0, 0));
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