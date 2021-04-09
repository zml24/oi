#include<bits/stdc++.h>

#define x first
#define y second
#define sq(x) (x) * (x)

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

const int N = 100010;

int n, m;
int w[N], b[N];

int check(int mid) {
    int res = 0;
    for (int i = 2; i <= n; i++) res += (b[i] - 1) / mid;
    return res;
}

void solve() {
    memset(b, 0, sizeof b);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
    int mx = 0;
    for (int i = 2; i <= n; i++) b[i] = w[i] - w[i - 1], mx = max(mx, b[i]);
    int l = 1, r = mx;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid) <= m) r = mid;
        else l = mid + 1;
    }
    printf("%d\n", l);
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