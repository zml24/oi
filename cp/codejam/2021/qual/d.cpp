#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<int, LL> PIL;

const int INF = 0x3f3f3f3f;
const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
const int N = 60;

int n, q;
int a[N];

int act(int a, int b, int c) {
    printf("%d %d %d\n", a + 1, b + 1, c + 1);
    fflush(stdout);
    int res;
    scanf("%d", &res);
    if (res == -1) exit(0);
    return res - 1;
}

int main() {
    int TT;
    scanf("%d%d%d", &TT, &n, &q);
    for (int ca = 1; ca <= TT; ca++) {
        memset(a, 0, sizeof a);
        a[0] = 0, a[1] = 1;
        for (int i = 2; i < n; i++) {
            int l = 0, r = i;
            while (l < r) {
                if (l + 1 == r) {
                    if (l) l--;
                    else r++;
                }
                int ml = (2 * l + r) / 3, mr = (l + 2 * r) / 3;
                int ans = act(a[ml], a[mr], i);
                if (ans == a[ml]) r = ml;
                else if (ans == a[mr]) l = mr + 1;
                else l = ml + 1, r = mr;
            }
            for (int j = i; j > l; j--) a[j] = a[j - 1];
            a[l] = i;
        }
        for (int i = 0; i < n; i++) printf("%d ", a[i] + 1);
        puts("");
        fflush(stdout);
        int res;
        scanf("%d", &res);
        if (res == -1) exit(0);
    }
    return 0;
}