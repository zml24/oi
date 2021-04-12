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

const int N = 100010;

int n, m;
int w[N];

void solve() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; i++) scanf("%d", &w[i]);
    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        int res = 0;
        if (b == 1) res = a;
        else if (a == 1) res = b;
        else if (a == n) res = n - b + 1;
        else {
            priority_queue<PII, vector<PII>, greater<PII>> pq;
            pq.push({w[a - 1], a - 1});
            pq.push({w[a], a});
            PII t;
            int cur = 0; // -1 for left, 1 for right
            for (int i = 1; i < b; i++) {
                t = pq.top(); // 1 <= t.y < n
                pq.pop();
                if (a > t.y) {
                    cur = -1;
                    if (t.y > 1) pq.push({w[t.y - 1], t.y - 1});
                } else {
                    cur = 1;
                    if (t.y < n - 1) pq.push({w[t.y + 1], t.y + 1});
                }
            }
            if (~cur) res = t.y + 1;
            else res = t.y;
        }
        printf("%d ", res);
    }
    puts("");
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