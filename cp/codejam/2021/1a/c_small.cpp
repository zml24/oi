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

const int N = 130;

int n, m;
int w[5];
char str[5][N];
char res[N];
map<char, char> mp = {{'F', 'T'}, {'T', 'F'}};

void solve() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%s%d", str[i], &w[i]);
    if (n == 1) {
        if (w[1] >= (m + 1) / 2) printf("%s %d/1\n", str[1], w[1]);
        else {
            memset(res, 0, sizeof res);
            for (int i = 0; i < m; i++) res[i] = mp[str[1][i]];
            printf("%s %d/1\n", res, m - w[1]);
        }
    } else if (n == 2) {
        memset(res, 0, sizeof res);
        int a = 0, b = 0;
        for (int i = 0; i < m; i++) {
            if (str[1][i] == str[2][i]) a++;
            else b++;
        }
        int x = (w[1] + w[2] - b) / 2;
        for (int i = 0; i < m; i++) {
            if (str[1][i] == str[2][i]) {
                if (x >= (a + 1) / 2) res[i] = str[1][i];
                else res[i] = mp[str[1][i]];
            }
            else res[i] = (w[1] < w[2]) ? str[2][i] : str[1][i];
        }
        if (x >= (a + 1) / 2) printf("%s %d/1\n", res, max(w[1], w[2]));
        else printf("%s %d/1\n", res, max(w[1], w[2]) - x + a - x);
    } else {
        exit(0);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int TT;
    scanf("%d", &TT);
    for (int ca = 1; ca <= TT; ca++) {
        printf("Case #%d: ", ca);
        solve();
    }
    return 0;
}