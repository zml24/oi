#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<int, LL> PIL;

const int INF = 0x3f3f3f3f;
const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
const int N = 25;

char a[N], b[N];
int f[N][N];

int main() {
    int TT;
    scanf("%d", &TT);
    while (TT--) {
        memset(f, 0, sizeof f);
        scanf("%s%s", a, b);
        for (int i = 0; i < strlen(a); i++)
            for (int j = 0; j < strlen(b); j++)
                if (a[i] == b[j]) f[i + 1][j + 1] = f[i][j] + 1;
        int res = 0;
        for (int i = 1; i <= strlen(a); i++)
            for (int j = 1; j <= strlen(b); j++)
                res = max(res, f[i][j]);
        printf("%d\n", strlen(a) + strlen(b) - 2 * res);
    }
    return 0;
}