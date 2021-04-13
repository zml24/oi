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

const int N = 100010, M = 18;

int n, m;
int w[N];
int f[N][M];

void init(int l, int r) {
    for (int j = 0; j < M; j++)
        for (int i = l; i + (1 << j) - 1 <= r; i++)
            if (!j) f[i][j] = w[i];
            else f[i][j] = max(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
}

int query(int l, int r) {
    int len = r - l + 1;
    int k = log2(len);
    return max(f[l][k], f[r - (1 << k) + 1][k]);
}

bool check(int st, int k, int mid) {
    int l = st - mid, r = st + k - mid;
    return query(l, st - 1) <= query(st, r);
}

int cal(int st, int k) {
    int l = max(0, k - (n - st)), r = min(st - 1, k);
    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (check(st, k, mid)) l = mid;
        else r = mid - 1;
    }
    r = st + k - l, l = st - l - 1;
    return w[l] < w[r] ? l : r + 1;
}

void solve() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; i++) scanf("%d", &w[i]);
    w[0] = w[n] = INF;
    init(0, n);
    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d ", b == 1 ? a : cal(a, b - 2));
    }
    puts("");
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