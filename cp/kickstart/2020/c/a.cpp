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

const int N = 200010;

int n, m;
int w[N];

void solve() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &w[i]);
    int res = 0;
    for (int i = n - 1; i >= m - 1; i--)
        if (w[i] == 1) {
            int j = i;
            while (~j && w[j] - w[i] == i - j) {
                if (i - j + 1 >= m) {
                    res++;
                    break;
                }
                j--;
            }
            i = j + 1;
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