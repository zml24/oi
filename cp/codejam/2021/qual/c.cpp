#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<int, LL> PIL;

const int INF = 0x3f3f3f3f;
const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
const int N = 110;

int n, m;
int a[N], b[N];

int main() {
    int TT;
    scanf("%d", &TT);
    for (int ca = 1; ca <= TT; ca++) {
        scanf("%d%d", &n, &m);
        if (m + 1 < n || m + 1 > (n + 1) * n / 2) printf("Case #%d: IMPOSSIBLE\n", ca);
        else {
            int t = m + 1;
            for (int i = 1; i <= n; i++) {
                if (t == (n - i + 1)) b[i] = 1;
                else {
                    int u = n - i + 1;
                    if (t - u >= n - i) b[i] = u;
                    else b[i] = t - (n - i);
                }
                t -= b[i];
            }
            for (int i = 1; i <= n; i++) a[i] = i;
            for (int i = n; i; i--) reverse(a + i, a + i + b[i]);
            printf("Case #%d: ", ca);
            for (int i = 1; i <= n; i++) printf("%d ", a[i]);
            puts("");
        }
    }
    return 0;
}