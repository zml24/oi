#include<bits/stdc++.h>

#define x first
#define y second
#define sq(x) (x) * (x)

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<int, LL> PIL;
typedef pair<double, double> PDD;

const int INF = 0x3f3f3f3f;
// const double INF = 1e20;
const double PI = acos(-1);
const double eps = 1e-8;
// const int mod = 1e9 + 7;
const int mod = 1e9;
// const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

const int N = 10010;

LL x, y, dx, dy;
char str[N];
int tt1, tt2, tt3;
LL num[N];
char op[N];
PII dir[N];
map<char, PII> mp = {{'N', {0, -1}}, {'S', {0, 1}}, {'W', {-1, 0}}, {'E', {1, 0}}};

int find(int idx) {
    int cnt = 1;
    for (int i = idx + 1; i < strlen(str); i++) {
        if (str[i] == '(') cnt++;
        if (str[i] == ')') cnt--;
        if (!cnt) return i;
    }
    return -1;
}

PII cal(int l, int r, LL k) {
    int x = 0, y = 0;
    for (int i = l; i <= r; i++) {
        auto c = str[i];
        if (mp.count(c)) {
            x = ((x + mp[c].x * k) % mod + mod) % mod;
            y = ((y + mp[c].y * k) % mod + mod) % mod;
        } else if (isdigit(c)) {
            LL tmp = 0, j = i;
            while (j <= r && isdigit(str[j])) tmp = tmp * 10 + str[j++] - '0';
            i = j - 1;
            int idx = find(i + 1);
            PII res = cal(i + 1, idx, tmp);
            x = ((x + res.x * k) % mod + mod) % mod;
            y = ((y + res.y * k) % mod + mod) % mod;
            i = idx;
        }
    }
    return {x, y};
}

void solve() {
    tt1 = tt2 = tt3 = 0;
    scanf("%s", str);
    int n = strlen(str);
    PII res = cal(0, n - 1, 1);
    printf("%d %d\n", res.x + 1, res.y + 1);
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