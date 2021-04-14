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

const int N = 110;

int n, a, b, c;
int res[N];

void solve() {
    scanf("%d%d%d%d", &n, &a, &b, &c);
    if (a - c + b - c + c > n) puts("IMPOSSIBLE");
    else if (a - c + b - c + c < n && c == 1) puts("IMPOSSIBLE");
    else {
        for (int i = 0; i < a - c; i++) res[i] = n - (a - c) + i;
        for (int i = 0; i < c; i++) res[i + a - c] = n;
        for (int i = 0; i < n - (a + b - c); i++) res[i + a] = 1;
        for (int i = 0; i < b - c; i++) res[i + n - b + c] = n - i - 1;
        for (int i = 0; i < n; i++) printf("%d ", res[i]);
        puts("");
    }
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