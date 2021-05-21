#include <bits/stdc++.h>

#define x first
#define y second
#define endl '\n'

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
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

const int N = 40;

int n, m;
int w[N];

void solve() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &w[i]);
    sort(w, w + n);
    int m1 = 0, m2 = 0;
    for (int i = 1; i < n; i++) {
        int d = w[i] - w[i - 1];
        d /= 2;
        if (!m1) m1 = d;
        else if (m1 >= d) m2 = max(m2, d);
        else if (m1 < d) m2 = m1, m1 = d;
    }
    if (w[0] != 1) {
        int d = w[0] - 1;
        if (!m1) m1 = d;
        else if (m1 >= d) m2 = max(m2, d);
        else if (m1 < d) m2 = m1, m1 = d;
    }
    if (w[n - 1] != m) {
        int d = m - w[n - 1];
        if (!m1) m1 = d;
        else if (m1 >= d) m2 = max(m2, d);
        else if (m1 < d) m2 = m1, m1 = d;
    }
    double ans = m1 + m2;
    for (int i = 1; i < n; i++) ans = max(w[i] - w[i - 1] - 1.0, ans);
    double res = ans / m;
    printf("%.10f\n", res);
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
