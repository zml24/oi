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

const int N = 10010;

int n;
int w[N];

void solve() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &w[i]);
    int res = 0;
    int low = 0, high = 0;
    for (int i = 1; i < n; i++) {
        if (w[i] > w[i - 1]) high++, low = 0;
        if (w[i] < w[i - 1]) low++, high = 0;
        if (low > 3 || high > 3) res++, high = 0, low = 0;
    }
    printf("%d\n", res);
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