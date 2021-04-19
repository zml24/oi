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

const int N = 100010;

int n, m;
PII w[N];

void solve() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        w[i] = {(a + m - 1) / m, i + 1};
    }
    sort(w, w + n);
    for (int i = 0; i < n; i++) printf("%d ", w[i].y);
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