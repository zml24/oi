#include <bits/stdc++.h>

#define x first
#define y second
#define endl '\n'

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<int, LL> PIL;
typedef pair<double, double> PDD;

const int INF = 0x3f3f3f3f;
// const double INF = 1e20;
const double PI = acos(-1);
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

void quick_read() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

const int N = 10;

int a, b;
set<int> S;

int get(int x) {
    string str = to_string(x);
    int res = 0;
    for (int i = 0; i < str.size(); i++) {
        res <<= 1;
        res += str[i] - '0';
    }
    return res;
}

int cal(int x) {
    if (x == 0) return 1;
    int res = 0;
    for (int i = 31 - __builtin_clz(x); ~i; i--) {
        res <<= 1;
        res += !(x >> i & 1);
    }
    return res;
}

void solve() {
    S.clear();
    scanf("%d%d", &a, &b);
    a = get(a), b = get(b);
    queue<PII> q;
    q.push({a, 0});
    S.insert(a);
    while (q.size()) {
        PII t = q.front();
        q.pop();
        if (t.x == b) {
            printf("%lld\n", t.y);
            return;
        }
        int x = cal(t.x);
        if (!S.count(x)) {
            q.push({x, t.y + 1});
            S.insert(x);
        }
        int y = t.x << 1;
        if (!S.count(y)) {
            q.push({y, t.y + 1});
            S.insert(y);
        }
    }
    puts("IMPOSSIBLE");
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