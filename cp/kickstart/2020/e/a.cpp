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

const int N = 200010;

int n;
int w[N];
int b[N];

void solve() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &w[i]);
    for (int i = 1; i < n; i++) b[i] = w[i] - w[i - 1];
    b[n] = INF;
    int res = 0, sum = 1;
    for (int i = 2; i <= n; i++) {
        if (b[i] != b[i - 1]) {
            res = max(res, sum);
            sum = 1;
        } else sum++;
    }
    printf("%d\n", res + 1);
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