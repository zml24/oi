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

const int N = 410;

int n;
int X1, X2, Y1, Y2;
char str[N][N];

void quick_read() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve() {
    scanf("%d", &n);
    X1 = X2 = Y1 = Y2 = -1;
    for (int i = 0; i < n; i++) scanf("%s", str[i]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (str[i][j] == '*') {
                if (X1 == -1) X1 = i, Y1 = j;
                else X2 = i; Y2 = j;
            }
    if (X1 == X2) {
        if (X1 == 0) str[1][Y1] = str[1][Y2] = '*';
        else str[0][Y1] = str[0][Y2] = '*';
    } else if (Y1 == Y2) {
        if (Y1 == 0) str[X1][1] = str[X2][1] = '*';
        else str[X1][0] = str[X2][0] = '*';
    } else str[X1][Y2] = str[X2][Y1] = '*';
    for (int i = 0; i < n; i++) printf("%s\n", str[i]);
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