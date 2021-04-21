#include <bits/stdc++.h>

#define x first
#define y second
#define endl '\n'

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<int, LL> PIL;
typedef pair<double, double> PDD;

const int INF = 0x3f3f3f3f;
// const double INF = 1e20;
// const LL INF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

void quick_read() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

const int N = 100010;

int n;

void solve() {
    scanf("%d", &n);
    LL sum = 0;
    priority_queue<PII> pq;
    for (int i = 0; i < n; i++) {
        int e, r;
        scanf("%d%d", &e, &r);
        sum += e;
        pq.push({e + r, e});
    }
    while (pq.size()) {
        if (pq.top().x <= sum) break;
        else {
            PII t = pq.top();
            pq.pop();
            sum -= t.y;
        }
    }
    if (pq.size()) printf("%d INDEFINITELY\n", n - pq.size());
    else printf("")
}

int main() {
    quick_read();
    int TT;
    scanf("%d", &TT);
    for (int ca = 1; ca <= TT; ca++) {
        printf("Case #%d: ", ca);
        solve();
    }
    return 0;
}