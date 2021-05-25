#include <bits/stdc++.h>

#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define endl '\n'

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;

const int INF = 0x3f3f3f3f;
// const double INF = 1e20;
// const LL INF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);
    cout.tie(nullptr);
    return 0;
}();

const int N = 70;

int k, n, m;
double f[4][N][N][N];
int d[4][N][N][N];
string res[4];

void init() {
    memset(d, -1, sizeof d);
    double w = 10.0;
    double e[4] = {10.0, 5.0, 2.0, 0.0};
    double ps, pr, pp;
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j <= 60; j++)
            for (int p = 0; p < j; p++)
                for (int r = 0; r + p < j; r++) {
                    if (j == 1) ps = pr = pp = 1.0 / 3;
                    else {
                        int s = j - 1 - p - r;
                        ps = 1.0 * p / (j - 1);
                        pr = 1.0 * s / (j - 1);
                        pp = 1.0 * r / (j - 1);
                    }
                    if (f[i][j - 1][p][r] + w * pr + e[i] * pp > f[i][j][p + 1][r]) {
                        f[i][j][p + 1][r] = f[i][j - 1][p][r] + w * pr + e[i] * pp;
                        d[i][j][p + 1][r] = 0;
                    }
                    if (f[i][j - 1][p][r] + w * ps + e[i] * pr > f[i][j][p][r + 1]) {
                        f[i][j][p][r + 1] = f[i][j - 1][p][r] + w * ps + e[i] * pr;
                        d[i][j][p][r + 1] = 1;
                    }
                    if (f[i][j - 1][p][r] + w * pp + e[i] * ps > f[i][j][p][r]) {
                        f[i][j][p][r] = f[i][j - 1][p][r] + w * pp + e[i] * ps;
                        d[i][j][p][r] = 2;
                    }
                }
        double ans = 0;
        int rp, rr, rs;
        for (int p = 0; p <= 60; p++)
            for (int r = 0; r + p <= 60; r++) {
                int s = 60 - p - r;
                if (f[i][60][p][r] > ans) {
                    ans = f[i][60][p][r];
                    rp = p;
                    rr = r;
                    rs = s;
                }
            }
        res[i] = "";
        for (int j = 60; j; j--) {
            if (d[i][j][rp][rr] == 0) {
                rp--;
                res[i] += "P";
            } else if (d[i][j][rp][rr] == 1) {
                rr--;
                res[i] += "R";
            } else res[i] += "S";
        }
        reverse(all(res[i]));
    }
}

void solve() {
    cin >> n >> m;
    if (n == m) cout << res[0] << endl;
    else if (n == 2 * m) cout << res[1] << endl;
    else if (n == 10 * m) cout << res[2] << endl;
    else cout << res[3] << endl;
}

int main() {
    int TT;
    cin >> TT >> k;
    init();
    for (int ca = 1; ca <= TT; ca++) {
        cout << "Case #" << ca << ": ";
        solve();
    }
    return 0;
}