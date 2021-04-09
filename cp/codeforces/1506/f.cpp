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
PII a[N];

int cal(PII st, PII ed) {
    if (st.x - st.y == ed.x - ed.y) {
        if ((st.x - st.y) & 1) return 0;
        return ed.x - st.x;
    }
    if ((st.x - st.y) & 1) return (ed.x - ed.y) - (st.x - st.y) + 1 >> 1;
    return (ed.x - ed.y) - (st.x - st.y) >> 1;
}

void solve() {
    scanf("%d", &n);
    a[0] = {1, 1};
    for (int i = 1; i <= n; i++) scanf("%d", &a[i].x);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i].y);
    sort(a, a + n + 1);
    int res = 0;
    for (int i = 1; i <= n; i++)
        res += cal(a[i - 1], a[i]);
    printf("%d\n", res);
}

int main() {
    int TT;
    scanf("%d", &TT);
    while (TT--) {
        solve();
    }
    return 0;
}