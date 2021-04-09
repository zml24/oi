#include<bits/stdc++.h>

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

const int N = 100010;

int n;
int w[N];
int s[N];
int cnts[N * 200]; // s[r] - s[l - 1] = x <=> s[l - 1] = s[r] - x

void solve() {
    memset(s, 0, sizeof s);
    memset(cnts, 0, sizeof cnts);
    scanf("%d", &n);
    int mi = 0, mx = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
        s[i] = s[i - 1] + w[i];
        if (w[i] < 0) mi -= w[i];
        else mx += w[i];
    }
    cnts[mi] = 1;
    LL res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j * j <= mx; j++) {
            if (s[i] - j * j + mi >= 0) res += cnts[s[i] - j * j + mi];
            else break;
        }
        cnts[s[i] + mi]++;
    }
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