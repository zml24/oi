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

const int N = 2000010;

int n, m;
char str[N];
int tr[N][26], cnt[N], idx;
LL res = 0;

void insert() {
    int p = 0;
    for (int i = 0; str[i]; i++) {
        int u = str[i] - 'A';
        if (!tr[p][u]) tr[p][u] = ++idx;
        p = tr[p][u];
    }
    cnt[p]++;
}

void dfs(int p, int d) {
    for (int i = 0; i < 26; i++)
        if (tr[p][i]) dfs(tr[p][i], d + 1), cnt[p] += cnt[tr[p][i]];
    while (cnt[p] >= m) {
        cnt[p] -= m;
        res += d;
    }
}

void solve() {
    memset(tr, 0, sizeof tr);
    memset(cnt, 0, sizeof cnt);
    idx = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        insert();
    }
    res = 0;
    dfs(0, 0);
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