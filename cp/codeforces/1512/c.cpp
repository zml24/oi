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

const int N = 200010;

int n, m, w;
char str[N];

void quick_read() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve() {
    scanf("%d%d%s", &n, &m, str);
    w = n + m;
    for (int i = 0; i < w; i++) {
        if (str[i] == '0') n--;
        if (str[i] == '1') m--;
    }
    if (n < 0 || m < 0) {
        puts("-1");
        return;
    }
    for (int i = 0; i < w / 2; i++) {
        if (str[i] == '?' && str[w - i - 1] == '?') continue;
        else if (str[w - i - 1] == '?') {
            str[w - i - 1] = str[i];
            if (str[i] == '0') n--;
            else m--;
            if (n < 0 || m < 0) {
                puts("-1");
                return;
            }
        } else if (str[i] == '?') {
            str[i] = str[w - i - 1];
            if (str[i] == '0') n--;
            else m--;
            if (n < 0 || m < 0) {
                puts("-1");
                return;
            }
        } else if (str[i] != str[w - i - 1]) {
            puts("-1");
            return;
        }
    }
    for (int i = 0; i < w / 2; i++)
        if (str[i] == '?' && str[w - i - 1] == '?') {
            if (n) str[i] = str[w - i - 1] = '0', n -= 2;
            else str[i] = str[w - i - 1] = '1', m -= 2;
            if (n < 0 || m < 0) {
                puts("-1");
                return;
            }
        }
    if (n < 0 || m < 0) {
        puts("-1");
        return;
    }
    if (n) str[w / 2] = '0';
    if (m) str[w / 2] = '1';
    printf("%d %d %s\n", n, m, str);
}

int main() {
    quick_read();
    int TT;
    scanf("%d", &TT);
    while (TT--) {
        solve();
    }
    return 0;
}