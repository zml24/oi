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
const double PI = acos(-1);
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

void quick_read() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

const int N = 200010;

int n, a, b, c;
char s[N];

void solve() {
    scanf("%d%d%s", &a, &b, s);
    n = a + b, c = 0;
    for (int i = 0; i < n; i++)
        if (s[i] != '?') {
            int j = n - i - 1;
            if (s[j] == '?') s[j] = s[i];
            else if (s[i] != s[j]) {
                puts("-1");
                return;
            }
        }
    for (int i = n - 1; ~i; i--)
        if (s[i] != '?') {
            int j = n - i - 1;
            if (s[j] == '?') s[j] = s[i];
            else if (s[i] != s[j]) {
                puts("-1");
                return;
            }
        }
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') a--;
        if (s[i] == '1') b--;
        if (s[i] == '?') c++;
    }
    bool flag = (n & 1) && (s[n / 2] == '?');
    if (a < 0 || b < 0 || a + b != c || (flag && a % 2 == 0 && b % 2 == 0)) {
        puts("-1");
        return;
    }
    if (a & 1 || b & 1) {
        if (s[n / 2] != '?') {
            puts("-1");
            return;
        }
        s[n / 2] = (a & 1) ? '0' : '1';
        if (a & 1) a--;
        else b--;
    }
    if (a & 1 || b & 1) {
        puts("-1");
        return;
    }
    for (int i = 0; i < n; i++)
        if (s[i] == '?') {
            int j = n - i - 1;
            if (a) {
                a -= 2;
                s[i] = s[j] = '0';
            } else {
                b -= 2;
                s[i] = s[j] = '1';
            }
        }
    printf("%s\n", s);
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