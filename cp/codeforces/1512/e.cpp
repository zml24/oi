#include<bits/stdc++.h>

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

const int N = 510;

int n, l, r, s;
int w[N];
bool st[N];

void quick_read() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve() {
    memset(w, 0, sizeof w);
    memset(st, 0, sizeof st);
    scanf("%d%d%d%d", &n, &l, &r, &s);
    int len = r - l + 1;
    int mi = (1 + len) * len / 2, mx = (n + n - len + 1) * len / 2;
    if (s > mx || s < mi) puts("-1");
    else {
        int avg = s / len, rem = s;
        for (int i = l; i <= r; i++) {
            w[i] = avg + i + 1 - l - len / 2;
            st[w[i]] = true;
            rem -= w[i];
        }
        if (rem > 0) {
            for (int i = r; i >= l; i--) {
                if (rem != 0) {
                    int t = min(n, w[i] + rem);
                    st[w[i]] = false;
                    rem -= (t - w[i]);
                    w[i] = t;
                    st[t] = true;
                } else break;
            }
        } else if (rem < 0) {
            for (int i = l; i <= r; i++) {
                if (rem != 0) {
                    int t = max(1, w[i] + rem);
                    st[w[i]] = false;
                    rem += (w[i] - t);
                    w[i] = t;
                    st[t] = true;
                } else break;
            }
        }
        int cur = 1;
        for (int i = 1; i <= n; i++)
            if (!w[i]) {
                while (st[cur]) cur++;
                w[i] = cur;
                st[cur] = true;
            }
        for (int i = 1; i <= n; i++) printf("%d ", w[i]);
        puts("");
    }
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