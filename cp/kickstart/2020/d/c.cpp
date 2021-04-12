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

const int N = 500010;

int n, m1, m2;
int h[N], e[N], ne[N], idx;
int cur[N];
int stk[N];
double st1[N], st2[N];
vector<int> ans;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void solve() {
    memset(h, -1, sizeof h);
    idx = 0;
    ans.clear();
    scanf("%d%d%d", &n, &m1, &m2);
    for (int i = 1; i <= n; i++) st1[i] = st2[i] = 0;
    for (int i = 2; i <= n; i++) {
        int a;
        scanf("%d", &a);
        add(a, i);
    }
    memcpy(cur, h, sizeof h);
    int tt = 0;
    stk[++tt] = 1;
    ans.push_back(1);
    while (tt) {
        int t = stk[tt];
        if (cur[t] != -1) {
            int i = cur[t];
            int j = e[i];
            stk[++tt] = j;
            ans.push_back(j);
            i = ne[i];
            cur[t] = i;
        } else {
            tt--;
            st1[ans[ans.size() - 1]]++;
            st2[ans[ans.size() - 1]]++;
            if (ans.size() > m1) st1[ans[ans.size() - 1 - m1]] += st1[ans[ans.size() - 1]];
            if (ans.size() > m2) st2[ans[ans.size() - 1 - m2]] += st2[ans[ans.size() - 1]];
            ans.pop_back();
        }
    }
    for (int i = 1; i <= n; i++) st1[i] /= n, st2[i] /= n;
    double res = 0;
    for (int i = 1; i <= n; i++) res += (st1[i] + st2[i] - st1[i] * st2[i]);
    printf("%lf\n", res);
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