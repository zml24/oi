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

const int N = 40;

int n;
int st[N];

void solve() {
    memset(st, 0, sizeof st);
    scanf("%d", &n);
    if (n <= 500) {
        for (int i = 1; i <= n; i++) printf("%d 1\n", i);
    } else {
        n -= 30;
        int m = 1, cnt = __builtin_popcount(n);
        while (n) {
            if (n & 1) st[m] = 1;
            n >>= 1;
            m++;
        }
        int flag = 1; // from left to right
        for (int i = 1; i <= 30; i++) {
            if (st[i]) {
                for (int j = 1; j <= i; j++) printf("%d %d\n", i, (flag & 1) ? j : (i - j + 1));
                flag ^= 1;
            } else printf("%d %d\n", i, (flag & 1) ? 1 : i);
        }
        for (int i = 1; i <= cnt; i++) printf("%d %d\n", 30 + i, (flag & 1) ? 1 : (30 + i));
    }
}

int main() {
    int TT;
    scanf("%d", &TT);
    for (int ca = 1; ca <= TT; ca++) {
        printf("Case #%d:\n", ca);
        solve();
    }
    return 0;
}