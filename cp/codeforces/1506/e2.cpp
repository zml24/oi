#include<bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<int, LL> PIL;

const int INF = 0x3f3f3f3f;
const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

const int N = 200010;

int n;
int q[N];
int res1[N], res2[N];

void solve() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &q[i]);
    memset(res1, 0, sizeof res1);
    memset(res2, 0, sizeof res2);
    for (int i = 0; i < n; i++)
        if (!i || q[i] != q[i - 1]) {
            res1[i] = q[i];
            res2[i] = q[i];
        }
    for (int i = 0; i < n; i++) printf("%d ", res1[i]);
    puts("");
    for (int i = 0; i < n; i++) printf("%d ", res2[i]);
    puts("");
}

int main() {
    int TT;
    scanf("%d", &TT);
    while (TT--) {
        solve();
    }
    return 0;
}