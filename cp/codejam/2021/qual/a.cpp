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

int n;
int a[N];

int main() {
    int TT;
    scanf("%d", &TT);
    for (int ca = 1; ca <= TT; ca++) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        int res = 0;
        for (int i = 1; i < n; i++) {
            int idx = i;
            for (int j = i + 1; j <= n; j++) {
                if (a[j] < a[idx]) idx = j;
            }
            reverse(a + i, a + idx + 1);
            res += (idx - i + 1);
        }
        printf("Case #%d: %d\n", ca, res);
    }
    return 0;
}