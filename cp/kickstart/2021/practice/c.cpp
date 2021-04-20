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

LL n;

bool check(LL x) {
    string str = to_string(x);
    for (int i = 0; i < str.size(); i++)
        if ((str[i] - '0') & 1) return false;
    return true;
}

LL get_l(LL x) {
    LL l = 0;
    string str = to_string(x);
    bool flag = false;
    for (int i = 0; i < str.size(); i++) {
        l *= 10;
        if (flag) l += 8;
        else if ((str[i] - '0') % 2 == 0) {
            l+= str[i] - '0';
        } else {
            l += str[i] - '0' - 1;
            flag = true;
        }
    }
    return l;
}

LL get_r(LL x) {
    LL r = 0;
    string str = to_string(x);
    bool flag = false;
    for (int i = 0; i < str.size(); i++) {
        r *= 10;
        if (flag) continue;
        else if ((str[i] - '0') % 2 == 0) {
            r += str[i] - '0';
        } else {
            r += str[i] - '0' + 1;
            flag = true;
        }
    }
    return r;
}

void solve() {
    scanf("%lld", &n);
    LL l = get_l(n), r = get_r(n);
    while (!check(r)) r = get_r(r);
    printf("%lld\n", min(n - l, r - n));
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