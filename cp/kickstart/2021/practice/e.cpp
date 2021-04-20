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

const int N = 110, M = 60;

int n, m;
char str[M];
int tr[N * M][2], cnt1[N * M], cnt2[N * M], idx; // 0 for B, 1 for R
LL res;

LL qmi(LL a, int k) {
    LL ans = 1;
    while (k) {
        if (k & 1) ans *= a;
        a *= a;
        k >>= 1;
    }
    return ans;
}

void insert() {
    int p = 0;
    for (int i = 0; str[i]; i++) {
        int u = (str[i] == 'R');
        if (!tr[p][u]) tr[p][u] = ++idx;
        p = tr[p][u];
        cnt1[p]++;
    }
    cnt2[p]++;
}

void dfs(int u, int p) {
    if (u > n) return;
    if (cnt2[p]) return;
    if (tr[p][0] && cnt1[tr[p][0]]) dfs(u + 1, tr[p][0]);
    else res += qmi(2, n - u);
    if (tr[p][1] && cnt1[tr[p][1]]) dfs(u + 1, tr[p][1]);
    else res += qmi(2, n - u);
}

void solve() {
    memset(tr, 0, sizeof tr);
    memset(cnt1, 0, sizeof cnt1);
    memset(cnt2, 0, sizeof cnt2);
    idx = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%s", str);
        insert();
    }
    res = 0;
    dfs(1, 0);
    printf("%lld\n", res);
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