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

const int N = 7010;

int n;
int w[N];

void solve() {
    scanf("%d", &n);
    int zeros = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
        if (!w[i]) zeros++;
    }
    LL res = 0;
    res += (LL)zeros * (zeros - 1) * (n - zeros) / 2;
    res += (LL)zeros * (zeros - 1) * (zeros - 2) / 6;
    sort(w, w + n);
    map<LL, LL> S;
    for (int i = n - 1; ~i; i--) {
        for (int j = i - 1; ~j; j--)
            if (w[i] && w[j] && S.count((LL)w[i] * w[j])) res += S[(LL)w[i] * w[j]];
        S[w[i]]++;
    }
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