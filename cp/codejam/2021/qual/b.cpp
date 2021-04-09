#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<int, LL> PIL;

const int INF = 0x3f3f3f3f;
const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
const int N = 1010;

char str[N];
int f[N][2]; // 0 for C, 1 for J

int main() {
    int TT;
    scanf("%d", &TT);
    for (int ca = 1; ca <= TT; ca++) {
        memset(f, 0x3f, sizeof f);
        int x, y; // x for CJ, y for JC
        scanf("%d%d%s", &x, &y, str);
        int n = strlen(str);
        if (str[0] == 'C') f[0][0] = 0;
        if (str[0] == 'J') f[0][1] = 0;
        if (str[0] == '?') f[0][0] = f[0][1] = 0;
        for (int i = 1; i < n; i++) {
            if (str[i] == 'C') f[i][0] = min(f[i - 1][0], f[i - 1][1] + y);
            if (str[i] == 'J') f[i][1] = min(f[i - 1][0] + x, f[i - 1][1]);
            if (str[i] == '?') {
                f[i][0] = min(f[i - 1][0], f[i - 1][1] + y);
                f[i][1] = min(f[i - 1][0] + x, f[i - 1][1]);
            }
        }
        printf("Case #%d: %d\n", ca, min(f[n - 1][0], f[n - 1][1]));
    }
    return 0;
}