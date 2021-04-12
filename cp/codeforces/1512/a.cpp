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

const int N = 110;

int n;
int w[N];
map<int, int> mp;

void quick_read() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve() {
    scanf("%d", &n);
    mp.clear();
    for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
    if (w[1] == w[2]) {
        for (int i = 3; i <= n; i++)
            if (w[i] != w[1]) {
                printf("%d\n", i);
                break;
            }
    } else {
        if (w[1] == w[3]) printf("%d\n", 2);
        else printf("%d\n", 1);
    }
}

int main() {
    quick_read();
    int TT;
    scanf("%d", &TT);
    while (TT--) {
        solve();
    }
    return 0;
}